// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Filesystem module
//
// *****************************************************************************************

osapi_error_fs_X( osapi_fs_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE						)

osapi_error_fs_X( osapi_fs_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC					)
osapi_error_fs_X( osapi_fs_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT					)
osapi_error_fs_X( osapi_fs_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM					)
osapi_error_fs_X( osapi_fs_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN					)
osapi_error_fs_X( osapi_fs_error_diffid,		,		"Filesystems are different"					)
osapi_error_fs_X( osapi_fs_error_elopen, 		,		"Element is not open"						)
osapi_error_fs_X( osapi_fs_error_elclose, 		,		"Element is not closed"						)
osapi_error_fs_X( osapi_fs_error_eldiff, 		,		"Elements are different"					)
osapi_error_fs_X( osapi_fs_error_elequal, 		,		"Elements are the same"						)
osapi_error_fs_X( osapi_fs_error_elcopy, 		,		"Element is not copiable"					)
osapi_error_fs_X( osapi_fs_error_elexists, 		,		"Element already exists"					)
osapi_error_fs_X( osapi_fs_error_invopenmode, 		,		"Invalid open mode"						)
osapi_error_fs_X( osapi_fs_error_fopen, 		,		"File is not opened"						)
osapi_error_fs_X( osapi_fs_error_notCreateMode, 	,		"File does not exist and creation was not requested"		)
osapi_error_fs_X( osapi_fs_error_fio, 			,		"File IO error"							)
osapi_error_fs_X( osapi_fs_error_fexists, 		,		"File exists"							)
osapi_error_fs_X( osapi_fs_error_lexists, 		,		"Link exists"							)
osapi_error_fs_X( osapi_fs_error_notFile, 		,		"Path name is not a file"					)
osapi_error_fs_X( osapi_fs_error_notDirectory, 		,		"Path name is not a directory"					)
osapi_error_fs_X( osapi_fs_error_notLink, 		,		"Path name is not a link"					)
osapi_error_fs_X( osapi_fs_error_dopen, 		,		"Directory is not open"						)
osapi_error_fs_X( osapi_fs_error_dclose, 		,		"Directory is not closed"					)
osapi_error_fs_X( osapi_fs_error_isOpen, 		,		"Element is already opened"					)
osapi_error_fs_X( osapi_fs_error_cap, 			,		"Insufficient space in list"					)
osapi_error_fs_X( osapi_fs_error_noList, 		,		"List is not allocated"						)
osapi_error_fs_X( osapi_fs_error_diffType, 		,		"Element changed type"						)
osapi_error_fs_X( osapi_fs_error_aopen, 		,		"Already Open"							)
osapi_error_fs_X( osapi_fs_error_invDest, 		,		"Destination is invalid"					)
osapi_error_fs_X( osapi_fs_error_strcpy, 		,		"Error when copying string"					)
osapi_error_fs_X( osapi_fs_error_locate, 		,		"Error when locating element"					)
osapi_error_fs_X( osapi_fs_error_pathsize, 		,		"The path name size is too big"					)

osapi_error_fs_X( osapi_fs_error_max, 			,		OSAPI_ERROR_STRING_UNKNOWN					)
