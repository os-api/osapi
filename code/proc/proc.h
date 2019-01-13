// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API
//
// *****************************************************************************************

#ifndef OSAPI_PROC_H_
#define OSAPI_PROC_H_

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
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Is PROC module supported in the platform
/// @return True if supported. False, otherwise (using status macros)
t_status	proc_module_supported		( void 				);

// + Instance management

// ++ Life cycle
/// @brief Create a new process instance
/// @param [in] proc - process type
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
/// @param [out] number - Number of children processes
/// @return Operation status
t_status proc_instance_getNumberOfDescendents( t_size * number );

/// @brief Terminate the current process. It always succeeds.
/// @param [in] code - Exit status code
OSAPI_NORETURN
void proc_instance_terminate( int code );

// ++ State management
/// @brief Suspend the execution of the current thread until an event occurs such as a signal in UNIX
/// @return Operation status
t_status proc_instance_suspendExecution		( void				);

//t_status	proc_instance_resumeExecution	( void				);


// ++ Operations
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
/// @param [in] size - Number of elements of the C-String array
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

// + Identity management
/// @brief Get the current process ID
/// @param [out] pid - The process ID
/// @return Operation status
t_status proc_id_get( t_pid * pid );

/// @brief Get the parent process ID
/// @param [out] ppid - The parent process ID
/// @return Operation status
t_status proc_id_getParent( t_pid * ppid );

/// @brief Get list of process IDs of children processes
/// @param [in] tsize - The size of the array
/// @param [out] csize - The number of found children processes
/// @param [out] array - List of process IDs of children
/// @return Operation status
t_status proc_id_getDescendents( t_size tsize, t_size * csize, t_pid (* array)[] );

/// @brief Get the User ID of the given process
/// @param [in] pid  - Target Process ID
/// @param [out] uid - User ID
/// @return Operation status
t_status proc_id_getUser( t_pid pid, t_uid * uid );

/// @brief Get the Group ID of the current process
/// @param [in] pid - Target Process ID
/// @param [out] gid - User ID
/// @return Operation status
t_status proc_id_getGroup( t_pid pid, t_gid * gid );

/// @brief Get Session Identifier
/// @param [in] pid - Target Process ID
/// @param [out] sid - Session ID
/// @return Operation status
t_status proc_id_getSession( t_pid pid, t_pid * sid );

/// @brief Create a new Session.
/// A new session is created with the current PID as being the Session ID
/// @return Operation status
t_status proc_id_setSession( void );

// + Signal handling
/// @brief Are signals supported by the OSAPI library?
/// @param [out] supportLevel - The level of support may vary, for instance, standard POSIX signals may be supported but not real time signals.
/// @return Operation status
t_status proc_signal_supported( int * supportLevel );

/// @brief Unblock of all signals.
/// If there are any blocked signal, these will be unblocked
/// @return Operation status
t_status proc_signal_clearAll( void );

/// @brief Send a signal to a process
/// The signal identifier will be the standard POSIX constant SIG_xxx
/// @param [in] pid - Target Process ID
/// @param [out] sigNumber - Signal identifier
/// @return Operation status
t_status proc_signal_send( t_pid pid, t_signal sigNumber );

/// @brief Send a signal to a process
/// The signal identifier will be the standard POSIX name "SIG_xxx"
/// @param [in] pid - Target Process ID
/// @param [out] sigName - Signal name
/// @return Operation status
t_status proc_signal_sendByName( t_pid pid, t_char * sigName );

/// @brief Set a signal handler function for a given signal number
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @param [out] sigFunc - The function name/address
/// @return Operation status
t_status proc_signal_setHandler( t_signal sigNumber, t_sig_func sigFunc );

/// @brief Set a signal handler function for a given signal name
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @param [out] sigFunc - The function name/address
/// @return Operation status
t_status proc_signal_setHandlerByName( t_char * sigName, t_sig_func sigFunc );

/// @brief Reset a signal to the default behavior
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @return Operation status
t_status proc_signal_resetHandler( t_signal sigNumber );

/// @brief Reset a signal to the default behavior
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @return Operation status
t_status proc_signal_resetHandlerByName( t_char * sigName );

/// @brief Get the name of a signal
/// The function maps a signal number to a signal name
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @param [out] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @return Operation status
t_status proc_signal_getName( t_signal sigNumber, t_char ** sigName );

/// @brief Get the name of a signal
/// The function maps a signal number to a signal name
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @param [out] sigNumber - The signal number
/// @return Operation status
t_status proc_signal_getNumber( t_char * sigName, t_signal * sigNumber );

// Add a cut through function to allow setting specific settings
//t_status	proc_signal_setAction		( t_signal, t_sig_func, t_sig_action * );

// Resource management
// + Memory management

/// @brief Allocate memory in the process heap
/// @param [in] size - Required memory size
/// @param [out] location - Address of the new memory block
/// @return Operation status
t_status proc_memory_allocate( t_size size, void ** location );

/// @brief Deallocate a previously allocated heap memory block
/// @param [in] location - Address of the new memory block
/// @return Operation status
t_status proc_memory_deallocate( void * location );

/// @brief Clear contents of memory block
/// @param [in] size - How many bytes have to be cleared
/// @param [out] location - Starting address of memory to clear
/// @return Operation status
t_status proc_memory_clear( t_size size, void * location );

// + Process general information
/// @brief Obtain raw process information
/// This is the function call that allows clients to make a single call and obtain all raw process data
/// @param [in] pid - Process ID
/// @param [out] procInfo - Process information
/// @return Operation status
t_status proc_info_get( t_pid pid, t_proc_info * procInfo );

// + Consumption monitoring
/// @brief Get the size of the process virtual memory
/// @param [in] pid - Process ID
/// @param [out] size - Virtual memory size in bytes
/// @return Operation status
t_status proc_usage_getVirtualMemory( t_pid pid, t_size * size );

/// @brief Get the size of the process real memory, i.e. ram usage
/// @param [in] pid - Process ID
/// @param [out] size - Real memory size in bytes
/// @return Operation status
t_status proc_usage_getRealMemory( t_pid pid, t_size * size );

/// @brief Get the process CPU consumption (summary of user and system)
/// @param [in] pid - Process ID
/// @param [out] size - Percentage of consumed process CPU
/// @return Operation status
t_status proc_usage_getCPU( t_pid pid, t_size * size );

/// @brief Get the number of process kernel threads / LWPs
/// @param [in] pid - Process ID
/// @param [out] number - Number of process threads
/// @return Operation status
t_status proc_usage_getThreads( t_pid pid, t_size * number );

/*
t_status	proc_usage_getIO
t_status	proc_usage_getNetwork
 */

/// @brief Is the load/unload of libraries supported in the platform?
/// @return SUCCESS / FAILURE
t_status proc_library_supported( void );

/// @brief Load a library into the current process
/// @param [in] path - Path to the library
/// @param [in] options - C-String array with list of system specific options
/// @param [out] lib - library type
/// @return Operation status
t_status proc_library_load( char * path, char * options[], t_library * lib );

/// @brief Unload a library from the current process
/// @param [in] lib - library type
/// @return Operation status
t_status proc_library_unload( t_library lib );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_H_ */
