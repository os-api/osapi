// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Com(munication) module API for a generic endpoint
//
// *****************************************************************************************

#ifndef OSAPI_COM_ENDPOINT_H_
#define OSAPI_COM_ENDPOINT_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "com/type/com_type_endpoint.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The endpoint section of the communication module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Create a TCP type based on IP and logical Port
/// @param [in] prot - The endpoint communication protocol
/// @param [out] ep - Communication endpoint
/// @return Operation status
t_status com_endpoint_create( t_protocol prot, t_endpoint * ep );


/// @brief Destroy the resources associated with an endpoint
/// @return Operation status
t_status com_endpoint_destroy( t_endpoint * ep );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_ENDPOINT_H_ */
