// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a clock type
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_TYPE_CLOCK_H_
#define OSAPI_CLOCK_TYPE_CLOCK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>

// Import OSAPI headers
#include "common/types/common_type_time.h"

// Include own headers


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


/// Structure supporting a time offset (from a standard time, for instance)
struct osapi_time_offset_S
{
      int64_t	seconds;    	///< Delta in seconds
      uint64_t	fraction;	///< Delta in fractions of a second (if delta is negative, the sign must be in the seconds)
};

typedef struct osapi_time_offset_S	t_time_offset;


/// Structure supporting a clock
struct osapi_clock_S
{
      t_time			value;    	///< Time value
      int			local;		///< Is time value a local time, if so it must have a time offset from Standard time
      t_time_offset		offset;    	///< Difference to the Standard Time
};

typedef struct osapi_clock_S	t_clock;



#endif /* OSAPI_CLOCK_TYPE_CLOCK_H_ */
