// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a Linux implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System includes
// The following define forces the existence of an extended functionality
#define _GNU_SOURCE

#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_types.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "status/trace_macros.h"
#include "common/common.h"
#include "common/common_helper.h"

// Own declarations
#include "fs/fs.h"
#include "fs/fs_sysheaders.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OS_LINUX

t_status fs_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}


t_status internal_fs_element_getInfo( const t_char * p_path, int option, t_element * p_elem )
{
 t_status	st;
 struct stat	buf;
 struct statx	bufx;
 int		fd		= -1;
 unsigned int	selection	= 0;

 status_reset( & st );

 TRACE( "Entering with pathname (%s) and option (%d)", p_path, option )

 if( p_path == NULL || p_elem == NULL )
   { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

 if( LINUX_VERSION_CODE < KERNEL_VERSION(4,11,0) || OSAPI_LIBRARY_MAJOR_VERSION < 2 || OSAPI_LIBRARY_MINOR_VERSION < 28 )
   {
     TRACE_MSG( "Attempt to retrieve FS information using stat" )

     // Call the generic POSIX function
     errno = 0;
     if( stat( p_path, &buf ) == -1 )
       { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

     st = posix_decode_element_info( &buf, p_elem );
     return st;
   }

 // If already available, use Linux extended statx call
 switch( option )
       {
	 case osapi_fs_at_all:		selection = STATX_ALL; 		break;
	 case osapi_fs_at_exists:	selection = STATX_TYPE;		break;
	 case osapi_fs_at_type:		selection = STATX_TYPE;		break;
	 case osapi_fs_at_user:		selection = STATX_UID; 		break;
	 case osapi_fs_at_group:	selection = STATX_GID; 		break;
	 case osapi_fs_at_fsID:
	 case osapi_fs_at_elemID:
	 case osapi_fs_at_ID:		selection = STATX_INO; 		break;
	 case osapi_fs_at_AccessTime:	selection = STATX_ATIME;	break;
	 case osapi_fs_at_modTime:	selection = STATX_MTIME; 	break;
	 case osapi_fs_at_changeTime:	selection = STATX_CTIME;	break;
	 case osapi_fs_at_birthTime:	selection = STATX_BTIME;	break;
	 case osapi_fs_at_links:	selection = STATX_BLOCKS;	break;
	 case osapi_fs_at_size:		selection = STATX_SIZE;		break;

	 case osapi_fs_at_allTimes:	selection = STATX_ATIME | STATX_MTIME | STATX_CTIME | STATX_BTIME; break;

       }

 TRACE( "Attempt to retrieve FS information using statx for option:%d,%u", option, selection )

 // If pathname is not an absolute path, need to explicitly pass this information
 if( p_path[ 0 ] != '/' )     fd = AT_FDCWD;	// Relative to current working directory

 errno = 0;
 if( statx( fd, p_path, AT_STATX_SYNC_AS_STAT | AT_SYMLINK_NOFOLLOW, selection, &bufx ) == -1 )
   { status_eset( OSAPI_MODULE_FS, __func__, errno, &st ); return st; }

 st = linux_decode_element_info( &bufx, selection, p_elem );

 return st;
}


inline void internal_fs_element_reset( t_element * p_elem )
{
  if( p_elem == NULL )	return;

  // Set defaults
  p_elem->type		= osapi_fs_type_unknown;
  p_elem->nlink		= 0;
  p_elem->id.fsid.major = 0;
  p_elem->id.fsid.minor = 0;
  p_elem->size		= (uint64_t) 0;
  p_elem->block_size	= (uint32_t) 0;
  p_elem->compressed	= false;
  p_elem->encrypted	= false;

  common_time_reset( &p_elem->btime );
  common_time_reset( &p_elem->ctime );
  common_time_reset( &p_elem->mtime );
  common_time_reset( &p_elem->atime );
}



t_status linux_decode_element_info( struct statx * p_stat, unsigned int selection, t_element * p_info )
{
  t_status		st;
  uint32_t		sel = (uint32_t) selection;

  status_reset( & st );

  TRACE_ENTER

  if( p_stat == NULL || p_info == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  internal_fs_element_reset( p_info );

  TRACE( "Obtained information from system:%u", (unsigned int) p_stat->stx_mask )

  // If information returned was not what was requested, or more, return error
  if( sel != p_stat->stx_mask && p_stat->stx_mask != STATX_BASIC_STATS && p_stat->stx_mask != STATX_ALL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  // Transform a POSIX structure onto a generic one ( statx fields may have invalid information )
  p_info->type		= posix_element_getType( p_stat->stx_mode );
  p_info->uid		= p_stat->stx_uid;				// Only possible since it's also at POSIX level, otherwise uid_copy
  p_info->gid		= p_stat->stx_gid;				// Only possible since it's also at POSIX level, otherwise gid_copy
  p_info->nlink		= (uint64_t) p_stat->stx_nlink;
  p_info->id.fsid.major = unix_get_dev_major( p_stat->stx_dev_major );
  p_info->id.fsid.minor = unix_get_dev_minor( p_stat->stx_dev_minor );

  if( p_stat->stx_size    >= (uint64_t) 0 )			p_info->size = (uint64_t) p_stat->stx_size;
  if( p_stat->stx_blksize <  (uint64_t) 0 )			p_info->block_size = (uint32_t) p_stat->stx_blksize;
  if( p_stat->stx_attributes_mask & STATX_ATTR_COMPRESSED )	p_info->compressed = true;
  if( p_stat->stx_attributes_mask & STATX_ATTR_ENCRYPTED  )	p_info->encrypted  = true;

  // The time can be in several formats.. need to convert to the same one
  common_time_copyNano	( p_stat->stx_ctime.tv_sec, p_stat->stx_ctime.tv_nsec, &p_info->ctime );
  common_time_copyNano	( p_stat->stx_mtime.tv_sec, p_stat->stx_mtime.tv_nsec, &p_info->mtime );
  common_time_copyNano	( p_stat->stx_atime.tv_sec, p_stat->stx_atime.tv_nsec, &p_info->atime );
  common_time_copyNano	( p_stat->stx_btime.tv_sec, p_stat->stx_btime.tv_nsec, &p_info->btime );

  p_info->perm.mode = p_stat->stx_mode & ( S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO );

  TRACE_EXIT

  return st;
}



// Get from a list of directory entries, the type of an element for the given entry member
t_status fs_direntry_getType( t_dir_entry * p_entry, t_fs_eType * p_type )
{
  t_status		st;

  status_reset( & st );

  if( p_entry == NULL || p_type == NULL )
    { status_iset( OSAPI_MODULE_FS, __func__, osapi_fs_error_params, &st ); return st; }

  *p_type = osapi_fs_type_unknown;

  switch( p_entry->d_type )
	{
	  case DT_REG: *p_type = osapi_fs_type_file; 		break;
	  case DT_DIR: *p_type = osapi_fs_type_directory; 	break;
	  case DT_LNK: *p_type = osapi_fs_type_softLink;	break;
	  case DT_CHR: *p_type = osapi_fs_type_charDevice;	break;
	  case DT_BLK: *p_type = osapi_fs_type_blockDevice;	break;
	  case DT_FIFO:*p_type = osapi_fs_type_fifo;		break;
	  case DT_SOCK:*p_type = osapi_fs_type_socket;		break;
	}

  if( *p_type == osapi_fs_type_unknown )	// Some file systems may not support this, use another way
      st = fs_element_getType( p_entry->d_name, p_type );

  return st;
}



// Not part of POSIX
unsigned int unix_get_dev_major( dev_t dev )
{
  return major( dev );
}

// Not part of POSIX
unsigned unix_get_dev_minor( dev_t dev )
{
  return minor( dev );
}


#endif // Linux only implementation
