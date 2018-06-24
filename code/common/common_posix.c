// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module using a POSIX compliant implementation
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
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_types.h"
#include "status/status.h"

// Own declarations
#include "common/common.h"
#include "common/common_priv_posix.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

size_t get_size_pwd_entry( void )
{
  size_t size = (size_t) sysconf(_SC_GETPW_R_SIZE_MAX );
  
  if( size == -1 )          /* Value was indeterminate */
      size = 16384;        /* Should be more than enough */

 return size;
}

size_t get_size_grp_entry( void )
{
  size_t size = (size_t) sysconf( _SC_GETGR_R_SIZE_MAX );
  
  if( size == -1 )          /* Value was indeterminate */
      size = 16384;        /* Should be more than enough */

 return size;
}


void set_common_status( int code, const char * funcname, t_status * p_status )
{
 if( code == 0 )
     status_iset( OSAPI_MODULE_NONE, funcname, OSAPI_ERROR_UNKNOWN, p_status );			// Empty result
 else
     status_iset( OSAPI_MODULE_NONE, funcname, code, p_status );				// Some error
}

// User functions

t_status get_userID( t_uid * p_id )
{
  t_status st;

  status_reset( &st );
  
  if( p_id == (t_uid *) 0 )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
  else
      *p_id = getuid();   

  return st;
}

t_status set_userID( t_uid id )
{
  t_status st;
  int	   rc = -1;

  status_reset( &st );
  
  rc = setuid( id );
  
  if( rc != 0 )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );

  return st;
}

t_status get_primaryGroupID( t_uid uid, t_gid * primaryGroupID )
{
  t_status 			st;
  int				rc;
  char *			buf;
  struct passwd			pwd;
  struct passwd *		result;

  status_reset( &st );

  size_t bufsize = get_size_pwd_entry();
  buf = malloc( bufsize );

  if( buf == NULL )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
  else
    {
      rc = getpwuid_r( uid, &pwd, buf, bufsize, &result);
      if( result == NULL )
          set_common_status( rc, __func__, &st );
      else
	  *primaryGroupID = pwd.pw_gid;

      free( buf );
    }

  return st;
}


t_status get_username_from_id( t_uid uid, size_t max_name, char * p_name )
{
  t_status 			st;
  int				rc;
  char *			buf;
  struct passwd		pwd;
  struct passwd *	result;

  status_reset( &st );

  size_t bufsize = get_size_pwd_entry();
  buf = malloc( bufsize );
  
  if( buf == NULL )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
  else
    {
      rc = getpwuid_r( uid, &pwd, buf, bufsize, &result);
      if( result == NULL )
          set_common_status( rc, __func__, &st );
      else
          strncpy( p_name, pwd.pw_name, max_name );

      free( buf );
    }
    
  return st;
}

t_status get_userID_from_name( char * username, t_uid * p_uid )
{
  t_status 			st;
  int				rc;
  char *			buf;
  struct passwd		pwd;
  struct passwd *	result;

  status_reset( &st );

  size_t bufsize = get_size_pwd_entry();
  buf = malloc( bufsize );
    
  if( buf == NULL )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
  else
    {
      rc = getpwnam_r( username, &pwd, buf, bufsize, &result );
      if( result == NULL )
          set_common_status( rc, __func__, &st );
      else
          *p_uid = pwd.pw_uid;
        
      free( buf );
    }
    
  return st;
}


t_status get_max_length_username( t_size * p_size )
{
  t_status	st;
  long		size = -1;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
  else
    {
      errno = 0;
      size = sysconf( _POSIX_LOGIN_NAME_MAX );
      if( size == -1 && errno != 0 )			// Got error
	  status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
      else
          *p_size = (t_size) size;
    }

  return st;
}



// Group functions

t_status get_groupID( t_gid * p_gid )
{
  t_status st;

  status_reset( &st );
  
  if( p_gid == (t_gid *) 0 )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
  else
      *p_gid = getgid();   

  return st;
}

t_status set_groupID( t_uid id )
{
  t_status st;
  int	   rc = -1;

  status_reset (&st);
  
  rc = setuid( id );
  
  if( rc != 0 )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );

  return st;
}

t_status get_groupname_from_id( t_gid gid, size_t max_name, char * p_groupname )
{
  t_status 			st;
  int				rc;
  char *			buf;
  struct group		grp;
  struct group *	result;

  status_reset( &st );

  size_t bufsize = get_size_grp_entry();
  buf = malloc( bufsize );
 
  if( buf == NULL )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
  else
    {
      rc = getgrgid_r( gid, &grp, buf, bufsize, &result );
      if( result == NULL )
          set_common_status( rc, __func__, &st );
      else
          strncpy( p_groupname, grp.gr_name, max_name );
        
      free( buf );
    }
    
  return st;
}

t_status get_groupID_from_name( char * groupname, t_gid * p_gid )
{
  t_status 			st;
  int				rc;
  char *			buf;
  struct group		grp;
  struct group *	result;

  status_reset( &st );

  size_t bufsize = get_size_grp_entry();
  buf = malloc( bufsize );
     
  if( buf == NULL )
      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
  else
    {
      rc = getgrnam_r( groupname, &grp, buf, bufsize, &result );
      if( result == NULL )
          set_common_status( rc, __func__, &st );
      else
          *p_gid = grp.gr_gid;
        
      free( buf );
    }
    
  return st;
}

t_status get_max_number_groups( t_size * p_size	)
{
  t_status	st;
  long		size = -1;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
  else
    {
      errno = 0;
      size = sysconf( _SC_NGROUPS_MAX + 1 );
      if( size == -1 && errno != 0 )			// Got error
	  status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
      else
          *p_size = (t_size) size;
    }

  return st;
}


#endif	// If POSIX is defined
