// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API for buffer functionality
//
// *****************************************************************************************

#ifndef OSAPI_PROC_LIST_H_
#define OSAPI_PROC_LIST_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Common includes
#include "common/types/common_types_list.h"

// Own declarations
#include "proc/proc_types.h"
#include "proc/proc_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
/// @brief The process management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Allocate memory in the HEAP for a list of items
/// The "list" is implemented as an array of bytes
/// @param [in] nItems		- Number of items for the memory allocation
/// @param [in] itemSize	- Size, in bytes, of each item
/// @param [out] list		- List descriptor
/// @return Operation status
t_status proc_list_allocate( t_size nItems, t_size itemSize, t_list * list );

/// @brief Resize a list of items
/// @param [in] nItems		- New number of items
/// @param [out] list		- List descriptor
/// @return Operation status
t_status proc_list_reAllocate( t_size nItems, t_list * list );

/// @brief Deallocate list
/// @param [in] list - List descriptor
/// @return Operation status
t_status proc_list_deallocate( t_list * list );

/// @brief Get the list capacity in terms of allocated items
/// @param [in] list	- List descriptor
/// @param [out] size	- List capacity
/// @return Operation status
t_status proc_list_getCapacity( const t_list * list, t_size * size );

/// @brief Check if the list can store N items
/// @param [in] list	- List descriptor
/// @param [in] size	- Required capacity from list
/// @return Success if enough capacity, error status otherwise
t_status proc_list_hasCapacity( const t_list * list, t_size size );

/// @brief Get the required list capacity in terms of allocated items
/// The required capacity is needed in case a list is not big enough to hold all elements
/// @param [in] list	- List descriptor
/// @param [out] size	- List required capacity
/// @return Operation status
t_status proc_list_getRequiredCapacity( const t_list * list, t_size * size );

/// @brief Get the memory address of a given data item (of a list)
/// @param [in]  list	- List descriptor
/// @param [in]  item	- Item number for which the address is needed
/// @param [out] data	- Address of the managed naked/raw HEAP memory
/// @return Operation status
t_status proc_list_getData( const t_list * list, t_size item,  void **  data );

/// @brief Get the current list usage in terms of number of items
/// @param [in]  list	- List descriptor
/// @param [out] size	- List usage size
/// @return Operation status
t_status proc_list_getSize( const t_list * list, t_size * size );

/// @brief Set the current list usage
/// @param [in]     size	- New list usage size
/// @param [in,out] list	- List descriptor
/// @return Operation status
t_status proc_list_setSize( t_size size, t_list * list );

/// @brief Set the current list required capacity
/// The required capacity is needed in case a list is not big enough to hold all elements
/// @param [in]     size	- New list required capacity
/// @param [in,out] list	- List descriptor
/// @return Operation status
t_status proc_list_setRequiredCapacity( t_size size, t_list * list );

/// @brief Copy two list memories
/// List cannot overlap in any way (this generates an error)
/// @param [in]  source	- Address of the source list
/// @param [out] target - Address of the target/destination list
/// @return Operation status
t_status proc_list_copy( const t_list * source, t_list * target );

/// @brief Copy from a list item to a naked/raw memory location
/// @param [in]  source 	- Address of the source buffer
/// @param [in]  sourceItem	- Item number to copy
/// @param [in]  targetSize	- Size of destination memory buffer
/// @param [out] target 	- Raw destination memory address
/// @return Operation status
t_status proc_list_copyFrom( const t_list * source, t_size sourceItem, t_size targetSize, void * target );

/// @brief Copy from a naked/raw memory into a list item
/// @param [in]  source     - Raw source memory address
/// @param [in]  sourceSize - Size of the source memory content
/// @param [in]  targetItem - Item number to copy into
/// @param [out] target     - List descriptor
/// @return Operation status
t_status proc_list_copyTo( const void * source, t_size sourceSize, t_size targetItem, t_list * target );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_LIST_H_ */
