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
#include <stdint.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_proc.h"
#include "status/status.h"

// Own module declarations
#include "proc/proc_info.h"
#include "proc/proc_time.h"


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************


t_status proc_time_getStart( t_pid pid, t_time * p_start )
{
 t_status		st;
 t_proc_info		pinfo;

 if( p_start == NULL )
   { status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st ); return st; }

 st = proc_info_get( pid, & pinfo );

 if( status_success( st ) )
   {
     if( pinfo.starttime > INT64_MAX )
       { status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_conversion, &st ); return st; }

     p_start->seconds	= (int64_t) pinfo.starttime;
     p_start->fraction	= (uint64_t) 0;
     p_start->precision = osapi_time_second;
   }

 return st;
}

