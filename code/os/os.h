/*
 * os.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef OS_OS_H_
#define OS_OS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <status/status.h>
#include <os/os_defs.h>
#include <os/os_platform.h>

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

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_H_ */
