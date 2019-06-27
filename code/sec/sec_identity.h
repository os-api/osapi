// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Sec(urity) module API
//
// *****************************************************************************************

#ifndef OSAPI_SEC_IDENTITY_H_
#define OSAPI_SEC_IDENTITY_H_

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

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Common includes
#include <common/common_types.h>

// Own declarations
#include "sec/sec_types.h"
#include "sec/sec_platform.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup SEC
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Sec(urity) module API for identification
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// Group ID functions

/// @brief Checks if the group ID exists in the system
/// @param [out] gid - group ID
/// @return Operation status
t_status sec_group_exists( t_gid gid );

/// @brief Convert a string into a Group ID
/// @param [in] string - C string
/// @param [out] gid - group ID
/// @return Operation status
t_status sec_group_stringToId( char * string, t_gid * gid );

/// @brief Convert a Group Id to a C String
/// @param [in] gid - Group ID
/// @param [in] size - Size of the C string
/// @param [out] string - String with group ID
/// @return Operation status
t_status sec_group_idToString( t_gid gid, t_size size, char * string );

/// @brief Compare two group IDs
/// @param [in] gid1 - First group ID
/// @param [in] gid2 - Second group ID
/// @param [out] result - True if identical. False otherwise.
/// @return Operation status
t_status sec_group_compare( t_gid gid1, t_gid gid2, bool * result );

/// @brief Copy a group ID
/// @param [in] source - Group ID
/// @param [out] target - Group ID
/// @return Operation status
t_status sec_group_copy( t_gid source, t_gid * target );

/// @brief Get current group ID
/// @param [out] gid - Current group ID
/// @return Operation status
t_status sec_group_getId( t_gid	* gid );

/// @brief Set current group ID
/// @param [in] gid - New group ID
/// @return Operation status
t_status sec_group_setId( t_gid	gid );

/// @brief Obtain the group ID from the group Name
/// @param [in] groupname - The group name
/// @param [out] gid - The group ID
/// @return Operation status
t_status sec_group_getIdFromName( char * groupname, t_gid * gid	);

/// @brief Obtain the group Name from the group ID
/// @param [in] gid - The group ID
/// @param [in] size - Size of the groupname string
/// @param [out] groupname - The group name
/// @return Operation status
t_status sec_group_getNameFromID( t_gid gid, t_size size, char * groupname );

/// @brief Get the maximum size in bytes of a group name
/// @param [out] size - Maximum size of group name
/// @return Operation status
t_status sec_group_getMaxSize( t_size * size );

/// @brief Get the maximum number of groups that a user can have
/// @param [out] max - Maximum number of user groups
/// @return Operation status
t_status sec_group_getMaxNumber( t_size * max );

// User ID functions
/// @brief Checks if the user ID exists in the system
/// @param [out] uid - User ID
/// @return Operation status
t_status sec_user_exists( t_uid uid );

/// @brief Convert a string into a user ID
/// @param [in] string - C string
/// @param [out] uid - user ID
/// @return Operation status
t_status sec_user_stringToId( char * string, t_uid * uid );

/// @brief Convert a user Id to a C String
/// @param [in] uid - user ID
/// @param [in] size - Size of the C string
/// @param [out] string - String with user ID
/// @return Operation status
t_status sec_user_idToString( t_uid uid, t_size size, char * string );

/// @brief Compare two user IDs
/// @param [in] uid1 - First user ID
/// @param [in] uid2 - Second user ID
/// @param [out] result - True if identical. False otherwise.
/// @return Operation status
t_status sec_user_compare( t_uid uid1, t_uid uid2, bool * result );

/// @brief Copy a user ID
/// @param [in] source - User ID
/// @param [out] target - User ID
/// @return Operation status
t_status sec_user_copy( t_uid source, t_uid * target );

/// @brief Get current user ID
/// @param [out] uid - Current user ID
/// @return Operation status
t_status sec_user_getId( t_uid	* uid );

/// @brief Set current user ID
/// @param [in] uid - New user ID
/// @return Operation status
t_status sec_user_setId( t_uid uid );

/// @brief Obtain the user ID from the user Name
/// @param [in] username - The user name
/// @param [out] uid - The user ID
/// @return Operation status
t_status sec_user_getIdFromName( char * username, t_uid * uid );

/// @brief Obtain the user Name from the user ID
/// @param [in] uid - The user ID
/// @param [in] size - Size of the username string
/// @param [out] username - The group name
/// @return Operation status
t_status sec_user_getNameFromID( t_uid uid, t_size size, char * username );

/// @brief Get the maximum size in bytes of a user name
/// @param [out] size - Maximum size of user name
/// @return Operation status
t_status sec_user_getMaxSize( t_size * size );

/// @brief Get the user groups
/// @param [in] uid - The target user ID
/// @param [in] groupListMaxSize - The maximum number of user groups
/// @param [out] groupListCurSize - Number of current user groups
/// @param [out] groupList - List of user groups (IDs)
/// @return Operation status
t_status sec_user_getGroups( t_uid uid, size_t groupListMaxSize, size_t * groupListCurSize, t_gid *  groupList );

#pragma GCC visibility pop			// End of public interface


///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_SEC_IDENTITY_H_ */
