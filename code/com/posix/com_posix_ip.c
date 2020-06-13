// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Com module using a POSIX compliant implementation
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
#include "error/modules/error_com.h"
#include "status/status.h"

// Own declarations
#include "com/com.h"
#include "com/com_private.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

t_status com_ip_getStringSize( t_protocol prot, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      if( prot == osapi_protocol_ipv4 )
	  *p_size = INET_ADDRSTRLEN;
      else if( prot == osapi_protocol_ipv6 )
	  *p_size = INET6_ADDRSTRLEN;
      else
	{
	  *p_size = 0;
	  status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_support, &st );
	}
    }

  return st;
}


t_status com_ip_getHost( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      if( p_ip->protocol == osapi_protocol_ipv4 )
	  p_source = (void *) &(p_ip->address.ipv4.field.host);
      else if( p_ip->protocol == osapi_protocol_ipv6 )
	  p_source = (void *) &(p_ip->address.ipv6);

      st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


t_status com_ip_getMask( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      if( p_ip->protocol == osapi_protocol_ipv4 )
	  p_source = (void *) &(p_ip->address.ipv4.field.mask);
      else
	  status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_invmask, &st );

      if( status_success( st ) )
	  st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


t_status com_ip_getTarget( t_ip * p_ip, t_size size, char * p_string )
{
  t_status	st;
  void	*	p_source = 0;

  status_reset( & st );

  if( p_ip == NULL || p_string == NULL )
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
  else
    {
      if( p_ip->protocol == osapi_protocol_ipv4 )
	{
	  if( p_ip->type_target == OSAPI_IP_TARGET_BROADCAST )
	      p_source = (void *) &(p_ip->address.ipv4.field.broadcast);
	  else if ( p_ip->type_target == OSAPI_IP_TARGET_POINT2POINT )
	      p_source = (void *) &(p_ip->address.ipv4.field.p2p);
	}

      if( p_source == 0 )
	  status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_target, &st );
      else
	  st = get_ip_string( p_ip->protocol, p_source, size, p_string );
    }

  return st;
}


#endif // POSIX only implementation
