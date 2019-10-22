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





#endif	// If POSIX is defined
