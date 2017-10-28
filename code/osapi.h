/*
 * system.h
 *
 *  Created on: 28/03/2017
 *  Author: joao
 *  Purpose: Master interface header that includes all system interfaces
 */

#ifndef OSAPI_H_
#define OSAPI_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include "../code/proc/proc.h"
// #include <machine/machine.h>
#include "../code/hw/hw.h"
#include "../code/os/os.h"
#include "../code/sec/sec.h"
#include "../code/clock/clock.h"
#include "../code/util/util.h"
#include "../code/string/string.h"

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_H_ */
