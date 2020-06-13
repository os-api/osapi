// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Com module generic implementation
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

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_com.h"
#include "status/status.h"

// Import own headers
#include "com/com_ip.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status com_ip_isV4( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->protocol == osapi_protocol_ipv4 )	*p_result = true;
    }

  return st;
}

t_status com_ip_isV6( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->protocol == osapi_protocol_ipv6 )	*p_result = true;
    }

  return st;
}


t_status com_ip_isBroadcast( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->type_target == OSAPI_IP_TARGET_BROADCAST ) *p_result = true;
    }

  return st;
}


t_status com_ip_isP2P( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->type_target == OSAPI_IP_TARGET_POINT2POINT ) *p_result = true;
    }

  return st;
}
