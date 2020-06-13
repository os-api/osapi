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
#include <stdbool.h>

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup GENERAL
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************

// Generic OSAPI wide types
/// Definition of a null char pointer
#define	OSAPI_NULL_CHAR_POINTER		( (char * ) 0 )

/// Definition of an empty string
#define OSAPI_EMPTY_STRING		""

/// Definition of a white space string
#define OSAPI_SPACE_STRING		" "

/// A marker for end of array
#define OSAPI_OPTIONS_END		-999999

/// Definition of OSAPI size type
typedef uint64_t			t_size;

/// Definition of OSAPI size type
typedef int64_t				t_offset;

/// Definition of a Byte type
typedef uint8_t				Byte;

/// Definition of own char type
typedef char				t_char;

/// Definition of a protocol type
typedef int				t_protocol;

// Own module types

/// Definition of the module type
typedef Byte				t_module;

/// Defines a generic pair name/value structure
struct general_optional_pair_S
{
  char *	name;	///< The name  part of the pair
  int		value;	///< The value part of the pair
};

/// The definition of a generic pair type
typedef struct general_optional_pair_S	t_option;



///@}
///@}


#endif /* OSAPI_GENERAL_TYPES_H_ */
