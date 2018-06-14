// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_OS_H_
#define CODE_ERR_ERROR_OS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_os_X(a, b, c) a b,
enum os_X {
	  #include "error/table_os.h"
};
#undef error_os_X


#endif /* CODE_ERR_ERROR_OS_H_ */
