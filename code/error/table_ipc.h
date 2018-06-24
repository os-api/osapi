// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the IPC module
//
// *****************************************************************************************

error_ipc_X( e_ipc_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
error_ipc_X( e_ipc_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
error_ipc_X( e_ipc_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
error_ipc_X( e_ipc_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)
error_ipc_X( e_ipc_diffsem, , "The number of semaphores is different"	)
/*
error_ipc_X( e_ipc_unknown, , OSAPI_ERROR_UNKNOWN		)
error_ipc_X( e_ipc_unknown, , OSAPI_ERROR_UNKNOWN		)
*/
