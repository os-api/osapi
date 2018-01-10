/*
 * sec_posic.c
 *
 *  Created on: 03/01/2018
 *      Author: joao
 */

#include <errno.h>

#include <sec/sec.h>
#include <sec/sec_posix.h>
#include <error/error_sec.h>

t_status sec_userID_get( t_user_id * p_id )
{
  t_status	st;

  status_reset( & st );

  if( p_id == (t_user_id *) 0 )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      *p_id = (t_user_id) getgid();
      if( *p_id == -1 )
          status_iset( OSAPI_MODULE_PROC, __func__, errno, &st );
    }

  return st;
}

t_status sec_groupID_get( t_group_id * p_id )
{
  t_status	st;

  status_reset( & st );

  if( p_id == (t_group_id *) 0 )
      status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
  else
    {
      *p_id = (t_group_id) getgid();
      if( *p_id == -1 )
          status_iset( OSAPI_MODULE_PROC, __func__, errno, &st );
    }

  return st;
}

