// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common Module Linux function implementation for an item list
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
#include "common/common_defs.h"
#include "common/common_memory.h"
#include "common/common_list.h"
#include "common/common_helper.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status common_list_allocate( t_size nItems, t_size itemSize, t_list * p_list )
{
  t_status	st;

  status_reset( & st );

  if( nItems == 0 || itemSize == 0 || p_list == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      t_size bufsize = nItems * itemSize;
      st = common_memory_allocate( bufsize, &(p_list->mem) );

      if( status_success( st ) )
	{
	  p_list->capacity		= nItems;
	  p_list->itemSize		= itemSize;
	  p_list->nitems		= 0;
	  p_list->requiredCapacity	= 0;
	}
    }

  return st;
}

t_status common_list_reAllocate( t_size nItems, t_list * p_list )
{
  t_status	st;

  status_reset( & st );

  if( nItems == 0 || p_list == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_list_not_allocated( p_list ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  if( nItems == p_list->nitems )  return st;	// Nothing to do

  t_size bufsize = nItems * (p_list->itemSize);

  st = common_memory_reAllocate( bufsize, &(p_list->mem) );

  if( status_success( st ) )
    {
      p_list->capacity	= nItems;

      if( nItems < p_list->nitems )	// Memory was released, adjust size
          p_list->nitems = nItems;
    }

  return st;
}

t_status common_list_deallocate( t_list * p_list )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      // Clear fields of structure
      st = common_memory_deallocate( &(p_list->mem) );
      if( status_success( st ) )
	{
	  p_list->capacity		= 0;
	  p_list->requiredCapacity	= 0;
	  p_list->itemSize		= 0;
	  p_list->nitems		= 0;
	}
    }

  return st;
}

t_status common_list_getCapacity( const t_list * p_list, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_list_not_allocated( p_list ) )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_size = p_list->capacity;
    }

  return st;
}


t_status common_list_getRequiredCapacity( const t_list * p_list, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL || p_size ==NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_list_not_allocated( p_list ) )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_size = p_list->requiredCapacity;
    }

  return st;
}


t_status common_list_getData( const t_list * p_list, t_size item, void **  p_data )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL || p_data == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_list_not_allocated( p_list ) )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	{
	  // Get a pointer to the raw memory for item number "item"

	  *p_data = get_list_item( p_list, item );
	}
    }

  return st;
}

t_status common_list_getSize( const t_list * p_list, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL || p_size == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_list_not_allocated( p_list ) )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  *p_size = p_list->nitems;
    }

  return st;
}

t_status common_list_setSize( t_size size, t_list * p_list )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( p_list->mem.canary != OSAPI_COMMON_CANARY )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	p_list->nitems = size;
    }

  return st;
}


t_status common_list_setRequiredCapacity( t_size size, t_list * p_list )
{
  t_status	st;

  status_reset( & st );

  if( p_list == NULL )
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
  else
    {
      if( is_list_not_allocated( p_list ) )	// Not allocated
	  status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      else
	  p_list->requiredCapacity = size;
    }

  return st;
}



t_status common_list_copy( const t_list * p_source, t_list * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_list_not_allocated( p_source ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  if( is_list_data_equal( p_source, p_target ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_memoverlap, &st );
      return st;
    }

  if( is_list_not_allocated( p_target ) && is_list_not_null( p_target ) )
      common_list_deallocate( p_target );	// Ignore return status

  st = common_list_allocate( p_source->nitems, p_source->itemSize, p_target );

  if( status_success( st ) )
    {
      errno = 0;

      void * ptr = memcpy( get_list_address( p_target ), get_list_address( p_source ), (size_t) get_list_used_capacity( p_source ) );
      if( ptr != p_target->mem.data || errno != 0 )
	  status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
      else
	{
	  p_target->nitems 		= p_source->nitems;
	  p_target->requiredCapacity	= p_source->requiredCapacity;
	}
    }

  return st;
}


t_status common_list_copyFrom( const t_list * p_source, t_size sourceItem, t_size targetSize, void * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL || sourceItem == 0 || targetSize == 0 )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_list_not_allocated( p_source ) )	// Not allocated
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  if( targetSize != p_source->itemSize )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_notEnoughMemory, &st );
      return st;
    }

  errno = 0;

  void * p_item = get_list_item( p_source, sourceItem );

  void * ptr = memcpy( p_target, p_item , (size_t) p_source->itemSize );

  if( ptr != p_target || errno != 0 )
      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );

  return st;
}


// Add sourceSize to function parameters to force clients to provide the size of the raw memory (sanity check)
// This call can leave empty items if the item > p_target->size
t_status common_list_copyTo( const void * p_source, t_size sourceSize, t_size targetItem, t_list * p_target )
{
  t_status	st;

  status_reset( & st );

  if( p_source == NULL || p_target == NULL || targetItem == (t_size) 0 )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st );
      return st;
    }

  if( is_list_not_allocated( p_target ) )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_canary, &st );
      return st;
    }

  if( sourceSize != p_target->itemSize )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_notEnoughMemory, &st );
      return st;
    }

  if( p_target->capacity < targetItem )
    {
      status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_notEnoughCapacity, &st );
      return st;
    }

  errno = 0;

  void * p_item = get_list_item( p_target, targetItem );

  void * ptr = memcpy( p_item, p_source, (size_t) sourceSize );
  if( ptr != p_item || errno != 0 )
      status_eset( OSAPI_MODULE_COMMON, __func__, errno, &st );
  else
    {
      if( targetItem > p_target->nitems )
          p_target->nitems = targetItem;
    }

  return st;
}




