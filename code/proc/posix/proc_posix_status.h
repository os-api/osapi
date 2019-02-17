// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Model the POSIX process status
//
// *****************************************************************************************

#ifndef OSAPI_PROC_POSIX_STATUS_H_
#define OSAPI_PROC_POSIX_STATUS_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include baseline
#include "general/general_baseline.h"


#ifdef OSAPI_POSIX

enum osapi_proc_status
{
  osapi_e_proc_status_unavailable	= 0,	// Running or dead
  osapi_e_proc_status_available		= 1,	// Normal exit with exit code
  osapi_e_proc_status_signal		= 2,	// Exit due to signal, no exit code
  osapi_e_proc_status_core		= 3,	// Exit and core dump, no exit code
  osapi_e_proc_status_stopped		= 4,	// Process stopped, no exit code
  osapi_e_proc_status_continued		= 5	// Process resumed, no exit code
};


#endif // OSAPI_POSIX

#endif /* OSAPI_PROC_POSIX_STATUS_H_ */
