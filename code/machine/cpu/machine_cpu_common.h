// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Intel/AMD compiler specific declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_COMMON_H_
#define OSAPI_MACHINE_COMPILERS_COMMON_H_

#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>

// Generic OSAPI includes

// Own declarations


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup MACHINE
/// @brief The machine management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Internal Machine CPU (X86/X64) API
//
// *****************************************************************************************


t_status internal_cpu_amd_getFeatures	( uint32_t featLevel, t_cpu_feature_list * p_list );
t_status internal_cpu_intel_getFeatures	( uint32_t featLevel, t_cpu_feature_list * p_list );

///@}
///@}



// *****************************************************************************************
//
// Section: Define Constants/Macros
//
// *****************************************************************************************


#endif	// X86 & AMD64

#endif /* OSAPI_MACHINE_CPU_COMMON_H_ */
