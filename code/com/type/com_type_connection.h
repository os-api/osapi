// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Connection type declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_TYPE_CONNECTION_H_
#define OSAPI_COM_TYPE_CONNECTION_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers

// General OSAPI headers
#include <common/common_types.h>
#include "general/general_protocol.h"
#include "com/type/com_type_conn_side.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


struct s_connection
{
  t_protocol		protocol;
  int			topology;
  t_connection_side	A;
  t_connection_side	Z;
};

typedef struct s_connection t_connection;

#endif /* OSAPI_COM_TYPE_CONNECTION_H_ */
