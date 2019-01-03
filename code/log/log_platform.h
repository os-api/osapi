// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	System Log platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_LOG_PLATFORM_H_
#define OSAPI_LOG_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include "log/linux/log_linux.h"
#endif


#endif /* OSAPI_LOG_PLATFORM_H_ */
