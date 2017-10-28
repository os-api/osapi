/*
 * string_defs.h
 *
 *  Created on: 23/04/2017
 *      Author: joao
 */

#ifndef STRING_STRING_DEFS_H_
#define STRING_STRING_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Define function IDs
enum
{
	f_string_none = 0,
	f_string_module_supported,

	// + Instance management
	// ++ Life cycle
	f_string_instance_new,
	f_string_instance_create,
	f_string_instance_delete,

	// ++ Operations
	f_string_instance_put,
	f_string_instance_set,
	f_string_instance_size,
	f_string_instance_clone,

	// + Content management
	f_string_message_print,
	f_string_message_get,

	// + Instances management
	f_string_instances_equal,
	f_string_instances_compare,
	f_string_instances_compareIcase,
	f_string_instances_concat,
	f_string_other
};


struct osapi_string
{
  uint64_t	tsize;			// Total size of the allocated string memory
  uint64_t	csize;			// Current used size
  char	    *	ps_location;		// Pointer to String location
};

typedef struct osapi_string	t_string;

#define OSAPI_STRING_NULL_POINTER	((t_string *) 0)

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STRING_STRING_DEFS_H_ */
