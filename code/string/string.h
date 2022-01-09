// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide String module API
//
// *****************************************************************************************

#ifndef OSAPI_STRING_H_
#define OSAPI_STRING_H_

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
#include "string/string_types.h"
#include "string/string_platform.h"
#include "string/string_basic.h"
//#include "string/string_wide.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STRING
/// @brief The String module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: String module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Is the string module supported in the platform
/// @return Operation status
t_status string_module_supported( void );

#pragma GCC visibility pop			// End of public interface

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STRING_H_ */
