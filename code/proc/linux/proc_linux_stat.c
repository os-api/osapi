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


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

extern const char * OSAPI_FS_PROC_NAME;
const char * OSAPI_FS_PROC_STAT_FILENAME		= "stat";

static const t_size OSAPI_FS_PROC_SIZE			= 100;
static const t_size OSAPI_FS_PROC_STAT_ENTRY_SIZE	= PATH_MAX + 1000;


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status parse_linux_proc_stat_line( char * line, t_proc_info * p_proc_info )
{
 t_status st;
 char * token, * rest;

 status_reset( & st );

 // Process line

 // 1. The process ID
 token = strtok_r( line, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.pid = (t_pid) atoi( token );

 // 2. The filename of the executable, in parentheses (if it contains spaces it prevents the usage of fscanf
 token = strtok_r( NULL, ")", &rest );
 strncpy( p_proc_info->id.name, &token[1], 16 );

 // Remove space in between ) and the next argument
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 3. Process state: RSDZTW
 if( token[0] != 'R' && token[0] != 'S' && token[0] != 'T' && token[0] != 'Z' && token[0] != 'D' &&
     token[0] != 'W' && token[0] != 'I' && token[0] != 't' && token[0] != 'X' )
     token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 p_proc_info->state = token[0];

 // 4. The PID of the parent
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.ppid = (t_pid) atoi( token );

 // 5. The process group ID of the process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.pgrp = (t_pid) atoi( token );

 // 6. The session ID of the process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.session = (t_pid) atoi( token );

 // 7. The controlling terminal of the process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 //p_proc_info->tty_nr = atoi( token );

 // 8. The ID of the foreground process group of the controlling terminal of the process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->id.tpgid = atoi( token );

 // 9. The kernel flags word of the process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 10. The number of minor faults the process has made which have not required loading a memory page from disk
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 11. The number of minor faults that the process's waited-for children have made
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 12. The number of major faults the process has made which have required loading a memory page from disk
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 13. The number of major faults that the process's waited-for children have made
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 14. Amount of time that this process has been scheduled in user mode, measured in clock ticks
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->resources.utime = (t_size) atol( token );

 // 15. Amount of time that this process has been scheduled in kernel mode, measured in clock ticks
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->resources.stime = (t_size) atol( token );

 // 16. Amount of time that this process's waited-for children have been scheduled in user mode, measured in clock ticks
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 17. Amount of time that this process's waited-for children have been scheduled in kernel mode, measured in clock ticks
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 18. Scheduling priority or raw nice value
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 19. The nice value
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 20. Number of threads in this process
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->resources.num_threads = (t_size) atol( token );

 // 21. The time in jiffies before the next SIGALRM is sent to the process due to an interval timer
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );

 // 22. The time the process started after system boot.
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->starttime = (time_t) atol( token );

 // 23. Virtual memory size in bytes
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->resources.vsize = (t_size) atol( token );

 // 24. Resident Set Size: number of pages the process has in real memory
 token = strtok_r( NULL, OSAPI_SPACE_STRING, &rest );
 p_proc_info->resources.ram = (t_size) atoi( token );

 // 25. Current soft limit in bytes on the rss of the process
 // 26. The address above which program text can run
 // 27. The address below which program text can run
 // 28. The address of the start (i.e., bottom) of the stack
 // 29. The current value of ESP (stack pointer), as found in the kernel stack page for the process
 // 30. The current EIP (instruction pointer)
 // 31. The bitmap of pending signals, displayed as a decimal number.
 // 32. The bitmap of blocked signals, displayed as a decimal number.
 // 33. The bitmap of ignored signals, displayed as a decimal number.
 // 34. The bitmap of caught signals, displayed as a decimal number
 // 35. This is the "channel" in which the process is waiting
 // 36. Number of pages swapped (not maintained)
 // 37. Cumulative nswap for child processes (not maintained) or exit signal number (since Linux 2.1.22)
 // 38. Signal to be sent to parent when we die
 // 39. CPU number last executed on
 // 40. Real-time scheduling priority
 // 41. Scheduling policy
 // 42. Aggregated block I/O delays, measured in clock ticks
 // 43. Guest time of the process measured in clock ticks
 // 44. Guest time of the process's children, measured in clock ticks

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

t_status proc_info_last_processing( t_proc_info * p_pinfo )
{
  t_status	st;
  long		sz;

  status_reset( & st );

  sz = sysconf(_SC_PAGESIZE);	// Size of memory pages in Linux
  if( sz > 0 )
      p_pinfo->resources.ram = p_pinfo->resources.ram * (t_size) sz;

  sz = sysconf(_SC_CLK_TCK);	// Number of clock ticks per second
  if( sz > 0 )
    {
      p_pinfo->resources.utime = p_pinfo->resources.utime / (t_size) sz;
      p_pinfo->resources.stime = p_pinfo->resources.stime / (t_size) sz;
      p_pinfo->starttime = p_pinfo->starttime / sz;
    }

  return st;
}

t_status choose_linux_proc_stat_decoder( FILE * fp, t_proc_info * p_pinfo )
{
  t_status st;
  char	line		[ OSAPI_FS_PROC_STAT_ENTRY_SIZE	];

/*
  int tty, flags;
  int cnswap, exit_signal, processor;
  int rt_priority, policy;
  long minflt, cminflt, majflt, cmajflt, cutime, cstime, priority, nice;
  unsigned long long itrealvalue, delayacct_blkio_ticks;
  unsigned long rsslim, startcode, endcode, startstack, kstkesp, kstkeip;
  unsigned long signal, blocked, sigignore, sigcatch, wchan, nswap, guest_time, cguest_time;
*/

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
	/*
	      if( fscanf( fp, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %d %u %u %llu %lu %ld",
		      &(p_pinfo->id.pid), p_pinfo->id.name, &(p_pinfo->state),
		      &(p_pinfo->id.ppid), &(p_pinfo->id.pgrp), &(p_pinfo->id.session),
		      &tty, &(p_pinfo->id.tpgid), &flags, &minflt , &cminflt , &majflt, &cmajflt,
		      &(p_pinfo->resources.utime), &(p_pinfo->resources.stime),
		      &cutime, &cstime, &priority, &nice, &(p_pinfo->resources.num_threads),
		      &itrealvalue, &(p_pinfo->starttime), &(p_pinfo->resources.vsize), &(p_pinfo->resources.ram),
		      &rsslim, &startcode, &endcode, &startstack, &kstkesp, &kstkeip, &signal, &blocked, &sigignore,
		      &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor, &rt_priority, &policy, &delayacct_blkio_ticks, &guest_time, &cguest_time
		    ) != 44 )
	*/
	      // Arguments that are currently needed
	      if( fscanf( fp, "%d %s %c %d %d %d %*d %d %*u %*u %*u %*u %*u %lu %lu %*d %*d %*d %*d %ld %lu %*u %ld %lu",
			      &(p_pinfo->id.pid), p_pinfo->id.name, &(p_pinfo->state),
			      &(p_pinfo->id.ppid), &(p_pinfo->id.pgrp), &(p_pinfo->id.session),
			      &(p_pinfo->id.tpgid),
			      &(p_pinfo->resources.utime), &(p_pinfo->resources.stime),
			      &(p_pinfo->resources.num_threads),
			      &(p_pinfo->starttime), &(p_pinfo->resources.vsize), &(p_pinfo->resources.ram)
		    ) != 24 )

		  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
	    }

	  // Post-processing
	  st = proc_info_last_processing( p_pinfo );
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
