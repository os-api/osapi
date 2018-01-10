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



// Function section

void status_reset( t_status * );
void status_set( int, Byte, const char *, int, t_status * );
void status_message_print( t_status );

// Macro section

#define status_iset(m,f,e,r) status_set( m, STATUS_INTERNAL, f, e, r )
#define status_eset(m,f,e,r) status_set( m, STATUS_SYSTEM  , f, e, r )

#define RETURN_STATUS_SUCCESS	{ t_status st; status_reset( &st ); return st; }

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STATUS_STATUS_H_ */
