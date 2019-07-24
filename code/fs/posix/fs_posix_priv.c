// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem module using a POSIX compliant implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_fs.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "fs/fs_sysheaders.h"
#include "fs/posix/fs_posix_priv.h"
#include "fs/fs_helper.h"



// *****************************************************************************************
//
// Section: POSIX private function definition
//
// *****************************************************************************************

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX



int64_t posix_get_fs_open_options( const char ** p_options )
{
  return common_options_get( osapi_fs_open_options,  (char **) p_options );
}


int64_t posix_get_fs_mode_options( const char ** p_options )
{
  return common_options_get( osapi_fs_mode_options,  (char **) p_options );
}









#endif // POSIX only implementation
