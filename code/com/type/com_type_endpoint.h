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

/// Define a generic connection endpoint type
struct osapi_connection_endpoint_S
{
  t_protocol	protocol;		///< Connection protocol

  /// Superset of all supported protocol information for the endpoint (based on the protocol field)
  union osapi_connection_endpoint_U
  {
    t_ip	ep_ip;			///< Connection IP information
    t_tcp	ep_tcp;			///< Connection TCP information
  } ep;					///< Connection Endpoint
};


/// The generic endpoint type
typedef struct osapi_connection_endpoint_S	t_endpoint;



#endif /* OSAPI_COM_TYPE_ENDPOINT_H_ */
