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

#ifdef __cplusplus
extern "C"
  {

#else	// C Version, not C++ compiler

#if __STDC_VERSION__ != 201112L
#  error "Wrong C standard version"
#endif


#if defined(unix) || defined(__unix__) || defined(__unix)
 #include "general/general_baseline_unix.h"
#endif


#endif	// C or C++ baseline

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* GENERAL_BASELINE_H_ */
