// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status module entry point implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <error/errors_status.h>
#include <stdio.h>
#include <string.h>

// // Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************



void status_message_iprint( t_status status );
void status_message_eprint( t_status status );


void status_reset( t_status * p_status )
{
  p_status->module	=	OSAPI_MODULE_NONE;
  p_status->type 	= 	STATUS_INTERNAL;
  p_status->code 	= 	0;
  p_status->funcname	=	OSAPI_EMPTY_STRING;
}

void status_set( int module, Byte tp, const char * fname, int code, t_status * p_status )
{
  p_status->module	= (Byte) module;
  p_status->type	= tp;
  p_status->code	= code;
  p_status->funcname	= fname;
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

void status_message_print( t_status status )
{
  //printf("Status: (type, code)=(%d,%d)\n", s.type, s.code );

  if( status.type == STATUS_INTERNAL )
      status_message_iprint( status );
  else
      status_message_eprint( status );
}


const char * status_module_get( t_status * p_status )
{
  return module_name[ p_status->module ];
}

const char * status_function_get( t_status * p_status )
{
  return p_status->funcname;
}

const char * status_error_get( t_status * p_status )
{
  if( p_status->type == STATUS_INTERNAL )
      return osapi_errors[ p_status->module ][ p_status->code ];
  else
      return strerror(p_status->code);
}

const char * status_errorByType_get( int code, Byte module, Byte type )
{
  if( type == STATUS_INTERNAL )
      return osapi_errors[ module ][ code ];
  else
      return strerror(code);
}

const char * status_moduleByID_get( Byte module )
{
  return module_name[ module ];
}




