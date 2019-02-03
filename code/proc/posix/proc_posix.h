// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_POSIX_H_
#define OSAPI_PROC_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own headers
#include "proc/posix/proc_posix_types.h"

// *****************************************************************************************
//
// Section: Function declaration for POSIX systems (with or without POSIX implementation)
//	    The implementation must be done either POSIX wide or in each UNIX system.
//
// *****************************************************************************************

t_status posix_library_load	( const char * pathname, int options, t_library * p_library	);
t_status posix_get_parent_pid	( t_pid childPid, t_pid * p_parentPid				);

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_PROC_POSIX_H_ */
