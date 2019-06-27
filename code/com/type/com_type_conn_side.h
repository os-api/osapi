// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Connection side type declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_TYPE_CONN_SIDE_H_
#define OSAPI_COM_TYPE_CONN_SIDE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers


// General OSAPI headers
#include <common/common_types.h>
#include "general/general_protocol.h"
#include "com/type/com_type_endpoint.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

// Point to Point connection topology
struct s_conn_side_p2p
{
  t_endpoint	ep;
};

// Placeholder structure for now (dummy)
struct s_conn_side_mp
{
  t_endpoint	ep[2];
};


struct s_connection_side
{
  union u_side
  {
    struct s_conn_side_p2p	p2p;
    struct s_conn_side_mp	mp;
    /*
    struct s_conn_side_broadcast;
    struct s_conn_side_unicast;
    */
  } side;
};

typedef struct s_connection_side t_connection_side;

#endif /* OSAPI_COM_TYPE_CONN_SIDE_H_ */
