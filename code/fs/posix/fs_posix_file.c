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
#include "status/trace_macros.h"
#include "common/common.h"
#include "common/common_helper.h"

// Own declarations
#include "fs/fs_element.h"
#include "fs/fs_file.h"
#include "fs/fs_dir.h"
#include "fs/posix/fs_posix.h"
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
 t_status	st;
 bool		file_exists = false;

 status_reset( & st );

 TRACE_ENTER

 if( p_path == NULL || p_mode == NULL || p_file == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 if( strlen( p_path ) == 0 )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = fs_element_exists( p_path, &file_exists );
 if( status_failure( st ) ) return st;

 if( file_exists )
     st = posix_element_open( p_path, &p_file->element );	// Open Element
 else
   {
     // Was creation mode requested?
     if( ! posix_fs_findInMode( p_mode, "O_CREAT" ) )
       {
	 TRACE_MSG( "Error: File doesn't exist and creation mode was not requested" );
	 status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notCreateMode, &st );
	 return st;
       }
   }

 int64_t openOptions = posix_fs_getOpenOptions( p_mode );
 int64_t modeOptions = posix_fs_getModeOptions( p_mode );

 st = posix_file_open( p_path, openOptions, modeOptions,  p_file );

 TRACE_EXIT

 return st;
}

t_status fs_file_updateInfo( t_file * p_file )
{
 t_status	st;

 status_reset( & st );

 TRACE_ENTER

 if( p_file == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = fs_element_updateInfo( &(p_file->element) );
 if( status_success( st ) )
     st = posix_file_getInfo( p_file );

TRACE_EXIT

return st;
}

t_status fs_file_openRead( const t_char * p_path, t_file * p_file )
{
  return posix_file_openStream( p_path, "r", p_file );
}

t_status fs_file_openWrite( const t_char * p_path, t_file * p_file )
{
  return posix_file_openStream( p_path, "w", p_file );
}

t_status fs_file_openReadWrite( const t_char * p_path, t_file * p_file )
{
  return posix_file_openStream( p_path, "r+", p_file );
}


t_status fs_file_setPosition( const t_file * p_file, int initial, t_offset offset )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

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

  TRACE_EXIT

  return st;
}



t_status fs_file_create( const char * p_path, const char ** p_mode )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  mode_t modeOptions = (mode_t) posix_fs_getModeOptions( p_mode );

  int fd = open( p_path, O_CREAT | O_EXCL | O_RDONLY, modeOptions );	// If file already exists, fail with error

  if( fd == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( close( fd ) == -1 )	// Should we care about close error?
	  status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  TRACE_EXIT

  return st;
}



t_status fs_file_close( t_file * p_file )
{
  return posix_file_close( p_file );
}


t_status fs_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  return posix_file_read( p_file, p_buffer, p_eof );
}



t_status fs_file_write( const t_file * p_file, t_buffer * p_buffer )
{
  return posix_file_write( p_file, p_buffer );
}



t_status fs_file_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  return posix_file_copy( p_source, p_target, overwrite );
}


// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************


t_status posix_file_open( const t_char * p_path, int64_t openMode, int64_t creationMode, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_aopen, &st ); return st; }

  p_file->file.state = osapi_fs_ostate_closed;

  p_file->file.descriptor = open( p_path, (int) openMode, (int) creationMode );
  if( p_file->file.descriptor < 0 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  p_file->file.isBuffered = false;

  if( ! isElementOpen( p_file ) )	// In case the file didn't exist before
    {
      st = posix_element_open( p_path, &p_file->element );
      if( status_failure( st ) ) return st;
    }

  st = posix_file_getInfo( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;

  TRACE_EXIT

  return st;
}



t_status posix_file_openStream( const t_char * p_path, const char * p_options, t_file * p_file )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

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

  p_file->file.isBuffered = true;

  int fd = fileno( p_file->file.handle );
  if( fd == -1 )
    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

  p_file->file.descriptor = fd;

  st = posix_file_getInfo( p_file );
  if( status_success( st ) )
      p_file->file.state = osapi_fs_ostate_opened;
  else
    {
      fclose( p_file->file.handle );		// Attempt to close file, ignore result
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
    }

  TRACE_EXIT

  return st;
}



