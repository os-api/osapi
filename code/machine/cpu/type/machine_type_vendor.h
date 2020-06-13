// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for CPU Vendors and respective CPU signatures
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_VENDOR_H_
#define OSAPI_MACHINE_CPU_TYPE_VENDOR_H_


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

#define osapi_machine_cpu_vendors_X(a, b, c) a b,

enum osapi_machine_cpu_vendor_E {
  #include "machine/cpu/mappings/table_vendors.h"
};

#undef osapi_machine_cpu_vendors_X


typedef	enum osapi_machine_cpu_vendor_E		t_cpu_vendor_id;



#define osapi_machine_cpu_signature_X(a, b, c) a b,

enum osapi_machine_cpu_signature_E {
  #include "machine/cpu/mappings/table_cpu_signatures.h"
};

#undef osapi_machine_cpu_signature_X


typedef	enum osapi_machine_cpu_signature_E	t_cpu_signature;


#endif /* OSAPI_MACHINE_CPU_TYPE_VENDOR_H_ */
