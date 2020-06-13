// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_SEC_H_
#define OSAPI_ERROR_SEC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_sec_X(a, b, c) a b,
enum osapi_error_sec_E {
	  #include "error/mappings/table_sec.h"
};
#undef osapi_error_sec_X


#endif /* OSAPI_ERROR_SEC_H_ */
