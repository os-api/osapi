// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	POSIX compliant implementation for the File system identification functionality
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
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_sysheaders.h"
#include "fs/fs_helper.h"

// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_id_get( const t_char * p_path, t_fs_id * p_id )
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

  p_id->major = unix_get_dev_major( buffer.st_dev );
  p_id->minor = unix_get_dev_minor( buffer.st_dev );

  return st;
}



t_status fs_id_equal( t_fs_id * p_id1, t_fs_id * p_id2, bool * p_result )
{
  t_status	st;

  status_reset( & st );

  if( p_id1 == NULL || p_id2 == NULL || p_result == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  *p_result = false;
  if( p_id1->major == p_id2->major && p_id1->minor == p_id2->minor )
      *p_result = true;

  return st;
}


t_status fs_id_same( const t_char * p_path1, const t_char * p_path2, bool * p_result )
{
  t_status		st;
  t_fs_id		id1;
  t_fs_id		id2;

  status_reset( & st );

  st = fs_id_get( p_path1, &id1 );
  if( status_failure( st ) ) return st;

  st = fs_id_get( p_path2, &id1 );
  if( status_failure( st ) ) return st;

  st = fs_id_equal( &id1, &id2, p_result );

  return st;
}


t_status fs_id_copy( t_fs_id * p_source, t_fs_id * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  p_target->major = p_source->major;
  p_target->minor = p_source->minor;

  return st;
}



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************





#endif // POSIX only implementation
