/*
 * proc_posix.c
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>

#include "../../code/proc/proc.h"
#include "../../code/proc/proc_posix.h"

t_status proc_module_supported( void )
{
  return STATUS_SUCCESS;	// Posix supports process interface
}


t_status proc_pid_get( t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 *p_pid = (t_pid) getpid();

 return st;
}


t_status proc_parentPid_get( t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 // STATUS_SET( status_modules.PROC, status_func.PARENTPID_GET, );

 *p_pid = (t_pid) getppid();

 return st;
}


t_status proc_signal_send( t_pid pid, t_signal sig )
{
 t_status	st;

 status_reset( & st );

 if( kill( pid, sig ) != 0 )
     status_set( PROC, f_proc_signal_send, (unsigned int) errno, &st );

 return st;
}
