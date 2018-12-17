// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define module names
//
// *****************************************************************************************

#ifndef GENERAL_PRIV_H_
#define GENERAL_PRIV_H_


// Version string
#define osapi_version_X(a, b, c) c,

static const char * osapi_version[] =
{
  #include "general/mappings/table_version.h"
};

#undef osapi_version_X


// Version stability string
#define osapi_quality_X(a, b, c) [a]=c,

static const char * osapi_version_quality[] =
{
  #include "general/mappings/table_version_quality.h"
};

#undef osapi_quality_X


// Version stability string
#define osapi_protocol_X(a, b, c) [a]=c,

static const char * osapi_protocol[] =
{
  #include "general/mappings/table_protocol.h"
};

#undef osapi_protocol_X


// Module strings
#define module_X(a, b, c) [a]=c,

static const char * module_name[] = {
  #include "general/mappings/table_modules.h"
};

#undef module_X




#endif /* GENERAL_PRIV_H_ */
