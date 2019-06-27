// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	COM type declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_TYPE_ENDPOINT_H_
#define OSAPI_COM_TYPE_ENDPOINT_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers

// General OSAPI headers
#include <common/common_types.h>
#include "general/general_protocol.h"
#include "com/type/com_type_tcp.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


struct s_connection_endpoint
{
  t_protocol	protocol;

  union u_connection_endpoint
  {
    t_ip	ep_ip;
    t_tcp	ep_tcp;
  } ep;
};

typedef struct s_connection_endpoint t_endpoint;



#endif /* OSAPI_COM_TYPE_ENDPOINT_H_ */
