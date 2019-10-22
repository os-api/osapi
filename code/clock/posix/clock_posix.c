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

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

// System headers <here>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"
#include "common/common_time.h"

// Own declarations
#include "clock/clock.h"
#include "error/modules/error_clock.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************



t_status clock_time_getPrecise( t_time * p_time )
{
 t_status		st;
 struct timespec	ts;

 status_reset( &st );

 if( p_time == (t_time *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( clock_gettime( CLOCK_REALTIME, &ts ) == -1 )
   { status_eset( OSAPI_MODULE_CLOCK, __func__, errno, &st ); return st; }

 p_time->seconds   = (int64_t)  ts.tv_sec;
 p_time->fraction  = (uint64_t) ts.tv_nsec;
 p_time->precision = osapi_time_nano;

 return st;
}


t_status clock_time_print( t_time * tm, const char * format )
{
  t_status st;

  status_reset( &st );

  return st;
}

t_status clock_time_diff( t_time t1, t_time t2, t_time * p_timeDiff )
{
  t_status st;

  status_reset( &st );

  return st;
}



t_status clock_timeZone_set( const t_char * p_tz )
{
  t_status st;

  status_reset( &st );

  return st;
}

t_status clock_timeZone_get( t_size size, t_char * p_tz )
{
  t_status st;

  status_reset( &st );

  return st;
}



#endif	// If POSIX is defined
