/*
 * os_linux.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef OS_OS_LINUX_H_
#define OS_OS_LINUX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <sys/utsname.h>

#define OSAPI_OS_MAX_INFO_SIZE		_UTSNAME_LENGTH
#define _UTSNAME_DOMAIN_LENGTH		_UTSNAME_LENGTH

#define	OSAPI_OS_MAX_KERNEL_NAME	OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_NODE_NAME		OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_RELEASE_NAME	OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_VERSION		OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_MACHINE_NAME	OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_DOMAIN_NAME	OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_PROVIDER_NAME	OSAPI_OS_MAX_INFO_SIZE
#define	OSAPI_OS_MAX_PROVIDER_RELEASE	16

#include <os/os_posix.h>

#define OSAPI_OS_RELEASE_INFO_FILE	"/etc/os-release"

// Internal function declarations
t_status os_info_provider_get( t_osInfo * );

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_LINUX_H_ */
