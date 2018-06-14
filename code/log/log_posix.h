// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log module POSIX declarations
//
// *****************************************************************************************

#ifndef LOG_LOG_POSIX_H_
#define LOG_LOG_POSIX_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


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


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif	// End of POSIX declarations

#endif /* LOG_LOG_POSIX_H_ */
