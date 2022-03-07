/******************************************************************************
*
*       Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2018
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
*       Freescale Semiconductor, Inc.
*
*       Description: Memory map file
*
*       Note: The implementation that was used is: AUTOSAR_MPC5600
*       System Generator for AUTOSAR OS/MPC5600 - Version: 4.0 Build 4.0.69
*
********************************************************************************/
/*  --- CONST DATA ---  */

#if defined(OsApplication0_START_SEC_CONST_8)

#undef OsApplication0_START_SEC_CONST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type ".sapp_c8" ".sapp_c8"

#elif defined(OSDIABPPC)

#pragma section CONST ".sapp_c8" ".sapp_c8"

#elif defined(OSGHSPPC)

#pragma ghs section const=".sapp_c8"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_8)

#undef OsApplication0_STOP_SEC_CONST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type

#elif defined(OSDIABPPC)

#pragma section CONST

#elif defined(OSGHSPPC)

#pragma ghs section const=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_16)

#undef OsApplication0_START_SEC_CONST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type ".sapp_c16" ".sapp_c16"

#elif defined(OSDIABPPC)

#pragma section CONST ".sapp_c16" ".sapp_c16"

#elif defined(OSGHSPPC)

#pragma ghs section const=".sapp_c16"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_16)

#undef OsApplication0_STOP_SEC_CONST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type

#elif defined(OSDIABPPC)

#pragma section CONST

#elif defined(OSGHSPPC)

#pragma ghs section const=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_32)

#undef OsApplication0_START_SEC_CONST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type ".sapp_c32" ".sapp_c32"

#elif defined(OSDIABPPC)

#pragma section CONST ".sapp_c32" ".sapp_c32"

#elif defined(OSGHSPPC)

#pragma ghs section const=".sapp_c32"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_32)

#undef OsApplication0_STOP_SEC_CONST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type

#elif defined(OSDIABPPC)

#pragma section CONST

#elif defined(OSGHSPPC)

#pragma ghs section const=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_UNSPECIFIED)

#undef OsApplication0_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type ".sapp_cU" ".sapp_cU"

#elif defined(OSDIABPPC)

#pragma section CONST ".sapp_cU" ".sapp_cU"

#elif defined(OSGHSPPC)

#pragma ghs section const=".sapp_cU"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_UNSPECIFIED)

#undef OsApplication0_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section const_type

#elif defined(OSDIABPPC)

#pragma section CONST

#elif defined(OSGHSPPC)

#pragma ghs section const=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- var DATA (in RAM or paged RAM) ---  */

#elif defined(OsApplication0_START_SEC_VAR_8)

#undef OsApplication0_START_SEC_VAR_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type ".app0_v8" ".app0_v8"

#elif defined(OSDIABPPC)

#pragma section DATA ".app0_v8" ".app0_v8"

#elif defined(OSGHSPPC)

#pragma ghs section data=".app0_v8_data"
#pragma ghs section bss=".app0_v8_bss"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_8)

#undef OsApplication0_STOP_SEC_VAR_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type

#elif defined(OSDIABPPC)

#pragma section DATA

#elif defined(OSGHSPPC)

#pragma ghs section bss=default
#pragma ghs section data=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_16)

#undef OsApplication0_START_SEC_VAR_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type ".app0_v16" ".app0_v16"

#elif defined(OSDIABPPC)

#pragma section DATA ".app0_v16" ".app0_v16"

#elif defined(OSGHSPPC)

#pragma ghs section data=".app0_v16_data"
#pragma ghs section bss=".app0_v16_bss"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_16)

#undef OsApplication0_STOP_SEC_VAR_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type

#elif defined(OSDIABPPC)

#pragma section DATA

#elif defined(OSGHSPPC)

#pragma ghs section bss=default
#pragma ghs section data=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_32)

#undef OsApplication0_START_SEC_VAR_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type ".app0_v32" ".app0_v32"

#elif defined(OSDIABPPC)

#pragma section DATA ".app0_v32" ".app0_v32"

#elif defined(OSGHSPPC)

#pragma ghs section data=".app0_v32_data"
#pragma ghs section bss=".app0_v32_bss"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_32)

#undef OsApplication0_STOP_SEC_VAR_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type

#elif defined(OSDIABPPC)

#pragma section DATA

#elif defined(OSGHSPPC)

