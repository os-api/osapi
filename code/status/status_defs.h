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
// Section: Import headers
//
// *****************************************************************************************

#include "error/error_types.h"


// *****************************************************************************************
//
// Section: Constants/Macros for client applications
//
// *****************************************************************************************

#define	OSAPI_STATUS_STRING_SIZE	101

// Helper definitions for a correct way to check for success/failure of operations
#define status_success( x )	( x.code == 0 && x.type == e_library_osapi	)
#define status_failure( x )	( x.code != 0 || x.type != e_library_osapi	)

// Match a given error
#define status_error( s, e )	( s.code == e )

#define status_true(  x )	( status_failure( x ) ? 0 : 1 )
#define status_false( x )	( status_success( x ) ? 1 : 0 )

// Find if a module or facility is supported
#define status_unsupported( s )	( s.code == OSAPI_ERROR_SUPPORT )


// *****************************************************************************************
//
// Section: Macros/definitions for internal usage
//
// *****************************************************************************************

// Status information, internal or external
//#define STATUS_INTERNAL		0
//#define STATUS_SYSTEM		1

enum osapi_library_id
{
  e_library_osapi 		= 0,

  // System Libraries get negative codes
  e_library_c			= -1,
  e_library_loader		= -2,
};

// Short notation for a success status
#define RETURN_STATUS_SUCCESS	{ t_status st; status_reset( &st ); return st; }

// Support macros for setting internal/external status errors

#define status_iset(m,f,e,r) 		status_set( m, e_library_osapi, f, e, r )
#define status_eset(m,f,e,r) 		status_set( m, e_library_c,     f, e, r )


#endif /* STATUS_STATUS_DEFS_H_ */
