// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide String module API
//
// *****************************************************************************************

#ifndef STRING_STRING_BASIC_H_
#define STRING_STRING_BASIC_H_

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

// Standard types
#include <stdbool.h>

// Own declarations
#include <string/string_types_basic.h>
#include "string/string_platform.h"


// *****************************************************************************************
//
// Section: String module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// + Basic String management (single byte)
// ++ Life cycle
t_status string_basic_new			( t_size, t_string *			);
t_status string_basic_create			( const char *, t_string *		);
t_status string_basic_delete			( t_string *				);

// ++ Operations
t_status string_basic_put			( const char *, t_string *		);
t_status string_basic_copy			( const char *, t_string *		);
t_status string_basic_size			( t_string *, t_size *			);
t_status string_basic_clone			( t_string *, t_string *		);

// + Content management
t_status string_basic_print			( t_string *				);
t_status string_basic_get			( t_string *, t_size, char *		);

// + Instances management
t_status string_basic_equal			( t_string *, t_string *, bool	*	);
t_status string_basic_compare			( t_string *, t_string *, Byte	*	);
t_status string_basic_compareIcase		( t_string *, t_string *, Byte	*	);
t_status string_basic_concat			( t_string *, t_string *, t_string *	);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* STRING_STRING_BASIC_H_ */
