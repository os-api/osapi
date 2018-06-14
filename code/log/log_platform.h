// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	System Log platform OS selection file
//
// *****************************************************************************************

#ifndef LOG_LOG_PLATFORM_H_
#define LOG_LOG_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include "log/log_linux.h"
#endif


#endif /* LOG_LOG_PLATFORM_H_ */
