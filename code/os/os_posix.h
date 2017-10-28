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

#include <sys/utsname.h>
#include <errno.h>

typedef struct utsname		t_osInfo;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OS_OS_POSIX_H_ */
