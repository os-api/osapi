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
#include <common/common_types.h>

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

/// @brief Get the number of shared libraries loaded in the process
/// @param [out] maxlibs - Number of currently loaded libraries
/// @return Operation status
t_status proc_library_getNumberOfLoaded( t_size * maxlibs );

/// @brief Get a list of name and version information for each process loaded/shared library
/// @param [in] maxlibs - Maximum size of the return arrays, i.e. name and version
/// @param [out] info - Array with name and version of loaded libraries
/// @return Operation status
t_status proc_library_getAllLoaded( t_size maxlibs, t_libinfo (*info)[] );


/// @brief Get the Release information of the named library
/// @param [in] name 		- Name of library to search
/// @param [in] max		- Max. size of the output string
/// @param [out] release	- The release version for the named library
/// @return Operation status
t_status proc_library_getRelease( const t_char * name, t_size max, char * release );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_LIBRARY_H_ */
