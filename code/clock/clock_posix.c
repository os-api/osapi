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

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_clock.h"
#include "status/status.h"

// Own declarations
#include "clock/clock.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status clock_module_supported( void )
{
  RETURN_STATUS_SUCCESS;		// Posix supports clocks
}

t_status clock_time_set (t_time tm)
{
  t_status st;

  status_reset (&st);

  return st;
}

t_status clock_time_get( t_time * p_tm )
{
  t_status st;

  status_reset (&st);

  if( p_tm == (t_time *) 0 )
       status_iset( OSAPI_MODULE_CLOCK, __func__, e_clock_params, &st);
  else if( time (p_tm) == -1 )
       status_eset( OSAPI_MODULE_CLOCK, __func__, errno, &st);

  return st;
}

t_status clock_time_print( t_time tm, const char * format )
{
  t_status st;

  status_reset (&st);

  return st;
}

t_status clock_time_diff( t_time t1, t_time t2, t_time * p_timeDiff )
{
  t_status st;

  status_reset (&st);

  return st;
}

// - Time based for high resolution

t_status clock_htTime_get (t_hrTime * p_hrTm)
{
  t_status st;

  status_reset (&st);

  return st;

}

t_status clock_hrTime_print( t_hrTime hrTm, const char * format )
{
  t_status st;

  status_reset (&st);

  return st;

}

t_status clock_hrTime_diff( t_hrTime t1, t_hrTime t2, t_hrTime * p_hrTimeDiff )
{
  t_status st;

  status_reset (&st);

  return st;
}

// - Clock based for full time and date functionality

t_status clock_localTime_get( t_clock * p_ltm )
{
  t_status st;

  status_reset (&st);

  return st;
}

t_status clock_timeZone_set( t_clock * p_tz )
{
  t_status st;

  status_reset (&st);

  return st;
}

t_status clock_timeZone_get( t_clock * p_tz )
{
  t_status st;

  status_reset (&st);

  return st;
}



#endif	// If POSIX is defined
