// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Security module POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_SEC_POSIX_TYPES_H_
#define OSAPI_SEC_POSIX_TYPES_H_

// Only relevant is OS is Linux
#ifdef OSAPI_POSIX

// The following definition is required by the system headers below
#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import System headers
#include <unistd.h>
#include <sys/types.h>



// *****************************************************************************************
//
// Section: Constant definitions
//
// *****************************************************************************************

// What is the size required to store a uid_t/gid_t types in a null terminated C-String (types as 32 bits)
#define OSAPI_STRING_SIZE_UID		11
#define OSAPI_STRING_SIZE_GID		11


// *****************************************************************************************
//
// Section: Type definition
//
// *****************************************************************************************

typedef uid_t		t_user_id;
typedef gid_t		t_group_id;





#endif	// End of POSIX Implementation

#endif /* OSAPI_SEC_POSIX_TYPES_H_ */
