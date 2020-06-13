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
#include "status/trace_macros.h"
#include "common/common.h"

// Own declarations
#include "fs/fs.h"
#include "fs/posix/fs_posix.h"
#include "fs/sys/fs_internal.h"
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

  TRACE_ENTER

  if( p_link == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isLinkNotOpen( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st ); return st;  }

  st = fs_element_updateInfo( &p_link->element );			// First update general element information

  if( status_success( st ) )
      st = posix_link_getInfo( p_link );				// Next, get link specific information

  TRACE_EXIT

  return st;
}



t_status fs_link_createSoft( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  return posix_link_createSoft( p_source, p_target, overwrite );
}


t_status fs_link_createHard( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( link( p_target, p_source ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  TRACE_EXIT

  return st;
}



t_status fs_link_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  return posix_link_copy( p_source, p_target, overwrite );
}



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************

t_status posix_link_open( const t_char * p_path, t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

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

  st = posix_link_getInfo( p_link );			// Get link information

  if( status_success( st ) )
      p_link->link.state = osapi_fs_ostate_opened;
  else
    {
      fs_element_close( &p_link->element );		// Ignore return, best effort
      fs_link_close( p_link );
    }

  TRACE_EXIT

  return st;
}


t_status posix_link_getInfo( t_link * p_link )
{
  t_status		st;
  char			buf[ OSAPI_PATH_MAX ];

  status_reset( & st );

  TRACE_ENTER

  if( p_link == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any link specific information
  if( isTypeNotLink( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  memset( buf, '\0', OSAPI_PATH_MAX);		// Ensure buffer is reseted
  ssize_t sz = readlink( p_link->element.fullpath, buf, OSAPI_PATH_MAX - 1 );

  if( sz == -1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  TRACE_MSG( "Obtain an absolute path for the link target" )
  st = fs_path_getAbsolute( buf, OSAPI_PATH_MAX, p_link->link.target );

  TRACE_EXIT

  return st;
}


t_status posix_link_createSoft( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  t_status	st;
  bool		exists = false;

  status_reset( & st );

  TRACE( "Entering with source (%s) and target (%s). Overwrite (%d) ", p_source, p_target, (int) overwrite )

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = fs_element_exists( p_source, &exists );
  if( status_failure( st ) ) return st;

  if( exists )
    {
      if( ! overwrite )
        { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elexists, &st ); return st; }

      st = fs_element_remove( p_source );
    }

  if( status_success( st ) && symlink( p_target, p_source ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  TRACE_EXIT

  return st;
}


t_status posix_link_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
 t_status	st;
 t_link		link;
 t_fs_eType	dtype;

 status_reset( & st );

 TRACE_ENTER

 if( p_source == NULL || p_target == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = posix_link_open( p_source, &link );
 if( status_failure( st ) ) return st;

 // Target can be a new link name or a directory
 st = fs_element_getType( p_target, &dtype );

 if( status_failure( st ) )
   {
     // If getting the type of the copy target results in error, this is fine as long as the error is that there is no target
     if( ! status_error( st, ENOENT ) )
       {
	 TRACE( "Error found when getting the file destination target type:%d", st.code )
	 return st;
       }

     st = posix_link_copy2link( &link, p_target, overwrite );
   }
 else   					// Element exists
   {
     switch( dtype )
	   {
	     case osapi_fs_type_directory: st = posix_link_copy2directory( &link, p_target, overwrite ); break;
	     case osapi_fs_type_softLink:
	     case osapi_fs_type_hardLink:
					   if( overwrite )
					       st = posix_link_copy2link( &link, p_target, overwrite );
					   else
					     {
					       TRACE_MSG( "Target of link already exists and overwrite is false" )
					       status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_lexists, &st );
					       return st;
					     }
					   break;
	     default:
					   TRACE_MSG( "Target of link already exists and is not a directory" )
					   status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_invDest, &st );
					   return st;
	   }

   }

 fs_link_close( &link );

 TRACE_EXIT

 return st;
}


t_status posix_link_copy2directory( const t_link * p_source, const t_char * p_target, bool overwrite )
{
 t_status	st;
 char * 	srcName = NULL;
 char		dest[ OSAPI_PATH_MAX + 1 ];

 status_reset( & st );

 TRACE( "Entering with target:%s", p_target )

 if( p_source == NULL || p_target == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 dest[ OSAPI_PATH_MAX ] = '\0';

 st = fs_elementInfo_getName( &p_source->element, &srcName );
 if( status_failure( st ) ) return st;

 t_size sz = strlen( srcName );
 strncpy( dest, p_target, OSAPI_PATH_MAX - sz - 2 );

 if( strcmp( dest, p_target ) != 0 )	// Sanity check
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_strcpy, &st ); return st; }

 strcat ( dest, "/" );
 strncat( dest, srcName, sz + 1 );

 TRACE( "Creating link (%s)", dest )

 st = posix_link_createSoft( dest, p_source->link.target, overwrite );

 TRACE_EXIT

 return st;
}

t_status posix_link_copy2link( const t_link * p_source, const t_char * p_target, bool overwrite )
{
 t_status	st;
 char * 	srcName = NULL;
 char		dest	[ OSAPI_PATH_MAX + 1 ];

 status_reset( & st );

 TRACE( "Entering with target:%s", p_target )

 if( p_source == NULL || p_target == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }


 st = fs_elementInfo_getName( &p_source->element, &srcName );
 if( status_failure( st ) ) return st;

 t_size sz = strlen( srcName );

 const char * ptr = strrchr( p_target, '/' );
 size_t len = strlen( p_target ) - strlen( ptr );

 if( len + sz + 1 > OSAPI_PATH_MAX )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_pathsize, &st ); return st; }

 // Build destination pathname
 strncpy( dest, p_target, OSAPI_PATH_MAX - 1 );
 strcat ( dest, "/" );
 strncat( dest, srcName, sz + 1 );
 dest[ OSAPI_PATH_MAX ] = '\0';

 TRACE( "%s%s", "The destination link to be created is:", dest );

 st = posix_link_createSoft( dest, p_source->link.target, overwrite );

 TRACE_EXIT

 return st;
}



#endif // POSIX only implementation
