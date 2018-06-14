// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Security module POSIX declarations
//
// *****************************************************************************************

#ifndef CODE_SEC_SEC_POSIX_H_
#define CODE_SEC_SEC_POSIX_H_

// Only relevant is OS is Linux
#ifdef OSAPI_POSIX

// The following definition is required by the system headers below
#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#include <unistd.h>
#include <sys/types.h>

typedef uid_t		t_user_id;
typedef gid_t		t_group_id;

#endif	// End of POSIX Implementation

#endif /* CODE_SEC_SEC_POSIX_H_ */
