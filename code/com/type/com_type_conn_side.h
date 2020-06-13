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


// Import OSAPI headers
#include "general/general_protocol.h"
#include "common/common_types.h"

// Import own module headers
#include "com/type/com_type_endpoint.h"



// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Point to Point connection topology
struct conn_side_p2p_S
{
  t_endpoint	ep;			///< The endpoint information for Point to Point connections
};

/// Placeholder structure for now (dummy)
struct conn_side_mp_S
{
  t_endpoint	ep[2];			///< The endpoint information for MultiPoint connections
};


/// Define a connection side type
struct connection_side_S
{
  /// The union of all possible connection sides
  union u_side
  {
    struct conn_side_p2p_S	p2p;	///< Point to Point connection side
    struct conn_side_mp_S	mp;	///< Multi Point connection side
    /*
    struct s_conn_side_broadcast;
    struct s_conn_side_unicast;
    */
  } side;				///< The connection side information
};

/// The connection side type
typedef struct connection_side_S t_connection_side;




#endif /* OSAPI_COM_TYPE_CONN_SIDE_H_ */
