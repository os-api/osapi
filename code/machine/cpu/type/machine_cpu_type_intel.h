// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Intel CPU specific declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_INTEL_H_
#define OSAPI_MACHINE_CPU_TYPE_INTEL_H_

#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stdint.h>



// *****************************************************************************************
//
// Section: Define structures for Standard CPUID functions
//
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 1
// *****************************************************************************************

///< Intel Standard CPUID 1, register EAX
struct intel_cpu_s1_a_S
{
  uint32_t	revision:4;		// 1-4
  uint32_t	model:4;		// 5-8
  uint32_t	family_id:4;		// 9-12
  uint32_t	type:2;			// 13-14
  uint32_t	:1;			// 15
  uint32_t	ext_model:4;		// 16-19
  uint32_t	ext_family:8;		// 20-28
  uint32_t	:4;			// 29-32
};

///< Intel Standard CPUID 1, register EBX
struct intel_cpu_s1_b_S
{
  uint32_t	brand_index:8;		// 1-8
  uint32_t	cf_lnsize:8;		// 8-16
  uint32_t	max_lcpus:8;		// 17-24
  uint32_t	initial_apic_id:1;	// 25-32
};

///< Intel Standard CPUID 1, register ECX
struct intel_cpu_s1_c_S
{
  uint32_t	SSE3:1;		// 1
  uint32_t	PCLMULQDQ:1;	// 2
  uint32_t	DTES64:1;	// 3
  uint32_t	MONITOR:1;	// 4
  uint32_t	DS_CPL:1;	// 5
  uint32_t	VMX:1;		// 6
  uint32_t	SMX:1;		// 7
  uint32_t	EIST:1;		// 8
  uint32_t	TM2:1;		// 9
  uint32_t	SSSE3:1;	// 10
  uint32_t	CNXT_ID:1;	// 11
  uint32_t	SDBG:1;		// 12
  uint32_t	FMA:1;		// 13
  uint32_t	CMPXCHG16B:1;	// 14
  uint32_t	XTPR:1;		// 15
  uint32_t	PDCM:1;		// 16
  uint32_t	:1;		// 17
  uint32_t	PCID:1;		// 18
  uint32_t	DCA:1;		// 19
  uint32_t	SSE4_1:1;	// 20
  uint32_t	SSE4_2:1;	// 21
  uint32_t	X2APIC:1;	// 22
  uint32_t	MOVBE:1;	// 23
  uint32_t	POPCNT:1;	// 24
  uint32_t	TSC:1;		// 25
  uint32_t	AES:1;		// 26
  uint32_t	XSAVE:1;	// 27
  uint32_t	OSXSAVE:1;	// 28
  uint32_t	AVX:1;		// 29
  uint32_t	F16C:1;		// 30
  uint32_t	RDRAND:1;	// 31
  uint32_t	:1;		// 32
};


///< Intel Standard CPUID 1, register EDX
struct intel_cpu_s1_d_S
{
  uint32_t	FPU:1;		// 1
  uint32_t	VME:1;		// 2
  uint32_t	DE:1;		// 3
  uint32_t	PSE:1;		// 4
  uint32_t	TSC:1;		// 5
  uint32_t	MSR:1;		// 6
  uint32_t	PAE:1;		// 7
  uint32_t	MCE:1;		// 8
  uint32_t	CX8:1;		// 9
  uint32_t	APIC:1;		// 10
  uint32_t	:1;		// 11
  uint32_t	SEP:1;		// 12
  uint32_t	MTRR:1;		// 13
  uint32_t	PGE:1;		// 14
  uint32_t	MCA:1;		// 15
  uint32_t	CMOV:1;		// 16
  uint32_t	PAT:1;		// 17
  uint32_t	PSE36:1;	// 18
  uint32_t	PSN:1;		// 19
  uint32_t	CLFSH:1;	// 20
  uint32_t	:1;		// 21
  uint32_t	DS:1;		// 22
  uint32_t	ACPI:1;		// 23
  uint32_t	MMX:1;		// 24
  uint32_t	FXSR:1;		// 25
  uint32_t	SSE:1;		// 26
  uint32_t	SSE2:1;		// 27
  uint32_t	SS:1;		// 28
  uint32_t	HTT:1;		// 29
  uint32_t	TM:1;		// 30
  uint32_t	:1;		// 31 (Reserved)
  uint32_t	PBE:1;		// 32
};

///< Structure that matches the register structure
struct intel_cpu_s1_S
{
  struct intel_cpu_s1_a_S	eax;
  struct intel_cpu_s1_b_S	ebx;
  struct intel_cpu_s1_c_S	ecx;
  struct intel_cpu_s1_d_S	edx;
};


