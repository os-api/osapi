// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a POSIX compliant implementation
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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/fs.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_element_exists( const char * p_element )
{
  t_status		st;

  status_reset( & st );

  if( p_element == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, e_fs_params, &st );
  else
    {
      struct stat statbuf;
      int rc = lstat( p_element, &statbuf );
      if( rc == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;

}

#endif // POSIX only implementation
