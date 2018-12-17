// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine module using a POSIX compliant implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <error/modules/error_machine.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "status/status.h"

// Own declarations
#include "machine/machine.h"
#include "machine/posix/machine_posix.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX



t_status machine_host_getName( t_size maxlen, t_char * hostname	)
{
  t_status	st;

  status_reset( & st );

  if( hostname == NULL || maxlen <= 0 )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      if( gethostname( hostname, maxlen ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}






#endif	// If POSIX is defined
