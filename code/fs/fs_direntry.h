// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a directory element
//
// *****************************************************************************************

#ifndef OSAPI_FS_DIRENTRY_H_
#define OSAPI_FS_DIRENTRY_H_

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


/// @brief Copy a directory entry information
/// @param [in] source  - Source directory entry
/// @param [out] target	- Destination directory entry
/// @return SUCCESS if copied. An error condition otherwise.
t_status fs_direntry_copy	( const t_dir_entry * source, t_dir_entry * target );

/// @brief Retrieve a directory entry from a t_list
/// @param [in] list	- A "t_list"
/// @param [in] member	- The list member to retrieve
/// @param [out] entry	- The directory entry
/// @return Operation status.
t_status fs_direntry_get	( const t_list * list, t_size member, t_dir_entry * entry );

/// @brief Get the name of a directory entry
/// @param [in]  entry	  - Directory entry information
/// @param [in]  nameSize - Size of storage for the file system name
/// @param [out] name	  - Name of file system element
/// @return Operation status.
t_status fs_direntry_getName 	( const t_dir_entry * entry, t_size nameSize, t_char * name );

/// @brief Get the type of a directory entry
/// @param [in]  entry	- Directory entry
/// @param [out] type	- The type of element for the specified entry
/// @return Operation status.
t_status fs_direntry_getType	( t_dir_entry * entry, t_fs_eType * type );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_DIRENTRY_H_ */
