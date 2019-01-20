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

#ifndef OSAPI_BASELINE_LANGUAGE_DISABLE

#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C ) && ( OSAPI_LANGUAGE_VERSION < 201112L )
  #error "C language version bellow baseline."
#endif


#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C_PLUS_PLUS ) && ( OSAPI_LANGUAGE_VERSION < 201103L )
  #error "C++ language version bellow baseline."
#endif


#endif	// If baseline language not disabled

#endif /* GENERAL_BASELINE_LANGUAGE_H_ */
