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

  st = get_element_info( p_element, &buffer );

  return st;
}


t_status fs_element_getInfo( const t_char * p_element, t_fs_elementInfo * p_info )
{
  t_status		st;
  struct stat		buffer;

  st = get_element_info( p_element, &buffer );

  if( status_success( st ) )
      st = decode_element_info( &buffer, p_info );

  return st;
}


t_status fs_elementInfo_getType( t_fs_elementInfo * p_info, int * p_type )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_type == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
      *p_type = p_info->type;

  return st;
}



t_status fs_elementInfo_getUID( t_fs_elementInfo * p_info, t_uid * p_uid )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_uid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
      *p_uid = p_info->uid;

  return st;
}


t_status fs_elementInfo_getGID( t_fs_elementInfo * p_info, t_gid * p_gid )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_gid == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
      *p_gid = p_info->gid;

  return st;
}


t_status fs_elementInfo_getSize( t_fs_elementInfo * p_info, t_size * p_size )
{
  t_status		st;

  status_reset( & st );

  if( p_info == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_e_params, &st );
  else
      *p_size = p_info->size;

  return st;
}


t_status fs_elementInfo_getAtime( t_fs_elementInfo * p_info, t_time * p_time )
{
 return get_element_time( p_info, osapi_fs_e_time_access, p_time );
}

t_status fs_elementInfo_getCtime( t_fs_elementInfo * p_info, t_time * p_time )
{
  return get_element_time( p_info, osapi_fs_e_time_create, p_time );
}

t_status fs_elementInfo_getMtime( t_fs_elementInfo * p_info, t_time * p_time )
{
  return get_element_time( p_info, osapi_fs_e_time_modify, p_time );
}



#endif // POSIX only implementation
