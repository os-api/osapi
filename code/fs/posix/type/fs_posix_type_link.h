// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPE_LINK_H_
#define OSAPI_FS_POSIX_TYPE_LINK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI headers
#include "common/common_types.h"

// Import module types
#include "fs/type/fs_type_ostate.h"

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Structure containing the C/POSIX file pointer/handler information
struct osapi_fs_s_link_info
{
  t_fs_ostate		state;				///< Current state
  t_char		target	[ OSAPI_PATH_MAX ];	///< Full path name of element to which the link points to
};

typedef struct osapi_fs_s_link_info		t_fs_linkInfo;


#endif /* OSAPI_FS_POSIX_TYPE_LINK_H_ */
