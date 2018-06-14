// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type declarations
//
// *****************************************************************************************

#ifndef PROC_PROC_TYPES_H_
#define PROC_PROC_TYPES_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// Import OS specific definitions
#ifdef	OS_LINUX
 #include "proc/proc_linux_types.h"
#endif


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* PROC_PROC_TYPES_H_ */
