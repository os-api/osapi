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

// System includes
#define _DEFAULT_SOURCE
  #include <unistd.h>
#undef _DEFAULT_SOURCE

#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_machine.h"
#include "status/status.h"

// Own declarations
#include "machine/machine.h"
#include "machine/machine_linux.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// Compile only if is a POSIX implementation
#ifdef OS_LINUX


t_status machine_host_setName( t_char * hostname )
{
  t_status	st;
  size_t	len = 0;

  status_reset( & st );

  if( hostname == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      len = strlen( hostname );

      if( sethostname( hostname, len ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}

// Domain name related calls

t_status machine_domain_getName( t_size maxlen, t_char * hostname )
{
  t_status	st;

  status_reset( & st );

  if( hostname == NULL || maxlen <= 0 )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      if( getdomainname( hostname, maxlen ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}

t_status machine_domain_setName( t_char * hostname )
{
  t_status	st;
  size_t	len = 0;

  status_reset( & st );

  if( hostname == NULL )
      status_iset( OSAPI_MODULE_MACHINE, __func__, e_machine_params, &st );
  else
    {
      errno = 0;
      len = strlen( hostname );

      if( setdomainname( hostname, len ) == -1 )			// Got error
	  status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st );
    }

  return st;
}


#endif	// If POSIX is defined
