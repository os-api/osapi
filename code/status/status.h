// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef STATUS_STATUS_H_
#define STATUS_STATUS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include "general/general_types.h"
#include "status/status_types.h"

#pragma GCC visibility push(default)		// Start of public interface

// Function section

void		status_reset( t_status * );
void		status_set( int, Byte, const char *, int, t_status * );
void		status_message_print( t_status );
const char *	status_module_get( t_status * );
const char *	status_function_get( t_status * );
const char *	status_error_get( t_status * );
const char *	status_errorByType_get( int, Byte, Byte );
const char *	status_moduleByID_get( Byte );

#pragma GCC visibility pop			// End of public interface


#include "status/status_defs.h"

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STATUS_STATUS_H_ */
