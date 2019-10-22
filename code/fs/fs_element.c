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
#include "fs/fs_file.h"
#include "fs/fs_link.h"
#include "fs/fs_dir.h"
#include "fs/fs_element.h"
#include "fs/sys/fs_internal.h"
#include "fs/fs_helper.h"

// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************

t_status fs_element_close( t_element * p_element )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_element == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      p_element->fullpath[ 0 ] = '\0';		// clear element path name
      p_element->state = osapi_fs_ostate_closed;
    }

  TRACE_EXIT

  return st;
}


t_status fs_element_remove( const char * p_path )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( remove( p_path ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  TRACE_EXIT

  return st;
}


t_status fs_element_getType( const t_char * p_path, t_fs_eType * p_type )
{
 t_status		st;
 t_element		elem;

 status_reset( & st );

 TRACE_ENTER

 if( p_path == NULL || p_type == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 if( strlen( p_path ) == 0 )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = internal_fs_element_getInfo( p_path, osapi_fs_at_type, &elem );

 *p_type = elem.type;

 TRACE_EXIT

 return st;
}


// Use t_buffer
t_status fs_element_getName( const char * p_path, char ** p_name )
{
  t_status		st;
  t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_name == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_name, &elem );

  *p_name = elem.fullpath;

  TRACE_EXIT

  return st;
}


t_status fs_element_getUID( const char * p_path, t_uid * p_uid )
{
  t_status		st;
  t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_uid == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_user, &elem );

  *p_uid = elem.uid;

  TRACE_EXIT

  return st;
}


t_status fs_element_getGID( const char * p_path, t_gid * p_gid )
{
  t_status		st;
  t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_gid == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_group, &elem );

  *p_gid = elem.gid;

  TRACE_EXIT

  return st;
}


t_status fs_element_getSize( const char * p_path, t_size * p_size )
{
  t_status		st;
  t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_size == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_size, &elem );

  *p_size = elem.size;

  TRACE_EXIT

  return st;
}




t_status fs_element_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  t_status		st;
  t_fs_eType		sType;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_source ) == 0 || strlen( p_target ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = fs_element_getType( p_source, &sType );
  if( status_failure( st ) ) return st;

  switch( sType )
        {
	  case osapi_fs_type_file:	st = fs_file_copy	( p_source, p_target, overwrite );	break;
	  case osapi_fs_type_directory:	st = fs_directory_copy	( p_source, p_target, overwrite );	break;
	  case osapi_fs_type_softLink:
	  case osapi_fs_type_hardLink:	st = fs_link_copy	( p_source, p_target, overwrite );	break;
	  default:			status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elcopy, &st );
        }

  TRACE_EXIT

  return st;
}



t_status fs_element_getCreationTime( const t_char * p_path, t_time * p_time )
{
  return internal_fs_element_getTime( p_path, osapi_fs_at_birthTime, p_time );
}


t_status fs_element_getAcessTime( const t_char * p_path, t_time * p_time )
{
 return internal_fs_element_getTime( p_path, osapi_fs_at_AccessTime, p_time );
}

t_status fs_element_getChangeTime( const t_char * p_path, t_time * p_time )
{
  return internal_fs_element_getTime( p_path, osapi_fs_at_changeTime, p_time );
}

t_status fs_element_getModificationTime( const t_char * p_path, t_time * p_time )
{
  return internal_fs_element_getTime( p_path, osapi_fs_at_modTime, p_time );
}




