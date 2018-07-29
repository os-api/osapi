// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine module using a POSIX compliant implementation
//
// *****************************************************************************************

// Compile only if is a Linux implementation
#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Project baseline
#include "general/general_baseline.h"

// System includes
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ifaddrs.h>

#define	__USE_MISC	1	// To select the inclusion of required symbols on the next header
#include <net/if.h>

// (Re)define system functions due to different define symbols required in different Linux versions
extern int gethostname	(char *name, size_t len		);
extern int sethostname	(const char *name, size_t len	);
extern int getdomainname(char *name, size_t len		);
extern int setdomainname(const char *name, size_t len	);

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_machine.h"
#include "status/status.h"

// Own declarations
#include "machine/machine.h"
#include "machine/machine_linux.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


static t_status copy_ip( struct sockaddr * saddress, void * taddress )
{
  t_status	st;

  status_reset( & st );

  if( saddress == NULL || taddress == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      if( osapi_is_ipv4_family( saddress->sa_family ) )
          memcpy( taddress, &(saddress->sa_data)[2], OSAPI_IPV4_ADDRESS_SIZE );
      else if( osapi_is_ipv6_family( saddress->sa_family ) )
	{
	  struct sockaddr_in6 * p_addr_v6 = (struct sockaddr_in6 *) saddress;
	  memcpy( taddress, &(p_addr_v6->sin6_addr), OSAPI_IPV6_ADDRESS_SIZE );
	}
    }

  return st;
}



static t_status fill_ip_structure( struct ifaddrs * p_address, t_ip * p_ip )
{
  t_status	st;

  status_reset( & st );

  if( p_address == NULL || p_ip == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      strncpy( p_ip->interface_name, p_address->ifa_name, OSAPI_INTERFACE_MAX_NAME_SIZE -1 );

      if( osapi_is_ip_valid_family( p_address->ifa_addr->sa_family ) )
	  p_ip->protocol = p_address->ifa_addr->sa_family;

      // Copy host IP
      if( osapi_is_ipv6_family( p_address->ifa_addr->sa_family ) )
	  st = copy_ip( p_address->ifa_addr, &(p_ip->address.ipv6) );
      else if( osapi_is_ipv4_family( p_address->ifa_addr->sa_family ) )
	{
	  st = copy_ip( p_address->ifa_addr, &(p_ip->address.ipv6) );

	  // Break on first failed operation
	  if( status_success( st ) )
	      st = copy_ip( p_address->ifa_netmask, &(p_ip->address.ipv4.field.mask) );

	  if( status_success( st ) )
	    {
	      p_ip->type_target = OSAPI_IP_TARGET_NONE;
	      if( osapi_is_ip_address_broadcast( p_address->ifa_flags ) && p_address->ifa_broadaddr != NULL )
		{	// Broadcast
		  struct sockaddr * p_sa = p_address->ifa_broadaddr;
		  if( status_success( copy_ip( p_sa, &(p_ip->address.ipv4.field.broadcast) ) ) )
		      p_ip->type_target = OSAPI_IP_TARGET_BROADCAST;
		}
	      else if( osapi_is_ip_address_ptp( p_address->ifa_flags ) && p_address->ifa_dstaddr != NULL )
		{	// or Point to Point address
		  struct sockaddr * p_sa = p_address->ifa_dstaddr;
		  if( status_success( copy_ip( p_sa, &(p_ip->address.ipv4.field.p2p) ) ) )
		      p_ip->type_target = OSAPI_IP_TARGET_POINT2POINT;
		}
	    }
	}
    }

  return st;
}


t_status machine_host_setName( t_char * hostname )
{
  t_status	st;
  size_t	len = 0;

  status_reset( & st );

  if( hostname == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      len = strlen( hostname );

      if( sethostname( hostname, len ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}

// Domain name related calls

t_status machine_domain_getName( t_size maxlen, t_char * hostname )
{
  t_status	st;

  status_reset( & st );

  if( hostname == NULL || maxlen <= 0 )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      if( getdomainname( hostname, maxlen ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}

t_status machine_domain_setName( t_char * hostname )
{
  t_status	st;
  size_t	len = 0;

  status_reset( & st );

  if( hostname == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      len = strlen( hostname );

      if( setdomainname( hostname, len ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}


t_status machine_ip_getNumber( t_protocol selector, t_size * number )
{
  t_status		st;
  struct ifaddrs * 	ifaddr, * ifa;
  int			n;
  sa_family_t		family;

  status_reset( & st );
  *number = 0;

  if( selector != e_protocol_ipv4 && selector != e_protocol_ipv6 )
      selector = e_protocol_ip;

  if( number == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      if( getifaddrs( & ifaddr ) == -1 )
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
      else
	{
          // Walk through linked list, maintaining head pointer so we can free list later

          for( ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++)
             {
               if (ifa->ifa_addr == NULL) continue;

               family = ifa->ifa_addr->sa_family;

               // For each requested type, for each AF_INET* interface address, increase the number of matching addresses
               if( osapi_is_ipv4_selection( selector, family ) )
        	 { (*number)++; continue; }

               if( osapi_is_ipv6_selection( selector, family ) )
        	 { (*number)++; }
             }

          // Release memory allocated by call getifaddrs
          freeifaddrs( ifaddr );
	}
    }

  return st;
}

t_status machine_ip_getList( t_protocol selector, t_size number, t_ip * p_list )
{
  t_status		st;
  struct ifaddrs * 	ifaddr, * ifa;
  int			n;
  sa_family_t		family;

  status_reset( & st );

  if( p_list == NULL || ! osapi_is_ip_valid_selector( selector ) )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      if( getifaddrs( & ifaddr ) == -1 )
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
      else
	{
          // Walk through linked list, maintaining head pointer so we can free list later

          for( ifa = ifaddr, n = -1; ifa != NULL; ifa = ifa->ifa_next )
             {
               if (ifa->ifa_addr == NULL) continue;

               family = ifa->ifa_addr->sa_family;

               // Did we find what we were looking for?
               if( osapi_is_ipv4_selection( selector, family ) || osapi_is_ipv6_selection( selector, family ) )
        	 {
        	   // Found matching IP
        	   n++;
        	   if( n < number )
        	       st = fill_ip_structure( ifa, &p_list[ n ] );
        	 }
             }

          // Release memory allocated by call getifaddrs
          freeifaddrs( ifaddr );
	}
    }

  return st;
}





#endif	// If OS_LINUX is defined
