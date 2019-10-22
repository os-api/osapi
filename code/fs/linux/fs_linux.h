// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module Linux header
//
// *****************************************************************************************

#ifndef OSAPI_FS_LINUX_H_
#define OSAPI_FS_LINUX_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
// The following define forces the existence of an extended functionality
#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stat.h>
#include <unistd.h>

// General OSAPI headers
#include "general/general.h"
#include "status/status_types.h"

// Include own headers
#include "fs/type/fs_type_element.h"

// Compile only if is a Linux implementation
#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

t_status	linux_decode_element_info	( struct statx * p_stat, unsigned int selection, t_element * p_info );


#endif // Only in Linux mode

#endif // OSAPI_FS_LINUX_H_
