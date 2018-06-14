// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_STRING_H_
#define CODE_ERR_ERROR_STRING_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_string_X(a, b, c) a b,
enum string_X {
	  #include "error/table_string.h"
};
#undef error_string_X


#endif /* CODE_ERR_ERROR_STRING_H_ */
