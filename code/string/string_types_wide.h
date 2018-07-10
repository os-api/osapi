// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module declarations
//
// *****************************************************************************************

#ifndef STRING_STRING_TYPES_WIDE_H_
#define STRING_STRING_TYPES_WIDE_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <stdint.h>

// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

struct osapi_wide_string
{
  uint64_t	tsize;			// Total size of the allocated string memory
  uint64_t	csize;			// Current used size
  wchar_t    *	ps_location;		// Pointer to String location
};


typedef struct osapi_wide_string	t_wString;

#define OSAPI_WIDE_STRING_NULL_POINTER	(( t_wString *) 0)
#define OSAPI_WIDE_CHAR_NULL_POINTER	(( wchar_t   *) 0)

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STRING_STRING_TYPES_WIDE_H_ */
