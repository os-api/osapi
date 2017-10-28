/*
 * os_posix.c
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#include "../../code/os/os_posix.h"

#include <string.h>

#include "../../code/error/error_os.h"
#include "../../code/os/os.h"

t_status os_info_get( t_osInfo * p_osInfo )
{
 t_status	st;

 status_reset( & st );

 errno = 0;
 if( uname( p_osInfo ) )
	 status_set( OS, f_os_info_get, (unsigned int) errno, &st );

 return st;
}

t_status os_name_get( t_osInfo * p_osInfo, char * p_osName )
{
 t_status	st;

 status_reset( & st );

 if( p_osInfo == (t_osInfo *) 0 || (p_osName == (char *) 0) )
	 status_set( OS, f_os_name_get, (unsigned int) e_os_params, &st );
 else
   {
	 errno = 0;
	 if( strcpy( p_osName, p_osInfo->sysname ) )
	     status_set( OS, f_os_name_get, (unsigned int) errno, &st );
   }

 return st;
}


