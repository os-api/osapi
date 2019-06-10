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



t_status proc_library_getNumberOfLoaded( t_size * maxlibs )
{
 return getNumberOfLoadedLibraries( maxlibs );
}


t_status proc_library_getAllLoaded( t_size maxlibs, t_libinfo (*info)[] )
{
  return getListOfLoadedLibraries( maxlibs, info );
}

t_status proc_library_getRelease( const t_char * p_name, t_size max, char * p_release )
{
 return getLibraryRelease( p_name, max, p_release );
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


// Get the Parent ID for any target process
// This function must be implemented in every POSIX compliant system
t_status posix_get_parent_pid( t_pid childPid, t_pid * p_parentPid )
{
  t_status		st;
  t_proc_info		pinfo;
  t_pid			pid;
  struct dirent *	p_dir_entry	= NULL;
  DIR * 		p_dir		= NULL;

  status_reset( & st );

  if( childPid < 2 || p_parentPid == (t_pid *) 0 )
    {
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
      return st;
    }

  status_iset( OSAPI_MODULE_PROC, __func__, e_proc_idNotFound, &st );

  p_dir = opendir( OSAPI_FS_PROC_NAME );

  while( ( p_dir_entry = readdir( p_dir ) ) )
       {
         if( ( strcmp( p_dir_entry->d_name, "."  ) == 0) ||
             ( strcmp( p_dir_entry->d_name, ".." ) == 0)  )
 	      continue;

 	    pid = (t_pid) atoi( p_dir_entry->d_name );

 	    if( pid == childPid )	// Check if it's the target process
 	      {
 		st = parse_linux_proc_stat_file( pid, & pinfo );

 		if( status_success( st ) )
 		  {
 		    *p_parentPid = pinfo.id.ppid;
 		    status_reset( & st );
 		  }

 		break;	// If the target process was found, no need to continue
 	      }
       }

  closedir( p_dir );

  return st;
}

t_status proc_instance_getState( t_pid pid, int * p_state )
{
  t_status		st;
  t_proc_info		pinfo;

  status_reset( & st );

  if( pid < 1 || p_state == (int *) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      st = parse_linux_proc_stat_file( pid, &pinfo );
      if( status_success( st ) )
	{
	  // Map Linux process state to generic state
	  switch( (int) pinfo.state )
	  {
	    case 'D':	// uninterruptible sleep (usually IO)
	    case 'S':	// interruptible sleep (waiting for an event to complete)
	    case 'I':	// Idle kernel thread
	    case 'W':	// paging (not valid since the 2.6.xx kernel)

			*p_state = osapi_e_proc_state_waiting; break;

	    case 'X':	// dead (should never be seen)
	    case 'Z':	// defunct ("zombie") process, terminated but not reaped by its parent

			*p_state = osapi_e_proc_state_terminated; break;

	    case 'T':	// stopped by job control signal
	    case 't':	// stopped by debugger during the tracing

			*p_state = osapi_e_proc_state_stopped; break;

	    case 'R':	// running or runnable (on run queue)

			*p_state = osapi_e_proc_state_running; break;

	    default:	*p_state = osapi_e_proc_state_inexistent; break;
	  }
	}
    }

  return st;
}



t_status proc_status_get( t_pid target_pid, t_pid * found_pid, t_proc_status * p_status )
{
 t_status	st;
 int		process_status = 0;

 status_reset( & st );

 if( found_pid == (t_pid *) 0 || p_status == (t_proc_status *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *found_pid = waitpid( target_pid, &process_status, WNOHANG | WUNTRACED | WCONTINUED );
     if( *found_pid == -1 )
	{
	  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
	  return st;		// Return immediately
	}

     memset( p_status, '\0', sizeof( t_proc_status ) );

     // First, check if the process is still running
     if( *found_pid == 0 )
	  p_status->info = osapi_e_proc_status_unavailable;
     else
	{
	  // Translate POSIX/UNIX status to OSAPI
	  if( WIFEXITED( process_status ) )
	    {
	      p_status->info	= osapi_e_proc_status_available;
	      p_status->exit_code = (int) WEXITSTATUS( process_status );
	    }
	  else
	    { // No exit information available, check if there was a change in the runtime information
	      if( WIFSTOPPED( process_status ) )
		{
		  p_status->info	= osapi_e_proc_status_stopped;
		  p_status->signumber	= WSTOPSIG( process_status );
		}

	     if( WIFCONTINUED( process_status ) )
	       {
		 p_status->info		= osapi_e_proc_status_continued;
		 p_status->signumber	= SIGCONT;
	       }

	      // If process was terminated by a signal, get the responsible signal number
	      if( WIFSIGNALED( process_status ) )
		{
		  p_status->info	= osapi_e_proc_status_signal;
		  p_status->signumber	= WTERMSIG( process_status );
#ifdef WCOREDUMP
		  if( WCOREDUMP( process_status ) )
		      p_status->info = osapi_e_proc_status_core;
#endif
		}
	    }
	}
   }

 return st;
}





#endif	// End of OS Linux
