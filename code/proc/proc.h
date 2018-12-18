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
#include <common/types/common_types.h>

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
t_status proc_instance_create			( t_proc * 	);
t_status proc_instance_destroy			( t_pid, int	);
t_status proc_instance_clone			( int * 	);
t_status proc_instance_isRunning		( t_pid 	);

// ++ State management
t_status	proc_instance_suspendExecution	( void		);
//t_status	proc_instance_resumeExecution	( void		);

OSAPI_NORETURN
void	 proc_instance_terminate		( int 		);

// ++ Operations
// + Building process data
t_status proc_data_setCmdLine			( t_size, char *[], t_proc * );
t_status proc_data_setEnvironment		( t_size, char *[], t_proc * );

// + Identity management
t_status	proc_id_get			( t_pid * 		);
t_status	proc_id_getParent		( t_pid * 		);
/*
t_status	proc_id_getGroup		( t_pid, t_pid * 	);
t_status	proc_id_setGroup		( t_pid  		);
*/
t_status	proc_id_getSession		( t_pid, t_pid *	);
t_status	proc_id_setSetssion		( void  		);

// + Signal handling
t_status	proc_signal_supported		( int * 		);
t_status	proc_signal_clearAll		( void			);
t_status	proc_signal_send		( t_pid, t_signal 	);
t_status	proc_signal_setHandler		( t_signal, t_sig_func	);
t_status	proc_signal_resetHandler	( t_signal		);

// Add a cut through function to allow setting specific settings
//t_status	proc_signal_setAction		( t_signal, t_sig_func, t_sig_action * );

// Resource management
// + Memory management
t_status	proc_memory_allocate		( t_size, void **	);
t_status	proc_memory_deallocate		( void * 		);
t_status	proc_memory_clear		( t_size size, void *  	);

// + Consumption monitoring
/*
t_status	proc_usage_getMemory
t_status	proc_usage_getCPU
t_status	proc_usage_getIO
t_status	proc_usage_getNetwork
 */

t_status	proc_library_supported		( void 				);
t_status	proc_library_load		( char *, char *[], t_library *	);
t_status	proc_library_unload		( t_library lib			);


#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_H_ */
