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
static const char * error_none [] =
{
  "Success",
  NULL
};

/// Auxiliary structure that helps in the definition of the maximum error code in each module
struct s_osapi_errors
{
  t_error 		topValue;	///< The maximum error value in a module
  const char ** 	name;		///< The error string that corresponds to the maximum error value
};

static const struct s_osapi_errors osapi_error_strings[ OSAPI_MODULE_MAX ] = {
	    { 1,			error_none 	},
	    { osapi_common_e_max, 	common_errors  	},
	    { e_string_max, 		string_errors  	},
	    { e_os_max, 		os_errors	},
	    { e_machine_max, 		machine_errors 	},
	    { e_proc_max, 		proc_errors	},
	    { e_clock_max,		clock_errors	},
	    { e_sec_max,		sec_errors	},
	    { e_io_max,			io_errors	},
	    { e_util_max,		util_errors	},
	    { osapi_fs_e_max,		fs_errors	},
	    { e_com_max,		com_errors	},
};



///@}
///@}

#endif /* OSAPI_ERROR_PRIV_H_ */
