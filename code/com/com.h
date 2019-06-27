// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Com(munication) module API
//
// *****************************************************************************************

#ifndef OSAPI_COM_H_
#define OSAPI_COM_H_

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
#include "com/com_ip.h"
#include "com/com_ipc.h"
// #include "com/com_connection.h"	// Under work !

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The networking module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status com_module_supported( void );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_H_ */
