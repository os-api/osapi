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

/// Enumeration of time information types (of a file system element)
enum osapi_fs_e_time_element
{
  osapi_fs_time_unknown	= 0,	///< Undefined time type
  osapi_fs_time_create	= 1,	///< Creation time type
  osapi_fs_time_change	= 2,	///< Creation time type
  osapi_fs_time_modify	= 3,	///< Modification time type
  osapi_fs_time_access	= 4	///< Access time type
};

/// Structure that defines a file system permissions
struct osapi_fs_s_element_permissions
{
  mode_t		mode;			///< POSIX encoding of an element permissions/type
  // ACL also required
};

typedef struct osapi_fs_s_element_permissions	t_fs_perm;



#endif /* OSAPI_FS_POSIX_TYPE_ELEMENT_H_ */
