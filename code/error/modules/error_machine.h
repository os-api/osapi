// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_MACHINE_H_
#define OSAPI_ERROR_MACHINE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_machine_X(a, b, c) a b,
enum osapi_error_machine_E {
	  #include "error/mappings/table_machine.h"
};
#undef osapi_error_machine_X


#endif /* OSAPI_ERROR_MACHINE_H_ */
