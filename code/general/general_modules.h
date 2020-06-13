// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Definition of Module IDs
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_MODULES_H_
#define OSAPI_GENERAL_MODULES_H_


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


#define osapi_module_X(a, b, c) a b,
enum osapi_module_E
{
  #include "general/mappings/table_modules.h"
};

#undef osapi_module_X

#endif /* OSAPI_GENERAL_MODULES_H_ */
