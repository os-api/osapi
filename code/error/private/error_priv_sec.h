// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Sec private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_SEC_H_
#define CODE_ERR_ERROR_PRIV_SEC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include <error/modules/error_sec.h>

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define error_sec_X(a, b, c) [a]=c,

static const char * sec_errors[] =
{
  #include <error/mappings/table_sec.h>
};

#undef error_sec_X

#endif /* CODE_ERR_ERROR_PRIV_SEC_H_ */
