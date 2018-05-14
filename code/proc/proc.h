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


#include <status/status.h>
#include <proc/proc_defs.h>
#include <proc/proc_platform.h>

#pragma GCC visibility push(default)		// Start of public interface

t_status	proc_module_supported		( void 			);
t_status	proc_id_get			( t_pid * 		);
t_status	proc_parentID_get		( t_pid * 		);
t_status	proc_signal_send		( t_pid, t_signal 	);

// Process (wall) Time functionality

//t_status	proc_

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_H_ */
