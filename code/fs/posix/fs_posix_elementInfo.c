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
#include "fs/fs_elementInfo.h"
#include "fs/posix/fs_posix.h"
#include "fs/fs_helper.h"


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX




t_status fs_elementInfo_getID( const t_element * p_element, t_fs_eid * p_id )
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


t_status fs_elementInfo_getCreationTime( const t_element * p_element, t_time * p_time )
{
  return posix_elementInfo_getTime( p_element, osapi_fs_at_birthTime, p_time );
}


t_status fs_elementInfo_getAcessTime( const t_element * p_element, t_time * p_time )
{
 return posix_elementInfo_getTime( p_element, osapi_fs_at_AccessTime, p_time );
}

t_status fs_elementInfo_getChangeTime( const t_element * p_element, t_time * p_time )
{
  return posix_elementInfo_getTime( p_element, osapi_fs_at_changeTime, p_time );
}

t_status fs_elementInfo_getModificationTime( const t_element * p_element, t_time * p_time )
{
  return posix_elementInfo_getTime( p_element, osapi_fs_at_modTime, p_time );
}


t_status fs_elementInfo_getPermissions( const t_element * p_element, t_fs_perm * p_perm )
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



// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************




t_status posix_elementInfo_getTime( const t_element * p_element, int selector, t_time * p_time )
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
	  case osapi_fs_at_birthTime:	*p_time = p_element->btime; break;
	  case osapi_fs_at_changeTime:	*p_time = p_element->ctime; break;
	  case osapi_fs_at_modTime:	*p_time = p_element->mtime; break;
	  case osapi_fs_at_AccessTime:	*p_time = p_element->atime; break;
       }

 TRACE_EXIT

 return st;
}





#endif // POSIX only implementation
