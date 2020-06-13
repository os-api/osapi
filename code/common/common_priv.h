// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common module internal API
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_PRIV_H_
#define OSAPI_COMMON_PRIV_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************


// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Import own module declarations
#include "common/common_types.h"


// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

/// @brief Get the maximum value of a given precision in terms of fraction of a second
/// @param [in] precision - The target precision enum value
/// @return Value of a precision
int64_t		common_timeFraction_getMaxPrecisionValue	( t_time_precision precision );




#endif // OSAPI_COMMON_PRIV_H_
