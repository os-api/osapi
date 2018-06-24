// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status module declarations
//
// *****************************************************************************************

#ifndef STATUS_TYPES_H_
#define STATUS_TYPES_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

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


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


typedef int			t_status_error;
typedef Byte			t_status_mod;
typedef Byte			t_status_type;
typedef const char *		t_status_funcname;

// Definition of opaque status type

struct s_status
{
  t_status_error	code;
  t_status_mod		module;
  t_status_type		type;
  t_status_funcname	funcname;
};

typedef struct s_status		t_status;



#endif /* STATUS_TYPES_H_ */
