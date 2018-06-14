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


// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif


#include <sys/types.h>

// Define POSIX opaque types that are cross functional modules
typedef uid_t	t_uid;		// User  ID
typedef gid_t	t_gid;		// Group ID


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif	// Posix only

#endif /* COMMON_TYPES_POSIX_H_ */