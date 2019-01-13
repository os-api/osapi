// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide String module API
//
// *****************************************************************************************

#ifndef OSAPI_STRING_BASIC_H_
#define OSAPI_STRING_BASIC_H_

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

// Standard types
#include <stdbool.h>

// Own declarations
#include "string/string_types_basic.h"
#include "string/string_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STRING
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: String module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// + Basic String management (single byte)
// ++ Life cycle

/// @brief Create a new OSAPI string
/// @param [in] size - The memory allocate to the new string
/// @param [out] string - Address of the new string
/// @return Operation status
t_status string_basic_new( t_size size, t_string * string );

/// @brief Create a new OSAPI string based on a C string
/// @param [in] cstring - The C string
/// @param [out] string - The resulting OSAPI string
/// @return Operation status
t_status string_basic_create( const char * cstring, t_string * string );

/// @brief Delete an OSAPI string
/// @param [in] string - The string to delete
/// @return Operation status
t_status string_basic_delete( t_string * string	);

// ++ Operations

/// @brief Set the OSAPI string with the contents of C string
/// @param [in] cstring - The source C string
/// @param [out] string - The resulting OSAPI string
/// @return Operation status
t_status string_basic_put( const char * cstring, t_string * string );

/// @brief Copy from a C string into an OSAPI string
/// @param [in] cstring - The source C string
/// @param [out] string - The resulting OSAPI string
/// @return Operation status
t_status string_basic_copy( const char * cstring, t_string * string );

/// @brief Get the size of the OSAPI string
/// @param [in] string - The OSAPI string
/// @param [out] size - The size of the OSAPI string
/// @return Operation status
t_status string_basic_size( t_string * string, t_size *	size );

/// @brief Clone an OSAPI string
/// @param [in] string1 - Source string
/// @param [out] string2 - Resulting string
/// @return Operation status
t_status string_basic_clone( t_string * string1, t_string * string2 );

// + Content management

/// @brief Print to standard output the contents of the OSAPI string
/// @param [in] string - OSAPI string
/// @return Operation status
t_status string_basic_print( t_string *	string );

/// @brief Get a C string from an OSAPI string
/// @param [in] string - OSAPI string
/// @param [in] size - Size of the C string
/// @param [out] cstring - Resulting C string
/// @return Operation status
t_status string_basic_get( t_string * string, t_size size, char * cstring );

// + Instances management

/// @brief Check if two OSAPI strings are the same
/// @param [in] string1 - First string
/// @param [in] string2 - Second string
/// @param [out] result - True if the strings are equal. False otherwise.
/// @return Operation status
t_status string_basic_equal( t_string * string1, t_string * string2, bool * result );

/// @brief Case compare two OSAPI strings
/// @param [in] string1 - First string
/// @param [in] string2 - Second string
/// @param [out] result - True if the strings are identical. False otherwise.
/// @return Operation status
t_status string_basic_compare( t_string * string1, t_string * string2, Byte * result );

/// @brief Case insensitive comparison of two OSAPI strings
/// @param [in] string1 - First string
/// @param [in] string2 - Second string
/// @param [out] result - True if the strings are identical. False otherwise.
/// @return Operation status
t_status string_basic_compareIcase( t_string * string1, t_string * string2, Byte * result );

/// @brief Concatenation of two OSAPI strings
/// @param [in] string1 - First string
/// @param [in] string2 - Second string
/// @param [out] string3 - Concatenated string
/// @return Operation status
t_status string_basic_concat( t_string * string1, t_string * string2, t_string * string3 );

#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STRING_BASIC_H_ */
