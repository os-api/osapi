// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Com module generic implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_com.h"
#include "status/status.h"


// Import own headers
#include "com/com.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status com_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}


