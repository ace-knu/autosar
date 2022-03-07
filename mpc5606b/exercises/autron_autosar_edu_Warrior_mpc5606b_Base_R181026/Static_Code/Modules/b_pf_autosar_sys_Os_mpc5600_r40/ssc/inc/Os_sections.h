/**
*   @file    Os_sections.h
*   @version 4.0.69
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Power Architecture
*   Peripheral           : e200z0/e200z0h
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.69
*   Build Version        : MPC5600V4_OS_4.0.69_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif


#if !defined(OSCWPPC) && !defined(OSDIABPPC) && !defined(OSGHSPPC)

#error Unknown compiler

#endif

#define OSMEMMAP_ERROR


/*
 * OSCODE
 */

#if defined(OSTEXT_START_SEC_CODE)
#undef OSTEXT_START_SEC_CODE
#undef OSMEMMAP_ERROR



#if defined(OSCWPPC)
#pragma section code_type ".ostext"
#endif
#if defined(OSDIABPPC)
#pragma section CODE ".ostext"
#endif
#if defined(OSGHSPPC)
#pragma ghs section text=".ostext"
#endif

#elif defined(OSTEXT_STOP_SEC_CODE)
#undef OSTEXT_STOP_SEC_CODE
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section code_type
#endif
#if defined(OSDIABPPC)
#pragma section CODE
#endif
#if defined(OSGHSPPC)
#pragma ghs section text=default
#endif


/*
* VAR sections
*/
#elif defined(OS_START_SEC_VAR_UNSPECIFIED)
#undef OS_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section data_type ".osdata" ".osbss"
#pragma section sdata_type ".ossdata" ".ossbss"
#endif
#if defined(OSDIABPPC)
#pragma section DATA ".osdata" ".osbss"
#pragma section SDATA ".ossdata" ".ossbss"
#endif
#if defined(OSGHSPPC)
#pragma ghs section bss=".osbss"
#pragma ghs startdata
#endif


#elif defined(OS_STOP_SEC_VAR_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section sdata_type
#pragma section data_type
#endif
#if defined(OSDIABPPC)
#pragma section SDATA
#pragma section DATA
#endif
#if defined(OSGHSPPC)
#pragma ghs enddata
#pragma ghs section bss=default
#endif



/*
* VAR FAST sections
*/
#elif defined(OS_START_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_START_SEC_VAR_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section sdata_type ".ossdata" ".ossbss"
#endif

#if defined(OSDIABPPC)
#pragma section SDATA ".ossdata" ".ossbss"
#endif

#if defined(OSGHSPPC)
#pragma ghs section sbss=".ossbss"
#pragma ghs startsda
#endif


#elif defined(OS_STOP_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section sdata_type
#endif

#if defined(OSDIABPPC)
#pragma section SDATA
#endif

#if defined(OSGHSPPC)
#pragma ghs endsda
#pragma ghs section sbss=default
#endif


/*
* NON CACHEABLE VAR sections
*/

#elif defined(OS_NONCACHEABLE_START_SEC_VAR_UNSPECIFIED)
#undef OS_NONCACHEABLE_START_SEC_VAR_UNSPECIFIED


#elif defined(OS_NONCACHEABLE_STOP_SEC_VAR_UNSPECIFIED)
#undef OS_NONCACHEABLE_STOP_SEC_VAR_UNSPECIFIED


/*
* STACK sections
*/
#elif defined(OSSTACK_START_SEC_VAR_UNSPECIFIED)
#undef OSSTACK_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section data_type ".osstack" ".osstack"
#endif
#if defined(OSDIABPPC)
#pragma section DATA ".osstack" ".osstack"
#endif
#if defined(OSGHSPPC)
#if __ghs_sda_threshold >= 32767   /* -sda=all is used */
#pragma ghs startdata
#else
#pragma ghs section bss=".osstack"
#endif
#endif

#elif defined(OSSTACK_STOP_SEC_VAR_UNSPECIFIED)
#undef OSSTACK_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section data_type
#endif
#if defined(OSDIABPPC)
#pragma section DATA
#endif
#if defined(OSGHSPPC)
#if __ghs_sda_threshold >= 32767   /* -sda=all is used */
#pragma ghs enddata
#else
#pragma ghs section bss=default
#endif
#endif



/*
* STACK second core
*/

#elif defined(OSSTACK2_START_SEC_VAR_UNSPECIFIED)
#undef OSSTACK2_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section data_type ".osstack2" ".osstack2"
#endif
#if defined(OSDIABPPC)
#pragma section DATA ".osstack2" ".osstack2"
#endif
#if defined(OSGHSPPC)
#if __ghs_sda_threshold >= 32767   /* -sda=all is used */
#pragma ghs startdata
#else
#pragma ghs section bss=".osstack2"
#endif
#endif

#elif defined(OSSTACK2_STOP_SEC_VAR_UNSPECIFIED)
#undef OSSTACK2_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section data_type
#endif
#if defined(OSDIABPPC)
#pragma section DATA
#endif
#if defined(OSGHSPPC)
#if __ghs_sda_threshold >= 32767   /* -sda=all is used */
#pragma ghs enddata
#else
#pragma ghs section bss=default
#endif
#endif




/*
* CONST sections
*/
#elif defined(OS_START_SEC_CONST_UNSPECIFIED)
#undef OS_START_SEC_CONST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section const_type ".osrodata" ".osrodata"
#endif
#if defined(OSDIABPPC)
#pragma section CONST ".osrodata" ".osrodata"
#pragma option -Xsmall-const=0
#endif
#if defined(OSGHSPPC)
#pragma ghs section rodata=".osrodata"
#pragma ghs startdata
#endif

#elif defined(OS_STOP_SEC_CONST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section const_type
#endif

#if defined(OSDIABPPC)
#if !defined(OSMEMPROTECTION)
/* restore small data threshold */
#pragma option -Xsmall-const=8
#endif
#pragma section CONST
#endif

#if defined(OSGHSPPC)
#pragma ghs enddata
#pragma ghs section rodata=default
#endif



/*
* CONST FAST - now UNUSED
*/

#elif defined(OS_START_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_START_SEC_CONST_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section sconst_type ".ossrodata" ".ossrodata"
/* Note: it is necessary also use __declspec(section ".ossrodata") before each const declaration */
#endif

#if defined(OSDIABPPC)
#endif

#if defined(OSGHSPPC)
#pragma ghs section rodata=".ossrodata"
#endif

#elif defined(OS_STOP_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSCWPPC)
#pragma section sconst_type
#endif

#if defined(OSDIABPPC)
#endif

#if defined(OSGHSPPC)
#pragma ghs section rodata=default
#endif

#endif


#if defined(OSMEMMAP_ERROR)
#error "Os_sections.h: OSMEMMAP_ERROR is defined"
#endif


#ifdef __cplusplus
}
#endif



/** @} */
