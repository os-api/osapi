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

// Generic OSAPI includes
#include "general/general.h"
#include "common/common.h"

// Include own headers
#include "error/modules/error_proc.h"
#include "proc/linux/proc_linux_priv.h"
#include "proc/posix/proc_posix_priv.h"


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

const char * OSAPI_FS_PROC_NAME			= "/proc";
const char * OSAPI_FS_PROC_STAT_FILENAME	= "stat";

static const t_size OSAPI_FS_PROC_SIZE			= 100;
static const t_size OSAPI_FS_PROC_STAT_ENTRY_SIZE	= PATH_MAX + 1000;


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

t_status parse_linux_proc_stat_line( char * line, t_proc_info * p_proc_info )
{
 t_status st;
 char * token, * rest;

 status_reset( & st );

 // Process line
 // Get PID
 token = strtok_r( line, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.pid = (t_pid) atoi( token );

 // Get process name (may contain spaces which prevents the usage of fscanf
 token = strtok_r( NULL, ")", &rest );
 strncpy( p_proc_info->id.name, &token[1], 16 );

 // Remove space in between ) and the next argument
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 //Possible states: RSDZTW
 if( token[0] != 'R' && token[0] != 'S' && token[0] != 'T' && token[0] != 'Z' && token[0] != 'D' &&
     token[0] != 'W' && token[0] != 'I' && token[0] != 't' && token[0] != 'X' )
     token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 p_proc_info->state = token[0];

 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.ppid = (t_pid) atoi( token );

 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.pgrp = (t_pid) atoi( token );

 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.session = (t_pid) atoi( token );

 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 //p_proc_info->tty_nr = atoi( token );

 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.tpgid = atoi( token );

 return st;
}


// Verify if there are empty spaces in the process name that prevents usage of fscanf
bool has_linux_proc_stat_file_spaces( char * line )
{
 bool 	ret 		= false;
 char * begin, * end;
 char	process_name	[ NAME_MAX + 1 ];

 begin = strstr( line, "(" );

 if( begin != NULL )
   {
     end = strstr( begin + 1, ") " );
     if( end != NULL )
       {
	 // Make sure that size doesn't exceed the allocated buffer
	 t_size sz = end - begin > NAME_MAX ? (t_size) NAME_MAX : (t_size) (end - begin -1);

	 memset( process_name, '\0', sizeof( process_name ) );

	 strncpy( process_name, begin + 1, sz );
	 if( strstr( process_name, " " ) != NULL )
	     ret = true;
       }
   }

 return ret;
}

t_status choose_linux_proc_stat_decoder( FILE * fp, t_proc_info * p_pinfo )
{
  t_status st;
  char	line		[ OSAPI_FS_PROC_STAT_ENTRY_SIZE	];
  int tty, flags;

  int cnswap, exit_signal, processor;
  int rt_priority, policy;
  long minflt, cminflt, majflt, cmajflt, cutime, cstime, priority, nice;
  unsigned long long itrealvalue, delayacct_blkio_ticks;
  unsigned long starttime, rsslim, startcode, endcode, startstack, kstkesp, kstkeip;
  unsigned long signal, blocked, sigignore, sigcatch, wchan, nswap, guest_time, cguest_time;

  status_reset( & st );

  if( fp == (FILE *) 0 || p_pinfo == (t_proc_info *) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      if( fgets( line, (int) OSAPI_FS_PROC_STAT_ENTRY_SIZE, fp ) == NULL )
 	   status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
      else
	{
	  // Does the process name contain spaces?
	  if( has_linux_proc_stat_file_spaces( line ) )
              st = parse_linux_proc_stat_line( line, p_pinfo );
	  else
	    {
	      rewind( fp );

	      // There are 44 arguments to be read from the file
	      if( fscanf( fp, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %d %u %u %llu %lu %ld",
		      &(p_pinfo->id.pid), p_pinfo->id.name, &(p_pinfo->state),
		      &(p_pinfo->id.ppid), &(p_pinfo->id.pgrp), &(p_pinfo->id.session),
		      &tty, &(p_pinfo->id.tpgid), &flags, &minflt , &cminflt , &majflt, &cmajflt,
		      &(p_pinfo->resources.utime), &(p_pinfo->resources.stime),
		      &cutime, &cstime, &priority, &nice, &(p_pinfo->resources.num_threads),
		      &itrealvalue, &starttime, &(p_pinfo->resources.vsize), &(p_pinfo->resources.ram),
		      &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip, &signal, &blocked, &sigignore,
		      &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority, &policy, &delayacct_blkio_ticks, &guest_time, &cguest_time
		    ) != 44 )
		  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
	    }
	}

    }

 return st;
}


t_status parse_linux_proc_stat_file( t_pid pid, t_proc_info * p_proc_info )
{
 t_status st;
 FILE *	p_status_file	= NULL;
 char	filename	[ OSAPI_FS_PROC_SIZE + 1 	];

 status_reset( & st );

 snprintf( filename, OSAPI_FS_PROC_SIZE, "%s/%d/%s", OSAPI_FS_PROC_NAME, pid, OSAPI_FS_PROC_STAT_FILENAME );
 filename[ OSAPI_FS_PROC_SIZE ] = '\0';		// Ensure that it's null terminated

 p_status_file = fopen( filename, "r" );

 if( p_status_file == NULL )
     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
 else
     st = choose_linux_proc_stat_decoder( p_status_file, p_proc_info );

 return st;
}



#endif	// End of OS Linux
