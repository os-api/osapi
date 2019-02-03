// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API to build a process plan
//
// *****************************************************************************************

#ifndef OSAPI_PROC_PLAN_H_
#define OSAPI_PROC_PLAN_H_

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
#include "common/types/common_types.h"

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
// Section: Public Function declarations
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// ++ Operations

// + Clear process data
/// @brief Reset process plan information to default system specific values
/// @param [in,out] proc - process type
/// @return Operation status
t_status proc_data_clear( t_proc * proc );


// + Building process data
/// @brief Change the current process User ID
/// @param [in] uid - New User ID
/// @param [out] proc - process type
/// @return Operation status
t_status proc_data_setUser( t_uid uid, t_proc * proc );

/// @brief Change the current process Group ID
/// @param [in] gid - New Group ID
/// @param [out] proc - process type
/// @return Operation status
t_status proc_data_setGroup( t_gid gid, t_proc * proc );

/// @brief Fills a process data structure with the execution command line
/// @param [in] size - Number of elements of the (C-String) array
/// @param [in] array - The command line array
/// @param [out] proc - The process type
/// @return Operation status
t_status proc_data_setCmdLine( t_size size, char * array[], t_proc * proc );

/// @brief Fills a process data structure with the new process environment
/// @param [in] size - Number of elements of the C-String array
/// @param [in] array - The environment array
/// @param [out] proc - The process type
/// @return Operation status
t_status proc_data_setEnvironment( t_size size, char * array[], t_proc * proc );

/// @brief Retrieve the process ID from the process type
/// @param [in] proc - Process type
/// @param [out] pid - process ID
/// @return Operation status
t_status proc_data_getPID( t_proc * proc, t_pid * pid );

/// @brief Retrieve the User ID from the process type
/// @param [in] proc - Process type
/// @param [out] uid - User ID
/// @return Operation status
t_status proc_data_getUID( t_proc * proc, t_uid * uid );

/// @brief Retrieve the User ID from the process type
/// @param [in] proc - Process type
/// @param [out] gid - User ID
/// @return Operation status
t_status proc_data_getGID( t_proc * proc, t_gid * gid );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_PLAN_H_ */
