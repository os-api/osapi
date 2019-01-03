// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log module POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_LOG_POSIX_H_
#define OSAPI_LOG_POSIX_H_


// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX

// System headers
#include <syslog.h>


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


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

#endif /* OSAPI_LOG_POSIX_H_ */
