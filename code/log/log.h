// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide System Log module API
//
// *****************************************************************************************

#ifndef LOG_LOG_H_
#define LOG_LOG_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Generic OSAPI includes
#include "general/general_types.h"
#include "status/status_types.h"

// Own declarations
#include "log/log_types.h"
#include "log/log_platform.h"


// *****************************************************************************************
//
// Section: Log module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

t_status 	log_module_supported	( void 							);
t_status	log_system_open		( const char *, const char *, const char * [], t_log *	);
t_status	log_system_close	( t_log							);
t_status	log_system_write	( t_log, t_log_level, t_log_message			);

// Utility functions
t_status	log_debug_write		( t_log, t_log_message	);
t_status	log_info_write		( t_log, t_log_message	);
t_status	log_warning_write	( t_log, t_log_message	);
t_status	log_error_write		( t_log, t_log_message	);
t_status	log_fatal_write		( t_log, t_log_message	);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif /* LOG_LOG_H_ */
