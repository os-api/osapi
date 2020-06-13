// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for Time related functionality
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TIME_H_
#define OSAPI_COMMON_TIME_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers
#include <stdint.h>
#include <time.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/common_types.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************


/// @brief Reset a time to the type default
/// @param [out]  tm - Time to reset
/// @return Operation status
t_status common_time_reset		( t_time * tm 						);

/// @brief Perform a copy between two time types
/// @param [in]  source - Copy from
/// @param [out] target - Copy to
/// @return Operation status
t_status common_time_copy		( const t_time * source, t_time * target		);

/// @brief Copy a Standard C time in seconds from the Epoch into a standard OSAPI time
/// @param [in]  source - Copy from
/// @param [out] target - Copy to
/// @return Operation status
t_status common_time_copySeconds	( const time_t source, t_time * target			);

/// @brief Copy a C Standard time in nanoseconds into a standard OSAPI time
/// @param [in]  source - Copy from
/// @param [out] target - Copy to
/// @return Operation status
t_status common_time_copyNano		( int64_t seconds, uint64_t nano, t_time * target 	);

/// @brief Copy a C Standard time in nanoseconds into a standard OSAPI time
/// @param [in]  source - Copy from
/// @param [out] target - Copy to
/// @return Operation status
t_status common_time_copySpec		( const struct timespec * source, t_time * target 	);

/// @brief Perform a copy between two time types
/// @param [in] t1 	- The first time to compare
/// @param [in] t2 	- Second time to compare
/// @param [out] result - True if times are the same. False otherwise
/// @return Operation status
t_status common_time_equal		( const t_time * t1, const t_time * t2, bool * result	);

/// @brief Add two times: : result = t1 + t2
/// @param [in] t1 	- Time one
/// @param [in] t2 	- Time two
/// @param [out] result - Added time
/// @return Operation status
t_status common_time_add		( const t_time * t1, const t_time * t2, t_time * result	);

/// @brief Subtract times: result = t1 - t2
/// Both times must be in the same precision
/// @param [in] t1 	- Time one
/// @param [in] t2 	- Time two
/// @param [out] result - Result of time subtraction
/// @return Operation status
t_status common_time_sub		( const t_time * t1, const t_time * t2, t_time * result	);

/// @brief Obtain the precision from a fraction of a second
/// @param [in] nano - The nano second resolution field
/// @return Precision time enum
int common_time_getResolution		( uint32_t nano	);



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_TIME_H_ */
