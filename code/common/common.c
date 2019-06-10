// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common Module Linux function implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Include standard headers
#include <strings.h>
#include <ctype.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/common.h"



// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

int common_options_get( const t_option * moduleOptions, char * providedOptions[] )
{
 int	opt = 0;

 if( moduleOptions != NULL && providedOptions != NULL )
     for( int i=0; providedOptions[ i ] != OSAPI_NULL_CHAR_POINTER; i++  )
        {
 	  for( int j=0; moduleOptions[ j ].value != OSAPI_OPTIONS_END; j++ )
 	     {
	       // Compares current option[i] with list of all available options
	       if( strcasecmp( providedOptions[ i ], moduleOptions[ j ].name ) == 0 )
		 {
		   // Match found: Add option to the list (int/opt)
		   opt |= moduleOptions[ j ].value;
		   break;
		 }
	      }
        }

 return opt;
}


// All elements of a C-string are digits?
bool common_string_isDigit( const char * str )
{
 bool rv = true;

 if( str == NULL )
     rv = false;
 else
   {
     for( int i=0; i < strlen( str ); i++ )
        {
          if( ! isdigit( (int) str[ i ] ) )
            {
              rv = false;
              break;
            }
        }
   }

 return rv;
}


