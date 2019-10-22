// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API
//
// *****************************************************************************************

#ifndef OSAPI_FS_H_
#define OSAPI_FS_H_

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

// Import own API headers
#include "fs/fs_element.h"
#include "fs/fs_elementInfo.h"
#include "fs/fs_file.h"
#include "fs/fs_direntry.h"
#include "fs/fs_dir.h"
#include "fs/fs_link.h"

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


/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status fs_module_supported	( void );

/// @brief Get an absolute path from a given path name
/// @param [in]  source  	- Input path
/// @param [in]  tsize		- Size of the target buffer
/// @param [out] target		- Output path
/// @return SUCCESS or FAILURE
t_status fs_path_getAbsolute( const t_char * source, t_size tsize, t_char * target );

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_H_ */
