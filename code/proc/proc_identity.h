// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API
//
// *****************************************************************************************

#ifndef OSAPI_PROC_IDENTITY_H_
#define OSAPI_PROC_IDENTITY_H_

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
#include <common/common_types.h>

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

/// @brief Get the current process ID
/// @param [out] pid - The process ID
/// @return Operation status
t_status proc_id_get( t_pid * pid );

/// @brief Get the parent process ID
/// @param [in] pid - The process ID for which the parent ID process is required
/// @param [out] ppid - The parent process ID
/// @return Operation status
t_status proc_id_getParent( t_pid pid, t_pid * ppid );

/// @brief Get list of process IDs of children processes
/// @param [in] pid - The process ID for which children are obtained
/// @param [in] tsize - The size of the array
/// @param [out] csize - The number of found children processes
/// @param [out] array - List of process IDs of children
/// @return Operation status
t_status proc_id_getDescendents( t_pid pid, t_size tsize, t_size * csize, t_pid (* array)[] );

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

/// @brief Get the List of IDs of Process Group members.
/// @param [in] pgid - The target Process Group ID for which to retrieve the member IDs
/// @param [in] initialMembers - Number of found members of group / Size of the array
/// @param [out] currentMembers - Number of members discovered during the execution of the operations / Current array size
/// @param [out] idList - List with process IDs of group members
/// @return Operation status
t_status proc_id_getGroupMembers( t_pid pgid, t_size initialMembers, t_size * currentMembers, t_pid (* idList)[] );

/// @brief Get the List of IDs of Process Session members.
/// @param [in] sid - The target Process Session ID for which to retrieve the member IDs
/// @param [in] initialMembers - Number of found members of group / Size of the array
/// @param [out] currentMembers - Number of members discovered during the execution of the operations / Current array size
/// @param [out] idList - List with process IDs of session members
/// @return Operation status
t_status proc_id_getSessionMembers( t_pid sid, t_size initialMembers, t_size * currentMembers, t_pid (* idList)[] );

/// @brief Convert a process ID to a C-String format.
/// @param [in] pid - The process ID to convert to string
/// @param [in] size - Size of the output string
/// @param [out] string - Process ID in C-String format
/// @return Operation status
t_status proc_id_toString( t_pid pid, t_size size, t_char * string );

/// @brief Convert a C-String into a process ID.
/// @param [in] string - The C-String to be converted into a process ID
/// @param [out] pid - The process ID obtained from the C-String
/// @return Operation status
t_status proc_id_fromString( t_char * string, t_pid * pid );

/// @brief Copy a source process ID to a target variable.
/// @param [in] source - The process ID to copy
/// @param [out] target - The copied process ID
/// @return Operation status
t_status proc_id_copy( t_pid source, t_pid * target );

/// @brief Reset ID to a default (and possible non usable) value
/// @param [in,out] pid - The process ID variable to reset
/// @return Operation status
t_status proc_id_clear( t_pid * pid );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_IDENTITY_H_ */
