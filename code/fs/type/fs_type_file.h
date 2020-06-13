// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for a file Element
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_FILE_H_
#define OSAPI_FS_TYPE_FILE_H_

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
#include "fs/type/fs_type_element.h"


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Enumeration of the possible file open locations
enum osapi_fs_file_position_E
{
  osapi_fs_file_position_none		= SEEK_CUR,	///< No file position specified, current location to be used
  osapi_fs_file_position_set		= SEEK_SET,	///< No file position specified, current location to be used
  osapi_fs_file_position_begin		= SEEK_SET,  	///< Start operating in the beginning of file
  osapi_fs_file_position_end		= SEEK_END  	///< Start operating at the end of file
};

typedef enum osapi_fs_file_position_E		t_file_location;

/// Structure that holds all file system element information
struct osapi_fs_file_S
{
  t_element				element;	///< General element information
  t_fs_fileInfo				file;		///< File element specific information
};

typedef struct osapi_fs_file_S			t_file;




#endif /* OSAPI_FS_TYPE_FILE_H_ */
