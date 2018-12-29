// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a POSIX compliant implementation
//
// *****************************************************************************************

#ifndef PROC_LINUX_PRIV_H_
#define PROC_LINUX_PRIV_H_

#ifdef OS_LINUX

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
#include "status/status.h"

#include "proc/proc_types.h"

// *****************************************************************************************
//
// Section: Module Process POSIX private declarations
//
// *****************************************************************************************

t_status proc_status_get( t_pid, t_pid *, t_proc_status * );




#endif // OS Linux

#endif /* PROC_LINUX_PRIV_H_ */
