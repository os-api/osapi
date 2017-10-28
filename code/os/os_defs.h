/*
 * os_defs.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef OS_OS_DEFS_H_
#define OS_OS_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


/* Import OS specific definitions
#ifdef	OS_LINUX
	#include "os/os_linux_defs.h"
#elif OS_SOLARIS
	#include "os/os_solaris_defs.h"
#endif
*/

// Define function IDs
enum
{
	f_os_none = 0,
	f_os_module_supported,
	f_os_info_get,
	f_os_name_get,
	f_os_other
};



// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_DEFS_H_ */
