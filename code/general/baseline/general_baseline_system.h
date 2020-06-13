// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General OS baseline specification
//
// *****************************************************************************************


#ifndef OSAPI_GENERAL_BASELINE_SYSTEM_H_
#define OSAPI_GENERAL_BASELINE_SYSTEM_H_


// *****************************************************************************************
//
// Section: Import headers according to the target CPU Architecture and OS
//
// *****************************************************************************************

// First the CPU
#include "general/general_architecture.h"

// Next the OS
#if defined(OS_LINUX) || defined(__linux__) || defined(LINUX)

 #define OS_LINUX    1
 #define OSAPI_LINUX 1
 #include "general/baseline/general_baseline_linux.h"

#elif defined(OS_WINDOWS) || defined(_WIN32) || defined(_WIN64)

 #define OS_WINDOWS 1

#endif


#endif /* OSAPI_GENERAL_BASELINE_SYSTEM_H_ */
