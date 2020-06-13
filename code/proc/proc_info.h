// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API for all information related to a process
//		These interfaces allow to retrieve Process Information on a single shot
//		and work on that information afterwards
//
// *****************************************************************************************

#ifndef OSAPI_PROC_INFO_H_
#define OSAPI_PROC_INFO_H_

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

// Common includes
#include "common/common_types.h"

// Own declarations
#include "proc/proc_types.h"
#include "proc/proc_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
/// @brief The process management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


// + Process general information
/// @brief Obtain raw process information
/// This is the function call that allows clients to make a single call and obtain all raw process data
/// @param [in]  pid  - Process ID
/// @param [out] info - Process information
/// @return Operation status
t_status proc_info_get			( t_pid pid, t_proc_info * info );

// + Consumption monitoring
/// @brief Extract the size of the process virtual memory from the process information
/// @param [in]  info - Process information
/// @param [out] size - Virtual memory size in bytes
/// @return Operation status
t_status proc_info_getVirtualMemory	( t_proc_info * info, t_size * size );

/// @brief Extract the size of the process real memory, i.e. ram usage, from the process information
/// @param [in]  info - Process information
/// @param [out] size - Real memory size in bytes
/// @return Operation status
t_status proc_info_getRealMemory	( t_proc_info * info, t_size * size );

/// @brief Extract the process CPU consumption (summary of user and system) from the process information
/// @param [in]  info - Process information
/// @param [out] size - Percentage of consumed process CPU
/// @return Operation status
t_status proc_info_getCPUConsumption	( t_proc_info * info, t_size * size );

/// @brief Extract the number of process kernel threads / LWPs from the process information
/// @param [in]  info   - Process information
/// @param [out] number - Number of process threads
/// @return Operation status
t_status proc_info_getThreads		( t_proc_info * info, t_size * number );

/*
t_status	proc_usage_getIO
t_status	proc_usage_getNetwork
 */

// + Process Time
/// @brief Extract the process start time from the process information
/// @param [in]  info  - Process information
/// @param [out] start - Process start time
/// @return Operation status
t_status proc_info_getStartTime		( t_proc_info * info, t_time * start );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_INFO_H_ */
