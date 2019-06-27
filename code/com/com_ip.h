// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Com(munication) module API
//
// *****************************************************************************************

#ifndef OSAPI_COM_IP_H_
#define OSAPI_COM_IP_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Common headers
#include "common/types/common_types_if.h"
#include "common/types/common_types_ip.h"

// Own declarations
// #include "net/net_types.h"
// #include "net/net_platform.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The IP section of the communication module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Obtain the required size to store a C-String for the given IP protocol
/// @param [in] prot - IP protocol (IPv4/6)
/// @param [out] size - Required size
/// @return Operation status
t_status com_ip_getStringSize( t_protocol prot, t_size * size );

/// @brief Get the source IP
/// @param [in] ip - The IP to verify
/// @param [in] size - The size of the C-String
/// @param [out] string - The source IP
/// @return Operation status
t_status com_ip_getHost( t_ip * ip, t_size size, char * string );

/// @brief Get the mask associated with the IP
/// @param [in] ip - The IP to verify
/// @param [in] size - The size of the C-String
/// @param [out] string - The IP mask
/// @return Operation status
t_status com_ip_getMask( t_ip * ip, t_size size, char * string );

/// @brief Obtain the C-String for the target protocol: Broadcast, Point to Point,
/// @param [in] ip - The IP to verify
/// @param [in] size - The size of the C-String
/// @param [out] string - The IP string
/// @return Operation status
t_status com_ip_getTarget( t_ip * ip, t_size size, char * string );	// Broadcast or P2P

/// @brief Verify if the IP is Version 4
/// @param [in] ip - The IP to verify
/// @param [out] result - True/False
/// @return Operation status
t_status com_ip_isV4( t_ip * ip, bool * result );

/// @brief Verify if the IP is Version 6
/// @param [in] ip - The IP to verify
/// @param [out] result - True/False
/// @return Operation status
t_status com_ip_isV6( t_ip * ip, bool * result );

/// @brief Verify if the IP is of type broadcast
/// @param [in] ip - The IP to verify
/// @param [out] result - True/False
/// @return Operation status
t_status com_ip_isBroadcast( t_ip * ip, bool * result );

/// @brief Verify if the IP is of type Point to Point
/// @param [in] ip - The IP to verify
/// @param [out] result - True/False
/// @return Operation status
t_status com_ip_isP2P( t_ip * ip, bool * result	);


/// @brief Create a TCP type based on IP and logical Port
/// @param [in] ipString - A source or target IP in string format
/// @param [out] ip - The decoded (from string) IP
/// @return Operation status
t_status com_ip_create( char * ipString, t_ip * ip );

/// @brief Destroy the resources associated with a IP type
/// @param [in] ip - IP type address
/// @return Operation status
t_status com_ip_destroy( t_ip * ip );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_IP_H_ */
