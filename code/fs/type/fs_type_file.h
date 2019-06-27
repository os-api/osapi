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
#include <common/common_types.h>
#include <stdio.h>

// General OSAPI headers
#include "fs/fs_platform.h"
#include "fs/type/fs_type_elementInfo.h"


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Enumeration of the possible file states
enum osapi_e_fs_file_state
{
  osapi_fs_e_file_opened	= 1234321,	///< MAGIC value to name a file state open
  osapi_fs_e_file_closed	= 9876789	///< MAGIC value to name a file state closed
};

typedef enum osapi_e_fs_file_state		t_fs_file_state;

/// Enumeration of the possible Open file modes
enum osapi_e_fs_fileOpenMode
{
  osapi_fs_e_file_default	= 0,  		///< Open file using system dependent default mode
  osapi_fs_e_file_read		= 1,  		///< Open file for reading
  osapi_fs_e_file_write		= 2,  		///< Open file for writing
  osapi_fs_e_file_readWrite	= 3   		///< Open file for read/write
};

typedef enum osapi_e_fs_fileOpenMode		t_file_openMode;

/// Enumeration of the possible file open locations
enum osapi_e_fs_fileOpenLocation
{
  osapi_fs_e_file_noPosition		= SEEK_CUR,	///< No file position specified, current location to be used
  osapi_fs_e_file_begin			= SEEK_SET,  	///< Start operating in the beginning of file
  osapi_fs_e_file_end			= SEEK_END  	///< Start operating at the end of file
};

typedef enum osapi_e_fs_fileOpenLocation	t_file_location;

/// Structure that holds all file system element information
struct osapi_s_fs_file
{
  t_fs_file_state				state;	///< Current file state
  t_fs_elementInfo				info;	///< General element information
  t_fs_fileInfo					data;	///< File element specific information
};

typedef struct osapi_s_fs_file			t_file;




#endif /* OSAPI_FS_TYPE_FILE_H_ */
