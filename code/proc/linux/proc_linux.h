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


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import own headers
#include <proc/linux/proc_linux_types.h>

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


// *****************************************************************************************
//
// Section: Private function declarations
//
// *****************************************************************************************


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* PROC_LINUX_H_ */
