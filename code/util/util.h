// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Util(ities) module API
//
// *****************************************************************************************

#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include "status/status_types.h"
#include <util/util_types.h>
#include "util/util_platform.h"

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status util_module_supported			( void					);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* UTIL_UTIL_H_ */
