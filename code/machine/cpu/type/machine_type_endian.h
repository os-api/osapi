// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for CPU endianess
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_ENDIAN_H_
#define OSAPI_MACHINE_CPU_TYPE_ENDIAN_H_


// *****************************************************************************************
//
// Section: Define CPU endianess possible values
//
// *****************************************************************************************

#define OSAPI_ENDIANESS_NONE		0
#define OSAPI_ENDIANESS_LITTLE		1
#define OSAPI_ENDIANESS_BIG		2
#define	OSAPI_ENDIANESS_BI		3


// *****************************************************************************************
//
// Section: Import machine enums
//
// *****************************************************************************************

#define osapi_machine_endianess_X(a, b, c) a b,

enum osapi_machine_endianess_E {
  #include "machine/cpu/mappings/table_endianess.h"
};

#undef osapi_machine_endianess_X


typedef	enum osapi_machine_endianess_E	t_cpu_endian;



#endif /* OSAPI_MACHINE_CPU_TYPE_ENDIAN_H_ */
