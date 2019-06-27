// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for an element info
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


/// @brief Get type of element
/// @param [in] info - File system element information
/// @param [out] type - Type of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getType		( t_fs_elementInfo * info, int * type 		);

/// @brief Get element ownership: User identifier
/// @param [in] info - File system element information
/// @param [out] uid - User ID
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getUID		( t_fs_elementInfo * info, t_uid * uid		);

/// @brief Get element ownership: Group identifier
/// @param [in] info - File system element information
/// @param [out] gid - Group ID
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getGID		( t_fs_elementInfo * info, t_gid * gid 		);

/// @brief Get element access time
/// @param [in] info - File system element information
/// @param [out] atime - Last element access time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getAtime	( t_fs_elementInfo * info, t_time * atime 	);

/// @brief Get element creation time
/// @param [in] info - File system element information
/// @param [out] ctime - Element creation time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getCtime	( t_fs_elementInfo * info, t_time * ctime 	);

/// @brief Get element modification time
/// @param [in] info - File system element information
/// @param [out] mtime - Last element modification time
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getMtime	( t_fs_elementInfo * info, t_time * mtime 	);

/// @brief Get size of element in the file system
/// @param [in] info - File system element information
/// @param [out] size - Size of element
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_elementInfo_getSize		( t_fs_elementInfo * info, t_size * size	);



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENTINFO_H_ */
