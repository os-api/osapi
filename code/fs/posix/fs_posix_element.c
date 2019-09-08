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
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_protocol.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "status/trace_macros.h"

// Own declarations
#include "fs/fs_id.h"
#include "fs/fs_element_id.h"
#include "fs/fs_element.h"
#include "fs/fs_sysheaders.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


t_status fs_element_exists( const t_char * p_path, bool * p_result )
{
 t_status		st;
 struct stat		buffer;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_result == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  errno = 0;
  if( lstat( p_path, &buffer ) != -1 )
      *p_result = true;
  else
    {
      if( errno == ENOENT )	*p_result = false;
      else	  		status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

  TRACE_EXIT

 return st;
}

t_status fs_element_getTypeByName( const t_char * p_path, t_fs_eType * p_type )
{
  t_status		st;
  char			errstr[ OSAPI_STATUS_STRING_SIZE + 1 ];
  struct stat		buffer;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_type == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_path ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  *p_type = osapi_fs_type_unknown;
  if( lstat( p_path, &buffer ) != -1 )
      *p_type = posix_element_getType( buffer.st_mode );
  else
    {
      strerror_r( errno, errstr, OSAPI_STATUS_STRING_SIZE );
      TRACE( "lstat function returned error: %s", errstr )

      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
    }

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

  st = fs_element_getTypeByName( p_source, &sType );
  if( status_failure( st ) ) return st;

  switch( sType )
        {
	  case osapi_fs_type_file:	st = posix_file_copy		( p_source, p_target, overwrite );	break;
	  case osapi_fs_type_directory:	st = posix_directory_copy	( p_source, p_target, overwrite );	break;
	  case osapi_fs_type_softLink:
	  case osapi_fs_type_hardLink:	st = posix_link_copy		( p_source, p_target, overwrite );	break;
	  default:			status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elcopy, &st );
        }

  TRACE_EXIT

  return st;
}


t_status fs_element_move( const t_char * p_source, const t_char * p_target )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( strlen( p_source ) == 0 || strlen( p_target ) == 0 )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Rename works accross filesystems ?
  if( rename( p_source, p_target ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );

  TRACE_EXIT

  return st;
}

t_status fs_element_same( const t_char * p_path1, const t_char * p_path2, bool * p_result )
{
  t_status		st;
  t_fs_eid		id1, id2;

  status_reset( & st );

  TRACE_ENTER

  // Get ID of first element
  st = fs_elementID_get( p_path1, &id1 );
  if( status_failure( st ) ) return st;

  // Get ID of second element
  st = fs_elementID_get( p_path2, &id2 );
  if( status_failure( st ) ) return st;

  // Check if IDs are equal
  st = fs_elementID_equal( &id1, &id2, p_result );

  TRACE_EXIT

  return st;
}



t_status fs_element_open( const t_char * p_path, t_element * p_element )
{
  return posix_element_open( p_path, p_element );
}


t_status fs_element_setPermissions( const char * p_path, t_fs_perm * p_perm )
{
  return posix_element_setPermissions( p_path, p_perm );
}


t_status fs_element_updateInfo( t_element * p_element )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( p_element->state != osapi_fs_ostate_opened )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st ); return st; }

  st = posix_element_getInfo( p_element );

  TRACE_EXIT

  return st;
}


t_status fs_element_getID( t_element * p_element, t_fs_eid * p_id )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  if( p_element->state != osapi_fs_ostate_opened )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st ); return st; }

  p_id->fsid.major = p_element->id.fsid.major;
  p_id->fsid.minor = p_element->id.fsid.minor;
  p_id->eid = p_element->id.eid;

  TRACE_EXIT

  return st;
}


t_status fs_element_getCreationTime( t_element * p_element, t_time * p_time )
{
  return posix_element_getTime( p_element, osapi_fs_time_create, p_time );
}


t_status fs_element_getAcessTime( t_element * p_element, t_time * p_time )
{
 return posix_element_getTime( p_element, osapi_fs_time_access, p_time );
}

t_status fs_element_getChangeTime( t_element * p_element, t_time * p_time )
{
  return posix_element_getTime( p_element, osapi_fs_time_change, p_time );
}

t_status fs_element_getModificationTime( t_element * p_element, t_time * p_time )
{
  return posix_element_getTime( p_element, osapi_fs_time_modify, p_time );
}


t_status fs_element_getPermissions( t_element * p_element, t_fs_perm * p_perm )
{
  return posix_element_getPermissions( p_element, p_perm );
}



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************



