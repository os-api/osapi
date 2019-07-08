// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS open state type declaration (it declares if the FS element is open for operations
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_OSTATE_H_
#define OSAPI_FS_TYPE_OSTATE_H_


// *****************************************************************************************
//
// Section: Type definition
//
// *****************************************************************************************

/// @brief The enum represents the possible elements of a file system
enum osapi_fs_e_open_state
{
  osapi_fs_ostate_opened	= 1234321,	///< MAGIC value to name a file state open
  osapi_fs_ostate_closed	= 9876789	///< MAGIC value to name a file state closed
};

typedef enum osapi_fs_e_open_state	t_fs_ostate;

#endif /* OSAPI_FS_TYPE_OSTATE_H_ */
