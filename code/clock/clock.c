// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock module implementation for time type
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
#include "common/common_number.h"
#include "common/common_time.h"

// Own declarations
#include "clock/clock.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status clock_time_make( int64_t seconds, uint64_t fraction, t_time_precision prec, t_time * p_tm )
{
 t_status	st;

 status_reset( & st );

 if( p_tm == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_params, &st ); return st; }

 p_tm->seconds   = seconds;
 p_tm->fraction  = fraction;
 p_tm->precision = prec;

 return st;
}

t_status clock_offset_make( int64_t seconds, uint64_t fraction, t_time_offset * p_offset )
{
 t_status	st;

 status_reset( & st );

 if( p_offset == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_params, &st ); return st; }

 p_offset->seconds  = seconds;
 p_offset->fraction = fraction;

 return st;
}

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

 // Add seconds
 st = common_number_add( p_base->seconds, p_offset->seconds, &p_result->seconds );
 if( status_failure( st ) ) return st;

 if( p_base->precision == osapi_time_second ) return st;	// Fraction computing is not required

 // Make sure that there is enough room for computing the time offset
 if( (p_base->fraction   & UINT64_C( 0x8000000000000000 )) == UINT64_C( 0x8000000000000000 ) ||
     (p_offset->fraction & UINT64_C( 0x8000000000000000 )) == UINT64_C( 0x8000000000000000 )
   )
   { status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_overflow, &st ); return st; }

 // Propagate the sign to the fraction
 if( p_base->seconds < 0 )	frac1 = (int64_t) -p_base->fraction;
 else				frac1 = (int64_t) p_base->fraction;

 if( p_offset->seconds < 0 )	frac2 = (int64_t) -p_offset->fraction;
 else				frac2 = (int64_t) p_offset->fraction;

 // Make calculations for the fraction
 st = common_number_add( frac1, frac2, &frac );
 if( status_failure( st ) ) return st;

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

   default:
	   status_iset( OSAPI_MODULE_CLOCK, __func__,osapi_clock_error_prec, &st );
	   return st;
 }

 uint64_t fvalue = (uint64_t) llabs( frac );
 if( fvalue >= top )
   {
     p_result->fraction = (uint64_t) (fvalue - top);

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


t_status clock_offset_copy( const t_time_offset * p_source, t_time_offset * p_target )
{
 t_status st;

 status_reset( &st );

 if( p_source == NULL || p_target == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 p_target->seconds  = p_source->seconds;
 p_target->fraction = p_source->fraction;

 return st;
}

// Construct an instance of a clock based on two types: a time value and an time offset
t_status clock_instance_createOffset( t_time * p_time, t_time_offset * p_offset, t_clock * p_clock )
{
 t_status st;

 status_reset( &st );

 if( p_time == NULL || p_offset == NULL || p_clock == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 // Don't care about status since we are already testing the pointers in this function
 common_time_copy ( p_time,   &(p_clock->value)  );
 clock_offset_copy( p_offset, &(p_clock->offset) );

 p_clock->local = false;
 if( p_offset->seconds == (int64_t) 0 && p_offset->fraction == (uint64_t) 0 )
     p_clock->local = true;

 return st;
}


t_status clock_instance_update( t_clock * p_clock )
{
 t_status st;

 status_reset( &st );

 if( p_clock == NULL )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 st = clock_time_get( &(p_clock->value) );

 return st;
}


