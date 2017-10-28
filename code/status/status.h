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

#include "../../code/general/general_defs.h"
#include "../../code/module/module_defs.h"
#include "../../code/status/status_defs.h"

void status_reset( t_status * );
void status_set( int, int, unsigned int, t_status * );
void status_message_print( t_status );
void status_function_set(int, int, const char * );


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STATUS_STATUS_H_ */
