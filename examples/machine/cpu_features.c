// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Get the list of current features supported by the CPU
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
#include <string.h>

// Import OSAPI header
#include "osapi.h"

// *****************************************************************************************
//
// Section: Constant definitions
//
// *****************************************************************************************

static const char * WS = " ";

// *****************************************************************************************
//
// Section: Function definitions
//
// *****************************************************************************************

#define check_status { if( status_failure( st ) )  { status_message_print( st ); exit( 1 );  } }


int main( int argc, char * argv[] )
{
  t_status		st;
  t_size		nFeatures	= 0;
  size_t		len		= 4000;		// Should be enough
  t_size		nSize, dSize;
  const char *  	name		= NULL;
  const char *  	desc		= NULL;
  t_cpu_feature_list	features;
  t_list		listName, listDesc;
  char			flags [ 4001 ];

  // Clear feature flags
  memset( flags, '\0', sizeof(flags) );

  // First check that the library supports CPU features for this CPU type
  st = machine_cpuFeature_supports();		  					check_status

  // Next, get the list of all available CPU features on the current running logical CPU
  st = machine_cpuFeature_getAll( &features );  					check_status

  // Next get the number of features found
  st = machine_cpuFeature_count( &features, &nFeatures ); 				check_status

  printf( "List of CPU Supported features (%lu)\n\n", nFeatures );

  // Allocate space for the name and description feature lists
  st = proc_list_allocate( nFeatures, (t_size) sizeof( const char * ),  &listName ); 	check_status
  st = proc_list_allocate( nFeatures, (t_size) sizeof( const char * ),  &listDesc ); 	check_status

  // Get the list of available feature names
  st = machine_cpuFeature_getListName		( &features, &listName ); 		check_status

  // Get the list of available feature descriptions
  st = machine_cpuFeature_getListDescription	( &features, &listDesc  );		check_status

  // Get the list of available feature names
  st = proc_list_getSize			( &listName, &nSize );			check_status

  // Get the list of available feature descriptions
  st = proc_list_getSize			( &listDesc, &dSize );			check_status

  if( nSize != dSize || nSize != nFeatures )
    {
      fprintf( stderr, "Mismatch at the number of Features. Exiting.." );
      exit( 2 );
    }

  // Finally, print the feature name and description
  flags[ 0 ] = '\0';
  for( unsigned int i=1; i <= nFeatures; i++ )
     {
       st = proc_list_copyFrom( &listName, i, sizeof(const char *), (void *) &name );	check_status

       strncat( flags, name, len     );
       strncat( flags, WS,   len - 1 );
       len = 4000 - strlen( flags );

       st = proc_list_copyFrom( &listDesc, i, sizeof(const char *), (void *) &desc );	check_status

       printf( "%s - %s\n", name, desc );
     }

  printf("\nFlags: %s\n", flags );
  printf("\n");

  // Deallocate lists
  proc_list_deallocate( &listName );
  proc_list_deallocate( &listDesc );

 return 0;
}
