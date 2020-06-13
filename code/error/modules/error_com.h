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

#define osapi_error_com_X(a, b, c) a b,
enum osapi_error_com_E {
	  #include <error/mappings/table_com.h>
};
#undef osapi_error_com_X


#endif /* OSAPI_ERROR_COM_H_ */
