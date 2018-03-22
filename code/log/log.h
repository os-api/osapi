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


t_status	log_module_supported		( void 						);
t_status	log_optionsPosix_set		( const char *, int, int, t_logGlobalOptions *	);
t_status	log_system_open			( t_logGlobalOptions 					);
t_status	log_system_close		( void						);
t_status	log_system_write		( t_logOptions, const char *			);


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif /* LOG_H_ */
