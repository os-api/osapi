// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Process module
//
// *****************************************************************************************

osapi_error_proc_X( osapi_proc_error_none,    = OSAPI_ERROR_BASE,	OSAPI_ERROR_STRING_NONE				)
osapi_error_proc_X( osapi_proc_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC			)
osapi_error_proc_X( osapi_proc_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT			)
osapi_error_proc_X( osapi_proc_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM			)
osapi_error_proc_X( osapi_proc_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN			)
osapi_error_proc_X( osapi_proc_error_libload, ,				"Library load error"				)
osapi_error_proc_X( osapi_proc_error_libunload, ,			"Library unload error"				)
osapi_error_proc_X( osapi_proc_error_noerror, ,				"No Library available error"			)
osapi_error_proc_X( osapi_proc_error_setsignal, ,			"Error when registering signal handler"		)
osapi_error_proc_X( osapi_proc_error_unsetsignal, ,			"Error when unregistering signal handler"	)
osapi_error_proc_X( osapi_proc_error_alloc, ,				"Error when allocating memory"			)
osapi_error_proc_X( osapi_proc_error_pid, ,				"Invalid PID"					)
osapi_error_proc_X( osapi_proc_error_exec, ,				"Process execution failed"			)
osapi_error_proc_X( osapi_proc_error_wait, ,				"Process PID mismatch"				)
osapi_error_proc_X( osapi_proc_error_notFound, ,			"Signal not found"				)
osapi_error_proc_X( osapi_proc_error_conversion, ,			"Conversion error"				)
osapi_error_proc_X( osapi_proc_error_idNotFound, ,			"Process ID not found"				)
osapi_error_proc_X( osapi_proc_error_nullptr, ,				"Null pointer found"				)

osapi_error_proc_X( osapi_proc_error_max, ,				OSAPI_ERROR_STRING_UNKNOWN			)
