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
#include "fs/type/fs_type_elementInfo.h"


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Enumeration of the possible Open file modes
enum osapi_fs_e_fileOpenMode
{
  osapi_fs_file_openMode_default	= 0,  		///< Open file using system dependent default mode
  osapi_fs_file_openMode_read		= 1,  		///< Open file for reading
  osapi_fs_file_openMode_write		= 2,  		///< Open file for writing
  osapi_fs_file_openMode_readWrite	= 3   		///< Open file for read/write
};

typedef enum osapi_fs_e_fileOpenMode		t_file_openMode;

/// Enumeration of the possible file open locations
enum osapi_fs_e_file_position
{
  osapi_fs_file_position_none		= SEEK_CUR,	///< No file position specified, current location to be used
  osapi_fs_file_position_begin		= SEEK_SET,  	///< Start operating in the beginning of file
  osapi_fs_file_position_end		= SEEK_END  	///< Start operating at the end of file
};

typedef enum osapi_fs_e_file_position		t_file_location;

/// Structure that holds all file system element information
struct osapi_fs_s_file
{
  t_fs_ostate					state;	///< Current file state
  t_fs_elementInfo				info;	///< General element information
  t_fs_fileInfo					data;	///< File element specific information
};

typedef struct osapi_fs_s_file			t_file;




#endif /* OSAPI_FS_TYPE_FILE_H_ */
