/*
 * status_defs.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef STATUS_STATUS_DEFS_H_
#define STATUS_STATUS_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define STATUS_MAX_ERROR_SIZE	1025

typedef int			t_status_error;
typedef Byte			t_status_mod;
typedef Byte			t_status_type;
typedef const char *		t_status_funcname;

// Definition of opaque status type

struct s_status
{
  t_status_error	code;
  t_status_mod		module;
  t_status_type		type;
  t_status_funcname	funcname;
};

typedef struct s_status		t_status;


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

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STATUS_STATUS_DEFS_H_ */
