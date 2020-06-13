// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Verify if the current system mets the baseline requirements
//		By compiling this code in the platform, the static baseline requirements are
//		validated. The runtime baseline requirements can be inquired as shown bellow.
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#include <stdio.h>

#include "general/general.h"


// *****************************************************************************************
//
// Section: Function definitions
//
// *****************************************************************************************


int main( int argc, char * argv[] )
{
 printf("Is Library baseline met: %s\n", osapi_verify_baseline() ? "True" : "False" );

 return 0;
}
