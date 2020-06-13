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
#include "proc/proc_buffer.h"




// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************



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

