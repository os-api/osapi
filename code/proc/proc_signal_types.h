// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Definition of Signal types
//
// *****************************************************************************************

#ifndef PROC_SIGNAL_TYPES_H_
#define PROC_SIGNAL_TYPES_H_


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


#define signal_level_X(a, b, c) a b,
enum osapi_signal_level
{
  #include <proc/linux/table_signal.h>
};

#undef signal_level_X

#endif /* PROC_SIGNAL_TYPES_H_ */
