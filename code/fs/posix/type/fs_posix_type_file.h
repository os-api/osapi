// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPE_FILE_H_
#define OSAPI_FS_POSIX_TYPE_FILE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import POSIX type headers
#include <stdio.h>
#include <stdbool.h>

// Import module types
#include "fs/type/fs_type_ostate.h"

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************


/// Structure containing the C/POSIX file pointer/handler information
struct osapi_fs_s_file_info
{
  t_fs_ostate		state;			///< Current state
  bool			isBuffered;		///< Which open was used? Buffered or not?
  int			descriptor;		///< File descriptor (raw)
  FILE	*		handle;			///< File descriptor (stream oriented)
  t_size		block_size;		///< File block size for buffered operations
};

typedef struct osapi_fs_s_file_info		t_fs_fileInfo;



#endif /* OSAPI_FS_POSIX_TYPE_FILE_H_ */
