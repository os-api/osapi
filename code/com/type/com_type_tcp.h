// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	TCP type declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_TYPE_TCP_H_
#define OSAPI_COM_TYPE_TCP_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers


// General OSAPI headers
#include "general/general_protocol.h"
#include "common/common_types.h"

// Include own headers


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Define a generic TCP connection type
struct osapi_tcp_S
{
 t_ip		ip;		///< The IP information part
 t_lport	port;		///< The Port information part
};

/// The TCP connection type
typedef struct osapi_tcp_S	t_tcp;




#endif /* OSAPI_COM_TYPE_TCP_H_ */
