// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide trace API
//
// *****************************************************************************************

#ifndef OSAPI_TRACE_H_
#define OSAPI_TRACE_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
#include <stdint.h>

// Generic OSAPI includes

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


/// @brief OSAPI C Trace function
/// The functions sends the output to standard error
/// @param [in] func - Name of function
/// @param [in] sep  - Separator between function and line number
/// @param [in] line - Line number
/// @param [in] fmt  - printf format for the remaining arguments
void osapi_trace( const char * func, const char * sep, uint64_t line, const char * fmt, ... );


/// @brief OSAPI C Trace function
/// The functions sends the output to standard error
/// @param [in] func 	- Name of function
/// @param [in] line 	- Line number
/// @param [in] st  	- An operation status
void osapi_status_trace( const char * func, uint64_t line, t_status st );

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_TRACE_H_ */
