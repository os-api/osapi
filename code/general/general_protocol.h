// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OSAPI Protocols
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_PROTOCOL_H_
#define OSAPI_GENERAL_PROTOCOL_H_

// Include protocol IDs

#define osapi_protocol_X(a, b, c) a b,
enum osapi_protocol_E {
	  #include "general/mappings/table_protocol.h"
};
#undef osapi_protocol_X


#define osapi_protocol_selector_X(a, b, c) a b,
enum osapi_protocol_selector_E {
	  #include "general/mappings/table_protocol_selector.h"
};
#undef osapi_protocol_selector_X


// Protocol alias
#define osapi_protocol_ipv4	osapi_protocol_inet
#define osapi_protocol_ipv6	osapi_protocol_inet6


#endif /* OSAPI_GENERAL_PROTOCOL_H_ */
