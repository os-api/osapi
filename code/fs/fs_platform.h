// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_FS_PLATFORM_H_
#define OSAPI_FS_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */

#ifdef OS_LINUX
      #include "fs/linux/fs_linux_types.h"
      #include "fs/posix/type/fs_posix_types.h"
#endif


#endif /* OSAPI_FS_PLATFORM_H_ */
