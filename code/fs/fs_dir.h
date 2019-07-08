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


/// @brief Open a directory
/// @param [in] path    - Directory name
/// @param [out] dir 	- New directory descriptor
/// @return SUCCESS if directory descriptor opened. An error condition otherwise.
t_status fs_dir_open			( const t_char * path, t_dir * dir );

/// @brief Close a directory
/// @param [in] dir 	- Directory descriptor
/// @return SUCCESS if directory descriptor closed. An error condition otherwise.
t_status fs_dir_close( t_dir * dir );

/// @brief Create a new directory
/// @param [in] path    - Directory name
/// @param [in] mode	- Directory creation options
/// @return SUCCESS if created. An error condition otherwise (e.g. An element already exists with that name).
t_status fs_directory_create		( const char * path, const char * mode );

/// @brief Remove a directory by file descriptor
/// @param [in] dir	- Directory descriptor
/// @return SUCCESS if directory removed. An error condition otherwise.
// t_status fs_directory_remove 		( t_dir * dir );


/// @brief Obtain a directory descriptor
/// @param [in] path    - Directory name
/// @param [out] dir	- Directory descriptor
/// @return SUCCESS if created. An error condition otherwise (e.g. An element already exists with that name).
t_status fs_directory_getInfo		( const char * path, t_dir * dir );

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

/// @brief Get the number of directory elements
/// @param [in] dir		- Directory descriptor
/// @param [in] number		- Number of directory entries for which space was allocated
/// @param [out] listSize	- Number of directory entries retrieved
/// @param [out] dirList	- The retrieved directory list
/// @return Operation status.
t_status fs_directory_getElementList 	( t_dir * dir, t_size number, t_size * listSize, t_dir_entry * dirList );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_DIR_H_ */
