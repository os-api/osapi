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
#include "common/common_helper.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status common_rawMemory_allocate( t_size size, void ** p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( size == 0 || p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      errno = 0;
      *p_mem = calloc( 1, size );

      if( *p_mem == NULL )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
    }

  TRACE_EXIT

  return st;
}

t_status common_rawMemory_reAllocate( t_size size, void ** p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( size == 0 || p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      errno = 0;
      *p_mem = realloc( *p_mem, size );

      if( *p_mem == NULL )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
    }

  TRACE_EXIT

  return st;
}

t_status common_rawMemory_deallocate( void * p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
      free( p_mem );

  TRACE_EXIT

  return st;
}


t_status common_memory_allocate( t_size size, t_memory * p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( size == 0 || p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_memory_allocated( p_mem ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_alloc, &st );
      else
	{
	  errno = 0;
	  p_mem->data = calloc( 1, size );

	  if( p_mem->data == OSAPI_NULL_CHAR_POINTER )
	      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
	  else
	    {
	      set_memory_allocated( p_mem );
	      p_mem->capacity	= size;
	    }
	}
    }

  TRACE_EXIT

  return st;
}

t_status common_memory_reAllocate( t_size size, t_memory * p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( size == 0 || p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      errno = 0;
      void * ptr = realloc( p_mem->data, size );

      if( ptr == OSAPI_NULL_CHAR_POINTER )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
      else
	{
	  if( is_memory_allocated( p_mem ) && size > p_mem->capacity )			// Requested size is bigger, clear delta
	    {
	      // The following variables are just for readability
	      size_t clearSize		= (size_t) (size - (p_mem->capacity) );		// Size of the new capacity that was not yet initialized
	      Byte * p_clearLocation	= &( (Byte *) ptr )[ p_mem->capacity ];		// Start on the array element that was not yet initialized

	      memset( p_clearLocation, '\0', clearSize );
	    }

	  p_mem->data		= ptr;				// In case the memory was reallocated into a new region
	  p_mem->capacity	= size;				// Update the capacity
	  set_memory_allocated( p_mem );			// In case it was not yet allocated
	}
    }

  TRACE_EXIT

  return st;
}

t_status common_memory_deallocate( t_memory * p_mem )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_mem == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_memory_not_allocated( p_mem ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_dealloc, &st );
      else
	{
	  errno = 0;
	  free( p_mem->data );

	  // Clear fields of structure
	  p_mem->data 		= OSAPI_NULL_CHAR_POINTER;
	  p_mem->capacity	= 0;
	  set_memory_unallocated( p_mem );
	}
    }

  TRACE_EXIT

  return st;
}

t_status common_memory_getCapacity( const t_memory * p_mem, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_mem == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_memory_not_allocated( p_mem ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_size = p_mem->capacity;
    }

  TRACE_EXIT

  return st;
}

t_status common_memory_getData( const t_memory * p_mem, void ** p_data )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_mem == NULL || p_data == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_memory_not_allocated( p_mem ) )
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_data = p_mem->data;
    }

  TRACE_EXIT

  return st;
}



t_status common_memory_copy( const t_memory * p_source, t_memory * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_memory_not_allocated( p_source ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  if( p_source->data == p_target->data )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_memoverlap, &st );
      return st;
    }

  if( is_memory_allocated( p_target ) && p_target->data != NULL )
      common_memory_deallocate( p_target );	// Ignore return status

  st = common_memory_allocate( p_source->capacity, p_target );

  if( status_success( st ) )
    {
      errno = 0;

      void * ptr = memcpy( p_target->data, p_source->data, p_source->capacity );
      if( ptr != p_target->data || errno != 0 )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
      else
	  p_target->capacity = p_source->capacity;
    }

  TRACE_EXIT

  return st;
}


t_status common_memory_copyFrom( const t_memory * p_source, t_size targetSize, void * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL || targetSize == (t_size) 0 )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_memory_not_allocated( p_source ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  // Ensure there is no memory violation
  t_size copySize = 0;
  if( targetSize >=  p_source->capacity )	copySize = p_source->capacity;
  else						copySize = targetSize;

  errno = 0;
  void * ptr = memcpy( p_target, p_source->data, copySize );

  if( ptr != p_target || errno != 0 )
      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );

  TRACE_EXIT

  return st;
}


t_status common_memory_copyTo( const void * p_source, t_size sourceSize, t_memory * p_target )
{
  t_status	st;

  status_reset( & st );

  TRACE_ENTER

  if( p_source == NULL || p_target == NULL || sourceSize == (t_size) 0 )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  // Make sure that if the memory of the target was previously allocated
  // it was with the same size, otherwise this is likely memory corruption
  if( is_memory_not_allocated( p_target ) && sourceSize != p_target->capacity )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  errno = 0;
  void * ptr = memcpy( p_target->data, p_source, sourceSize );

  if( ptr != p_target->data || errno != 0 )
      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );

  TRACE_EXIT

  return st;
}




