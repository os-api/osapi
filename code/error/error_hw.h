// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_HW_H_
#define CODE_ERR_ERROR_HW_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_hw_X(a, b, c) a b,
enum hw_X {
	  #include "error/table_hw.h"
};
#undef error_hw_X

#endif /* CODE_ERR_ERROR_HW_H_ */
