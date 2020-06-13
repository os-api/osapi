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
#include "machine/cpu/type/machine_cpu_type_intel.h"



// *****************************************************************************************
//
// Section: Internal Function definition
//
// *****************************************************************************************


// Internal function, no check of inputs
void internal_cpu_intel_fs_1( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_s1_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = true;
  if( f.ecx.PCLMULQDQ	) 	p_list->feature[ osapi_machine_cpu_feature_pclmulqdq	] = true;
  if( f.ecx.DTES64	) 	p_list->feature[ osapi_machine_cpu_feature_dtes64	] = true;
  if( f.ecx.MONITOR	) 	p_list->feature[ osapi_machine_cpu_feature_monitor	] = true;
  if( f.ecx.DS_CPL	) 	p_list->feature[ osapi_machine_cpu_feature_ds_cpl	] = true;
  if( f.ecx.VMX		) 	p_list->feature[ osapi_machine_cpu_feature_vmx		] = true;
  if( f.ecx.SMX		) 	p_list->feature[ osapi_machine_cpu_feature_smx		] = true;
  if( f.ecx.EIST	) 	p_list->feature[ osapi_machine_cpu_feature_est		] = true;
  if( f.ecx.TM2		) 	p_list->feature[ osapi_machine_cpu_feature_tm2		] = true;
  if( f.ecx.SSSE3	) 	p_list->feature[ osapi_machine_cpu_feature_ssse3	] = true;
  if( f.ecx.CNXT_ID	) 	p_list->feature[ osapi_machine_cpu_feature_cid		] = true;
  if( f.ecx.SDBG	)	p_list->feature[ osapi_machine_cpu_feature_sdbg		] = true;
  if( f.ecx.FMA		) 	p_list->feature[ osapi_machine_cpu_feature_fma		] = true;
  if( f.ecx.CMPXCHG16B	)	p_list->feature[ osapi_machine_cpu_feature_cx16		] = true;
  if( f.ecx.XTPR	) 	p_list->feature[ osapi_machine_cpu_feature_xtpr		] = true;
  if( f.ecx.PDCM	) 	p_list->feature[ osapi_machine_cpu_feature_pdcm		] = true;
  if( f.ecx.PCID	) 	p_list->feature[ osapi_machine_cpu_feature_pcid		] = true;
  if( f.ecx.DCA		) 	p_list->feature[ osapi_machine_cpu_feature_dca		] = true;
  if( f.ecx.SSE4_1	) 	p_list->feature[ osapi_machine_cpu_feature_sse4_1	] = true;
  if( f.ecx.SSE4_2	) 	p_list->feature[ osapi_machine_cpu_feature_sse4_2	] = true;
  if( f.ecx.X2APIC	) 	p_list->feature[ osapi_machine_cpu_feature_x2apic	] = true;
  if( f.ecx.MOVBE	) 	p_list->feature[ osapi_machine_cpu_feature_movbe	] = true;
  if( f.ecx.POPCNT	) 	p_list->feature[ osapi_machine_cpu_feature_popcnt	] = true;
  if( f.ecx.TSC		) 	p_list->feature[ osapi_machine_cpu_feature_tsc_dt	] = true;
  if( f.ecx.AES		) 	p_list->feature[ osapi_machine_cpu_feature_aes		] = true;
  if( f.ecx.XSAVE	) 	p_list->feature[ osapi_machine_cpu_feature_xsave	] = true;
  if( f.ecx.OSXSAVE	)	p_list->feature[ osapi_machine_cpu_feature_xsaveopt	] = true;
  if( f.ecx.AVX		)	p_list->feature[ osapi_machine_cpu_feature_avx		] = true;
  if( f.ecx.F16C	)	p_list->feature[ osapi_machine_cpu_feature_f16c		] = true;
  if( f.ecx.RDRAND	)	p_list->feature[ osapi_machine_cpu_feature_rdrand	] = true;


  // EDX now
  if( f.edx.FPU		)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = true;
  if( f.edx.VME		)	p_list->feature[ osapi_machine_cpu_feature_vme		] = true;
  if( f.edx.DE		)	p_list->feature[ osapi_machine_cpu_feature_de		] = true;
  if( f.edx.PSE		)	p_list->feature[ osapi_machine_cpu_feature_pse		] = true;
  if( f.edx.TSC		)	p_list->feature[ osapi_machine_cpu_feature_tsc		] = true;
  if( f.edx.MSR		)	p_list->feature[ osapi_machine_cpu_feature_msr		] = true;
  if( f.edx.PAE		)	p_list->feature[ osapi_machine_cpu_feature_pae		] = true;
  if( f.edx.MCE		)	p_list->feature[ osapi_machine_cpu_feature_mce		] = true;
  if( f.edx.CX8		)	p_list->feature[ osapi_machine_cpu_feature_cx8		] = true;
  if( f.edx.APIC	)	p_list->feature[ osapi_machine_cpu_feature_apic		] = true;
  if( f.edx.SEP		)	p_list->feature[ osapi_machine_cpu_feature_syscall	] = true;
  if( f.edx.MTRR	)	p_list->feature[ osapi_machine_cpu_feature_mtrr		] = true;
  if( f.edx.PGE		)	p_list->feature[ osapi_machine_cpu_feature_pge		] = true;
  if( f.edx.MCA		)	p_list->feature[ osapi_machine_cpu_feature_mca		] = true;
  if( f.edx.CMOV	)	p_list->feature[ osapi_machine_cpu_feature_cmov		] = true;
  if( f.edx.PAT		)	p_list->feature[ osapi_machine_cpu_feature_pat		] = true;
  if( f.edx.PSE36	)	p_list->feature[ osapi_machine_cpu_feature_pse36	] = true;
  if( f.edx.PSN		)	p_list->feature[ osapi_machine_cpu_feature_psn		] = true;
  if( f.edx.CLFSH	)	p_list->feature[ osapi_machine_cpu_feature_clflush	] = true;
  if( f.edx.DS		)	p_list->feature[ osapi_machine_cpu_feature_dts		] = true;
  if( f.edx.ACPI	)	p_list->feature[ osapi_machine_cpu_feature_acpi		] = true;
  if( f.edx.MMX		)	p_list->feature[ osapi_machine_cpu_feature_mmx		] = true;
  if( f.edx.FXSR	)	p_list->feature[ osapi_machine_cpu_feature_fxsr		] = true;
  if( f.edx.SSE		)	p_list->feature[ osapi_machine_cpu_feature_sse		] = true;
  if( f.edx.SSE2	)	p_list->feature[ osapi_machine_cpu_feature_sse2		] = true;
  if( f.edx.SS		)	p_list->feature[ osapi_machine_cpu_feature_ss		] = true;
  if( f.edx.HTT		)	p_list->feature[ osapi_machine_cpu_feature_ht		] = true;
  if( f.edx.TM		)	p_list->feature[ osapi_machine_cpu_feature_tm		] = true;
  if( f.edx.PBE		)	p_list->feature[ osapi_machine_cpu_feature_pbe		] = true;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_intel_fs_6( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_s6_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  if( f.eax.DIGTEMP 	) 	p_list->feature[ osapi_machine_cpu_feature_dtherm 	] = true;
  if( f.eax.TRBOBST	) 	p_list->feature[ osapi_machine_cpu_feature_ida		] = true;	// Intel Dynamic Acceleration "rebranded" as Turbo Boost Technologies
  if( f.eax.ARAT 	) 	p_list->feature[ osapi_machine_cpu_feature_arat 	] = true;
  if( f.eax.PLN 	) 	p_list->feature[ osapi_machine_cpu_feature_pln	 	] = true;
  if( f.eax.ECMD 	) 	p_list->feature[ osapi_machine_cpu_feature_ecmd 	] = true;
  if( f.eax.PTM 	) 	p_list->feature[ osapi_machine_cpu_feature_pts	 	] = true;
  if( f.eax.HWP 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp	 	] = true;
  if( f.eax.HWP_NOT 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_notify 	] = true;
  if( f.eax.HWP_AW 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_act_win 	] = true;
  if( f.eax.HWP_EPP 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_epp 	] = true;
  if( f.eax.HWP_PLR 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_pkg_req 	] = true;
  if( f.eax.HDC 	) 	p_list->feature[ osapi_machine_cpu_feature_hdc 		] = true;
  if( f.eax.TBOOST_MAX 	) 	p_list->feature[ osapi_machine_cpu_feature_tboost_max 	] = true;
  if( f.eax.HWP_CAP 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_cap 	] = true;
  if( f.eax.HWP_PECI 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_peci 	] = true;
  if( f.eax.HWP_FLEX 	) 	p_list->feature[ osapi_machine_cpu_feature_hwp_flex 	] = true;
  if( f.eax.FAST_MODE 	) 	p_list->feature[ osapi_machine_cpu_feature_fam	 	] = true;
  if( f.eax.HW_FEEDBACK ) 	p_list->feature[ osapi_machine_cpu_feature_hw_feedback 	] = true;
  if( f.eax.HWP_IGNORE 	) 	p_list->feature[ osapi_machine_cpu_feature_lp_ignore 	] = true;

  if( f.ecx.HW_CFC	)	p_list->feature[ osapi_machine_cpu_feature_hw_cfc	] = true;
  if( f.ecx.ENERGY_BIAS	)	p_list->feature[ osapi_machine_cpu_feature_enegy_bias	] = true;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_intel_fs_7( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_s7_S		f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // EBX first
  if( f.ebx.FSGSBASE 		) 	p_list->feature[ osapi_machine_cpu_feature_fsgsbase 		] = true;
  if( f.ebx.SGX 		) 	p_list->feature[ osapi_machine_cpu_feature_sgx 			] = true;
  if( f.ebx.BMI1 		) 	p_list->feature[ osapi_machine_cpu_feature_bmi1 		] = true;
  if( f.ebx.HLE 		) 	p_list->feature[ osapi_machine_cpu_feature_hle 			] = true;
  if( f.ebx.AVX2 		) 	p_list->feature[ osapi_machine_cpu_feature_avx2 		] = true;
  if( f.ebx.SMEP 		) 	p_list->feature[ osapi_machine_cpu_feature_smep 		] = true;
  if( f.ebx.BMI2 		) 	p_list->feature[ osapi_machine_cpu_feature_bmi2 		] = true;
  if( f.ebx.ERMS 		) 	p_list->feature[ osapi_machine_cpu_feature_erms 		] = true;
  if( f.ebx.INVPCID 		) 	p_list->feature[ osapi_machine_cpu_feature_invpcid 		] = true;
  if( f.ebx.RTM 		) 	p_list->feature[ osapi_machine_cpu_feature_rtm 			] = true;
  if( f.ebx.PQM 		) 	p_list->feature[ osapi_machine_cpu_feature_pqm 			] = true;
  if( f.ebx.MPX 		) 	p_list->feature[ osapi_machine_cpu_feature_mpx 			] = true;
  if( f.ebx.PQE 		) 	p_list->feature[ osapi_machine_cpu_feature_pqe 			] = true;
  if( f.ebx.AVX512_F 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512f 		] = true;
  if( f.ebx.AVX512_DQ 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512dq 		] = true;
  if( f.ebx.RDSEED 		) 	p_list->feature[ osapi_machine_cpu_feature_rdseed 		] = true;
  if( f.ebx.ADX 		) 	p_list->feature[ osapi_machine_cpu_feature_adx	 		] = true;
  if( f.ebx.SMAP 		) 	p_list->feature[ osapi_machine_cpu_feature_smap 		] = true;
  if( f.ebx.AVX512_IFMA 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512ifma 		] = true;
  if( f.ebx.CLFLUSHOPT 		) 	p_list->feature[ osapi_machine_cpu_feature_clflushopt 		] = true;
  if( f.ebx.CLWB 		) 	p_list->feature[ osapi_machine_cpu_feature_clwb 		] = true;
  if( f.ebx.INTEL_PT 		) 	p_list->feature[ osapi_machine_cpu_feature_intel_pt 		] = true;
  if( f.ebx.AVX512_PF 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512pf 		] = true;
  if( f.ebx.AVX512_ER 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512er 		] = true;
  if( f.ebx.AVX512_CD 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512cd 		] = true;
  if( f.ebx.SHA 		) 	p_list->feature[ osapi_machine_cpu_feature_sha	 		] = true;
  if( f.ebx.AVX512_BW 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512bw 		] = true;
  if( f.ebx.AVX512_VL 		) 	p_list->feature[ osapi_machine_cpu_feature_avx512vl 		] = true;

  // ECX first
  if( f.ecx.PREFETCHWT1 	) 	p_list->feature[ osapi_machine_cpu_feature_prefetchwt1 		] = true;
  if( f.ecx.AVX512_VBMI 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vbmi 		] = true;
  if( f.ecx.UMIP 		) 	p_list->feature[ osapi_machine_cpu_feature_umip 		] = true;
  if( f.ecx.PKU 		) 	p_list->feature[ osapi_machine_cpu_feature_pku	 		] = true;
  if( f.ecx.OSPKE 		) 	p_list->feature[ osapi_machine_cpu_feature_ospke 		] = true;
  if( f.ecx.WAITPKG 		) 	p_list->feature[ osapi_machine_cpu_feature_waitpkg 		] = true;
  if( f.ecx.AVX512_VBMI2 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vbmi2 		] = true;
  if( f.ecx.GFNI 		) 	p_list->feature[ osapi_machine_cpu_feature_gfni 		] = true;
  if( f.ecx.VAES 		) 	p_list->feature[ osapi_machine_cpu_feature_vaes 		] = true;
  if( f.ecx.VPCLMULQDQ 		) 	p_list->feature[ osapi_machine_cpu_feature_vpclmulqdq 		] = true;
  if( f.ecx.AVX512_VNNI		) 	p_list->feature[ osapi_machine_cpu_feature_avx512vnni 		] = true;
  if( f.ecx.AVX512_BITALG 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512bitalg		] = true;
  if( f.ecx.AVX512_VPOPCNTDQ 	) 	p_list->feature[ osapi_machine_cpu_feature_avx512vpopcntdq 	] = true;
  if( f.ecx.RDPID 		) 	p_list->feature[ osapi_machine_cpu_feature_rdpid 		] = true;
  if( f.ecx.CLDEMOTE 		) 	p_list->feature[ osapi_machine_cpu_feature_cldemote 		] = true;
  if( f.ecx.MOVDIRI 		) 	p_list->feature[ osapi_machine_cpu_feature_movdiri 		] = true;
  if( f.ecx.MOVDIR64B 		) 	p_list->feature[ osapi_machine_cpu_feature_movdir64b 		] = true;
  if( f.ecx.ENQCMD 		) 	p_list->feature[ osapi_machine_cpu_feature_enqcmd 		] = true;
  if( f.ecx.SGX_LC 		) 	p_list->feature[ osapi_machine_cpu_feature_sgx_lc 		] = true;

  // EDX now
  if( f.edx.AVX512_4VNNIW	)	p_list->feature[ osapi_machine_cpu_feature_avx5124vnniw		] = true;
  if( f.edx.AVX512_4FMAPS	)	p_list->feature[ osapi_machine_cpu_feature_avx5124fmaps		] = true;
  if( f.edx.FSRM		)	p_list->feature[ osapi_machine_cpu_feature_fsrm			] = true;
  if( f.edx.AVX512_VP2I		)	p_list->feature[ osapi_machine_cpu_feature_avx512vp2i		] = true;
  if( f.edx.PCONFIG		)	p_list->feature[ osapi_machine_cpu_feature_pconfig		] = true;
  if( f.edx.SPEC_CTRL		)	p_list->feature[ osapi_machine_cpu_feature_spec_ctrl		] = true;
  if( f.edx.STIBP		)	p_list->feature[ osapi_machine_cpu_feature_stibp		] = true;
  if( f.edx.IA32_AC		)	p_list->feature[ osapi_machine_cpu_feature_sscm1		] = true;
  if( f.edx.IA32_CC		)	p_list->feature[ osapi_machine_cpu_feature_sscm2		] = true;
  if( f.edx.SSBD		)	p_list->feature[ osapi_machine_cpu_feature_ssbd			] = true;

  TRACE_MSG( "Leaving" )
}

void internal_cpu_intel_fs_7_1( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_s7_1_S		f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  if( f.eax.AVX512_BF16	) 	p_list->feature[ osapi_machine_cpu_feature_avx512bf16 	] = true;


  TRACE_MSG( "Leaving" )
}

void internal_cpu_intel_fs_16( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_s16_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  //if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = osapi_machine_cpu_feature_sse3;


  // EDX now
  //if( f.edx.FPU		)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = osapi_machine_cpu_feature_fpu;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_intel_fe_1( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_e1_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  if( f.ecx.LAHF_SAHF 	) 	p_list->feature[ osapi_machine_cpu_feature_lahf_lm 	] = true;
  if( f.ecx.CMP		) 	p_list->feature[ osapi_machine_cpu_feature_cmp_legacy	] = true;
  if( f.ecx.SVM		) 	p_list->feature[ osapi_machine_cpu_feature_svm		] = true;
  if( f.ecx.EXTAPIC	) 	p_list->feature[ osapi_machine_cpu_feature_extapic	] = true;
  if( f.ecx.CR8		) 	p_list->feature[ osapi_machine_cpu_feature_cr8_legacy	] = true;
  if( f.ecx.ABM		) 	p_list->feature[ osapi_machine_cpu_feature_abm		] = true;
  if( f.ecx.SSE4A	) 	p_list->feature[ osapi_machine_cpu_feature_sse4a	] = true;
  if( f.ecx.MISALIGN	) 	p_list->feature[ osapi_machine_cpu_feature_misalignsse	] = true;
  if( f.ecx.S3D_PREF	) 	p_list->feature[ osapi_machine_cpu_feature_3dnowpref	] = true;
  if( f.ecx.OSVW	) 	p_list->feature[ osapi_machine_cpu_feature_osvw		] = true;
  if( f.ecx.IBS		) 	p_list->feature[ osapi_machine_cpu_feature_ibs		] = true;
  if( f.ecx.XOP		) 	p_list->feature[ osapi_machine_cpu_feature_xop		] = true;
  if( f.ecx.SKINIT	) 	p_list->feature[ osapi_machine_cpu_feature_skinit	] = true;
  if( f.ecx.WDT		) 	p_list->feature[ osapi_machine_cpu_feature_wdt		] = true;
  if( f.ecx.LWP		) 	p_list->feature[ osapi_machine_cpu_feature_lwp		] = true;
  if( f.ecx.FMA4	) 	p_list->feature[ osapi_machine_cpu_feature_fma4		] = true;
  if( f.ecx.TCE		) 	p_list->feature[ osapi_machine_cpu_feature_tce		] = true;
  if( f.ecx.NID		) 	p_list->feature[ osapi_machine_cpu_feature_nodeid_msr	] = true;
  if( f.ecx.TBM		) 	p_list->feature[ osapi_machine_cpu_feature_tbm		] = true;
  if( f.ecx.TOPO	) 	p_list->feature[ osapi_machine_cpu_feature_topoext	] = true;
  if( f.ecx.PCORE	) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_core	] = true;
  if( f.ecx.PNB		) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_nb	] = true;
  if( f.ecx.DBX		) 	p_list->feature[ osapi_machine_cpu_feature_bpext	] = true;
  if( f.ecx.PTSC	) 	p_list->feature[ osapi_machine_cpu_feature_ptsc		] = true;
  if( f.ecx.PL2		) 	p_list->feature[ osapi_machine_cpu_feature_perfctr_l2	] = true;


  // EDX now

  if( f.edx.MP		)	p_list->feature[ osapi_machine_cpu_feature_mp		] = true;
  if( f.edx.NX		)	p_list->feature[ osapi_machine_cpu_feature_nx		] = true;
  if( f.edx.MMXEXT	)	p_list->feature[ osapi_machine_cpu_feature_mmxext	] = true;
  if( f.edx.FXSR_OPT	)	p_list->feature[ osapi_machine_cpu_feature_fxsr_opt	] = true;
  if( f.edx.PDP1GB	)	p_list->feature[ osapi_machine_cpu_feature_pdpe1gb	] = true;
  if( f.edx.RDTSCP	)	p_list->feature[ osapi_machine_cpu_feature_rdtscp	] = true;
  if( f.edx.LM		)	p_list->feature[ osapi_machine_cpu_feature_lm		] = true;
  if( f.edx.E3DNOW	)	p_list->feature[ osapi_machine_cpu_feature_3dnowext	] = true;
  if( f.edx.S3DNOW	)	p_list->feature[ osapi_machine_cpu_feature_3dnow	] = true;

  TRACE_MSG( "Leaving" )
}


