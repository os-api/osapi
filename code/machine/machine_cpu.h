// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Machine CPU API
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_H_
#define OSAPI_MACHINE_CPU_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"
#include "common/types/common_types_list.h"
#include "common/types/common_type_cpu.h"

// Own declarations
#include "machine/cpu/type/machine_type_cpu.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup MACHINE
/// @brief The machine management module
///@{
///
/// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface


// *****************************************************************************************
//
// Section: Machine module API for CPU information
//
// *****************************************************************************************

/// @brief Retrieve the target (compiled) CPU architecture
/// @param [out] arch	- Name of CPU Architecture
/// @return Operation status
t_status machine_cpu_getArch			( const char ** arch );


/// @brief Obtain summary information about machine CPUs
/// @param [out] summary - Machine CPU summary information
/// @return Operation status
t_status machine_cpu_getSummary			( t_cpu_summary * summary );

/// @brief Obtain information about a machine CPU
/// @param [out] info - CPU information
/// @return Operation status
t_status machine_cpu_getInfo			( t_cpu * info );

/// @brief Retrieve a name that corresponds to a feature ID
/// @param [in]  cpu       - Machine CPU information
/// @param [in]  fid       - Feature ID
/// @param [out] available - True if available. False otherwise (Only if call is successful)
/// @return Operation status
t_status machine_cpu_isFeatureAvailable		( const t_cpu * cpu, unsigned int fid, bool * available );

/// @brief Execute a CPUID machine instruction
/// Provides raw access to the underline CPUID instruction
/// @param [in]  op       - Specific operation to execute
/// @param [in]  param    - Parameter to the operation (If none, set it to 0)
/// @param [out] regs 	  - List of CPU registers (machine architecture dependent)
/// @return Operation status
t_status machine_cpu_id				( uint32_t op, uint32_t param, t_cpu_regs * regs );


/// @brief Retrieve the endianess of a CPU architecture
/// @param [out] endian	  - Get the CPU endianess
/// @return Operation status
t_status machine_cpu_getEndian			( t_cpu_endian * endian );

/// @brief Retrieve the string describing the endianess of a CPU architecture
/// @param [out] endian	  - Get the CPU endianess string
/// @return Operation status
t_status machine_cpu_getEndianString		( const char ** endian );



// *****************************************************************************************
//
// Section: Machine module API for CPU Vendors
//
// *****************************************************************************************

/// @brief Retrieve the CPU Vendor name
/// @param [in]  nsize	- The size of the buffer where the name will be stored
/// @param [out] name 	- The Vendor name
/// @return Operation status
t_status machine_cpuVendor_getName		( t_size nsize, char ** name );


/// @brief Retrieve the CPU Vendor name form the Vendor ID
/// @param [in]  id	- The Vendor ID
/// @param [out] name 	- The Vendor name
/// @return Operation status
t_status machine_cpuVendor_getNameFromId	( uint16_t id, const char ** name );

/// @brief Retrieve the CPU Vendor Identification from a Vendors name
/// @param [in]  name	- The Vendor name
/// @param [out] id 	- The Vendor ID
/// @return Operation status
t_status machine_cpuVendor_getIDFromName	( const char * name, int * id );


// *****************************************************************************************
//
// Section: Machine module API for CPU features
//
// *****************************************************************************************

/// @brief Check if the OSAPI library or the CPU supports features
/// @return Success if feature reporting is available, otherwise Failure
t_status machine_cpuFeature_supports		( void );

/// @brief Retrieval all supported CPU features
/// @param [out] list 	- A list to contain the CPU supported features
/// @return Operation status
t_status machine_cpuFeature_getAll		( t_cpu_feature_list * list );

/// @brief Check if a feature is available in the feature list
/// @param [in]  list		- List of available CPU features
/// @param [in]  id       	- Feature ID
/// @param [out] available 	- True if available. False otherwise (Only if call is successful)
/// @return Operation status
t_status machine_cpuFeature_isAvailable		( const t_cpu_feature_list * list, unsigned int id, bool * available );


/// @brief Retrieve a name that corresponds to a feature ID
/// @param [in]  fid		- Feature ID
/// @param [out] name		- Name of feature
/// @return Operation status
t_status machine_cpuFeature_getName		( unsigned int fid, const char ** name );


/// @brief Retrieve a descroption that corresponds to a feature ID
/// @param [in]  fid		- Item identifier
/// @param [out] desc		- Feature description
/// @return Operation status
t_status machine_cpuFeature_getDescription	( unsigned int fid, const char ** desc );

/// @brief Count number of available features in list
/// @param [in]  list		- A list of features
/// @param [out] nfeatures	- Number of features found in list
/// @return Operation status
t_status machine_cpuFeature_count		( const t_cpu_feature_list * list, t_size * nfeatures );

/// @brief Retrieve a list containing pointers to Feature Names
/// @param [in]  features	- The feature list
/// @param [out] list		- A list of pointers to feature names
/// @return Operation status
t_status machine_cpuFeature_getListName		( const t_cpu_feature_list * features, t_list * list );


/// @brief Retrieve a list containing pointers to Feature Descriptions
/// @param [in]  features	- The feature list
/// @param [out] list		- A list of pointers to feature descriptions
/// @return Operation status
t_status machine_cpuFeature_getListDescription	( const t_cpu_feature_list * features, t_list * list );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif // OSAPI_MACHINE_CPU_H_
