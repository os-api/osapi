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
#include "error/modules/error_clock.h"
#include "status/status.h"
#include "common/common_time.h"
#include "common/common_helper.h"

// Own declarations
#include "clock/clock.h"
#include "clock/clock_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// The clock module is not yet supported (under construction)
t_status clock_module_supported( void )
{
  t_status st;

  // RETURN_STATUS_SUCCESS;
  status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st);

  return st;
}

t_status clock_time_set (t_time * tm)
{
  t_status st;

  status_reset (&st);

  return st;
}

t_status clock_time_get( t_time * p_time )
{
 t_status		st;
 time_t			tm = (time_t) 0;
 struct timespec	ts;

 status_reset( &st );

 if( p_time == (t_time *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( clock_gettime( CLOCK_REALTIME_COARSE, &ts ) == 0 )
     st = common_time_copyNano   ( (int64_t) ts.tv_sec, (uint64_t) ts.tv_nsec, p_time );
 else	// Use other way
   {
     if( time( &tm ) == -1 )
	 status_eset( OSAPI_MODULE_CLOCK, __func__, errno, &st );
     else
	 st = common_time_copySeconds( (int64_t) tm, p_time );
   }

 return st;
}


t_status clock_vtime_get( t_time * p_time )
{
 t_status		st;
 // time_t			tm = (time_t) 0;
 struct timespec	ts;

 status_reset( &st );

 if( p_time == (t_time *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( clock_gettime( CLOCK_MONOTONIC_COARSE, &ts ) == 0 )
     st = common_time_copyNano   ( (int64_t) ts.tv_sec, (uint64_t) ts.tv_nsec, p_time );
 else
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st ); return st; }

 return st;
}


t_status clock_vtime_getPrecise( t_time * p_time )
{
 t_status		st;
 // time_t			tm = (time_t) 0;
 struct timespec	ts;

 status_reset( &st );

 if( p_time == (t_time *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( clock_gettime( CLOCK_MONOTONIC_RAW, &ts ) == 0 )
     st = common_time_copyNano   ( (int64_t) ts.tv_sec, (uint64_t) ts.tv_nsec, p_time );
 else
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st ); return st; }

 return st;
}

t_status clock_instance_createTimezone( t_time * p_time, const char * timezone, t_clock * p_clock )
{
 t_status st;

 status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st);

 return st;
}


// To get a more accurate time delta, time is retrieved as late as possible
t_status clock_chrono_start( t_chrono * p_chrono )
{
 t_status		st;
 struct timespec	ts;

 status_reset( &st );

 if( p_chrono == (t_chrono *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 p_chrono->magic = OSAPI_CLOCK_CHRONO_NONE;

 if( clock_gettime( CLOCK_BOOTTIME, &ts ) != 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st ); return st; }
 else
   {
     copy_timeNano( ((int64_t) ts.tv_sec), ((uint64_t) ts.tv_nsec), (&p_chrono->value) )	// macro
     p_chrono->magic = OSAPI_CLOCK_CHRONO_STARTED;
   }


 return st;
}


// To get a more accurate time delta, get final clock time first and only after perform usual operations
t_status clock_chrono_stop( t_chrono * p_chrono )
{
 t_status		st;
 t_time			endTime, deltaTime;
 struct timespec	ts;

 if( clock_gettime( CLOCK_BOOTTIME, &ts ) != 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_support, &st ); return st; }

 if( p_chrono == (t_chrono *) 0 )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_params, &st ); return st; }

 if( p_chrono->magic != OSAPI_CLOCK_CHRONO_STARTED )
   { status_iset( OSAPI_MODULE_CLOCK, __func__, osapi_clock_error_noStart, &st ); return st; }

 // Only now perform the status reset
 status_reset( &st );

 copy_timeNano( ((int64_t) ts.tv_sec), ((uint64_t) ts.tv_nsec), (&endTime) )	// macro

 st = common_time_sub( &p_chrono->value, &endTime, &deltaTime );
 if( status_success( st ) )
   {
     copy_time( (&deltaTime), (&p_chrono->value) );
     p_chrono->magic = OSAPI_CLOCK_CHRONO_STOPPED;
   }

 return st;
}

#endif	// If POSIX is defined
