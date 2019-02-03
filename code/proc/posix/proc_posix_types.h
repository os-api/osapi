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
#include "proc/posix/proc_posix_defs.h"
#include "proc/proc_signal_types.h"

// *****************************************************************************************
//
// Section: Module Type declarations
//
// *****************************************************************************************

/// The PID type for a POSIX implementation
typedef pid_t		t_pid;
/// The signal type for a POSIX implementation
typedef int		t_signal;
/// The process function in a POSIX implementation
typedef Byte 		(*t_procfunc)(void);

/// The proc structure for a process in a POSIX compliant system
struct  s_proc
{
  // Base process properties
  bool		has_pid;	///< PID information available
  t_pid		pid;		///< Process ID given by the kernel
  bool		has_uid;	///< User ID information available
  t_uid		uid;		///< Runtime User  ID
  bool		has_gid;	///< Group ID information available
  t_gid		gid;		///< Runtime Group ID
  char	*	name;		///< Process name
  size_t	nargs;		///< Number of command line arguments
  char	**	args;		///< Array of command line arguments
  size_t	nenv;		///< Number of elements in the environment
  char	**	env;		///< Environment array

  // Process options

  // Process action - Function to be executed upon process creation
  t_procfunc	func;		///< Pointer to function to customize process settings (called between fork and exec)
};

/// Process type
typedef struct s_proc		t_proc;

/// Library type
typedef void *			t_library;

/// Signal action type
typedef struct sigaction	t_sig_action;

/// Signal function type
typedef void 			(* t_sig_func)( int );

/// Process status structure
struct s_proc_status
{
  bool		running;	///< Terminated or still running?
  bool		alive;		///< A process may not be running but still alive (if suspended/SIGSTOP)

  /// Process status structure that contains detail information
  struct details
  {
   unsigned int code:8;		///< Returned status of the dead process
   unsigned int normal:1;	///< Normal exit? if so them there is a status available..
   unsigned int signal:1;	///< Exit due to signal ?
   unsigned int core:1;		///< Core dump generated ?
   unsigned int stopped:1;	///< Process in stopped state
   unsigned int cont:1;		///< Process was resumed by a CONT signal
  } exit; ///< The exit information from a terminated process

  t_signal	signumber;	///< Signal that caused the termination/stop/continuation
  // Any other
};

/// The process status type
typedef struct s_proc_status	t_proc_status;


// *****************************************************************************************
//
// Section: Enumerators
//
// *****************************************************************************************

enum osapi_proc_target
{
  e_proc_target_none = 0,
  e_proc_target_parent,
  e_proc_target_pgroup,
  e_proc_target_session
};

// *****************************************************************************************
//
// Section: Macros
//
// *****************************************************************************************

// Macros for client applications to check the status of the process

/// Test if a process is alived based on the process type x
#define proc_alive( x )		(x.alive)
/// Test if a process is running based on the process type x
#define proc_running( x )	(x.running)

/// Test if a process exited normally based on the process type x
#define proc_exitNormal( x )	(x.exit.normal  ? 1: 0 )
/// Test if a process exited due to a signal based on the process type x
#define proc_exitSignal( x )	(x.exit.signal  ? 1: 0 )
/// Test if a process core dumped based on the process type x
#define proc_core( x )		(x.exit.core    ? 1: 0 )

/// Get signal that caused process termination based on the process type x
#define proc_getSignal( x )	(x.exit.signal  ? x.signumber: 0 )
/// Get process exit code based on the process type x
#define proc_getStatus( x )	(x.exit.code)



#endif /* OSAPI_PROC_POSIX_TYPES_H_ */
