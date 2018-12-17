// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW module entry point implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers <here>

// Generic OSAPI includes

#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "machine/machine.h"
#include "error/modules/error_machine.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status machine_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports HW related functions
}
