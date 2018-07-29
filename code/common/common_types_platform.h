// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module platform OS selection file for types
//
// *****************************************************************************************

#ifndef COMMON_COMON_TYPES_PLATFORM_H_
#define COMMON_COMON_TYPES_PLATFORM_H_

// Import OS specific definitions
#ifdef	OS_LINUX
	#include "common/common_types_linux.h"
/*
#elif OS_SOLARIS
	#include <util/util_solaris.h>
*/



#endif

#endif /* COMMON_COMON_TYPES_PLATFORM_H_ */
