// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_POSIX_H_
#define OSAPI_PROC_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own headers
#include "proc/posix/proc_posix_types.h"

// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

t_status posix_library_load( const char * pathname, int options, t_library * p_library );


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_PROC_POSIX_H_ */
