// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_H_
#define OSAPI_STATUS_H_

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
#include "general/general_types.h"

// Own declarations
#include "status/status_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STATUS
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Status module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


void		status_reset		( t_status * 										);
void		status_set		( t_module, t_status_type, t_status_funcname, t_error, t_status *			);
void		status_setString	( t_module, t_status_type, t_status_funcname, t_status_string, t_status * 		);

void		status_message_print	( t_status										);
void		status_message_get	( t_status, t_size, t_char *								);

// Get component strings of a t_status type
const char *	status_module_get	( t_status										);
const char *	status_function_get	( t_status 										);
const char *	status_error_get	( t_status 										);


#pragma GCC visibility pop			// End of public interface


// *****************************************************************************************
//
// Section: Help macros
//
// *****************************************************************************************

// Import macros
#include "status/status_defs.h"

///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STATUS_H_ */
