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
#include <stdint.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Import own module declarations
#include "common/common_types.h"
#include "common/common_number.h"
#include "common/common_time.h"
#include "common/common_group.h"
#include "common/common_user.h"
#include "common/common_memory.h"
#include "common/common_buffer.h"
#include "common/common_list.h"
#include "common/common_machine.h"


// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************


// Utility functions
int64_t		common_options_get		( const t_option * moduleOptions, char * providedOptions[]				);

/// @brief Does the search string exists in the array of C-Strings ?
/// @param [in] arrayString  - The array to check
/// @param [in] searchString - The string to search
/// @return True or False
bool		common_arrayString_find		( const char ** arrayString, const char * searchString					);

/// @brief Is the string composed of only digits (0-9)?
/// @param [in] str - The string to verify
/// @return True or False
bool		common_string_isDigit		( const char * str									);


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI__COMMON_H_ */
