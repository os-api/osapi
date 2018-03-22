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

// Support of syslog type of logging
t_status log_optionsPosix_set( const char * name, int myOption, int fac, t_logGlobalOptions * p_options )
{
  t_status	st;

  status_reset( & st );

  if( name == ((char *) 0) || p_options == ((t_logGlobalOptions *) 0) )
      status_iset( OSAPI_MODULE_LOG, __func__, e_log_params, &st );
  else
    {
      p_options->ident    = name;
      p_options->option   = myOption;
      p_options->facility = fac;
    }

  return st;
}



t_status log_system_open( t_logGlobalOptions options )
{
  openlog( options.ident, options.option, options.facility );

  RETURN_STATUS_SUCCESS;
}

t_status log_system_close( void )
{
  closelog();

  RETURN_STATUS_SUCCESS;
}


t_status log_system_write( t_logOptions level, const char * message )
{
  syslog( level, "%s", message );

  // syslog doesn't return feedback about success or failure
  RETURN_STATUS_SUCCESS;
}
