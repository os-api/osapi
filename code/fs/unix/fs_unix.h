// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module UNIX header
//
// *****************************************************************************************

#ifndef OSAPI_FS_UNIX_H_
#define OSAPI_FS_UNIX_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// General OSAPI headers
#include "general/general.h"
#include "status/status_types.h"

// Include own headers


// Compile only if is a POSIX implementation
#ifdef OSAPI_UNIX


// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

unsigned int	unix_get_dev_major		( dev_t dev );
unsigned int	unix_get_dev_minor		( dev_t dev );

#endif // Only in UNIX mode

#endif // OSAPI_FS_UNIX_H_
