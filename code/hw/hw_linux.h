/*
 * hw_linux.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef HW_HW_LINUX_H_
#define HW_HW_LINUX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <sys/sysinfo.h>

#include <status/status.h>

typedef struct sysinfo		t_mem;

t_status hw_physicalRam_get( t_mem *, uint64_t );

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* HW_HW_LINUX_H_ */
