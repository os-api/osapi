// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declaration for an element ID
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPE_ELEMENT_ID_H_
#define OSAPI_FS_POSIX_TYPE_ELEMENT_ID_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import POSIX type headers
#include <sys/types.h>

// Import module types
#include "fs/type/fs_type_ostate.h"


// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Structure that defines a an element ID
struct osapi_fs_element_id_S
{
  t_fs_id		fsid;			///< POSIX File system ID
  ino_t			eid;			///< POSIX unique identifier for the element inside the file system
};

typedef struct osapi_fs_element_id_S	t_fs_eid;



#endif /* OSAPI_FS_POSIX_TYPE_ELEMENT_ID_H_ */
