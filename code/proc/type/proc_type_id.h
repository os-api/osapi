// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc ID declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPE_ID_H_
#define OSAPI_PROC_TYPE_ID_H_


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
#include "proc/proc_platform.h"
#include "proc/proc_state.h"


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
struct osapi_proc_id_S
{
  t_pid		pid;			///< Process ID
  char		name[ NAME_MAX + 1 ];	///< Process name
  t_pid		ppid;			///< Parent PID
  t_pid		pgrp;			///< Process Group ID
  t_pid		session;		///< Session ID
  int		tpgid;			///< The ID of the foreground process group of the controlling terminal of the process
};

/// The Process identity type
typedef struct osapi_proc_id_S		t_proc_id;


///@}
///@}


#endif /* OSAPI_PROC_TYPE_ID_H_ */
