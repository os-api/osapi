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
	#include "common/linux/common_types_linux.h"
#endif

#endif /* COMMON_COMON_TYPES_PLATFORM_H_ */
