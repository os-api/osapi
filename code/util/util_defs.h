/*
 * util_defs.h
 *
 *  Created on: 23/04/2017
 *      Author: joao
 */

#ifndef UTIL_UTIL_DEFS_H_
#define UTIL_UTIL_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// Define function IDs
enum
{
	f_util_none = 0,
	f_util_module_supported,
	f_util_other
};


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* UTIL_UTIL_DEFS_H_ */
