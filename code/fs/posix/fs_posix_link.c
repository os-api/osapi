// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a POSIX compliant implementation
//		for directory functionality
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
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_types.h"
#include "fs/fs_element.h"
#include "fs/fs_link.h"
#include "fs/posix/fs_posix.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_link_open( const t_char * p_path, t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_link == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( strlen( p_path ) == 0 )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      else
	{
	  st = fs_element_getInfo( p_path, &( p_link->info ) );		// First get general element information
	  if( status_success( st ) )
	    {
	      if( p_link->info.type != osapi_fs_type_softLink || p_link->info.type != osapi_fs_type_hardLink )
		  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st );
	      else
		{

		}
	    }
	}
    }

  return st;
}


t_status fs_link_getInfo( const t_char * p_path, t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_link == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( strlen( p_path ) == 0 )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      else
	{
	  if( p_link->state != osapi_fs_ostate_opened )
	      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
	  else
	    {
	      st = fs_element_getInfo( p_path, &( p_link->info ) );		// First update general element information
	      if( status_success( st ) )
		{
		  if( p_link->info.type != osapi_fs_type_directory )
		      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notLink, &st );
		  else
		      st = posix_get_link_info( p_path, &(p_link->data) );		// Next, update directory specific information
		}
	    }
	}
    }

  return st;
}



t_status fs_link_createSoft( const t_char * p_source, const t_char * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( symlink( p_target, p_source ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}


t_status fs_link_createHard( const t_char * p_source, const t_char * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( link( p_target, p_source ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}


t_status fs_link_close( t_link * p_link )
{
  t_status	st;

  status_reset( & st );

  if( p_link == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      /*
      if( closedir( p_link->data.handle ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	{
	  p_dir->data.handle = NULL;
	  p_dir->state = osapi_fs_ostate_closed;
	}
	*/
    }

  return st;
}



#endif // POSIX only implementation
