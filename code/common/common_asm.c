// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Machine ASM interface
//		This is compiler and CPU dependent, so there must be two conditions checked
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI headers
#include "general/general_baseline.h"

// Include standard headers
#include <string.h>		// Required by memset

// Own declarations
#include "common/common_machine.h"


// *****************************************************************************************
//
// Section: Compiler Function definitions for different CPU Architectures
//
// *****************************************************************************************

// For a given Compiler
#if (OSAPI_COMPILER == OSAPI_COMPILER_GNU ) || ( OSAPI_COMPILER == OSAPI_COMPILER_CLANG )

// And for a given CPU architecture
#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)

// This call needs to be implemented for every CPU supported architecture
int common_asm_cpuid( uint32_t op, uint32_t param,  t_cpu_regs * p_regs )
{
  if( p_regs == NULL ) return 1;

  memset( p_regs, '\0', sizeof(t_cpu_regs) );

  __asm__ volatile ("cpuid\n\t"						\
             : "=a" (p_regs->eax), "=b" (p_regs->ebx), "=c" (p_regs->ecx), "=d" (p_regs->edx)	\
             : "a" (op), "c" (param));

  return 0;
}


// Add other CPU architectures in #else blocks, the last one is the unsupported one

#else

int common_asm_cpuid( uint32_t op, uint32_t param,  t_cpu_regs * p_regs )
{
  return 1;
}

#endif	// CPU Architecture

#endif	// CLang & GCC
