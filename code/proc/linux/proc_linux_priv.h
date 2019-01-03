// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a POSIX compliant implementation
//
// *****************************************************************************************

#ifndef OSAPI_PROC_LINUX_PRIV_H_
#define OSAPI_PROC_LINUX_PRIV_H_

#ifdef OS_LINUX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <stdio.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc_types.h"

// *****************************************************************************************
//
// Section: Module Process Linux private declarations
//
// *****************************************************************************************

t_status 	proc_status_get			( t_pid, t_pid *, t_proc_status * 	);
t_status 	parse_linux_proc_stat_line	( char *, t_proc_info * 		);
t_status 	parse_linux_proc_stat_file	( t_pid,  t_proc_info *			);
t_status 	choose_linux_proc_stat_decoder	( FILE *, t_proc_info *			);
bool		has_linux_proc_stat_file_spaces	( char *				);



#endif // OS Linux

#endif /* OSAPI_PROC_LINUX_PRIV_H_ */
