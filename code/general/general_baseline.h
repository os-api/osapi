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
#if defined(OS_LINUX)
 #include "general/general_baseline_unix.h"
 #include "general/general_baseline_linux.h"
#endif


#endif /* OSAPI_GENERAL_BASELINE_H_ */
