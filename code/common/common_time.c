// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common Module Linux function implementation for time functionality
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Include standard headers
#include <time.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_common.h"
#include "status/status.h"
#include "status/trace_macros.h"

// Own declarations
#include "common/common_priv.h"
#include "common/common_number.h"
#include "common/common_time.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status common_time_reset( t_time * p_tm )
{
  t_status	st;

  status_reset( & st );

  if( p_tm == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  p_tm->seconds		= (uint64_t) 0;
  p_tm->fraction	= (int64_t) 0;
  p_tm->precision	= osapi_time_unspecified;

  return st;
}


t_status common_time_copy( const t_time * p_source, t_time * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  p_target->seconds	= p_source->seconds;
  p_target->fraction	= p_source->fraction;
  p_target->precision	= p_source->precision;

  return st;
}

t_status common_time_copySeconds( const int64_t source, t_time * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_target == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  p_target->seconds	= source;
  p_target->fraction	= (uint64_t) 0;
  p_target->precision	= osapi_time_second;

  return st;
}

t_status common_time_copyNano( int64_t seconds, uint64_t nano, t_time * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_target == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  p_target->seconds	= (int64_t)  seconds;
  p_target->fraction	= (uint64_t) nano;
  p_target->precision	= osapi_time_nano;

  return st;
}


t_status common_time_copySpec( const struct timespec * p_source, t_time * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  p_target->seconds	= (int64_t)  p_source->tv_sec;
  p_target->fraction	= (uint64_t) p_source->tv_nsec;
  p_target->precision	= osapi_time_nano;

  return st;
}


t_status common_time_equal( const t_time * p_t1, const t_time * p_t2, bool * result )
{
  t_status	st;

  status_reset( & st );

  if( p_t1 == NULL || p_t2 == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  *result = false;
  if( p_t1->seconds == p_t2->seconds && p_t1->fraction == p_t2->fraction )
      *result = true;

  return st;
}


int common_time_getResolution( uint32_t nano )
{
       if( nano / 100000000 > 0 )		return osapi_time_tsecond;
  else if( nano / 10000000 > 0  )		return osapi_time_hsecond;
  else if( nano / 1000000 > 0   )		return osapi_time_milli;
  else if( nano / 100000 > 0    )		return osapi_time_tmilli;
  else if( nano / 10000 > 0     )		return osapi_time_hmilli;
  else if( nano / 1000 > 0      )		return osapi_time_micro;
  else if( nano / 100 > 0       )		return osapi_time_tmicro;
  else if( nano / 10 > 0        )		return osapi_time_hmicro;
  else 						return osapi_time_nano;

}

int64_t common_timeFraction_getMaxPrecisionValue( t_time_precision precision )
{
  switch( precision )
  {
    case osapi_time_tsecond:	return	10;
    case osapi_time_hsecond:	return	100;
    case osapi_time_milli:	return	1000;
    case osapi_time_tmilli:	return	10000;
    case osapi_time_hmilli:	return	100000;
    case osapi_time_micro:	return	1000000;
    case osapi_time_tmicro:	return	10000000;
    case osapi_time_hmicro:	return	100000000;
    case osapi_time_nano:	return	1000000000;
    case osapi_time_tnano:	return	10000000000;
    case osapi_time_hnano:	return	100000000000;
    case osapi_time_pico:	return	1000000000000;
    case osapi_time_femto:	return	1000000000000000;
    case osapi_time_atto:	return	1000000000000000000;

    default:			return -1;
    /* Unsupported with uint64_t
    case osapi_time_zepto:	return	10^21;
    case osapi_time_yocto:	return	10^24;
    case osapi_time_planck:	return	10^44;
    */
  }
}

t_status common_time_add( const t_time * p_t1, const t_time * p_t2, t_time * p_result )
{
 t_status	st;

 status_reset( & st );

 if( p_t1 == NULL || p_t2 == NULL || p_result == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( p_t1->precision != p_t2->precision )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_precision, &st ); return st; }

 int64_t ceiling = common_timeFraction_getMaxPrecisionValue( p_t1->precision );
 if( ceiling < 0 )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_precision, &st ); return st; }

 int64_t f1 = (int64_t) p_t1->fraction;
 int64_t f2 = (int64_t) p_t2->fraction;
 int64_t fr = 0;

 st = common_realNumber_add( p_t1->seconds, f1, p_t2->seconds, f2, ceiling, &(p_result->seconds), &fr );

 p_result->fraction = (uint64_t) fr;

 return st;
}

t_status common_time_sub( const t_time * p_t1, const t_time * p_t2, t_time * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_t1 == NULL || p_t2 == NULL || p_result == NULL )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

  if( p_t1->precision != p_t2->precision )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_precision, &st ); return st; }

  int64_t ceiling = common_timeFraction_getMaxPrecisionValue( p_t1->precision );
  if( ceiling < 0 )
    { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_precision, &st ); return st; }

  int64_t f1 = (int64_t) p_t1->fraction;
  int64_t f2 = (int64_t) p_t2->fraction;
  int64_t fr = 0;

  st = common_realNumber_subtract( p_t1->seconds, f1, p_t2->seconds, f2, ceiling, &(p_result->seconds), &fr );

  p_result->fraction = (uint64_t) fr;

  return st;
}



