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

t_status log_optionsWindows_set( t_log_windows options )
{
  t_status	st;

  // Unsupported function in POSIX
  status_iset( OSAPI_MODULE_LOG, __func__, e_log_support, &st );

  return st;
}

// Support of syslog type of logging
t_status log_optionsPosix_set( t_log_posix options , t_log * p_log )
{
  t_status	st;

  status_reset( & st );

  if( p_log == ((t_log *) 0) )
      status_iset( OSAPI_MODULE_LOG, __func__, e_log_params, &st );
  else
    {
      p_log->options    = options;
    }

  return st;
}

// Set Cross platform logging options
t_status log_options_set( t_log_name name, t_log_facility fac, t_log * p_log )
{
  t_status	st;

  status_reset( & st );

  if( name == ((char *) 0) || p_log == ((t_log *) 0) )
      status_iset( OSAPI_MODULE_LOG, __func__, e_log_params, &st );
  else
    {
      p_log->name    	= name;
      p_log->facility	= fac;
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
