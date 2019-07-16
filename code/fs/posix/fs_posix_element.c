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
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_element_exists( const t_char * p_path )
{
  t_status		st;
  struct stat		buffer;

  status_reset( & st );

  int rc = lstat( p_path, &buffer );
  if( rc == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}


t_status fs_element_open( const t_char * p_path, t_element * p_element )
{
  return posix_element_open( p_path, p_element );
}


t_status fs_element_updateInfo( t_element * p_element )
{
  t_status		st;

  status_reset( & st );

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( p_element->state != osapi_fs_ostate_opened )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st ); return st; }

  st = posix_get_element_info( p_element );

  return st;
}



t_status fs_element_getAtime( t_element * p_element, t_time * p_time )
{
 return posix_get_element_time( p_element, osapi_fs_time_access, p_time );
}

t_status fs_element_getCtime( t_element * p_element, t_time * p_time )
{
  return posix_get_element_time( p_element, osapi_fs_time_create, p_time );
}

t_status fs_element_getMtime( t_element * p_element, t_time * p_time )
{
  return posix_get_element_time( p_element, osapi_fs_time_modify, p_time );
}



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************



t_fs_eType posix_get_element_type( mode_t m )
{
  switch( m & S_IFMT)
	{
	  case S_IFREG: return osapi_fs_type_file;
	  case S_IFDIR: return osapi_fs_type_directory;
	  case S_IFLNK:	return osapi_fs_type_softLink;
	  case S_IFCHR: return osapi_fs_type_charDevice;
	  case S_IFBLK: return osapi_fs_type_blockDevice;
	  case S_IFIFO: return osapi_fs_type_fifo;
	  case S_IFSOCK:return osapi_fs_type_socket;
	}

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

  strcpy( p_element->fullpath, p_path );

  st = posix_get_element_info( p_element );

  if( status_success( st ) )
      p_element->state = osapi_fs_ostate_opened;

  if( isElementTypeNotLink( p_element ) )
    {
      p_string = realpath( p_path, p_element->fullpath );
      if( p_string != p_element->fullpath )
	  strcpy( p_element->fullpath, p_path );			// Make sure that there is always a path even if relative
    }

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
  p_info->type	= posix_get_element_type( p_stat->st_mode );
  p_info->uid	= p_stat->st_uid;			// Only possible since it's also at POSIX level, otherwise uid_copy
  p_info->gid	= p_stat->st_gid;			// Only possible since it's also at POSIX level, otherwise gid_copy
  p_info->nlink	= (uint64_t) p_stat->st_nlink;
  if( p_stat->st_size < (uint64_t) 0 )
      p_info->size = (uint64_t) 0;
  else
      p_info->size = (uint64_t) p_stat->st_size;	// Size in file system


  // The time can be in several formats.. need to convert to the same one
  //p_info->ctime	= p_stat->;

  return st;
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





#endif // POSIX only implementation
