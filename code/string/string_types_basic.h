// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module declarations for basic C strings
//
// *****************************************************************************************

#ifndef OSAPI_STRING_TYPES_BASIC_H_
#define OSAPI_STRING_TYPES_BASIC_H_

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

struct osapi_basic_string
{
  uint64_t	tsize;			// Total size of the allocated string memory
  uint64_t	csize;			// Current used size
  char	    *	ps_location;		// Pointer to String location
};

typedef struct osapi_basic_string	t_string;

#define OSAPI_STRING_NULL_POINTER	(( t_string  *) 0)


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_STRING_TYPES_BASIC_H_ */
