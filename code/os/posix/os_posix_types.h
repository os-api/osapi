// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS type declarations for Linux OS
//
// *****************************************************************************************

#ifndef OSAPI_POSIX_TYPES_H_
#define OSAPI_POSIX_TYPES_H_

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

struct s_osInfo
{
  char		kernel		[ OSAPI_OS_MAX_KERNEL_NAME	];
  char		node		[ OSAPI_OS_MAX_NODE_NAME	];
  char		release		[ OSAPI_OS_MAX_RELEASE_NAME	];
  char		version		[ OSAPI_OS_MAX_VERSION		];
  char		machine		[ OSAPI_OS_MAX_MACHINE_NAME	];
  char		domain		[ OSAPI_OS_MAX_DOMAIN_NAME	];
  char		provider	[ OSAPI_OS_MAX_PROVIDER_NAME	];
  char		provider_release[ OSAPI_OS_MAX_PROVIDER_RELEASE	];
};

typedef struct s_osInfo		t_osInfo;




#endif /* OSAPI_POSIX_TYPES_H_ */
