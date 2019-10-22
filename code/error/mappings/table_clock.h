// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Clock module
//
// *****************************************************************************************

osapi_clock_error_X( osapi_clock_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE		)

osapi_clock_error_X( osapi_clock_error_generic,  = OSAPI_ERROR_GENERIC,		OSAPI_ERROR_STRING_GENERIC	)
osapi_clock_error_X( osapi_clock_error_support,  = OSAPI_ERROR_SUPPORT,		OSAPI_ERROR_STRING_SUPPORT	)
osapi_clock_error_X( osapi_clock_error_params,   = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
osapi_clock_error_X( osapi_clock_error_unknown,  = OSAPI_ERROR_UNKNOWN,		OSAPI_ERROR_STRING_UNKNOWN	)
osapi_clock_error_X( osapi_clock_error_overflow, 			,	"Overflow"			)

osapi_clock_error_X( osapi_clock_error_max, ,					OSAPI_ERROR_STRING_UNKNOWN	)
