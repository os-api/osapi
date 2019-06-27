// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a POSIX compliant implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_file.h"
#include "fs/posix/fs_posix.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX




t_status fs_file_open( const t_char * p_path, bool create, int openMode, int location, t_file * p_file )
{
  t_status	st;
  char 		mode[3];

  set_file_open_mode( create, openMode, location, mode );

  if( strlen( mode ) == 0 )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_invopenmode, &st );
  else
    {
      st = open_file( p_path, mode, p_file );
      if( status_success( st ) )
	  // Ensure that position respects function contract
	  st = fs_file_setPosition( p_file, location, (t_size) 0 );
    }

  return st;
}



t_status fs_file_openRead( const t_char * p_path, t_file * p_file )
{
  return open_file( p_path, "r", p_file );
}

t_status fs_file_openWrite( const t_char * p_path, t_file * p_file )
{
  return open_file( p_path, "a", p_file );
}

t_status fs_file_openReadWrite( const t_char * p_path, t_file * p_file )
{
  return open_file( p_path, "a+", p_file );
}


t_status fs_file_setPosition( const t_file * p_file, int initial, t_offset offset )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      if( p_file->state != osapi_fs_e_file_opened )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_fopen, &st );
      else
	{
	  fseek( p_file->data.handle, (long) offset, initial );
	  if( p_file->data.handle == NULL )
	      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
	}
    }

  return st;
}


t_status fs_file_create( const char * p_path )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      int fd = open( p_path, O_CREAT | O_EXCL | O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP );	// If file already exists, fail with error

      if( fd == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	{
	  if( close( fd ) == -1 )
	      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
	}
    }

  return st;
}



t_status fs_file_close( t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      if( fclose( p_file->data.handle ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	{
	  p_file->data.handle = NULL;
	  p_file->state = osapi_fs_e_file_closed;
	}
    }

  return st;
}


t_status fs_file_getError( const t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      if( p_file->data.handle == NULL )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_fopen, &st );
      else
	{
	  if( feof( p_file->data.handle ) == 0 )
	      if( ferror( p_file->data.handle ) )
		  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_fio, &st );

	  clearerr( p_file->data.handle );
	}
    }

  return st;
}

t_status fs_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL || p_eof == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      t_size cap = (t_size) 0;
      void * p_data = NULL;

      if( p_file->state != osapi_fs_e_file_opened )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_fopen, &st );

      if( status_success( st ) )
	  st = common_buffer_getData( p_buffer, &p_data );

      if( status_success( st ) )
	  st = common_buffer_getCapacity( p_buffer, &cap );

      if( status_success( st ) )
	{
	  size_t sz = fread( p_data, (size_t) 1, cap, p_file->data.handle );

	  common_buffer_setSize( (t_size) sz, p_buffer );		// Ignore error, if any

	  if( sz == 0 )
	      st = fs_file_getError( p_file );		// Check if there was an error or simply eof
	}
    }

  return st;
}



t_status fs_file_write( const t_file * p_file, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      t_size current = (t_size) 0;
      void * p_data = NULL;

      if( p_file->state != osapi_fs_e_file_opened )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_fopen, &st );

      if( status_success( st ) )
	  st = common_buffer_getData( p_buffer, &p_data );

      if( status_success( st ) )
	  st = common_buffer_getSize( p_buffer, &current );

      if( status_success( st ) )
	{
	  size_t sz = fwrite( p_data, (size_t) 1, current, p_file->data.handle );
	  if( sz == 0 )
	      st = fs_file_getError( p_file );		// Check if there was an error or simply eof

	  st = common_buffer_setSize( sz, p_buffer );
	}
    }

  return st;
}


#endif // POSIX only implementation
