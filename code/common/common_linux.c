// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common module Linux implementation
//
// *****************************************************************************************

#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System includes
#include <limits.h>
#include <errno.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "common/common.h"


t_status get_max_length_groupname( t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_size == NULL )
      status_iset( OSAPI_MODULE_NONE, __func__, 1, &st );
  else
      *p_size = 32;		// Apparently this is the maximum size of a group name.. requires confirmation

  return st;
}



#endif
