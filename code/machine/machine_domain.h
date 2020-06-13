// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide machine domain API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_DOMAIN_H_
#define OSAPI_MACHINE_DOMAIN_H_

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

/// @brief Get the machine domain name
/// @param [in] maxlen - The size of C-String
/// @param [out] domainname - The name of the machine domain
/// @return Operation status
t_status machine_domain_getName( t_size maxlen, t_char * domainname );

/// @brief Set the machine domain name
/// @param [in] domainname - New domain name
/// @return Operation status
t_status machine_domain_setName( t_char * domainname );




#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_MACHINE_DOMAIN_H_ */
