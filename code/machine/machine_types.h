// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine module declarations
//
// *****************************************************************************************

#ifndef MACHINE_MACHINE_TYPES_H_
#define MACHINE_MACHINE_TYPES_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers

// OSAPI headers
#include <common/types/common_types_ip.h>		// Import IP OSAPI generic type
#include "general/general_types.h"
#include "general/general_protocol.h"

// Platform own headers
#ifdef OS_LINUX
 #include <machine/linux/machine_types_linux.h>
#endif


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************






#endif /* MACHINE_MACHINE_TYPES_H_ */
