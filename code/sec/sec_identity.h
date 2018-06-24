// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Sec(urity) module API
//
// *****************************************************************************************

#ifndef SEC_SEC_IDENTITY_H_
#define SEC_SEC_IDENTITY_H_

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
#include "common/common_types.h"

// Own declarations
#include "sec/sec_types.h"
#include "sec/sec_platform.h"


// *****************************************************************************************
//
// Section: Sec(urity) module API for identification
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// Group ID functions
t_status sec_group_getId		( t_gid	* p_gid										);
t_status sec_group_setId		( t_gid	  gid										);
t_status sec_group_getIdFromName	( char * groupname, t_gid * p_gid							);
t_status sec_group_getNameFromID	( t_gid gid, t_size size, char * groupname						);
t_status sec_group_getMaxSize		( t_size * p_size									);
t_status sec_group_getMaxNumber		( t_size * p_size									);

// User ID functions
t_status sec_user_getId			( t_uid	* p_uid										);
t_status sec_user_setId			( t_uid	  p_uid										);
t_status sec_user_getIdFromName		( char * username, t_uid * p_uid							);
t_status sec_user_getNameFromID		( t_uid uid, t_size size, char * username						);
t_status sec_user_getMaxSize		( t_size * p_size									);
t_status sec_user_getGroups		( t_uid uid, size_t groupListMaxSize, size_t * p_groupListCurSize, t_gid *  p_groupList	);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* SEC_SEC_IDENTITY_H_ */
