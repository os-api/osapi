// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Definition of Signal types
//
// *****************************************************************************************

#ifndef OSAPI_PROC_SIGNAL_TYPES_H_
#define OSAPI_PROC_SIGNAL_TYPES_H_


// *****************************************************************************************
//
// Section: Import Headers
//
// *****************************************************************************************

// Own headers
#include "proc/posix/proc_posix_signal_macros.h"

// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


#define signal_level_X(a, b, c) a b,
enum osapi_signal_level
{
  #include "proc/mappings/table_signal.h"
};

#undef signal_level_X




#endif /* OSAPI_PROC_SIGNAL_TYPES_H_ */