static inline void getStandardFeature7( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
 TRACE_ENTER

 TRACE_MSG("Testing level 7")

 internal_cpu_intel_fs_7  ( p_regs, p_list );

 // Sub-leaf 1
 if( p_regs->eax >= 1 && ! common_asm_cpuid( 7, 1, p_regs ))
     internal_cpu_intel_fs_7_1( p_regs, p_list );

 TRACE_MSG( "Leaving" )
}



void internal_cpu_intel_fe_7( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_e7_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  //if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = osapi_machine_cpu_feature_sse3;


  // EDX now
  //if( f.edx.FPU	)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = osapi_machine_cpu_feature_fpu;

  TRACE_MSG( "Leaving" )
}


void internal_cpu_intel_fe_8( t_cpu_regs * p_regs, t_cpu_feature_list * p_list )
{
  struct intel_cpu_e8_S	f;

  TRACE_ENTER

  osapi_static_assert( sizeof(f) == 16, "Wrong CPU register structures" );

  // Copy structure for naming purposed
  memcpy( &f, p_regs, sizeof( f ) );

  // For each feature present, add it to the list
  // ECX first
  //if( f.ecx.SSE3 	) 	p_list->feature[ osapi_machine_cpu_feature_sse3 	] = osapi_machine_cpu_feature_sse3;


  // EDX now
  //if( f.edx.FPU	)	p_list->feature[ osapi_machine_cpu_feature_fpu		] = osapi_machine_cpu_feature_fpu;

  TRACE_MSG( "Leaving" )
}

