// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPE_DIR_H_
#define OSAPI_FS_POSIX_TYPE_DIR_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import POSIX type headers
#include <sys/types.h>
#include <dirent.h>

// Import module types
#include "fs/type/fs_type_ostate.h"

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Structure describing a directory descriptor type
struct osapi_fs_s_directory_info
{
  t_fs_ostate		state;			///< Current state
  DIR		*	handle;			///< POSIX directory descriptor
};

typedef struct osapi_fs_s_directory_info	t_fs_directoryInfo;

typedef struct dirent				t_dir_entry;



#endif /* OSAPI_FS_POSIX_TYPE_DIR_H_ */
