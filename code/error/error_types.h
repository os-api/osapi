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
// Section: Constants
//
// *****************************************************************************************

#define	ERROR_BASE		1
#define ERROR_MAX		INT_MAX

// Define Generic Error strings
#define OSAPI_ERROR_GENERIC	"Generic Error"
#define OSAPI_ERROR_SUPPORT	"Unsupported function"
#define OSAPI_ERROR_INVPARAM	"Invalid Parameter(s)"
#define OSAPI_ERROR_UNKNOWN	"Unknown error"


#endif /* CODE_ERR_ERROR_DEF_H_ */