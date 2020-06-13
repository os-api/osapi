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
#include "proc/proc_memory.h"


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

t_status proc_rawMemory_allocate( t_size size, Byte type, void * p_memory )
{
 return common_rawMemory_allocate( size, type, p_memory );
}

t_status proc_rawMemory_reAllocate( t_size size, void * p_memory )
{
  return common_rawMemory_reAllocate( size, p_memory );
}

t_status proc_rawMemory_deallocate( void * p_memory )
{
 return common_rawMemory_deallocate( p_memory );
}

t_status proc_memory_allocate( t_size size, Byte type, t_memory * p_memory )
{
 return common_memory_allocate( size, type, p_memory );
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


