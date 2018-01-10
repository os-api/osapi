/*
 * util.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <status/status.h>
#include <util/util_defs.h>
#include <util/util_platform.h>

// Functions bellow
t_status util_module_supported			( void					);

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* UTIL_UTIL_H_ */
