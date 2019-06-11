// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Master interface header that includes all system interfaces
//
// *****************************************************************************************

#ifndef OSAPI_H_
#define OSAPI_H_

/// @addtogroup OSAPI
/// @brief The Open System API library
///@{


// *****************************************************************************************
//
// Section: Import OS API headers
//
// *****************************************************************************************

#include "general/general.h"
#include "status/status.h"

// All Functional Modules

#include "string/string.h"
#include "clock/clock.h"
#include "sec/sec.h"
#include "machine/machine.h"
#include "os/os.h"
#include "log/log.h"
#include "proc/proc.h"
#include "util/util.h"
#include "io/io.h"
#include "com/com.h"
#include "fs/fs.h"

///@}

#endif /* OSAPI_H_ */
