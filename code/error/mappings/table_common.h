// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Common module
//
// *****************************************************************************************

osapi_common_error_X( osapi_common_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE					)

osapi_common_error_X( osapi_common_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC				)
osapi_common_error_X( osapi_common_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT				)
osapi_common_error_X( osapi_common_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM				)
osapi_common_error_X( osapi_common_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN				)
osapi_common_error_X( osapi_common_error_canary, ,				"Memory unallocated/corrupted"				)
osapi_common_error_X( osapi_common_error_alloc, ,				"Memory already allocated (potential memory leak)"	)
osapi_common_error_X( osapi_common_error_dealloc, ,				"Memory not allocated"					)
osapi_common_error_X( osapi_common_error_memoverlap, ,				"Memory overlap"					)
osapi_common_error_X( osapi_common_error_notEnoughMemory, ,			"Insufficient memory"					)
osapi_common_error_X( osapi_common_error_notEnoughCapacity, ,			"Insufficient capacity"					)

osapi_common_error_X( osapi_common_error_max, ,					OSAPI_ERROR_STRING_UNKNOWN				)
