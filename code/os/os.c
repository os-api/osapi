// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS module entry point implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_os.h"
#include "status/status.h"

// Own declarations
#include "os/os.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status os_module_supported( void )
{
  RETURN_STATUS_SUCCESS;
}


t_status os_name_get( t_osInfo * p_osInfo, char ** p_osName )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osName == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osName = p_osInfo->kernel;

 return st;
}


t_status os_version_get( t_osInfo * p_osInfo, char ** p_osVersion )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osVersion == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osVersion = p_osInfo->version;

 return st;
}

t_status os_release_get( t_osInfo * p_osInfo, char ** p_osRelease )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osRelease == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osRelease = p_osInfo->release;

 return st;
}

t_status os_node_get( t_osInfo * p_osInfo, char ** p_osNode )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osNode == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osNode = p_osInfo->node;

 return st;
}

t_status os_machine_get( t_osInfo * p_osInfo, char ** p_osMachine )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osMachine == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osMachine = p_osInfo->machine;

 return st;
}

t_status os_domain_get( t_osInfo * p_osInfo, char ** p_osDomain )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osDomain == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osDomain = p_osInfo->domain;

 return st;
}


t_status os_provider_get( t_osInfo * p_osInfo, char ** p_osProvider )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osProvider == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osProvider = p_osInfo->provider;

 return st;
}

t_status os_providerRelease_get( t_osInfo * p_osInfo, char ** p_osProviderRelease )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || p_osProviderRelease == (char **) 0 )
     status_iset( OSAPI_MODULE_OS, __func__, e_os_params, &st );
 else
     *p_osProviderRelease = p_osInfo->provider_release;

 return st;
}
