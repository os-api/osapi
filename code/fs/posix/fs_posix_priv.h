// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS Module POSIX private header for posix private implementation
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
#include <fcntl.h>

// General OSAPI headers
#include "general/general.h"
#include "status/status_types.h"

// Include own headers
#include "fs/fs_platform.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Type declarations
//
// *****************************************************************************************


// Ensure that the non POSIX constants options exist
#ifndef		O_ASYNC
#define		O_ASYNC		0
#endif

#ifndef		O_CLOEXEC
#define		O_CLOEXEC	0
#endif

#ifndef		O_DIRECT
#define		O_DIRECT	0
#endif

#ifndef		O_DSYNC
#define		O_DSYNC		0
#endif

#ifndef		O_LARGEFILE
#define		O_LARGEFILE	0
#endif

#ifndef		O_NOATIME
#define		O_NOATIME	0
#endif

#ifndef		O_NOCTTY
#define		O_NOCTTY	0
#endif

#ifndef		O_NOFOLLOW
#define		O_NOFOLLOW	0
#endif

#ifndef		O_NONBLOCK
#define		O_NONBLOCK	0
#endif


#ifndef		O_NDELAY
#define		O_NDELAY	0
#endif

#ifndef		O_PATH
#define		O_PATH		0
#endif

#ifndef		O_SYNC
#define		O_SYNC		0
#endif

#ifndef		O_TMPFILE
#define		O_TMPFILE	0
#endif

// Superset of UNIX options for file system

const t_option osapi_fs_open_options[] = {
      { "O_RDWR", 	O_RDWR	 		},
      { "O_RDONLY", 	O_RDONLY 		},
      { "O_WRONLY", 	O_WRONLY 		},
      { "O_APPEND", 	O_APPEND 		},
      { "O_ASYNC", 	O_ASYNC 		},
      { "O_CLOEXEC", 	O_CLOEXEC 		},
      { "O_CREAT", 	O_CREAT 		},
      { "O_DIRECT", 	O_DIRECT 		},
      { "O_DSYNC", 	O_DSYNC 		},
      { "O_DIRECTORY", 	O_DIRECTORY 		},
      { "O_EXCL", 	O_EXCL	 		},
      { "O_LARGEFILE", 	O_LARGEFILE 		},
      { "O_NOATIME", 	O_NOATIME 		},
      { "O_NOCTTY", 	O_NOCTTY 		},
      { "O_NONBLOCK", 	O_NONBLOCK 		},
      { "O_NDELAY", 	O_NDELAY 		},
      { "O_PATH", 	O_PATH	 		},
      { "O_SYNC", 	O_SYNC	 		},
      { "O_TMPFILE", 	O_TMPFILE 		},
      { "O_TRUNC", 	O_TRUNC 		},
      { "",		OSAPI_OPTIONS_END	},
};


const t_option osapi_fs_mode_options[] = {
      { "S_IRWXU", 	S_IRWXU 		},
      { "S_IRUSR", 	S_IRUSR 		},
      { "S_IWUSR", 	S_IWUSR 		},
      { "S_IXUSR",	S_IXUSR 		},
      { "S_IRWXG", 	S_IRWXG 		},
      { "S_IRGRP", 	S_IRGRP 		},
      { "S_IWGRP", 	S_IWGRP 		},
      { "S_IXGRP", 	S_IXGRP 		},
      { "S_IRWXO", 	S_IRWXO 		},
      { "S_IROTH", 	S_IROTH 		},
      { "S_IWOTH", 	S_IWOTH 		},
      { "S_IXOTH", 	S_IXOTH 		},
      { "S_ISUID", 	S_ISUID 		},
      { "S_ISGID", 	S_ISGID 		},
      { "S_ISVTX", 	S_ISVTX 		},
      { "",		OSAPI_OPTIONS_END	},
};

#endif // Only in POSIX mode

#endif // OSAPI_FS_POSIX_PRIV_H_
