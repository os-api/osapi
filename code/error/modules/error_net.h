// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Net Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_NET_H_
#define OSAPI_ERROR_NET_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_net_X(a, b, c) a b,
enum net_X {
	  #include "error/mappings/table_net.h"
};
#undef error_net_X


#endif /* OSAPI_ERROR_NET_H_ */