// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for CPU
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_TYPE_CPU_H_
#define OSAPI_MACHINE_TYPE_CPU_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers
#include <stdint.h>

// General OSAPI headers
#include "common/types/common_type_cpu.h"

// Import own elements
#include "machine/machine_platform.h"
#include "machine/cpu/type/machine_type_features.h"
#include "machine/cpu/type/machine_type_endian.h"
#include "machine/cpu/type/machine_type_arch.h"
#include "machine/cpu/type/machine_type_vendor.h"
#include "machine/cpu/type/machine_type_vm.h"


// *****************************************************************************************
//
// Section: Sanity checks
//
// *****************************************************************************************

osapi_static_assert( OSAPI_MACHINE_CPU_FEATURE_MAX > osapi_machine_cpu_feature_max, " CPU error: Number of features exceeds maximum" 	);


// *****************************************************************************************
//
// Section: Declarations
//
// *****************************************************************************************



/// @brief CPU ID information (For CPUs that support it)
struct osapi_machine_cpu_info_S
{
  char 		oem		[ OSAPI_MACHINE_CPU_SIZE_VENDORID	];	///< Name of OEM company
  char		family		[ OSAPI_MACHINE_CPU_SIZE_FAMILY		];	///< NAme of CPU family
  char		model_id	[ OSAPI_MACHINE_CPU_SIZE_MODEL		];	///< CPU Model ID
  char		model_name	[ OSAPI_MACHINE_CPU_SIZE_MODELNAME	];	///< CPU Model Name
  char		level		[ OSAPI_MACHINE_CPU_SIZE_REVISION	];	///< CPU revision level (stepping)
  char		virt		[ OSAPI_MACHINE_CPU_SIZE_VIRTUAL	];	///< CPU virtualization name/type
};

typedef	struct osapi_machine_cpu_info_S	t_cpu_info;


/// @brief A generic CPU type
struct osapi_machine_cpu_S
{
  uint8_t		canary;							///< Sanity checks
  t_cpu_info		info;							///< The CPU generic information
  t_cpu_feature_list	features;						///< The CPU supported features
};

typedef	struct osapi_machine_cpu_S		t_cpu;



/// @brief Machine CPU summary information
struct osapi_machine_cpu_summary_S
{
  t_cpu_info		info;			///< CPU information (assumes all CPUs with the same info)
  t_cpu_nthreads	nthreads;		///< Number of threads per core
  t_cpu_ncores		ncores;			///< Number of cores per CPU
  t_cpu_nlogical	ncpus_present;		///< Present Logical CPUs in the system
  t_cpu_nlogical	ncpus_available;	///< Available Logical CPUs in the system
  t_cpu_nsocket		sockets;		///< Number of sockets in the system
  t_cpu_endian		endianess;		///< CPU architecture endianness
};

typedef	struct osapi_machine_cpu_summary_S	t_cpu_summary;


#endif /* OSAPI_MACHINE_TYPE_CPU_H_ */
