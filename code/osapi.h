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

#include <general/general.h>

// Functional Modules

#include "string/string.h"
#include "clock/clock.h"
#include "sec/sec.h"
#include "hw/hw.h"
#include "os/os.h"
#include "log/log.h"
#include "proc/proc.h"
#include "util/util.h"



// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_H_ */
