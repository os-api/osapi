// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Sec(urity) module API
//
// *****************************************************************************************

#ifndef NET_PRIVATE_H_
#define NET_PRIVATE_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "status/status_types.h"

// Common includes
#include "common/common_types.h"

// Own declarations


// *****************************************************************************************
//
// Section: Net(work) module private functions
//
// *****************************************************************************************


t_status get_ip_string( t_protocol protocol, void * location, t_size strSize, char * string );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* NET_PRIVATE_H_ */