t_fs_eType posix_element_getType( mode_t m )
{
 t_fs_eType	tp = osapi_fs_type_unknown;

 TRACE_ENTER

 switch( m & S_IFMT)
       {
	  case S_IFREG: tp = osapi_fs_type_file;	break;
	  case S_IFDIR: tp = osapi_fs_type_directory;	break;
	  case S_IFLNK:	tp = osapi_fs_type_softLink;	break;
	  case S_IFCHR: tp = osapi_fs_type_charDevice;	break;
	  case S_IFBLK: tp = osapi_fs_type_blockDevice;	break;
	  case S_IFIFO: tp = osapi_fs_type_fifo;	break;
	  case S_IFSOCK:tp = osapi_fs_type_socket;	break;
       }

  TRACE( "Leaving with %d", tp )

  return tp;
}


t_status posix_element_open( const t_char * p_path, t_element * p_element )
{
  t_status		st;
  char		*	p_string;;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  p_element->state = osapi_fs_ostate_closed;

  strcpy( p_element->fullpath, p_path );

  st = posix_element_getInfo( p_element );

  if( status_success( st ) )
      p_element->state = osapi_fs_ostate_opened;

  if( isElementTypeNotLink( p_element ) )
    {
      p_string = realpath( p_path, p_element->fullpath );
      if( p_string != p_element->fullpath )
	  strcpy( p_element->fullpath, p_path );			// Make sure that there is always a path even if relative
    }

  TRACE_EXIT

  return st;
}


t_status posix_element_getInfo( t_element * p_element )
{
  t_status		st;
  struct stat		buffer;

  status_reset( & st );

  TRACE_ENTER

  if( p_element == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st );return st; }

  if( lstat( p_element->fullpath, &buffer ) == -1 )
      status_eset( OSAPI_MODULE_FS, __func__, errno, &st );
  else
      st = posix_decode_element_info( &buffer, p_element );

  TRACE_EXIT

  return st;
}


t_status posix_decode_element_info( const struct stat * p_stat, t_element * p_info )
{
  t_status		st;

  status_reset( & st );

  TRACE_ENTER

  if( p_stat == NULL || p_info == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Transform a POSIX structure onto a generic one
  p_info->type	= posix_element_getType( p_stat->st_mode );
  p_info->uid	= p_stat->st_uid;				// Only possible since it's also at POSIX level, otherwise uid_copy
  p_info->gid	= p_stat->st_gid;				// Only possible since it's also at POSIX level, otherwise gid_copy
  p_info->nlink	= (uint64_t) p_stat->st_nlink;
  p_info->id.fsid.major = unix_get_dev_major( p_stat->st_dev );
  p_info->id.fsid.minor = unix_get_dev_minor( p_stat->st_dev );

  // File size
  if( p_stat->st_size < (uint64_t) 0 )	p_info->size = (uint64_t) 0;
  else					p_info->size = (uint64_t) p_stat->st_size;

  // Block size
  if( p_stat->st_blksize < (uint64_t) 0 )	p_info->block_size = (uint32_t) 0;
  else						p_info->block_size = (uint32_t) p_stat->st_blksize;

  // The time can be in several formats.. need to convert to the same one
  //p_info->ctime	= p_stat->;

  p_info->perm.mode = p_stat->st_mode & ( S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO );

  TRACE_EXIT

  return st;
}



t_status posix_element_getTime( const t_element * p_element, int selector, t_time * p_time )
{
 t_status		st;

 status_reset( & st );

 TRACE_ENTER

 if( p_element == NULL || p_time == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 if( p_element->state != osapi_fs_ostate_opened )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_elopen, &st ); return st; }

 switch( selector )
       {
	  case osapi_fs_time_create:	*p_time = p_element->btime; break;
	  case osapi_fs_time_change:	*p_time = p_element->ctime; break;
	  case osapi_fs_time_modify:	*p_time = p_element->mtime; break;
	  case osapi_fs_time_access:	*p_time = p_element->atime; break;
       }

 TRACE_EXIT

 return st;
}


t_status posix_element_setPermissions( const char * p_path, t_fs_perm * p_perm )
{
 t_status		st;

 status_reset( & st );

 TRACE_ENTER

 if( p_path == NULL || p_perm == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }


// TODO


 TRACE_EXIT

 return st;
}


t_status posix_element_getPermissions( t_element * p_element, t_fs_perm * p_perm )
{
 t_status		st;

 status_reset( & st );

 TRACE_ENTER

 if( p_element == NULL || p_perm == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 p_perm->mode = p_element->perm.mode;

 TRACE( "Element Permissions: %d, %d", (int) p_perm->mode, (int) ((p_element->perm.mode) & 7777) )

 TRACE_EXIT

 return st;
}



#endif // POSIX only implementation
