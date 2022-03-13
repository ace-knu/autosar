/**
*   @file    Os_compiler_internal_api.h
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
#ifndef OS_COMPILER_INTERNAL_API_H_
#define OS_COMPILER_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_compiler_api.h>

#if !defined(OSCWPPC)
#if defined(__MWERKS__)
#define OSCWPPC
#endif /* defined(__MWERKS__) */
#endif

#if defined(OSGHSPPC)
#include <ppc_ghs.h>            /* for intrinsic functions only */
#endif


#if defined(OSDIABPPC)
#if !defined(OSDIABPPC_ASM_H)
#define OSDIABPPC_ASM_H
#include <diab/asm.h>           /* for intrinsic functions only */
#endif
#endif


#if !defined(OSCWPPC) && !defined(OSDIABPPC) && !defined(OSGHSPPC)
#error "Compiler is not defined"
#endif

  /* Data section addresses for various compilers */
#if defined(OSCWPPC)
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif

#if defined(OSGHSPPC)
#define OS_BEGIN_DSADDR(DSNAME) __ghsbegin_##DSNAME
#define OS_END_DSADDR(DSNAME)   __ghsend_##DSNAME
#endif

#if defined(OSDIABPPC)
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif


#if defined(OSCWPPC)
      /* turn off the "unsafe register variables" warning using this pragma */
#pragma unsafe_global_reg_vars off
#endif

/* definitions for assembler functions */
#if defined(OSDIABPPC) || defined(OSGHSPPC)
#define OSSTRING(x) #x
#define OSASMF(x) OSASM (" "OSSTRING(x)" ")
#define OSASMF2(x,x1) OSASM (" "OSSTRING(x)","OSSTRING(x1)" ")
#define OSASMF3(x,x1,x2) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)" ")
#define OSASMF4(x,x1,x2,x3) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)","OSSTRING(x3)" ")
#define OSASMF5(x,x1,x2,x3,x4) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)","OSSTRING(x3)","OSSTRING(x4)" ")
#endif /* defined(OSDIABPPC) || defined(OSGHSPPC) */

#if defined(OSCWPPC)
#define OSASMF(x)  x
#define OSASMF2(x,x1)  x,x1
#define OSASMF3(x,x1,x2) x,x1,x2
#define OSASMF4(x,x1,x2,x3) x,x1,x2,x3
#define OSASMF5(x,x1,x2,x3,x4) x,x1,x2,x3,x4
#endif /* defined(OSCWPPC) */

#if defined(OSDIABPPC)
#define OSWARNSUPPRESS
#endif /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
#define OSWARNSUPPRESS  OSASM volatile { .warn_def_reserved_reg off; }
#endif /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
#define OSWARNSUPPRESS
#endif /* defined(OSGHSPPC) */

#if defined(OSDIABPPC) 
#define OSINTERRUPT         __interrupt__
#define OSINTERRUPTNEST     __interrupt__
#endif  /* defined(OSDIABPPC)  */

#if defined(OSGHSPPC)
#define OSINTERRUPT         __interrupt
#define OSINTERRUPTNEST     __interrupt
#endif  /* defined(OSGHSPPC) */

#if defined(OSCWPPC)
#define OSINTERRUPT         __declspec(interrupt)
#define OSINTERRUPTNEST     __declspec(interrupt SRR)
#endif /* defined(OSCWPPC) */

#if !defined(OSMEMPROTECTION)

#if defined(OSGHSPPC)
#pragma ghs startdata           /* To prevent compiler to use short addressing */
#endif /* defined(OSGHSPPC) */

extern OSDWORD OS_MAIN_TOS[];
extern OSDWORD OS_MAIN_BOS[];

#define OSSTACKBOTTOM       OS_MAIN_BOS
#define OSSTACKTOP          OS_MAIN_TOS

#if defined(OSGHSPPC)
#pragma ghs enddata
#endif /* defined(OSGHSPPC) */

#endif /* defined(OSMEMPROTECTION) */



#if defined(OSDIABPPC)
#define OSUSE_FRAME            __attribute__((use_frame_pointer))
#endif

#if defined(OSCWPPC)
#define OSUSE_FRAME
#endif

#if defined(OSGHSPPC)
#define OSUSE_FRAME
#endif



#ifdef __cplusplus
}
#endif


#endif /*OS_COMPILER_INTERNAL_API_H_ */

/** @} */
