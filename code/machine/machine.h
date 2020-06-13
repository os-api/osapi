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
#include "machine/machine_ip.h"
#include "machine/machine_host.h"
#include "machine/machine_domain.h"
#include "machine/machine_cpu.h"
#include "machine/machine_virtual.h"

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

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status machine_module_supported( void	);


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_MACHINE_H_ */
