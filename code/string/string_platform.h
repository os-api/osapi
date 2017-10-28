/*
 * util_platform.h
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#ifndef UTIL_UTIL_PLATFORM_H_
#define UTIL_UTIL_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include "../../code/string/string_posix.h"
#elif OS_SOLARIS
	#include <string/string_posix.h>
#endif



#endif /* UTIL_UTIL_PLATFORM_H_ */
