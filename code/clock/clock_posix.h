/*
 * clock_posix.h
 *
 *  Created on: 29/04/2017
 *      Author: joao
 */

#ifndef CLOCK_POSIX_H_
#define CLOCK_POSIX_H_

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#include <unistd.h>
#include <time.h>
#include <errno.h>

typedef struct timespec	t_hrTime;
typedef time_t		t_time;

struct s_clock
{
  struct timespec	time;;
  struct tm 		interval;
};

typedef struct s_clock t_clock;


#endif /* CLOCK_POSIX_H_ */
