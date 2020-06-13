// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_PLATFORM_H_
#define OSAPI_MACHINE_PLATFORM_H_

/* Import CPU Architecture specific definitions */
#include "common/common_machine.h"

#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)
 // Include here any machine specific definitions

#else
  #error "Unknown CPU Architecture"
#endif

#if (OSAPI_COMPILER == OSAPI_COMPILER_GNU ) || ( OSAPI_COMPILER == OSAPI_COMPILER_CLANG )

  // Import CLang / GCC code
  // #include "machine/compilers/type/..."

#else
  #error "Unknown compiler"
#endif

/* Import OS specific definitions */
#ifdef	OS_LINUX
 #include "machine/linux/machine_linux_types.h"

#else
  #error "Unknown Operating System"
#endif


#endif /* OSAPI_MACHINE_PLATFORM_H_ */
