// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec module platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_SEC_PLATFORM_H_
#define OSAPI_SEC_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OS specific definitions
#ifdef OS_LINUX
	#include "sec/linux/sec_linux.h"
#endif



#endif /* OSAPI_SEC_PLATFORM_H_ */
