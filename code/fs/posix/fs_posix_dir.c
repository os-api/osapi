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
#include "fs/fs_dir.h"
#include "fs/posix/fs_posix.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_directory_open( const t_char * p_path, t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_dir == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( strlen( p_path ) == 0 )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      else
	{
	  st = fs_element_getInfo( p_path, &( p_dir->info ) );		// First get general element information
	  if( status_success( st ) )
	    {
	      if( p_dir->info.type != osapi_fs_type_directory )
		  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notDirectory, &st );
	      else
		{
		  DIR * p_myDir = opendir( p_path );
		  if( p_myDir == NULL )
		      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
		  else
		    {
		      p_dir->state		= osapi_fs_ostate_opened;
		      p_dir->data.handle	= p_myDir;
		      st = posix_get_directory_info( p_path, &( p_dir->data) );
		    }
		}
	    }
	}
    }

  return st;
}


t_status fs_directory_getInfo( const t_char * p_path, t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_dir == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( strlen( p_path ) == 0 )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      else
	{
	  if( p_dir->state != osapi_fs_ostate_opened )
	      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
	  else
	    {
	      st = fs_element_getInfo( p_path, &( p_dir->info ) );		// First update general element information
	      if( status_success( st ) )
		{
		  if( p_dir->info.type != osapi_fs_type_directory )
		      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notDirectory, &st );
		  else
		      st = posix_get_directory_info( p_path, &(p_dir->data) );		// Next, update directory specific information
		}
	    }
	}
    }

  return st;
}



t_status fs_dir_create( const char * p_path, const char * mode )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {

      if( mkdir( p_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}


t_status fs_directory_getNumberElements( t_dir * p_dir, t_size * p_number )
{
  t_status	st;

  status_reset( & st );

  if( p_dir == NULL || p_number == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      (*p_number) = 0;
      if( p_dir->state != osapi_fs_ostate_opened )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
      else
	{
	  struct dirent * p_entry = NULL;

	  do {
	        p_entry = readdir( p_dir->data.handle );

	        if( p_entry != NULL )
	            (*p_number)++;

	      } while( p_entry != NULL );
	}
    }

  return st;
}

t_status fs_directory_getElements( t_dir * p_dir, t_size number, t_size * p_listSize, t_dir_entry * p_dirList )
{
  t_status	st;
  t_size	count = 0;

  status_reset( & st );

  if( p_dir == NULL || number == 0 || p_listSize == NULL || p_dirList == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( p_dir->state != osapi_fs_ostate_opened )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
      else
	{
	  struct dirent * p_entry = NULL;

	  do {
	        p_entry = readdir( p_dir->data.handle );

	        if( p_entry != NULL )
	          {
	            memcpy( (void *) &p_dirList[ count ], p_entry, sizeof( struct dirent ) );
	            count++;
	          }

	      } while( p_entry != NULL && number > count );
	}

      *p_listSize = count;
    }

  return st;
}

t_status fs_dir_close( t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  if( p_dir == NULL )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
  else
    {
      if( closedir( p_dir->data.handle ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	{
	  p_dir->data.handle = NULL;
	  p_dir->state = osapi_fs_ostate_closed;
	}
    }

  return st;
}



#endif // POSIX only implementation
