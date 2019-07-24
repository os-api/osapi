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

// System includes

// The following two defines for force the existence of an extended functionality
#define _DEFAULT_SOURCE
#define _BSD_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <dirent.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_types.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common_list.h"
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
      st = fs_element_getTypeByName( p_entry->d_name, p_type );

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


#endif // POSIX only implementation
