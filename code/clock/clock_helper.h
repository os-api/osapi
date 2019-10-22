// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock helper macros
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_HELPER_H_
#define OSAPI_CLOCK_HELPER_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI types

// Import module headers


// *****************************************************************************************
//
// Section: Macros for clock
//
// *****************************************************************************************

#define get_clock_time( x )		(x->value)
#define get_clock_seconds( x )		(x->value.seconds)
#define get_clock_fraction( x )		(x->value.fraction)
#define get_clock_precision( x )	(x->value.precision)
#define get_clock_offset(x)		(x->offset)
#define get_clock_seconds_offset(x)	(x->offset.seconds)
#define get_clock_fraction_offset(x)	(x->offset.fraction)




#endif /* OSAPI_CLOCK_HELPER_H_ */
