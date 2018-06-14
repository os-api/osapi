// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide String module API
//
// *****************************************************************************************

#ifndef STRING_STRING_H_
#define STRING_STRING_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include "status/status_types.h"
#include "string/string_platform.h"
#include <string/string_types.h>

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status string_module_supported			( void					);

// + Instance management
// ++ Life cycle
t_status string_instance_new				( t_size, t_string *			);
t_status string_instance_create				( const char *, t_string *		);
t_status string_instance_delete				( t_string *				);

// ++ Operations
t_status string_instance_put				( const char *, t_string *		);
t_status string_instance_copy				( const char *, t_string *		);
t_status string_instance_size				( t_string *, t_size *			);
t_status string_instance_clone				( t_string *, t_string *		);

// + Content management
t_status string_message_print				( t_string *				);
t_status string_message_get				( t_string *, t_size, char *		);

// + Instances management
t_status string_instances_equal				( t_string *, t_string *, _Bool	*	);
t_status string_instances_compare			( t_string *, t_string *, Byte	*	);
t_status string_instances_compareIcase			( t_string *, t_string *, Byte	*	);
t_status string_instances_concat			( t_string *, t_string *, t_string *	);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STRING_STRING_H_ */
