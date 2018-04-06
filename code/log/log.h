/*
 * log.h
 *
 *  Created on: 20/03/2018
 *      Author: joao
 */

#ifndef LOG_H_
#define LOG_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <status/status.h>
#include <log/log_defs.h>
#include <log/log_platform.h>


t_status	log_module_supported	( void 							);
t_status	log_system_open		( t_log		 					);
t_status	log_system_close	( t_log							);
t_status	log_system_write	( t_log, t_log_level, t_log_message			);

// Utility functions
t_status	log_debug_write		( t_log, t_log_message					);
t_status	log_info_write		( t_log, t_log_message					);
t_status	log_warning_write	( t_log, t_log_message					);
t_status	log_error_write		( t_log, t_log_message					);
t_status	log_fatal_write		( t_log, t_log_message					);



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif /* LOG_H_ */
