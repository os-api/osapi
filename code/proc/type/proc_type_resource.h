// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type Resource declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPE_RESOURCE_H_
#define OSAPI_PROC_TYPE_RESOURCE_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System includes

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


/// The process resources structure
struct osapi_proc_resources_S
{
  t_size	utime;			///< The process consumed user time
  t_size	stime;			///< The process consumed system time
  t_size	num_threads;		///< The number of threads in the process
  t_size	vsize;			///< The size of the virtual memory
  t_size	ram;			///< The size of the process in RAM
};


/// The process resources type
typedef struct osapi_proc_resources_S	t_proc_resources;


///@}
///@}


#endif /* OSAPI_PROC_TYPE_RESOURCE_H_ */