#pragma ghs section bss=default
#pragma ghs section data=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_UNSPECIFIED)

#undef OsApplication0_START_SEC_VAR_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type ".app0_vU" ".app0_vU"

#elif defined(OSDIABPPC)

#pragma section DATA ".app0_vU" ".app0_vU"

#elif defined(OSGHSPPC)

#pragma ghs section data=".app0_vU_data"
#pragma ghs section bss=".app0_vU_bss"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_UNSPECIFIED)

#undef OsApplication0_STOP_SEC_VAR_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section data_type

#elif defined(OSDIABPPC)

#pragma section DATA

#elif defined(OSGHSPPC)

#pragma ghs section bss=default
#pragma ghs section data=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- FAST DATA (in direct page)  ---  */

#elif defined(OsApplication0_START_SEC_VAR_FAST_8)

#undef OsApplication0_START_SEC_VAR_FAST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type ".sapp_v8_data" ".sapp_v8_bss"

#elif defined(OSDIABPPC)

#pragma section SDATA ".sapp_v8_data" ".sapp_v8_bss"

#elif defined(OSGHSPPC)

#pragma ghs section sdata=".sapp_v8_data"
#pragma ghs section sbss=".sapp_v8_bss"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_FAST_8)

#undef OsApplication0_STOP_SEC_VAR_FAST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type

#elif defined(OSDIABPPC)

#pragma section SDATA

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sbss=default
#pragma ghs section sdata=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_FAST_16)

#undef OsApplication0_START_SEC_VAR_FAST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type ".sapp_v16_data" ".sapp_v16_bss"

#elif defined(OSDIABPPC)

#pragma section SDATA ".sapp_v16_data" ".sapp_v16_bss"

#elif defined(OSGHSPPC)

#pragma ghs section sdata=".sapp_v16_data"
#pragma ghs section sbss=".sapp_v16_bss"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_FAST_16)

#undef OsApplication0_STOP_SEC_VAR_FAST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type

#elif defined(OSDIABPPC)

#pragma section SDATA

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sbss=default
#pragma ghs section sdata=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_FAST_32)

#undef OsApplication0_START_SEC_VAR_FAST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type ".sapp_v32_data" ".sapp_v32_bss"

#elif defined(OSDIABPPC)

#pragma section SDATA ".sapp_v32_data" ".sapp_v32_bss"

#elif defined(OSGHSPPC)

#pragma ghs section sdata=".sapp_v32_data"
#pragma ghs section sbss=".sapp_v32_bss"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_FAST_32)

#undef OsApplication0_STOP_SEC_VAR_FAST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type

#elif defined(OSDIABPPC)

#pragma section SDATA

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sbss=default
#pragma ghs section sdata=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_VAR_FAST_UNSPECIFIED)

#undef OsApplication0_START_SEC_VAR_FAST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type ".sapp_vU_data" ".sapp_vU_bss"

#elif defined(OSDIABPPC)

#pragma section SDATA ".sapp_vU_data" ".sapp_vU_bss"

#elif defined(OSGHSPPC)

#pragma ghs section sdata=".sapp_vU_data"
#pragma ghs section sbss=".sapp_vU_bss"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_VAR_FAST_UNSPECIFIED)

#undef OsApplication0_STOP_SEC_VAR_FAST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sdata_type

#elif defined(OSDIABPPC)

#pragma section SDATA

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sbss=default
#pragma ghs section sdata=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- FAST CONST DATA (in RAM or paged RAM) ---  */

#elif defined(OsApplication0_START_SEC_CONST_FAST_8)

#undef OsApplication0_START_SEC_CONST_FAST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type ".sapp_fc8" ".sapp_fc8"

#elif defined(OSDIABPPC)

#pragma section SCONST ".sapp_fc8" ".sapp_fc8"

#elif defined(OSGHSPPC)

#pragma ghs section sdata2=".sapp_fc8"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_FAST_8)

#undef OsApplication0_STOP_SEC_CONST_FAST_8
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type

#elif defined(OSDIABPPC)

#pragma section SCONST

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sdata2=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_FAST_16)

#undef OsApplication0_START_SEC_CONST_FAST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type ".sapp_fc16" ".sapp_fc16"

#elif defined(OSDIABPPC)

#pragma section SCONST ".sapp_fc16" ".sapp_fc16"

#elif defined(OSGHSPPC)

