// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for to retrieve information from a FS element
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENTINFO_H_
#define OSAPI_FS_ELEMENTINFO_H_

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


/// @brief Get type of element
/// @param [in] element - File system element information
/// @param [out] type - Type of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getType	( const t_element * element, int * type		);

/// @brief Obtain the element name (basename)
/// The returned name pointer is only valid as long as info is available
/// @param [in] element - Structure containing the file system element information
/// @param [out] name - The element name
/// @return Operation status.
t_status fs_elementInfo_getName ( const t_element * element, char ** name );

/// @brief Obtain the full pathname to element
/// The returned name pointer is only valid as long as info is available
/// @param [in] element - Structure containing the file system element information
/// @param [out] pathname - The full path to element
/// @return Operation status.
t_status fs_elementInfo_getPath ( const t_element * element, const char ** pathname );

/// @brief Obtain the full pathname to element
/// The returned name pointer is only valid as long as info is available
/// @param [in] element - Structure containing the file system element information
/// @param [in] size    - Size of the output name string
/// @param [out] name   - The directory where the element resides
/// @return Operation status.
t_status fs_elementInfo_getDirName ( const t_element * element, t_size size, char * name );

/// @brief Obtain the element unique identifier on the file system
/// @param [in] element - Structure containing the file system element information
/// @param [out] id  	- Current ID of the file system element
/// @return Operation status.
t_status fs_elementInfo_getID 	( const t_element * element, t_fs_eid * id );


/// @brief Obtain the user ID owning the element
/// @param [in] element - Structure containing the file system element information
/// @param [out] uid  - Current User ID of file system element
/// @return Operation status.
t_status fs_elementInfo_getUID 	( const t_element * element, t_uid * uid );

/// @brief Obtain the group ID owning the element
/// @param [in] element - Structure containing the file system element information
/// @param [out] gid  - Current User ID of filesystem element
/// @return Operation status.
t_status fs_elementInfo_getGID 	( const t_element * element, t_gid * gid );


/// @brief Get element access time
/// @param [in] element - File system element information
/// @param [out] atime  - Last element access time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getAccessTime	( const t_element * element, t_time * atime 	);

/// @brief Get element creation/birth time
/// @param [in] info   - File system element information
/// @param [out] btime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getCreationTime	( const t_element * info, t_time * btime 	);

/// @brief Get element change time
/// @param [in] info   - File system element information
/// @param [out] ctime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getChangetime	( const t_element * info, t_time * ctime 	);

/// @brief Get element modification time
/// @param [in] info   - File system element information
/// @param [out] mtime - Last element modification time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getModificationTime	( const t_element * info, t_time * mtime 	);

/// @brief Get size of element in the file system
/// @param [in] element - File system element information
/// @param [out] size - Size of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getSize	( const t_element * element, t_size * size	);

/// @brief Obtain the permissions of the element
/// @param [in]  element - Structure containing the file system element information
/// @param [out] perm - Current permissions of element
/// @return Operation status.
t_status fs_elementInfo_getPermissions ( const t_element * element, t_fs_perm * perm );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENTINFO_H_ */
