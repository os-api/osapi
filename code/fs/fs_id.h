// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide module API for a FS ID
//
// *****************************************************************************************

#ifndef OSAPI_FS_ID_H_
#define OSAPI_FS_ID_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C standard headers
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "fs/fs_platform.h"


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


/// @brief Open a file with fine grain control
/// @param [in] path    - Name of a file system location
/// @param [out] id 	- File system identifier
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_id_get		( const t_char * path, t_fs_id * id );

/// @brief Compare two file system identifiers
/// @param [in] id1	- ile system identifier
/// @param [in] id2	- ile system identifier
/// @param [out] result - Comparison result
/// @return SUCCESS if IDs match. An error otherwise.
t_status fs_id_equal		( t_fs_id * id1, t_fs_id * id2, bool * result );

/// @brief Compare two file system identifiers
/// @param [in] path1    - Name of a file system location
/// @param [in] path2    - Name of a file system location
/// @return SUCCESS if IDs match. An error otherwise.
t_status fs_id_same		( const t_char * path1, const t_char * path2 );

/// @brief Copy a FS ID
/// @param [in] source	- Source file system identifier
/// @param [in] target	- Destination file system identifier
/// @return SUCCESS if IDs match. An error otherwise.
t_status fs_id_copy		( t_fs_id * source, t_fs_id * target );

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ID_H_ */
