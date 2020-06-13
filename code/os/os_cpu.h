// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module API for CPU information
//
// *****************************************************************************************

#ifndef OSAPI_OS_CPU_H_
#define OSAPI_OS_CPU_H_

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
#include "common/types/common_type_cpu.h"

// Own declarations


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

/// @brief Get the number of online Logical CPUs
/// @param [out] ncpus - Number of Logical CPUs available
/// @return Operation status
t_status os_cpu_getAvailable( t_cpu_nlogical * ncpus	);

/// @brief Get the number of present/configured Logical CPUs
/// @param [out] ncpus - Number of Logical CPUs visible by the OS
/// @return Operation status
t_status os_cpu_getPresent( t_cpu_nlogical * ncpus	);

/// @brief Get the maximum number of Logical CPUs that the OS can address
/// @param [out] ncpus - Number of logical CPUs that can be managed by the OS
/// @return Operation status
t_status os_cpu_getMax( t_cpu_nlogical * ncpus	);

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_OS_CPU_H_ */
