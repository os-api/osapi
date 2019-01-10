// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Net(work) module API
//
// *****************************************************************************************

#ifndef OSAPI_NET_H_
#define OSAPI_NET_H_

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

// Own declarations
// #include "net/net_types.h"
// #include "net/net_platform.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup NET
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Net module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status net_module_supported		( void						);

// IP related facility

/// @brief Obtain the required size to store a C-String for the given IP protocol
/// @param in IP protocol (IPv4/6)
/// @param out Required size
/// @return Operation status
t_status net_ip_getStringSize		( t_protocol prot, t_size * p_size		);

/// @brief Get the source IP
/// @param in IP type
/// @param in size of the C-String
/// @param out Source IP
/// @return Operation status
t_status net_ip_getHost			( t_ip * p_ip, t_size size, char * p_string	);

/// @brief Get the mask associated with the IP
/// @param in IP
/// @param in size of the C-String
/// @param out IP mask
/// @return Operation status
t_status net_ip_getMask			( t_ip * p_ip, t_size size, char * p_string	);

/// @brief Obtain the C-String for the target protocol: Broadcast, Point to Point,
/// @param in IP type
/// @param in Size of the C-String
/// @param out IP string
/// @return Operation status
t_status net_ip_getTarget		( t_ip * p_ip, t_size size, char * p_string	);	// Broadcast or P2P

/// @brief Verify if the IP is Version 4
/// @param in IP type
/// @param out True/False
/// @return Operation status
t_status net_ip_isV4			( t_ip * p_ip, bool * p_result			);

/// @brief Verify if the IP is Version 6
/// @param in IP type
/// @param out True/False
/// @return Operation status
t_status net_ip_isV6			( t_ip * p_ip, bool * p_result			);

/// @brief Verify if the IP is of type broadcast
/// @param in IP type
/// @param out True/False
/// @return Operation status
t_status net_ip_isBroadcast		( t_ip * p_ip, bool * p_result			);

/// @brief Verify if the IP is of type Point to Point
/// @param in IP type
/// @param out True/False
/// @return Operation status
t_status net_ip_isP2P			( t_ip * p_ip, bool * p_result			);

// Port related facility



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_NET_H_ */
