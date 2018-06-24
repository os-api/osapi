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

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI & Own includes

#include "general/general_baseline.h"
#include "general/general_version.h"
#include "general/general_types.h"

// *****************************************************************************************
//
// Section: OSAPI bootstrap API
//
// *****************************************************************************************

unsigned long	osapi_get_version			( void );
int		osapi_get_version_stability		( void );
const char *	osapi_get_version_string		( void );
const char *	osapi_get_version_stability_string	( void );

#endif /* GENERAL_H_ */
