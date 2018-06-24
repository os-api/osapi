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

// Defines to import function getgrouplist
//#define _DEFAULT_SOURCE		// Glibc since  2.19
//#define _BSD_SOURCE		// Glibc before 2.19
#define __USE_MISC
#include <grp.h>

//#undef _BSD_SOURCE
//#undef _DEFAULT_SOURCE

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_types.h"
#include "status/status.h"

// Own declarations
#include "common/common.h"


t_status get_max_length_groupname( t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
  else
      *p_size = 32;		// Apparently this is the maximum size of a group name.. requires confirmation

  return st;
}

#include <stdio.h>
t_status get_user_group_list( t_uid uid, size_t groupListMaxSize, size_t * p_groupListCurSize, t_gid *  p_groupList )
{
  t_status st;

  status_reset( &st );

  if( p_groupList == ((t_gid *) 0) || groupListMaxSize <= 0 || p_groupListCurSize == (size_t *) 0 )
      status_iset( OSAPI_MODULE_NONE, __func__, OSAPI_ERROR_INVPARAM, &st );
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
		      status_eset( OSAPI_MODULE_NONE, __func__, errno, &st );
		  else
		      *p_groupListCurSize = (size_t) ngroups;
		}
	    }
	}
    }

  return st;
}



#endif
