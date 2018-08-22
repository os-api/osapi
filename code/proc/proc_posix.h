// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) POSIX declarations
//
// *****************************************************************************************

#ifndef PROC_POSIX_H_
#define PROC_POSIX_H_

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
#include "proc/proc_posix_types.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status posix_library_load( const char * pathname, int options, t_library * p_library );


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* PROC_POSIX_H_ */
