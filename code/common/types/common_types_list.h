// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a generic list type
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPES_LIST_H_
#define OSAPI_COMMON_TYPES_LIST_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI headers
#include "general/general_types.h"

// Import own types
#include "common/types/common_types_memory.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Structure supporting a self describing list of items
/// The reasoning behind this type is that many interface functions require too many parameters
/// - Size of the allocated memory
/// - Usage of the allocated memory
///   It should be the same but a system is dynamic and between calls such as getNumberItems and getItems
///   the number of items may have shrink or grow
/// - The address of the memory address
/// - Also, ideally a parameter that specifies how big the list is currently
struct osapi_s_list
{
  t_size	capacity;		///< The number of items that exist currently
  t_size	requiredCapacity;	///< The number of items would be required (in case the capacity is less what was required )
  t_size	itemSize;		///< Size, in bytes, of each item in memory. This is typically the sizeof of a given type
  t_size	nitems;			///< Current capacity usage, i.e. how many items are in the list
  t_memory  	mem;			///< Allocated memory to store the array of items
};

typedef struct osapi_s_list		t_list;


#endif /* OSAPI_COMMON_TYPES_LIST_H_ */
