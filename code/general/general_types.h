// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Generic type declarations
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_TYPES_H_
#define OSAPI_GENERAL_TYPES_H_

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
#define OSAPI_SPACE_STRING		" "

#define OSAPI_OPTIONS_END		-999999

typedef uint64_t			t_size;

typedef uint8_t				Byte;

typedef char				t_char;

typedef int				t_protocol;

// Own module types

typedef Byte				t_module;

// Define a generic pair name/value structure
struct s_optional_pair
{
  char *	name;
  int		value;
};

typedef struct s_optional_pair	t_option;

// Work around C/C++ attribute mismatches
#if __cplusplus
  #define OSAPI_NORETURN	[[noreturn]]
#else
  #define OSAPI_NORETURN	_Noreturn
#endif

// *****************************************************************************************
//
// Section: Macro definitions
//
// *****************************************************************************************

#define	osapi_bit_on(  x )	(x=1)
#define	osapi_bit_off( x )	(x=0)


#endif /* OSAPI_GENERAL_TYPES_H_ */
