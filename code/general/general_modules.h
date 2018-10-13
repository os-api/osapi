// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Definition of Module IDs
//
// *****************************************************************************************

#ifndef GENERAL_GENERAL_MODULES_H_
#define GENERAL_GENERAL_MODULES_H_


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


#define module_X(a, b, c) a b,
enum module_id
{
  #include <general/table_modules.h>
};

#undef module_X

#endif /* GENERAL_GENERAL_MODULES_H_ */
