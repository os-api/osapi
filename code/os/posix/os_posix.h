// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module declarations for POSIX
//
// *****************************************************************************************

#ifndef OSAPI_OS_POSIX_H_
#define OSAPI_OS_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import system headers

// Import own headers
#include "os/posix/os_posix_types.h"

// *****************************************************************************************
//
// Section: Module Process POSIX private declarations
//
// *****************************************************************************************

// Internal POSIX module functions
t_status os_posix_info_get( t_osInfo * p_osInfo );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_OS_POSIX_H_ */
