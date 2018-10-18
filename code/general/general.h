// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide base module types and other declarations
//
// *****************************************************************************************

#ifndef GENERAL_H_
#define GENERAL_H_


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Own headers

#include "general/general_baseline.h"
#include "general/general_version.h"
#include "general/general_types.h"
#include "general/general_modules.h"
#include "general/general_defs.h"

// *****************************************************************************************
//
// Section: OSAPI bootstrap API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

unsigned long	osapi_get_version			( void		);
int		osapi_get_version_stability		( void		);
const char *	osapi_get_version_string		( void		);
const char *	osapi_get_version_stability_string	( void 		);
const char * 	osapi_get_protocol_version_string	( t_protocol id );

// Module related
const char *	osapi_getModule				( t_module	);

#pragma GCC visibility pop			// End of public interface


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* GENERAL_H_ */
