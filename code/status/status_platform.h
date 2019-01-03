// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Platform selector for the status module
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_PLATFORM_H_
#define OSAPI_STATUS_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
  #include "status/linux/status_linux.h"
#endif



#endif /* OSAPI_STATUS_PLATFORM_H_ */
