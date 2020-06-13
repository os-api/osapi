// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide AMD CPU specific declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_CPU_TYPE_AMD_H_
#define OSAPI_MACHINE_CPU_TYPE_AMD_H_

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

struct amd_cpu_features_s1_c_S
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
  uint32_t	:1;		// 12
  uint32_t	FMA:1;		// 13
  uint32_t	CMPXCHG16B:1;	// 14
  uint32_t	XTPR:1;		// 15
  uint32_t	PDCM:1;		// 16
  uint32_t	:1;		// 17
  uint32_t	:1;		// 18
  uint32_t	DCA:1;		// 19
  uint32_t	SSE4_1:1;	// 20
  uint32_t	SSE4_2:1;	// 21
  uint32_t	x2APIC:1;	// 22
  uint32_t	MOVBE:1;	// 23
  uint32_t	:1;		// 24
  uint32_t	POPCNT:1;	// 25
  uint32_t	AES:1;		// 26
  uint32_t	XSAVE:1;	// 27
  uint32_t	OSXSAVE:1;	// 28
  uint32_t	AVX:1;		// 29
  uint32_t	F16C:1;		// 30
  uint32_t	RDRAND:1;	// 31
  uint32_t	HYPERVISOR:1;	// 32
};


struct amd_cpu_features_s1_d_S
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
  uint32_t	:1;		// 10
  uint32_t	APIC:1;		// 11
  uint32_t	SEP:1;		// 12
  uint32_t	MTRR:1;		// 13
  uint32_t	PGE:1;		// 14
  uint32_t	MCA:1;		// 15
  uint32_t	CMOV:1;		// 16
  uint32_t	PAT:1;		// 17
  uint32_t	PSE36:1;	// 18
  uint32_t	PSN:1;		// 19
  uint32_t	:1;		// 20
  uint32_t	CLFSH:1;	// 21
  uint32_t	DS:1;		// 22
  uint32_t	ACPI:1;		// 23
  uint32_t	MMX:1;		// 24
  uint32_t	FXSR:1;		// 25
  uint32_t	SSE:1;		// 26
  uint32_t	SSE2:1;		// 27
  uint32_t	SS:1;		// 28
  uint32_t	HTT:1;		// 29
  uint32_t	:1;		// 30
  uint32_t	TM:1;		// 31
  uint32_t	PBE:1;		// 32
};

// Structure that matches the register structure
struct amd_cpu_features_s1_S
{
  uint32_t				eax;
  uint32_t				ebx;
  struct amd_cpu_features_s1_c_S	ecx;
  struct amd_cpu_features_s1_d_S	edx;
};


// *****************************************************************************************
// Standard CPUID function 6
// *****************************************************************************************

struct amd_cpu_features_s6_a_S
{
  uint32_t	DIGTEMP:1;	// 1
  uint32_t	TRBOBST:1;	// 2
  uint32_t	ARAT:1;		// 3
};


struct amd_cpu_features_s6_c_S
{
  uint32_t	MPERF_APERF_MSR:1;	// 1
};

// Structure that matches the register structure
struct amd_cpu_features_s6_S
{
  struct amd_cpu_features_s6_a_S	eax;
  uint32_t				ebx;
  struct amd_cpu_features_s6_c_S	ecx;
  uint32_t				edx;
};



// *****************************************************************************************
// Standard CPUID function 7
// *****************************************************************************************

