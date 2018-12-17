/*
 * sec_defs.h
 *
 *  Created on: 23/04/2017
 *      Author: joao
 */

#ifndef SEC_SEC_TYPES_H_
#define SEC_SEC_TYPES_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#ifdef OS_LINUX
   #include <sec/linux/sec_linux.h>
#endif

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* SEC_SEC_TYPES_H_ */
