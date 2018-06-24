// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings  for errors on the String module
//
// *****************************************************************************************

error_string_X( e_string_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
error_string_X( e_string_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
error_string_X( e_string_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
error_string_X( e_string_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)

error_string_X( e_string_create, , 				"Unable to create string"	)
error_string_X( e_string_nullPointer, , 			"Empty pointer location"	)
error_string_X( e_string_exists, , 				"String exists already"		)
error_string_X( e_string_noSpace, , 				"Not enough space"		)
error_string_X( e_string_sameString, , 				"The string is the same"	)

