// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a clock API
//		A clock is defined as a type that contains a standard time and a time offset
//		to allow representations of local times (instead of using a timezone)
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_INSTANCE_H_
#define OSAPI_CLOCK_INSTANCE_H_

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

/// @brief Create a new clock instance based on a given timezone and time value
/// @param [in]  value    - The time value (standard format)
/// @param [in]  timezone - The timezone information (e.g. CDT)
/// @param [out] clk      - The new clock instance
/// @return Operation status
t_status clock_instance_createTimezone( t_time * value, const char * timezone, t_clock * clk );

/// @brief Create a new clock instance based on a given time offset from the standard time
/// @param [in]  value  - The time value (standard format)
/// @param [in]  offset - The offset value
/// @param [out] clk    - The new clock instance
/// @return Operation status
t_status clock_instance_createOffset( t_time * value, t_time_offset * offset, t_clock * clk );

/// @brief Get the current local time from a clock
/// @param [in]  clk       - The current clock
/// @param [out] localTime - The extracted local time
/// @return Operation status
t_status clock_instance_getLocalTime( t_clock * clk, t_time * localTime );

/// @brief Get the current standard time from a clock
/// @param [in]  clk     - The current clock
/// @param [out] stdTime - The extracted local time
/// @return Operation status
t_status clock_instance_getTime( t_clock * clk, t_time * stdTime );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_INSTANCE_H_ */
