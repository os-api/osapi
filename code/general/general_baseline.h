// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General baseline specification
//
// *****************************************************************************************

#ifndef GENERAL_BASELINE_H_
#define GENERAL_BASELINE_H_

// Language baseline: C or C++

#ifndef __cplusplus

#if __STDC_VERSION__ < 201112L
 #error "Wrong C standard version"
#endif

#endif	// C or C++ baseline

// Platform baseline
#if defined(OS_LINUX)
 #include "general/general_baseline_unix.h"
#endif


#endif /* GENERAL_BASELINE_H_ */
