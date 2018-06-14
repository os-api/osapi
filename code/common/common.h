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

#include "status/status_types.h"
#include "common/common_types.h"

// Functions section

// Functions for Groups
t_status	get_groupID			( t_gid * p_gid		  				);
t_status	set_groupID			( t_gid	gid						);
t_status	get_groupname_from_id		( t_gid gid, size_t max_name, char * p_groupname	);
t_status	get_groupID_from_name		( char * groupname, t_gid * p_gid			);
t_status	get_max_length_groupname	( t_size * p_size 					);
t_status	get_max_number_groups		( t_size * p_size 					);

// Functions for Users
t_status	get_userID			( t_uid * p_id		  				);
t_status	set_userID			( t_uid	uid						);
t_status	get_username_from_id		( t_uid uid, size_t max_name, char * p_name		);
t_status	get_userID_from_name		( char * p_name, t_uid * p_id				);
t_status	get_max_length_username		( t_size * p_size 					);
t_status	get_user_group_list		( t_uid uid, t_gid * p_groupList			);


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* CODE_COMMON_H_ */
