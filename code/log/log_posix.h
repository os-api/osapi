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

struct s_log
{
 const char *			ident;
 int				option;
 int				facility;
};

typedef struct s_log		t_log;
typedef const char *		t_log_message;
typedef int			t_log_level;

// Macro section

#define	log_source(s,x)		x->ident=s
#define	log_options(o,x)	x->option=o
#define	log_facility(f,x)	x->facility=f

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* LOG_LOG_POSIX_H_ */
