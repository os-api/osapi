// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type declarations
//
// *****************************************************************************************

#ifndef PROC_PROC_TYPES_H_
#define PROC_PROC_TYPES_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes

// Generic OSAPI includes
#include "general/general.h"

// Import OS specific definitions
#ifdef	OS_LINUX
 #include "proc/linux/proc_linux_types.h"
#endif

// *****************************************************************************************
//
// Section: Define process related types
//
// *****************************************************************************************


struct s_proc_id
{
  t_pid		pid;			// Process ID
  char		name[ NAME_MAX + 1 ];	// Process name
  t_pid		ppid;			// Parent PID
  t_pid		pgrp;			// Process Group ID
  t_pid		session;		// Session ID
  int		tpgid;			// The ID of the foreground process group of the controlling terminal of the process
};


struct s_proc_resources
{
  t_size	utime;
  t_size	stime;
  t_size	num_threads;
  t_size	vsize;
  t_size	ram;
};


typedef struct s_proc_id	t_proc_id;
typedef struct s_proc_resources	t_proc_resources;

struct s_proc_info
{
  t_proc_id		id;
  char			state;		// State: System dependent
  char		**	args;
  // t_proc_term	term;
  t_proc_resources	resources;
};

typedef struct s_proc_info	t_proc_info;


#endif /* PROC_PROC_TYPES_H_ */
