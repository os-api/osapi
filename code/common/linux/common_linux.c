// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module Linux implementation
//
// *****************************************************************************************

#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/sysinfo.h>

// Declare Linux/BSD specific function to avoid symbols definitions
extern int getgrouplist(const char *, gid_t, gid_t *, int * );

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_common.h"
#include "status/status.h"

// Own declarations
#include "common/common.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status get_max_length_groupname( t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
      *p_size = 32;		// Apparently this is the maximum size of a group name.. requires confirmation

  return st;
}

t_status get_user_group_list( t_uid uid, size_t groupListMaxSize, size_t * p_groupListCurSize, t_gid *  p_groupList )
{
  t_status st;

  status_reset( &st );

  if( p_groupList == ((t_gid *) 0) || groupListMaxSize <= 0 || p_groupListCurSize == (size_t *) 0 )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      // First get primary GID matching uid
      t_gid gid;
      st = get_primaryGroupID( uid, &gid );

      if( status_success( st ) )
	{
	  // Second get the maximum size of a username
	  size_t username_size = 0;
	  st = get_max_length_username( &username_size );
	  if( status_success( st ) )
	    {
	      // Allocate memory to store username
	      char * username = (char *) malloc( username_size );

	      // Third, map uid to a name
	      st = get_username_from_id( uid, username_size, username );
	      if( status_success( st) )
		{
		  // The ngroups in the getgrouplist function bellow is an in-out parameter
		  // In - the max size of the Group List
		  // Out - The number of groups found, this parameter can be greater than the input if
		  //       the number of groups found in the system exceeds the initial assumed max number of groups
		  // We assume that the max group size passed in the functions is big enough to old all group IDs,
		  // otherwise this function returns an error (since we can't reside the list)

		  int ngroups = (int) groupListMaxSize;	// Number of returned groups
		  errno = 0;

		  if( getgrouplist( username, gid, p_groupList, &ngroups ) == -1 )
		      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
		  else
		      *p_groupListCurSize = (size_t) ngroups;
		}
	    }
	}
    }

  return st;
}

t_status common_cpu_getAvailable( t_cpu_nlogical * p_ncpus )
{
 t_status	 st;

 status_reset( & st );

 if( p_ncpus == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st ); return st; }

 int np = get_nprocs();
 if( np == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 *p_ncpus = (t_cpu_nlogical) np;

 return st;
}

t_status common_cpu_getPresent( t_cpu_nlogical * p_ncpus )
{
 t_status	 st;

 status_reset( & st );

 if( p_ncpus == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st ); return st; }

 int np = get_nprocs_conf();
 if( np == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 *p_ncpus = (t_cpu_nlogical) np;

 return st;
}


// Not yet implemented
t_status common_cpu_getMax( t_cpu_nlogical * p_ncpus )
{
  t_status st;

  // RETURN_STATUS_SUCCESS;
  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st);

  return st;
}



t_status common_memory_getPageSize( uint32_t * p_size )
{
 t_status	 st;

 status_reset( & st );

 if( p_size == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st ); return st; }

 long sz = sysconf( OSAPI_COMMON_PAGESIZE );
 if( sz == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 *p_size = (uint32_t) sz;

 return st;
}


t_status common_memory_getNumberOfPages( uint32_t * p_number )
{
 t_status	 st;

 status_reset( & st );

 if( p_number == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st ); return st; }

 long sz = sysconf( _SC_PHYS_PAGES );
 if( sz == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 *p_number = (uint32_t) sz;

 return st;
}


// The implementation of this call is more efficient if done at the specific OS level
t_status common_memory_getMax( uint64_t * p_size )
{
 t_status	 st;

 status_reset( & st );

 if( p_size == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_error_params, &st ); return st; }

 long pages = sysconf( _SC_AVPHYS_PAGES );
 if( pages == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 long pagesize = sysconf( OSAPI_COMMON_PAGESIZE );
 if( pagesize == -1 )
   { status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st ); return st; }

 *p_size = (uint64_t) (pages * pagesize);

 return st;
}


#endif	// OS_LINUX
