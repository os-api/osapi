/*
 * hw.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef HW_HW_H_
#define HW_HW_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include "../../code/status/status.h"
#include "../../code/hw/hw_defs.h"
#include "../../code/hw/hw_platform.h"

// Functions bellow
t_status	hw_module_supported		( void					);

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* HW_HW_H_ */
