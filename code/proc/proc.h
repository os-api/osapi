// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API
//
// *****************************************************************************************

#ifndef PROC_H_
#define PROC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Common includes
#include "common/common_types.h"

// Own declarations
#include "proc/proc_types.h"
#include "proc/proc_platform.h"


// *****************************************************************************************
//
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

t_status	proc_module_supported		( void 			);

// + Instance management
// ++ Life cycle
t_status proc_instance_new			( t_proc * p_process			);
t_status proc_instance_create			( t_proc * p_process			);
t_status proc_instance_destroy			( t_proc * p_process			);

// ++ Operations

// + Identity management
t_status	proc_id_get			( t_pid * 		);
t_status	proc_parentID_get		( t_pid * 		);

// + Signal handling
t_status	proc_signal_send		( t_pid, t_signal 	);


// Resource management
/*
t_status	proc_usage_getMemory
t_status	proc_usage_getCPU
t_status	proc_usage_getIO
t_status	proc_usage_getNetwork
 */

t_status	proc_library_load		( const char * pathname, const char * options[], t_library * lib	);
t_status	proc_library_unload		( t_library lib								);


#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_H_ */
