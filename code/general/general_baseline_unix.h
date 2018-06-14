// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General UNIX baseline specification
//
// *****************************************************************************************



#ifndef GENERAL_BASELINE_UNIX_H_
#define GENERAL_BASELINE_UNIX_H_

#include <unistd.h>

#if (_XOPEN_VERSION < 700)
    #error "Wrong XOPEN Version"
#endif

#define OSAPI_POSIX


#endif /* GENERAL_BASELINE_UNIX_H_ */
