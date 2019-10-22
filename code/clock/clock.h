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
#include "clock/clock_time.h"
#include "clock/clock_instance.h"
#include "clock/clock_timezone.h"
#include "clock/clock_calendar.h"


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


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_CLOCK_H_ */
