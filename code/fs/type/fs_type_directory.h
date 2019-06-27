// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declaration for a directory element
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_DIRECTORY_H_
#define OSAPI_FS_TYPE_DIRECTORY_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers


// General OSAPI headers
#include <common/common_types.h>
#include "fs/fs_platform.h"
#include "fs/type/fs_type_elementInfo.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Structure containing directory information
struct osapi_s_dir
{
  t_fs_elementInfo			info;	///< Generic element file system information
  t_fs_directoryInfo			data;	///< Specific directory element information
};

typedef struct osapi_s_fs_dir		t_dir;



#endif /* OSAPI_FS_TYPE_DIRECTORY_H_ */
