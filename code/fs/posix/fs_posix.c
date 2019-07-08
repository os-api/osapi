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
#include "fs/posix/fs_posix.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}

t_status fs_element_exists( const t_char * p_element )
{
  t_status		st;
  struct stat		buffer;

  st = posix_get_element_info( p_element, &buffer );

  return st;
}


t_status fs_element_getInfo( const t_char * p_element, t_fs_elementInfo * p_info )
{
  t_status		st;
  struct stat		buffer;

  st = posix_get_element_info( p_element, &buffer );

  if( status_success( st ) )
      st = posix_decode_element_info( &buffer, p_info );

  return st;
}




t_status fs_elementInfo_getAtime( t_fs_elementInfo * p_info, t_time * p_time )
{
 return posix_get_element_time( p_info, osapi_fs_time_access, p_time );
}

t_status fs_elementInfo_getCtime( t_fs_elementInfo * p_info, t_time * p_time )
{
  return posix_get_element_time( p_info, osapi_fs_time_create, p_time );
}

t_status fs_elementInfo_getMtime( t_fs_elementInfo * p_info, t_time * p_time )
{
  return posix_get_element_time( p_info, osapi_fs_time_modify, p_time );
}



#endif // POSIX only implementation
