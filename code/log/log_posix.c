/*
 * proc_posix.c
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#include <error/error_log.h>

#include <log/log.h>
#include <log/log_posix.h>

t_status log_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports syslog interface
}


t_status log_system_open( t_log log )
{
  openlog( log.ident, log.option, log.facility );

  RETURN_STATUS_SUCCESS;
}

t_status log_system_close( t_log log )
{
  closelog();

  RETURN_STATUS_SUCCESS;
}


t_status log_system_write( t_log log, t_log_level level, t_log_message message )
{
  syslog( level, "%s", message );

  // syslog doesn't return feedback about success or failure
  RETURN_STATUS_SUCCESS;
}

inline t_status log_debug_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}

inline t_status log_info_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


inline t_status log_warning_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


inline t_status log_error_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


inline t_status log_fatal_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}

