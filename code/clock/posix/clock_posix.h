// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_POSIX_H_
#define OSAPI_CLOCK_POSIX_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard C types
#include <unistd.h>
#include <time.h>
#include <errno.h>

// Import OSAPI types
#include "common/common_types.h"

// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************



#endif	// If POSIX is defined

#endif /* OSAPI_CLOCK_POSIX_H_ */
