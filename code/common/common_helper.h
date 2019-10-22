// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common helper macros
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_HELPER_H_
#define OSAPI_COMMON_HELPER_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI types
#include "general/general_types.h"

// Import module headers
#include "common/common_defs.h"



// *****************************************************************************************
//
// Section: Macros for type memory
//
// *****************************************************************************************

// x must be a t_memory structure
#define is_memory_allocated(x)		(x->canary == OSAPI_COMMON_CANARY)
#define is_memory_not_allocated(x)	(x->canary != OSAPI_COMMON_CANARY)

// x must be a t_memory structure
#define set_memory_allocated(x)		(x->canary = OSAPI_COMMON_CANARY)
#define set_memory_unallocated(x)	(x->canary = 0)

// Compare two raw memory addresses
#define is_memory_data_equal(x,y)	(x->data == y->data)

// Check if memory descriptor is not pointing to a valid memory address
#define is_memory_null(x)		(x->data == NULL)
#define is_memory_not_null(x)		(x->data != NULL)

// Get memory information
#define get_memory_capacity(x)		(x->capacity)
#define get_memory_address(x)		(x->data)


// *****************************************************************************************
//
// Section: Macros for type buffer
//
// *****************************************************************************************

// x must be a t_buffer structure
#define is_buffer_allocated(x)		(x->mem.canary == OSAPI_COMMON_CANARY)
#define is_buffer_not_allocated(x)	(x->mem.canary != OSAPI_COMMON_CANARY)

// Compare two buffer data
#define is_buffer_data_equal(x,y)	(x->mem.data == y->mem.data)

// Check if buffer descriptor is not pointing to a valid memory address (or not)
#define is_buffer_null(x)		(x->mem.data == NULL)
#define is_buffer_not_null(x)		(x->mem.data != NULL)

// Get buffer information
#define get_buffer_size(x)		(x->size)
#define get_buffer_capacity(x)		(x->mem.capacity)
#define get_buffer_address(x)		(x->mem.data)


// *****************************************************************************************
//
// Section: Macros for type list
//
// *****************************************************************************************

// x must be a t_list structure
#define is_list_allocated(x)		(x->mem.canary == OSAPI_COMMON_CANARY)
#define is_list_not_allocated(x)	(x->mem.canary != OSAPI_COMMON_CANARY)

// Compare two buffer data
#define is_list_data_equal(x,y)		(x->mem.data == y->mem.data)

// Check if list descriptor is not pointing to a valid memory address
#define is_list_null(x)			(x->mem.data == NULL)
#define is_list_not_null(x)		(x->mem.data != NULL)

// Get list information

// x is the t_list and y is the item number
#define get_list_item(x,y)		( &( ( (Byte *) x->mem.data)[ ( (y - 1) * (x->itemSize) ) ] ) )
#define get_list_capacity(x)		(x->capacity)
#define get_list_size(x)		(x->nitems)
#define get_list_used_capacity(x)	( x->nitems * x->itemSize )
#define get_list_address(x)		(x->mem.data)


#define set_list_capacity(x,y)		(x->capacity = y)
#define set_list_requiredCapacity(x,y)	(x->requiredCapacity = y)
#define set_list_size(x,y)		(x->nitems = y )


// *****************************************************************************************
//
// Section: Macros for time
//
// *****************************************************************************************

#define get_time_precision( x )		(x->precision)
#define get_time_seconds( x )		(x->seconds)
#define get_time_fraction( x )		(x->fraction)




#endif /* OSAPI_COMMON_HELPER_H_ */
