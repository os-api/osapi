// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for Group related functionality
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_GROUP_H_
#define OSAPI_COMMON_GROUP_H_

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
#include "common/common_types.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************


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



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_GROUP_H_ */
