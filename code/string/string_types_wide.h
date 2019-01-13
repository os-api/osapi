// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module declarations for wide C String types
//
// *****************************************************************************************

#ifndef OSAPI_STRING_TYPES_WIDE_H_
#define OSAPI_STRING_TYPES_WIDE_H_

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
// Section: Type declarations
//
// *****************************************************************************************

/// The OSAPI C String structure for wide characters
struct osapi_wide_string
{
  uint64_t	tsize;			///< Total size of the allocated string memory
  uint64_t	csize;			///< Current used size
  wchar_t    *	ps_location;		///< Pointer to String location
};

/// The OSAPI C String type for wide characters
typedef struct osapi_wide_string	t_wString;

/// Define a null OSAPI wide string
#define OSAPI_WIDE_STRING_NULL_POINTER	(( t_wString *) 0)

/// Define a null pointer for an array of wide characters
#define OSAPI_WIDE_CHAR_NULL_POINTER	(( wchar_t   *) 0)


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_STRING_TYPES_WIDE_H_ */
