// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Net module generic implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Project baseline
#include "general/general_baseline.h"

// System includes

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/error_net.h"
#include "status/status.h"
#include "common/common_types_ip.h"

// Own declarations
#include "net/net.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status net_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}



t_status net_ip_isV4( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->protocol == e_protocol_ipv4 )	*p_result = true;
    }

  return st;
}

t_status net_ip_isV6( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->protocol == e_protocol_ipv6 )	*p_result = true;
    }

  return st;
}


t_status net_ip_isBroadcast( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->type_target == OSAPI_IP_TARGET_BROADCAST ) *p_result = true;
    }

  return st;
}


t_status net_ip_isP2P( t_ip * p_ip, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_ip == NULL || p_result == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      *p_result = false;
      if( p_ip->type_target == OSAPI_IP_TARGET_POINT2POINT ) *p_result = true;
    }

  return st;
}
