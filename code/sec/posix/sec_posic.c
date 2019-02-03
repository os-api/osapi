// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec(urity) module using a POSIX compliant implementation
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
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"
#include "common/common.h"
#include "common/posix/common_posix.h"

// Own declarations
#include "sec/sec.h"
#include "error/modules/error_sec.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX

// Group functions
t_status sec_group_exists( t_gid gid )
{
 t_status		st;
 int			rc;
 char *			buf;
 struct group		grp;
 struct group *		result;

 status_reset( & st );

 if( gid < 0 )
     status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
 else
   {
     size_t bufsize = get_size_grp_entry();
     buf = malloc( bufsize );

     if( buf == NULL )
	 status_iset( OSAPI_MODULE_SEC, __func__, e_sec_memory, &st );
     else
       {
	 rc = getgrgid_r( gid, &grp, buf, bufsize, &result );
	 if( rc != 0 || result == NULL )
	     status_iset( OSAPI_MODULE_SEC, __func__, e_sec_groupid, &st );

	 free( buf );
       }
   }

 return st;
}



// User functions
t_status sec_user_exists( t_uid uid )
{
 t_status		st;
 int			rc;
 char *			buf;
 struct passwd		pwd;
 struct passwd *	result;

 status_reset( & st );

 if( uid < 0 )
     status_iset( OSAPI_MODULE_SEC, __func__, e_sec_params, &st );
 else
   {
     size_t bufsize = get_size_pwd_entry();
     buf = malloc( bufsize );

     if( buf == NULL )
	 status_iset( OSAPI_MODULE_SEC, __func__, e_sec_memory, &st );
     else
       {
	 rc = getpwuid_r( uid, &pwd, buf, bufsize, &result);
	 if( rc != 0 || result == NULL )
	     status_iset( OSAPI_MODULE_SEC, __func__, e_sec_userid, &st );

	 free( buf );
       }
   }

 return st;
}


#endif	// End of POSIX Implementation

