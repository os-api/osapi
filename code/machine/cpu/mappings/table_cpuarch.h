// *********************************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide enum to string mappings for CPU Architecture information
//
//		In case the CPU endianess is either selectable or in some can operate in both ways, set it to biendian
//		A biendian CPU requires a check on the current operation mode, see calls osapi_endian_*
// *********************************************************************************************************************


osapi_machine_cpuarch_X( osapi_machine_cpuarch_none,	= OSAPI_CPU_ARCHITECTURE_NONE	,	"", 		OSAPI_ENDIANESS_NONE		)

// Intel / AMD features
osapi_machine_cpuarch_X( osapi_machine_cpuarch_x86, 	= OSAPI_CPU_ARCHITECTURE_X86	,	"x86",		OSAPI_ENDIANESS_LITTLE		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_amd64,	= OSAPI_CPU_ARCHITECTURE_AMD64	,	"x64",		OSAPI_ENDIANESS_LITTLE		)

// ARM is BIEndian since V3
osapi_machine_cpuarch_X( osapi_machine_cpuarch_arm, 	= OSAPI_CPU_ARCHITECTURE_ARM	,	"ARM",		OSAPI_ENDIANESS_BI		)

// Sparc-v9 is biendian
osapi_machine_cpuarch_X( osapi_machine_cpuarch_sparc, 	= OSAPI_CPU_ARCHITECTURE_SPARC	,	"Sparc",	OSAPI_ENDIANESS_BI		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_alpha, 	= OSAPI_CPU_ARCHITECTURE_ALPHA	,	"Alpha",	OSAPI_ENDIANESS_BI		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_powerpc,	= OSAPI_CPU_ARCHITECTURE_POWERPC,	"PowerPC",	OSAPI_ENDIANESS_BI		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_mips, 	= OSAPI_CPU_ARCHITECTURE_MIPS	,	"MIPS",		OSAPI_ENDIANESS_BI		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_ia64, 	= OSAPI_CPU_ARCHITECTURE_IA64	,	"IA64",		OSAPI_ENDIANESS_BI		)
osapi_machine_cpuarch_X( osapi_machine_cpuarch_parisc, 	= OSAPI_CPU_ARCHITECTURE_PARISC	,	"PARisc",	OSAPI_ENDIANESS_BI		)

osapi_machine_cpuarch_X( osapi_machine_cpuarch_max, 			,			"",		OSAPI_ENDIANESS_NONE		)
