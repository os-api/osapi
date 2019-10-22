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
#include "common/common.h"

// Own declarations
#include "fs/fs_id.h"
#include "fs/fs_element_id.h"
#include "fs/fs_element.h"
#include "fs/posix/fs_posix.h"
#include "fs/sys/fs_internal.h"
#include "fs/sys/fs_unix.h"
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
 t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL || p_result == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_exists, &elem );

  if( status_success( st ) )		*p_result = true;
  else
    {
      if( status_error(st, ENOENT ) )
	{
	  *p_result = false;
	  status_reset( & st );		// The failure is normal since the element doesn't exist, the operation succeeded
	}
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



t_status fs_element_getID( const t_char * p_path, t_fs_eid * p_id )
{
  t_status		st;
  t_element		elem;

  status_reset( & st );

  TRACE_ENTER

  if( p_path == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  st = internal_fs_element_getInfo( p_path, osapi_fs_at_ID, &elem );
  if( status_failure( st ) ) return st;

  p_id->fsid.major = elem.id.fsid.major;
  p_id->fsid.minor = elem.id.fsid.minor;
  p_id->eid = elem.id.eid;

  TRACE_EXIT

  return st;
}




t_status fs_element_getPermissions( const t_char * p_path, t_fs_perm * p_perm )
{
  return posix_element_getPermissions( p_path, p_perm );
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
  char		*	p_string;
  char			pathdir[ OSAPI_PATH_MAX + 1 ];

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

  // To replace by fs_path_getAbsolute

  // realpath follows the symlink (which is a problematic POSIX idiom)
  // Extra work for link elements
  else
    {
      if( p_path[ 0 ] == OSAPI_FS_PATH_SEPARATOR )	// Absolute path already even if not a real path
	  strcpy( p_element->fullpath, p_path );
      else	// Relative path name
	{
	  pathdir[ OSAPI_PATH_MAX ] = '\0';

	  if( getcwd( pathdir, OSAPI_PATH_MAX ) != pathdir )
	    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

	  if( realpath( pathdir, p_element->fullpath ) != p_element->fullpath )
	    { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

	  if( strlen( p_element->fullpath ) + strlen( p_path ) > OSAPI_PATH_MAX - 2 )
	    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_pathsize, &st ); return st; }
	  else
	    {
	      strcat( p_element->fullpath, OSAPI_FS_PATH_SEPARATOR_STRING );
	      strcat( p_element->fullpath, p_path );
	    }
	}
    }

  TRACE( "Element pathname is (%s)", p_element->fullpath )

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

  internal_fs_element_reset( p_info );

  // Transform a POSIX structure onto a generic one
  p_info->type	= posix_element_getType( p_stat->st_mode );
  p_info->uid	= p_stat->st_uid;				// Only possible since it's also at POSIX level, otherwise uid_copy
  p_info->gid	= p_stat->st_gid;				// Only possible since it's also at POSIX level, otherwise gid_copy
  p_info->nlink	= (uint64_t) p_stat->st_nlink;
  p_info->id.fsid.major = unix_get_dev_major( p_stat->st_dev );
  p_info->id.fsid.minor = unix_get_dev_minor( p_stat->st_dev );

  if( p_stat->st_size    > (uint64_t) 0 )	p_info->size 		= (uint64_t) p_stat->st_size;
  if( p_stat->st_blksize > (uint64_t) 0 )	p_info->block_size 	= (uint32_t) p_stat->st_blksize;

  // The time can be in several formats.. need to convert to the same one
  common_time_copySpec	( &p_stat->st_ctim , &p_info->ctime );
  common_time_copySpec	( &p_stat->st_atim , &p_info->mtime );
  common_time_copySpec	( &p_stat->st_mtim , &p_info->atime );
  common_time_reset	( &p_info->btime );

  p_info->perm.mode = p_stat->st_mode & ( S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO );

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


t_status posix_element_getPermissions( const t_char * p_path, t_fs_perm * p_perm )
{
 t_status		st;
 t_element		elem;

 status_reset( & st );

 TRACE_ENTER

 if( p_path == NULL || p_perm == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = internal_fs_element_getInfo( p_path, osapi_fs_at_perm, &elem );

 p_perm->mode = elem.perm.mode;

 TRACE( "Element Permissions: %d, %d", (int) p_perm->mode, (int) ((elem.perm.mode) & 7777) )

 TRACE_EXIT

 return st;
}



// *****************************************************************************************
//
// Section: Internal Function definition
//
// *****************************************************************************************


t_status internal_fs_element_getTime( const t_char * p_path, int selector, t_time * p_time )
{
 t_status		st;
 t_element		elem;

 status_reset( & st );

 TRACE_ENTER

 if( p_path == NULL || p_time == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 st = internal_fs_element_getInfo( p_path, osapi_fs_at_name, &elem );

 switch( selector )
       {
	  case osapi_fs_at_birthTime:	*p_time = elem.btime; break;
	  case osapi_fs_at_changeTime:	*p_time = elem.ctime; break;
	  case osapi_fs_at_modTime:	*p_time = elem.mtime; break;
	  case osapi_fs_at_AccessTime:	*p_time = elem.atime; break;
       }

 TRACE_EXIT

 return st;
}






#endif // POSIX only implementation
