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
#include "error/error_log.h"
#include "status/status.h"

// Own declarations
#include "log/log.h"
#include "log/log_posix.h"
#include "log/log_posix_priv.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Definition: Private functions
static int get_facility( const char * target )
{
 int	fac = 0;

 if( target != OSAPI_NULL_CHAR_POINTER )
   {
     for( int i=0; log_facility[ i ].facValue != OSAPI_LOG_END; i++ )
        {
          if( strcasecmp( target, log_facility[ i ].facName ) == 0 )
            {
              fac = log_facility[ i ].facValue;
              break;
            }
        }
   }

 return fac;
}

// Convert a set of string options into a single int option

static int get_option( const char * options[] )
{
 int	opt = 0;

 for( int i=0; options[ i ] != OSAPI_NULL_CHAR_POINTER; i++  )
   {
     for( int j=0; log_options[ j ].optionValue != OSAPI_LOG_END; j++ )
        {
	  // Compares current option[i] with list of all available options
          if( strcasecmp( options[ i ], log_options[ j ].optionName ) == 0 )
            {
              // Match found: Add option to the list (int/opt)
              opt |= log_options[ j ].optionValue;
              break;
            }
        }
   }

 return opt;
}


// Definition: Public functions

t_status log_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports syslog interface
}


t_status log_system_open( const char * source, const char * target, const char * options[], t_log * log )
{
  log->ident    = source;
  log->facility = get_facility( target  );
  log->option   = get_option  ( options );

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
