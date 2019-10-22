// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a clock calendar type
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_TYPE_CALENDAR_H_
#define OSAPI_CLOCK_TYPE_CALENDAR_H_

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



/// @brief The enum represents the possible clock calendars
enum osapi_clock_e_calendar
{
    osapi_calendar_unspecified	= -1, 	///< Unspecified calendar, no way to give meaning to time
    osapi_calendar_ce		= 0,  	///< Common Era calendar (consider the Gregorian Calendar as if it was already available in the origin and not only in the 16 century)
    osapi_calendar_gregorian	,  	///< Gregorian Calendar (after October 1582)
    osapi_calendar_julian	,  	///< Julian Calendar
    osapi_calendar_mayan	,  	///< Mayan Calendar
    osapi_calendar_chinese	,  	///< Chinese Calendar
    osapi_calendar_roman	,  	///< Roman Calendar

    // Other calendars

};

typedef enum osapi_clock_e_calendar	t_calendar;





#endif /* OSAPI_CLOCK_TYPE_CALENDAR_H_ */
