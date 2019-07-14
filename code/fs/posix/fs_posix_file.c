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
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/fs_file.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX




t_status fs_file_open( const t_char * p_path, const char ** p_mode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_mode == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = posix_element_open( p_path, &p_file->element );	// Open Element

  if( status_failure( st ) ) return st;

  int64_t openOptions = posix_get_fs_open_options( p_mode );
  int64_t modeOptions = posix_get_fs_mode_options( p_mode );

  st = posix_open_file( p_path, openOptions, modeOptions,  p_file );

  return st;
}



t_status fs_file_openRead( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "r", p_file );
}

t_status fs_file_openWrite( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "w", p_file );
}

t_status fs_file_openReadWrite( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "r+", p_file );
}


t_status fs_file_setPosition( const t_file * p_file, int initial, t_offset offset )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }


  int64_t rc	= 0;
  errno		= 0;

  if( p_file->file.isBuffered )
      rc = (int64_t) fseek( p_file->file.handle, (long) offset, initial );
  else
      rc = (int64_t) lseek( p_file->file.descriptor, (long) offset, initial );

  if( rc != (int64_t) -1 || errno != 0 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}



t_status fs_file_create( const char * p_path, const char ** p_mode )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  mode_t modeOptions = (mode_t) posix_get_fs_mode_options( p_mode );

  int fd = open( p_path, O_CREAT | O_EXCL | O_RDONLY, modeOptions );	// If file already exists, fail with error

  if( fd == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( close( fd ) == -1 )	// Should we care about close error?
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}



t_status fs_file_close( t_file * p_file )
{
  t_status	st;
  int		rc;

  status_reset( & st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  rc	= 0;
  errno	= 0;

  if( p_file->file.isBuffered )
      fclose( p_file->file.handle );
  else
      rc = close( p_file->file.descriptor );

  if( rc == -1 || errno != 0 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
      p_file->file.state	= osapi_fs_ostate_closed;

      st = fs_element_close( &p_file->element );
    }

  return st;
}


t_status fs_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL || p_eof == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size cap = (t_size) 0;
  void * p_data = NULL;

  st = common_buffer_getData( p_buffer, &p_data );
  if( status_failure( st ) ) return st;

  st = common_buffer_getCapacity( p_buffer, &cap );
  if( status_failure( st ) ) return st;

  int64_t sz	= 0;
  errno		= 0;

  if( p_file->file.isBuffered )
      sz = (int64_t) fread( p_data, (size_t) 1, (size_t) cap, p_file->file.handle );
  else
      sz = (int64_t) read( p_file->file.descriptor, p_data, (size_t) cap );

  if( sz == (int64_t) -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( sz == (ssize_t) 0 ) *p_eof = true;			// EOF reached
      st = common_buffer_setSize( (t_size) sz, p_buffer );
    }

  return st;
}



t_status fs_file_write( const t_file * p_file, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size current = (t_size) 0;
  void * p_data = NULL;

  st = common_buffer_getData( p_buffer, &p_data );
  if( status_failure( st ) ) return st;

  st = common_buffer_getSize( p_buffer, &current );
  if( status_failure( st ) ) return st;

  errno 	= 0;
  int64_t sz	= 0;

  if( p_file->file.isBuffered )
      sz = (int64_t) fwrite( p_data, (size_t) 1, (size_t) current, p_file->file.handle );
  else
      sz = (int64_t) write( p_file->file.descriptor, p_data, (size_t) current );

  if( sz == (int64_t) -1 || (sz == (int64_t) 0 && errno != 0) )
    {
      fprintf( stderr, "P1:%d,%p; %ld,%d,%ld", p_file->file.descriptor, p_file->file.handle, sz, errno, current );
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }
  else
      st = common_buffer_setSize( (t_size) sz, p_buffer );

  return st;
}


#endif // POSIX only implementation
