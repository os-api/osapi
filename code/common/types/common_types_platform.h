// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module platform OS selection file for types
//
// *****************************************************************************************

#ifndef OSAPI_COMON_TYPES_PLATFORM_H_
#define OSAPI_COMON_TYPES_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OS specific definitions
#ifdef	OS_LINUX
	#include "common/linux/common_types_linux.h"
#endif

#endif /* OSAPI_COMON_TYPES_PLATFORM_H_ */
