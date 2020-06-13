// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a C compliant implementation
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
#include "error/modules/error_proc.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "proc/proc_info.h"




// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************


t_status proc_info_getVirtualMemory( t_proc_info * p_info, t_size * p_size )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_info == NULL || (void *) p_size == NULL )
   {
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
     return st;
   }

 *p_size = p_info->resources.vsize;

 return st;
}

t_status proc_info_getRealMemory( t_proc_info * p_info, t_size * p_size )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_info == NULL || (void *) p_size == NULL )
   {
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
     return st;
   }

 *p_size = p_info->resources.ram;

 return st;
}

t_status proc_info_getCPUConsumption( t_proc_info * p_info, t_size * p_size )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_info == NULL || (void *) p_size == NULL )
   {
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
     return st;
   }

 *p_size = p_info->resources.utime + p_info->resources.utime ;

 return st;
}

t_status proc_info_getThreads( t_proc_info * p_info, t_size * p_number )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_info == NULL || (void *) p_number == NULL )
   {
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
     return st;
   }

 *p_number = p_info->resources.num_threads;

 return st;
}

t_status proc_info_getStartTime( t_proc_info * p_info, t_time * p_start )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_info == NULL || (void *) p_start == NULL )
   {
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
     return st;
   }

 p_start->seconds  = (int64_t) p_info->starttime;
 p_start->fraction = 0;

 return st;
}

