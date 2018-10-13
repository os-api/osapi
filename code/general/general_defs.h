// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General module definitions
//
// *****************************************************************************************

#ifndef GENERAL_DEFS_H_
#define GENERAL_DEFS_H_

#define general_is_valid_module( x )	( x >  OSAPI_MODULE_NONE && x <  OSAPI_MODULE_MAX ? 1 : 0 )
#define general_is_invalid_module( x )	( x <= OSAPI_MODULE_NONE || x >= OSAPI_MODULE_MAX ? 1 : 0 )

#endif /* GENERAL_DEFS_H_ */
