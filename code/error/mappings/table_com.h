// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Com(munication) module
//
// *****************************************************************************************

osapi_error_com_X( osapi_com_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE					)

osapi_error_com_X( osapi_com_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC				)
osapi_error_com_X( osapi_com_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT				)
osapi_error_com_X( osapi_com_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM				)
osapi_error_com_X( osapi_com_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN				)
osapi_error_com_X( osapi_com_error_target, ,				"Not a broadcast or point to point address"		)
osapi_error_com_X( osapi_com_error_invmask, , 				"No network mask in protocol"				)
osapi_error_com_X( osapi_com_error_diffsem, , 				"The number of semaphores is different"			)

osapi_error_com_X( osapi_com_error_max, ,				OSAPI_ERROR_STRING_UNKNOWN				)

