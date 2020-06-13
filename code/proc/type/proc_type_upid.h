// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type Unique PID (upid) declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPE_UPID_H_
#define OSAPI_PROC_TYPE_UPID_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"



/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Define process related types
//
// *****************************************************************************************


/// The process information structure for the Unique CPU type
/// This type represents a local node unique PID in time to support IPC use cases where endpoints need to maintain awareness
/// of the other end lifecycle, for instance, it the other end of the communication channel was restarted
union osapi_proc_upid_U
{
  struct
  {
    int64_t		pid;		///< Process Identifier
    int64_t		time;		///< Startup time of the process, usually in seconds
  };
  Byte			id[ 16 ];	///< A raw ID value (which is more relevant than the internal composition of the ID itself)
};


/// Define the Unique PID
typedef union osapi_proc_upid_U		t_upid;

///@}
///@}


#endif /* OSAPI_PROC_TYPE_UPID_H_ */
