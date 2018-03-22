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


struct s_logGlobalOptions
{
  const char * ident;
  int option;
  int facility;
};

typedef struct s_logGlobalOptions	t_logGlobalOptions;
typedef int				t_logOptions;



// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* LOG_LOG_POSIX_H_ */
