// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Calendar time API
//
// *****************************************************************************************

#ifndef CLOCK_H_
#define CLOCK_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C"
  {
#endif

#include <status/status_types.h>
#include <clock/clock_types.h>
#include <clock/clock_platform.h>

#pragma GCC visibility push(default)		// Start of public interface

// There are three function types:

// - Time in seconds
t_status clock_module_supported (void);
t_status clock_time_set (t_time);
t_status clock_time_get (t_time *);
t_status clock_time_print (t_time, const char *);
t_status clock_time_diff (t_time, t_time, t_time *);

// - Time based for high frequency sampling
t_status clock_htTime_get (t_hrTime *);
t_status clock_hrTime_print (t_hrTime, const char *);
t_status clock_hrTime_diff (t_hrTime, t_hrTime, t_hrTime *);

// - Clock based - Full time/date/time zone capabilities
t_status clock_localTime_get (t_clock *);
t_status clock_timeZone_set (t_clock *);
t_status clock_timeZone_get (t_clock *);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* CLOCK_H_ */
