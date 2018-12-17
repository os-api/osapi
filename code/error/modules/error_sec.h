// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_SEC_H_
#define CODE_ERR_ERROR_SEC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_sec_X(a, b, c) a b,
enum sec_X {
	  #include <error/mappings/table_sec.h>
};
#undef error_sec_X


#endif /* CODE_ERR_ERROR_SEC_H_ */
