// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide string mappings for signals on the Proc(ess) module
//
// *****************************************************************************************

#ifndef OSAPI_PROC_SIGNAL_DEFS_H_
#define OSAPI_PROC_SIGNAL_DEFS_H_


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

#define		OSAPI_SIGNAL_END		-999999

// Internal variables
const t_option osapi_signal[] = {
    { "SIGHUP", 	SIGHUP 			},
    { "SIGINT", 	SIGINT 			},
    { "SIGQUIT",	SIGQUIT 		},
    { "SIGILL", 	SIGILL 			},
    { "SIGTRAP", 	SIGTRAP 		},
    { "SIGABRT", 	SIGABRT 		},
    { "SIGBUS", 	SIGBUS 			},
    { "SIGKILL", 	SIGKILL 		},
    { "SIGUSR1", 	SIGUSR1 		},
    { "SIGUSR2", 	SIGUSR2 		},
    { "SIGSEGV", 	SIGSEGV 		},
    { "SIGPIPE", 	SIGPIPE			},
    { "SIGALRM", 	SIGALRM 		},
    { "SIGTERM", 	SIGTERM 		},
    { "SIGSTKFLT", 	SIGSTKFLT 		},
    { "SIGCHLD", 	SIGCHLD 		},
    { "SIGCONT", 	SIGCONT 		},
    { "SIGSTOP", 	SIGSTOP 		},
    { "SIGTSTP", 	SIGTSTP 		},
    { "SIGTTIN", 	SIGTTIN 		},
    { "SIGTTOU", 	SIGTTOU 		},
    { "SIGURG", 	SIGURG 			},
    { "SIGXCPU", 	SIGXCPU 		},
    { "SIGXFSZ", 	SIGXFSZ 		},
    { "SIGVTALRM", 	SIGVTALRM 		},
    { "SIGPROF", 	SIGPROF 		},
    { "SIGWINCH", 	SIGWINCH 		},
    { "SIGIO", 		SIGIO 			},
    { "SIGPWR", 	SIGPWR 			},
    { "SIGSYS", 	SIGSYS 			},
    { "", 		OSAPI_OPTIONS_END	},
};


#endif	// OSAPI_POSIX

#endif	// OSAPI_PROC_SIGNAL_DEFS_H_
