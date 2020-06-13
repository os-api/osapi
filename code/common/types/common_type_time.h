// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a time type
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPE_TIME_H_
#define OSAPI_COMMON_TYPE_TIME_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>

// Import OSAPI headers

// Include own headers


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// @brief The enum represents the possible precisions of a clock
enum osapi_common_time_precision_E
{
    osapi_time_unspecified	= 0, 	///< Unspecified precision
    osapi_time_second		,  	///< Precision to the second
    osapi_time_tsecond		,  	///< Precision to the tens of a second
    osapi_time_hsecond		,  	///< Precision to the hundreds of a second
    osapi_time_milli		,  	///< Precision to the millisecond (10^3)
    osapi_time_tmilli		,  	///< Precision to the tens of a millisecond (10^4)
    osapi_time_hmilli		,  	///< Precision to the hundreds of a millisecond (10^5)
    osapi_time_micro		,  	///< Precision to the microsecond (10^6)
    osapi_time_tmicro		,  	///< Precision to the tens of a microsecond (10^7)
    osapi_time_hmicro		,  	///< Precision to the hundreds of a microsecond (10^8)
    osapi_time_nano		,  	///< Precision to the nanosecond  (10^9)
    osapi_time_tnano		,  	///< Precision to the tens of a nanosecond  (10^10)
    osapi_time_hnano		,  	///< Precision to the hundreds of a nanosecond  (10^11)
    osapi_time_pico		,  	///< Precision to the picosecond  (10^12)
    osapi_time_femto		,  	///< Precision to the femtosecond (10^15)
    osapi_time_atto		,  	///< Precision to the attosecond  (10^18)
    osapi_time_zepto		,  	///< Precision to the zeptosecond (10^21)
    osapi_time_yocto		,  	///< Precision to the yoctosecond (10^24)
    osapi_time_planck		,  	///< Theorical smallest precision possible (10^44) of a second

    osapi_time_minute		,  	///< Precision to the minute
    osapi_time_hour		  	///< Precision to the hour

};

typedef enum osapi_common_time_precision_E	t_time_precision;


/// Structure supporting a time date
struct osapi_time_S
{
      int64_t		seconds;    	///< Seconds since the Epoch (UNIX time)
      uint64_t		fraction;	///< Fraction of a second
      t_time_precision	precision;	///< Time resolution
};

typedef struct osapi_time_S	t_time;


#endif /* OSAPI_COMMON_TYPE_TIME_H_ */