struct amd_cpu_features_s7_b_S
{
  uint32_t	FSGSBASE:1;		// 1
  uint32_t	:1;			// 2
  uint32_t	SGX:1;			// 3
  uint32_t	BMI1:1;			// 4
  uint32_t	HLE:1;			// 5
  uint32_t	AVX2:1;			// 6
  uint32_t	:1;			// 7
  uint32_t	SMEP:1;			// 8
  uint32_t	BMI2:1;			// 9
  uint32_t	ERMS:1;			// 10
  uint32_t	INVPCID:1;		// 11
  uint32_t	RTM:1;			// 12
  uint32_t	PQM:1;			// 13
  uint32_t	:1;			// 14
  uint32_t	MPX:1;			// 15
  uint32_t	PQE:1;			// 16
  uint32_t	AVX512_F:1;		// 17
  uint32_t	AVX512_DQ:1;		// 18
  uint32_t	RDSEED:1;		// 19
  uint32_t	ADX:1;			// 20
  uint32_t	SMAP:1;			// 21
  uint32_t	AVX512_IFMA:1;		// 22
  uint32_t	PCOMMIT:1;		// 23
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


struct amd_cpu_features_s7_c_S
{
  uint32_t	PREFETCHWT1:1;		// 1
  uint32_t	AVX512_VBMI:1;		// 2
  uint32_t	UMIP:1;			// 3
  uint32_t	PKU:1;			// 4
  uint32_t	OSPKE:1;		// 5
  uint32_t	WAITPKG:1;		// 6
  uint32_t	AVX512_VBMI2:1;		// 7
  uint32_t	SHSTK:1;		// 8
  uint32_t	GFNI:1;			// 9
  uint32_t	VAES:1;			// 10
  uint32_t	VPCLMULQDQ:1;		// 11
  uint32_t	AVX512_VNNI:1;		// 12
  uint32_t	AVX512_BITALG:1;	// 13
  uint32_t	:1;			// 14
  uint32_t	AVX512_VPOPCNTDQ:1;	// 15
  uint32_t	:1;			// 16
  uint32_t	:1;			// 17
  uint32_t	:5;			// 18-22 (The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode)
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


struct amd_cpu_features_s7_d_S
{
  uint32_t	:1;			// 1
  uint32_t	:1;			// 2
  uint32_t	AVX512_4VNNIW:1;	// 3
  uint32_t	AVX512_4FMAPS:1;	// 4
  uint32_t	FSRM:1;			// 5
  uint32_t	:3;			// 6-8
  uint32_t	AVX512_VP2I:1;		// 9
  uint32_t	:1;			// 10
  uint32_t	MD_CLEAR:1;		// 11
  uint32_t	:2;			// 12-13
  uint32_t	TSX_FORCE_ABORT:1;	// 14
  uint32_t	SERIALIZE:1;		// 15
  uint32_t	HYBRID:1;		// 16
  uint32_t	TSXLDTRK:1;		// 17
  uint32_t	:1;			// 18
  uint32_t	PCONFIG:1;		// 19
  uint32_t	:1;			// 20
  uint32_t	IBT:1;			// 21
  uint32_t	:5;			// 22-26
  uint32_t	SPEC_CTRL:1;		// 27
  uint32_t	STIBP:1;		// 28
  uint32_t	:1;			// 29
  uint32_t	IA32_AC:1;		// 30
  uint32_t	IA32_CC:1;		// 31
  uint32_t	SSBD:1;			// 32

};

// Structure that matches the register structure for request 7, option 0 (sub-leaf)
struct amd_cpu_features_s7_S
{
  uint32_t				eax;
  struct amd_cpu_features_s7_b_S	ebx;
  struct amd_cpu_features_s7_c_S	ecx;
  struct amd_cpu_features_s7_d_S	edx;
};


struct amd_cpu_features_s7_1_a_S
{
  uint32_t	:5;			// 1-5
  uint32_t	AVX512_BF16:1;		// 6
  uint32_t	:26;			// 7-32

};


// Structure that matches the register structure for request 7, option 1 (sub-leaf)
struct amd_cpu_features_s7_1_S
{
  struct amd_cpu_features_s7_1_a_S	exx;
  uint32_t				ebx;
  uint32_t				ecx;
  uint32_t				edx;
};



// *****************************************************************************************
// Standard CPUID function D
// *****************************************************************************************
/*
struct common_features_sd_a_S
{
  uint32_t	DIGTEMP:1;	// 1
  uint32_t	TRBOBST:1;	// 2
  uint32_t	ARAT:1;		// 3
};


struct common_features_sd_c_S
{
  uint32_t	MPERF_APERF_MSR:1;	// 1
};


// Structure that matches the register structure
struct common_features_sd_S
{
  struct common_features_sd_a_S		eax;
  uint32_t				ebx;
  struct common_features_sd_c_S		ecx;
  uint32_t				edx;
};
*/

// *****************************************************************************************
// Standard CPUID function F
// *****************************************************************************************
/*
struct common_features_sf_a_S
{
  uint32_t	DIGTEMP:1;	// 1
  uint32_t	TRBOBST:1;	// 2
  uint32_t	ARAT:1;		// 3
};


struct common_features_sf_c_S
{
  uint32_t	MPERF_APERF_MSR:1;	// 1
};


// Structure that matches the register structure
struct common_features_sf_S
{
  struct common_features_sf_a_S		eax;
  uint32_t				ebx;
  struct common_features_sf_c_S		ecx;
  uint32_t				edx;
};
*/

// *****************************************************************************************
//
// Section: Define structures for Extended CPUID functions
//
// *****************************************************************************************


// *****************************************************************************************
// Extended CPUID function 1
// *****************************************************************************************

struct amd_cpu_features_e1_c_S
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
  uint32_t	BPEXT:1;	// 27
  uint32_t	PTSC:1;		// 28
  uint32_t	PL2:1;		// 29
  uint32_t	:3;		// 30-32

};


struct amd_cpu_features_e1_d_S
{
  uint32_t	:19;		// 1-19		// Already available in standard function 1
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
struct amd_cpu_features_e1_S
{
  uint32_t				eax;
  uint32_t				ebx;
  struct amd_cpu_features_e1_c_S	ecx;
  struct amd_cpu_features_e1_d_S	edx;
};


// *****************************************************************************************
// Extended CPUID function 7
// *****************************************************************************************
/*
struct common_features_e7_c_S
{
  uint32_t	:8;		// 1-8
  uint32_t	INVTSC:1;	// 9
};

// Structure that matches the register structure
struct common_features_e7_S
{
  uint32_t				eax;
  uint32_t				ebx;
  struct common_features_e7_c_S		ecx;
  uint32_t				edx;
};

*/

// *****************************************************************************************
// Extended CPUID function 7
// *****************************************************************************************

struct amd_cpu_features_e7_b_S
{
  uint32_t	:8;		// 1-8
  uint32_t	INVTSC:1;	// 9
};

// Structure that matches the register structure
struct amd_cpu_features_e7_S
{
  uint32_t				eax;
  struct amd_cpu_features_e7_b_S	ebx;
  uint32_t				ecx;
  uint32_t				edx;
};

// *****************************************************************************************
// Extended CPUID function 8
// *****************************************************************************************

struct amd_cpu_features_e8_c_S
{
  uint32_t	:8;		// 1-8
  uint32_t	INVTSC:1;	// 9
};

// Structure that matches the register structure
struct amd_cpu_features_e8_S
{
  uint32_t				eax;
  uint32_t				ebx;
  struct amd_cpu_features_e8_c_S	ecx;
  uint32_t				edx;
};


// *****************************************************************************************
// Extended CPUID function A
// *****************************************************************************************

struct amd_cpu_features_eA_c_S
{
  uint32_t	:8;		// 1-8
  uint32_t	INVTSC:1;	// 9
};

// Structure that matches the register structure
struct amd_cpu_features_eA_S
{
  uint32_t				eax;
  uint32_t				ebx;
  struct amd_cpu_features_eA_c_S	ecx;
  uint32_t				edx;
};


#endif	// AMD64

#endif /* OSAPI_MACHINE_CPU_TYPE_AMD_H_ */
