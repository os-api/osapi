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
#include <unistd.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/posix/fs_posix.h"


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

// *****************************************************************************************
//
// Section: POSIX private function definition
//
// *****************************************************************************************


t_fs_eType get_element_type( mode_t m )
{
  if( S_ISREG ( m ) ) return osapi_fs_e_type_file;
  if( S_ISDIR ( m ) ) return osapi_fs_e_type_directory;
  if( S_ISCHR ( m ) ) return osapi_fs_e_type_charDevice;
  if( S_ISBLK ( m ) ) return osapi_fs_e_type_blockDevice;
  if( S_ISFIFO( m ) ) return osapi_fs_e_type_fifo;
  if( S_ISLNK ( m ) ) return osapi_fs_e_type_softLink;
  if( S_ISSOCK( m ) ) return osapi_fs_e_type_socket;

  return osapi_fs_e_type_unknown;
}


t_status get_element_info( const t_char * p_element, struct stat * p_info )
{
  t_status		st;

  status_reset( & st );

  if( p_element == NULL || p_info == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      int rc = lstat( p_element, p_info );
      if( rc == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}


t_status decode_element_info( const struct stat * p_stat, t_fs_elementInfo * p_info )
{
  t_status		st;

  status_reset( & st );

  if( p_stat == NULL || p_info == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      // Transform a POSIX structure onto a generic one
      p_info->type = get_element_type( p_stat->st_mode );

    }

  return st;
}


void set_file_open_mode( bool create, int openMode, int location, char * mode )
{
 switch( openMode )
       {
	 case osapi_fs_e_file_read:	// When reading, ignore create mode and file positioning
					 strncpy( mode, "r", 3 );
					 break;

	 case osapi_fs_e_file_write:
					if( create )
					  {
					    if( location == osapi_fs_e_file_begin )	strncpy( mode, "w", 3 );
					    else					strncpy( mode, "a", 3 );
					  }
					break;

	 case osapi_fs_e_file_readWrite:
	 default:
					if( create )
					  {
					    if( location == osapi_fs_e_file_begin )	strncpy( mode, "w+", 3 );
					    else					strncpy( mode, "a+", 3 );
					  }
					else
					  {
					    if( location == osapi_fs_e_file_begin )	strncpy( mode, "r+", 3 );
					  }
       }
}


t_status get_element_time( const t_fs_elementInfo * p_info, int selector, t_time * p_time )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_time == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      switch( selector )
	    {
	      case osapi_fs_e_time_create:	*p_time = p_info->ctime; break;
	      case osapi_fs_e_time_modify:	*p_time = p_info->mtime; break;
	      case osapi_fs_e_time_access:	*p_time = p_info->atime; break;
	    }
    }

 return st;
}


t_status open_file( const t_char * p_path, const char * p_mode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_mode ==NULL || p_file == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
    {
      p_file->data.handle = fopen( p_path, p_mode );
      if( p_file->data.handle == NULL )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	  p_file->state = osapi_fs_e_file_opened;
    }

  return st;
}

#endif // POSIX only implementation
