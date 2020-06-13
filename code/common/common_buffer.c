// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common Module Linux function implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Include standard headers
#include <strings.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_common.h"
#include "status/status.h"
#include "status/trace_macros.h"

// Own declarations
#include "common/common_defs.h"
#include "common/common_memory.h"
#include "common/common_buffer.h"
#include "common/common_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status common_buffer_allocate( t_size bufsize, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  st = common_memory_allocate( bufsize, 0, &(p_buffer->mem) );

  if( status_success( st ) )
      p_buffer->size = 0;

  TRACE_EXIT

  return st;
}

t_status common_buffer_reAllocate( t_size bufsize, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  st = common_memory_reAllocate( bufsize, &(p_buffer->mem) );

  if( status_success( st ) )		// Resize current memory usage, if needed
    {
      t_size sz = 0;
      st = common_memory_getCapacity( &(p_buffer->mem), &sz );

      if( status_success( st ) )
	{
	  if( p_buffer->size > sz )
	      p_buffer->size = sz;
	}
    }

  TRACE_EXIT

  return st;
}

t_status common_buffer_deallocate( t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  st = common_memory_deallocate( &(p_buffer->mem) );

  if( status_success( st ) )
      p_buffer->size	= 0;

  TRACE_EXIT

  return st;
}

t_status common_buffer_getCapacity( const t_buffer * p_buffer, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_buffer == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
      st = common_memory_getCapacity( &(p_buffer->mem), p_size );

  TRACE_EXIT

  return st;
}

t_status common_buffer_getData( const t_buffer * p_buffer, void ** p_data )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_buffer == NULL || p_data == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
      st = common_memory_getData( &(p_buffer->mem), p_data );

  TRACE_EXIT

  return st;
}

t_status common_buffer_getSize( const t_buffer * p_buffer, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_buffer == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_buffer_not_allocated( p_buffer ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_size = p_buffer->size;
    }

  TRACE_EXIT

  return st;
}

t_status common_buffer_setSize( t_size size, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_buffer == NULL || size == 0 )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_buffer_not_allocated( p_buffer ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  p_buffer->size = size;
    }

  TRACE_EXIT

  return st;
}




t_status common_buffer_copy( const t_buffer * p_source, t_buffer * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  st = common_memory_copy( &(p_source->mem), &(p_target->mem) );

  if( status_success( st ) )
      p_target->size = p_source->size;

  TRACE_EXIT

  return st;
}


t_status common_buffer_copyFrom( const t_buffer * p_source, t_size targetSize, void * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
      st = common_memory_copyFrom( &(p_source->mem), targetSize, p_target );

  TRACE_EXIT

  return st;
}

t_status common_buffer_copyTo( const void * p_source, t_size sourceSize, t_buffer * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL || sourceSize == (t_size) 0 )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      st = common_memory_copyTo( p_source, sourceSize, &(p_target->mem) );
      if( status_success( st ) )
	  p_target->size = sourceSize;	// == capacity also
    }

  TRACE_EXIT

  return st;
}




