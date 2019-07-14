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
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_helper.h"
#include "fs/posix/fs_posix.h"
#include "fs/posix/fs_posix_priv.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

// *****************************************************************************************
//
// Section: POSIX private function definition
//
// *****************************************************************************************


t_fs_eType posix_get_element_type( mode_t m )
{
  if( S_ISREG ( m ) ) return osapi_fs_type_file;
  if( S_ISDIR ( m ) ) return osapi_fs_type_directory;
  if( S_ISCHR ( m ) ) return osapi_fs_type_charDevice;
  if( S_ISBLK ( m ) ) return osapi_fs_type_blockDevice;
  if( S_ISFIFO( m ) ) return osapi_fs_type_fifo;
  if( S_ISLNK ( m ) ) return osapi_fs_type_softLink;
  if( S_ISSOCK( m ) ) return osapi_fs_type_socket;

  return osapi_fs_type_unknown;
}


t_status posix_element_open( const t_char * p_path, t_element * p_element )
{
  t_status		st;
  char		*	p_string;;

  status_reset( & st );

  if( p_path == NULL || p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  p_element->state = osapi_fs_ostate_closed;

  // Store the full pathname to element for latter usage
  p_string = realpath( p_path, p_element->fullpath );
  if( p_string != p_element->fullpath )
      strcpy( p_element->fullpath, p_path );			// If not possible to use full path, use relative..

  st = posix_get_element_info( p_element );

  if( status_success( st ) )
      p_element->state = osapi_fs_ostate_opened;

  return st;
}


t_status posix_get_element_info( t_element * p_element )
{
  t_status		st;
  struct stat		buffer;

  status_reset( & st );

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );return st; }

  int rc = lstat( p_element->fullpath, &buffer );
  if( rc == -1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  st = posix_decode_element_info( &buffer, p_element );

  return st;
}


t_status posix_decode_element_info( const struct stat * p_stat, t_fs_elementInfo * p_info )
{
  t_status		st;

  status_reset( & st );

  if( p_stat == NULL || p_info == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Transform a POSIX structure onto a generic one
  p_info->type = posix_get_element_type( p_stat->st_mode );

  return st;
}


int64_t posix_get_fs_open_options( const char ** p_options )
{
  return common_options_get( osapi_fs_open_options,  (char **) p_options );
}


int64_t posix_get_fs_mode_options( const char ** p_options )
{
  return common_options_get( osapi_fs_mode_options,  (char **) p_options );
}


t_status posix_get_element_time( const t_element * p_element, int selector, t_time * p_time )
{
  t_status		st;

  status_reset( & st );

  if( p_element == NULL || p_time == NULL )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( p_element->state != osapi_fs_ostate_opened )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st );
      return st;
    }

  switch( selector )
        {
	  case osapi_fs_time_create:	*p_time = p_element->ctime; break;
	  case osapi_fs_time_modify:	*p_time = p_element->mtime; break;
	  case osapi_fs_time_access:	*p_time = p_element->atime; break;
        }

 return st;
}


t_status posix_open_file( const t_char * p_path, int64_t openMode, int64_t creationMode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_aopen, &st ); return st; }

  p_file->file.state = osapi_fs_ostate_closed;

  p_file->file.descriptor = open( p_path, (int) openMode, (int) creationMode );
  if( p_file->file.descriptor < 0 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  st = posix_get_file_info( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;

  return st;
}

t_status posix_open_filestream( const t_char * p_path, const char * p_options, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_options == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 || strlen( p_options ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_aopen, &st ); return st; }

  p_file->file.state = osapi_fs_ostate_closed;

  st = posix_element_open( p_path, &p_file->element );	// Open Element

  if( status_failure( st ) ) return st;

  p_file->file.handle = fopen( p_path, p_options );

  if( p_file->file.handle == NULL )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  int fd = fileno( p_file->file.handle );
  if( fd == -1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  p_file->file.descriptor = fd;

  st = posix_get_file_info( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;
  else
    {
      fclose( p_file->file.handle );		// Attempt to close file, ignore result
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
    }

  return st;
}

t_status posix_get_file_info( t_file * p_file )
{
  t_status		st;

  status_reset( &st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any directory specific information
  if( isTypeNotFile( p_file ) )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notFile, &st );
  // else...

  return st;
}


t_status posix_get_directory_info( t_dir * p_dir )
{
  t_status		st;

  status_reset( & st );

  if( p_dir == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any directory specific information
  if( isTypeNotDir( p_dir ) )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notDirectory, &st );
  // else...

  return st;
}


t_status posix_get_link_info( t_link * p_link )
{
  t_status		st;

  status_reset( & st );

  if( p_link == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any link specific information
  if( isTypeNotLink( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  ssize_t sz = readlink( p_link->element.fullpath, p_link->link.target, PATH_MAX -1 );
  if( sz == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
      p_link->link.target[ sz ] = '\0';	// Ensure it's always null terminated

  return st;
}

#endif // POSIX only implementation
