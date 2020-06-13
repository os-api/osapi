// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module API
//
// *****************************************************************************************

#ifndef OSAPI_OS_H_
#define OSAPI_OS_H_

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
#include "common/types/common_type_time.h"

// Own declarations
#include "os/os_types.h"
#include "os/os_platform.h"
#include "os/os_info.h"
#include "os/os_cpu.h"
#include "os/os_memory.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup OS
/// @brief The Operating System interface module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status os_module_supported( void );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_OS_H_ */
