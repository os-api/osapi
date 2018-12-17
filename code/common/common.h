// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API
//
// *****************************************************************************************

#ifndef CODE_COMMON_H_
#define CODE_COMMON_H_

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

// Own declarations
#include <common/types/common_types.h>


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of internal interface

// Functions for Groups
t_status	get_groupID			( t_gid * p_gid		  								);
t_status	set_groupID			( t_gid	gid										);
t_status	get_groupname_from_id		( t_gid gid, size_t max_name, char * p_groupname					);
t_status	get_groupID_from_name		( char * groupname, t_gid * p_gid							);
t_status	get_max_length_groupname	( t_size * p_size 									);
t_status	get_max_number_groups		( t_size * p_size 									);
t_status	stringTo_gid			( const char * p_string, t_gid * p_gid							);
t_status	gidTo_string			( t_gid gid, t_size strSize, char * p_string						);
t_status	gid_compare			( t_gid gid1, t_gid gid2, bool * p_result						);
t_status	gid_copy			( t_gid source, t_gid * p_target							);

// Functions for Users
t_status	get_userID			( t_uid * p_id		  								);
t_status	set_userID			( t_uid	uid										);
t_status	get_primaryGroupID		( t_uid	uid, t_gid * primaryGroupID							);
t_status	get_username_from_id		( t_uid uid, size_t max_name, char * p_name						);
t_status	get_userID_from_name		( char * p_name, t_uid * p_id								);
t_status	get_max_length_username		( t_size * p_size 									);
t_status	get_user_group_list		( t_uid uid, size_t groupListMaxSize, size_t * p_groupListCurSize, t_gid *  p_groupList	);
t_status	stringTo_uid			( const char * p_string, t_gid * p_uid							);
t_status	uidTo_string			( t_uid uid, t_size strSize, char * p_string						);
t_status	uid_compare			( t_uid uid1, t_uid uid2, bool * p_result						);
t_status	uid_copy			( t_uid source, t_uid * p_target							);


// Utility functions
int		common_options_get		( const t_option * moduleOptions, char * providedOptions[]				);

#pragma GCC visibility pop			// End of internal interface

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* CODE_COMMON_H_ */
