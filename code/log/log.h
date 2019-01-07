// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide System Log module API
//
// *****************************************************************************************

#ifndef OSAPI_LOG_H_
#define OSAPI_LOG_H_

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


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup LOG
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Log module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @fn t_status ipc_module_supported( void )
/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status 	log_module_supported	( void 							);

/// @fn t_status log_system_open( const char * source, const char * target, const char * [] options, t_log * log )
/// @brief Opens a new system log defined by target and log options
/// @param in Source name, usually the current application name
/// @param in Target system log name, e.g. one of the UNIX facilities
/// @param in Options for the system log, array of C-Strings with name of option to pass to the system log service
/// @param out Log type
/// @return Operation status
t_status	log_system_open		( const char *, const char *, const char * [], t_log *	);

/// @fn t_status log_system_close( t_log )
/// @brief Closes the system log identified by <log>
/// @param out log type
/// @return Operation status
t_status	log_system_close	( t_log	log						);

/// @fn t_status log_system_write( t_log log, t_log_level level, t_log_message message )
/// @brief Writes a message to the system log (e.g. syslog, event service, etc.)
/// @param in log type
/// @param in log level
/// @param in message
/// @return Operation status
t_status	log_system_write	( t_log, t_log_level, t_log_message			);

// Utility functions

/// @fn t_status log_debug_write( t_log log, t_log_message message )
/// @brief Writes a message to the system log in DEBUG level
/// @param in log type
/// @param in message
/// @return Operation status
t_status	log_debug_write		( t_log, t_log_message	);

/// @fn t_status log_info_write( t_log log, t_log_message message )
/// @brief Writes a message to the system log in INFO level
/// @param in log type
/// @param in message
/// @return Operation status
t_status	log_info_write		( t_log, t_log_message	);

/// @fn t_status log_warning_write( t_log log, t_log_message message )
/// @brief Writes a message to the system log in WARNING level
/// @param in log type
/// @param in message
/// @return Operation status
t_status	log_warning_write	( t_log, t_log_message	);

/// @fn t_status log_error_write( t_log log, t_log_message message )
/// @brief Writes a message to the system log in ERROR level
/// @param in log type
/// @param in message
/// @return Operation status
t_status	log_error_write		( t_log, t_log_message	);

/// @fn t_status log_fatal_write( t_log log, t_log_message message )
/// @brief Writes a message to the system log in FATAL level
/// @param in log type
/// @param in message
/// @return Operation status
t_status	log_fatal_write		( t_log, t_log_message	);

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif /* OSAPI_LOG_H_ */
