// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a CPU information
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPE_CPU_H_
#define OSAPI_COMMON_TYPE_CPU_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>

// Import OSAPI headers

// Include own headers


// *****************************************************************************************
//
// Section: Constants
//
// *****************************************************************************************

// Define the size of main CPU types
#define	OSAPI_MACHINE_CPU_SIZE_VENDORID		20 //?
#define OSAPI_MACHINE_CPU_SIZE_FAMILY		2
#define OSAPI_MACHINE_CPU_SIZE_MODEL		2
#define OSAPI_MACHINE_CPU_SIZE_MODELNAME	65 // ?
#define OSAPI_MACHINE_CPU_SIZE_REVISION		10		// AKA Stepping
#define OSAPI_MACHINE_CPU_SIZE_VIRTUAL		10 // ?

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Number of threads per CPU
typedef uint8_t		t_cpu_nthreads;

/// Number of cores per CPU
typedef uint16_t	t_cpu_ncores;

/// Number of logical CPUs in the system
typedef uint32_t	t_cpu_nlogical;

/// Number of cores per CPU
typedef uint16_t	t_cpu_nsocket;


// All CPU architectures must define the t_cpu_regs structure/type
#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)

/// General purpose registers for INTEL/AMD architectures
struct osapi_cpu_regs_S
{
  uint32_t	eax;		///< EAX register
  uint32_t	ebx;		///< EBX register
  uint32_t	ecx;		///< ECX register
  uint32_t	edx;		///< EDX register
};

/// The generic CPU register
typedef struct osapi_cpu_regs_S		t_cpu_regs;

#else
  #error "Unknown CPU architecture"
#endif


#endif /* OSAPI_COMMON_TYPE_CPU_H_ */
