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
#include "status/trace_macros.h"

// Own declarations
#include "fs/fs.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_path_getAbsolute( const t_char * p_source, t_size size, t_char * p_target )
{
  t_status		st;
  t_fs_eType		dtype;
  char			pathdir[ PATH_MAX ];

  status_reset( & st );

  TRACE( "Entering with source (%s) and target buffer size (%ld)", p_source, (unsigned long int) size )

  if( p_source == NULL || p_target == NULL || size == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Absolute path already even if not a real path
  if( p_source[ 0 ] == OSAPI_FS_PATH_SEPARATOR )
    {
      TRACE_MSG( "Path is already an absolute path.")
      strncpy( p_target, p_source, size );
      TRACE_EXIT
      return st;
    }

  // Relative path name
  p_target[ 0 ] = '\0';

  // Get the type of element
  st = fs_element_getType( p_source, &dtype );

  if( dtype != osapi_fs_type_softLink && dtype != osapi_fs_type_hardLink )
    {
      if( realpath( p_source, p_target ) != p_target )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

      TRACE( "Leaving with absolute path: %s", p_target )
      return st;
    }

  // Special handling due to specific behaviour of realpath regarding links

  TRACE_MSG( "Path is a link. Attempt to get absolute path.")

  if( getcwd( pathdir, PATH_MAX - 1 ) != pathdir )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  if( realpath( pathdir, p_target ) != p_target )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  if( strlen( p_source ) + strlen( pathdir ) > (size - 2) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_pathsize, &st ); return st; }
  else
    {
      strcat( p_target, OSAPI_FS_PATH_SEPARATOR_STRING );
      strcat( p_target, p_source );

      TRACE( "Leaving with absolute path: %s", p_target )
    }


  return st;
}


#endif // POSIX only implementation
