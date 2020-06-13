// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Security module
//
// *****************************************************************************************

osapi_error_sec_X( osapi_sec_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE		)

osapi_error_sec_X( osapi_sec_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
osapi_error_sec_X( osapi_sec_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
osapi_error_sec_X( osapi_sec_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
osapi_error_sec_X( osapi_sec_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)
osapi_error_sec_X( osapi_sec_error_memory, ,				"Unable to allocate memory"	)
osapi_error_sec_X( osapi_sec_error_userid, ,				"User ID not found"		)
osapi_error_sec_X( osapi_sec_error_groupid, ,				"Group ID not found"		)

osapi_error_sec_X( osapi_sec_error_max, ,				OSAPI_ERROR_STRING_UNKNOWN	)
