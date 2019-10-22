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
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/fs_id.h"
#include "fs/fs_element_id.h"
#include "fs/sys/fs_unix.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX




t_status fs_elementID_equal( t_fs_eid * p_id1, t_fs_eid * p_id2, bool * p_result )
{
  t_status		st;

  status_reset( & st );

  if( p_id1 == NULL || p_id2 == NULL || p_result == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = fs_id_equal( &(p_id1->fsid), &(p_id2->fsid), p_result );
  if( status_failure( st ) || *p_result == false ) return st;

  // If IDs are on the same file system, need to compare inode number next
  if( p_id1->eid == p_id2->eid ) *p_result = true;
  else				 *p_result = false;

  return st;
}


t_status fs_elementID_copy( t_fs_eid * p_source, t_fs_eid * p_target )
{
  t_status		st;

  status_reset( & st );

  if( p_source == NULL || p_target )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  p_target->fsid.major	= p_source->fsid.major;
  p_target->fsid.minor	= p_source->fsid.minor;
  p_target->eid 	= p_source->eid;

  return st;
}


t_status fs_elementID_get( const t_char * p_path, t_fs_eid * p_id )
{
  t_status		st;
  struct stat		buffer;

  status_reset( & st );

  if( p_path == NULL || p_id == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( lstat( p_path, &buffer ) == - 1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  // Get first the file system element id
  p_id->fsid.major = unix_get_dev_major( buffer.st_dev );
  p_id->fsid.minor = unix_get_dev_minor( buffer.st_dev );

  // Copy the ID inside the filesystem
  p_id->eid = buffer.st_ino;

  return st;
}




// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************




#endif // POSIX only implementation
