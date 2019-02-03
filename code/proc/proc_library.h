// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API for loading/unloading libraries from a process
//
// *****************************************************************************************

#ifndef OSAPI_PROC_LIBRARY_H_
#define OSAPI_PROC_LIBRARY_H_

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
#include "common/types/common_types.h"

// Own declarations
#include "proc/proc_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
/// @brief The process management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Public Function declarations
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Is the load/unload of libraries supported in the platform?
/// @return SUCCESS / FAILURE
t_status proc_library_supported( void );

/// @brief Load a library into the current process
/// @param [in] path - Path to the library
/// @param [in] options - C-String array with list of system specific options
/// @param [out] lib - library type
/// @return Operation status
t_status proc_library_load( char * path, char * options[], t_library * lib );

/// @brief Unload a library from the current process
/// @param [in] lib - library type
/// @return Operation status
t_status proc_library_unload( t_library lib );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_LIBRARY_H_ */
