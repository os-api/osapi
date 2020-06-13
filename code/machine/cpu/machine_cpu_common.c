// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines a generic machine CPU implementation (like an interface)
//		and calls the specific cpu architecture implementation
//
// *****************************************************************************************

#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"


// System headers <here>
#include <stdint.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_machine.h"
#include "status/status.h"
#include "status/trace_macros.h"
#include "common/common_machine.h"

// Own declarations
#include "machine/machine_cpu.h"
#include "machine/cpu/machine_cpu_types.h"
#include "machine/cpu/machine_cpu_common.h"



// *****************************************************************************************
//
// Section: Function declarations
//
// *****************************************************************************************

extern t_status internal_cpu_intel_getFeatures( uint32_t featLevel, t_cpu_feature_list * p_list );
extern t_status internal_cpu_amd_getFeatures  ( uint32_t featLevel, t_cpu_feature_list * p_list );

// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


t_status machine_cpu_id( uint32_t op, uint32_t param, t_cpu_regs * p_regs )
{
 t_status	st;

 status_reset( &st );

 if( p_regs == NULL )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 if( common_asm_cpuid( op, param, p_regs ) )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuid, &st ); return st; }

 return st;
}


t_status machine_cpuVendor_getName( t_size nsize, char ** p_name )
{
 t_status	st;
 t_cpu_regs	regs;

 status_reset( &st );

 if( p_name == NULL || nsize < 13 )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 TRACE_ENTER

 if( common_asm_cpuid( 0, 0, &regs ) || regs.eax == 0 )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuid, &st ); return st; }

 memcpy( *p_name,     &regs.ebx, 4);
 memcpy( *p_name + 4, &regs.edx, 4);
 memcpy( *p_name + 8, &regs.ecx, 4);

 *p_name[12] = '\0';

 return st;
}


t_status machine_cpuFeature_supports( void )
{
 t_status	st;
 t_cpu_regs	regs;

 status_reset( &st );

 if( common_asm_cpuid( 0, 0, &regs ) || regs.eax == 0 )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuid, &st ); return st; }

 return st;
}


t_status machine_cpuFeature_getAll( t_cpu_feature_list * p_list )
{
 t_status	st;
 t_cpu_regs	regs;
 uint32_t	featLevel;
 char		vendor[13];

 status_reset( &st );

 if( p_list == NULL )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 TRACE_ENTER

 // Init the structure
 memset( p_list, '\0', sizeof( t_cpu_feature_list ) );
 p_list->max = osapi_machine_cpu_feature_max;

 // Get the max supported CPUID functions
 if( common_asm_cpuid( 0, 0, &regs ) || regs.eax == 0 )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuid, &st ); return st; }

 featLevel = regs.eax;

 TRACE( "Max. standard CPUID level: 0x%x", featLevel )

 memcpy( vendor,     &regs.ebx, 4 );
 memcpy( vendor + 4, &regs.edx, 4 );
 memcpy( vendor + 8, &regs.ecx, 4 );

 vendor[12] = '\0';

 int vendor_id;
 st = machine_cpuVendor_getIDFromName( vendor, &vendor_id );
 if( status_failure( st) ) return st;

 // Forward request to specific CPU vendor API
 switch( vendor_id )
       {
         case osapi_machine_cpu_signature_intel:	st = internal_cpu_intel_getFeatures( featLevel, p_list );	break;
         /*
         case osapi_machine_cpu_signature_amd_k5:
         case osapi_machine_cpu_signature_amd:		st = internal_cpu_amd_getFeatures  ( featLevel, p_list );	break;
	 */
         default:					status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_noVendor, &st );
       }


 // Count the available features
 for( unsigned int i=1; i < osapi_machine_cpu_feature_max; i++ )
      if( p_list->feature[ i ] )  p_list->avail++;

 TRACE_EXIT

 return st;
}






// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************




#endif	// AMD / Intel Architectures
