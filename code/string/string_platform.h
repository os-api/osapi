// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_STRING_PLATFORM_H_
#define OSAPI_STRING_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include <string/string_posix.h>
#endif



#endif /* OSAPI_STRING_PLATFORM_H_ */
