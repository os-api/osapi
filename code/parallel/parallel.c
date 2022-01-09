// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Parallel module entry point implementation file
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
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_parallel.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "parallel/parallel.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status parallel_module_supported( void )
{
  t_status st;

  // RETURN_STATUS_SUCCESS;
  status_iset( OSAPI_MODULE_PARALLEL, __func__, osapi_parallel_error_support, &st );

  return st;
}

