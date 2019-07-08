// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_H_
#define OSAPI_COMMON_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Import own declarations
#include "common/common_types.h"
#include "common/common_group.h"
#include "common/common_user.h"
#include "common/common_memory.h"
#include "common/common_buffer.h"
#include "common/common_list.h"


// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of internal interface

// Utility functions
int		common_options_get		( const t_option * moduleOptions, char * providedOptions[]				);

/// @brief Is the string composed of only digits (0-9)?
/// @param [in] str - The string to verify
/// @return True or False
bool		common_string_isDigit		( const char * str									);

#pragma GCC visibility pop			// End of internal interface

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI__COMMON_H_ */
