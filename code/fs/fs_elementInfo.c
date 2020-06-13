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

// Include Standard headers
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "status/trace_macros.h"

// Own declarations
#include "fs/fs_elementInfo.h"
#include "fs/fs_helper.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************



t_status fs_elementInfo_getType( const t_element * p_info, int * p_type )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_type == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_type = (int) p_info->type;

  TRACE_EXIT

  return st;
}



t_status fs_elementInfo_getName( const t_element * p_info, char ** p_name )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_name == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      TRACE( "Obtain the file name from path:%s", p_info->fullpath )

      char * ptr = strrchr( p_info->fullpath, '/' );
      *p_name = ptr + 1;	// Doesn't support multibyte (needs to be fixed at a latter stage

      TRACE( "The element name is (%s)", *p_name )
    }

  TRACE_EXIT

  return st;
}


t_status fs_elementInfo_getPathname( const t_element * p_info, const char ** p_name )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_name == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_name = p_info->fullpath;

  TRACE_EXIT

  return st;
}


t_status fs_elementInfo_getDirName( const t_element * p_info, t_size size, char * p_dir )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_dir == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  const char * ptr = strrchr( p_info->fullpath, '/' );
  size_t len = strlen( p_info->fullpath ) - strlen( ptr );

  if( len >= size )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_strcpy, &st ); return st; }

  strncpy( p_dir, ptr + 1 , len );
  p_dir[ len + 1 ] = '\0';			// Ensure that it's null terminated

  TRACE_EXIT

  return st;
}


t_status fs_elementInfo_getUID( const t_element * p_info, t_uid * p_uid )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_uid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_uid = p_info->uid;

  TRACE_EXIT

  return st;
}


t_status fs_elementInfo_getGID( const t_element * p_info, t_gid * p_gid )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_gid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_gid = p_info->gid;

  TRACE_EXIT

  return st;
}


t_status fs_elementInfo_getSize( const t_element * p_info, t_size * p_size )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_info == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
      *p_size = p_info->size;

  TRACE_EXIT

  return st;
}


