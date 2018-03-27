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
  char *	name;
  int		open;
  int		facility;
};

typedef const char *			t_log_name;
typedef const char *			t_log_message;
typedef struct s_options		t_log_options;
typedef int				t_log_facility;
typedef int				t_log_level;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* LOG_LOG_POSIX_H_ */
