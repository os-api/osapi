// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a link element
//
// *****************************************************************************************

#ifndef OSAPI_FS_LINK_H_
#define OSAPI_FS_LINK_H_

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
#include "fs/type/fs_type_link.h"

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


/// @brief Open a link
/// @param [in] path    - Link name
/// @param [out] link 	- New link descriptor
/// @return SUCCESS if link opened. An error condition otherwise.
t_status fs_link_open			( const t_char * path, t_link * link );

/// @brief Close a link
/// @param [in] link 	- Link descriptor
/// @return SUCCESS if descriptor closed. An error condition otherwise.
t_status fs_link_close			( t_link * link );

/// @brief Create a new soft link
/// @param [in] source  - New link name
/// @param [in] target	- Link target
/// @return SUCCESS if created. An error condition otherwise.
t_status fs_link_createSoft		( const t_char * source, const t_char * target );

/// @brief Create a new hard link
/// @param [in] source  - New link name
/// @param [in] target	- Link target
/// @return SUCCESS if created. An error condition otherwise.
t_status fs_link_createHard		( const t_char * source, const t_char * target );

/// @brief Obtain a link descriptor from a path name
/// @param [in] path    - Link name
/// @param [out] link	- Link descriptor
/// @return SUCCESS if information about the link was obtained. Failure otherwise.
t_status fs_link_getInfo		( const t_char * path, t_link * link );

/// @brief Obtain an element descriptor from a link descriptor
/// @param [in] link	- Link descriptor
/// @param [out] elem	- Element descriptor
/// @return Operation status.
t_status fs_link_getElement		( t_link * link, t_element * elem );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_LINK_H_ */
