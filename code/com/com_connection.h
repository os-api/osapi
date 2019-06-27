// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Connection management functions
//
// *****************************************************************************************

#ifndef OSAPI_COM_CONNECTION_H_
#define OSAPI_COM_CONNECTION_H_

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
#include "com/com_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The communication module IPC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API for Connections
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Accepts connections for any valid URI
/// @param [in] uri - The connection identification string
/// @param [out] connection - Connection information
/// @return Success or error information.
t_status com_connection_accept( char * uri, t_connection * connection );

/// @brief Creates a connection to any valid URI
/// @param [in] uri - The connection identification string
/// @param [out] connection - Connection information
/// @return Success or error information.
t_status com_connection_establish( char * uri, t_connection * connection );

/// @brief Closes an established connection
/// @param [in] connection - Connection address
/// @return Success or error information.
t_status com_connection_close( t_connection * connection );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_CONNECTION_H_ */
