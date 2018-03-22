/*
 * status.c
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#include <error/errors_priv.h>
#include <status/status.h>

#include <stdio.h>
#include <string.h>



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


void status_message_iprint( t_status s )
{
  printf("Module %s, function %s with status: %s.\n",
	 module_name[ s.module ],
	 s.funcname,
	 osapi_errors[ s.module ][ s.code ] );
}

void status_message_eprint( t_status s )
{
  printf("Module %s, function %s with status: %s.\n",
	 module_name[ s.module ],
	 s.funcname,
	 strerror(s.code) );
}

void status_message_print( t_status s )
{
  printf("Status: (type, code)=(%d,%d)\n", s.type, s.code );

  if( s.type == STATUS_INTERNAL )
      status_message_iprint( s );
  else
      status_message_eprint( s );
}


const char * status_module_get( t_status * ps )
{
  return module_name[ ps->module ];
}

const char * status_function_get( t_status * ps )
{
  return ps->funcname;
}

const char * status_error_get( t_status * ps )
{
  if( ps->type == STATUS_INTERNAL )
      return osapi_errors[ ps->module ][ ps->code ];
  else
      return strerror(ps->code);
}



