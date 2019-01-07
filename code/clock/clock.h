// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Calendar time API
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_H_
#define OSAPI_CLOCK_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C"
  {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "clock/clock_types.h"
#include "clock/clock_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup CLOCK
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Clock module API
//
// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface

// There are three function types:

/// @fn t_status clock_module_supported( void )
/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status clock_module_supported( void );

// - Time in seconds
/// @fn t_status clock_time_set(t_time newTime)
/// @brief Set the system clock with the supplied time data
/// @param in newTime
/// @return Operation status
t_status clock_time_set ( t_time newTime );
/// @fn t_status clock_time_get( t_time * curtime )
/// @brief Get the current time in seconds from the epoch
/// @param in,out curtime
/// @return Operation status
t_status clock_time_get( t_time * curtime );
/// @fn t_status clock_time_print( t_time ctime, const char * tmString )
/// @brief Return the current time in seconds from the epoch in human readable format
/// @param in current time
/// @param out Formated time string
/// @return Operation status
t_status clock_time_print( t_time ctime, const char * tmString );

/// @fn t_status clock_time_diff(t_time t1, t_time t2, t_time * diff)
/// @brief Return the difference between two times, in seconds
/// @param in t1,t2
/// @param out diff
/// @return Operation status
t_status clock_time_diff 	(t_time t1, t_time t2, t_time * diff );

// - Time based for high frequency sampling
/*
t_status clock_htTime_get( t_hrTime * );
t_status clock_hrTime_print( t_hrTime, const char * );
t_status clock_hrTime_diff( t_hrTime, t_hrTime, t_hrTime * );
*/

// - Clock based - Full time/date/time zone capabilities
/// @fn t_status clock_localTime_get (t_clock * clk)
/// @brief Get the current local time (considering the timezone)
/// @param in,out clk
/// @return Operation status
t_status clock_localTime_get( t_clock * clk );
/// @fn t_status clock_timeZone_set( t_clock * clk )
/// @brief Set the current timezone
/// @param in,out clk
/// @return Operation status
t_status clock_timeZone_set( t_clock * clk );
/// @fn t_status clock_timeZone_get( t_clock * clk )
/// @brief Get the current timezone
/// @param in,out clk
/// @return Operation status
t_status clock_timeZone_get( t_clock * clk );

#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_H_ */
