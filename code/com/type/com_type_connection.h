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

/// Define a generic connection (between endpoints)
struct osapi_connection_S
{
  t_protocol		protocol;	///< Connection protocol
  int			topology;	///< Connection topology (1 to 1, for example)
  t_connection_side	A;		///< A - connection side
  t_connection_side	Z;		///< Z - connection side
};

/// The connection type
typedef struct osapi_connection_S	t_connection;




#endif /* OSAPI_COM_TYPE_CONNECTION_H_ */