// *****************************************************************************************
// Standard CPUID function 2 - Cache and TLB Information
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 3 - Processor serial number
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 4 - Deterministic Cache Parameters
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 5 - Monitor/MWAIT
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function 6 - Thermal and Power Management
// *****************************************************************************************

///< Intel Standard CPUID 6, register EAX
struct intel_cpu_s6_a_S
{
  uint32_t	DIGTEMP:1;		// 1
  uint32_t	TRBOBST:1;		// 2
  uint32_t	ARAT:1;			// 3
  uint32_t	:1;			// 4
  uint32_t	PLN:1;			// 5
  uint32_t	ECMD:1;			// 6
  uint32_t	PTM:1;			// 7
  uint32_t	HWP:1;			// 8
  uint32_t	HWP_NOT:1;		// 9
  uint32_t	HWP_AW:1;		// 10
  uint32_t	HWP_EPP:1;		// 11
  uint32_t	HWP_PLR:1;		// 12
  uint32_t	:1;			// 13
  uint32_t	HDC:1;			// 14
  uint32_t	TBOOST_MAX:1;		// 15
  uint32_t	HWP_CAP:1;		// 16
  uint32_t	HWP_PECI:1;		// 17
  uint32_t	HWP_FLEX:1;		// 18
  uint32_t	FAST_MODE:1;		// 19
  uint32_t	HW_FEEDBACK:1;		// 20
  uint32_t	HWP_IGNORE:1;		// 21
  uint32_t	:11;			// 22-32
};

///< Intel Standard CPUID 6, register EBX
struct intel_cpu_s6_b_S
{
  uint32_t	dgt_interrupts:4;	// 4
  uint32_t	:28;			// 28
};

///< Intel Standard CPUID 6, register ECX
struct intel_cpu_s6_c_S
{
  uint32_t	HW_CFC:1;		// 1
  uint32_t	:2;			// 2-3
  uint32_t	ENERGY_BIAS:1;		// 4
  uint32_t	:28;			// 5-32
};

///< Intel Standard CPUID 6, register EDX
struct intel_cpu_s6_d_S
{
  uint32_t	hw_feedback_support:1;	// 1
  uint32_t	hw_feedback:7;		// 2-8
  uint32_t	hw_fb_enum:4;		// 9-12
  uint32_t	:4;			// 13-16 ?
  uint32_t	hw_fb_index:16;		// 17-32
};


///< Structure that matches the register structure
struct intel_cpu_s6_S
{
  struct intel_cpu_s6_a_S	eax;
  struct intel_cpu_s6_b_S	ebx;
  struct intel_cpu_s6_c_S	ecx;
  struct intel_cpu_s6_d_S	edx;
};


// *****************************************************************************************
// Standard CPUID function 7 - Extended feature flags
// *****************************************************************************************

///< Intel Standard CPUID 7, register EAX
struct intel_cpu_s7_a_S
{
  uint32_t	max_subleaves:32;	// All
};

///< Intel Standard CPUID 7, register EBX
struct intel_cpu_s7_b_S
{
  uint32_t	FSGSBASE:1;		// 1
  uint32_t	:1;			// 2		: IA32_TSC_ADJUST
  uint32_t	SGX:1;			// 3
  uint32_t	BMI1:1;			// 4
  uint32_t	HLE:1;			// 5
  uint32_t	AVX2:1;			// 6
  uint32_t	SMEP:1;			// 8
  uint32_t	:1;			// 7
  uint32_t	BMI2:1;			// 9
  uint32_t	ERMS:1;			// 10
  uint32_t	INVPCID:1;		// 11
  uint32_t	RTM:1;			// 12
  uint32_t	PQM:1;			// 13
  uint32_t	:1;			// 14		Deprecates FPU CS and DS if on
  uint32_t	MPX:1;			// 15
  uint32_t	PQE:1;			// 16
  uint32_t	AVX512_F:1;		// 17
  uint32_t	AVX512_DQ:1;		// 18
  uint32_t	RDSEED:1;		// 19
  uint32_t	ADX:1;			// 20
  uint32_t	SMAP:1;			// 21
  uint32_t	AVX512_IFMA:1;		// 22
  uint32_t	:1;			// 23
  uint32_t	CLFLUSHOPT:1;		// 24
  uint32_t	CLWB:1;			// 25
  uint32_t	INTEL_PT:1;		// 26
  uint32_t	AVX512_PF:1;		// 27
  uint32_t	AVX512_ER:1;		// 28
  uint32_t	AVX512_CD:1;		// 29
  uint32_t	SHA:1;			// 30
  uint32_t	AVX512_BW:1;		// 31
  uint32_t	AVX512_VL:1;		// 32

};

