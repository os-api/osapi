// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General baseline specification
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_BASELINE_H_
#define OSAPI_GENERAL_BASELINE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import own headers
#include "general/general_language.h"
#include "general/general_compiler.h"

// OSAPI Baseline definition
#include "general/general_baseline_language.h"
#include "general/general_baseline_compiler.h"


// Platform baseline
#if defined(OS_LINUX) || defined(__linux__) || defined(LINUX)

 #define OS_LINUX 1
 #include "general/general_baseline_linux.h"

#elif defined(OS_WINDOWS) || defined(_WIN32) || defined(_WIN64)

 #define OS_WINDOWS 1

#endif


#endif /* OSAPI_GENERAL_BASELINE_H_ */
