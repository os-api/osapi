// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Filesystem module
//
// *****************************************************************************************

error_fs_X( osapi_fs_e_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE		)
error_fs_X( osapi_fs_e_generic, = OSAPI_ERROR_GENERIC,		OSAPI_ERROR_STRING_GENERIC	)
error_fs_X( osapi_fs_e_support, = OSAPI_ERROR_SUPPORT,		OSAPI_ERROR_STRING_SUPPORT	)
error_fs_X( osapi_fs_e_params,  = OSAPI_ERROR_INVPARAM,		OSAPI_ERROR_STRING_INVPARAM	)
error_fs_X( osapi_fs_e_unknown, = OSAPI_ERROR_UNKNOWN,		OSAPI_ERROR_STRING_UNKNOWN	)
error_fs_X( osapi_fs_e_invopenmode, 			,	"Invalid open mode"		)
error_fs_X( osapi_fs_e_fopen, 			,		"File is not opened"		)
error_fs_X( osapi_fs_e_fio, 			,		"File IO error"			)

error_fs_X( osapi_fs_e_max, ,					OSAPI_ERROR_STRING_UNKNOWN	)
