// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	TCP type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_ELEMENTINFO_H_
#define OSAPI_FS_TYPE_ELEMENTINFO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers


// General OSAPI headers
#include <common/common_types.h>
#include "fs/fs_platform.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Structure containing the file system element generic information
struct osapi_s_fs_elementInfo
{
  t_char	*	name;		///< The path name
  t_fs_eType		type;		///< Element type: File, directory, etc.
  t_uid			uid;		///< User ID
  t_gid			gid;		///< Group ID
  t_size		size;		///< Element size
  t_time		ctime;		///< Creation time
  t_time		atime;		///< Access time
  t_time		mtime;		///< Modification time
  // t_fs_ePerm	perm;
};


typedef struct osapi_s_fs_elementInfo t_fs_elementInfo;

#endif /* OSAPI_FS_TYPE_ELEMENTINFO_H_ */
