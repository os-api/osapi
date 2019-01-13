// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status module declarations
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_TYPES_H_
#define OSAPI_STATUS_TYPES_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <stdint.h>

// OSAPI headers
#include "general/general_types.h"
#include "error/error_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STATUS
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

/// @brief Library identifier type (OSAPI, libc, etc.)
typedef int			t_status_type;

/// @brief Error string type
typedef const char *		t_status_string;

/// @brief Function name type
typedef const char *		t_status_funcname;

/// Definition of opaque status type
struct s_status
{
  /// For which library is the status available
  t_status_type		type;
  union
  {
    /// The status can provided by an error code
    t_error		code;
    /// The error can also be provided through a string directly
    t_status_string	string;
  };
  /// Module that provides the status
  t_module		module;
  /// Function name that provides the status
  t_status_funcname	funcname;
};

/// @brief The status type
typedef struct s_status		t_status;

///@}
///@}


#endif /* OSAPI_STATUS_TYPES_H_ */
