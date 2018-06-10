/*
 * sec_defs.h
 *
 *  Created on: 23/04/2017
 *      Author: joao
 */

#ifndef SEC_SEC_DEFS_H_
#define SEC_SEC_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// Define function IDs
enum
{
	f_sec_none = 0,
	f_sec_module_supported,
	f_sec_other
};


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* SEC_SEC_DEFS_H_ */
