// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module implementation for link elements
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/fs_link.h"
#include "fs/fs_helper.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************



t_status fs_link_close( t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_link == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      p_link->link.state = osapi_fs_ostate_closed;
      st = fs_element_close( &p_link->element );
    }

  return st;
}


t_status fs_link_getTarget( const t_link * p_link, const t_char ** p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_link == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isLinkNotOpen( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  if( isLinkNotAvailable( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  *p_target = p_link->link.target;

  return st;
}


t_status fs_link_getName( const t_link * p_link, const t_char ** p_name )
{
  t_status	st;

  status_reset( & st );

  if( p_link == NULL || p_name == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isLinkNotOpen( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  if( isLinkNotAvailable( p_link ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st ); return st; }

  *p_name = p_link->element.fullpath;

  return st;
}
