// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Net module using a POSIX compliant implementation
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
#include <netinet/in.h>
#include <arpa/inet.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/error_net.h"
#include "status/status.h"
#include "common/common_types_if.h"
#include "common/common_types_ip.h"

// Own declarations
#include "net/net.h"
#include "net/net_private.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status net_ip_getHost( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      if( p_ip->protocol == e_protocol_ipv4 )
	  p_source = (void *) &(p_ip->address.ipv4.field.host);
      else if( p_ip->protocol == e_protocol_ipv6 )
	  p_source = (void *) &(p_ip->address.ipv6);

      st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


t_status net_ip_getMask( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      if( p_ip->protocol == e_protocol_ipv4 )
	  p_source = (void *) &(p_ip->address.ipv4.field.mask);
      else
	  status_iset( OSAPI_MODULE_NET, __func__, e_net_invmask, &st );

      if( status_success( st ) )
	  st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


t_status net_ip_getTarget( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      if( p_ip->protocol == e_protocol_ipv4 )
	{
	  if( p_ip->type_target == OSAPI_IP_TARGET_BROADCAST )
	      p_source = (void *) &(p_ip->address.ipv4.field.broadcast);
	  else if ( p_ip->type_target == OSAPI_IP_TARGET_POINT2POINT )
	      p_source = (void *) &(p_ip->address.ipv4.field.p2p);
	}

      if( p_source == 0 )
	  status_iset( OSAPI_MODULE_NET, __func__, e_net_target, &st );
      else
	  st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


#endif // POSIX only implementation
