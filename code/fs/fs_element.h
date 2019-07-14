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
#include "fs/type/fs_type_element.h"

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


/// @brief Open a file system element descriptor
/// @param [in]  path 		- Path name to the file system element
/// @param [out] element 	- File element descriptor
/// @return Operation status
t_status fs_element_open	( const char * path, t_element * element );

/// @brief Close a file system element descriptor
/// @param [out] element - File element descriptor
/// @return Operation status
t_status fs_element_close	( t_element * element );

/// @brief Eliminate a an element from the file system
/// @param [in] path     - Path name to element
/// @return SUCCESS if removed. An error condition otherwise.
t_status fs_element_remove	( const char * path );

/// @brief Does such element exists in the path
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_exists	( const char * path );

/// @brief Change the user owning the element
/// @param [in] path	- Pathname to element
/// @param [in] uid	- New User ID
/// @return Operation status.
t_status fs_element_setUID 	( const char * path, t_uid uid );

/// @brief Change the group owning the element
/// @param [in] path	- Pathname to element
/// @param [in] gid	- New Group ID
/// @return Operation status.
t_status fs_element_setGID 	( const char * path, t_gid gid );

/// @brief Change the permissions of the the element
/// @param [in] path	- Pathname to element
/// @param [in] perm	- New set of element permissions
/// @return Operation status.
t_status fs_element_setPermissions ( const char * path, t_fs_perm * perm );

/// @brief Update the generic information about a file system element
/// @param [in,out] element - Structure containing the file system element information
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_updateInfo	( t_element * element );

/// @brief Get type of element
/// @param [in] element - File system element information
/// @param [out] type - Type of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getType	( t_element * element, int * type		);

/// @brief Obtain the full pathname to element
/// The returned name pointer is only valid as long as info is available
/// @param [in] element - Structure containing the file system element information
/// @param [out] name - The element name
/// @return Operation status.
t_status fs_element_getName 	( t_element * element, char ** name );

/// @brief Obtain the user ID owning the element
/// @param [in] element - Structure containing the file system element information
/// @param [out] uid  - Current User ID of file system element
/// @return Operation status.
t_status fs_element_getUID 	( t_element * element, t_uid * uid );

/// @brief Obtain the group ID owning the element
/// @param [in] element - Structure containing the file system element information
/// @param [out] gid  - Current User ID of filesystem element
/// @return Operation status.
t_status fs_element_getGID 	( t_element * element, t_gid * gid );


/// @brief Get element access time
/// @param [in] element - File system element information
/// @param [out] atime - Last element access time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getAtime	( t_element * element, t_time * atime 	);

/// @brief Get element creation time
/// @param [in] info - File system element information
/// @param [out] ctime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getCtime	( t_element * info, t_time * ctime 	);

/// @brief Get element modification time
/// @param [in] element - File system element information
/// @param [out] mtime - Last element modification time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getMtime	( t_element * element, t_time * mtime 	);

/// @brief Get size of element in the file system
/// @param [in] element - File system element information
/// @param [out] size - Size of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getSize	( t_element * element, t_size * size	);

/// @brief Obtain the permissions of the element
/// @param [in]  element - Structure containing the file system element information
/// @param [out] perm - Current permissions of element
/// @return Operation status.
t_status fs_element_getPermissions ( t_element * element, t_fs_perm * perm );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENT_H_ */
