// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Parallel module API
//
// *****************************************************************************************

#ifndef OSAPI_PARALLEL_H_
#define OSAPI_PARALLEL_H_

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
//#include "common/types/common_type_time.h"

// Own declarations


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PARALLEL
/// @brief The Parallel interface module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status parallel_module_supported( void );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif // OSAPI_PARALLEL_H_
