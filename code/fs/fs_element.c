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
#include "fs/fs_element.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status fs_element_remove( const char * p_path )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( remove( p_path ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}


t_status fs_elementInfo_getType( t_element * p_info, int * p_type )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_type == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_type = p_info->type;

  return st;
}


// Use t_buffer
t_status fs_element_getName( t_element * p_info, char ** p_name )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_name == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_name = p_info->name;

  return st;
}


t_status fs_element_getUID( t_element * p_info, t_uid * p_uid )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_uid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_uid = p_info->uid;

  return st;
}


t_status fs_element_getGID( t_element * p_info, t_gid * p_gid )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_gid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_gid = p_info->gid;

  return st;
}


t_status fs_element_getSize( t_element * p_info, t_size * p_size )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_size = p_info->size;

  return st;
}

