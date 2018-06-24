// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module API
//
// *****************************************************************************************

#ifndef OS_OS_H_
#define OS_OS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "os/os_types.h"
#include "os/os_platform.h"


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

t_status os_module_supported		( void					);
t_status os_info_get			( t_osInfo * 				);
t_status os_name_get			( t_osInfo *, char **			);
t_status os_version_get			( t_osInfo *, char **			);
t_status os_release_get			( t_osInfo *, char **			);
t_status os_node_get			( t_osInfo *, char **			);
t_status os_machine_get			( t_osInfo *, char **			);
t_status os_domain_get			( t_osInfo *, char **			);
t_status os_provider_get		( t_osInfo *, char **			);
t_status os_providerRelease_get		( t_osInfo *, char **			);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_H_ */
