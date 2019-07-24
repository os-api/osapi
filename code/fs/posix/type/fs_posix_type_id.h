// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Type declarations for a FS ID
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_ID_H_
#define OSAPI_FS_TYPE_ID_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


/// Structure that holds a directory system element information
struct osapi_fs_s_id
{
  unsigned int		major;		///< File system device major number
  unsigned int		minor;		///< File system device minor number
};

typedef struct osapi_fs_s_id		t_fs_id;



#endif /* OSAPI_FS_TYPE_ID_H_ */
