// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Net module private implementation
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
#include <common/types/common_types_if.h>
#include <common/types/common_types_ip.h>
#include <error/modules/error_net.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "status/status.h"
#include "net/net_private.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status get_ip_string( t_protocol protocol, void * p_location, t_size strSize, char * p_string )
{
  t_status	st;

  status_reset( & st );

  if( p_location == NULL || p_string == NULL || ! osapi_is_ip_valid_family( protocol) || strSize == 0 )
      status_iset( OSAPI_MODULE_NET, __func__, e_net_params, &st );
  else
    {
      errno = 0;
      if( inet_ntop( protocol, p_location, p_string, (socklen_t) strSize ) == NULL )
	  status_eset( OSAPI_MODULE_NET, __func__, errno, &st );
    }

  return st;
}


