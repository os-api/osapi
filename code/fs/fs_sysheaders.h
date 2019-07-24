// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS platform OS selection file for implementation files (.c)
//
// *****************************************************************************************

#ifndef OSAPI_FS_SYSHEADERS_H_
#define OSAPI_FS_SYSHEADERS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OS specific types
#include "fs/fs_platform.h"

// Import OS specific headers
#ifdef OS_LINUX
    // #include "fs/linux/fs_linux.h"
    #include "fs/posix/fs_posix.h"
    #include "fs/unix/fs_unix.h"
#endif


#endif /* OSAPI_FS_SYSHEADERS_H_ */
