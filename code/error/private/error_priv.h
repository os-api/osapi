// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_H_
#define OSAPI_ERROR_PRIV_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <stddef.h>

// OSAPI module error information
#include "general/general_types.h"
#include "general/general_modules.h"

// Error information
#include "error/error_types.h"
#include "error/private/error_priv_common.h"
#include "error/private/error_priv_clock.h"
#include "error/private/error_priv_io.h"
#include "error/private/error_priv_fs.h"
#include "error/private/error_priv_machine.h"
#include "error/private/error_priv_os.h"
#include "error/private/error_priv_proc.h"
#include "error/private/error_priv_sec.h"
#include "error/private/error_priv_string.h"
#include "error/private/error_priv_util.h"
#include "error/private/error_priv_com.h"
#include "error/private/error_priv_log.h"
#include "error/private/error_priv_parallel.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup ERROR
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Error Definitions
//
// *****************************************************************************************

// Generic error definitions

/// Auxiliary structure for a successful status
static const char * osapi_error_none [] =
{
  "Success",
  NULL
};

/// Auxiliary structure that helps in the definition of the maximum error code in each module
struct osapi_error_S
{
  t_error 		topValue;	///< The maximum error value in a module
  const char ** 	name;		///< The error string that corresponds to the maximum error value
};

// The following structure must match exactly the modules defined in general/mappings/table_modules.h
static const struct osapi_error_S osapi_error_strings[ OSAPI_MODULE_MAX ] = {
	    { 1,							osapi_error_none		},
	    { osapi_common_error_max, 		osapi_common_errors  	},
	    { osapi_string_error_max,		osapi_string_errors  	},
	    { osapi_os_error_max,			osapi_os_errors			},
	    { osapi_machine_error_max, 		osapi_machine_errors 	},
	    { osapi_proc_error_max, 		osapi_proc_errors		},
	    { osapi_clock_error_max,		osapi_clock_errors		},
	    { osapi_sec_error_max,			osapi_sec_errors		},
	    { osapi_io_error_max,			osapi_io_errors			},
	    { osapi_log_error_max,			osapi_log_errors		},
	    { osapi_fs_error_max,			osapi_fs_errors			},
	    { osapi_com_error_max,			osapi_com_errors		},
	    { osapi_util_error_max,			osapi_util_errors		},
		{ osapi_parallel_error_max,		osapi_parallel_errors	},
};



///@}
///@}

#endif /* OSAPI_ERROR_PRIV_H_ */
