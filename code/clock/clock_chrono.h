// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a Chronometer API
// 		Functionality to measure time deltas
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_CHRONO_H_
#define OSAPI_CLOCK_CHRONO_H_

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
// Section: API declaration
//
// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface

/// @brief Get the current machine/real time in seconds from the epoch
/// @param [out] ctime - Initial time
/// @return Operation status
t_status clock_chrono_start( t_chrono * ctime );

/// @brief Compute a delta between first measurement (in the start method) and now
/// @param [in,out] ctime - Current time delta from initial time
/// @return Operation status
t_status clock_chrono_stop( t_chrono * ctime );



#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_CHRONO_H_ */
