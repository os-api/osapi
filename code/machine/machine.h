// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Hardware Module API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_H_
#define OSAPI_MACHINE_H_

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
#include "machine/machine_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup MACHINE
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Machine module API
//
// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status	machine_module_supported	( void					);

// Host name related calls

/// @brief Obtain the machine hostname
/// @param in Size of C-String
/// @param out Hostname
/// @return Operation status
t_status	machine_host_getName		( t_size maxlen, t_char * hostname	);

/// @brief Set the machine hostname
/// @param in New hostname
/// @return Operation status
t_status	machine_host_setName		( t_char * hostname			);

// Domain name related calls

/// @brief Get the machine domain name
/// @param in Size of C-String
/// @param in Domain name
/// @return Operation status
t_status	machine_domain_getName		( t_size maxlen, t_char * hostname	);

/// @brief Set the machine domain name
/// @param in New domain name
/// @return Operation status
t_status	machine_domain_setName		( t_char * hostname			);

// HW related
/*
// Get total available RAM
t_status	machine_memory_getTotal
// Get total physical CPUs / Sockets
t_status	machine_cpu_getTotal
// Get total Ethernet Ports
t_status	machine_mports_getTotal		( t_size * mports );
// Get total physical disks
t_status	machine_disks_getTotal
*/

// IP related

/// @brief Obtain the number of IPs for the given protocol
/// @param in IP protocol (IPv4/6 or all)
/// @param out Number of machine IPs
/// @return Operation status
t_status	machine_ip_getNumber		( t_protocol selector, t_size * number			);

/// @brief Retrieves a list containing the machine IPs
/// @param in IP protocol (IPv4/6 or all)
/// @param in Size of the IP List
/// @param out IP list
/// @return Operation status
t_status	machine_ip_getList		( t_protocol selector, t_size number, t_ip * list	);





#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_MACHINE_H_ */
