// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for CPU Architectures
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_ARCH_H_
#define OSAPI_MACHINE_CPU_TYPE_ARCH_H_


// *****************************************************************************************
//
// Section: Define Constants
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Import machine enums
//
// *****************************************************************************************

#define osapi_machine_cpuarch_X(a, b, c, d) a b,

enum osapi_machine_cpuarch_E {
  #include "machine/cpu/mappings/table_cpuarch.h"
};

#undef osapi_machine_cpuarch_X


typedef	enum osapi_machine_cpuarch_E		t_cpu_arch;



#endif /* OSAPI_MACHINE_CPU_TYPE_ARCH_H_ */
