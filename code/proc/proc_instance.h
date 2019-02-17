// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API for process management, i.e. creation, destruction, etc.
//
// *****************************************************************************************

#ifndef OSAPI_PROC_INSTANCE_H_
#define OSAPI_PROC_INSTANCE_H_

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

// ++ Life cycle
/// @brief Create a new process instance
/// @param [in,out] proc - process type
/// @return Operation status
t_status proc_instance_create( t_proc * proc );

/// @brief Terminate a running process
/// @param [in] pid - The process to terminate
/// @param [in] forced - Normal or forced termination
/// @return Operation status
t_status proc_instance_destroy( t_pid pid, int forced );

/// @brief Clone the current process
/// @param [out] isChild - Child or father
/// @return Operation status
t_status proc_instance_clone( int * isChild );

/// @brief Is a process instance running
/// @param [in] pid - Process ID to check
/// @return SUCCESS (Running) / FAILURE
t_status proc_instance_isRunning( t_pid pid );

/// @brief Obtain the state of a given process
/// @param [in] pid - Process ID to check
/// @param [out] state - The corresponding process state
/// @return Operation status
t_status proc_instance_getState( t_pid pid, int * state );

/// @brief Obtain status of a child process
/// @param [in] pid - Process ID
/// @param [out] status - Status of child process
/// @return Operation status
t_status proc_instance_getChildStatus( t_pid * pid, t_proc_status * status );

/// @brief Obtain a status of a process
/// @param [in] pid - Process ID
/// @param [out] status - Status of child process
/// @return Operation status
t_status proc_instance_getStatus( t_pid pid, t_proc_status * status );

/// @brief Obtain the number of children processes
/// @param [in] pid - Get descendants of this process
/// @param [out] number - Number of children processes
/// @return Operation status
t_status proc_instance_getNumberOfDescendents( t_pid pid, t_size * number );

/// @brief Obtain the number of process group members
/// @param [in] pgid - The process group id
/// @param [out] number - Number of process group members
/// @return Operation status
t_status proc_instance_getNumberOfGroupMembers( t_pid pgid, t_size * number );

/// @brief Obtain the number of process session members
/// @param [in] sid - The session id
/// @param [out] number - Number of process group members
/// @return Operation status
t_status proc_instance_getNumberOfSessionMembers( t_pid sid, t_size * number );

/// @brief Terminate the current process. It always succeeds.
/// @param [in] code - Exit status code
OSAPI_NORETURN
void proc_instance_terminate( int code );

// ++ State management
/// @brief Suspend the execution of the current thread until an event occurs such as a signal in UNIX
/// @return Operation status
t_status proc_instance_suspendExecution		( void				);

//t_status	proc_instance_resumeExecution	( void				);


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_INSTANCE_H_ */
