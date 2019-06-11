// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Com(munication) module
//
// *****************************************************************************************

error_com_X( e_com_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE					)

error_com_X( e_com_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC				)
error_com_X( e_com_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT				)
error_com_X( e_com_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM				)
error_com_X( e_com_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN				)
error_com_X( e_com_target, ,				"Not a broadcast or point to point address"		)
error_com_X( e_com_invmask, , 				"No network mask in protocol"				)
error_com_X( e_com_diffsem, , 				"The number of semaphores is different"			)

error_com_X( e_com_max, ,				OSAPI_ERROR_STRING_UNKNOWN				)

