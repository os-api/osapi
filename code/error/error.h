// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_H_
#define OSAPI_ERROR_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard types
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_types.h"

// Own declarations
#include "error/error_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup ERROR
/// @brief The error management module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Error module OSAPI internal API
//
// *****************************************************************************************

/// @brief Get the error string for an OSAPI module and error number
/// @param [in] module - The module number
/// @param [in] code - The error code
/// @return Formated error string
const char * error_string_get( t_module module, t_error code );

/// @brief Verify if a given error number is valid for the provided OSAPI module
/// @param [in] module - The module number
/// @param [in] code - The error code
/// @return True or False
bool error_code_isValid( t_module module, t_error code );

// *****************************************************************************************
//
// Section: Help macros
//
// *****************************************************************************************


///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_ERROR_H_ */
