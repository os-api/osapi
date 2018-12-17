// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module entry point implementation file
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "string/string.h"
#include "error/modules/error_string.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status string_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}

