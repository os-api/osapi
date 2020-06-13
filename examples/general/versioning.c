// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Get the current version baseline
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
 printf("Current Library Release: %lu\n", osapi_get_release() );
 // Or 
 printf("Current Library Release: %s\n", osapi_get_release_string() );

 printf("Current Library Version: %lu\n", osapi_get_version() );
 // Or 
 printf("Current Library Version: %s\n", osapi_get_version_string() );

 // Possible returns from the next call: 
 // osapi_version_unstable
 // osapi_version_stable
 printf("Current Library Version stability: %d\n", osapi_get_version_stability() );
 // Or 
 printf("Current Library Version stability: %s\n", osapi_get_version_stability_string() );

 return 0;
}
