// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide machine devices related API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_DEVICE_H_
#define OSAPI_MACHINE_DEVICE_H_

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
#include "common/common_list.h"

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


/// @brief Obtain the number of machine devices
/// @param [out] number - The count of devices reported by the OS
/// @return Operation status
t_status machine_device_getNumber( t_size * number );

/// @brief Get a list of machine devices
/// @param [out] devList - Device List
/// @return Operation status
t_status machine_device_getList( t_list * devList );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif // OSAPI_MACHINE_DEVICE_H_
