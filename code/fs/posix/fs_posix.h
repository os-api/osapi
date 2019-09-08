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
t_status	posix_element_getInfo		( t_element * p_element							);
t_status	posix_decode_element_info	( const struct stat *  p_stat, t_fs_elementInfo * p_info		);
t_status	posix_element_getTime		( const t_fs_elementInfo * info, int selector, t_time * time		);
t_status	posix_element_setPermissions	( const char * p_path, t_fs_perm * p_perm				);
t_status	posix_element_getPermissions	( t_element * p_element, t_fs_perm * p_perm				);
t_fs_eType	posix_element_getType		( mode_t mode								);

t_status	posix_file_open			( const t_char * path, int64_t open, int64_t mode, t_file * file	);
t_status	posix_file_read			( const t_file * p_file, t_buffer * p_buffer, bool * p_eof		);
t_status	posix_file_write		( const t_file * p_file, const t_buffer * p_buffer			);
t_status	posix_file_copy			( const t_char * p_source, const t_char * p_target, bool overwrite	);
t_status	posix_file_close		( t_file * p_file							);
t_status	posix_file_copy2file		( t_file * p_source, const t_char * p_target, bool overwrite		);
t_status	posix_file_copy2dir		( t_file * p_source, const t_char * p_target, bool overwrite		);
t_status	posix_file_openStream		( const t_char * pathname, const char * options, t_file * file		);
t_status 	posix_file_getInfo		( t_file * p_file							);

t_status	posix_directory_open		( const t_char * p_path, t_dir * p_dir					);
t_status	posix_directory_copy		( const t_char * p_source, const t_char * p_target, bool overwrite	);
t_status	posix_directory_getInfo		( t_dir * p_dir								);
t_fs_eType	posix_get_type_dir_entry	( t_dir_entry * entry							);

t_status	posix_link_open			( const t_char * p_path, t_link * p_link				);
t_status	posix_link_copy			( const t_char * p_source, const t_char * p_target, bool overwrite	);
t_status	posix_link_createSoft		( const t_char * p_source, const t_char * p_target			);
t_status	posix_get_link_info		( t_link * p_info							);

// POSIX specific functions
int64_t		posix_fs_getOpenOptions		( const char ** p_options						);
int64_t		posix_fs_getModeOptions		( const char ** p_options						);



// *****************************************************************************************
//
// Section: Macros
//
// *****************************************************************************************

#define		posix_getElementPermMode(x)	( x->element.perm.mode )

#endif // Only in POSIX mode

#endif // OSAPI_FS_POSIX_H_