t_status posix_file_close( t_file * p_file )
{
  t_status	st;
  int		rc;

  status_reset( & st );

  TRACE_ENTER

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  rc	= 0;
  errno	= 0;

  if( p_file->file.isBuffered )
    {
      if( isFileAvailable( p_file ) )
	  fclose( p_file->file.handle );
    }
  else
    {
      if( isFileAvailable( p_file ) )
	  rc = close( p_file->file.descriptor );
    }

  if( rc == -1 || errno != 0 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      p_file->file.descriptor	= -1;
      p_file->file.handle	= NULL;
      p_file->file.state	= osapi_fs_ostate_closed;

      st = fs_element_close( &p_file->element );
    }

  TRACE_EXIT

  return st;
}


t_status posix_file_read( const t_file * p_file, t_buffer * p_buffer, bool * p_eof )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_file == NULL || p_buffer == NULL || p_eof == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size cap 	= get_buffer_capacity( p_buffer );
  void * p_data = get_buffer_address( p_buffer );

  int64_t sz	= 0;
  errno		= 0;

  TRACE( "File buffer size: %ld", cap )

  errno = 0;
  if( p_file->file.isBuffered )
    {
      sz = (int64_t) fread( p_data, (size_t) cap, (size_t) 1, p_file->file.handle );
      TRACE( "Read from unbuffered file:%ld (%d)", sz, errno )
    }
  else
    {
      sz = (int64_t) read( p_file->file.descriptor, p_data, (size_t) cap );
      TRACE( "Read from unbuffered file (%d):%ld (%d)", p_file->file.descriptor, sz, errno )
    }

  if( sz == (int64_t) -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
    {
      if( sz == 0 || sz < cap )
	{
	  *p_eof = true;			// EOF reached
	  TRACE_MSG( "EOF reached" )
	}

      st = common_buffer_setSize( (t_size) sz, p_buffer );
    }

  TRACE_EXIT

  return st;
}


t_status posix_file_write( const t_file * p_file, const t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_file == NULL || p_buffer == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_file ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  t_size current	= get_buffer_size	( p_buffer );
  void * p_data		= get_buffer_address	( p_buffer );

  errno 	= 0;
  int64_t sz	= 0;

  if( p_file->file.isBuffered )
    {
      sz = (int64_t) fwrite( p_data, (size_t) current, (size_t) 1, p_file->file.handle );
      TRACE( "Buffered write to file:%ld (%d)", sz, errno )
    }
  else
    {
      sz = (int64_t) write( p_file->file.descriptor, p_data, (size_t) current );
      TRACE( "Unbuffered write to file:%ld (%d)", sz, errno )
    }

  if( sz == (int64_t) -1 || (sz == (int64_t) 0 && errno != 0) )
    {
      TRACE( "%d,%p; %ld,%d,%ld", p_file->file.descriptor, p_file->file.handle, sz, errno, current );
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  TRACE_EXIT

  return st;
}




t_status posix_file_getInfo( t_file * p_file )
{
  t_status		st;

  status_reset( &st );

  TRACE_ENTER

  if( p_file == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  TRACE("Type:%d", p_file->element.type );

  // Any directory specific information
  if( isTypeNotFile( p_file ) )
      status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_notFile, &st );

  // File operations block size set with the File system block size (initialized)
  p_file->file.block_size = p_file->element.block_size;

  TRACE_EXIT

  return st;
}



t_status posix_file_copy( const t_char * p_source, const t_char * p_target, bool overwrite )
{
  t_status		st;
  t_file		sFile;
  t_fs_eType		dtype;

  status_reset( &st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = fs_element_getType( p_target, &dtype );

  // If getting the type of the copy target results in error, this is fine as long as the error is that there is no target
  if( status_failure( st ) && ! status_error( st, ENOENT ) )
    {
      TRACE( "Error found when getting the file destination target type:%d", st.code )
      return st;
    }

  if( status_error( st, ENOENT ) )
    {
      TRACE_MSG(" Destination doesn't exist, file is intended" )
      dtype = osapi_fs_type_file;
    }
  else
    {
      TRACE( "Destination exist and is of type: %d", dtype )

      if( dtype != osapi_fs_type_file && dtype != osapi_fs_type_directory )
	{
	  TRACE_MSG( "Destination is not a file or directory" )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_invDest, &st );
	  return st;
	}

      if( dtype == osapi_fs_type_file && overwrite == false )
        {
	  TRACE_MSG( "Destination is a file and overwrite is set to false" )
	  status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fexists, &st );
	  return st;
        }
    }

  TRACE_MSG( "Opening source file" )

  st = posix_file_open( p_source, (int64_t) O_RDONLY, (int64_t) 0, &sFile );
  if( status_failure( st ) ) return st;

  switch( dtype )
	{
	  case osapi_fs_type_file:	st = posix_file_copy2file( &sFile, p_target, overwrite );
					break;
	  case osapi_fs_type_directory:	st = posix_file_copy2dir ( &sFile, p_target, overwrite );
					break;
	  default:			TRACE_MSG( "Unknown destination type" )
					status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fexists, &st );
	}

  posix_file_close( &sFile );

  TRACE_EXIT

  return st;
}


