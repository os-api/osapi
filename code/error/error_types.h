// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Generic Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_DEF_H_
#define CODE_ERR_ERROR_DEF_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System includes
#include <limits.h>
#include <errno.h>


// *****************************************************************************************
//
// Section: Constants/Type declarations
//
// *****************************************************************************************

#define	OSAPI_ERROR_BASE		0
#define OSAPI_ERROR_GENERIC		OSAPI_ERROR_BASE + 1
#define OSAPI_ERROR_SUPPORT		OSAPI_ERROR_BASE + 2
#define OSAPI_ERROR_INVPARAM		OSAPI_ERROR_BASE + 3
#define OSAPI_ERROR_UNKNOWN		OSAPI_ERROR_BASE + 4
#define OSAPI_ERROR_MAX			INT_MAX

// Define Generic Error strings
#define OSAPI_ERROR_STRING_NONE		"Success"
#define OSAPI_ERROR_STRING_GENERIC	"Generic Error"
#define OSAPI_ERROR_STRING_SUPPORT	"Unsupported function"
#define OSAPI_ERROR_STRING_INVPARAM	"Invalid Parameter(s)"
#define OSAPI_ERROR_STRING_UNKNOWN	"Unknown error"


// Define own error type (copy the standard error definition for compatibility, usage of enums, etc)
typedef	int				t_error;


#endif /* CODE_ERR_ERROR_DEF_H_ */
