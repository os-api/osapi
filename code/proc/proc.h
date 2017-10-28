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


#include "../../code/status/status.h"
#include "../../code/proc/proc_defs.h"
#include "../../code/proc/proc_platform.h"

t_status	proc_module_supported		( void 			);
t_status	proc_pid_get			( t_pid * 		);
t_status	proc_parentPid_get		( t_pid * 		);
t_status	proc_signal_send		( t_pid, t_signal 	);

// Process (wall) Time functionality

//t_status	proc_

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_H_ */
