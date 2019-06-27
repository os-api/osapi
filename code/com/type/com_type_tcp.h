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
#include <common/common_types.h>
#include "general/general_protocol.h"

// Include own headers


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


struct s_tcp
{
 t_ip		ip;
 t_lport	port;
};

typedef struct s_tcp t_tcp;

#endif /* OSAPI_COM_TYPE_TCP_H_ */
