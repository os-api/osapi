/*
 * sec_posix.h
 *
 *  Created on: 03/01/2018
 *      Author: joao
 */

#ifndef CODE_SEC_SEC_POSIX_H_
#define CODE_SEC_SEC_POSIX_H_

#ifndef _POSIX_SOURCE
  #define _POSIX_SOURCE
#endif

#include <unistd.h>
#include <sys/types.h>

typedef uid_t		t_user_id;
typedef gid_t		t_group_id;

#endif /* CODE_SEC_SEC_POSIX_H_ */
