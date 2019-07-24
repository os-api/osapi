// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module implementation for dir elements
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common_list.h"
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/fs_direntry.h"
#include "fs/fs_dir.h"
#include "fs/fs_helper.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status fs_direntry_copy( const t_dir_entry * p_source, t_dir_entry * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  memcpy( (void *) p_target, (void *) p_source, sizeof( t_dir_entry ) );

  return st;
}

t_status fs_direntry_get( const t_list * p_list, t_size member, t_dir_entry * p_entry )
{
  t_status		st;
  t_size		maxListSize = 0;

  status_reset( & st );

  if( p_list == NULL || member == 0 || p_entry == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( is_list_not_allocated( p_list ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_noList, &st ); return st; }

  maxListSize = get_list_size( p_list );	// Use macro since it was tested before that the list is allocated

  if( maxListSize == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_cap, &st ); return st; }

  st = common_list_copyFrom( p_list, member, sizeof( struct dirent ), (void *) p_entry );

  return st;
}



