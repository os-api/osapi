// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS type declarations for Linux OS
//
// *****************************************************************************************

#ifndef OSAPI_OS_POSIX_TYPES_H_
#define OSAPI_OS_POSIX_TYPES_H_


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup OS
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif


/// The OS information structure
struct s_osInfo
{
  char		kernel		[ OSAPI_OS_MAX_KERNEL_NAME	];	///< The Kernel name
  char		node		[ OSAPI_OS_MAX_NODE_NAME	];	///< The machine node name
  char		release		[ OSAPI_OS_MAX_RELEASE_NAME	];	///< The Kernel Release
  char		version		[ OSAPI_OS_MAX_VERSION		];	///< The Kernel version
  char		machine		[ OSAPI_OS_MAX_MACHINE_NAME	];	///< The machine name
  char		domain		[ OSAPI_OS_MAX_DOMAIN_NAME	];	///< The domain to which the machine belongs
  char		provider	[ OSAPI_OS_MAX_PROVIDER_NAME	];	///< The OS vendor name
  char		provider_release[ OSAPI_OS_MAX_PROVIDER_RELEASE	];	///< The OS vendor release
};


/// The OS information type
typedef struct s_osInfo		t_osInfo;



///@}
///@}


#endif /* OSAPI_OS_POSIX_TYPES_H_ */
