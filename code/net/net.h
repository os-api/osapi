// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Net(work) module API
//
// *****************************************************************************************

#ifndef NET_NET_H_
#define NET_NET_H_

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

// *****************************************************************************************
//
// Section: Net module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


// Functions bellow
t_status net_module_supported		( void						);

// IP related facility
t_status net_ip_getStringSize		( t_protocol prot, t_size * p_size		);
t_status net_ip_getHost			( t_ip * p_ip, t_size size, char * p_string	);
t_status net_ip_getMask			( t_ip * p_ip, t_size size, char * p_string	);
t_status net_ip_getTarget		( t_ip * p_ip, t_size size, char * p_string	);	// Broadcast or P2P
t_status net_ip_isV4			( t_ip * p_ip, bool * p_result			);
t_status net_ip_isV6			( t_ip * p_ip, bool * p_result			);
t_status net_ip_isBroadcast		( t_ip * p_ip, bool * p_result			);
t_status net_ip_isP2P			( t_ip * p_ip, bool * p_result			);

// Port related facility



#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* NET_NET_H_ */