///< Intel Standard CPUID 7, register ECX
struct intel_cpu_s7_c_S
{
  uint32_t	PREFETCHWT1:1;		// 1
  uint32_t	AVX512_VBMI:1;		// 2
  uint32_t	UMIP:1;			// 3
  uint32_t	PKU:1;			// 4
  uint32_t	OSPKE:1;		// 5
  uint32_t	WAITPKG:1;		// 6
  uint32_t	AVX512_VBMI2:1;		// 7
  uint32_t	:1;			// 8
  uint32_t	GFNI:1;			// 9
  uint32_t	VAES:1;			// 10
  uint32_t	VPCLMULQDQ:1;		// 11
  uint32_t	AVX512_VNNI:1;		// 12
  uint32_t	AVX512_BITALG:1;	// 13
  uint32_t	:1;			// 14
  uint32_t	AVX512_VPOPCNTDQ:1;	// 15
  uint32_t	:7;			// 16-22 (The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode)
  uint32_t	RDPID:1;		// 23
  uint32_t	:2;			// 24-25 (reserved)
  uint32_t	CLDEMOTE:1;		// 26
  uint32_t	:1;			// 27
  uint32_t	MOVDIRI:1;		// 28
  uint32_t	MOVDIR64B:1;		// 29
  uint32_t	ENQCMD:1;		// 30
  uint32_t	SGX_LC:1;		// 31
  uint32_t	:1;			// 32
};


///< Intel Standard CPUID 7, register EDX
struct intel_cpu_s7_d_S
{
  uint32_t	:2;			// 1-2
  uint32_t	AVX512_4VNNIW:1;	// 3
  uint32_t	AVX512_4FMAPS:1;	// 4
  uint32_t	FSRM:1;			// 5
  uint32_t	:3;			// 6-8
  uint32_t	AVX512_VP2I:1;		// 9
  uint32_t	:8;			// 10-18 Reserved
  uint32_t	PCONFIG:1;		// 19
  uint32_t	:7;			// 20-26 Reserved
  uint32_t	SPEC_CTRL:1;		// 27
  uint32_t	STIBP:1;		// 28
  uint32_t	:1;			// 29
  uint32_t	IA32_AC:1;		// 30
  uint32_t	IA32_CC:1;		// 31
  uint32_t	SSBD:1;			// 32

};

///< Structure that matches the register structure for request 7, option 0 (sub-leaf)
struct intel_cpu_s7_S
{
  struct intel_cpu_s7_a_S	eax;
  struct intel_cpu_s7_b_S	ebx;
  struct intel_cpu_s7_c_S	ecx;
  struct intel_cpu_s7_d_S	edx;
};


///< Intel Standard CPUID 7, leaf 1, register EAX
struct intel_cpu_s7_1_a_S
{
  uint32_t	:5;			// 1-5
  uint32_t	AVX512_BF16:1;		// 6
  uint32_t	:26;			// 7-32
};


///< Structure that matches the register structure for request 7, option 1 (sub-leaf)
struct intel_cpu_s7_1_S
{
  struct intel_cpu_s7_1_a_S	eax;
  uint32_t			ebx;
  uint32_t			ecx;
  uint32_t			edx;
};



// *****************************************************************************************
// Standard CPUID function 9 - Direct Cache Access Information
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function A - Architecture Performance Monitoring
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function B - Extended Topology
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function D - Processor Extended State
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function F - Intel Resource Director Technology (RDT) Monitoring
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 10h - L3 Cache RDT Monitoring capabiity
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 12h - Software Guard Extensions Capacity enumeration
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 14h - Processor Trace
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function 15h - Time Stamp Counter and Core Crystal Clock Information
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function 16h - Processor Frequency Information
// *****************************************************************************************

// All frequencies are in MHz and are factory settings, not actual values

struct intel_cpu_s16_a_S
{
  uint32_t	freq_base:16;		// 1-16
  uint32_t	:16;			// 17-32
};


struct intel_cpu_s16_b_S
{
  uint32_t	freq_max:16;		// 1-16
  uint32_t	:16;			// 17-32
};

struct intel_cpu_s16_c_S
{
  uint32_t	freq_bus:16;		// 1-16
  uint32_t	:16;			// 17-32
};


// Structure that matches the register structure
struct intel_cpu_s16_S
{
  struct intel_cpu_s16_a_S	eax;
  struct intel_cpu_s16_b_S	ebx;
  struct intel_cpu_s16_c_S	ecx;
  uint32_t			edx;
};


