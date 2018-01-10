/*
 * sec.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef SEC_SEC_H_
#define SEC_SEC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <status/status.h>
#include <sec/sec_defs.h>
#include <sec/sec_platform.h>

// Functions bellow
t_status sec_module_supported		( void			);
t_status sec_userID_get			( t_user_id	*	);
t_status sec_groupID_get		( t_group_id	*	);

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* SEC_SEC_H_ */
