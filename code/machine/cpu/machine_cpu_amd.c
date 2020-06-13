// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines a generic machine CPU implementation (like an interface)
//		and calls the specific cpu architecture implementation
//
// *****************************************************************************************

#if (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_X86) || (OSAPI_CPU_ARCHITECTURE_TARGET == OSAPI_CPU_ARCHITECTURE_AMD64)


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"


// System headers <here>
#include <stdint.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_machine.h"
#include "status/status.h"
#include "status/trace_macros.h"
#include "common/common_machine.h"

// Own declarations
#include "machine/machine_cpu.h"
#include "machine/cpu/machine_cpu_common.h"
#include "machine/cpu/type/machine_cpu_type_amd.h"



// *****************************************************************************************
//
// Section: Internal Function definition
//
// *****************************************************************************************
/*

// Internal function, no check of inputs
void internal_cpu_amd_fs_1(t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct amd_cpu_s1_S	f;

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = (t_cpu_feature) osapi_machine_cpu_feature_sse3;
  if( f.ecx.PCLMULQDQ	) 	p_list->feature[ osapi_machine_cpu_feature_pclmulqdq	] = (t_cpu_feature) osapi_machine_cpu_feature_pclmulqdq;
  if( f.ecx.DTES64	) 	p_list->feature[ osapi_machine_cpu_feature_dtes64	] = (t_cpu_feature) osapi_machine_cpu_feature_dtes64;
  if( f.ecx.MONITOR	) 	p_list->feature[ osapi_machine_cpu_feature_monitor	] = (t_cpu_feature) osapi_machine_cpu_feature_monitor;
  if( f.ecx.DS_CPL	) 	p_list->feature[ osapi_machine_cpu_feature_ds_cpl	] = (t_cpu_feature) osapi_machine_cpu_feature_ds_cpl;
  if( f.ecx.VMX		) 	p_list->feature[ osapi_machine_cpu_feature_vmx		] = (t_cpu_feature) osapi_machine_cpu_feature_vmx;
  if( f.ecx.SMX		) 	p_list->feature[ osapi_machine_cpu_feature_smx		] = (t_cpu_feature) osapi_machine_cpu_feature_sse;
  if( f.ecx.EIST	) 	p_list->feature[ osapi_machine_cpu_feature_est		] = (t_cpu_feature) osapi_machine_cpu_feature_est;
  if( f.ecx.TM2		) 	p_list->feature[ osapi_machine_cpu_feature_tm2		] = (t_cpu_feature) osapi_machine_cpu_feature_tm2;
  if( f.ecx.SSSE3	) 	p_list->feature[ osapi_machine_cpu_feature_ssse3	] = (t_cpu_feature) osapi_machine_cpu_feature_ssse3;
  if( f.ecx.CNXT_ID	) 	p_list->feature[ osapi_machine_cpu_feature_cid		] = (t_cpu_feature) osapi_machine_cpu_feature_cid;
  if( f.ecx.SDBG	)	p_list->feature[ osapi_machine_cpu_feature_sdbg		] = (t_cpu_feature) osapi_machine_cpu_feature_sdbg;
  if( f.ecx.FMA		) 	p_list->feature[ osapi_machine_cpu_feature_fma		] = (t_cpu_feature) osapi_machine_cpu_feature_fma;
  if( f.ecx.CMPXCHG16B	)	p_list->feature[ osapi_machine_cpu_feature_cx16		] = (t_cpu_feature) osapi_machine_cpu_feature_cx16;
  if( f.ecx.XTPR	) 	p_list->feature[ osapi_machine_cpu_feature_xtpr		] = (t_cpu_feature) osapi_machine_cpu_feature_xtpr;
  if( f.ecx.PDCM	) 	p_list->feature[ osapi_machine_cpu_feature_pdcm		] = (t_cpu_feature) osapi_machine_cpu_feature_pdcm;
  if( f.ecx.PCID	) 	p_list->feature[ osapi_machine_cpu_feature_pcid		] = (t_cpu_feature) osapi_machine_cpu_feature_pcid;
  if( f.ecx.DCA		) 	p_list->feature[ osapi_machine_cpu_feature_dca		] = (t_cpu_feature) osapi_machine_cpu_feature_dca;
  if( f.ecx.SSE4_1	) 	p_list->feature[ osapi_machine_cpu_feature_sse4_1	] = (t_cpu_feature) osapi_machine_cpu_feature_sse4_1;
  if( f.ecx.SSE4_2	) 	p_list->feature[ osapi_machine_cpu_feature_sse4_2	] = (t_cpu_feature) osapi_machine_cpu_feature_sse4_2;
  if( f.ecx.X2APIC	) 	p_list->feature[ osapi_machine_cpu_feature_x2apic	] = (t_cpu_feature) osapi_machine_cpu_feature_x2apic;
  if( f.ecx.MOVBE	) 	p_list->feature[ osapi_machine_cpu_feature_movbe	] = (t_cpu_feature) osapi_machine_cpu_feature_movbe;
  if( f.ecx.POPCNT	) 	p_list->feature[ osapi_machine_cpu_feature_popcnt	] = (t_cpu_feature) osapi_machine_cpu_feature_popcnt;
  if( f.ecx.TSC		) 	p_list->feature[ osapi_machine_cpu_feature_tsc_dt	] = (t_cpu_feature) osapi_machine_cpu_feature_tsc_dt;
  if( f.ecx.AES		) 	p_list->feature[ osapi_machine_cpu_feature_aes		] = (t_cpu_feature) osapi_machine_cpu_feature_aes;
  if( f.ecx.XSAVE	) 	p_list->feature[ osapi_machine_cpu_feature_xsave	] = (t_cpu_feature) osapi_machine_cpu_feature_xsave;
  if( f.ecx.OSXSAVE	)	p_list->feature[ osapi_machine_cpu_feature_xsaveopt	] = (t_cpu_feature) osapi_machine_cpu_feature_xsaveopt;
  if( f.ecx.AVX		)	p_list->feature[ osapi_machine_cpu_feature_avx		] = (t_cpu_feature) osapi_machine_cpu_feature_avx;
  if( f.ecx.F16C	)	p_list->feature[ osapi_machine_cpu_feature_f16c		] = (t_cpu_feature) osapi_machine_cpu_feature_f16c;
  if( f.ecx.RDRAND	)	p_list->feature[ osapi_machine_cpu_feature_rdrand	] = (t_cpu_feature) osapi_machine_cpu_feature_rdrand;


  // EDX now
  if( f.edx.FPU		)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = (t_cpu_feature) osapi_machine_cpu_feature_fpu;
  if( f.edx.VME		)	p_list->feature[ osapi_machine_cpu_feature_vme		] = (t_cpu_feature) osapi_machine_cpu_feature_vme;
  if( f.edx.DE		)	p_list->feature[ osapi_machine_cpu_feature_de		] = (t_cpu_feature) osapi_machine_cpu_feature_de;
  if( f.edx.PSE		)	p_list->feature[ osapi_machine_cpu_feature_pse		] = (t_cpu_feature) osapi_machine_cpu_feature_pse;
  if( f.edx.TSC		)	p_list->feature[ osapi_machine_cpu_feature_tsc		] = (t_cpu_feature) osapi_machine_cpu_feature_tsc;
  if( f.edx.MSR		)	p_list->feature[ osapi_machine_cpu_feature_msr		] = (t_cpu_feature) osapi_machine_cpu_feature_msr;
  if( f.edx.PAE		)	p_list->feature[ osapi_machine_cpu_feature_pae		] = (t_cpu_feature) osapi_machine_cpu_feature_pae;
  if( f.edx.MCE		)	p_list->feature[ osapi_machine_cpu_feature_mce		] = (t_cpu_feature) osapi_machine_cpu_feature_mce;
  if( f.edx.CX8		)	p_list->feature[ osapi_machine_cpu_feature_cx8		] = (t_cpu_feature) osapi_machine_cpu_feature_cx8;
  if( f.edx.APIC	)	p_list->feature[ osapi_machine_cpu_feature_apic		] = (t_cpu_feature) osapi_machine_cpu_feature_apic;
  if( f.edx.SEP		)	p_list->feature[ osapi_machine_cpu_feature_syscall	] = (t_cpu_feature) osapi_machine_cpu_feature_syscall;
  if( f.edx.MTRR	)	p_list->feature[ osapi_machine_cpu_feature_mtrr		] = (t_cpu_feature) osapi_machine_cpu_feature_mtrr;
  if( f.edx.PGE		)	p_list->feature[ osapi_machine_cpu_feature_pge		] = (t_cpu_feature) osapi_machine_cpu_feature_pge;
  if( f.edx.MCA		)	p_list->feature[ osapi_machine_cpu_feature_mca		] = (t_cpu_feature) osapi_machine_cpu_feature_mca;
  if( f.edx.CMOV	)	p_list->feature[ osapi_machine_cpu_feature_cmov		] = (t_cpu_feature) osapi_machine_cpu_feature_cmov;
  if( f.edx.PAT		)	p_list->feature[ osapi_machine_cpu_feature_pat		] = (t_cpu_feature) osapi_machine_cpu_feature_pat;
  if( f.edx.PSE36	)	p_list->feature[ osapi_machine_cpu_feature_pse36	] = (t_cpu_feature) osapi_machine_cpu_feature_pse36;
  if( f.edx.PSN		)	p_list->feature[ osapi_machine_cpu_feature_psn		] = (t_cpu_feature) osapi_machine_cpu_feature_psn;
  if( f.edx.CLFSH	)	p_list->feature[ osapi_machine_cpu_feature_clflush	] = (t_cpu_feature) osapi_machine_cpu_feature_clflush;
  if( f.edx.DS		)	p_list->feature[ osapi_machine_cpu_feature_dts		] = (t_cpu_feature) osapi_machine_cpu_feature_dts;
  if( f.edx.ACPI	)	p_list->feature[ osapi_machine_cpu_feature_acpi		] = (t_cpu_feature) osapi_machine_cpu_feature_acpi;
  if( f.edx.MMX		)	p_list->feature[ osapi_machine_cpu_feature_mmx		] = (t_cpu_feature) osapi_machine_cpu_feature_mmx;
  if( f.edx.FXSR	)	p_list->feature[ osapi_machine_cpu_feature_fxsr		] = (t_cpu_feature) osapi_machine_cpu_feature_fxsr;
  if( f.edx.SSE		)	p_list->feature[ osapi_machine_cpu_feature_sse		] = (t_cpu_feature) osapi_machine_cpu_feature_sse;
  if( f.edx.SSE2	)	p_list->feature[ osapi_machine_cpu_feature_sse2		] = (t_cpu_feature) osapi_machine_cpu_feature_sse2;
  if( f.edx.SS		)	p_list->feature[ osapi_machine_cpu_feature_ss		] = (t_cpu_feature) osapi_machine_cpu_feature_ss;
  if( f.edx.HTT		)	p_list->feature[ osapi_machine_cpu_feature_ht		] = (t_cpu_feature) osapi_machine_cpu_feature_ht;
  if( f.edx.TM		)	p_list->feature[ osapi_machine_cpu_feature_tm		] = (t_cpu_feature) osapi_machine_cpu_feature_tm;
  if( f.edx.PBE		)	p_list->feature[ osapi_machine_cpu_feature_pbe		] = (t_cpu_feature) osapi_machine_cpu_feature_pbe;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_amd_fs_6(t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct amd_cpu_s1_S	f;

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = (t_cpu_feature) osapi_machine_cpu_feature_sse3;
  if( f.ecx.PCLMULQDQ	) 	p_list->feature[ osapi_machine_cpu_feature_pclmulqdq	] = (t_cpu_feature) osapi_machine_cpu_feature_pclmulqdq;

  // EDX now
  if( f.edx.FPU		)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = (t_cpu_feature) osapi_machine_cpu_feature_fpu;
  if( f.edx.VME		)	p_list->feature[ osapi_machine_cpu_feature_vme		] = (t_cpu_feature) osapi_machine_cpu_feature_vme;
  if( f.edx.DE		)	p_list->feature[ osapi_machine_cpu_feature_de		] = (t_cpu_feature) osapi_machine_cpu_feature_de;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_amd_fs_7(t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct amd_cpu_s7_S		f;

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // EBX first
  if( f.ebx.FSGSBASE 		) 	p_list->feature[ osapi_machine_cpu_feature_fsgsbase 		] = (t_cpu_feature) osapi_machine_cpu_feature_fsgsbase;
  if( f.ebx.SGX 		) 	p_list->feature[ osapi_machine_cpu_feature_sgx 			] = (t_cpu_feature) osapi_machine_cpu_feature_sgx;
  if( f.ebx.BMI1 		) 	p_list->feature[ osapi_machine_cpu_feature_bmi1 		] = (t_cpu_feature) osapi_machine_cpu_feature_bmi1;
  if( f.ebx.HLE 		) 	p_list->feature[ osapi_machine_cpu_feature_hle 			] = (t_cpu_feature) osapi_machine_cpu_feature_hle;
  if( f.ebx.AVX2 		) 	p_list->feature[ osapi_machine_cpu_feature_avx2 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx2;
  if( f.ebx.SMEP 		) 	p_list->feature[ osapi_machine_cpu_feature_smep 		] = (t_cpu_feature) osapi_machine_cpu_feature_smep;
  if( f.ebx.BMI2 		) 	p_list->feature[ osapi_machine_cpu_feature_bmi2 		] = (t_cpu_feature) osapi_machine_cpu_feature_bmi2;
  if( f.ebx.ERMS 		) 	p_list->feature[ osapi_machine_cpu_feature_erms 		] = (t_cpu_feature) osapi_machine_cpu_feature_erms;
  if( f.ebx.INVPCID 		) 	p_list->feature[ osapi_machine_cpu_feature_invpcid 		] = (t_cpu_feature) osapi_machine_cpu_feature_invpcid;
  if( f.ebx.RTM 		) 	p_list->feature[ osapi_machine_cpu_feature_rtm 			] = (t_cpu_feature) osapi_machine_cpu_feature_rtm;
  if( f.ebx.PQM 		) 	p_list->feature[ osapi_machine_cpu_feature_pqm 			] = (t_cpu_feature) osapi_machine_cpu_feature_pqm;
  if( f.ebx.MPX 		) 	p_list->feature[ osapi_machine_cpu_feature_mpx 			] = (t_cpu_feature) osapi_machine_cpu_feature_mpx;
  if( f.ebx.PQE 		) 	p_list->feature[ osapi_machine_cpu_feature_pqe 			] = (t_cpu_feature) osapi_machine_cpu_feature_pqe;
  if( f.ebx.AVX512_F 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512f 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512f;
  if( f.ebx.AVX512_DQ 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512dq 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512dq;
  if( f.ebx.RDSEED 		) 	p_list->feature[ osapi_machine_cpu_feature_rdseed 		] = (t_cpu_feature) osapi_machine_cpu_feature_rdseed;
  if( f.ebx.ADX 		) 	p_list->feature[ osapi_machine_cpu_feature_adx	 		] = (t_cpu_feature) osapi_machine_cpu_feature_adx;
  if( f.ebx.SMAP 		) 	p_list->feature[ osapi_machine_cpu_feature_smap 		] = (t_cpu_feature) osapi_machine_cpu_feature_smap;
  if( f.ebx.AVX512_IFMA 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512ifma 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512ifma;
  if( f.ebx.CLFLUSHOPT 		) 	p_list->feature[ osapi_machine_cpu_feature_clflushopt 		] = (t_cpu_feature) osapi_machine_cpu_feature_clflushopt;
  if( f.ebx.CLWB 		) 	p_list->feature[ osapi_machine_cpu_feature_clwb 		] = (t_cpu_feature) osapi_machine_cpu_feature_clwb;
  if( f.ebx.INTEL_PT 		) 	p_list->feature[ osapi_machine_cpu_feature_amd_pt 		] = (t_cpu_feature) osapi_machine_cpu_feature_amd_pt;
  if( f.ebx.AVX512_PF 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512pf 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512pf;
  if( f.ebx.AVX512_ER 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512er 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512er;
  if( f.ebx.AVX512_CD 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512cd 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512cd;
  if( f.ebx.SHA 		) 	p_list->feature[ osapi_machine_cpu_feature_sha	 		] = (t_cpu_feature) osapi_machine_cpu_feature_sha;
  if( f.ebx.AVX512_BW 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512bw 		] = (t_cpu_feature) osapi_machine_cpu_feature_fsgsbase;
  if( f.ebx.AVX512_VL 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512vl 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vl;

  // ECX first
  if( f.ecx.PREFETCHWT1 	) 	p_list->feature[ osapi_machine_cpu_feature_prefetchwt1 		] = (t_cpu_feature) osapi_machine_cpu_feature_prefetchwt1;
  if( f.ecx.AVX512_VBMI 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vbmi 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vbmi;
  if( f.ecx.UMIP 		) 	p_list->feature[ osapi_machine_cpu_feature_umip 		] = (t_cpu_feature) osapi_machine_cpu_feature_umip;
  if( f.ecx.PKU 		) 	p_list->feature[ osapi_machine_cpu_feature_pku	 		] = (t_cpu_feature) osapi_machine_cpu_feature_pku;
  if( f.ecx.OSPKE 		) 	p_list->feature[ osapi_machine_cpu_feature_ospke 		] = (t_cpu_feature) osapi_machine_cpu_feature_ospke;
  if( f.ecx.WAITPKG 		) 	p_list->feature[ osapi_machine_cpu_feature_waitpkg 		] = (t_cpu_feature) osapi_machine_cpu_feature_waitpkg;
  if( f.ecx.AVX512_VBMI2 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vbmi2 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vbmi2;
  if( f.ecx.GFNI 		) 	p_list->feature[ osapi_machine_cpu_feature_gfni 		] = (t_cpu_feature) osapi_machine_cpu_feature_gfni;
  if( f.ecx.VAES 		) 	p_list->feature[ osapi_machine_cpu_feature_vaes 		] = (t_cpu_feature) osapi_machine_cpu_feature_vaes;
  if( f.ecx.VPCLMULQDQ 		) 	p_list->feature[ osapi_machine_cpu_feature_vpclmulqdq 		] = (t_cpu_feature) osapi_machine_cpu_feature_vpclmulqdq;
  if( f.ecx.AVX512_VNNI		) 	p_list->feature[ osapi_machine_cpu_feature_avx512vnni 		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vnni;
  if( f.ecx.AVX512_BITALG 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512bitalg		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512bitalg;
  if( f.ecx.AVX512_VPOPCNTDQ 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vpopcntdq 	] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vpopcntdq;
  if( f.ecx.RDPID 		) 	p_list->feature[ osapi_machine_cpu_feature_rdpid 		] = (t_cpu_feature) osapi_machine_cpu_feature_rdpid;
  if( f.ecx.CLDEMOTE 		) 	p_list->feature[ osapi_machine_cpu_feature_cldemote 		] = (t_cpu_feature) osapi_machine_cpu_feature_cldemote;
  if( f.ecx.MOVDIRI 		) 	p_list->feature[ osapi_machine_cpu_feature_movdiri 		] = (t_cpu_feature) osapi_machine_cpu_feature_movdiri;
  if( f.ecx.MOVDIR64B 		) 	p_list->feature[ osapi_machine_cpu_feature_movdir64b 		] = (t_cpu_feature) osapi_machine_cpu_feature_movdir64b;
  if( f.ecx.ENQCMD 		) 	p_list->feature[ osapi_machine_cpu_feature_enqcmd 		] = (t_cpu_feature) osapi_machine_cpu_feature_enqcmd;
  if( f.ecx.SGX_LC 		) 	p_list->feature[ osapi_machine_cpu_feature_sgx_lc 		] = (t_cpu_feature) osapi_machine_cpu_feature_sgx_lc;

  // EDX now
  if( f.edx.AVX512_4VNNIW	)	p_list->feature[ osapi_machine_cpu_feature_avx5124vnniw		] = (t_cpu_feature) osapi_machine_cpu_feature_avx5124vnniw;
  if( f.edx.AVX512_4FMAPS	)	p_list->feature[ osapi_machine_cpu_feature_avx5124fmaps		] = (t_cpu_feature) osapi_machine_cpu_feature_avx5124fmaps;
  if( f.edx.FSRM		)	p_list->feature[ osapi_machine_cpu_feature_fsrm			] = (t_cpu_feature) osapi_machine_cpu_feature_fsrm;
  if( f.edx.AVX512_VP2I		)	p_list->feature[ osapi_machine_cpu_feature_avx512vp2i		] = (t_cpu_feature) osapi_machine_cpu_feature_avx512vp2i;
  if( f.edx.PCONFIG		)	p_list->feature[ osapi_machine_cpu_feature_pconfig		] = (t_cpu_feature) osapi_machine_cpu_feature_pconfig;
  if( f.edx.SPEC_CTRL		)	p_list->feature[ osapi_machine_cpu_feature_spec_ctrl		] = (t_cpu_feature) osapi_machine_cpu_feature_spec_ctrl;
  if( f.edx.STIBP		)	p_list->feature[ osapi_machine_cpu_feature_stibp		] = (t_cpu_feature) osapi_machine_cpu_feature_stibp;
  if( f.edx.IA32_AC		)	p_list->feature[ osapi_machine_cpu_feature_sscm1		] = (t_cpu_feature) osapi_machine_cpu_feature_sscm1;
  if( f.edx.IA32_CC		)	p_list->feature[ osapi_machine_cpu_feature_sscm2		] = (t_cpu_feature) osapi_machine_cpu_feature_sscm2;
  if( f.edx.SSBD		)	p_list->feature[ osapi_machine_cpu_feature_ssbd			] = (t_cpu_feature) osapi_machine_cpu_feature_ssbd;

  TRACE_MSG( "Leaving" )
}

void internal_cpu_amd_fs_7_1(t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct amd_cpu_s7_1_S		f;

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  //if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = osapi_machine_cpu_feature_sse3;


  // EDX now
  //if( f.edx.FPU		)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = osapi_machine_cpu_feature_fpu;

  TRACE_MSG( "Leaving" )
}

void internal_cpu_amd_fe_1(t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct amd_cpu_e1_S	f;

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  if( f.ecx.LAHF_SAHF 	) 	p_list->feature[ osapi_machine_cpu_feature_lahf_lm 	] = (t_cpu_feature) osapi_machine_cpu_feature_lahf_lm;
  if( f.ecx.CMP		) 	p_list->feature[ osapi_machine_cpu_feature_cmp_legacy	] = (t_cpu_feature) osapi_machine_cpu_feature_cmp_legacy;
  if( f.ecx.SVM		) 	p_list->feature[ osapi_machine_cpu_feature_svm		] = (t_cpu_feature) osapi_machine_cpu_feature_svm;
  if( f.ecx.EXTAPIC	) 	p_list->feature[ osapi_machine_cpu_feature_extapic	] = (t_cpu_feature) osapi_machine_cpu_feature_extapic;
  if( f.ecx.CR8		) 	p_list->feature[ osapi_machine_cpu_feature_cr8_legacy	] = (t_cpu_feature) osapi_machine_cpu_feature_cr8_legacy;
  if( f.ecx.ABM		) 	p_list->feature[ osapi_machine_cpu_feature_abm		] = (t_cpu_feature) osapi_machine_cpu_feature_abm;
  if( f.ecx.SSE4A	) 	p_list->feature[ osapi_machine_cpu_feature_sse4a	] = (t_cpu_feature) osapi_machine_cpu_feature_sse4a;
  if( f.ecx.MISALIGN	) 	p_list->feature[ osapi_machine_cpu_feature_misalignsse	] = (t_cpu_feature) osapi_machine_cpu_feature_misalignsse;
  if( f.ecx.S3D_PREF	) 	p_list->feature[ osapi_machine_cpu_feature_3dnowpref	] = (t_cpu_feature) osapi_machine_cpu_feature_3dnowpref;
  if( f.ecx.OSVW	) 	p_list->feature[ osapi_machine_cpu_feature_osvw		] = (t_cpu_feature) osapi_machine_cpu_feature_osvw;
  if( f.ecx.IBS		) 	p_list->feature[ osapi_machine_cpu_feature_ibs		] = (t_cpu_feature) osapi_machine_cpu_feature_ibs;
  if( f.ecx.XOP		) 	p_list->feature[ osapi_machine_cpu_feature_xop		] = (t_cpu_feature) osapi_machine_cpu_feature_xop;
  if( f.ecx.SKINIT	) 	p_list->feature[ osapi_machine_cpu_feature_skinit	] = (t_cpu_feature) osapi_machine_cpu_feature_skinit;
  if( f.ecx.WDT		) 	p_list->feature[ osapi_machine_cpu_feature_wdt		] = (t_cpu_feature) osapi_machine_cpu_feature_wdt;
  if( f.ecx.LWP		) 	p_list->feature[ osapi_machine_cpu_feature_lwp		] = (t_cpu_feature) osapi_machine_cpu_feature_lwp;
  if( f.ecx.FMA4	) 	p_list->feature[ osapi_machine_cpu_feature_fma4		] = (t_cpu_feature) osapi_machine_cpu_feature_fma4;
  if( f.ecx.TCE		) 	p_list->feature[ osapi_machine_cpu_feature_tce		] = (t_cpu_feature) osapi_machine_cpu_feature_tce;
  if( f.ecx.NID		) 	p_list->feature[ osapi_machine_cpu_feature_nodeid_msr	] = (t_cpu_feature) osapi_machine_cpu_feature_nodeid_msr;
  if( f.ecx.TBM		) 	p_list->feature[ osapi_machine_cpu_feature_tbm		] = (t_cpu_feature) osapi_machine_cpu_feature_tbm;
  if( f.ecx.TOPO	) 	p_list->feature[ osapi_machine_cpu_feature_topoext	] = (t_cpu_feature) osapi_machine_cpu_feature_topoext;
  if( f.ecx.PCORE	) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_core	] = (t_cpu_feature) osapi_machine_cpu_feature_perfctr_core;
  if( f.ecx.PNB		) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_nb	] = (t_cpu_feature) osapi_machine_cpu_feature_perfctr_nb;
  if( f.ecx.DBX		) 	p_list->feature[ osapi_machine_cpu_feature_bpext	] = (t_cpu_feature) osapi_machine_cpu_feature_bpext;
  if( f.ecx.PTSC	) 	p_list->feature[ osapi_machine_cpu_feature_ptsc		] = (t_cpu_feature) osapi_machine_cpu_feature_ptsc;
  if( f.ecx.PL2		) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_l2	] = (t_cpu_feature) osapi_machine_cpu_feature_perfctr_l2;


  // EDX now

  if( f.edx.MP		)	p_list->feature[ osapi_machine_cpu_feature_mp		] = (t_cpu_feature) osapi_machine_cpu_feature_mp;
  if( f.edx.NX		)	p_list->feature[ osapi_machine_cpu_feature_nx		] = (t_cpu_feature) osapi_machine_cpu_feature_nx;
  if( f.edx.MMXEXT	)	p_list->feature[ osapi_machine_cpu_feature_mmxext	] = (t_cpu_feature) osapi_machine_cpu_feature_mmxext;
  if( f.edx.FXSR_OPT	)	p_list->feature[ osapi_machine_cpu_feature_fxsr_opt	] = (t_cpu_feature) osapi_machine_cpu_feature_fxsr_opt;
  if( f.edx.PDP1GB	)	p_list->feature[ osapi_machine_cpu_feature_pdpe1gb	] = (t_cpu_feature) osapi_machine_cpu_feature_pdpe1gb;
  if( f.edx.RDTSCP	)	p_list->feature[ osapi_machine_cpu_feature_rdtscp	] = (t_cpu_feature) osapi_machine_cpu_feature_rdtscp;
  if( f.edx.LM		)	p_list->feature[ osapi_machine_cpu_feature_lm		] = (t_cpu_feature) osapi_machine_cpu_feature_lm;
  if( f.edx.E3DNOW	)	p_list->feature[ osapi_machine_cpu_feature_3dnowext	] = (t_cpu_feature) osapi_machine_cpu_feature_3dnowext;
  if( f.edx.S3DNOW	)	p_list->feature[ osapi_machine_cpu_feature_3dnow	] = (t_cpu_feature) osapi_machine_cpu_feature_3dnow;

  TRACE_MSG( "Leaving" )
}



static inline void getStandardFeature1( t_cpu_feature_list * p_list )
{
 t_cpu_regs	regs;

 TRACE_MSG("Testing level 1")

 common_asm_cpuid( 1, 0, &regs );
 internal_cpu_amd_fs_1( &regs, p_list );
}


static inline void getStandardFeature7( t_cpu_feature_list * p_list )
{
 t_cpu_regs	regs;

 TRACE_MSG("Testing level 7")

 common_asm_cpuid( 7, 0, &regs );
 internal_cpu_amd_fs_7  ( &regs, p_list ); // Sub-leaf 0

 // Sub-leaf 1
 if( regs.eax >= 1 )
   {
     internal_machine_asm_cpuid( 7, 1, &regs );
     internal_cpu_amd_fs_7_1( &regs, p_list );
   }
}


static inline void getExtendedFeature1( t_cpu_feature_list * p_list )
{
 t_cpu_regs	regs;

 TRACE_MSG("Testing level 0x80000001")

 common_asm_cpuid( 0x80000001, 0, &regs );
 internal_cpu_amd_fe_1( &regs, p_list );
}

*/
t_status internal_cpu_amd_getFeatures( uint32_t featLevel, t_cpu_feature_list * p_list )
{
 t_status	st;
 /*
 t_cpu_regs	regs;

 osapi_static_assert( sizeof( regs ) == 16, "Wrong CPU register structures" );

 status_reset( &st );

 if( p_list == NULL )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 TRACE_ENTER

 if( featLevel > 0 ) getStandardFeature1( p_list );
 if( featLevel > 6 ) getStandardFeature7( p_list );

 // Get the max extended supported CPUID functions
 common_asm_cpuid( 0x80000000, 0, &regs );
 if( regs.eax == 0 ) return st;
 featLevel = regs.eax;

 TRACE( "Max. standard CPUID level: 0x%x", featLevel )

 if( featLevel >= 0x80000001 ) getExtendedFeature1( p_list );
 //if( featLevel >= 0x80000001 ) getExtendedFeature1( p_list );

 TRACE_EXIT
*/

 // AMD CPUs are not yet supported.
 status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_support, &st );

 return st;
}


#endif	// Intel interfaces
