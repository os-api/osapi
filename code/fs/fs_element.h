// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a FS element
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENT_H_
#define OSAPI_FS_ELEMENT_H_

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
#include "fs/fs_types.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup FS
/// @brief The file system module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Does such element exists in the path
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_exists	( const char * path );

/// @brief Does such element exists in the path
/// @param [in] path - Path name to the file system element
/// @param [out] info - Structure containing the file system element information
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getInfo	( const char * path, t_fs_elementInfo * info );

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENT_H_ */
