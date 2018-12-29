// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX type declarations
//
// *****************************************************************************************

#ifndef PROC_POSIX_SIGNAL_MACROS_H_
#define PROC_POSIX_SIGNAL_MACROS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers
#include <signal.h>
#include <stdbool.h>

// *****************************************************************************************
//
// Section: Macro definitions
//
// *****************************************************************************************

#define proc_isSignalChild( x )		(x == SIGCHLD)
#define proc_isSignalTerm( x )		(x == SIGTERM)
#define proc_isSignalKill( x )		(x == SIGKILL)
#define proc_isSignalHup( x )		(x == SIGHUP)
#define proc_isSignalAbort( x )		(x == SIGABRT)

#endif /* PROC_POSIX_SIGNAL_MACROS_H_ */