t_status posix_file_copy2file( t_file * p_sFile, const t_char * p_target, bool overwrite )
{
  t_status		st;
  t_file		tFile;
  t_buffer		buffer;
  bool			eof = false;

  status_reset( &st );

  TRACE_ENTER

  if( p_sFile == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileClose( p_sFile ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  int64_t mode  = (int64_t) posix_getElementPermMode( p_sFile );
  int64_t flags = (int64_t) O_WRONLY | O_CREAT;

  if( overwrite )	flags |= O_TRUNC;
  else			flags |= O_EXCL;

  // Open target file
  st = posix_file_open( p_target, flags, (int64_t) mode , &tFile );
  if( status_failure( st ) )
    {
      TRACE_EXIT
      return st;
    }

  // Allocate memory for copy bytes
  TRACE( "Allocating memory for copy buffer:%ld", p_sFile->file.block_size )
  st = common_buffer_allocate( p_sFile->file.block_size, &buffer );

  if( status_success( st ) )
    {
      do {

	   TRACE( "%s", "Preparing to read file" )
	   st = posix_file_read( p_sFile, &buffer, &eof );

	   if( status_success( st ) )
	     {
	       TRACE( "%s", "Writing file" )
	       st = posix_file_write( &tFile, &buffer );
	     }

         } while( status_success( st ) && ! eof );

      // Deallocate buffered memory
      common_buffer_deallocate( &buffer ); // Ignore return
    }

  // Finally close the target file, ignore return
  posix_file_close( &tFile );

  TRACE_EXIT

  return st;
}


t_status posix_file_copy2dir( t_file * p_sFile, const t_char * p_target, bool overwrite )
{
  t_status		st;
  t_dir			dir;
  char			path[ PATH_MAX + 1 ];

  status_reset( &st );

  TRACE_ENTER

  if( p_sFile == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( isFileNotOpen( p_sFile ) )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_fopen, &st ); return st; }

  st = posix_directory_open( p_target, &dir );

  if( status_success( st) )
    {
      // Make sure that the destination path (directory + file name) is a valid pathname
      char * ptr = strrchr( p_sFile->element.fullpath, (int) '/' );
      if( ptr == NULL )
	{ status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_locate, &st ); return st; }

      size_t filename_len = strlen( ptr );	// No need to test size 0, already done above

      if( (size_t) (filename_len + strlen( p_target )) > (size_t) (PATH_MAX - 2) )
	{ status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_pathsize, &st ); return st; }

      strncpy( path, p_target, PATH_MAX - filename_len - 1 );
      strcat ( path, "/" );
      strncat( path, ptr, PATH_MAX - filename_len );

      st = posix_file_copy2file( p_sFile, path, overwrite );

      fs_directory_close( &dir );
    }

  TRACE_EXIT

  return st;
}


#endif // POSIX only implementation
