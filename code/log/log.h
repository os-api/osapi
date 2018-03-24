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

struct s_log
{
 t_log_name			name;
 t_log_options			options;
 t_log_facility			facility;
};

typedef struct s_log		t_log;


t_status	log_module_supported	( void 							);
t_status 	log_options_set		( t_log_name, t_log_facility, t_log *			);
t_status	log_posix_set		( t_log_posix,   t_log *				);
t_status	log_windows_set		( t_log_windows, t_log *				);
t_status	log_system_open		( t_log		 					);
t_status	log_system_close	( t_log							);
t_status	log_system_write	( t_log, t_log_level, t_log_message			);


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif /* LOG_H_ */
