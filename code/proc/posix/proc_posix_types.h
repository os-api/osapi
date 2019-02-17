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

#include "general/general_baseline.h"

#ifdef OSAPI_POSIX

// Include standard headers
#include <signal.h>
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "common/types/common_types.h"

// Own module types
#include "proc/posix/proc_posix_defs.h"
//#include "proc/posix/proc_posix_status.h"
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
  int			info;		///< Information about the existence of a status (meta-information)
  int			exit_code;	///< The returned exit code from the process when there is a normal exit
  t_signal		signumber;	///< Signal that caused the termination/stop/continuation
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
// Section: Macros for client applications to check the status of the process
//
// *****************************************************************************************

/// Test if a process exited normally based on the process type x
#define proc_exitNormal( x )	( x.info == osapi_e_proc_status_available )
/// Test if a process exited due to a signal based on the process type x
#define proc_exitSignal( x )	( x.info == osapi_e_proc_status_signal )
/// Test if a process core dumped based on the process type x
#define proc_core( x )		( x.info == osapi_e_proc_status_core )

/// Get the status meta information
#define proc_getStatusInfo( x )		( x.info )

/// Get signal that caused process termination based on the process type x
#define proc_getStatusSignal( x )	( x.signumber )

/// Get process exit code based on the process type x
#define proc_getStatusCode( x )		( x.exit_code )

/// Allow client applications to understand if the process is a parent
#define proc_isParent( x )		( x.has_pid && x.pid != 0)

/// Allow client applications to understand if the process is a child
#define proc_isChild( x )		( x.has_pid && x.pid == 0 )

/// If created process is father, get the child PID
#define proc_getChildPID( x )		( x.has_pid ? x.pid : -1 )

#endif	// OSAPI_POSIX

#endif /* OSAPI_PROC_POSIX_TYPES_H_ */
