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

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_hw.h"
#include "status/status.h"

// Own declarations
#include "hw/hw.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status hw_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports HW related functions
}
