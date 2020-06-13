// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General definitions
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_DEFS_H_
#define OSAPI_GENERAL_DEFS_H_


// *****************************************************************************************
//
// Section: Constants
//
// *****************************************************************************************

// Constants that provide a sanity check for calls that require a start and end to complete an operation
#define OSAPI_SANITY_NONE	0x00	// Clear 	(Operation reset)
#define OSAPI_SANITY_BEGIN	0xAA	// 10101010	(Operation has begun)
#define OSAPI_SANITY_END	0x55	// 01010101	(Operation ended, some result is available)


// *****************************************************************************************
//
// Section: Macros
//
// *****************************************************************************************

// Macro modules
#define general_is_valid_module( x )	( x >  OSAPI_MODULE_NONE && x <  OSAPI_MODULE_MAX ? 1 : 0 )
#define general_is_invalid_module( x )	( x <= OSAPI_MODULE_NONE || x >= OSAPI_MODULE_MAX ? 1 : 0 )

//Macros bits
/// @brief Set a byte to on
#define	osapi_bit_on(  x )	(x=1)
/// @brief Set a byte to off
#define	osapi_bit_off( x )	(x=0)

#endif /* OSAPI_GENERAL_DEFS_H_ */
