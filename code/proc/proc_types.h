// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPES_H_
#define OSAPI_PROC_TYPES_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <time.h>

// Generic OSAPI includes
#include "general/general.h"

// Import OS specific definitions
#ifdef	OS_LINUX
 #include "proc/linux/proc_linux_types.h"
#endif


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Define process related types
//
// *****************************************************************************************

/// The process identity structure
struct s_proc_id
{
  t_pid		pid;			///< Process ID
  char		name[ NAME_MAX + 1 ];	///< Process name
  t_pid		ppid;			///< Parent PID
  t_pid		pgrp;			///< Process Group ID
  t_pid		session;		///< Session ID
  int		tpgid;			///< The ID of the foreground process group of the controlling terminal of the process
};

/// The process resources structure
struct s_proc_resources
{
  t_size	utime;			///< The process consumed user time
  t_size	stime;			///< The process consumed system time
  t_size	num_threads;		///< The number of threads in the process
  t_size	vsize;			///< The size of the virtual memory
  t_size	ram;			///< The size of the process in RAM
};

/// The Process identity type
typedef struct s_proc_id	t_proc_id;

/// The process resources type
typedef struct s_proc_resources	t_proc_resources;

/// The process information structure
struct s_proc_info
{
  t_proc_id		id;		///< The Process ID
  char			state;		///< State: System dependent
  char		**	args;		///< The process command line arguments
  // t_proc_term	term;
  t_proc_resources	resources;	///< The process resources
  time_t		starttime;	///< The process start time
};

/// The process information type
typedef struct s_proc_info	t_proc_info;


///@}
///@}


#endif /* OSAPI_PROC_TYPES_H_ */
