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
#include "fs/type/fs_type_element_attributes.h"
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
  t_fs_eid		id;				///< Element identifier
  t_uid			uid;				///< User ID
  t_gid			gid;				///< Group ID
  uint64_t		size;				///< Element size
  uint32_t		block_size;			///< IO preferred block size
   // Next field requires a Linux implementation using statx and not stat structure
  t_time		btime;				///< Creation (birth) time
  t_time		ctime;				///< Change time
  t_time		atime;				///< Access time
  t_time		mtime;				///< Modification time
  uint64_t		nlink;				///< Number of hard links to element
  t_fs_perm		perm;				///< Permission set
  bool			compressed;			///< Element compressed ?
  bool			encrypted;			///< Element encrypted ?
  t_char		fullpath [ OSAPI_PATH_MAX ];	///< The full and real path name to the element
};


typedef struct osapi_fs_element_info 	t_fs_elementInfo;

#endif /* OSAPI_FS_TYPE_ELEMENTINFO_H_ */
