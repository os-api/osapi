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
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"



// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

t_status proc_memory_allocate( t_size size, void ** p_memory )
{
 t_status	st;

 status_reset( & st );

 if( size <= (t_size) 0 || p_memory == (void **) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *p_memory = malloc( (size_t) size );
     if( *p_memory == NULL )
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}

t_status proc_memory_deallocate( void * p_memory )
{
 t_status	st;

 status_reset( & st );

 if( p_memory == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
     free( p_memory );

 return st;
}


t_status proc_memory_clear( t_size size, void * p_memory )
{
 t_status	st;
 void	*	p_m;

 status_reset( & st );

 if( size <= (t_size) 0 || p_memory == (void **) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     p_m = memset( p_memory, (int) '\0', (size_t) size );
     if( p_m != p_memory )		// Shouldn't happen according to the specification
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}


// Add process data

t_status proc_data_setName( char * name, t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( name == ((char *) 0) || p_proc == ((t_proc *) 0) || strlen( name ) <= ((t_size) 0) )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
     p_proc->name = name;

 return st;
}



t_status proc_data_setCmdLine( t_size sizeArgList, char * argList[], t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( sizeArgList <= (t_size) 0 || argList == ((char **) 0) || p_proc == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
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
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     p_proc->nenv = sizeArgList;
     p_proc->env  = argList;
   }

 return st;
}




