// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General module definitions for CPU architectures
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_ARCHITECTURE_H_
#define OSAPI_GENERAL_ARCHITECTURE_H_


// *****************************************************************************************
//
// Section: CPU Architecture Constants
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_NONE	0 // Undefined architecture, also base

#define OSAPI_CPU_ARCHITECTURE_X86	1
#define OSAPI_CPU_ARCHITECTURE_AMD64	2
#define OSAPI_CPU_ARCHITECTURE_ARM	3
#define OSAPI_CPU_ARCHITECTURE_SPARC	4
#define OSAPI_CPU_ARCHITECTURE_ALPHA	5
#define OSAPI_CPU_ARCHITECTURE_POWERPC	6
#define OSAPI_CPU_ARCHITECTURE_MIPS	7
#define OSAPI_CPU_ARCHITECTURE_IA64	8
#define OSAPI_CPU_ARCHITECTURE_PARISC	9

#define OSAPI_CPU_ARCHITECTURE_MAX	10 // Last architecture +1


// *****************************************************************************************
//
// Section: INTEL CPU Architecture Specific versions (families)
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_INTEL_386	3
#define OSAPI_CPU_ARCHITECTURE_INTEL_486	4
#define OSAPI_CPU_ARCHITECTURE_INTEL_586	5
#define OSAPI_CPU_ARCHITECTURE_INTEL_686	6


// *****************************************************************************************
//
// Section: IA64 CPU Architecture Specific versions
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_IA64_32		1
#define OSAPI_CPU_ARCHITECTURE_IA64_E32		2
#define OSAPI_CPU_ARCHITECTURE_IA64_64		3


// *****************************************************************************************
//
// Section: ARM CPU Architecture Specific versions
//
// *****************************************************************************************

// 32 bit versions Legacy
#define OSAPI_CPU_ARCHITECTURE_ARM_V1		1
#define OSAPI_CPU_ARCHITECTURE_ARM_V2		2
#define OSAPI_CPU_ARCHITECTURE_ARM_V3		3
#define OSAPI_CPU_ARCHITECTURE_ARM_V4		4
#define OSAPI_CPU_ARCHITECTURE_ARM_V4T		5
#define OSAPI_CPU_ARCHITECTURE_ARM_V5TE		6
#define OSAPI_CPU_ARCHITECTURE_ARM_V6		7

// 32 bit versions Cortex
#define OSAPI_CPU_ARCHITECTURE_ARM_V6M		10
#define OSAPI_CPU_ARCHITECTURE_ARM_V7M		11
#define OSAPI_CPU_ARCHITECTURE_ARM_V7EM		12
#define OSAPI_CPU_ARCHITECTURE_ARM_V7R		13
#define OSAPI_CPU_ARCHITECTURE_ARM_V7A		14
#define OSAPI_CPU_ARCHITECTURE_ARM_V81M		15
#define OSAPI_CPU_ARCHITECTURE_ARM_V8R		16

// 64/32 bit architectures
#define OSAPI_CPU_ARCHITECTURE_ARM_V8A		20
#define OSAPI_CPU_ARCHITECTURE_ARM_V81A		21
#define OSAPI_CPU_ARCHITECTURE_ARM_V82A		22
#define OSAPI_CPU_ARCHITECTURE_ARM_V83A		23
#define OSAPI_CPU_ARCHITECTURE_ARM_V84A		24
#define OSAPI_CPU_ARCHITECTURE_ARM_V85A		25
#define OSAPI_CPU_ARCHITECTURE_ARM_V86A		26

// 64 bit architectures only
// #define OSAPI_CPU_ARCHITECTURE_ARM_V?	30



// *****************************************************************************************
//
// Section: Alpha CPU Architecture Specific versions
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_ALPHA_EV4	1
#define OSAPI_CPU_ARCHITECTURE_ALPHA_EV5	2
#define OSAPI_CPU_ARCHITECTURE_ALPHA_EV6	3
#define OSAPI_CPU_ARCHITECTURE_ALPHA_EV7	4

// *****************************************************************************************
//
// Section: POWERPC CPU Architecture Specific versions
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_POWERPC_G1	1
#define OSAPI_CPU_ARCHITECTURE_POWERPC_G2	2
#define OSAPI_CPU_ARCHITECTURE_POWERPC_G3	3
#define OSAPI_CPU_ARCHITECTURE_POWERPC_G4	4
#define OSAPI_CPU_ARCHITECTURE_POWERPC_G5	5
#define OSAPI_CPU_ARCHITECTURE_POWERPC_G6	6

// *****************************************************************************************
//
// Section: MIPS CPU Architecture Specific versions
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_MIPS_V1		1
#define OSAPI_CPU_ARCHITECTURE_MIPS_V2		2
#define OSAPI_CPU_ARCHITECTURE_MIPS_V3		3
#define OSAPI_CPU_ARCHITECTURE_MIPS_V4		4
#define OSAPI_CPU_ARCHITECTURE_MIPS_V5		5
#define OSAPI_CPU_ARCHITECTURE_MIPS_64		6
#define OSAPI_CPU_ARCHITECTURE_MIPS_Micro	7

// *****************************************************************************************
//
// Section: PARISC CPU Architecture Specific versions
//
// *****************************************************************************************

#define OSAPI_CPU_ARCHITECTURE_PARISC_TS_1	1
#define OSAPI_CPU_ARCHITECTURE_PARISC_CS_1	2
#define OSAPI_CPU_ARCHITECTURE_PARISC_NS_1	3
#define OSAPI_CPU_ARCHITECTURE_PARISC_NS_2	4
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX	5
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_S	6
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_T	7
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_L	8
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_L2	9
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_U	9
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_W	10
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_Maco	11
#define OSAPI_CPU_ARCHITECTURE_PARISC_PCX_SHORT	12


#endif /* OSAPI_GENERAL_ARCHITECTURE_H_ */
