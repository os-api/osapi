/*
 * string_posix.h
 *
 *  Created on: 07/05/2017
 *      Author: joao
 */

#ifndef STRING_POSIX_H_
#define STRING_POSIX_H_

// Only relevant is OS is Linux
#ifdef OSAPI_POSIX

// The following definition is required by the system headers below
#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#endif	// End of POSIX declarations

#endif /* STRING_POSIX_H_ */
