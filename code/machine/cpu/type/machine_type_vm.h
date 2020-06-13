// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for a Virtual Machine
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_VM_H_
#define OSAPI_MACHINE_CPU_TYPE_VM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
#include <stdbool.h>
#include <stdint.h>

// General OSAPI headers

// Import own elements
#include "machine/machine_platform.h"


// *****************************************************************************************
//
// Section: Import machine enums
//
// *****************************************************************************************

#define osapi_machine_hypervisor_X(a, b, c, d) a b,

enum osapi_machine_hypervisor_E {
  #include "machine/cpu/mappings/table_hypervisor.h"
};

#undef osapi_machine_hypervisor_X


// *****************************************************************************************
//
// Section: Declarations
//
// *****************************************************************************************

/// Hypervisor description type
struct osapi_machine_hypervisor_s
{
  int			id;			///< Enum for the Vendor
  const char *		vendor;			///< Vendor name
  const char *		signature;		///< Vendor signature
};

typedef	struct osapi_machine_hypervisor_s	t_hypervisor;

/// Virtual Machine description
struct osapi_machine_vm_s
{
  bool			supported;		///< Is virtualization supported
  bool			available;		///< Is SW currently running inside VM
  t_hypervisor		hypervisor;		///< Hypervisor information
};


/// The VM type
typedef	struct osapi_machine_vm_s		t_vm;







#endif /* OSAPI_MACHINE_CPU_TYPE_VM_H_ */
