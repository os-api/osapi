// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a POSIX compliant implementation
//		for directory functionality
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_types.h"
#include "fs/fs_element.h"
#include "fs/fs_dir.h"
#include "fs/fs_link.h"
#include "fs/fs_sysheaders.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_link_open( const t_char * p_path, t_link * p_link )
{
  return posix_link_open( p_path, p_link );
}


t_status fs_link_updateInfo( t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_link == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isLinkNotOpen( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st ); return st;  }

  st = fs_element_updateInfo( &p_link->element );			// First update general element information

  if( status_success( st ) )
      st = posix_get_link_info( p_link );				// Next, get link specific information

  return st;
}



t_status fs_link_createSoft( const t_char * p_source, const t_char * p_target )
{
  return posix_link_createSoft( p_source, p_target );
}


t_status fs_link_createHard( const t_char * p_source, const t_char * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( link( p_target, p_source ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}


/*
t_status fs_link_copy( const t_char * p_source, const t_char * p_target )
{
  return posix_link_copy( p_source, p_target );
}
*/


// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************

t_status posix_link_open( const t_char * p_path, t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_link == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isLinkOpen( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_isOpen, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  p_link->link.state = osapi_fs_ostate_closed;

  st = fs_element_open( p_path, &p_link->element );	// Get element information

  if( status_failure( st ) ) return st;

  if( isTypeNotLink( p_link ) )
    {
      fs_element_close( &p_link->element );		// Ignore return, best effort
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st );
      return st;
    }

  st = posix_get_link_info( p_link );			// Get link information

  if( status_success( st ) )
      p_link->link.state = osapi_fs_ostate_opened;
  else
    {
      fs_element_close( &p_link->element );		// Ignore return, best effort
      fs_link_close( p_link );
    }

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


t_status posix_link_createSoft( const t_char * p_source, const t_char * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( symlink( p_target, p_source ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}

/*
t_status posix_link_copy( const t_char * p_source, const t_char * p_target )
{
  t_status	st;
  t_dir		dir;
  t_link	link;
  char		str1[ OSAPI_PATH_MAX ];
  char		str2[ OSAPI_PATH_MAX ];

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = posix_link_open( p_source, &link );
  if( status_success( st) )
    {
      // Make sure that target is a directory
      st = fs_directory_open( p_target, &dir );
      if( status_success( st) )
	{
	  // Get the link target and type
	  char * p_link_destination, * p_link_name;

	  if( status_success( fs_link_getTarget( &link, &p_link_destination ) ) &&
	      status_success( fs_link_getName  ( &link, &p_link_name ) ) )
	    {
	      strncpy( str1, p_source, OSAPI_PATH_MAX );		// Copy source pathname first
	      char * ptr = basename( str1 );				// Get the element name

	      t_size sz = strlen( ptr );
	      strncpy( str2, p_target, OSAPI_PATH_MAX - sz - 2 );

	      if( strcmp( str2, p_target ) != 0 )	// Sanity check
		  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_strcpy, &st );
	      else
		{
		  strcat(  str2, "/" );
		  strncat( str2, ptr, sz );

		  st = fs_link_createSoft( str2, p_link_destination );
		}
	    }

	  fs_directory_close( &dir );
	}

      fs_link_close( &link );
    }

  return st;
}
*/

#endif // POSIX only implementation
