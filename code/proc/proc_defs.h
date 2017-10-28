/*
 * proc_defs.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef PROC_PROC_DEFS_H_
#define PROC_PROC_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


/* Import OS specific definitions
#ifdef	OS_LINUX
	#include <proc/proc_linux_defs.h>
#elif OS_SOLARIS
	#include <proc/proc_solaris_defs.h>
#endif
*/

// Define function IDs
enum
{
        f_proc_none = 0,
	f_proc_module_supported,
	f_proc_pid_get,
	f_proc_parentPid_get,
	f_proc_signal_send
};

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* PROC_PROC_DEFS_H_ */
