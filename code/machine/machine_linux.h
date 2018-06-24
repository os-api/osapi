// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW Linux OS declarations
//
// *****************************************************************************************

#ifndef MACHINE_MACHINE_LINUX_H_
#define MACHINE_MACHINE_LINUX_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include System headers
#include <sys/sysinfo.h>

// Generic OSAPI includes
#include "status/status_types.h"

// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

typedef struct sysinfo		t_mem;


// *****************************************************************************************
//
// Section: Function Declarations
//
// *****************************************************************************************


t_status machine_physicalRam_get( t_mem *, uint64_t );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif	// End of OS Linux

#endif /* MACHINE_MACHINE_LINUX_H_ */
