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

#include <unistd.h>
#include <time.h>
#include <errno.h>

typedef struct timespec t_hrTime;
typedef time_t t_time;

struct s_clock
{
  struct timespec time;
  ;
  struct tm interval;
};

typedef struct s_clock t_clock;


#endif	// If POSIX is defined

#endif /* OSAPI_CLOCK_POSIX_H_ */
