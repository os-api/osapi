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
t_status fs_element_open		( const char * path, t_element * element );

/// @brief Close a file system element descriptor
/// @param [out] element - File element descriptor
/// @return Operation status
t_status fs_element_close		( t_element * element );

/// @brief Eliminate a an element from the file system
/// @param [in] path     - Path name to element
/// @return SUCCESS if removed. An error condition otherwise.
t_status fs_element_remove		( const char * path );

// @brief Special element copy operation
// It enables full control of the copy operation by allowing to specify:
// overwrite - Should the target element be overwritten
// bsize - Copy block size in bytes
// perm - destination element permissions
// ownership - The destination file ownership (UID and GID)
// @param [in] source     - Copy from
// @param [in] target     - Copy into
// @param [in] options	   - Copy control options
// @return SUCCESS if copied. An error condition otherwise.
//t_status fs_element_scopy	( const t_char * source, const t_char * target, const char ** options );

/// @brief Extended element copy operation
/// If the destination already exists, it will be overwritten if the respective parameter is set to true.
/// @param [in] source     - Copy from
/// @param [in] target     - Copy into
/// @param [in] overwrite  - Overwrite target?
/// @return SUCCESS if copied. An error condition otherwise.
t_status fs_element_copy	( const t_char * source, const t_char * target, bool overwrite );

/// @brief Move an element
/// If the destination already exists, it will overwrite it
/// @param [in] source     - Move from
/// @param [in] target     - Move into
/// @return SUCCESS if moved. An error condition otherwise.
t_status fs_element_move	( const t_char * source, const t_char * target );

/// @brief Test if two file system paths are the same element
/// @param [in]  path1    - Path name of element 1
/// @param [in]  path2    - Path name of element 2
/// @param [out] result   - The comparison result
/// @return Operation status.
t_status fs_element_same	( const t_char * path1, const t_char * path2, bool * result );

/// @brief Does such element exists in the path
/// @param [in]   path    - Path name of element
/// @param [out]  exists  - Result of element search
/// @return Operation status.
t_status fs_element_exists	( const char * path, bool * exists );

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

/// @brief Get type of element through a path name
/// @param [in]  path - Pathname from which to retrieve the information
/// @param [out] type - Type of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getType	( const t_char * path, t_fs_eType * type );

/// @brief Obtain the full pathname to element
/// The returned name pointer is only valid as long as info is available
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] name - The element name
/// @return Operation status.
t_status fs_element_getName 	( const char * path, char ** name );

/// @brief Obtain the element unique identifier on the file system
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] id  	- Current ID of the file system element
/// @return Operation status.
t_status fs_element_getID 	( const char * path, t_fs_eid * id );


/// @brief Obtain the user ID owning the element
/// @param [in] path - Pathname from which to retrieve the user ID
/// @param [out] uid  - Current User ID of file system element
/// @return Operation status.
t_status fs_element_getUID 	( const char * path, t_uid * uid );

/// @brief Obtain the group ID owning the element
/// @param [in] path - Pathname from which to retrieve the group ID
/// @param [out] gid  - Current User ID of filesystem element
/// @return Operation status.
t_status fs_element_getGID 	( const char * path, t_gid * gid );


/// @brief Get element access time
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] atime  - Last element access time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getAccessTime	( const char * path, t_time * atime 	);

/// @brief Get element creation/birth time
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] btime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getCreationTime	( const char * path, t_time * btime 	);

/// @brief Get element change time
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] ctime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getChangetime	( const char * path, t_time * ctime 	);

/// @brief Get element modification time
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] mtime - Last element modification time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getModificationTime	( const char * path, t_time * mtime 	);

/// @brief Get size of element in the file system
/// @param [in] path - Pathname from which to retrieve the information
/// @param [out] size - Size of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_element_getSize	( const char * path, t_size * size	);

/// @brief Obtain the permissions of the element
/// @param [in]  path - Pathname from which to retrieve the information
/// @param [out] perm - Current permissions of element
/// @return Operation status.
t_status fs_element_getPermissions ( const char * path, t_fs_perm * perm );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENT_H_ */
