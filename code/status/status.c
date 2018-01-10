/*
 * status.c
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#include <status/status.h>

#include <stdio.h>
#include <string.h>


#include <error/errors_priv.h>

void status_message_iprint( t_status status );
void status_message_eprint( t_status status );


void status_reset( t_status * status )
{
  status->module	=	OSAPI_MODULE_NONE;
  status->type 		= 	STATUS_INTERNAL;
  status->code 		= 	0;
  status->funcname	=	OSAPI_EMPTY_STRING;
}

void status_set( int module, Byte tp, const char * fname, int code, t_status * status )
{
  status->module	= (Byte) module;
  status->type		= tp;
  status->code		= code;
  status->funcname	= fname;
}


void status_message_iprint( t_status status )
{
  printf("Module %s, function %s with status: %s.\n",
	 module_name[ status.module ],
	 status.funcname,
	 osapi_errors[ status.module ][ status.code ] );
}

void status_message_eprint( t_status status )
{
  printf("Module %s, function %s with status: %s.\n",
	 module_name[ status.module ],
	 status.funcname,
	 strerror(status.code) );
}

void status_message_print( t_status status )
{
  printf("Status: (type, code)=(%d,%d)\n", status.type, status.code );

  if( status.type == STATUS_INTERNAL )
      status_message_iprint( status );
  else
      status_message_eprint( status );
}

