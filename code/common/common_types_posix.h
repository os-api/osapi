// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common POSIX declarations
//
// *****************************************************************************************

#ifndef COMMON_TYPES_POSIX_H_
#define COMMON_TYPES_POSIX_H_

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




#endif	// Posix only

#endif /* COMMON_TYPES_POSIX_H_ */
