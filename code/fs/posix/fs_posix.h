// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module POSIX private header
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_H_
#define OSAPI_FS_POSIX_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// First include baseline
#include "general/general_baseline.h"

// Standard C headers
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// General OSAPI headers
#include "general/general.h"
#include "status/status_types.h"

// Include own headers
#include "fs/fs_types.h"



// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

t_status	posix_element_open		( const t_char * p_path, t_element * p_element				);
t_status	posix_get_element_info		( t_element * p_element							);
t_status	posix_decode_element_info	( const struct stat *  p_stat, t_fs_elementInfo * p_info		);
t_fs_eType	posix_get_element_type		( mode_t mode								);
int64_t		posix_get_fs_open_options	( const char ** p_options						);
int64_t		posix_get_fs_mode_options	( const char ** p_options						);
t_status	posix_get_element_time		( const t_fs_elementInfo * info, int selector, t_time * time		);
t_status	posix_open_file			( const t_char * pathname, int64_t open, int64_t mode, t_file * file	);
t_status	posix_open_filestream		( const t_char * pathname, const char * options, t_file * file		);
t_status 	posix_get_file_info		( t_file * p_file							);
t_status	posix_get_directory_info	( t_dir * p_dir								);
t_status	posix_get_link_info		( t_link * p_info							);

#endif // Only in POSIX mode

#endif // OSAPI_FS_POSIX_H_
