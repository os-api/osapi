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
enum protocol_X {
	  #include <general/mappings/table_protocol.h>
};
#undef osapi_protocol_X


#define osapi__protocol_selector_X(a, b, c) a b,
enum selectors_X {
	  #include <general/mappings/table_protocol_selector.h>
};
#undef osapi__protocol_selector_X



#endif /* OSAPI_GENERAL_PROTOCOL_H_ */
