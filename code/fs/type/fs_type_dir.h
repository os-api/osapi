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

// Import own headers
#include "fs/fs_platform.h"
#include "fs/type/fs_type_element.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


/// Structure that holds a directory system element information
struct osapi_fs_dir_S
{
  t_element			element;	///< General element information
  t_fs_directoryInfo		dir;		///< Directory element specific information
};

typedef struct osapi_fs_dir_S			t_dir;



#endif /* OSAPI_FS_TYPE_DIR_H_ */
