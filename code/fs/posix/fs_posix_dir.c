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
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_types.h"
#include "fs/fs_element.h"
#include "fs/fs_dir.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


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
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( strlen( p_path ) == 0 )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  p_dir->dir.state = osapi_fs_ostate_closed;

  st = fs_element_open( p_path, &p_dir->element );	// Get element information

  if( status_failure( st ) ) return st;

  if( isTypeNotDir( p_dir ) )
    {
      fs_element_close( &p_dir->element );		// Ignore return, best effort
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notDirectory, &st );
      return st;
    }

  // Attempt to open directory
  p_dir->dir.handle = opendir( p_path );
  if( isDirNull( p_dir ) )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  st = posix_get_directory_info( p_dir );		// Get directory specific information

  if( status_success( st ) )
      p_dir->dir.state = osapi_fs_ostate_opened;
  else
    {
      fs_element_close( &p_dir->element );		// Ignore return, best effort
      fs_dir_close( p_dir );
    }

  return st;
}


t_status fs_directory_getInfo( t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  if( p_dir == NULL )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( strlen( p_dir->element.fullpath ) == 0 )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( isDirNotOpen( p_dir ) )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
      return st;
    }

  st = fs_element_updateInfo( &( p_dir->element ) );		// First update general element information
  if( status_failure( st ) ) return st;

  st = posix_get_directory_info( p_dir );		// Next, update directory specific information

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
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( isDirNotOpen( p_dir ) )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
      return st;
    }

  struct dirent * p_entry = NULL;
  (*p_number) = 0;

  do {
       p_entry = readdir( p_dir->dir.handle );

       if( p_entry != NULL )
	   (*p_number)++;

     } while( p_entry != NULL );

  return st;
}

t_status fs_directory_getElements( t_dir * p_dir, t_list * p_list )
{
  t_status	st;
  t_size	count	= 0;
  t_size	cap	= 0;

  status_reset( & st );

  if( p_dir == NULL || p_list == NULL )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );
      return st;
    }

  if( is_list_not_allocated( p_list ) )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_noList, &st );
      return st;
    }

// Working here

  if( isDirNotOpen( p_dir ) )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st );
      return st;
    }

  st = common_list_getCapacity( p_list, &cap );

  if( status_failure( st) )	return st;

  if( cap == 0 )
    {
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_cap, &st );
      return st;
    }

  struct dirent * p_entry = NULL;

  do {
       p_entry = readdir( p_dir->dir.handle );

       if( p_entry != NULL )
	 {
	   //memcpy( (void *) &p_dirList[ count ], p_entry, sizeof( struct dirent ) );

	   st = common_list_copyTo( (void *) p_entry, sizeof( struct dirent ), count, p_list );
	   if( status_failure( st ) )
	       break;

	   count++;
	 }

     } while( p_entry != NULL && cap > count );

  set_list_size( p_list, count );
  set_list_requiredCapacity( p_list, count );

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
      if( closedir( p_dir->dir.handle ) == -1 )
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
      else
	{
	  p_dir->dir.handle = NULL;
	  p_dir->dir.state = osapi_fs_ostate_closed;
	  st = fs_element_close( &p_dir->element );
	}
    }

  return st;
}



#endif // POSIX only implementation
