/*
 * status_defs.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef STATUS_STATUS_DEFS_H_
#define STATUS_STATUS_DEFS_H_

// Macro section

// Helper definitions for a correct way to check for success/failure of operations
#define status_success( x )	( x.code == 0 )
#define status_failure( x )	( x.code != 0 )
#define status_error( x )	( x.code )

#define STATUS_INTERNAL		0
#define STATUS_SYSTEM		1

// Expansion of structure arguments
#define OSAPI_STATUS(x)		status(x.code,x.module,x.type,x.funcname)

#define RETURN_STATUS_SUCCESS	{ t_status st; status_reset( &st ); return st; }


// Macro section

#define status_iset(m,f,e,r) 		status_set( m, STATUS_INTERNAL, f, e, r )
#define status_eset(m,f,e,r) 		status_set( m, STATUS_SYSTEM  , f, e, r )

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STATUS_STATUS_DEFS_H_ */
