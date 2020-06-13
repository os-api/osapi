// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Virtual Machine API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_VIRTUAL_H_
#define OSAPI_MACHINE_VIRTUAL_H_

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
#include "machine/cpu/type/machine_type_vm.h"


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


/// @brief Is this process running inside a Virtual machine?
/// @param [out] result - True if running in a VM. False otherwise.
/// @return Operation status
t_status machine_virtual_is( bool * result );

/// @brief Obtain information about a virtual machine
/// @param [out] vm - Virtual machine information
/// @return Operation status
t_status machine_virtual_getInfo( t_vm * vm );


/// @brief Obtain information about a virtual machine
/// @param [in]  vm 	- Virtual machine information
/// @param [out] vendor - The VM provider
/// @return Operation status
t_status machine_virtual_getVendor( t_vm * vm, char ** vendor );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif // OSAPI_MACHINE_VIRTUAL_H_
