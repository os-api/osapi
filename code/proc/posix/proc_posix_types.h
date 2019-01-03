// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX type declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_POSIX_TYPES_H_
#define OSAPI_PROC_POSIX_TYPES_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers
#include <signal.h>
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "common/types/common_types.h"

// Own module types
#include "proc/proc_signal_types.h"

// *****************************************************************************************
//
// Section: Module Type declaration
//
// *****************************************************************************************

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
  size_t	nenv;		// Number of elements in the environment
  char	**	env;		// Environment array

  // Process options

  // Process action - Function to be executed upon process creation
  t_procfunc	func;		// Pointer to function to customize process settings (called between fork and exec)
};

typedef struct s_proc		t_proc;

typedef void *			t_library;

typedef struct sigaction	t_sig_action;

typedef void 			(* t_sig_func)( int );

// Process status

struct s_proc_status
{
  bool		running;	// Terminated or still running?
  bool		alive;		// A process may not be running but still alive (if suspended/SIGSTOP)
  struct details
  {
   unsigned int code:8;		// Returned status of the dead process
   unsigned int normal:1;	// Normal exit? if so them there is a status available..
   unsigned int signal:1;	// Exit due to signal ?
   unsigned int core:1;		// Core dump generated ?
   unsigned int stopped:1;	// Process in stopped state
   unsigned int cont:1;		// Process was resumed by a CONT signal
  } exit;

  t_signal	signumber;	// Signal that caused the termination/stop/continuation
  // Any other
};


typedef struct s_proc_status	t_proc_status;

// Macros for client applications to check the status of the process
#define proc_alive( x )		(x.alive)
#define proc_running( x )	(x.running)

#define proc_exitNormal( x )	(x.exit.normal  ? 1: 0 )
#define proc_exitSignal( x )	(x.exit.signal  ? 1: 0 )
#define proc_core( x )		(x.exit.core    ? 1: 0 )

#define proc_getSignal( x )	(x.exit.signal  ? x.signumber: 0 )
#define proc_getStatus( x )	(x.exit.code)



#endif /* OSAPI_PROC_POSIX_TYPES_H_ */
