// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module declarations
//
// *****************************************************************************************

#ifndef STRING_STRING_DEFS_H_
#define STRING_STRING_DEFS_H_


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

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
