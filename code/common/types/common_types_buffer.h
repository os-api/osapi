// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common declarations for a generic buffer type
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPES_BUFFER_H_
#define OSAPI_COMMON_TYPES_BUFFER_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI headers
#include "general/general_types.h"

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************

/// Structure supporting a self describing memory/buffer
/// The reasoning is that naked memory handling is more error prone and encapsulation of
/// memory supported by a "buffer" type can provided more robust code.
struct osapi_s_buffer
{
  t_size	capacity;		///< The buffer allocated capacity
  Byte		canary;			///< A MAGIC constant to indicate if the data pointer is really pointing to previously allocated memory
  t_size	size;			///< Current capacity usage, i.e. how many bytes are you using of the allocated capacity
  void	  *	data;			///< Allocated HEAP memory location
};

typedef struct osapi_s_buffer		t_buffer;


#endif /* OSAPI_COMMON_TYPES_BUFFER_H_ */
