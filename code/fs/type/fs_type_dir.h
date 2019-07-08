// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for a directory Element
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_DIR_H_
#define OSAPI_FS_TYPE_DIR_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
#include <stdio.h>

// General OSAPI headers
#include "common/common_types.h"

// Import own headers
#include "fs/fs_platform.h"
#include "fs/type/fs_type_ostate.h"
#include "fs/type/fs_type_elementInfo.h"


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


/// Structure that holds all file system element information
struct osapi_fs_s_dir
{
  t_fs_ostate				state;	///< Current directory state
  t_fs_elementInfo				info;	///< General element information
  t_fs_directoryInfo				data;	///< Directory element specific information
};

typedef struct osapi_fs_s_dir			t_dir;




#endif /* OSAPI_FS_TYPE_DIR_H_ */
