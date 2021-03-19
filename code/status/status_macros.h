// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module macros & other definitions
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_MACROS_H_
#define OSAPI_STATUS_MACROS_H_

/// @file status_macros.h
/// @brief File providing public definitions for the status module

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard C headers
#include <stdbool.h>

// Include OSAPI headers
#include "error/error_types.h"


// *****************************************************************************************
//
// Section: Constants/Macros for client applications
//
// *****************************************************************************************

// TODO: Move pointer to reference to speedup operations
/// @brief Resets the status structure (to success)
#define status_reset( x )					( (x)->code = 0 )

/// @brief See status_instance_set function
#define status_set( m, t, f, e, r )			status_instance_set( m, t, f, e, r )

/// @brief See status_instance_setString function
#define status_setString( m, t, f, s, r )	status_instance_setString( m, t, f, s, r )

// Helper definitions for a correct way to check for success/failure of operations
/// @brief Returns true if the operation that returned x was successful
/// @returns True if success, False otherwise
#define status_success( x )					( x.code == 0 )

/// @brief Returns true if the operation that returned x failed
/// @returns True if failed, False otherwise
#define status_failure( x )					( x.code != 0 )

/// @brief Match a given error
/// @returns True if the error code in s is equal to the error e
#define status_error( s, e )				( s.code == e )

/// @brief Check if the status result of the operation is true
/// @returns True if the status x was successful. False otherwise
#define status_true(  x )					( status_failure( x ) ? 0 : 1 )

/// @brief Check if the status result of the operation is true
/// @returns True if status x failed. False otherwise
#define status_false( x )					( status_success( x ) ? 1 : 0 )

/// @brief Get the operation status result: success==true/failure==false
#define status_result( x )					( x.code == 0 ? true : false )

/// @brief Find if a module or facility is supported
/// @returns True if the error code is equal to UNSUPPORTED. False otherwise
#define status_unsupported( s )				( s.code == OSAPI_ERROR_SUPPORT )


#endif /* OSAPI_STATUS_MACROS_H_ */
