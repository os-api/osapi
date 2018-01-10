/*
 * general_defs.h
 *
 *  Created on: 23/04/2017
 *      Author: joao
 */

#ifndef GENERAL_GENERAL_DEFS_H_
#define GENERAL_GENERAL_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <general/general_baseline.h>

#define	OSAPI_NULL_CHAR_POINTER		( (char * ) 0 )

#define OSAPI_EMPTY_STRING		""

typedef uint64_t			t_size;

typedef uint8_t				Byte;


#define module_X(a, b, c) a b,
enum module_id
{
  #include <general/table_modules.h>
};

#undef module_X


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* GENERAL_GENERAL_DEFS_H_ */
