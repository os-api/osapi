/*
 * proc.h
 *
 *  Created on: 05/03/2017
 *      Author: joao
 */

#ifndef PROC_H_
#define PROC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include "status/status.h"
#include "common/common_types.h"
#include "proc/proc_defs.h"
#include "proc/proc_platform.h"

#pragma GCC visibility push(default)		// Start of public interface

t_status	proc_module_supported		( void 			);


// + Instance management
// ++ Life cycle
t_status proc_instance_new			( t_proc * p_process			);
t_status proc_instance_create			( t_proc * p_process			);
t_status proc_instance_destroy			( t_proc * p_process			);

// ++ Operations
// t_status string_instance_put			( const char *, t_string *		);

// + Identity management
t_status	proc_id_get			( t_pid * 		);
t_status	proc_parentID_get		( t_pid * 		);

// + Signal handling
t_status	proc_signal_send		( t_pid, t_signal 	);


// Process (wall) Time functionality

//t_status	proc_

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_H_ */
