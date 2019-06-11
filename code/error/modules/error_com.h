// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Com Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_COM_H_
#define OSAPI_ERROR_COM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_com_X(a, b, c) a b,
enum com_X {
	  #include <error/mappings/table_com.h>
};
#undef error_com_X


#endif /* OSAPI_ERROR_COM_H_ */
