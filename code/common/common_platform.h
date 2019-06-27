// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module platform OS selection file for types
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_PLATFORM_H_
#define OSAPI_COMMON_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OS specific definitions
#ifdef	OS_LINUX
	#include "common/linux/common_linux_types.h"
	#include "common/posix/common_posix_types.h"
#endif

#endif /* OSAPI_COMMON_PLATFORM_H_ */
