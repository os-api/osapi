// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declarations
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_TYPES_H_
#define OSAPI_FS_POSIX_TYPES_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import POSIX type headers
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Enumeration of time information types (of a file system element)
enum osapi_e_fs_elementTime
{
  osapi_fs_e_time_unknown	= 0,	///< Undefined time type
  osapi_fs_e_time_create	= 1,	///< Creation time type
  osapi_fs_e_time_modify	= 2,	///< Modification time type
  osapi_fs_e_time_access	= 3	///< Access time type
};

// Include own types
typedef mode_t	t_fs_ePerm;

/// Structure containing the C/POSIX file pointer/handler information
struct osapi_s_fs_fileInfo
{
  FILE		*		handle;		///< POSIX file handle
};

typedef struct osapi_s_fs_fileInfo		t_fs_fileInfo;

/// Structure describing a directory descriptor type
struct osapi_s_fs_directoryInfo
{
  DIR		*		handle;		///< POSIX directory descriptor
};

typedef struct osapi_s_fs_directoryInfo		t_fs_directoryInfo;



#endif /* OSAPI_FS_POSIX_TYPES_H_ */
