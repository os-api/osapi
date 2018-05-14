/*
 * status.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef STATUS_STATUS_H_
#define STATUS_STATUS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <general/general_defs.h>
#include <status/status_defs.h>

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

// Macro section

#define status_iset(m,f,e,r) 		status_set( m, STATUS_INTERNAL, f, e, r )
#define status_eset(m,f,e,r) 		status_set( m, STATUS_SYSTEM  , f, e, r )

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STATUS_STATUS_H_ */
