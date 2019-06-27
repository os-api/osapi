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
#include "proc/proc.h"




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

// Buffer related

t_status proc_buffer_allocate( size_t bufsize, t_buffer * p_buffer )
{
  return common_buffer_allocate( bufsize, p_buffer );
}

t_status proc_buffer_reAllocate( t_size bufsize, t_buffer * p_buffer )
{
  return common_buffer_reAllocate( bufsize, p_buffer );
}

t_status proc_buffer_deallocate( t_buffer * p_buffer )
{
  return common_buffer_deallocate( p_buffer );
}

t_status proc_buffer_getCapacity( const t_buffer * p_buffer, t_size * p_size )
{
  return common_buffer_getCapacity( p_buffer, p_size );
}

t_status proc_buffer_getData( const t_buffer * p_buffer, void ** p_data )
{
  return common_buffer_getData( p_buffer, p_data );
}

t_status proc_buffer_getSize( const t_buffer * p_buffer, t_size * p_size )
{
  return common_buffer_getSize( p_buffer, p_size );
}

t_status proc_buffer_setSize( t_size size, t_buffer * p_buffer )
{
  return common_buffer_setSize( size, p_buffer );
}




t_status proc_buffer_copy( const t_buffer * p_source, t_buffer * p_target )
{
 return common_buffer_copy( p_source, p_target );
}

t_status proc_buffer_copyFrom( const t_buffer * p_source, void * p_target )
{
 return common_buffer_copyFrom( p_source, p_target );
}

t_status proc_buffer_copyTo( const void * p_source, t_size sourceSize, t_buffer * p_target )
{
 return common_buffer_copyTo( p_source, sourceSize, p_target );
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



t_status proc_data_getCmdLine( t_proc * p_proc, t_size * p_nargs, char *** p_cmdLine )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_nargs == (t_size *) 0 || (void *) p_cmdLine == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( (void *) p_proc->args == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_nullptr, &st );
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
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( (void *) p_proc->env == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_nullptr, &st );
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
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( (void *) p_proc->name == NULL )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_nullptr, &st );
     else
	 *p_name = p_proc->name;
   }

 return st;
}

