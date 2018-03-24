/*
 * proc_posix.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef LOG_LOG_POSIX_H_
#define LOG_LOG_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#include <syslog.h>

struct s_options
{
  int		open;
};

typedef const char *			t_log_name;
typedef const char *			t_log_message;
typedef struct s_options		t_log_posix;		// POSIX only options
typedef int				t_log_windows;		// WINDOWS only options - Placeholder type
typedef int				t_log_facility;
typedef int				t_log_level;

// The generic type is an alias for the particular type
typedef t_log_posix			t_log_options;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* LOG_LOG_POSIX_H_ */
