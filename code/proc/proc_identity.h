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

/// @brief Get the current process ID
/// @param [out] pid - The process ID
/// @return Operation status
t_status proc_id_get( t_pid * pid );

/// @brief Get the parent process ID
/// @param [out] ppid - The parent process ID
/// @return Operation status
t_status proc_id_getParent( t_pid * ppid );

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
/// @param [in] tgid - The target Process Group ID for which to retrieve the member IDs
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

#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_IDENTITY_H_ */
