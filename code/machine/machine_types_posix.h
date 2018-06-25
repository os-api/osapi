// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common POSIX declarations
//
// *****************************************************************************************

#ifndef MACHINE_TYPES_POSIX_H_
#define MACHINE_TYPES_POSIX_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif	// Posix only

#endif /* MACHINE_TYPES_POSIX_H_ */
