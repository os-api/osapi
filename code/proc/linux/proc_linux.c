// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module using a Linux implementation
//
// *****************************************************************************************

// Only relevant is OS is Linux
#ifdef OS_LINUX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes <here>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/procfs.h>
#include <sys/stat.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"
#include "common/common.h"

// Include own headers
#include "proc/proc.h"
#include "error/modules/error_proc.h"
#include "proc/posix/proc_posix.h"
#include "proc/linux/proc_linux.h"
#include "proc/linux/proc_linux_priv.h"


// *****************************************************************************************
//
// Section: Constant declarations/definitions
//
// *****************************************************************************************

extern const char * OSAPI_FS_PROC_NAME;

const t_option lib_options[] = {
        { "RTLD_LAZY", 	 RTLD_LAZY 		},
	{ "RTLD_NOW", 	 RTLD_NOW 		},
	{ "RTLD_GLOBAL", RTLD_GLOBAL	 	},
	{ "RTLD_LOCAL",  RTLD_LOCAL 		},
        { "",		 OSAPI_OPTIONS_END	},
};



// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status proc_library_load( char * pathname, char * options[], t_library * p_library )
{
  int	opt = 0;

  opt = common_options_get( lib_options, options );

  return posix_library_load( pathname, opt, p_library );
}

t_status proc_instance_getNumberOfDescendents( t_pid pid, t_size * p_number )
{
  return count_proc_members( e_proc_target_parent, pid, p_number );
}


t_status proc_instance_getNumberOfGroupMembers( t_pid pgid, t_size * p_number )
{
  return count_proc_members( e_proc_target_pgroup, pgid, p_number );
}


t_status proc_instance_getNumberOfSessionMembers( t_pid sid, t_size * p_number )
{
 return count_proc_members( e_proc_target_session, sid, p_number );
}



t_status proc_id_getDescendents( t_pid pid, t_size nchildrens, t_size * p_nFoundChildren, t_pid (* p_descendents)[] )
{
 return get_id_members( e_proc_target_parent, pid, nchildrens, p_nFoundChildren, p_descendents );
}


t_status proc_id_getGroupMembers( t_pid pgid, t_size nmembers, t_size * p_nFoundMembers, t_pid (* p_members)[] )
{
  return get_id_members( e_proc_target_pgroup, pgid, nmembers, p_nFoundMembers, p_members );
}


t_status proc_id_getSessionMembers( t_pid sid, t_size nmembers, t_size * p_nFoundMembers, t_pid (* p_members)[] )
{
  return get_id_members( e_proc_target_session, sid, nmembers, p_nFoundMembers, p_members );
}


t_status proc_info_get( t_pid pid, t_proc_info * p_pinfo )
{
  t_status		st;

  status_reset( & st );

  if( p_pinfo == (t_proc_info *) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
      if( pid > 0 ) st = parse_linux_proc_stat_file( pid, p_pinfo );

  return st;
}




#endif	// End of OS Linux
