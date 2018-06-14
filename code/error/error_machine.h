// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_MACHINE_H_
#define CODE_ERR_ERROR_MACHINE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_machine_X(a, b, c) a b,
enum machine_X {
	  #include "error/table_machine.h"
};
#undef error_machine_X


#endif /* CODE_ERR_ERROR_MACHINE_H_ */
