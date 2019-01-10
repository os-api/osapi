// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module API
//
// *****************************************************************************************

#ifndef OSAPI_OS_H_
#define OSAPI_OS_H_

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

// Own declarations
#include "os/os_types.h"
#include "os/os_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup OS
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status os_module_supported		( void					);

/// @brief Get the Operating System information
/// @param in info - OS Information
/// @return Operation status
t_status os_info_get			( t_osInfo * info			);

/// @brief Get the OS name
/// @param in info - OS Info
/// @param out name - OS name
/// @return Operation status
t_status os_name_get			( t_osInfo * p_osInfo, char ** name	);

/// @brief Get the OS version
/// @param in info - OS Info
/// @param out version - OS version
/// @return Operation status
t_status os_version_get			( t_osInfo * info, char ** version	);

/// @brief Get the OS release
/// @param in info - OS Info
/// @param out release - OS release
/// @return Operation status
t_status os_release_get			( t_osInfo * info, char ** release	);

/// @brief Get the OS Node name
/// @param in info - OS Info
/// @param out nodename - OS node name
/// @return Operation status
t_status os_node_get			( t_osInfo * info, char ** nodename	);

/// @brief Get the machine name
/// @param in info - OS Info
/// @param out machine - Machine name
/// @return Operation status
t_status os_machine_get			( t_osInfo * info, char ** machine	);

/// @brief Get the machine domain name
/// @param in info - OS Info
/// @param out domainname - Machine domain name
/// @return Operation status
t_status os_domain_get			( t_osInfo * info, char ** domainname	);

/// @brief Get the OS provider name (Vendor)
/// @param in info - OS Info
/// @param out provider - Vendor name
/// @return Operation status
t_status os_provider_get		( t_osInfo * info, char ** provider	);

/// @brief Get the Vendor Release
/// @param in info - OS Info
/// @param out providerRelease - Vendor release
/// @return Operation status
t_status os_providerRelease_get		( t_osInfo * info, char ** providerRelease );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_OS_H_ */
