/*
 * common.h
 *
 *  Created on: 10/06/2018
 *      Author: joao
 */

#ifndef CODE_COMMON_H_
#define CODE_COMMON_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

#include "status/status.h"
#include "common/common_types_posix.h"

// Functions section

// Functions for Users
t_status	get_userID			( t_uid * p_id		  				);
t_status	set_userID			( t_uid	uid						);
t_status	get_username_from_id		( t_uid uid, size_t max_name, char * p_name		);
t_status	get_userID_from_name		( char * p_name, t_uid * p_id				);

// Functions for Groups
t_status	get_groupID			( t_gid * p_gid		  				);
t_status	set_groupID			( t_gid	gid						);
t_status	get_groupname_from_id		( t_gid gid, size_t max_name, char * p_groupname	);
t_status	get_groupID_from_name		( char * groupname, t_gid * p_gid			);

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* CODE_COMMON_H_ */
