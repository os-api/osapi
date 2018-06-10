/*
 * common_types_posix.h
 *
 *  Created on: 10/06/2018
 *      Author: joao
 */

#ifndef COMMON_TYPES_POSIX_H_
#define COMMON_TYPES_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif


#include <sys/types.h>

// Define POSIX opaque types that are cross functional modules
typedef uid_t	t_uid;		// User  ID
typedef gid_t	t_gid;		// Group ID


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* COMMON_TYPES_POSIX_H_ */
