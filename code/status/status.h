// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_H_
#define OSAPI_STATUS_H_

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
#include "general/general_types.h"

// Own declarations
#include "status/status_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STATUS
/// @brief The OSAPI status module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Status module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Reset the status type
/// @param [out] status - status type
void status_reset( t_status * status );

/// @brief Set the status type with the current status information using an error code
/// @param [in] module - Set the status module
/// @param [in] type - Library information (OSAPI, libc, dl, etc)
/// @param [in] funcname - Name of the function for which status is being provided
/// @param [in] error - Error reported
/// @param [out] status - status type
void status_set( t_module module, t_status_type type , t_status_funcname funcname, t_error error, t_status * status );

/// @brief Set the status type with the current status information using an error string
/// @param [in] module - Set the status module
/// @param [in] type - Library information (OSAPI, libc, dl, etc)
/// @param [in] funcname - Name of the function for which status is being provided
/// @param [in] errorString - String with the error information
/// @param [out] status - status type
void status_setString( t_module module, t_status_type type, t_status_funcname funcname, t_status_string errorString, t_status * status );

/// @brief Write a message with the status information to Standard output
/// @param [in] status - Status information
void status_message_print( t_status status );

/// @brief Get the status information into a message string
/// @param [in] status - Status information
/// @param [in] size - Size of the message string
/// @param [out] message - String with the status information
void status_message_get( t_status status, t_size size, t_char * message	);

// Get component strings of a t_status type
/// @brief Get the module name that corresponds to the provided status information
/// @param [in] status - Status information
/// @return Module name
const char * status_module_get( t_status status	);

/// @brief Get the function name that corresponds to the provided status information
/// @param [in] status - Status information
/// @return Function name

const char * status_function_get( t_status status );

/// @brief Get the error message that corresponds to the provided status information
/// @param [in] status - Status information
/// @return Error string
const char * status_error_get( t_status status );


#pragma GCC visibility pop			// End of public interface


// *****************************************************************************************
//
// Section: Help macros
//
// *****************************************************************************************

// Import macros
#include "status/status_defs.h"

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STATUS_H_ */
