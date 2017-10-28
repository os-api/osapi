/*
 * proc_posix.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef PROC_PROC_POSIX_H_
#define PROC_PROC_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

#define t_pid		pid_t
#define t_signal	int


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_PROC_POSIX_H_ */
