// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec(urity) module implementation for identity functions
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
#include <limits.h>
#include <errno.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_sec.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "sec/sec_identity.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// User ID functions

t_status sec_user_stringToId( char * p_string, t_gid * p_uid )
{
  t_status	st;

  status_reset( & st );

  if( p_uid == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = stringTo_uid( p_string, p_uid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}


t_status sec_user_idToString( t_uid uid, t_size strSize, char * p_string )
{
  t_status	st;

  status_reset( & st );

  if( strSize <= 0 || p_string == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = uidTo_string( uid, strSize, p_string );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}

t_status sec_user_compare( t_uid uid1, t_uid uid2, bool * p_result )
{
  return uid_compare( uid1, uid2, p_result );
}


t_status sec_user_getId( t_uid * p_uid )
{
  t_status	st;

  status_reset( & st );

  if( p_uid == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = get_userID( p_uid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}

t_status sec_user_setId( t_uid uid )
{
  t_status	st;

  status_reset( & st );

  t_status nst = set_userID( uid );

  if( status_failure( nst ) )
      status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );

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
      t_status nst = get_userID_from_name( username, p_uid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}

t_status sec_user_getNameFromID( t_uid uid, t_size max_name, char * username )
{
  t_status	st;

  status_reset( & st );

  if( username == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      // size_t max_name = (size_t) sysconf( _POSIX_LOGIN_NAME_MAX );

      t_status nst = get_username_from_id( uid, max_name, username );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}


t_status sec_user_getMaxSize( t_size * p_size )
{
 return get_max_length_username( p_size );
}


t_status sec_user_getGroups( t_uid uid, size_t groupListMaxSize, size_t * p_groupListCurSize, t_gid *  p_groupList )
{
  t_status	st;

  status_reset( & st );

  if( p_groupList == NULL || p_groupListCurSize == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = get_user_group_list( uid, groupListMaxSize, p_groupListCurSize, p_groupList );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}



// Group ID functions

t_status sec_group_stringToId( char * p_string, t_gid * p_gid )
{
  t_status	st;

  status_reset( & st );

  if( p_gid == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = stringTo_gid( p_string, p_gid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}


t_status sec_group_idToString( t_gid gid, t_size strSize, char * p_string )
{
  t_status	st;

  status_reset( & st );

  if( strSize <= 0 || p_string == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = gidTo_string( gid, strSize, p_string );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}

t_status sec_group_compare( t_gid gid1, t_gid gid2, bool * p_result )
{
  return gid_compare( gid1, gid2, p_result );
}


t_status sec_group_getId( t_gid * p_gid )
{
  t_status	st;

  status_reset( & st );

  if( p_gid == NULL )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      t_status nst = get_groupID( p_gid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}

t_status sec_group_setId( t_gid gid )
{
  t_status	st;

  status_reset( & st );

  t_status nst = set_groupID( gid );

  if( status_failure( nst ) )
      status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );

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
      t_status nst = get_groupID_from_name( groupname, p_gid );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
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
      t_status nst = get_groupname_from_id( gid, size, groupname );

      if( status_failure( nst ) )
          status_set( OSAPI_MODULE_SEC, nst.type, __func__, nst.code, &st );
    }

  return st;
}


t_status sec_group_getMaxSize( t_size * p_size )
{
  return get_max_length_groupname( p_size );
}

t_status sec_group_getMaxNumber( t_size * p_size )
{
  return get_max_number_groups( p_size );
}

