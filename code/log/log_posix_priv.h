// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log Module POSIX private header
//
// *****************************************************************************************

#ifndef LOG_POSIX_PRIV_H_
#define LOG_POSIX_PRIV_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

#define		OSAPI_LOG_END  		-999999

// Internal variables

const t_option log_facility[] = {
      { "LOG_LOCAL0", 	LOG_LOCAL0 		},
      { "LOG_LOCAL1", 	LOG_LOCAL1 		},
      { "LOG_LOCAL2", 	LOG_LOCAL2 		},
      { "LOG_LOCAL3", 	LOG_LOCAL3 		},
      { "LOG_LOCAL4", 	LOG_LOCAL4 		},
      { "LOG_LOCAL5", 	LOG_LOCAL5 		},
      { "LOG_LOCAL6", 	LOG_LOCAL6 		},
      { "LOG_LOCAL7", 	LOG_LOCAL7 		},
      { "LOG_AUTH", 	LOG_AUTH		},
      { "LOG_AUTHPRIV",	LOG_AUTHPRIV		},
      { "LOG_CRON", 	LOG_CRON		},
      { "LOG_DAEMON", 	LOG_DAEMON		},
      { "LOG_FTP",	LOG_FTP			},
      { "LOG_KERN",	LOG_KERN		},
      { "LOG_LPR", 	LOG_LPR			},
      { "LOG_MAIL",	LOG_MAIL		},
      { "LOG_NEWS",	LOG_NEWS		},
      { "LOG_SYSLOG",	LOG_SYSLOG		},
      { "LOG_USER",	LOG_USER		},
      { "LOG_UUCP",	LOG_UUCP		},
      { "",		OSAPI_OPTIONS_END	},
};


const t_option log_options[] = {
      { "LOG_CONS", 	LOG_CONS 		},
      { "LOG_NDELAY", 	LOG_NDELAY 		},
      { "LOG_NOWAIT", 	LOG_NOWAIT 		},
      { "LOG_ODELAY",	LOG_ODELAY 		},
      { "LOG_PERROR", 	LOG_PERROR 		},
      { "LOG_PID", 	LOG_PID 		},
      { "",		OSAPI_OPTIONS_END	},
};


#endif	// End of POSIX declarations

#endif /* LOG_POSIX_PRIV_H_ */
