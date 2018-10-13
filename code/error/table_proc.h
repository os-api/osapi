// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Process module
//
// *****************************************************************************************

error_proc_X( e_proc_none,    = OSAPI_ERROR_BASE,	OSAPI_ERROR_STRING_NONE		)
error_proc_X( e_proc_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
error_proc_X( e_proc_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
error_proc_X( e_proc_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
error_proc_X( e_proc_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)
error_proc_X( e_proc_libload, ,				"Library load error"		)
error_proc_X( e_proc_libunload, ,			"Library unload error"		)
error_proc_X( e_proc_noerror, ,				"No Library available error"	)

error_proc_X( e_proc_max, ,				OSAPI_ERROR_STRING_UNKNOWN	)
