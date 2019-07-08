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
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// *****************************************************************************************
//
// Section: Define POSIX specific types
//
// *****************************************************************************************

/// Enumeration of time information types (of a file system element)
enum osapi_fs_e_time_element
{
  osapi_fs_time_unknown	= 0,	///< Undefined time type
  osapi_fs_time_create	= 1,	///< Creation time type
  osapi_fs_time_modify	= 2,	///< Modification time type
  osapi_fs_time_access	= 3	///< Access time type
};

// Include own types
typedef mode_t	t_fs_ePerm;

/// Structure containing the C/POSIX file pointer/handler information
struct osapi_fs_s_file_info
{
  FILE		*		handle;		///< POSIX file handle
};

typedef struct osapi_fs_s_file_info		t_fs_fileInfo;

/// Structure describing a directory descriptor type
struct osapi_fs_s_directory_info
{
  DIR		*		handle;		///< POSIX directory descriptor
};

typedef struct osapi_fs_s_directory_info	t_fs_directoryInfo;

typedef struct dirent				t_dir_entry;


/// Structure that defines a file system permissions
struct osapi_fs_s_element_permissions
{
  mode_t	mode;				///< POSIX encoding of an element permissions/type
  // ACL also required
};

typedef struct osapi_fs_s_element_permissions	t_fs_perm;


/// Structure containing the C/POSIX file pointer/handler information
struct osapi_fs_s_link_info
{
  FILE		*	handle;				///< POSIX file handle
  t_char		p_target[ PATH_MAX ];		///< Full path name of element to which the link points to
};

typedef struct osapi_fs_s_link_info		t_fs_linkInfo;


#endif /* OSAPI_FS_POSIX_TYPES_H_ */
