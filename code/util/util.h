// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Util(ities) module API
//
// *****************************************************************************************

#ifndef OSAPI_UTIL_H_
#define OSAPI_UTIL_H_

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
#include "util/util_types.h"
#include "util/util_platform.h"

// *****************************************************************************************
//
// Section: Util module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


// Functions bellow
t_status util_module_supported			( void					);


#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_UTIL_H_ */
