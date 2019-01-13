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
/// @brief The clock module
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

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status clock_module_supported( void );

// - Time in seconds
/// @brief Set the system clock with the supplied time data
/// @param [in] newTime - The new time
/// @return Operation status
t_status clock_time_set( t_time newTime );

/// @brief Get the current time in seconds from the epoch
/// @param [out] curtime - Current time
/// @return Operation status

t_status clock_time_get( t_time * curtime );

/// @brief Return the current time in seconds from the epoch in human readable format
/// @param [in] ctime - The current time
/// @param [out] tmString - Formated time string
/// @return Operation status
t_status clock_time_print( t_time ctime, const char * tmString );

/// @brief Return the difference between two times, in seconds
/// @param [in] t1 - First time
/// @param [in] t2 - Second time
/// @param [out] diff - Time difference
/// @return Operation status
t_status clock_time_diff 	(t_time t1, t_time t2, t_time * diff );

// - Time based for high frequency sampling
/*
t_status clock_htTime_get( t_hrTime * );
t_status clock_hrTime_print( t_hrTime, const char * );
t_status clock_hrTime_diff( t_hrTime, t_hrTime, t_hrTime * );
*/

// - Clock based - Full time/date/time zone capabilities
/// @brief Get the current local time (considering the timezone)
/// @param [out] clk - The current time
/// @return Operation status
t_status clock_localTime_get( t_clock * clk );

/// @brief Set the current timezone
/// @param [in] clk - New time
/// @return Operation status
t_status clock_timeZone_set( t_clock * clk );

/// @brief Get the current timezone
/// @param [out] clk - Get the current timezone
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
