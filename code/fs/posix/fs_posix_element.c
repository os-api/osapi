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
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_element_exists( const t_char * p_path )
{
  t_status		st;
  struct stat		buffer;

  status_reset( & st );

  int rc = lstat( p_path, &buffer );
  if( rc == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}


t_status fs_element_open( const t_char * p_path, t_element * p_element )
{
  return posix_element_open( p_path, p_element );
}


t_status fs_element_updateInfo( t_element * p_element )
{
  t_status		st;

  status_reset( & st );

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( p_element->state != osapi_fs_ostate_opened )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st ); return st; }

  st = posix_get_element_info( p_element );

  return st;
}



t_status fs_element_getAtime( t_element * p_element, t_time * p_time )
{
 return posix_get_element_time( p_element, osapi_fs_time_access, p_time );
}

t_status fs_element_getCtime( t_element * p_element, t_time * p_time )
{
  return posix_get_element_time( p_element, osapi_fs_time_create, p_time );
}

t_status fs_element_getMtime( t_element * p_element, t_time * p_time )
{
  return posix_get_element_time( p_element, osapi_fs_time_modify, p_time );
}



#endif // POSIX only implementation
