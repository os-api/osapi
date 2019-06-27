// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module POSIX private header
//
// *****************************************************************************************

#ifndef OSAPI_FS_POSIX_PRIV_H_
#define OSAPI_FS_POSIX_PRIV_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// First include baseline
#include "general/general_baseline.h"

// Standard C headers
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

t_status	get_element_info	( const t_char * pathname, struct stat * p_stat			);
t_status	decode_element_info	( const struct stat *  p_stat, t_fs_elementInfo * p_info	);
t_fs_eType	get_element_type	( mode_t mode							);
void		set_file_open_mode	( bool create, int openMode, int location, char * mode		);
t_status	get_element_time	( const t_fs_elementInfo * info, int selector, t_time * time	);
t_status	open_file		( const t_char * pathname, const char * mode, t_file * file	);

#endif // Only in POSIX mode

#endif // OSAPI_FS_POSIX_PRIV_H_
