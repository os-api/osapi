// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a POSIX compliant implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX

// System includes

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"


// *****************************************************************************************
//
// Section: Constant declarations/definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

t_status proc_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports process interface
}









#endif	// End of POSIX compilation
