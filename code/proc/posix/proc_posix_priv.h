// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a POSIX compliant implementation
//
// *****************************************************************************************

#ifndef PROC_POSIX_PRIV_H_
#define PROC_POSIX_PRIV_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************


// Force baseline before system headers
#include "general/general_baseline.h"

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX

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


OSAPI_NORETURN void	proc_app_launch		( t_proc * 				);


#endif	// POSIX

#endif // PROC_POSIX_PRIV_H_
