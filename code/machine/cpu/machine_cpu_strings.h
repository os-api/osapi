// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define CPU submodule strings
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_STRINGS_H_
#define OSAPI_MACHINE_CPU_STRINGS_H_


// *****************************************************************************************
//
// Section: CPU string mappings
//
// *****************************************************************************************

// Short version of CPU feature name
#define osapi_machine_cpu_feature_X(a, b, c, d) [a]=c,

static const char * osapi_machine_cpu_feature_string[] =
{
  #include "machine/cpu/mappings/table_cpu_features.h"
};

#undef osapi_machine_cpu_feature_X

// Long version of CPU feature name
#define osapi_machine_cpu_feature_X(a, b, c, d) [a]=d,

static const char * osapi_machine_cpu_feature_long_string[] =
{
  #include "machine/cpu/mappings/table_cpu_features.h"
};

#undef osapi_machine_cpu_feature_X


#define osapi_machine_cpuarch_X(a, b, c, d) [a]=c,

static const char * osapi_machine_cpuarch_string[] =
{
  #include "machine/cpu/mappings/table_cpuarch.h"
};

#undef osapi_machine_cpuarch_X


#define osapi_machine_cpuarch_X(a, b, c, d) d,

static const int osapi_machine_cpuarch_endianess_A[] =
{
  #include "machine/cpu/mappings/table_cpuarch.h"
};

#undef osapi_machine_cpuarch_X


#define osapi_machine_endianess_X(a, b, c) [a]=c,

static const char * osapi_machine_endianess_string[] =
{
  #include "machine/cpu/mappings/table_endianess.h"
};

#undef osapi_machine_endianess_X


#define osapi_machine_cpu_vendors_X(a, b, c) [a]=c,

static const char * osapi_machine_cpu_vendor_string[] =
{
  #include "machine/cpu/mappings/table_vendors.h"
};

#undef osapi_machine_cpu_vendors_X



#define osapi_machine_cpu_signature_X(a, b, c) [a]=c,

static const char * osapi_machine_cpu_signature_string[] =
{
  #include "machine/cpu/mappings/table_cpu_signatures.h"
};

#undef osapi_machine_cpu_signature_X


#endif /* OSAPI_MACHINE_PRIV_H_ */
