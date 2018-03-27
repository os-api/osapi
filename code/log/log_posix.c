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

t_status log_options_set( t_log_options options, t_log * p_log )
{
  t_status	st;

  status_reset( & st );

  if( p_log == ((t_log *) 0) )
      status_iset( OSAPI_MODULE_LOG, __func__, e_log_params, &st );
  else
    {
      p_log->options.name    	= options.name;
      p_log->options.facility	= options.facility;
      p_log->options.open	= options.open;
    }

  return st;
}



t_status log_system_open( t_log log )
{
  openlog( log.name, log.options.open, log.facility );

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
