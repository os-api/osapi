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


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

typedef int			t_status_type;
typedef const char *		t_status_string;
typedef const char *		t_status_funcname;

// Definition of opaque status type

struct s_status
{
  t_status_type		type;
  union
  {
    t_error		code;		// The status can provided by an error code or
    t_status_string	string;		// it can be provided through a string directly
  };
  t_module		module;
  t_status_funcname	funcname;
};

typedef struct s_status		t_status;


#endif /* OSAPI_STATUS_TYPES_H_ */
