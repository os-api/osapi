/*
 * sec_posic.c
 *
 *  Created on: 03/01/2018
 *      Author: joao
 */

#include <limits.h>

#include "errno.h"
#include "error/error_sec.h"

#include "status/status.h"
#include "common/common.h"
#include "sec/sec.h"
#include "sec/sec_posix.h"


// User ID functions

t_status sec_user_getId( t_uid * p_uid )
{
  t_status	st;

  status_reset( & st );

  if( p_uid == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      st = get_userID( p_uid );
      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}

t_status sec_user_setId( t_uid uid )
{
  t_status	st;

  status_reset( & st );

  st = set_userID( uid );
  t_status_error err = status_error( st );

  if( status_failure( st ) )
      status_eset( OSAPI_MODULE_SEC, __func__, err, &st );

  return st;
}


t_status sec_user_getIdFromName( char * username, t_uid * p_uid )
{
  t_status	st;

  status_reset( & st );

  if( p_uid == NULL || username == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      st = get_userID_from_name( username, p_uid );
      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}

t_status sec_user_getNameFromID( t_uid uid, t_size size, char * username )
{
  t_status	st;

  status_reset( & st );

  if( username == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      size_t max_name = (size_t) sysconf( _POSIX_LOGIN_NAME_MAX );
      st = get_username_from_id( uid, max_name, username );

      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}


// Group ID functions

t_status sec_group_getId( t_gid * p_gid )
{
  t_status	st;

  status_reset( & st );

  if( p_gid == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      st = get_groupID( p_gid );
      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}

t_status sec_group_setId( t_gid gid )
{
  t_status	st;

  status_reset( & st );

  st = set_groupID( gid );
  t_status_error err = status_error( st );

  if( status_failure( st ) )
      status_eset( OSAPI_MODULE_SEC, __func__, err, &st );

  return st;
}



t_status sec_group_getIdFromName( char * groupname, t_gid * p_gid )
{
  t_status	st;

  status_reset( & st );

  if( p_gid == NULL || groupname == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      st = get_groupID_from_name( groupname, p_gid );
      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}

t_status sec_group_getNameFromID( t_gid gid, t_size size, char * groupname )
{
  t_status	st;

  status_reset( & st );

  if( groupname == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      // max size = 32;		// Not sure if this limit is defined somewhere
      st = get_groupname_from_id( gid, size, groupname );

      t_status_error err = status_error( st );
      if( status_failure( st ) )
          status_eset( OSAPI_MODULE_SEC, __func__, err, &st );
    }

  return st;
}


