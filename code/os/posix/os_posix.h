/*
 * os_posix.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef OS_OS_POSIX_H_
#define OS_OS_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

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

// Internal POSIX module functions
t_status os_posix_info_get( t_osInfo * p_osInfo );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_POSIX_H_ */