#pragma ghs section sdata2=".sapp_fc16"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_FAST_16)

#undef OsApplication0_STOP_SEC_CONST_FAST_16
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type

#elif defined(OSDIABPPC)

#pragma section SCONST

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sdata2=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_FAST_32)

#undef OsApplication0_START_SEC_CONST_FAST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type ".sapp_fc32" ".sapp_fc32"

#elif defined(OSDIABPPC)

#pragma section SCONST ".sapp_fc32" ".sapp_fc32"

#elif defined(OSGHSPPC)

#pragma ghs section sdata2=".sapp_fc32"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_FAST_32)

#undef OsApplication0_STOP_SEC_CONST_FAST_32
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type

#elif defined(OSDIABPPC)

#pragma section SCONST

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sdata2=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_START_SEC_CONST_FAST_UNSPECIFIED)

#undef OsApplication0_START_SEC_CONST_FAST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type ".sapp_fcU" ".sapp_fcU"

#elif defined(OSDIABPPC)

#pragma section SCONST ".sapp_fcU" ".sapp_fcU"

#elif defined(OSGHSPPC)

#pragma ghs section sdata2=".sapp_fcU"
#pragma ghs startsda

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OsApplication0_STOP_SEC_CONST_FAST_UNSPECIFIED)

#undef OsApplication0_STOP_SEC_CONST_FAST_UNSPECIFIED
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section sconst_type

#elif defined(OSDIABPPC)

#pragma section SCONST

#elif defined(OSGHSPPC)

#pragma ghs endsda
#pragma ghs section sdata2=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- HOOKS CODE ---  */

#elif defined(OSHOOK_START_SEC_CODE)

#undef OSHOOK_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type ".oshook"

#elif defined(OSDIABPPC)

#pragma section CODE ".oshook"

#elif defined(OSGHSPPC)

#pragma ghs section text=".oshook"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OSHOOK_STOP_SEC_CODE)

#undef OSHOOK_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type 

#elif defined(OSDIABPPC)

#pragma section CODE 

#elif defined(OSGHSPPC)

#pragma ghs section text=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- APP CODE ---  */

#elif defined(APP_START_SEC_CODE)

#undef APP_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type ".appcode"

#elif defined(OSDIABPPC)

#pragma section CODE ".appcode"

#elif defined(OSGHSPPC)

#pragma ghs section text=".appcode"

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(APP_STOP_SEC_CODE)

#undef APP_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type 

#elif defined(OSDIABPPC)

#pragma section CODE 

#elif defined(OSGHSPPC)

#pragma ghs section text=default

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- OSVECTORS CODE ---  */

#elif defined(OSVECTORS_START_SEC_CODE)

#undef OSVECTORS_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type ".vects"

#elif defined(OSDIABPPC)

#pragma section CODE ".vects"

#elif defined(OSGHSPPC)

OSASM("    .section  \".vects\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OSVECTORS_STOP_SEC_CODE)

#undef OSVECTORS_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type

#elif defined(OSDIABPPC)

#pragma section CODE

#elif defined(OSGHSPPC)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- OSVECTORS CODE second core ---  */

#elif defined(OSVECTORS2_START_SEC_CODE)

#undef OSVECTORS2_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type ".vects2"

#elif defined(OSDIABPPC)

#pragma section CODE ".vects2"

#elif defined(OSGHSPPC)

OSASM("    .section  \".vects2\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OSVECTORS2_STOP_SEC_CODE)

#undef OSVECTORS2_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type

#elif defined(OSDIABPPC)

#pragma section CODE

#elif defined(OSGHSPPC)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

/*  --- STARTUP CODE second core ---  */

#elif defined(OSSTARTUP2_START_SEC_CODE)

#undef OSSTARTUP2_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type ".startup2"

#elif defined(OSDIABPPC)

#pragma section CODE ".startup2"

#elif defined(OSGHSPPC)

OSASM("    .section  \".startup2\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

#elif defined(OSSTARTUP2_STOP_SEC_CODE)

#undef OSSTARTUP2_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSCWPPC)

#pragma section code_type

#elif defined(OSDIABPPC)

#pragma section CODE

#elif defined(OSGHSPPC)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#else

#error Unknown compiler
#endif /* OSCWPPC */

#endif /* OsApplication0_START_SEC_CONST_8 */

