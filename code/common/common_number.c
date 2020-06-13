// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common Module Linux function implementation for an item list
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
#include <stdlib.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_common.h"
#include "status/status.h"


// Own declarations
#include "common/common_defs.h"
#include "common/common_number.h"




// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************




t_status common_number_add( int64_t x, int64_t y, int64_t * result )
{
 t_status	st;

 status_reset( & st );

 if( result == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( osapi_number_add( x, y, result ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 return st;
}


t_status common_number_subtract( int64_t x, int64_t y, int64_t * result )
{
 t_status	st;

 status_reset( & st );

 if( result == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( osapi_number_sub( x, y, result ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 return st;
}


t_status common_number_multiply( int64_t x, int64_t y, int64_t * result )
{
 t_status	st;

 status_reset( & st );

 if( result == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( osapi_number_mul( x, y, result ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 return st;
}





t_status common_realNumber_add( int64_t i1, int64_t f1, int64_t i2, int64_t f2, int64_t ceiling, int64_t * p_ir, int64_t * p_fr )
{
 t_status	st;

 status_reset( & st );

 // Validate first all inputs
 if( p_ir == NULL || p_fr == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( ceiling <= 0 )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_nceiling, &st ); return st; }

 if( f1 < 0 || f2 < 0 )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_nfraction, &st ); return st; }

 if( f1 >= ceiling || f2 >= ceiling )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_aceiling, &st ); return st; }

 // Add first the fractions
 if( osapi_number_add( f1, f2, p_fr ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 // Add next the integers
 if( osapi_number_add( i1, i2, p_ir ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 // Check for negative fraction
 if( *p_fr < 0 )
   {
     *p_fr = ceiling + (*p_fr);
     (*p_ir)--;
   }
 else
   {
     if( *p_fr >= ceiling )	// Check for ceiling crossing
       {
	 *p_fr = ceiling - (*p_fr);
	 (*p_ir)++;
       }
   }

 return st;
}


t_status common_realNumber_subtract( int64_t i1, int64_t f1, int64_t i2, int64_t f2, int64_t ceiling, int64_t * p_ir, int64_t * p_fr )
{
 t_status	st;

 status_reset( & st );

 // Validate first all inputs
 if( p_ir == NULL || p_fr == NULL )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_params, &st ); return st; }

 if( ceiling <= 0 )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_nceiling, &st ); return st; }

 if( f1 < 0 || f2 < 0 )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_nfraction, &st ); return st; }

 if( f1 >= ceiling || f2 >= ceiling )
   { status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_aceiling, &st ); return st; }

 // Add first the fractions
 if( osapi_number_sub( f1, f2, p_fr ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 // Add next the integers
 if( osapi_number_sub( i1, i2, p_ir ) )
     status_iset( OSAPI_MODULE_COMMON, __func__,osapi_common_error_overflow, &st );

 // Check for negative fraction
 if( *p_fr < 0 )
   {
     *p_fr = ceiling + (*p_fr);
     (*p_ir)--;
   }
 else
   {
     if( *p_fr >= ceiling )	// Check for ceiling crossing
       {
	 *p_fr = ceiling - (*p_fr);
	 (*p_ir)++;
       }
   }

 return st;
}

