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


// *****************************************************************************************
//
// Section: String module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// Module query function
t_status string_module_supported		( void					);

#pragma GCC visibility pop			// End of public interface

// Include remaining submodules
#include "string/string_basic.h"
//#include "string/string_wide.h"


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STRING_H_ */
