// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX type declarations
//
// *****************************************************************************************

#ifndef PROC_PROC_POSIX_TYPES_H_
#define PROC_PROC_POSIX_TYPES_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "common/common_types.h"

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
  char	**	env;		// Environment array

  // Process options

  // Process action - Function to be executed upon process creation
  t_procfunc	func;		// Pointer to function to customize process settings (called between fork and exec)
};

typedef struct s_proc		t_proc;

typedef void *			t_library;


#endif /* PROC_PROC_POSIX_TYPES_H_ */
