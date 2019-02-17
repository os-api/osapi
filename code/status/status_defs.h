// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module macros & other definitions
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_DEFS_H_
#define OSAPI_STATUS_DEFS_H_

/// @file status_defs.h
/// @brief File providing definitions for the status module

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

/// @brief Maximum size of the error string
/// The t_status type supports either error code or an error string. This last type, the error string,
/// is limited in size to the this value
#define	OSAPI_STATUS_STRING_SIZE	101

// Helper definitions for a correct way to check for success/failure of operations
/// @brief Returns true if the operation that returned x was successful
/// @returns True if success, False otherwise
#define status_success( x )	( x.code == 0 )

/// @brief Returns true if the operation that returned x failed
/// @returns True if failed, False otherwise
#define status_failure( x )	( x.code != 0 )

/// @brief Match a given error
/// @returns True if the error code in s is equal to the error e
#define status_error( s, e )	( s.code == e )

/// @brief Check if the status result of the operation is true
/// @returns True if the status x was successful. False otherwise
#define status_true(  x )	( status_failure( x ) ? 0 : 1 )

/// @brief Check if the status result of the operation is true
/// @returns True if status x failed. False otherwise
#define status_false( x )	( status_success( x ) ? 1 : 0 )

/// @brief Get the operation status result: success==true/failure==false
#define status_result( x )	( x.code == 0 ? true : false )

/// @brief Find if a module or facility is supported
/// @returns True if the error code is equal to UNSUPPORTED. False otherwise
#define status_unsupported( s )	( s.code == OSAPI_ERROR_SUPPORT )


// *****************************************************************************************
//
// Section: Macros/definitions for internal usage
//
// *****************************************************************************************

/// The enum that defines the library ID used by the t_status type
enum osapi_library_id
{
  /// OSAPI Library
  e_library_osapi 		= 0,//!< e_library_osapi

  // System Libraries get negative codes
  /// LibC Library
  e_library_c			= -1,    //!< e_library_c
  /// Loader library
  e_library_loader		= -2,//!< e_library_loader
};

/// @brief Short notation to set a status type with a default value of success
#define RETURN_STATUS_SUCCESS	{ t_status st; status_reset( &st ); return st; }

// Support macros for setting internal/external status errors

/// @brief Set status type with OSAPI library information
#define status_iset(m,f,e,r) 		status_set( m, e_library_osapi, f, e, r )

/// @brief Set status type with C library information
#define status_eset(m,f,e,r) 		status_set( m, e_library_c,     f, e, r )


#endif /* OSAPI_STATUS_DEFS_H_ */
