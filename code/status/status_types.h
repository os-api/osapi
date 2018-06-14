/*
 * status_types.h
 *
 *  Created on: 14/06/2018
 *      Author: joao
 */

#ifndef STATUS_TYPES_H_
#define STATUS_TYPES_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "general/general_types.h"

#define STATUS_MAX_ERROR_SIZE	1025

typedef int			t_status_error;
typedef Byte			t_status_mod;
typedef Byte			t_status_type;
typedef const char *		t_status_funcname;

// Definition of opaque status type

struct s_status
{
  t_status_error	code;
  t_status_mod		module;
  t_status_type		type;
  t_status_funcname	funcname;
};

typedef struct s_status		t_status;



#endif /* STATUS_TYPES_H_ */
