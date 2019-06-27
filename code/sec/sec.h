// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Sec(urity) module API
//
// *****************************************************************************************

#ifndef SEC_SEC_H_
#define SEC_SEC_H_

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

// Common includes
#include <common/common_types.h>

// Own declarations
#include "sec/sec_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup SEC
/// @brief The Security module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Sec(urity) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Is the Security module supported in the platform
/// return Operation status
t_status sec_module_supported( void );

#pragma GCC visibility pop			// End of public interface

// Include the submodules that compose the Security module
#include "sec/sec_identity.h"


///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* SEC_SEC_H_ */
