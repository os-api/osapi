/*
 * sec.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef SEC_SEC_H_
#define SEC_SEC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include "status/status.h"
#include "common/common_types.h"
#include "sec/sec_defs.h"
#include "sec/sec_platform.h"

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status sec_module_supported		( void						);

// User ID functions
t_status sec_user_getId			( t_uid	* p_uid					);
t_status sec_user_setId			( t_uid	  p_uid					);
t_status sec_user_getIdFromName		( char * username, t_uid * p_uid		);
t_status sec_user_getNameFromID		( t_uid uid, t_size size, char * username	);

// Group ID functions
t_status sec_group_getId		( t_gid	* p_gid					);
t_status sec_group_setId		( t_gid	  gid					);
t_status sec_group_getIdFromName	( char * groupname, t_gid * p_gid		);
t_status sec_group_getNameFromID	( t_gid gid, t_size size, char * groupname	);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* SEC_SEC_H_ */
