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
#include "status/trace_macros.h"
#include "common/common.h"
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_types.h"
#include "fs/fs_element.h"
#include "fs/fs_dir.h"
#include "fs/fs_direntry.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_directory_open( const t_char * p_path, t_dir * p_dir )
{
  return posix_directory_open( p_path, p_dir );
}


t_status fs_directory_updateInfo( t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_dir == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_dir->element.fullpath ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isDirNotOpen( p_dir ) || isDirNotAvailable( p_dir ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st ); return st; }

  st = fs_element_updateInfo( &( p_dir->element ) );		// First update general element information
  if( status_failure( st ) ) return st;

  st = posix_directory_getInfo( p_dir );		// Next, update directory specific information

  TRACE_EXIT

  return st;
}



t_status fs_directory_create( const t_char * p_path, const char ** mode )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( mkdir( p_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  TRACE_EXIT

  return st;
}


t_status fs_directory_getNumberElements( t_dir * p_dir, t_size * p_number )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_dir == NULL || p_number == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isDirNotOpen( p_dir ) || isDirNotAvailable( p_dir ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st ); return st; }

  struct dirent * p_entry = NULL;
  (*p_number) = 0;

  rewinddir( p_dir->dir.handle );	// Position in the begin on the directory stream

  do {
       p_entry = readdir( p_dir->dir.handle );

       if( p_entry != NULL )  (*p_number)++;

     } while( p_entry != NULL );

  TRACE_EXIT

  return st;
}

t_status fs_directory_getElementList( t_dir * p_dir, t_list * p_list )
{
  t_status	st;
  t_size	count	= 0;
  t_size	cap	= 0;

  status_reset( & st );

  TRACE_ENTER

  if( p_dir == NULL || p_list == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isDirNotOpen( p_dir ) || isDirNotAvailable( p_dir ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_dopen, &st ); return st; }

  if( is_list_not_allocated( p_list ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_noList, &st ); return st; }

  cap = get_list_capacity( p_list );	// Use macro since it was tested before that the list is allocated

  if( cap == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_cap, &st ); return st; }

  rewinddir( p_dir->dir.handle );	// Position in the begin on the directory stream

  struct dirent * p_entry = NULL;

  do {
       errno = 0;
       p_entry = readdir( p_dir->dir.handle );

       if( p_entry == NULL && errno != 0 )
	 { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

       if( p_entry == NULL ) break;

       st = common_list_copyTo( (void *) p_entry, sizeof( struct dirent ), (t_size) count + 1, p_list );

       if( status_failure( st ) )  break;

       count++;

     } while( cap > count );

  set_list_requiredCapacity( p_list, count );
  set_list_size( p_list, count );

  TRACE_EXIT

  return st;
}

t_status fs_directory_close( t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

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

  TRACE_EXIT

  return st;
}



t_status fs_directory_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  return posix_directory_copy( p_source, p_target, overwrite );
}


t_status fs_direntry_getName ( const t_dir_entry * p_entry, t_size nameSize, t_char * p_name )
{
  t_status		st;
  t_size		size = 0;

  status_reset( & st );

  TRACE_ENTER

  if( p_entry == NULL || p_name == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  size = strlen( p_entry->d_name ) + 1;	// Make sure we copy the C-String terminator
  if( size == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( nameSize < size )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  strncpy( p_name, p_entry->d_name, size );

  TRACE_EXIT

  return st;
}



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************


t_status posix_directory_open( const t_char * p_path, t_dir * p_dir )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_dir == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

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
  if( isDirNotAvailable( p_dir ) )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  st = posix_directory_getInfo( p_dir );		// Get directory specific information

  if( status_success( st ) )
      p_dir->dir.state = osapi_fs_ostate_opened;
  else
    {
      fs_element_close( &p_dir->element );		// Ignore return, best effort
      fs_directory_close( p_dir );
    }

  TRACE_EXIT

  return st;
}


t_status posix_directory_getInfo( t_dir * p_dir )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_dir == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any directory specific information
  if( isTypeNotDir( p_dir ) )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notDirectory, &st );
  // else...

  TRACE_EXIT

  return st;
}


t_status posix_directory_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  t_status	st;
  t_dir		sDir, tDir;
  t_list	list;
  t_size	nElems		= 0;
  bool		equal		= false;

  status_reset( & st );

  // Unsupported until be able to test it
  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_support, &st );
  return st;

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Make sure that directories aren't the same, their IDs must be different
  st = fs_element_same( p_source, p_target, &equal );
  if( status_success( st ) && equal == true)
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elequal, &st ); return st; }

  // Target must be a directory and it must be possible to open it
  st = fs_directory_open( p_target, &tDir );
  if( status_failure( st ) ) return st;

  // Open the source directory
  st = fs_directory_open( p_source, &sDir );
  if( status_failure( st ) ) return st;

  // Get the list of elements
  st = fs_directory_getNumberElements( &sDir, &nElems );
  if( status_failure( st ) ) return st;

  st = common_list_allocate( nElems, sizeof(t_element), &list );
  if( status_failure( st ) ) return st;

  st = fs_directory_getElementList( &sDir, &list );

  if( status_success( st ) )
    {
      t_element * ptr = NULL;

      // Copy element by element into destination
      for( t_size i = 1; i <= get_list_size( (&list) ); i++ )
	 {
	   st = common_list_getData( &list, (t_size) i, (void **) &ptr );
	   if( status_success( st ) )
	       st = fs_element_copy( ptr->fullpath, p_target, true );

	   if( status_failure( st ) ) break;
	 }
    }

  common_list_deallocate( &list );

  TRACE_EXIT

  return st;
}


#endif // POSIX only implementation
