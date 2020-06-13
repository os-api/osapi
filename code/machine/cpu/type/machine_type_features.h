// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for CPU Features
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_FEATURES_H_
#define OSAPI_MACHINE_CPU_TYPE_FEATURES_H_



// *****************************************************************************************
//
// Section: Define Constants
//
// *****************************************************************************************

#define OSAPI_MACHINE_CPU_FEATURE_MAX		UINT16_MAX

// *****************************************************************************************
//
// Section: Import machine enums
//
// *****************************************************************************************

#define osapi_machine_cpu_feature_X(a, b, c, d) a b,

enum osapi_machine_cpu_feature_E {
  #include "machine/cpu/mappings/table_cpu_features.h"
};

#undef osapi_machine_cpu_feature_X


typedef	uint16_t	t_cpu_feature_size;


/// @brief Define a type for CPU features
struct osapi_machine_cpu_feature_S
{
  t_cpu_feature_size	max;						///< Maximum number of OSAPI supported CPU features (to avoid mismatches between clients and library)
  t_cpu_feature_size	avail;						///< Number of available CPU features (to speedup library functions)
 _Bool			feature[ osapi_machine_cpu_feature_max + 1 ];	///< Is Feature present?
};

typedef struct osapi_machine_cpu_feature_S	t_cpu_feature_list;




#endif /* OSAPI_MACHINE_CPU_TYPE_FEATURES_H_ */
