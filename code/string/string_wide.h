// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide String module API for wide C string types
//
// *****************************************************************************************

#ifndef OSAPI_STRING_WIDE_H_
#define OSAPI_STRING_WIDE_H_

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

// Standard headers
#include <stdbool.h>

// Include own types
#include "string/string_types_wide.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup STRING
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: String module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


// + Wide String management (multi byte)
// ++ Life cycle
t_status string_wide_new			( t_size size, t_wString * p_string				);
t_status string_wide_create			( const wchar_t * p_initial_string, t_wString * p_string	);
t_status string_wide_delete			( t_wString * p_string						);

// ++ Operations
t_status string_wide_put			( const wchar_t * message, t_wString * p_string			);
t_status string_wide_copy			( const wchar_t *, t_wString *		);
t_status string_wide_size			( t_wString *, t_size *			);
t_status string_wide_clone			( t_wString * ps_old, t_wString * ps_new			);

// + Content management
t_status string_wide_print			( t_wString *							);
t_status string_wide_get			( t_wString *, t_size, wchar_t *				);

// + Instances management
t_status string_wide_equal			( t_wString *, t_wString *, bool	*			);
t_status string_wide_compare			( t_wString *, t_wString *, Byte	*			);
// t_status string_wide_compareIcase		( t_wString *, t_wString *, Byte	*			);
t_status string_wide_concat			( t_wString *, t_wString *, t_wString *				);


#pragma GCC visibility pop			// End of public interface


///@}
///@}


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_STRING_WIDE_H_ */
