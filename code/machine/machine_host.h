// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide machine host related API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_HOST_H_
#define OSAPI_MACHINE_HOST_H_

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


/// @brief Obtain the machine hostname
/// @param [in] maxlen - The size of C-String
/// @param [out] hostname - The name of the machine
/// @return Operation status
t_status machine_host_getName( t_size maxlen, t_char * hostname	);

/// @brief Set the machine hostname
/// @param [in] hostname - New hostname
/// @return Operation status
t_status machine_host_setName( t_char * hostname );




#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_MACHINE_HOST_H_ */
