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

#include "general/general_defs.h"
#include "common/common_types.h"

typedef pid_t		t_pid;
typedef int		t_signal;
typedef Byte 		(*t_procfunc)(void);

struct  s_proc
{
  // Base process properties
  t_pid		pid;		// Process ID given by the kernel
  t_uid		uid;		// Runtime User  ID
  t_gid		gid;		// Runtime Group ID
  char	*	name;		// Process name
  size_t	nargs;		// Number of command line arguments
  char	**	args;		// Array of command line arguments
  char	**	env;		// Environment array

  // Process options

  // Process action - Function to be executed upon process creation
  t_procfunc	func;		// Pointer to function to customize process settings (called between fork and exec)
};

typedef struct s_proc		t_proc;


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_PROC_POSIX_H_ */
