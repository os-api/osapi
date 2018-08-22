// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Generic type declarations
//
// *****************************************************************************************

#ifndef GENERAL_GENERAL_DEFS_H_
#define GENERAL_GENERAL_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

// Generic OSAPI wide types
#define	OSAPI_NULL_CHAR_POINTER		( (char * ) 0 )

#define OSAPI_EMPTY_STRING		""

#define OSAPI_OPTIONS_END		-999999

typedef uint64_t			t_size;

typedef uint8_t				Byte;

typedef char				t_char;

typedef int				t_protocol;

// Own module types

#define module_X(a, b, c) a b,
enum module_id
{
  #include <general/table_modules.h>
};

#undef module_X

// Define a generic pair name/value structure
struct s_optional_pair
{
  char *	name;
  int		value;
};

typedef struct s_optional_pair	t_option;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* GENERAL_GENERAL_DEFS_H_ */
