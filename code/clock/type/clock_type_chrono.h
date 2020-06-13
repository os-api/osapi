// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define a chrono type
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_TYPE_CHRONO_H_
#define OSAPI_CLOCK_TYPE_CHRONO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>

// Import OSAPI headers
#include "general/general_defs.h"
#include "common/types/common_type_time.h"

// Include own headers


// *****************************************************************************************
//
// Section: Constants
//
// *****************************************************************************************

#define OSAPI_CLOCK_CHRONO_NONE		OSAPI_SANITY_NONE	// No time yet
#define OSAPI_CLOCK_CHRONO_STARTED	OSAPI_SANITY_BEGIN	// Start time available
#define OSAPI_CLOCK_CHRONO_STOPPED	OSAPI_SANITY_END	// Delta time available

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************



/// Structure supporting a chrono type
struct osapi_clock_chrono_S
{
      t_time		value;    	///< Time value
      uint8_t		magic;    	///< A magic constant to verify if there as a start before computing time deltas
};

typedef struct osapi_clock_chrono_S	t_chrono;





#endif /* OSAPI_CLOCK_TYPE_CHRONO_H_ */