// *****************************************************************************************
// Standard CPUID function 17h - System-On-Chip Vendor Attribute
// *****************************************************************************************


// *****************************************************************************************
// Standard CPUID function 18h - Deterministic Address Translation Parameters
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 1B - PCONFIG Information
// *****************************************************************************************

// *****************************************************************************************
// Standard CPUID function 1F - V2 Extended Topology enumeration
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Define structures for Extended CPUID functions (0x8000xxxxH)
//
// *****************************************************************************************


// *****************************************************************************************
// Extended CPUID function 1 - Extended CPUID information
// *****************************************************************************************

struct intel_cpu_e1_c_S
{
  uint32_t	LAHF_SAHF:1;	// 1
  uint32_t	CMP:1;		// 2
  uint32_t	SVM:1;		// 3
  uint32_t	EXTAPIC:1;	// 4
  uint32_t	CR8:1;		// 5
  uint32_t	ABM:1;		// 6
  uint32_t	SSE4A:1;	// 7
  uint32_t	MISALIGN:1;	// 8
  uint32_t	S3D_PREF:1;	// 9
  uint32_t	OSVW:1;		// 10
  uint32_t	IBS:1;		// 11
  uint32_t	XOP:1;		// 12
  uint32_t	SKINIT:1;	// 13
  uint32_t	WDT:1;		// 14
  uint32_t	:1;		// 15
  uint32_t	LWP:1;		// 16
  uint32_t	FMA4:1;		// 17
  uint32_t	TCE:1;		// 18
  uint32_t	:1;		// 19
  uint32_t	NID:1;		// 20
  uint32_t	:1;		// 21
  uint32_t	TBM:1;		// 22
  uint32_t	TOPO:1;		// 23
  uint32_t	PCORE:1;	// 24
  uint32_t	PNB:1;		// 25
  uint32_t	:1;		// 26
  uint32_t	DBX:1;		// 27
  uint32_t	PTSC:1;		// 28
  uint32_t	PL2:1;		// 29
  uint32_t	:3;		// 30-32

};


struct intel_cpu_e1_d_S
{
  uint32_t	:19;		// 1-19		// Already available in standard function 1 ( SEP & SYSCALL are the same instruction? )
  uint32_t	MP:1;		// 20
  uint32_t	NX:1;		// 21
  uint32_t	:1;		// 22
  uint32_t	MMXEXT:1;	// 23
  uint32_t	:2;		// 24-25
  uint32_t	FXSR_OPT:1;	// 26
  uint32_t	PDP1GB:1;	// 27
  uint32_t	RDTSCP:1;	// 28
  uint32_t	:1;		// 29
  uint32_t	LM:1;		// 30
  uint32_t	E3DNOW:1;	// 31
  uint32_t	S3DNOW:1;	// 32
};


// Structure that matches the register structure
struct intel_cpu_e1_S
{
  uint32_t			eax;
  uint32_t			ebx;
  struct intel_cpu_e1_c_S	ecx;
  struct intel_cpu_e1_d_S	edx;
};


// *****************************************************************************************
// Extended CPUID function 2 - CPU Brand 1
// *****************************************************************************************


// *****************************************************************************************
// Extended CPUID function 3 - CPU Brand 2
// *****************************************************************************************

// *****************************************************************************************
// Extended CPUID function 4 - CPU Brand 3
// *****************************************************************************************

// *****************************************************************************************
// Extended CPUID function 6 - Cache line information
// *****************************************************************************************


// *****************************************************************************************
// Extended CPUID function 7 - Invariant TSC
// *****************************************************************************************

struct intel_cpu_e7_b_S
{
  uint32_t	:8;		// 1-8
  uint32_t	INVTSC:1;	// 9
};

// Structure that matches the register structure
struct intel_cpu_e7_S
{
  uint32_t			eax;
  struct intel_cpu_e7_b_S	ebx;
  uint32_t			ecx;
  uint32_t			edx;
};

// *****************************************************************************************
// Extended CPUID function 8 - Virtual/Physical Address size
// *****************************************************************************************

struct intel_cpu_e8_b_S
{
  uint32_t	:9;		// 1-9
  uint32_t	WBNOINVD:1;	// 10
  uint32_t	:22;		// 11-32
};

// Structure that matches the register structure
struct intel_cpu_e8_S
{
  uint32_t			eax;
  struct intel_cpu_e8_b_S	ebx;
  uint32_t			ecx;
  uint32_t			edx;
};



#endif	// X86 & AMD64

#endif /* OSAPI_MACHINE_CPU_COMMON_H_ */
