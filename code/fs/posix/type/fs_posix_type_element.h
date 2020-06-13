// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	POSIX FS type declarations for a file system element
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPE_ELEMENT_H_
#define OSAPI_FS_POSIX_TYPE_ELEMENT_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import POSIX type headers
#include <sys/types.h>

// Import module types
#include "fs/type/fs_type_ostate.h"

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Structure that defines a file system permissions
struct osapi_fs_element_permissions_S
{
  mode_t		mode;			///< POSIX encoding of an element permissions/type
  // ACL also required
};

typedef struct osapi_fs_element_permissions_S	t_fs_perm;


// *****************************************************************************************
//
// Section: Define constants for POSIX systems
//
// *****************************************************************************************

#define OSAPI_FS_PATH_SEPARATOR			'/'
#define OSAPI_FS_PATH_SEPARATOR_STRING		"/"


#endif /* OSAPI_FS_POSIX_TYPE_ELEMENT_H_ */
