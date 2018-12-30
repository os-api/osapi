// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for IP (IP type is used by several modules)
//
// *****************************************************************************************

#ifndef TYPES_COMMON_TYPES_IP_H_
#define TYPES_COMMON_TYPES_IP_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdbool.h>

// OSAPI headers
#include "general/general_types.h"
#include "general/general_protocol.h"

// Include own headers
#include "common/types/common_types_if.h"

// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

#define osapi_is_ip_valid_selector( s )		( s==e_protocol_ip || s==e_protocol_ipv4 || e_protocol_ipv6 ? true : false 		)
#define osapi_is_ip_valid_family( f )		( f==e_protocol_ipv4 || f==e_protocol_ipv6 ? true : false				)
#define osapi_is_ipv4_selection( s, f )		( ( s==e_protocol_ip || s==e_protocol_ipv4 ) && f==e_protocol_ipv4  ? true : false	)
#define osapi_is_ipv6_selection( s, f )		( ( s==e_protocol_ip || s==e_protocol_ipv6 ) && f==e_protocol_ipv6  ? true : false	)

#define osapi_is_ipv4_family( f )		( f==e_protocol_ipv4  ? true : false )
#define osapi_is_ipv6_family( f )		( f==e_protocol_ipv6  ? true : false )

// Macros for checking additional IP information
#define osapi_is_ip_address_broadcast( a )	( (a & IFF_BROADCAST)   ? true : false )
#define osapi_is_ip_address_loopback ( a )	( (a & IFF_LOOPBACK)    ? true : false )
#define osapi_is_ip_address_up( a )		( (a & IFF_UP)          ? true : false )
#define osapi_is_ip_address_running( a )	( (a & IFF_RUNNING)     ? true : false )
#define osapi_is_ip_address_multicast( a )	( (a & IFF_MULTICAST)   ? true : false )
#define osapi_is_ip_address_promisc( a )	( (a & IFF_PROMISC)     ? true : false )
#define osapi_is_ip_address_ptp( a )		( (a & IFF_POINTOPOINT) ? true : false )

#define OSAPI_IP_TARGET_NONE		0
#define OSAPI_IP_TARGET_BROADCAST	1
#define OSAPI_IP_TARGET_POINT2POINT	2

// Size that it takes to create a string with an IP address
#define OSAPI_IPV4_ADDRESS_SIZE		4
#define OSAPI_IPV6_ADDRESS_SIZE		16

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


typedef int		t_address_type;

struct s_ipv4_address
{
  Byte			host		[ OSAPI_IPV4_ADDRESS_SIZE ];	// IP address
  Byte			mask		[ OSAPI_IPV4_ADDRESS_SIZE ];	// Network mask
  Byte			broadcast	[ OSAPI_IPV4_ADDRESS_SIZE ];	// Broadcast address type or
  Byte			p2p		[ OSAPI_IPV4_ADDRESS_SIZE ];	// Point to Point address type
};

union u_ipv4_address
{
  struct s_ipv4_address	field;						// Select individual fields
  Byte			raw		[ OSAPI_IPV6_ADDRESS_SIZE ];	// Array of the same number of bytes as IPV6 address
};

union u_ip_address
{
  union u_ipv4_address	ipv4;
  Byte			ipv6		[ OSAPI_IPV6_ADDRESS_SIZE ];
};

typedef union u_ip_address	t_ip_address;

struct s_ip
{
  char			interface_name	[ OSAPI_INTERFACE_MAX_NAME_SIZE ];
  t_protocol		protocol;	// V4/V6
  t_ip_address		address;	// IP address
  t_address_type	type_target;	// BroadCast / PtP
  //t_mac_address	mac;
};

typedef struct s_ip	t_ip;



#endif /* TYPES_COMMON_TYPES_IP_H_ */
