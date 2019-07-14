// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_LINUX_TYPES_H_
#define OSAPI_FS_LINUX_TYPES_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import UNIX type headers
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


// *****************************************************************************************
//
// Section: Define Linux specific types
//
// *****************************************************************************************

#ifndef	_FILE_OFFSET_BITS
 #define _FILE_OFFSET_BITS	64
#endif

#endif /* OSAPI_FS_POSIX_TYPES_H_ */
