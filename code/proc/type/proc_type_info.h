// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type Info declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPE_INFO_H_
#define OSAPI_PROC_TYPE_INFO_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System includes

// Generic OSAPI includes
#include "general/general.h"

// Import OS specific definitions
#include "proc/proc_platform.h"
#include "proc/proc_state.h"
#include "proc/type/proc_type_id.h"
#include "proc/type/proc_type_resource.h"


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


/// The process information structure
struct osapi_proc_info_S
{
  t_proc_id		id;		///< The Process ID
  char			state;		///< State: System dependent
  char		**	args;		///< The process command line arguments
  // t_proc_term	term;
  t_proc_resources	resources;	///< The process resources
  uint64_t		starttime;	///< The process start time
};

/// The process information type
typedef struct osapi_proc_info_S	t_proc_info;


///@}
///@}


#endif /* OSAPI_PROC_TYPE_INFO_H_ */
