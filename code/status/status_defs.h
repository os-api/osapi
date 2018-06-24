// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module macros & other definitions
//
// *****************************************************************************************

#ifndef STATUS_STATUS_DEFS_H_
#define STATUS_STATUS_DEFS_H_

// *****************************************************************************************
//
// Section: Macros for client applications
//
// *****************************************************************************************

// Helper definitions for a correct way to check for success/failure of operations
#define status_success( x )	( x.code == 0 )
#define status_failure( x )	( x.code != 0 )
#define status_error( x )	( x.code )

// Expansion of structure arguments (this avoids that client applications need to know internal details of t_status)
#define OSAPI_STATUS(x)		status(x.code,x.module,x.type,x.funcname)


// *****************************************************************************************
//
// Section: Macros/definitions for internal usage
//
// *****************************************************************************************

// Status information, internal or external
#define STATUS_INTERNAL		0
#define STATUS_SYSTEM		1

// Short notation for a success status
#define RETURN_STATUS_SUCCESS	{ t_status st; status_reset( &st ); return st; }

// Support macros for setting internal/external status errors

#define status_iset(m,f,e,r) 		status_set( m, STATUS_INTERNAL, f, e, r )
#define status_eset(m,f,e,r) 		status_set( m, STATUS_SYSTEM  , f, e, r )


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STATUS_STATUS_DEFS_H_ */
