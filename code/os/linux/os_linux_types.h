// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS type declarations for Linux OS
//
// *****************************************************************************************

#ifndef OSAPI_LINUX_TYPES_H_
#define OSAPI_LINUX_TYPES_H_

// *****************************************************************************************
//
// Section: Constant/Macro definitions
//
// *****************************************************************************************

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

#define OSAPI_OS_RELEASE_INFO_FILE	"/etc/os-release"


#endif /* OSAPI_LINUX_TYPES_H_ */
