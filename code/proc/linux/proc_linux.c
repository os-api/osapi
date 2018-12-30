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

t_status proc_instance_getNumberOfDescendents( t_size * p_number )
{
 t_status st;
 t_proc_info		pinfo;
 t_pid			pid, parent_pid;
 t_size			current 	= 0;
 struct dirent *	p_dir_entry	= NULL;
 DIR * 			p_dir		= NULL;

 status_reset( & st );

 if( p_number == (t_size *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     parent_pid = getpid();

     p_dir = opendir( OSAPI_FS_PROC_NAME );

     while( ( p_dir_entry = readdir( p_dir ) ) )
          {
	    if( ( strcmp( p_dir_entry->d_name, "."  ) == 0) ||
		( strcmp( p_dir_entry->d_name, ".." ) == 0)  )
	        continue;

	    pid = (t_pid) atoi( p_dir_entry->d_name );

	    if( pid > 0 )	// Check if process is a descendent
	      {
		st = parse_linux_proc_stat_file( pid, & pinfo );

		if( status_success( st ) && pinfo.id.ppid == parent_pid )  current++;
	      }
          }

   }

 *p_number = current;

 return st;
}


t_status proc_id_getDescendents( t_size nchildrens, t_size * p_nFoundChildren, t_pid (* p_descendents)[] )
{
 t_status		st;
 t_proc_info		pinfo;
 t_pid			pid, parent_pid;
 t_size			current 	= 0;
 struct dirent *	p_dir_entry	= NULL;
 DIR * 			p_dir		= NULL;

 status_reset( & st );

 if( p_descendents == (t_pid (*) []) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     parent_pid = getpid();

     p_dir = opendir( OSAPI_FS_PROC_NAME );

     while( ( p_dir_entry = readdir( p_dir ) ) )
          {
	    if( ( strcmp( p_dir_entry->d_name, "."  ) == 0) ||
		( strcmp( p_dir_entry->d_name, ".." ) == 0)  )
	        continue;

	    pid = (t_pid) atoi( p_dir_entry->d_name );

	    if( pid > 0 )	// Check if process is a descendent
	      {
		st = parse_linux_proc_stat_file( pid, & pinfo );

		if( status_success( st ) )
		  {
		    if( pinfo.id.ppid == parent_pid && current < nchildrens )
		        (*p_descendents)[ current++ ] = pinfo.id.pid;
		  }
	      }
          }
   }

 *p_nFoundChildren = current;

 return st;
}


#endif	// End of OS Linux
