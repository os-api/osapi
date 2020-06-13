#include "osapi.h"

int main( int argc, char * argv[] )
{
 t_log log;	// Define type opaque type

// My Client application name
 const char * source= "client";

// The following entries are specific to each platform
 const char * target    = "LOG_LOCAL0";				// UNIX facility
 const char * options[] = { "LOG_PID", "LOG_CONS", NULL };	// UNIX log options

 // Open the platform log
 log_system_open( source, target, options, &log );

 // Write to the system log in Info level
 log_info_write( log, "My log entry" );

 // Finally close the system log
 log_system_close( log );
}
