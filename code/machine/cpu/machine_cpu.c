// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine CPU submodule main implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers <here>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_machine.h"
#include "status/status.h"
#include "status/trace_macros.h"
#include "common/common_list.h"
#include "common/common_machine.h"
#include "common/common_helper.h"

// Own declarations
#include "machine/machine_cpu.h"
#include "machine/cpu/machine_cpu_internal.h"
#include "machine/cpu/machine_cpu_strings.h"




// *****************************************************************************************
//
// Section: Private Function definition
//
// *****************************************************************************************


// No need to check pointers
static t_status internal_machine_getList( bool name, const t_cpu_feature_list * p_features, t_list * p_list )
{
  t_status 	st;

  status_reset( &st );

  TRACE_ENTER

  if( p_features == NULL || p_list == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( is_list_not_allocated( p_list ) )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_canary, &st ); return st; }

  if( sizeof( const char * ) != get_list_itemSize( p_list ) )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_notEnoughMemory, &st ); return st; }

  // Does the allocated list has capacity for storing the CPU feature list?
  if( get_list_capacity( p_list ) < p_features->avail )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_noCapacity, &st ); return st; }

  TRACE( "Cycle through feature list (%d,%d)", p_features->avail, p_list->capacity )

  set_list_size( p_list, 0 );

  t_cpu_feature_size f = 1;
  t_size l = 1;
  for( ; f < osapi_machine_cpu_feature_max && l <= get_list_capacity( p_list ) && l <= p_features->avail; f++ )
     {
       if( p_features->feature[ f ] )
	 {
	   const char * p_string;

	   if( name )	p_string = osapi_machine_cpu_feature_string     [ f ];
	   else		p_string = osapi_machine_cpu_feature_long_string[ f ];

	   errno = 0;
	   memcpy( (void *) get_list_item( p_list, l ), &p_string, sizeof( const char * ) );

	   if( errno )
	     { status_eset( OSAPI_MODULE_MACHINE, __func__, errno, &st ); return st; }

	   inc_list_size( p_list );
	   l++;
	 }
     }

  TRACE( "List Size:%d", p_list->nitems )

  TRACE_EXIT

  return st;
}


// *****************************************************************************************
//
// Section: Public Function definition
//
// *****************************************************************************************


t_status machine_cpuVendor_getIDFromName( const char * p_name, int * p_id )
{
  t_status	st;
  int		vid = 0;

  status_reset( &st );

  if( p_name == NULL || p_id == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  TRACE( "Entering with vendor name: %s", p_name )

  int i;
  for( i = 1; i < osapi_machine_cpu_signature_max; i++ )
     {
       if( strcmp( p_name, osapi_machine_cpu_signature_string[ i ] ) == 0 ) break;
     }

  if( i == osapi_machine_cpu_signature_max )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_noVendor, &st ); return st; }

  switch( i )
        {
	  case osapi_machine_cpu_signature_intel:	vid = osapi_machine_cpu_vendor_intel; 		break;
	  case osapi_machine_cpu_signature_amd:
	  case osapi_machine_cpu_signature_amd_k5:	vid = osapi_machine_cpu_vendor_amd; 		break;
	  case osapi_machine_cpu_signature_transmeta:
	  case osapi_machine_cpu_signature_transmeta_2:	vid = osapi_machine_cpu_vendor_transmeta; 	break;

	  default:					vid = osapi_machine_cpu_vendor_none; 		break;
        }

  TRACE( "Leaving with Vendor ID: %d", vid )

  *p_id = vid;

  return st;
}


t_status machine_cpuVendor_getNameFromID( uint16_t vendor_id, const char ** p_name )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_name == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( vendor_id >= osapi_machine_cpu_signature_max )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_noVendor, &st ); return st; }

  *p_name = osapi_machine_cpu_vendor_string[ vendor_id ];

  TRACE_EXIT

  return st;
}



