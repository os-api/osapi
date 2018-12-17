// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Net(work) module
//
// *****************************************************************************************

error_net_X( e_net_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE					)

error_net_X( e_net_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC				)
error_net_X( e_net_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT				)
error_net_X( e_net_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM				)
error_net_X( e_net_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN				)
error_net_X( e_net_target, ,				"Not a broadcast or point to point address"		)
error_net_X( e_net_invmask, , 				"No network mask in protocol"				)

error_net_X( e_net_max, ,				OSAPI_ERROR_STRING_UNKNOWN				)

