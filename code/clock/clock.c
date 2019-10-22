// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock module using a POSIX compliant implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers <here>
#include <time.h>
#include <stdlib.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_clock.h"
#include "status/status.h"
#include "common/common_time.h"

// Own declarations
#include "clock/clock.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status clock_time_copy( const t_time * source, t_time * target )
{
  return common_time_copy( source, target );
}


t_status clock_time_equal( const t_time * t1, const t_time * t2, bool * result )
{
  return common_time_equal( t1, t2, result );
}


t_status clock_instance_getTime( t_clock * p_clock, t_time * p_time )
{
  return common_time_copy( &( p_clock->value ), p_time );
}


t_status clock_offset_apply( t_time * p_base, t_time_offset * p_offset, t_time * p_result )
{
 t_status	st;
 int64_t	frac, frac1, frac2;

 status_reset( & st );

 if( p_base == NULL || p_offset == NULL || p_result == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_params, &st ); return st; }

 // Make sure that there is enough room for computing the time offset
 if( (p_base->fraction   & UINT64_C( 0x8000000000000000 )) == UINT64_C( 0x8000000000000000 ) ||
     (p_offset->fraction & UINT64_C( 0x8000000000000000 )) == UINT64_C( 0x8000000000000000 )
   )
   { status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_overflow, &st ); return st; }

 p_result->seconds = p_base->seconds + p_offset->seconds;

 if( p_base->precision == osapi_time_second ) return st;	// Fraction computing is not required

 // Propagate the sign to the fraction
 if( p_base->seconds < 0 )	frac1 = (int64_t) -p_base->fraction;
 else				frac1 = (int64_t) p_base->fraction;

 if( p_offset->seconds < 0 )	frac2 = (int64_t) -p_offset->fraction;
 else				frac2 = (int64_t) p_offset->fraction;

 // Make calculations for the base
 frac = frac1 + frac2;

 // Set up base for fraction
 uint64_t top = 0;
 switch( p_base->precision )
 {
   case osapi_time_tsecond:	top = UINT64_C( 10 );			break;
   case osapi_time_hsecond:	top = UINT64_C( 100 );			break;
   case osapi_time_milli:	top = UINT64_C( 1000 );			break;
   case osapi_time_tmilli:	top = UINT64_C( 10000 );		break;
   case osapi_time_hmilli:	top = UINT64_C( 100000 );		break;
   case osapi_time_micro:	top = UINT64_C( 1000000 );		break;
   case osapi_time_tmicro:	top = UINT64_C( 10000000 );		break;
   case osapi_time_hmicro:	top = UINT64_C( 100000000 );		break;
   case osapi_time_nano:	top = UINT64_C( 1000000000 );		break;
   case osapi_time_tnano:	top = UINT64_C( 10000000000 );		break;
   case osapi_time_hnano:	top = UINT64_C( 100000000000 );		break;
   case osapi_time_pico:	top = UINT64_C( 1000000000000 );	break;
 }

 if( (uint64_t) llabs( frac ) >= top )
   {
     p_result->fraction = (uint64_t) ((uint64_t) llabs( frac ) ) - top;

     if( frac >= 0 )	p_result->seconds++;
     else		p_result->seconds--;
   }
 else
   {
     p_result->fraction = (uint64_t) frac;
     if( frac < 0 )	p_result->seconds--;
   }

 return st;
}


// Construct a local time using the standard time plus offset
t_status clock_instance_getLocalTime( t_clock * p_clock, t_time * p_ltime )
{
 t_status st;

 status_reset( &st );

 if( p_clock == NULL || p_ltime == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( p_clock->offset.seconds == (int64_t) 0 && p_clock->offset.fraction == (uint64_t) 0 )
     st = common_time_copy( &(p_clock->value), p_ltime );	// Local time is equal to standard time
 else
     st = clock_offset_apply( &(p_clock->value), &p_clock->offset, p_ltime );

 return st;
}
