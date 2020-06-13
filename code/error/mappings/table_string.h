// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings  for errors on the String module
//
// *****************************************************************************************

osapi_error_string_X( osapi_string_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE		)

osapi_error_string_X( osapi_string_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
osapi_error_string_X( osapi_string_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
osapi_error_string_X( osapi_string_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
osapi_error_string_X( osapi_string_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)

osapi_error_string_X( osapi_string_error_create, , 				"Unable to create string"	)
osapi_error_string_X( osapi_string_error_nullPointer, , 			"Empty pointer location"	)
osapi_error_string_X( osapi_string_error_exists, , 				"String exists already"		)
osapi_error_string_X( osapi_string_error_noSpace, , 				"Not enough space"		)
osapi_error_string_X( osapi_string_error_sameString, , 				"The string is the same"	)

osapi_error_string_X( osapi_string_error_max, ,					OSAPI_ERROR_STRING_UNKNOWN	)
