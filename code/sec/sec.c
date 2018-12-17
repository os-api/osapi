// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Security Module entry point implementation file
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include baseline before system headers
#include "general/general_baseline.h"

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Import common
#include "common/common.h"

// Own declarations
#include "sec/sec.h"
#include "error/modules/error_sec.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status sec_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports clocks
}


