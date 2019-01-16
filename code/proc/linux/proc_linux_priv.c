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

// Increase baseline with Linux specific functionality
#define __USE_MISC 1

// System includes <here>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>



// Generic OSAPI includes
#include "general/general.h"
#include "common/common.h"

// Include own headers
#include "error/modules/error_proc.h"
#include "proc/linux/proc_linux_priv.h"
//#include "proc/posix/proc_posix_priv.h"


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

const char * OSAPI_FS_PROC_NAME			= "/proc";


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


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
	{
	  p_status->running 	= true;
	  p_status->alive	= true;
	}
     else
	{
	  // Translate POSIX/UNIX status to OSAPI
	  if( WIFEXITED( process_status ) )
	    {
	      p_status->running = false;
	      p_status->alive	= false;
	      osapi_bit_on( p_status->exit.normal );
	      p_status->exit.code = (Byte) WEXITSTATUS( process_status );
	    }
	  else
	    { // No exit information available, check if there was a change in the runtime information
	      if( WIFSTOPPED( process_status ) )
		{
		  p_status->running 	= false;
		  p_status->alive	= true;
		  osapi_bit_on( p_status->exit.stopped );
		  p_status->signumber = WSTOPSIG( process_status );
		}

	     if( WIFCONTINUED( process_status ) )
	       {
		 p_status->running 	= true;
		 p_status->alive	= true;
		 osapi_bit_on( p_status->exit.cont );
		 p_status->signumber = SIGCONT;
	       }

	      // If process was terminated by a signal, get the responsible signal number
	      if( WIFSIGNALED( process_status ) )
		{
		  osapi_bit_on( p_status->exit.signal );
		  p_status->signumber = WTERMSIG( process_status );
#ifdef WCOREDUMP
	 if( WCOREDUMP( process_status ) )	osapi_bit_on( p_status->exit.core );
#endif
		}
	    }
	}
   }

 return st;
}


t_status get_id_members( int target, t_pid target_id, t_size nmembers, t_size * p_nFoundMembers, t_pid (* p_members)[] )
{
 t_status		st;
 t_proc_info		pinfo;
 t_pid			pid, match_id;
 t_size			current 	= 0;
 struct dirent *	p_dir_entry	= NULL;
 DIR * 			p_dir		= NULL;

 status_reset( & st );

 p_dir = opendir( OSAPI_FS_PROC_NAME );

 while( ( p_dir_entry = readdir( p_dir ) ) )
      {
        if( ( strcmp( p_dir_entry->d_name, "."  ) == 0) ||
            ( strcmp( p_dir_entry->d_name, ".." ) == 0)  )
	      continue;

	    pid = (t_pid) atoi( p_dir_entry->d_name );

	    if( pid >= 0 )	// Check if process is valid
	      {
		st = parse_linux_proc_stat_file( pid, & pinfo );

		if( status_success( st ) && current < nmembers )
		  {
		    match_id = -1;
		    switch( target )
			  {
			    case e_proc_target_parent:	match_id = pinfo.id.ppid; 	break;
			    case e_proc_target_pgroup:	match_id = pinfo.id.pgrp; 	break;
			    case e_proc_target_session:	match_id = pinfo.id.session; 	break;

			    default: break;	// Do Nothing
			  }

		    if( match_id == target_id )	(*p_members)[ current++ ] = pid;
		  }
	      }
          }

 closedir( p_dir );
 *p_nFoundMembers = current;

 return st;
}


t_status count_proc_members( int target, t_pid target_id, t_size * p_number )
{
 t_status st;
 t_proc_info		pinfo;
 t_pid			pid, match_id;
 t_size			current 	= 0;
 struct dirent *	p_dir_entry	= NULL;
 DIR * 			p_dir		= NULL;

 status_reset( & st );

 if( p_number == (t_size *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     p_dir = opendir( OSAPI_FS_PROC_NAME );

     while( ( p_dir_entry = readdir( p_dir ) ) )
          {
	    if( ( strcmp( p_dir_entry->d_name, "."  ) == 0) ||
		( strcmp( p_dir_entry->d_name, ".." ) == 0)  )
	        continue;

	    pid = (t_pid) atoi( p_dir_entry->d_name );

	    if( pid >= 0 )	// Check if process is valid
	      {
		st = parse_linux_proc_stat_file( pid, & pinfo );

		if( status_success( st ) )
		  {
		    match_id = -1;
		    switch( target )
			  {
			    case e_proc_target_parent:	match_id = pinfo.id.ppid; 	break;
			    case e_proc_target_pgroup:	match_id = pinfo.id.pgrp; 	break;
			    case e_proc_target_session:	match_id = pinfo.id.session; 	break;

			    default: break;	// Do Nothing
			  }

		    if( match_id == target_id ) 	current++;
		  }
	      }
          }

     closedir( p_dir );
   }

 *p_number = current;

 return st;
}


#endif	// End of OS Linux
