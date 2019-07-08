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

t_status proc_memory_allocate( t_size size, t_memory * p_memory )
{
 return common_memory_allocate( size, p_memory );
}

t_status proc_memory_reAllocate( t_size size, t_memory * p_memory )
{
  return common_memory_reAllocate( size, p_memory );
}

t_status proc_memory_deallocate( t_memory * p_memory )
{
 return common_memory_deallocate( p_memory );
}

t_status proc_memory_getCapacity( const t_memory * p_memory, t_size * p_size )
{
  return common_memory_getCapacity( p_memory, p_size );
}

t_status proc_memory_getData( const t_memory * p_memory, void ** p_data )
{
  return common_memory_getData( p_memory, p_data );
}

t_status proc_memory_copy( const t_memory * p_source, t_memory * p_target )
{
 return common_memory_copy( p_source, p_target );
}

t_status proc_memory_copyFrom( const t_memory * p_source, t_size targetSize, void * p_target )
{
 return common_memory_copyFrom( p_source, targetSize, p_target );
}

t_status proc_memory_copyTo( const void * p_source, t_size sourceSize, t_memory * p_target )
{
 return common_memory_copyTo( p_source, sourceSize, p_target );
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

t_status proc_buffer_copyFrom( const t_buffer * p_source, t_size targetSize, void * p_target )
{
 return common_buffer_copyFrom( p_source, targetSize, p_target );
}

t_status proc_buffer_copyTo( const void * p_source, t_size sourceSize, t_buffer * p_target )
{
 return common_buffer_copyTo( p_source, sourceSize, p_target );
}


// List related

t_status proc_list_allocate( t_size nItems, t_size itemSize, t_list * list )
{
  return common_list_allocate( nItems, itemSize, list );
}

t_status proc_list_reAllocate( t_size nItems, t_list * list )
{
  return common_list_reAllocate( nItems, list );
}

t_status proc_list_deallocate( t_list * list )
{
  return common_list_deallocate( list );
}

t_status proc_list_getCapacity( const t_list * list, t_size * size )
{
  return common_list_getCapacity( list, size );
}

t_status proc_list_getRequiredCapacity( const t_list * list, t_size * size )
{
  return common_list_getRequiredCapacity( list, size );
}

t_status proc_list_getData( const t_list * list, t_size item, void **  data )
{
  return common_list_getData( list, item, data );
}

t_status proc_list_getSize( const t_list * list, t_size * size )
{
  return common_list_getSize( list, size );
}

t_status proc_list_setSize( t_size size, t_list * list )
{
  return common_list_setSize( size, list );
}

t_status proc_list_setRequiredCapacity( t_size size, t_list * list )
{
  return common_list_setRequiredCapacity( size, list );
}

t_status proc_list_copy( const t_list * source, t_list * target )
{
 return common_list_copy( source, target );
}

t_status proc_list_copyFrom( const t_list * p_source, t_size sourceItem, t_size targetSize, void * p_target )
{
 return common_list_copyFrom( p_source, sourceItem, targetSize, p_target );
}

t_status proc_list_copyTo( const void * p_source, t_size sourceSize, t_size targetItem, t_list * p_target )
{
 return common_list_copyTo( p_source, sourceSize, targetItem, p_target );
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

