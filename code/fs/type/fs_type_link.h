// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for a link Element
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_LINK_H_
#define OSAPI_FS_TYPE_LINK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C headers

// General OSAPI headers
#include "common/common_types.h"

// Import own headers
#include "fs/fs_platform.h"
#include "fs/type/fs_type_elementInfo.h"


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


/// Structure that holds all file system element information
struct osapi_fs_s_link
{
  t_fs_ostate			state;	///< Current directory state
  t_fs_elementInfo		info;	///< General element information
  t_fs_linkInfo			data;	///< Link element specific information
};

typedef struct osapi_fs_s_link			t_link;




#endif /* OSAPI_FS_TYPE_LINK_H_ */
