// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a Virtual Clock API
// 		A virtual clock is a clock that only goes forward in time, a machine real
//		clock can be set to a previous moment in time, to correct time drifts,
//		for instance
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_VIRTUAL_H_
#define OSAPI_CLOCK_VIRTUAL_H_

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




#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_VIRTUAL_H_ */