t_status internal_cpu_intel_getFeatures( uint32_t featLevel, t_cpu_feature_list * p_list )
{
 t_status	st;
 t_cpu_regs	regs;

 TRACE_ENTER

 osapi_static_assert( sizeof( regs ) == 16, "Wrong CPU register structures" );

 status_reset( &st );

 if( p_list == NULL )
   { status_iset( OSAPI_MODULE_MACHINE, __func__, osapi_machine_error_params, &st ); return st; }

 TRACE( "Entering with feature level:%d", featLevel )

 for( uint32_t i=1; i <= featLevel; i++ )
   {
     if( ! common_asm_cpuid( i, 0, &regs ) )
       {
	 switch( i )
	 {
	   case 1: 	internal_cpu_intel_fs_1  ( &regs, p_list ); break;
	   case 6: 	internal_cpu_intel_fs_6  ( &regs, p_list ); break;
	   case 7:	getStandardFeature7	 ( &regs, p_list ); break;
	   case 16: 	internal_cpu_intel_fs_16 ( &regs, p_list ); break;
	 }
       }
   }

 // Get the max extended supported CPUID functions
 common_asm_cpuid( 0x80000000, 0, &regs );
 if( regs.eax == 0 ) return st;
 featLevel = regs.eax;

 TRACE( "Max. standard CPUID level: 0x%x", featLevel )

 for( uint32_t i=0x80000001; i <= featLevel; i++ )
   {
     if( ! common_asm_cpuid( i, 0, &regs ) )
       {
	 switch( i )
	 {
	   case 0x80000001: internal_cpu_intel_fe_1  ( &regs, p_list ); break;
	   //case 0x80000007: internal_cpu_intel_fe_7  ( &regs, p_list ); break;
	   //case 0x80000008: internal_cpu_intel_fe_8  ( &regs, p_list ); break;
	 }
       }
   }

 TRACE_MSG( "Leaving" )

 return st;
}


#endif	// Intel interfaces
