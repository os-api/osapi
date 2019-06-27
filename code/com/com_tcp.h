// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Com(munication) module API for TCP
//
// *****************************************************************************************

#ifndef OSAPI_COM_TCP_H_
#define OSAPI_COM_TCP_H_

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

// Common headers
#include "common/types/common_types_ip.h"

// Own declarations
#include "com/type/com_type_tcp.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The TCP section of the communication module
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
/// @param [in] ip - A source or target IP
/// @param [in] port - A source or target Port
/// @param [out] tcp - A combination of IP and Port
/// @return Operation status
t_status com_tcp_create( t_ip ip, t_lport port, t_tcp * tcp );


/// @brief Destroy the resources associated with a TCP type
/// @param [in] tcp - TCP type address
/// @return Operation status
t_status com_tcp_destroy( t_tcp * tcp );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_TCP_H_ */
