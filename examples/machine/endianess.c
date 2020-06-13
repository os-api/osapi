// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Get the current endianess of a system
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import standard headers
#include <stdio.h>
#include <stdlib.h>

// Import OSAPI header
#include "osapi.h"


// *****************************************************************************************
//
// Section: Function definitions
//
// *****************************************************************************************


int main( int argc, char * argv[] )
{
  t_status	st;
  t_cpu_endian	en;
  const char *  endianess	= NULL;
  const char *  cpuarch		= NULL;

  st = machine_cpu_getArch( &cpuarch );
  if( status_failure( st ) )
    { status_message_print( st ); exit( 1 );  }

  st = machine_cpu_getEndian( &en );
  if( status_failure( st ) )
    { status_message_print( st ); exit( 2 );  }

  st = machine_cpu_getEndianString( &endianess );
  if( status_failure( st ) )
    { status_message_print( st ); exit( 3 );  }

  printf("CPU Architecture is: %s\n", cpuarch );
  printf("CPU Architecture endianess type (%d) is: %s\n\n", en, endianess );

  if( osapi_endian_isBig() )	printf("Currently running in Big endian\n");
  else				printf("Currently running in Little endian\n");

 return 0;
}
