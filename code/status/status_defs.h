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

// Include own module pubic definitions
#include "status/status_macros.h"


// *****************************************************************************************
//
// Section: Macros/definitions for internal usage
//
// *****************************************************************************************

/// @brief Maximum size of the error string
/// The t_status type supports either error code or an error string. This last type, the error string,
/// is limited in size to the this value
#define	OSAPI_STATUS_STRING_SIZE	101


/// The enum that defines the library ID used by the t_status type
enum osapi_status_e_library_id
{
  osapi_status_library_osapi 		= 0,	//!< Internal OSAPI library

  // System Libraries get negative codes
  osapi_status_library_c			= -1,   //!< LibC Library
  osapi_status_library_loader		= -2,	//!< Loader library
};

/// @brief Short notation to set a status type with a default value of success
#define RETURN_STATUS_SUCCESS	{ t_status st; st.code = 0; return st; }


// Support macros for setting internal/external status errors

/// @brief Set status type with OSAPI library information
#define status_iset(m,f,e,r) 		status_set( m, osapi_status_library_osapi, f, e, r )

/// @brief Set status type with C library information
#define status_eset(m,f,e,r) 		status_set( m, osapi_status_library_c,     f, e, r )


#endif /* OSAPI_STATUS_DEFS_H_ */
