// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPES_POSIX_H_
#define OSAPI_COMMON_TYPES_POSIX_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import system headers
#include <sys/types.h>


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

// Define POSIX opaque types that are cross functional modules
typedef uid_t	t_uid;		// User  ID
typedef gid_t	t_gid;		// Group ID

// Define the required C-String space to represent uid_t/gid_t
#define OSAPI_STRING_SIZE_UID	11
#define OSAPI_STRING_SIZE_GID	11


#endif	// Posix only

#endif /* OSAPI_COMMON_TYPES_POSIX_H_ */
