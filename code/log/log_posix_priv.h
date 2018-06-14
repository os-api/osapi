/*
 * log_posix_priv.h
 *
 *  Created on: 29/04/2018
 *      Author: joao
 */

#ifndef LOG_POSIX_PRIV_H_
#define LOG_POSIX_PRIV_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#define		OSAPI_LOG_END  		-999999

// Declaration: Private functions
static int	get_facility	( const char * target 		);
static int	get_option	( const char * options[]	);

struct s_log_facility
{
  char *	facName;
  int		facValue;
};

struct s_log_option
{
  char *	optionName;
  int		optionValue;
};

// Internal variables

static const struct s_log_facility log_facility[] = {
    { "LOG_LOCAL0", 	LOG_LOCAL0 	},
    { "LOG_LOCAL1", 	LOG_LOCAL1 	},
    { "LOG_LOCAL2", 	LOG_LOCAL2 	},
    { "LOG_LOCAL3", 	LOG_LOCAL3 	},
    { "LOG_LOCAL4", 	LOG_LOCAL4 	},
    { "LOG_LOCAL5", 	LOG_LOCAL5 	},
    { "LOG_LOCAL6", 	LOG_LOCAL6 	},
    { "LOG_LOCAL7", 	LOG_LOCAL7 	},
    { "LOG_AUTH", 	LOG_AUTH	},
    { "LOG_AUTHPRIV",	LOG_AUTHPRIV	},
    { "LOG_CRON", 	LOG_CRON	},
    { "LOG_DAEMON", 	LOG_DAEMON	},
    { "LOG_FTP",	LOG_FTP		},
    { "LOG_KERN",	LOG_KERN	},
    { "LOG_LPR", 	LOG_LPR		},
    { "LOG_MAIL",	LOG_MAIL	},
    { "LOG_NEWS",	LOG_NEWS	},
    { "LOG_SYSLOG",	LOG_SYSLOG	},
    { "LOG_USER",	LOG_USER	},
    { "LOG_UUCP",	LOG_UUCP	},
    { "",		OSAPI_LOG_END	},
};


static const struct s_log_option log_options[] = {
    { "LOG_CONS", 	LOG_CONS 	},
    { "LOG_NDELAY", 	LOG_NDELAY 	},
    { "LOG_NOWAIT", 	LOG_NOWAIT 	},
    { "LOG_ODELAY",	LOG_ODELAY 	},
    { "LOG_PERROR", 	LOG_PERROR 	},
    { "LOG_PID", 	LOG_PID 	},
    { "",		OSAPI_LOG_END	},
};



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif

#endif	// End of POSIX declarations

#endif /* LOG_POSIX_PRIV_H_ */
