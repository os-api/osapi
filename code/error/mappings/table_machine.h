// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for errors on the Machine module
//
// *****************************************************************************************

osapi_error_machine_X( osapi_machine_error_none,    = OSAPI_ERROR_BASE,		OSAPI_ERROR_STRING_NONE		)
osapi_error_machine_X( osapi_machine_error_generic, = OSAPI_ERROR_GENERIC,	OSAPI_ERROR_STRING_GENERIC	)
osapi_error_machine_X( osapi_machine_error_support, = OSAPI_ERROR_SUPPORT,	OSAPI_ERROR_STRING_SUPPORT	)
osapi_error_machine_X( osapi_machine_error_params,  = OSAPI_ERROR_INVPARAM,	OSAPI_ERROR_STRING_INVPARAM	)
osapi_error_machine_X( osapi_machine_error_unknown, = OSAPI_ERROR_UNKNOWN,	OSAPI_ERROR_STRING_UNKNOWN	)
osapi_error_machine_X( osapi_machine_error_cpuarch, ,				"Unsupported CPU architecture"	)
osapi_error_machine_X( osapi_machine_error_cpuid, ,				"CPUID not supported"		)
osapi_error_machine_X( osapi_machine_error_noData, ,				"No CPU data was collected"	)
osapi_error_machine_X( osapi_machine_error_invFID, ,				"Invalid CPU feature ID"	)
osapi_error_machine_X( osapi_machine_error_noVendor, ,				"Vendor not found"		)
osapi_error_machine_X( osapi_machine_error_noCapacity, ,			"Insufficient capacity"		)
osapi_error_machine_X( osapi_machine_error_canary, ,				"Memory unallocated/corrupted"	)
osapi_error_machine_X( osapi_machine_error_notEnoughMemory, ,			"Insufficient memory"		)

osapi_error_machine_X( osapi_machine_error_max, ,				OSAPI_ERROR_STRING_UNKNOWN	)
