// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Com module API
//
// *****************************************************************************************

#ifndef OSAPI_COM_PRIVATE_H_
#define OSAPI_COM_PRIVATE_H_

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
#include <common/common_types.h>

// Own declarations


// *****************************************************************************************
//
// Section: Module private functions
//
// *****************************************************************************************


t_status get_ip_string( t_protocol protocol, void * location, t_size strSize, char * string );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_PRIVATE_H_ */
