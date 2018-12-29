// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc Module Linux header
//
// *****************************************************************************************

#ifndef PROC_LINUX_H_
#define PROC_LINUX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// Only relevant is OS is POSIX compliant
#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <dlfcn.h>

// Import own headers
#include "proc/linux/proc_linux_types.h"

// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

const t_option lib_options[] = {
        { "RTLD_LAZY", 	 RTLD_LAZY 		},
	{ "RTLD_NOW", 	 RTLD_NOW 		},
	{ "RTLD_GLOBAL", RTLD_GLOBAL	 	},
	{ "RTLD_LOCAL",  RTLD_LOCAL 		},
        { "",		 OSAPI_OPTIONS_END	},
};


#endif	// OS_LINUX

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_LINUX_H_ */
