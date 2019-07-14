// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Element info type declarations
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
#include "common/common_types.h"

// Import own headers
#include "fs/fs_platform.h"
#include "fs/type/fs_type_element_type.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Structure containing the file system element generic information
struct osapi_fs_element_info
{
  t_fs_ostate		state;				///< Element state (closed/open)
  t_fs_eType		type;				///< Element type: File, directory, etc.
  t_uid			uid;				///< User ID
  t_gid			gid;				///< Group ID
  t_size		size;				///< Element size
  t_time		ctime;				///< Creation time
  t_time		atime;				///< Access time
  t_time		mtime;				///< Modification time
  t_fs_perm		perm;				///< Permission set
  t_char		fullpath [ OSAPI_PATH_MAX ];	///< The full and real path name to the element
};


typedef struct osapi_fs_element_info 	t_fs_elementInfo;

#endif /* OSAPI_FS_TYPE_ELEMENTINFO_H_ */
