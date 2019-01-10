// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide base module types and other declarations
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_H_
#define OSAPI_GENERAL_H_


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Own headers

#include "general/general_baseline.h"
#include "general/general_version.h"
#include "general/general_types.h"
#include "general/general_modules.h"
#include "general/general_defs.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup GENERAL
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: OSAPI bootstrap API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Get the version number of the Library
/// @return Version number
unsigned long	osapi_get_version			( void		);

/// @brief Get the library stability type: Stable vs Unstable
/// @return enum that describes the stability type
int		osapi_get_version_stability		( void		);

/// @brief Get the version string of the Library
/// @return C String library version
const char *	osapi_get_version_string		( void		);

/// @brief Get the string describing the library stability type: Stable vs Unstable
/// @return C String library stability type
const char *	osapi_get_version_stability_string	( void 		);

/// @brief Get the OSAPI Protocol name
/// @param in Protocol ID
/// @return C String for the given Protocol ID
const char * 	osapi_get_protocol_string		( t_protocol id );

// Module related
/// @brief Get the module string
/// @param in module ID
/// @return C String for the given module ID
const char *	osapi_getModule				( t_module	);

#pragma GCC visibility pop			// End of public interface

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_GENERAL_H_ */
