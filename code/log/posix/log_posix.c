// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log module using a POSIX compliant implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Include System headers
#include <strings.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "log/log.h"
#include "error/modules/error_log.h"
#include "log/posix/log_posix.h"
#include "log/posix/log_posix_priv.h"


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Definition: Public functions

t_status log_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports syslog interface
}


t_status log_system_open( const char * source, const char * target, const char * options[], t_log * log )
{
  const char * targets[2];

  // Convert target from a single pointer to an array of pointers for usage in common_options_get call
  targets[0] = target;
  targets[1] = NULL;

  log->ident    = source;
  log->facility = (int) common_options_get( log_facility, (char **) targets );
  log->option   = (int) common_options_get( log_options,  (char **) options );

  openlog( log->ident, log->option, log->facility );

  RETURN_STATUS_SUCCESS;
}

t_status log_system_close( t_log log )
{
  closelog();

  RETURN_STATUS_SUCCESS;
}


inline t_status log_system_write( t_log log, t_log_level level, t_log_message message )
{
  syslog( level, "%s", message );

  // syslog doesn't return feedback about success or failure
  RETURN_STATUS_SUCCESS;
}

t_status log_debug_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}

t_status log_info_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


t_status log_warning_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


t_status log_error_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}


t_status log_fatal_write( t_log log, t_log_message message )
{
  return log_system_write( log, LOG_DEBUG, message );
}



#endif	// Conditional POSIX compilation
