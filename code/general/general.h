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
/// @brief The OSAPI library base module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: OSAPI bootstrap API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Get the release number of the Library
/// @return Release number
unsigned long osapi_get_release( void );

/// @brief Get the version number of the Library
/// @return Version number
unsigned long osapi_get_version( void );

/// @brief Get the library stability type: Stable vs Unstable
/// @return enum that describes the stability type
int osapi_get_version_stability( void );

/// @brief Get the release string of the Library
/// @return C String library release information
const char * osapi_get_release_string( void );

/// @brief Get the version string of the Library
/// @return C String library version
const char * osapi_get_version_string( void );

/// @brief Get the string describing the library stability type: Stable vs Unstable
/// @return C String library stability type
const char * osapi_get_version_stability_string( void );

/// @brief Get the OSAPI Protocol name
/// @param [in] id - The protocol ID
/// @return C String for the given Protocol ID
const char * osapi_get_protocol_string( t_protocol id );

/// @brief Compare library runtime baseline against requirements
/// @return True if baseline meets requirements or False otherwise
bool osapi_verify_baseline( void );

// Module related
/// @brief Get the module string
/// @param [in] module - The module ID
/// @return C String for the given module ID
const char * osapi_module_get( t_module module );

// Detect Endianess
/// @brief Check if current endianess is little
/// @return True if little endian, False otherwise
bool osapi_endian_isLittle( void );

/// @brief Check if current endianess is big
/// @return True if big endian, False otherwise
bool osapi_endian_isBig( void );

/// @brief Print a trace message to standard error
/// @param [in] func - Function name
/// @param [in] sep  - Separator string
/// @param [in] line - Code line number
/// @param [in] fmt  - Message format specifier
void osapi_trace( const char * func, const char * sep, uint64_t line, const char * fmt, ... );


#pragma GCC visibility pop			// End of public interface

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_GENERAL_H_ */
