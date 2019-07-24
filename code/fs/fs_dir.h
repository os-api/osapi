// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a directory element
//
// *****************************************************************************************

#ifndef OSAPI_FS_DIR_H_
#define OSAPI_FS_DIR_H_

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
#include "fs/type/fs_type_dir.h"

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


/// @brief Open a directory
/// @param [in] path    - Directory name
/// @param [out] dir 	- New directory descriptor
/// @return SUCCESS if directory descriptor opened. An error condition otherwise.
t_status fs_directory_open			( const t_char * path, t_dir * dir );

/// @brief Close a directory
/// @param [in] dir 	- Directory descriptor
/// @return SUCCESS if directory descriptor closed. An error condition otherwise.
t_status fs_directory_close( t_dir * dir );

/// @brief Create a new directory
/// @param [in] path    - Directory name
/// @param [in] mode	- Directory creation options
/// @return SUCCESS if created. An error condition otherwise (e.g. An element already exists with that name).
t_status fs_directory_create		( const t_char * path, const char ** mode );

/*
/// @brief Copy an entire directory onto another
/// @param [in] source  - Source directory name
/// @param [in] target	- Destination directory name
/// @return SUCCESS if copied. An error condition otherwise.
t_status fs_directory_copy		( const t_char * source, const t_char * target );
*/

/// @brief Obtain a directory descriptor
/// @param [out] dir	- Directory descriptor
/// @return SUCCESS if created. An error condition otherwise (e.g. An element already exists with that name).
t_status fs_directory_updateInfo		( t_dir * dir );

/// @brief Obtain an element descriptor from a directory descriptor
/// @param [in] dir	- Directory descriptor
/// @param [out] elem	- Element descriptor
/// @return Operation status.
t_status fs_directory_getElement	( t_dir * dir, t_element * elem );

/// @brief Get the number of directory elements
/// @param [in]  dir	- Directory descriptor
/// @param [out] number	- Number of directory elements
/// @return Operation status.
t_status fs_directory_getNumberElements ( t_dir * dir, t_size * number );

/// @brief Get the list of directory elements
/// @param [in]  dir		- Directory descriptor
/// @param [out] dirList	- The retrieved directory list
/// @return Operation status.
t_status fs_directory_getElementList 	( t_dir * dir, t_list * dirList );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_DIR_H_ */
