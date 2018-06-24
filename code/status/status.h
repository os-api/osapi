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


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"

// Own declarations
#include "status/status_types.h"

// *****************************************************************************************
//
// Section: Status module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


void		status_reset		( t_status * p_status								);
void		status_set		( int module, Byte tp, const char * fname, int code, t_status * p_status	);

void		status_message_print	( t_status status								);
const char *	status_module_get	( t_status * p_status								);
const char *	status_function_get	( t_status * p_status								);
const char *	status_error_get	( t_status * p_status								);
const char *	status_errorByType_get	( int code, Byte module, Byte type						);
const char *	status_moduleByID_get	( Byte module									);


#pragma GCC visibility pop			// End of public interface


// *****************************************************************************************
//
// Section: Help macros
//
// *****************************************************************************************

// Import macros
#include "status/status_defs.h"


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STATUS_STATUS_H_ */
