// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module using a POSIX implementation
//
// *****************************************************************************************

#ifndef OSAPI_STRING_POSIX_H_
#define OSAPI_STRING_POSIX_H_

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX

// The following definition is required by the system headers below
#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#endif	// End of POSIX declarations

#endif /* OSAPI_STRING_POSIX_H_ */
