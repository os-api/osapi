// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Net Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_NET_H_
#define CODE_ERR_ERROR_NET_H_

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
	  #include "error/table_net.h"
};
#undef error_net_X


#endif /* CODE_ERR_ERROR_NET_H_ */
