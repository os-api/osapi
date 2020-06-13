// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General CPU architecture baseline specification
//
// *****************************************************************************************


#ifndef OSAPI_GENERAL_BASELINE_ARCHITECTURE_H_
#define OSAPI_GENERAL_BASELINE_ARCHITECTURE_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Find what CPU architecture this compilation is targeted for
#include "general/general_architecture.h"


// *****************************************************************************************
//
// Section: Baseline for INTEL
//
// *****************************************************************************************

#if ( OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86 )

#if ( OSAPI_CPU_ARCHITECTURE_VERSION == OSAPI_CPU_ARCHITECTURE_INTEL_386 )
  #error "I386: Unsupported Intel Architecture"
#elif ( OSAPI_CPU_ARCHITECTURE_VERSION == OSAPI_CPU_ARCHITECTURE_INTEL_486 )
  #error "I486: Unsupported Intel Architecture"
#endif

#endif	// End of X86 Architecture baseline verification


// *****************************************************************************************
//
// Section: Baseline for SPARC
//
// *****************************************************************************************

#if ( OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_SPARC )

#if ( OSAPI_CPU_ARCHITECTURE_VERSION != OSAPI_CPU_ARCHITECTURE_SPARC_V9 )
  #error "Unsupported SPARC Architecture"
#endif

#endif	// End of X86 Architecture baseline verification



// *****************************************************************************************
//
// Section: Other baselines that must be met
//
// *****************************************************************************************

/*

#if ( OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_XXX )

#if ( OSAPI_CPU_ARCHITECTURE_VERSION != OSAPI_CPU_ARCHITECTURE_XXX_XXX )
  #error "Unsupported SPARC Architecture"
#endif

#endif	// End of XXX Architecture baseline verification

*/



#endif /* OSAPI_GENERAL_BASELINE_ARCHITECTURE_H_ */
