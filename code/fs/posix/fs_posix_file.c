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
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/fs_file.h"
#include "fs/fs_dir.h"
#include "fs/fs_sysheaders.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX




t_status fs_file_open( const t_char * p_path, const char ** p_mode, t_file * p_file )
{
  return posix_file_open( p_path, p_mode, p_file );
}


t_status fs_file_openRead( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "r", p_file );
}

t_status fs_file_openWrite( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "w", p_file );
}

t_status fs_file_openReadWrite( const t_char * p_path, t_file * p_file )
{
  return posix_open_filestream( p_path, "r+", p_file );
}


t_status fs_file_setPosition( const t_file * p_file, int initial, t_offset offset )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }


  int64_t rc	= 0;
  errno		= 0;

  if( p_file->file.isBuffered )
      rc = (int64_t) fseek( p_file->file.handle, (long) offset, initial );
  else
      rc = (int64_t) lseek( p_file->file.descriptor, (long) offset, initial );

  if( rc != (int64_t) -1 || errno != 0 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  return st;
}



t_status fs_file_create( const char * p_path, const char ** p_mode )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  mode_t modeOptions = (mode_t) posix_get_fs_mode_options( p_mode );

  int fd = open( p_path, O_CREAT | O_EXCL | O_RDONLY, modeOptions );	// If file already exists, fail with error

  if( fd == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( close( fd ) == -1 )	// Should we care about close error?
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  return st;
}



t_status fs_file_close( t_file * p_file )
{
  return fs_file_close( p_file );
}


t_status fs_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  return fs_file_read( p_file, p_buffer, p_eof );
}



t_status fs_file_write( const t_file * p_file, t_buffer * p_buffer )
{
  return posix_file_write( p_file, p_buffer );
}


/*
t_status fs_file_copy( const t_char * p_source, const t_char * p_target )
{
  return posix_file_copy( p_source, p_target );
}
*/

// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************


t_status posix_file_open( const t_char * p_path, const char ** p_mode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_mode == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = posix_element_open( p_path, &p_file->element );	// Open Element

  if( status_failure( st ) ) return st;

  int64_t openOptions = posix_get_fs_open_options( p_mode );
  int64_t modeOptions = posix_get_fs_mode_options( p_mode );

  st = posix_open_file( p_path, openOptions, modeOptions,  p_file );

  return st;
}


t_status posix_file_close( t_file * p_file )
{
  t_status	st;
  int		rc;

  status_reset( & st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  rc	= 0;
  errno	= 0;

  if( p_file->file.isBuffered )
      fclose( p_file->file.handle );
  else
      rc = close( p_file->file.descriptor );

  if( rc == -1 || errno != 0 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
      p_file->file.state	= osapi_fs_ostate_closed;

      st = fs_element_close( &p_file->element );
    }

  return st;
}


t_status posix_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL || p_eof == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size cap = (t_size) 0;
  void * p_data = NULL;

  st = common_buffer_getData( p_buffer, &p_data );
  if( status_failure( st ) ) return st;

  st = common_buffer_getCapacity( p_buffer, &cap );
  if( status_failure( st ) ) return st;

  int64_t sz	= 0;
  errno		= 0;

  if( p_file->file.isBuffered )
      sz = (int64_t) fread( p_data, (size_t) 1, (size_t) cap, p_file->file.handle );
  else
      sz = (int64_t) read( p_file->file.descriptor, p_data, (size_t) cap );

  if( sz == (int64_t) -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( sz == (ssize_t) 0 ) *p_eof = true;			// EOF reached
      st = common_buffer_setSize( (t_size) sz, p_buffer );
    }

  return st;
}


t_status posix_file_write( const t_file * p_file, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( p_file == NULL || p_buffer == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size current = (t_size) 0;
  void * p_data = NULL;

  st = common_buffer_getData( p_buffer, &p_data );
  if( status_failure( st ) ) return st;

  st = common_buffer_getSize( p_buffer, &current );
  if( status_failure( st ) ) return st;

  errno 	= 0;
  int64_t sz	= 0;

  if( p_file->file.isBuffered )
      sz = (int64_t) fwrite( p_data, (size_t) 1, (size_t) current, p_file->file.handle );
  else
      sz = (int64_t) write( p_file->file.descriptor, p_data, (size_t) current );

  if( sz == (int64_t) -1 || (sz == (int64_t) 0 && errno != 0) )
    {
      fprintf( stderr, "P1:%d,%p; %ld,%d,%ld", p_file->file.descriptor, p_file->file.handle, sz, errno, current );
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }
  else
      st = common_buffer_setSize( (t_size) sz, p_buffer );

  return st;
}


t_status posix_open_file( const t_char * p_path, int64_t openMode, int64_t creationMode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_aopen, &st ); return st; }

  p_file->file.state = osapi_fs_ostate_closed;

  p_file->file.descriptor = open( p_path, (int) openMode, (int) creationMode );
  if( p_file->file.descriptor < 0 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  st = posix_get_file_info( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;

  return st;
}

t_status posix_open_filestream( const t_char * p_path, const char * p_options, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  if( p_path == NULL || p_options == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 || strlen( p_options ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_aopen, &st ); return st; }

  p_file->file.state = osapi_fs_ostate_closed;

  st = posix_element_open( p_path, &p_file->element );	// Open Element

  if( status_failure( st ) ) return st;

  p_file->file.handle = fopen( p_path, p_options );

  if( p_file->file.handle == NULL )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  int fd = fileno( p_file->file.handle );
  if( fd == -1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  p_file->file.descriptor = fd;

  st = posix_get_file_info( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;
  else
    {
      fclose( p_file->file.handle );		// Attempt to close file, ignore result
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
    }

  return st;
}

t_status posix_get_file_info( t_file * p_file )
{
  t_status		st;

  status_reset( &st );

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Any directory specific information
  if( isTypeNotFile( p_file ) )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notFile, &st );
  // else...

  return st;
}

/*
t_status posix_file_copy( const t_char * p_source, const t_char * p_target )
{
  t_status		st;
  t_file		file;
  t_dir			dir;
  const char 	*	fileOptions[] = { "O_RDONLY", NULL };

  status_reset( &st );

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = posix_file_open( p_source, fileOptions, &file );
  if( status_success( st) )
    {
      st = fs_directory_open( p_target, &dir );
      if( status_success( st) )
	{
	  // Get file size

	  // Attempt to allocate memory for the file size if size <= OSAPI_FS_FILE_BUFFER_MAXSIZE
	  // Otherwise, allocate only OSAPI_FS_FILE_BUFFER_MAXSIZE

	  // In a cycle, read and write using the copy block size


	  st = fs_directory_close( &dir );
	}

      st = posix_file_close( &file );
    }


  return st;
}

*/


#endif // POSIX only implementation
