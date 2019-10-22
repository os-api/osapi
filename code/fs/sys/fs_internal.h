// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module header for interface to the system.
//		Internal cross platform calls. May support multiple OSs.
//
// *****************************************************************************************

#ifndef OSAPI_FS_INTERNAL_H_
#define OSAPI_FS_INTERNAL_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// First include baseline
#include "general/general_baseline.h"

// Standard C headers

// General OSAPI headers
#include "general/general.h"
#include "status/status_types.h"

// Include own headers
#include "fs/fs_element.h"

// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

// Current platforms supporting this call
#if defined(OS_LINUX) || defined(OSAPI_LINUX) || defined(OSAPI_POSIX)


/// @brief Get element information from OS
/// @param [in] path   - Path to element
/// @param [in] option - Which option to retrieve
/// @param [out] elem  - Information about the element
/// @return Operation status
t_status	internal_fs_element_getInfo	( const t_char * path, int option, t_element * elem 	);

/// @brief Reset an element to the default values
/// @param [in,out] elem  - Element to be reseted
void 		internal_fs_element_reset	( t_element * elem 					);

/// @brief Get element tme information
/// @param [in] path   - Path to element
/// @param [in] option - Which time option to retrieve
/// @param [out] time  - Information about the time for element
/// @return Operation status
t_status	internal_fs_element_getTime	( const t_char * path, int option, t_time * time	);

#endif	// End of internal API

#endif // OSAPI_FS_INTERNAL_H_
