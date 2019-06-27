// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide IO module API
//
// *****************************************************************************************

#ifndef OSAPI_IO_H_
#define OSAPI_IO_H_

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

// Common includes
#include <common/common_types.h>

// Own declarations
#include "io/io_types.h"
#include "io/io_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup IO
/// @brief The Input/Output module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status io_module_supported( void );

// Directory facilities
/// @brief Change the current process working directory
/// @param [in] dirname - New working directory name
/// @return Operation status
t_status io_directory_change( t_char * dirname );

/*
t_status	io_directory_create		( t_char *		);
t_status	io_directory_is			( t_char *		);
t_status	io_directory_getCurrent		( t_char *		);

*/

// File facilities
/*
t_status	io_file_open			( t_char *, t_file *		);
t_status	io_file_close			( t_file			);
t_status	io_file_read			( t_file, t_size, t_stream *	);
t_status	io_file_write			( t_file, t_size, t_stream	);
*/

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_IO_H_ */
