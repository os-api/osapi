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


// Own declarations
#include "common/common.h"
#include "common/common_types.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

int common_options_get( const t_option * moduleOptions, char * providedOptions[] )
{
 int	opt = 0;

 if( moduleOptions != NULL && providedOptions != NULL )
     for( int i=0; providedOptions[ i ] != OSAPI_NULL_CHAR_POINTER; i++  )
        {
 	  for( int j=0; moduleOptions[ j ].value != OSAPI_OPTIONS_END; j++ )
 	     {
	       // Compares current option[i] with list of all available options
	       if( strcasecmp( providedOptions[ i ], moduleOptions[ j ].name ) == 0 )
		 {
		   // Match found: Add option to the list (int/opt)
		   opt |= moduleOptions[ j ].value;
		   break;
		 }
	      }
        }

 return opt;
}


// All elements of a C-string are digits?
bool common_string_isDigit( const char * str )
{
 bool rv = true;

 if( str == NULL )
     rv = false;
 else
   {
     for( int i=0; i < strlen( str ); i++ )
        {
          if( ! isdigit( (int) str[ i ] ) )
            {
              rv = false;
              break;
            }
        }
   }

 return rv;
}



// *****************************************************************************************
//
// Section: Buffer function definition
//
// *****************************************************************************************


t_status common_buffer_allocate( size_t bufsize, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( bufsize == 0 || p_buffer == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary == OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_alloc, &st );
      else
	{
	  errno = 0;
	  p_buffer->data = calloc( 1, bufsize );

	  if( p_buffer->data == OSAPI_NULL_CHAR_POINTER )
	      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
	  else
	    {
	      p_buffer->capacity	= bufsize;
	      p_buffer->canary 		= OSAPI_COMMON_CANARY;
	      p_buffer->size		= 0;
	    }
	}
    }

  return st;
}

t_status common_buffer_reAllocate( t_size bufsize, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( bufsize == 0 || p_buffer == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      else
	{
	  errno = 0;
	  void * ptr = realloc( p_buffer->data, bufsize );

	  if( ptr == OSAPI_NULL_CHAR_POINTER )
	      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
	  else
	    {
	      p_buffer->data		= ptr;
	      p_buffer->capacity	= bufsize;
	    }
	}
    }

  return st;
}

t_status common_buffer_deallocate( t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( p_buffer == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_dealloc, &st );
      else
	{
	  errno = 0;
	  free( p_buffer->data );

	  // Clear fields of structure
	  p_buffer->data 	= OSAPI_NULL_CHAR_POINTER;
	  p_buffer->capacity	= 0;
	  p_buffer->canary 	= 0;
	  p_buffer->size	= 0;
	}
    }

  return st;
}

t_status common_buffer_getCapacity( const t_buffer * p_buffer, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_buffer == NULL || p_size ==NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      else
	  *p_size = p_buffer->capacity;
    }

  return st;
}

t_status common_buffer_getData( const t_buffer * p_buffer, void ** p_data )
{
  t_status	st;

  status_reset( & st );

  if( p_buffer == NULL || p_data == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      else
	  *p_data = p_buffer->data;
    }

  return st;
}

t_status common_buffer_getSize( const t_buffer * p_buffer, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_buffer == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      else
	  *p_size = p_buffer->size;
    }

  return st;
}

t_status common_buffer_setSize( t_size size, t_buffer * p_buffer )
{
  t_status	st;

  status_reset( & st );

  if( p_buffer == NULL || size == 0 )
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
  else
    {
      if( p_buffer->canary != OSAPI_COMMON_CANARY )
	  status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      else
	  p_buffer->size = size;
    }

  return st;
}




t_status common_buffer_copy( const t_buffer * p_source, t_buffer * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
      return st;
    }

  if( p_source->canary != OSAPI_COMMON_CANARY )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      return st;
    }

  if( p_source->data == p_target->data )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_memoverlap, &st );
      return st;
    }

  if( p_target->canary == OSAPI_COMMON_CANARY && p_target->data != NULL )
      common_buffer_deallocate( p_target );	// Ignore return status

  st = common_buffer_allocate( p_source->size, p_target );

  if( status_success( st ) )
    {
      errno = 0;

      void * ptr = memcpy( p_target->data, p_source->data, p_source->size );
      if( ptr != p_target->data || errno != 0 )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
      else
	  p_target->size = p_source->size;
    }

  return st;
}


t_status common_buffer_copyFrom( const t_buffer * p_source, void * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
      return st;
    }

  if( p_source->canary != OSAPI_COMMON_CANARY )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_canary, &st );
      return st;
    }

  errno = 0;

  void * ptr = memcpy( p_target, p_source->data, p_source->size );
  if( ptr != p_target || errno != 0 )
      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );

  return st;
}

t_status common_buffer_copyTo( const void * p_source, t_size sourceSize, t_buffer * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL || sourceSize == (t_size) 0 )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__, osapi_common_e_params, &st );
      return st;
    }

  if( p_target->canary == OSAPI_COMMON_CANARY )
    {
      common_buffer_deallocate( p_target );	// Ignore return status

      st = common_buffer_allocate( sourceSize, p_target );
    }

  if( status_success( st ) )
    {
      errno = 0;

      void * ptr = memcpy( p_target->data, p_source, sourceSize );
      if( ptr != p_target->data || errno != 0 )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
      else
	  p_target->size = sourceSize;
    }

  return st;
}




