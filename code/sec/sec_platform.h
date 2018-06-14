// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec module platform OS selection file
//
// *****************************************************************************************

#ifndef SEC_SEC_PLATFORM_H_
#define SEC_SEC_PLATFORM_H_

// Import OS specific definitions
#ifdef	OS_LINUX
	#include "sec/sec_linux.h"
//#elif OS_SOLARIS
//	#include <sec/sec_solaris.h>
#endif



#endif /* SEC_SEC_PLATFORM_H_ */
