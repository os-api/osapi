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
#include "proc/proc_list.h"


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************


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

t_status proc_list_hasCapacity( const t_list * list, t_size size )
{
 return common_list_hasCapacity( list, size );
}
