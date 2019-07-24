// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a FS element ID
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENT_ID_H_
#define OSAPI_FS_ELEMENT_ID_H_

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


/// @brief Compare two file system element identifiers
/// @param [in] id1	- File system identifier
/// @param [in] id2	- File system identifier
/// @param [out] result - Comparison result
/// @return Operation status.
t_status fs_elementID_equal	( t_fs_eid * id1, t_fs_eid * id2, bool * result );

/// @brief Copy an element ID
/// @param [in] source     - Copy from
/// @param [in] target     - Copy into
/// @return SUCCESS if copied. An error condition otherwise.
t_status fs_elementID_copy	( t_fs_eid * source, t_fs_eid * target );

/// @brief Obtain the element unique identifier on the file system element
/// @param [in] path 	- Path name to the file system element
/// @param [out] id  	- Current ID of the file system element
/// @return Operation status.
t_status fs_elementID_get 	( const t_char * path, t_fs_eid * id );



#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_ELEMENT_ID_H_ */
