// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define the C/C++ language baseline
//
// *****************************************************************************************

#ifndef GENERAL_BASELINE_LANGUAGE_H_
#define GENERAL_BASELINE_LANGUAGE_H_

#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C ) && ( OSAPI_LANGUAGE_VERSION < 201112L )
  #error "Baseline: C language version insufficient."
#endif


#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C_PLUS_PLUS ) && ( OSAPI_LANGUAGE_C_PLUS_PLUS < 201103L )
  #error "Baseline error: C language version insufficient."
#endif




#endif /* GENERAL_BASELINE_LANGUAGE_H_ */
