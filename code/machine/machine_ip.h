// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide nachine IP API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_IP_H_
#define OSAPI_MACHINE_IP_H_

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
/// @brief The machine management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Machine module API
//
// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface


/// @brief Obtain the number of IPs for the given protocol
/// @param [in] selector - The IP protocol (IPv4/6 or all)
/// @param [out] number - Number of machine IPs matching the selector
/// @return Operation status
t_status machine_ip_getNumber( t_protocol selector, t_size * number );

/// @brief Retrieves a list containing the machine IPs
/// @param [in] selector - The IP protocol (IPv4/6 or all)
/// @param [in] number - The maximum size of the IP List
/// @param [out] list - The machine IPs
/// @return Operation status
t_status machine_ip_getList( t_protocol selector, t_size number, t_ip * list );





#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_MACHINE_IP_H_ */
