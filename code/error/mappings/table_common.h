// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Common module
//
// *****************************************************************************************

error_common_X( osapi_common_e_none,    = OSAPI_ERROR_BASE,	OSAPI_ERROR_STRING_NONE					)

error_common_X( osapi_common_e_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC				)
error_common_X( osapi_common_e_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT				)
error_common_X( osapi_common_e_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM				)
error_common_X( osapi_common_e_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN				)
error_common_X( osapi_common_e_canary, ,			"Memory unallocated/corrupted"				)
error_common_X( osapi_common_e_alloc, ,				"Memory already allocated (potential memory leak)"	)
error_common_X( osapi_common_e_dealloc, ,			"Memory not allocated"					)
error_common_X( osapi_common_e_memoverlap, ,			"Memory overlap"					)

error_common_X( osapi_common_e_max, ,				OSAPI_ERROR_STRING_UNKNOWN				)
