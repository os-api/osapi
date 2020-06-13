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
#include "proc/proc_plan.h"


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************




// Add process data

t_status proc_data_setName( char * name, t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( name == ((char *) 0) || p_proc == ((t_proc *) 0) || strlen( name ) <= ((t_size) 0) )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
     p_proc->name = name;

 return st;
}



t_status proc_data_setCmdLine( t_size sizeArgList, char * argList[], t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( sizeArgList <= (t_size) 0 || argList == ((char **) 0) || p_proc == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
   {
     p_proc->nargs = sizeArgList;
     p_proc->args  = argList;
   }

 return st;
}

t_status proc_data_setEnvironment( t_size sizeArgList, char * argList[], t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( sizeArgList <= (t_size) 0 || argList == ((char **) 0) || p_proc == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
   {
     p_proc->nenv = sizeArgList;
     p_proc->env  = argList;
   }

 return st;
}



t_status proc_data_getCmdLine( t_proc * p_proc, t_size * p_nargs, char *** p_cmdLine )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_nargs == (t_size *) 0 || (void *) p_cmdLine == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
   {
     if( (void *) p_proc->args == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_nullptr, &st );
     else
       {
	 *p_nargs	= p_proc->nargs;
	 *p_cmdLine	= p_proc->args;
       }
   }

 return st;
}


t_status proc_data_getEnvironment( t_proc * p_proc, t_size * p_nargs, char *** p_environ )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_nargs == (t_size *) 0 || (void *) p_environ == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
   {
     if( (void *) p_proc->env == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_nullptr, &st );
     else
       {
	 *p_nargs	= p_proc->nenv;
	 *p_environ	= p_proc->env;
       }
   }

 return st;
}



t_status proc_data_getName( t_proc * p_proc, char ** p_name )
{
 t_status	st;

 status_reset( & st );

 if( (void **) p_name == NULL || (void *) p_proc == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
   {
     if( (void *) p_proc->name == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_nullptr, &st );
     else
	 *p_name = p_proc->name;
   }

 return st;
}

