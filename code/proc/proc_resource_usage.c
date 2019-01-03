// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module that provides a generic resource related implementation
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
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"



// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************


t_status proc_usage_getVirtualMemory( t_pid pid, t_size * p_size )
{
 t_status		st;
 t_proc_info		pinfo;

 st = proc_info_get( pid, & pinfo );

 if( status_success( st ) )
     *p_size = pinfo.resources.vsize;

 return st;
}

t_status proc_usage_getRealMemory( t_pid pid, t_size * p_size )
{
 t_status		st;
 t_proc_info		pinfo;

 st = proc_info_get( pid, & pinfo );

 if( status_success( st ) )
     *p_size = pinfo.resources.ram;

 return st;
}

t_status proc_usage_getCPU( t_pid pid, t_size * p_size )
{
 t_status		st;
 t_proc_info		pinfo;

 st = proc_info_get( pid, & pinfo );

 if( status_success( st ) )
     *p_size = pinfo.resources.utime + pinfo.resources.stime;

 return st;
}


t_status proc_usage_getThreads( t_pid pid, t_size * p_size )
{
 t_status		st;
 t_proc_info		pinfo;

 st = proc_info_get( pid, & pinfo );

 if( status_success( st ) )
     *p_size = pinfo.resources.num_threads;

 return st;
}
