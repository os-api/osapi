// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Platform selector for the status module
//
// *****************************************************************************************

#ifndef STATUS_PLATFORM_H_
#define STATUS_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
  #include "status/status_linux.h"
#endif



#endif /* STATUS_PLATFORM_H_ */
