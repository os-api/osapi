// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a time API that operates on standard time to:
//		- retrieve or set the machine system time
//		- Obtain high resolution time
//		- Operate on time types (deltas, printing, etc)
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_TIME_H_
#define OSAPI_CLOCK_TIME_H_

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

// - Time in seconds
/// @brief Set the time structure with the supplied data
/// @param [in] seconds  - The number of seconds since the machine/OS epoch
/// @param [in] fraction - The fraction of a second
/// @param [out] tm 	 - The new time representation
/// @return Operation status
t_status clock_time_make( int64_t seconds, uint64_t fraction, t_time * tm );

/// @brief Get the current time in seconds from the epoch
/// @param [out] curtime - Current time
/// @return Operation status
t_status clock_time_get( t_time * curtime );

/// @brief Get the current time in the highest available resolution since the machine/OS epoch
/// @param [out] curtime - Current highest precision time
/// @return Operation status
t_status clock_time_getPrecise( t_time * curtime );

/// @brief Extract the resolution from a time type
/// @param [in]  tm 		- Time information
/// @param [out] resolution	- Time precision
/// @return Operation status
t_status clock_time_getResolution( t_time * tm, int * resolution );

/// @brief Print the current time in seconds from the epoch in human readable format
/// @param [in] ctime - The current time
/// @param [out] tmString - Formated time string
/// @return Operation status
t_status clock_time_print	( t_time * ctime, const char * tmString );

/// @brief Return the difference between two times, in seconds
/// @param [in] t1 - First time
/// @param [in] t2 - Second time
/// @param [out] diff - Time difference
/// @return Operation status
t_status clock_time_diff 	(t_time t1, t_time t2, t_time * diff );

/// @brief Perform a copy between two time types
/// @param [in]  source - Copy from
/// @param [out] target - Copy to
/// @return Operation status
t_status clock_time_copy( const t_time * source, t_time * target	);

/// @brief Perform a comparison between two time types
/// @param [in] t1 	- The first time to compare
/// @param [in] t2 	- Second time to compare
/// @param [out] result - True if times are the same. False otherwise
/// @return Operation status
t_status clock_time_equal( const t_time * t1, const t_time * t2, bool * result );

/// @brief Generate a time offset from components
/// @param [in]  seconds	- Time in seconds from a certain origin
/// @param [in]  fraction	- The fraction of a second
/// @param [out] offset		- The result time offset type
/// @return Precision time enum
t_status clock_offset_make	( int64_t seconds, uint64_t fraction, t_time_offset * offset );

/// @brief Incorporate a time offset into a new time
/// @param [in]  base   - The source time
/// @param [in]  offset - The time offset
/// @param [out] result - The result time after applying an offset to a base time
/// @return Precision time enum
t_status clock_offset_apply	( t_time * base, t_time_offset * offset, t_time * result );

#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_TIME_H_ */