t_status machine_cpu_getArch( const char ** p_arch )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_arch == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  *p_arch = osapi_machine_cpuarch_string[ OSAPI_CPU_ARCHITECTURE_TARGET ];

  TRACE_EXIT

  return st;
}




t_status machine_cpuFeature_getName( unsigned int fid, const char ** p_name )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_name == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( fid >= osapi_machine_cpu_feature_max )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_invFID, &st ); return st; }

  *p_name = osapi_machine_cpu_feature_string[ fid ];

  TRACE_EXIT

  return st;
}



t_status machine_cpuFeature_getDescription( unsigned int fid, const char ** p_desc )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_desc == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( fid >= osapi_machine_cpu_feature_max )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_invFID, &st ); return st; }

  *p_desc = osapi_machine_cpu_feature_long_string[ fid ];

  TRACE_EXIT

  return st;
}



// Is feature available in the CPU information type?
t_status machine_cpu_isFeatureAvailable( const t_cpu * p_cpu, unsigned int fid, bool * p_available )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_cpu == NULL || p_available == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( fid >= osapi_machine_cpu_feature_max )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_invFID, &st ); return st; }

  if( p_cpu->canary != OSAPI_SANITY_END )
      status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_noData, &st );
  else
      *p_available = p_cpu->features.feature[ fid ];

  TRACE_EXIT

  return st;
}



t_status machine_cpu_getEndian( t_cpu_endian * p_endian )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_endian == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( OSAPI_CPU_ARCHITECTURE_TARGET > osapi_machine_cpuarch_max )
      status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuarch, &st );
  else
      *p_endian = (t_cpu_endian) osapi_machine_cpuarch_endianess_A[ OSAPI_CPU_ARCHITECTURE_TARGET ];

  TRACE_EXIT

  return st;
}


t_status machine_cpu_getEndianString( const char ** p_endian )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_endian == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  if( OSAPI_CPU_ARCHITECTURE_TARGET > osapi_machine_cpuarch_max )
      status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_cpuarch, &st );
  else
      *p_endian = osapi_machine_endianess_string[ osapi_machine_cpuarch_endianess_A[ OSAPI_CPU_ARCHITECTURE_TARGET ] ];

  TRACE_EXIT

  return st;
}


t_status machine_cpu_getSummary( t_cpu_summary * p_summary )
{
  t_status st;

  status_reset( &st );

  TRACE_ENTER

  if( p_summary == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  st = common_cpu_getPresent( &(p_summary->ncpus_present) );
  if( status_failure( st ) ) return st;

  st = common_cpu_getAvailable( &(p_summary->ncpus_available) );
  if( status_failure( st ) ) return st;

  //...

  st = machine_cpu_getEndian( &(p_summary->endianess) );
  if( status_failure( st ) ) return st;

  TRACE_EXIT

  return st;
}


t_status machine_cpuFeature_isAvailable( const t_cpu_feature_list * p_list, unsigned int id, bool * p_available )
{
 t_status	st;

 status_reset( &st );

 TRACE_ENTER

 if( p_list == NULL || p_available == NULL )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 *p_available = p_list->feature[ id ];

 TRACE_EXIT

 return st;
}


t_status machine_cpuFeature_count( const t_cpu_feature_list * p_list, t_size * p_nFeatures )
{
  t_status 	st;

  status_reset( &st );

  TRACE_ENTER

  if( p_list == NULL || p_nFeatures == NULL )
    { status_iset( OSAPI_MODULE_MACHINE, __func__,osapi_machine_error_params, &st ); return st; }

  *p_nFeatures = p_list->avail;

  TRACE_EXIT

  return st;
}



t_status machine_cpuFeature_getListName( const t_cpu_feature_list * p_features, t_list * p_list )
{
  return internal_machine_getList( true, p_features, p_list );
}


t_status machine_cpuFeature_getListDescription( const t_cpu_feature_list * p_features, t_list * p_list )
{
  return internal_machine_getList( false, p_features, p_list );
}


