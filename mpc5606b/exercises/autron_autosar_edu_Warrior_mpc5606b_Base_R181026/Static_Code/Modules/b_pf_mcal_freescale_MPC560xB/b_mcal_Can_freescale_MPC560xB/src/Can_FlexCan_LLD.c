/**
*   @file    Can_FlexCan_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - LLD module implementation.
*   @details Low Level Driver implementation.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FlexCan_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 12.1, Use of mixed mode arithmetic
* This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed
* to the macro. The care is taken for the parameters sent as inputs to the macro and hence unintended truncation of values
* would not result.
*
* @section FlexCan_LLD_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section FlexCan_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section FlexCan_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section FlexCan_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
* A source of error in writing dynamic code is that the stack segment may be different from the data segment.
*
* @section FlexCan_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section FlexCan_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section FlexCan_LLD_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section FlexCan_LLD_c_REF_11
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: a) it is not a
* conversion to a wider integer type of the same signedness, or b)
* the expression is complex, or c) the expression is not constant
* and is a function argument, or d) the expression is not constant
* and is a return expression
*
* @section FlexCan_LLD_c_REF_12
* Violates MISRA 2004 Required Rule 10.3 , The value of a complex expression of integer type may only be cast
* to a type that is narrower and of the same signedness as the underlying type of the expression
* This violation is due to the value of a complex expression of integer type was cast to a type that is
* not narrower.
*
* @section FlexCan_LLD_c_REF_13
* Violates MISRA 2004 Required Rule 10.5 , If the bitwise operators ~ and << are applied to an operand
* of underlying type unsigned char or unsigned shot, the result shall be immediately cast to the underlying type
* of the operand
* This violation is due to the operator << was used.
*
* @section FlexCan_LLD_c_REF_14
* Violates MISRA 2004 Required Rule 12.4, The right hand operand of a logical && or || operator shall not
* contain side effects.
*
* @section FlexCan_LLD_c_REF_15
* Violates MISRA 2004 Required Rule 14.3, Before preprocessing, a null statement shall only occur on a line
* by itself, it may be followed by a comment provided that the first character following the null statement
* is a white-space character.
*
* @section FlexCan_LLD_c_REF_16
* Violates MISRA 2004 Required Rule 14.8, The statement forming the body of a switch, while, do...while or for
* statement shall be a compound statement.
*
* @section FlexCan_LLD_c_REF_17
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*
* @section FlexCan_LLD_c_REF_18
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be
* permitted.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_LLD.h"
#include "CanIf_Cbk.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/*
* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Cer.h"
#include "SchM_Can.h"
#include "Mcal.h"

#if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Can_FlexCan_LLD.c
* @implements     DCAN02423
*/
#define CAN_VENDOR_ID_FLEXCAN_C                    43
#define CAN_MODULE_ID_FLEXCAN_C                    80
/*
* @violates @ref FlexCan_LLD_c_REF_7 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_C     4
/*
* @violates @ref FlexCan_LLD_c_REF_7 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_C     0
/*
* @violates @ref FlexCan_LLD_c_REF_7 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_FLEXCAN_C  3
#define CAN_SW_MAJOR_VERSION_FLEXCAN_C             1
#define CAN_SW_MINOR_VERSION_FLEXCAN_C             0
#define CAN_SW_PATCH_VERSION_FLEXCAN_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_FLEXCAN_C != CAN_VENDOR_ID_FLEXCAN_H)
    #error "Can_FlexCan_LLD.c and Can_FlexCan_LLD.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_C    != CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_C    != CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_FLEXCAN_C != CAN_AR_RELEASE_REVISION_VERSION_FLEXCAN_H))
    #error "AutoSar Version Numbers of Can_FlexCan_LLD.c and Can_FlexCan_LLD.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_FLEXCAN_C != CAN_SW_MAJOR_VERSION_FLEXCAN_H) || \
     (CAN_SW_MINOR_VERSION_FLEXCAN_C != CAN_SW_MINOR_VERSION_FLEXCAN_H) || \
     (CAN_SW_PATCH_VERSION_FLEXCAN_C != CAN_SW_PATCH_VERSION_FLEXCAN_H))
    #error "Software Version Numbers of Can_FlexCan_LLD.c and Can_FlexCan_LLD.h are different"
#endif


/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_FlexCan_LLD.c and Det.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    /* Check if current file and Dem header file are of the same version */
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_FlexCan_LLD.c and Dem.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief          Array holding current status/run-time configuration of individual FlexCAN controllers
* @details        Array holding current status/run-time configuration of individual FlexCAN controllers
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for id, INT nesting level,
*                 Index of MB buffer being cancelled, Index of the first MB used for Tx , Controller Options.
*
* @implements     DCAN02806
*
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatuses[CAN_MAXCTRL_CONFIGURED];

/**
* @brief          Array holding current MCR Register status
* @details        Array holding current MCR Register status. If the Can_SetControllerMode returns with CAN_NOT_OK,
*                 then the MCR Register is saved and the Can_MainFunction_Mode must be called to see a state change
*                 of the controller
*
* @implements     DCAN02810
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint32, CAN_VAR) Can_MCR_Configuration[CAN_MAXCTRL_SUPPORTED];


/* Global Variable to store status of controller*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint8, CAN_VAR)  MB_Busy = 0U;

#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/* Global Variable to store status of tx cancel confirmation */
VAR(uint32, CAN_VAR)   Can_TxCancelStatus[CAN_MAXCTRL_SUPPORTED][2];
#else
/*for 32 message buffer*/
VAR(uint32, CAN_VAR)   Can_TxCancelStatus[CAN_MAXCTRL_SUPPORTED][1];
#endif
#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_NO_INIT_32

/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
#if (CAN_API_ERROR_STATUS == STD_ON)
/*
* @brief   Array holding  status of ESR register of FlexCAN controllers
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(uint32, CAN_VAR)  Can_EsrRegStatus[ CAN_MAXCTRL_SUPPORTED ];
#endif
#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
/* Unique identifier of a PDU within a software module */
VAR(PduIdType, CAN_VAR) Can_PduIdBuff[CAN_MAXCTRL_SUPPORTED][CAN_MAXMB_CONFIGURED];

/* Store the basic information about a PDU */
VAR(PduInfoType, CAN_VAR) Can_PduInfoBuff[CAN_MAXCTRL_SUPPORTED][CAN_MAXMB_CONFIGURED];
#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_NO_INIT_32

/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/**
* @brief          CAN base address array
* @details        CAN base address array
*
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(uint32, CAN_CONST) FLEXCAN_BASE_ADDRS[] = {
#ifdef  FLEXCAN0_BASEADDR
        FLEXCAN0_BASEADDR,
#endif /* FLEXCAN0_BASEADDR */
#ifdef  FLEXCAN1_BASEADDR
        FLEXCAN1_BASEADDR,
#endif /* FLEXCAN1_BASEADDR */
#ifdef  FLEXCAN2_BASEADDR
        FLEXCAN2_BASEADDR,
#endif /* FLEXCAN2_BASEADDR */
#ifdef  FLEXCAN3_BASEADDR
        FLEXCAN3_BASEADDR,
#endif /* FLEXCAN3_BASEADDR */
#ifdef  FLEXCAN4_BASEADDR
        FLEXCAN4_BASEADDR,
#endif /* FLEXCAN4_BASEADDR */
#ifdef  FLEXCAN5_BASEADDR
        FLEXCAN5_BASEADDR, 
#endif /* FLEXCAN5_BASEADDR */
#ifdef  FLEXCAN6_BASEADDR
        FLEXCAN6_BASEADDR,
#endif /* FLEXCAN6_BASEADDR */
#ifdef  FLEXCAN7_BASEADDR
        FLEXCAN7_BASEADDR
#endif /* FLEXCAN7_BASEADDR */
    };
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

static VAR(uint8, CAN_VAR) Can_message_states[] = {
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 0 RESETMODULE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 1 WAITFORBUSIDLE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          1,  /* 2, bit1 BUSIDLE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 3 TXSTARTOFFRAME */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 4 TXIDENTIFIER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 5 TXSRTRBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 6 TXIDEBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 7 TXIDEBITR */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 8 TXIDEBITE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 9 TXEXIDENTIFIER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 10 TXRTRBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 11 TXRESERVEDBITS */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 12 TXRESERVEDBITSEX */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 13 TXDATALENGTHCODE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 14 TXDATAFIELD */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 15 TXCRCSEQUENCE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 16 TXCRCDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 17 TXACKSLOT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 18 TXACKDELIMITER  */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 19 TXENDOFFRAME */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          1,  /* 20, bit1 TXINTERMISSION */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 21 TXSUSPENDTRANSMISSION */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 22 TXACTIVEERRORFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 23 TXACTIVEERRORFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          7,  /* 24, bit7 TXERRORDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 25 TXPASSIVEERRORFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 26 TXPASSIVEERRORFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 27 TXOVERLOADFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 28 TXOVERLOADFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          7,  /* 29, bit7 TXOVERLOADDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 30 LOSTARBITRATION */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 31 LOSTARBINSRTRBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 32 LOSTARBINIDEBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 33 LOSTARBINIDEBITSTUFFR */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 34 LOSTARBINIDEBITSTUFFE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 35 LOSTEARBITRATION */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 36 LOSTARBINRTRBIT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 37 RXRESERVEDBITS */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 38 RXRESERVEDBITSEX */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 39 RXDATALENGTHCODE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 40 RXDATAFIELD */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 41 RXCRCSEQUENCEFIRST */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 42 RXCRCSEQUENCE */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 43 RXCRCDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 44 RXACKSLOT */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 45 RXACKDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          7,  /* 46, bit7 RXENDOFFRAME */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          1,  /* 47, bit1 RXINTERMISSION */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 48 RXACTIVEERRORFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 49 RXACTIVEERRORFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 50 RXACTIVEERRORFLAGW2 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          7,  /* 51, bit7 RXERRORDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 52 RXPASSIVEERRORFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 53 RXPASSIVEERRORFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 54 RXPASSIVEERRORFLAGW2 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 55 RXOVERLOADFLAG */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          0,  /* 56 RXOVERLOADFLAGW1 */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          7,  /* 57, bit7 RXOVERLOADDELIMITER */
          /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
          1,  /* 58 BUSOFF1 */
        };

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#define CAN_START_SEC_RAMCODE
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static FUNC (uint8, CAN_CODE) Can_LLD_ForbiddenRegion_Ram( VAR(uint8, AUTOMATIC) can_hw_offset, VAR(uint8, AUTOMATIC) can_mb_index, VAR(uint32, AUTOMATIC) can_mb_content[4]);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*
The parameter "can_mb_content" is used for returning the 4 words of a MB. It's structure is:
    can_mb_content[0] -> Code & Length
    can_mb_content[1] -> ID
    can_mb_content[2] -> byte 0,byte 1, byte 2, byte 3
    can_mb_content[3] -> byte 4,byte 5, byte 6, byte 7
Also, this function will return if the region we are in this moment, is a safe region
*/
static FUNC (uint8, CAN_CODE) Can_LLD_ForbiddenRegion_Ram( VAR(uint8, AUTOMATIC) can_hw_offset, VAR(uint8, AUTOMATIC) can_mb_index, VAR(uint32, AUTOMATIC) can_mb_content[4])
{
    /* Variable for region in Can Frame */
    VAR(uint8, AUTOMATIC)  Can_state = 0U;
    VAR(uint8, AUTOMATIC)  Can_result   = 0U;
    VAR(uint8, AUTOMATIC)  Can_rezult = 1U;
    MB_Busy = 0U;
    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
    Can_state = (FLEXCAN_DBG1_READ(can_hw_offset) & FLEXCAN_DBG1_CFSM);
    Can_result = Can_message_states[Can_state];

    if (0U == Can_result)
    {
        /* The reading must be done verry fast. Thats why we store it in local buffers, and after we will use them. */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        can_mb_content[0] = FLEXCAN_MB_READ(can_hw_offset, can_mb_index);
        if(FLEXCAN_MBCS_CODERXBUSY != (Can_MB_Code_Length & FLEXCAN_MBCS_CODE))
        {
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[1] = FLEXCAN_MB_READ_ID_EXTENDED(can_hw_offset, can_mb_index);
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[2] = FLEXCAN_MB_READ_DATA_LOW(can_hw_offset, can_mb_index);
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[3] = FLEXCAN_MB_READ_DATA_HIGH(can_hw_offset, can_mb_index);
            MB_Busy = 1U;
        }
        Can_rezult = 0U;
    }
    else if (1U == Can_result)
    {
        /* Intermission or BusOff */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref FlexCan_LLD_c_REF_15 Violates MISRA 2004 Required Rule 14.3, a null statement shall only occur on a line by itself */
        /* @violates @ref FlexCan_LLD_c_REF_16 Violates MISRA 2004 Required Rule 14.8, The statement forming the body of a switch, while, do...while or for statement shall be a compound statement. */
        while(FLEXCAN_DBG2_READ(can_hw_offset) & FLEXCAN_DBG2_APP);
        ASM_KEYWORD("nop"); /* delay(Tmv);  64 ns */
        /* The reading must be done verry fast. Thats why we store it in local buffers, and after we will use them. */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        can_mb_content[0] = FLEXCAN_MB_READ(can_hw_offset, can_mb_index);
        if(FLEXCAN_MBCS_CODERXBUSY != (Can_MB_Code_Length & FLEXCAN_MBCS_CODE))
        {
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[1] = FLEXCAN_MB_READ_ID_EXTENDED(can_hw_offset, can_mb_index);
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[2] = FLEXCAN_MB_READ_DATA_LOW(can_hw_offset, can_mb_index);
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_content[3] = FLEXCAN_MB_READ_DATA_HIGH(can_hw_offset, can_mb_index);
            MB_Busy = 1U;
        }
        Can_rezult = 0U;
    }
    else
    {
      /* Region the precedes Intermission, just wait quit it*/
    }
    return Can_rezult;
}

#define CAN_STOP_SEC_RAMCODE
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
P2FUNC (uint8, const, Can_LLD_ForbiddenRegion)( VAR(uint8, AUTOMATIC) can_hw_offset, VAR(uint8, AUTOMATIC) can_mb_index, VAR(uint32, AUTOMATIC) can_mb_content[4]) = &Can_LLD_ForbiddenRegion_Ram;

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif
#endif

#define CAN_START_SEC_CODE
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief          Initialisation of indicator, statuses, etc.
* @details        Initialisation of indicator, statuses, etc.
*                 This routine is called by:
*                 - Can_Init() from Can.c file.
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set variables into a definite state.
*
* @implements     DCAN02807
*
*/
FUNC (void, CAN_CODE) Can_LLD_InitVariables( void )
    {

        /* Index CAN controllers from configuration. */
        VAR(uint8, AUTOMATIC) can_ctrl_index = 0U;
        VAR(uint8, AUTOMATIC) can_mb_index = 0U;

        /* Init all global varibales/statuses for all controllers. */
        for ( can_ctrl_index = 0U; can_ctrl_index < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_ctrl_index++)
        {
            /* Init INT Disable nesting indicator. It is incremented after every call of Can_DisableControllerInterrupts().
               The function Can_EnableControllerInterrupts() shall perform no action when Can_DisableControllerInterrupts() has not been called before. */
            Can_ControllerStatuses[can_ctrl_index].IntDisableLevel = (sint8)0;

            /* Set interrupt mode status to interrupt disabled mode. */
            Can_ControllerStatuses[can_ctrl_index].ControllerSWFlag = (uint8)0U;

            /* Set to null the first Tx MB index for every controller. */
            Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex = (uint8)0U;

            /* Set  interrupt mode status to interrupt disabled mode. */
            Can_ControllerStatuses[can_ctrl_index].InterruptMode = (uint8)CAN_INTERRUPT_ENABLED;

            /* Set the controller state to STOP after power-up */
            Can_ControllerStatuses[can_ctrl_index].ControllerState = CAN_STOPPED;

#if (CAN_API_ERROR_STATUS == STD_ON)
            /* Init the global varibales/statuses for all controllers   */
            Can_EsrRegStatus[can_ctrl_index] = (uint32)0U;
#endif   /*  (CAN_API_ERROR_STATUS == STD_ON)*/

            /* Set the controller current baudrate index as default */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            Can_ControllerStatuses[can_ctrl_index].CurrentBaudRateIndex = (uint8)(Can_ControlerDescriptorsPtr[can_ctrl_index].DefaultBaudRateIndex);

            for (can_mb_index = 0U; can_mb_index < (uint8)CAN_MAXMB_CONFIGURED; can_mb_index++)
            {
                 Can_ControllerStatuses[can_ctrl_index].Can_MBMapping[can_mb_index] = (uint16)0U;
           }
#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/* Global Variable to store status of tx cancel confirmation */
                 Can_TxCancelStatus[can_ctrl_index][0] = (uint32)0x0;
                 Can_TxCancelStatus[can_ctrl_index][1] = (uint32)0x0;
#else
/*for 32 message buffer*/
                 Can_TxCancelStatus[can_ctrl_index][0] = (uint32)0x0;
#endif
#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */                

        }
    }


/*================================================================================================*/
/**
* @brief          Service for initializing the Can driver module according to a configuration set referenced by Config.
* @details        Driver Module Initialization - LLD Driver Module Initialization
*                 This routine is called by:
*                  - Can_Init() from Can.c file.
*
* @param[in]      Controller Can controller to be initialized
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Controller is enabled and set into Stop mode.
*
* @implements     DCAN01072, DCAN01073, DCAN01074, DCAN01027
*
*/
FUNC (void, CAN_CODE) Can_LLD_Init( VAR(uint8, AUTOMATIC) Controller )
    {
        VAR(uint8, AUTOMATIC)  can_hw_offset = 0U;/* Hardware Can controller offset. */
        /* Time-out counter local variable */
        VAR(uint32, AUTOMATIC) can_timeout_cnt = 0U;
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
        VAR(uint32, AUTOMATIC)         can_timeout_count = 0U;/* Timeout counter. */
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */
         /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used  */
        /* Get the hardware offset for this controller. */
        can_hw_offset = Can_ControlerDescriptorsPtr[Controller].ControllerOffset;

        /* Enter Freeze mode after enabling, Self-Reception disabled, individual MB filter masks set. */

        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        FLEXCAN_MCR_CONFIG( can_hw_offset, (uint32)(FLEXCAN_MCR_MDIS | FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT | FLEXCAN_MCR_SRXDIS));
        /* load local time-out variable with configured time-out value*/
        can_timeout_cnt = (uint32)CAN_TIMEOUT_DURATION;
        /* After controller disable, wait until low power mode acknowledgement bit to set*/
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        while ( (FLEXCAN_MCR_LPMACK != ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_LPMACK)) &&
                (can_timeout_cnt > (uint32)0x0U) )
        {
            /* MCR[LPM_ACK] still not set -> controller disable is in-progress. */
            can_timeout_cnt--;
        }
        /* Test for Hardware failure. */
        if ( (uint32)0x0U == can_timeout_cnt )
        {
            #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
               if ((uint32)STD_ON == Can_CurrentConfigPtr->Can_E_TimeoutCfg.state)
               {
                  Dem_ReportErrorStatus((Dem_EventIdType) Can_CurrentConfigPtr->Can_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
               }    
            #endif
        }
/*
* @ errata ERR_IPV_FLEXCAN_0008 software errata FlexCAN: Non-Correctable Errors In FlexCAN Access
*        Put Device In Freeze Mode bit not working properly
*/
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        FLEXCAN_CLEAR_MCR_MDIS(can_hw_offset);
        can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        while ( (FLEXCAN_MCR_MDIS == ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_MDIS)) &&
                (can_timeout_count > (uint32)0x0U) )
        {
            can_timeout_count--;
        }
     #else
    #error : the define ERR_IPV_FLEXCAN_0008 must not be STD_OFF
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */
        /*
           (CAN259) The function Can_Init shall set all CAN controllers in the state CANIF_CS_STOPPED.
           (CAN260) The function Can_ChangeBaudrate shall maintain the CAN controller in the state CANIF_CS_STOPPED.
                 The function Can_ChangeBaudrate shall ensure that any settings that will cause the CAN controller to participate in the network are not set.
        */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        FLEXCAN_MCR_CONFIG( can_hw_offset, (uint32)(FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT | FLEXCAN_MCR_SRXDIS));
        /* load local time-out variable with configured time-out value*/
        can_timeout_cnt = (uint32)CAN_TIMEOUT_DURATION;
        /* After freeze, wait until controller freeze acknowledgement bit to set*/
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        while ( (FLEXCAN_MCR_FRZACK != ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_FRZACK)) &&
                (can_timeout_cnt > (uint32)0x0U) )
        {
            /* MCR[FRZ_ACK] still not set -> controller freeze is in-progress. */
            can_timeout_cnt--;
        }
        /* Test for Hardware failure. */
        if ( (uint32)0x0U == can_timeout_cnt )
        {
            /* Report production error */
            #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
               if ((uint32)STD_ON == Can_CurrentConfigPtr->Can_E_TimeoutCfg.state)
               {
                  Dem_ReportErrorStatus((Dem_EventIdType) Can_CurrentConfigPtr->Can_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
               }    
            #endif
        }
    }


/*================================================================================================*/
/**
* @brief          Service for reset the controller.
* @details        Re-initialization must start with a reset (soft).
*                 This routine is called by:
*                  - Can_LLD_ChangeBaudrate() from Can_FlexCan_LLD.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done (CAN_FCA_INDEX / CAN_FCB_INDEX).
*                 This ID depends by the order of the controller's definition in the Tresos 'CanController' list.
*                 If CanController_0 is assigned to CANB then CAN_FCB_INDEX is 0.
*                 These indexes are used for access inside 'Can_ControlerDescriptorType' structure.
*
* @post           Controller is enabled and reset.
*
* @implements     DCAN01076
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Can_ReturnType, CAN_CODE) Can_LLD_ResetController( VAR(uint8, AUTOMATIC) Controller)
    {

        /* Variable for return status. */
        VAR(Can_ReturnType, AUTOMATIC) Out_can_return = CAN_OK;
        /* Timeout counter. */
        VAR(uint32, AUTOMATIC)         can_timeout_count = 0U;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)          can_hw_offset = 0U;
#if defined(ERR_IPV_FLEXCAN_0013)
    #if (ERR_IPV_FLEXCAN_0013 == STD_ON)
        VAR(uint32, AUTOMATIC)         can_busoff_state = 0U;
    #else
        #error : the define ERR_IPV_FLEXCAN_0013 must not be STD_OFF
    #endif
#endif /* ERR_IPV_FLEXCAN_0013 */

        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset =  Can_ControlerDescriptorsPtr[Controller].ControllerOffset;


        /* The re-initialization of controller start with a Soft-Reset. Test if Can is not ready -> can be in any of disable, Doze/Stop/Freeze modes. */
        /* Enable Can module. */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        FLEXCAN_CLEAR_MCR_MDIS( can_hw_offset);
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
            can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            while ( (FLEXCAN_MCR_MDIS == ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_MDIS)) &&
                    (can_timeout_count > (uint32)0x0U) )
            {
                can_timeout_count--;
            }
     #else
    #error : the define ERR_IPV_FLEXCAN_0008 must not be STD_OFF
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */

        /* MCR[FLEXCAN_MCR_LPMACK] not set yet ->to ensure that CAN controller is not in LP mode before giving a SOFT RESET. */
        can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        while ( (FLEXCAN_MCR_LPMACK == ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_LPMACK)) &&
                (can_timeout_count > (uint32)0x0U) )
        {
            can_timeout_count--;
        }

        /* Test for Hardware failure. */
        if ( (uint32)0x0U == can_timeout_count )
        {
            #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
               if ((uint32)STD_ON == Can_CurrentConfigPtr->Can_E_TimeoutCfg.state)
               {
                  Dem_ReportErrorStatus((Dem_EventIdType) Can_CurrentConfigPtr->Can_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
               }    
            #endif
            Out_can_return = CAN_NOT_OK;
        }
        else
        {

#if defined(ERR_IPV_FLEXCAN_0013)
    #if (ERR_IPV_FLEXCAN_0013 == STD_ON)
            /* Disable bus off interrupt in case the Bus Off Interrupt is enabled */
            /* @violates @ref FlexCan_LLD_c_REF_7 Conversion of pointer to function to Non Integer type*/
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_busoff_state = FLEXCAN_CTRL_READ(can_hw_offset) & FLEXCAN_CTRL_BOFFMSK;
            if(can_busoff_state == FLEXCAN_CTRL_BOFFMSK)
            {
                  /* @violates @ref FlexCan_LLD_c_REF_7 Conversion of pointer to function to Non Integer type*/
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_CLEAR_CTRL_BOFFMSK(can_hw_offset);
            }
    #else
        #error : the define ERR_IPV_FLEXCAN_0013 must not be STD_OFF
    #endif
#endif /* ERR_IPV_FLEXCAN_0013 */

            /* Execute Controller Reset. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_SET_MCR_SOFT_RST(can_hw_offset);

            /* Wait the Reset end off. */
            can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            while ( (FLEXCAN_MCR_SOFTRST == ((uint32)(FLEXCAN_MCR_READ(can_hw_offset)) & FLEXCAN_MCR_SOFTRST)) &&
                    (can_timeout_count > (uint32)0x0U) )
            {
                /* MCR[SOFT_RST] still set -> reset in progress. */
                can_timeout_count--;
            }

         if ( (uint32)0x0U == can_timeout_count )
            {
                #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                   if ((uint32)STD_ON == Can_CurrentConfigPtr->Can_E_TimeoutCfg.state)
                   {
                      Dem_ReportErrorStatus((Dem_EventIdType) Can_CurrentConfigPtr->Can_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                   }    
                #endif
                Out_can_return = CAN_NOT_OK;
            }

#if defined(ERR_IPV_FLEXCAN_0013)
    #if (ERR_IPV_FLEXCAN_0013 == STD_ON)
            /* Poll ESR[FLTCONF] bit in the Error and Status Register until this field is equal to 0b00. */
            can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
            /* @violates @ref FlexCan_LLD_c_REF_2 casting to unsigned long to pointer */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            while ( (FLEXCAN_ESR_FLTCONF == ((uint32)FLEXCAN_ESR_READ(can_hw_offset) & FLEXCAN_ESR_FLTCONF)) &&
                    (can_timeout_count > (uint32)0x0U) )
            {
                /* MCR[SOFT_RST] still set -> reset in progress. */
                can_timeout_count--;
            }      
            
            /* Test for Hardware failure. */
         if ( (uint32)0x0U == can_timeout_count )
            {
                #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                   if ((uint32)STD_ON == Can_CurrentConfigPtr->Can_E_TimeoutCfg.state)
                   {
                      Dem_ReportErrorStatus((Dem_EventIdType) Can_CurrentConfigPtr->Can_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                   }    
                #endif
                Out_can_return = CAN_NOT_OK;
            }
            
            /* Clear Bus Off interrupt flag */
            /* @violates @ref FlexCan_LLD_c_REF_7 Conversion of pointer to function to Non Integer type*/
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_SET_ESR_BOFFINT(can_hw_offset);
            
            if(can_busoff_state == FLEXCAN_CTRL_BOFFMSK)
            {
               /* Re-enable bus off interrupt in case the Bus Off Interrupt is enabled */
               /* @violates @ref FlexCan_LLD_c_REF_7 Conversion of pointer to function to Non Integer type*/
               /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
               FLEXCAN_SET_CTRL_BOFFMSK(can_hw_offset);
            }
    #else
        #error : the define ERR_IPV_FLEXCAN_0013 must not be STD_OFF
    #endif
#endif /* ERR_IPV_FLEXCAN_0013 */
        }

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Service for (re)initializing only CAN controller specific settings.
* @details        CAN controller (re-)initialization.
*                 This routine is called by:
*                  - Can_Init() from Can.c file.
*                  - Can_ChangeBaudrate() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            At least one controller must be configured in the Driver structure.
* @post           Set the MBs and interrupts into predefinite state for Can bus communication.
*
* @implements     DCAN02808
*
*/
FUNC (void, CAN_CODE) Can_LLD_ChangeBaudrate( VAR(uint8, AUTOMATIC) Controller)
    {

        /* Local copy of pointer to the controller descriptor. */
        VAR(Can_PtrControlerDescriptorType, AUTOMATIC) can_ptrControlerDescriptor = NULL_PTR;
        /* Pointer to the MB container structure. */
        VAR(Can_PtrMBConfigContainerType, AUTOMATIC)   can_ptrMBConfigContainer = NULL_PTR;
        /* Variable for indexing all the MBs fron hardware unit chain (all controllers). */
        VAR(uint16, AUTOMATIC)            can_mb_global_index = 0U;
        /* Variable for indexing the MBs inside a single controller. */
        VAR(uint8, AUTOMATIC)             can_mb_ctrl_index = 0U;
        /* ID of current MB. */
        VAR(uint32, AUTOMATIC)            can_mb_messageid = 0U;
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
        /* Variable for calculating the interrupt masks of IMASK1 & IMASK2 register s*/
        VAR(uint8, AUTOMATIC) rxglobal_mskupdate = 0U;
        VAR(uint8, AUTOMATIC) Temp14 = 0U;
        VAR(uint8, AUTOMATIC) Temp15 = 0U;
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
#if (CAN_RXFIFO_ENABLE == STD_ON)
        /* Used to access configured table id and filtermask. */
        VAR(uint8, AUTOMATIC)             can_temp_index = 0U;
        /* Used to save the the index pointing to the table id connfiguration. */
        VAR(uint8, AUTOMATIC)             can_rxfifo_tableid_index = 0U;
        /* Used to index the Table ID for RxFifo. */
        VAR(uint8, AUTOMATIC)             can_rxfifo_tableid = 0U;
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)             can_hw_offset = 0U;
        /* Max number of mb */
        VAR(uint8, AUTOMATIC)             can_mb_max = 0U;
        /* Temporary register value. */
        VAR(uint32, AUTOMATIC)            can_mb_config = 0U;
        /* Variable for return status. */
        VAR(Can_ReturnType, AUTOMATIC)    can_reset_return = CAN_OK;
        /* Variable to hold the index of the current baudrate */
        VAR(uint8, AUTOMATIC) Baudrateindex = 0U;
#if (CAN_RXFIFO_ENABLE == STD_ON)
        /*to skip first MB configured if FIFO enabled for configured controller*/
        VAR(uint8, AUTOMATIC)             can_mb_skip = 1U;
#endif
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
        VAR(uint32, AUTOMATIC)         can_timeout_count = 0U;/* Timeout counter. */
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */
        /* Fill the local pointer copy with address of the Controller Descriptor.  */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        can_ptrControlerDescriptor = &(Can_CurrentConfigPtr->ControlerDescriptors[Controller]);
        can_ptrMBConfigContainer   = &(Can_CurrentConfigPtr->MBConfigContainer);


        /* Get the hardware offset for this controller. */
        can_hw_offset = can_ptrControlerDescriptor->ControllerOffset;

        /* Reset Controller. */
        can_reset_return = Can_LLD_ResetController( Controller);

        /* Get the index of the current baudrate */
        Baudrateindex = Can_ControllerStatuses[Controller].CurrentBaudRateIndex;

        if (can_reset_return == CAN_OK)
          {
             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_SET_MCR_MDIS(can_hw_offset);
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
            can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            while ( (FLEXCAN_MCR_MDIS != ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_MDIS)) &&
                    (can_timeout_count > (uint32)0x0U) )
            {
                can_timeout_count--;
            }
     #else
    #error : the define ERR_IPV_FLEXCAN_0008 must not be STD_OFF
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */

            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                FLEXCAN_CTRL_CONFIG( can_hw_offset, (uint32)(can_ptrControlerDescriptor->ControllerBaudrateConfigsPtr[Baudrateindex].ControlRegister & FLEXCAN_CTRL_CLKSRC));
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_CLEAR_MCR_MDIS(can_hw_offset);
                can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                while ( (FLEXCAN_MCR_MDIS == ((uint32)FLEXCAN_MCR_READ(can_hw_offset) & FLEXCAN_MCR_MDIS)) &&
                        (can_timeout_count > (uint32)0x0U) )
                {
                    can_timeout_count--;
                }
     #else
    #error : the define ERR_IPV_FLEXCAN_0008 must not be STD_OFF
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */

                 /* Enable access to module and enter in freeze mode - clearing MCR[MDIS] bit. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_MCR_CONFIG( can_hw_offset, (uint32)(FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT | FLEXCAN_MCR_SRXDIS));
                Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
                  /* Reset software Flags. */
            Can_ControllerStatuses[Controller].ControllerSWFlag = (uint8)0x0U;
/*
* @ errata ERR_IPV_FLEXCAN_0008 software errata FlexCAN: Non-Correctable Errors In FlexCAN Access
*        Put Device In Freeze Mode bit not working properly
*/
#if defined(ERR_IPV_FLEXCAN_0008)
   #if (ERR_IPV_FLEXCAN_0008 == STD_ON)
                  /* Enable that the MECR register is updated */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_SET_CTRL2_ECRWRE( can_hw_offset);
                  /* Enables writes on MECR register */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_CLEAR_MECR_ECRWRDIS( can_hw_offset);
                  /* Keep normal operation */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_CLEAR_MECR_NCEFAFRZ( can_hw_offset);
                  /* Disables writes on MECR register */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_SET_MECR_ECRWRDIS( can_hw_offset);
                  /* Disable update on MECR register */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                  FLEXCAN_CLEAR_CTRL2_ECRWRE( can_hw_offset);
     #else
    #error : the define ERR_IPV_FLEXCAN_0008 must not be STD_OFF
   #endif
#endif /* ERR_IPV_FLEXCAN_0008 */
/*
* @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
*/
#if defined(ERR_IPV_FLEXCAN_0002)
    #if (ERR_IPV_FLEXCAN_0002== STD_ON)
            /* If RFIFO is enabled then the first 8 MB will be used by the FIFO, initialize the
            CancelMBIndex to the value of Max. MB supported to avoid the false TX-MB cancellation */
            if ( CAN_CONTROLLERCONFIG_RXFIFO == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_RXFIFO))
            {
                Can_ControllerStatuses[Controller].CancelMBIndex = CAN_MAXMB_SUPPORTED;
            }
            else /* RFIFO is disabled */
            {
                /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
                Can_ControllerStatuses[Controller].CancelMBIndex = can_ptrMBConfigContainer->MessageBufferConfigCount;
            }
  #else
    #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
  #endif
#elif defined(CAN_USE_MCR_ABORT_ENABLE)
    #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
            /* If RFIFO is enabled then the first 8 MB will be used by the FIFO, initialize the
            CancelMBIndex to the value of Max. MB supported to avoid the false TX-MB cancellation */
            if ( CAN_CONTROLLERCONFIG_RXFIFO == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_RXFIFO))
            {
                Can_ControllerStatuses[Controller].CancelMBIndex = CAN_MAXMB_SUPPORTED;
            }
            else /* RFIFO is disabled */
            {
                /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
                Can_ControllerStatuses[Controller].CancelMBIndex = can_ptrMBConfigContainer->MessageBufferConfigCount;
            }
    #else
        #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
    #endif
#else
            /* Init the Cancelled MB index with a precalculated value - out of range for every controller. */
            Can_ControllerStatuses[Controller].CancelMBIndex = can_ptrMBConfigContainer->MessageBufferConfigCount;
#endif

            /* Clear Tx guard flags. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            /* Check whether Can controller supports 64 message buffers */
            if ( FLEXCAN_MB_64 == can_ptrControlerDescriptor->Can_NumberOfMB)
            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                Can_ControllerStatuses[Controller].TxGuard[1U] = (uint32)0x0UL;
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */
            Can_ControllerStatuses[Controller].TxGuard[0U] = (uint32)0x0UL;

#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
            /* Check if BCC support is enabled in configuration */
            if ( CAN_CONTROLLERCONFIG_BCC_EN != (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BCC_EN) )
            {
                /* Enable individual MB filter masking. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_SET_MCR_BCC(can_hw_offset);
            }
#else /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
                /* Enable individual MB filter masking. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_SET_MCR_BCC(can_hw_offset);

#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */

#if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* FlexCan uses the filtered RX input to detect recessive to dominant edges on the bus. */
            if ( CAN_CONTROLLERCONFIG_WAKEUP_SRC == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WAKEUP_SRC) )
            {
                               FLEXCAN_SET_MCR_WAK_SRC( can_hw_offset);
            }
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

            /* FlexCan uses local priority feature - extend the ID during the arbitration process with PRIO field from MB reg. */
            if ( CAN_CONTROLLERCONFIG_LPRIO_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_LPRIO_EN) )
            {
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_SET_MCR_LPRIOEN( can_hw_offset);
            }

            /* If WRN_EN is set the TWRN_INT and RWRN_INT will be set error counter transition from <96 to >= 96. */
            if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
            {
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_SET_MCR_WRNEN( can_hw_offset);
            }

            /* Set-up Control Register (CTRL - Controller Configuration) - ControllerBaudrateConfigsPtr->ControlRegister is configured by user using Tresos tool. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
            FLEXCAN_CTRL_CONFIG( can_hw_offset, (uint32)(can_ptrControlerDescriptor->ControllerBaudrateConfigsPtr[Baudrateindex].ControlRegister));

            /* Loop Back Mode configuration. Clear also the MCR[SRCXDIS] to allow receiving frames transmitted by itself. */
             /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            if ( FLEXCAN_CTRL_LPB == ((can_ptrControlerDescriptor->ControllerBaudrateConfigsPtr[Baudrateindex].ControlRegister) & FLEXCAN_CTRL_LPB) )
            {
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_CLEAR_MCR_SRXDIS( can_hw_offset);
            }


            /* Stage1: init RxFifo ******************************************************************** */

#if (CAN_RXFIFO_ENABLE == STD_ON)
            /* If RX FIFO is used, then configure the Controller's registers for Rx Fifo. */
            if ( CAN_CONTROLLERCONFIG_RXFIFO == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_RXFIFO) )
            {
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_SET_MCR_FEN( can_hw_offset);

                /* Processing MB must start from index 8 if RxFifo is enabled when configure MBs. */
                can_mb_ctrl_index += FLEXCAN_FIFO_MB_COUNT;
                can_mb_ctrl_index = can_mb_ctrl_index - 1U;
                can_mb_skip = 0U;

                switch (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_IDAM_MASK)
                {
                    case CAN_CONTROLLERCONFIG_IDAM_A:
                        /* One full ID per filter element - clear IDAM bits. */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_IDAM( can_hw_offset, FLEXCAN_MCR_IDAM32);
                        break;

                    case CAN_CONTROLLERCONFIG_IDAM_B:
                        /* Two full standard IDs or two partial 14-bit exteneded IDs per filter element. */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_IDAM( can_hw_offset, FLEXCAN_MCR_IDAM16);
                        break;

                    case CAN_CONTROLLERCONFIG_IDAM_C:
                        /* Four partial 8-bit IDs (standard or extended) per filter element. */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_IDAM( can_hw_offset, FLEXCAN_MCR_IDAM08);
                        break;

                    case CAN_CONTROLLERCONFIG_IDAM_D:
                        /* RX Fifo is enabled, but all frames will be rejected. */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_IDAM( can_hw_offset, FLEXCAN_MCR_IDAM);
                        break;

                    default:
                        /* This case should never occurs. */
                        Cer_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHANGE_BAUDRATE, (uint8)CAN_E_DEFAULT);
                        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                              Cer_ReportError() function implementation */
                        break;
                } /* end switch. */

                /* Save the index pointing to table id configuration. */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                can_rxfifo_tableid_index = (Can_CurrentConfigPtr->ControlerDescriptors[Controller].RxFiFoTableIdConfigIndex);

                /* Init the IDTable and RXIMR registers of RxFifo. */
                for ( can_temp_index = can_rxfifo_tableid_index; can_temp_index < (can_rxfifo_tableid_index + FLEXCAN_FIFO_MB_COUNT); can_temp_index++)
                {
                    /* Calculate the physical address for each table to write the Table ID and FilterMask. */

                    FLEXCAN_RXFIFO_ID_CONFIG( can_hw_offset, can_rxfifo_tableid,
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                     /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            (uint32)(((Can_CurrentConfigPtr->Can_RxFiFoTableIdConfigPtr) + can_temp_index)->TableId) );

    #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                    /* Check if BCC support is enabled in configuration */
                        if ( CAN_CONTROLLERCONFIG_BCC_EN != (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BCC_EN) )
                    {
    #endif
                        FLEXCAN_RXIMR_CONFIG( can_hw_offset, can_rxfifo_tableid,
                                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                            (uint32)((((Can_CurrentConfigPtr->Can_RxFiFoTableIdConfigPtr) + can_temp_index))->TableFilterMask));
    #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                    }
    #endif

                    /* Increment the Table Id index for RxFifo configuration. */
                    can_rxfifo_tableid++;
                }

    #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
        /* Check if BCC support is enabled in configuration */
        if ( CAN_CONTROLLERCONFIG_BCC_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BCC_EN) )
        {
    /*@violates @ref FlexCan_LLD_c_REF_18 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
    if((can_mb_ctrl_index != CAN_MB_14) && (can_mb_ctrl_index != CAN_MB_15) && (rxglobal_mskupdate == 0U))
                                            {
                                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                FLEXCAN_RXGMASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex] << 18U) );
                                                rxglobal_mskupdate++;
                                            }
        }
    #endif /*#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)*/

                /* Configure Interrupt Mask Bits in case handling of RX is implemented by interrupts (not by polling). */
                if ( CAN_CONTROLLERCONFIG_RXPOL_EN != (CAN_CONTROLLERCONFIG_RXPOL_EN & can_ptrControlerDescriptor->Options) )
                {
                    /* Check if Overflow RxFifo interrupt is enabled and set the IMASK bit if yes. */
                    if ( CAN_CONTROLLERCONFIG_OVER_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_OVER_EN) )
                    {
                        Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX] |= FLEXCAN_FIFO_OVERFLOW_INT_MASK;
                    }
                    /* Check if Warning RxFifo interrupt is enabled and set the IMASK bit if yes. */
                    if ( CAN_CONTROLLERCONFIG_WARN_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WARN_EN) )
                    {
                        Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX] |= FLEXCAN_FIFO_WARNING_INT_MASK;
                    }
                    /* If RxFifo is enabled, then frames are implicitly enabled. IDAM bits can filter the messages or can block at all. */
                    Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX] |= FLEXCAN_FIFO_AVAILABLE_INT_MASK;
                }
            }
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

            /* Stage2: Init Rx/Tx MBs ******************************************************************** */

            /* Parse all MBs that are of type RECEIVE from the chain list, but process only the MBs for controller transmitted as parameter in this function. */
            while ( (can_mb_ctrl_index < can_ptrControlerDescriptor->MaxMBCount) &&
                    (can_mb_global_index < can_ptrMBConfigContainer->MessageBufferConfigCount) )
            {
                /* can_mb_global_index variable is incrementing based of existing HOH for MBs. */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                if ( Controller == (((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->ControllerId))
                {
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    if (CAN_RECEIVE == ((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->MBType )
                    {
#if (CAN_RXFIFO_ENABLE == STD_ON)
                        /* Skip the MB configuration if FIFO is enabled and this is the FIRST RX MB configured . */
                        if(can_mb_skip == (uint8)1U)
                        {
#endif
                            /* Get the ID of the current MB. */
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                            can_mb_messageid = (uint32)((can_ptrMBConfigContainer->MessageBufferConfigsPtr+can_mb_global_index)->MessageId);

                            /* Clear variable for every MB. */
                            can_mb_config = (uint32)0U;

#if (CAN_EXTENDEDID == STD_ON)
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                            if ( CAN_STANDARD == (((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdType) )
                            {
#endif /* (CAN_EXTENDEDID == STD_ON) */

#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                                /* Check if BCC support is enabled in configuration */
                                if ( CAN_CONTROLLERCONFIG_BCC_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BCC_EN) )
                                {
#if (CAN_RXFIFO_ENABLE == STD_ON)
                                    /* If RX FIFO is used, then configure the Controller's registers for Rx Fifo. */
                                    if ( CAN_CONTROLLERCONFIG_RXFIFO != (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_RXFIFO) )
                                    {
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                                        if((can_mb_ctrl_index != CAN_MB_14) && (can_mb_ctrl_index != CAN_MB_15) && (rxglobal_mskupdate == 0U))
                                        {
                                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                            FLEXCAN_RXGMASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex] << 18U) );
                                            rxglobal_mskupdate++;
                                        }
                                        else if((can_mb_ctrl_index == CAN_MB_14) && (Temp14 == 0U))
                                        {
                                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                            {  
                                                     /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                     FLEXCAN_RX14MASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex] << 18U) );
                                            }
                                            else 
                                            {
                                                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                    FLEXCAN_RX14MASK_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);
                                            }      
                                            Temp14++;
                                        }
                                        else if((can_mb_ctrl_index == CAN_MB_15) && (Temp15 == 0U))
                                        {
                                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                            {  
                                                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                    FLEXCAN_RX15MASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex] << 18U) );
                                            }
                                            else
                                            {
                                                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                    FLEXCAN_RX15MASK_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);
                                            }
                                            Temp15++;
                                        }
                                        else
                                        {
                                            /* Already the  RX Global MASK register is updated, its used as acceptance mask for all Rx MBs except for 14 and 15 MB's*/
                                        }
#if (CAN_RXFIFO_ENABLE == STD_ON)
                                    }
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                                }
                                else
                                {
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
                                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                    if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                    {
                                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                        /* @violates @ref FlexCan_LLD_c_REF_12 Violates MISRA 2004 Required Rule 10.3, the value of a complex expression was cast to a type that is not narrower */
                                        /* @violates @ref FlexCan_LLD_c_REF_13 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
                                        FLEXCAN_RXIMR_CONFIG( can_hw_offset, can_mb_ctrl_index, (uint32)((uint32)(Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex] << 18U) );
                                    }
                                    else
                                    {
                                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                        /* @violates @ref FlexCan_LLD_c_REF_12 Violates MISRA 2004 Required Rule 10.3, the value of a complex expression was cast to a type that is not narrower */
                                        /* @violates @ref FlexCan_LLD_c_REF_13 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
                                        FLEXCAN_RXIMR_CONFIG( can_hw_offset, can_mb_ctrl_index, FLEXCAN_32BITMASK);
                                    }
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                                }
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */

                                /* Copy the Message ID (serves as acceptance filter for Rx MBs). For Standard type, ID is placed on bits 28:18 on ID Reg of the MB structure. */
                                can_mb_messageid <<= FLEXCAN_STANDARD_ID_SHIFT;
#if (CAN_EXTENDEDID == STD_ON)
                            }
                            else
                            {
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                                /* Check if BCC support is enabled in configuration */
                                if ( CAN_CONTROLLERCONFIG_BCC_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BCC_EN) )
                                {
#if (CAN_RXFIFO_ENABLE == STD_ON)
                                    /* If RX FIFO is used, then configure the Controller's registers for Rx Fifo. */
                                    if ( CAN_CONTROLLERCONFIG_RXFIFO != (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_RXFIFO) )
                                    {
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                                        if((can_mb_ctrl_index != CAN_MB_14) && (can_mb_ctrl_index != CAN_MB_15) && (rxglobal_mskupdate == 0U))
                                        {
                                                 /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                 FLEXCAN_RXGMASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex]) );
                                            rxglobal_mskupdate++;
                                        }
                                        else if((can_mb_ctrl_index == CAN_MB_14) && (Temp14 == 0U))
                                        {
                                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                            {  
                                                 /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                 FLEXCAN_RX14MASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex]) );
                                            }
                                            else 
                                            {
                                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                FLEXCAN_RX14MASK_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);
                                            }
                                            Temp14++;
                                        }
                                        else if((can_mb_ctrl_index == CAN_MB_15) && (Temp15 == 0U))
                                        {
                                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                            if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                            {
                                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                FLEXCAN_RX15MASK_CONFIG(can_hw_offset,(uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex]) );
                                            }
                                            else 
                                            {
                                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                FLEXCAN_RX15MASK_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);
                                            }     
                                            Temp15++;
                                        }
                                        else
                                        {
                                            /* Already the  RX Global MASK register is updated, its used as acceptance mask for all Rx MBs except for 14 and 15 MB's*/
                                        }
#if (CAN_RXFIFO_ENABLE == STD_ON)
                                    }
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                                }
                                else
                                {
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
                                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                    if(CAN_MAXMASKCOUNT !=(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex))
                                    {       
                                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                         /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                        FLEXCAN_RXIMR_CONFIG( can_hw_offset, can_mb_ctrl_index, (uint32)((Can_CurrentConfigPtr->FilterMasksPtr)[((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->IdMaskIndex]) );
                                    }
                                    else
                                    {
                                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                        FLEXCAN_RXIMR_CONFIG( can_hw_offset, can_mb_ctrl_index, FLEXCAN_32BITMASK);
                                    }
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                                }
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */

                                /* Set the IDE bit if the ID type is EXTENDED or MIXED. */
                                can_mb_config = FLEXCAN_MBCS_IDE ;

                                /* For EXTENDED MB type the ID is placed starting from bits 0 ( unlike STANDARD type when is placed starting to bit 18). */
                            }
#endif /* (CAN_EXTENDEDID == STD_ON) */

                            /* Enable the MB as a Rx object. MB is used for Rx & Mark the buffer as empty. */
                            can_mb_config |= FLEXCAN_MBCS_CODERXEMPTY;
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_CS_CONFIG( can_hw_offset, can_mb_ctrl_index, can_mb_config);

                            /* Copy the Message ID (serves as acceptance filter for Rx MBs). */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_ID_CONFIG( can_hw_offset, can_mb_ctrl_index, can_mb_messageid);

                            /* Save the mask bit from IMASK register for this MB used by Can_EnableControllerInterrupts() API. */
                            if ( CAN_CONTROLLERCONFIG_RXPOL_EN != (CAN_CONTROLLERCONFIG_RXPOL_EN & can_ptrControlerDescriptor->Options) )
                            {
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                                if ( can_mb_ctrl_index >= FLEXCAN_MB_32 )
                                {
                                    Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK2_INDEX] |= ((uint32)1U << (can_mb_ctrl_index - FLEXCAN_MB_32));
                                }
                                else
                                {
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                                    Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX] |= ((uint32)1U << can_mb_ctrl_index);
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                                }
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                            }
#if (CAN_RXFIFO_ENABLE == STD_ON)
                        }
                        else
                        {
                            can_mb_skip = (uint8)1U;
                        }
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                        /* Record for current controller the HTH/HRH assigned foe every MB. */
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                        Can_ControllerStatuses[Controller].Can_MBMapping[can_mb_ctrl_index] = (uint16)((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->HWObjID;

                        /* Increment current index for the controller on every RxMB configured. */
                        can_mb_ctrl_index++;

                        /* At this point "FirstTxMBIndex" is updated and considering RxFifo if enebaled also. */
                        Can_ControllerStatuses[Controller].FirstTxMBIndex = can_mb_ctrl_index;
                    }
                }
                /* Increment the MB index for the controller even is Tx or Rx MB.
                  "can_mb_global_index" should parse all HOH or at least all the MBs for this controller are configured. */
                can_mb_global_index++;
            }

            /*Reset the counter for global MBs. */
            can_mb_global_index  = 0U;

            /* Parse all MBs that are of type TRANSMIT from the chain list, but process only the MBs for controller transmitted as parameter in this function. */
            while ( (can_mb_ctrl_index < can_ptrControlerDescriptor->MaxMBCount) &&
                    (can_mb_global_index < can_ptrMBConfigContainer->MessageBufferConfigCount) )
            {
                /* can_mb_global_index variable is incrementing based of existing HOH for MBs. */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used  */
                if ( Controller == (((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->ControllerId))
                {
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4 */
                    if (CAN_TRANSMIT == ((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->MBType )
                    {
                            /* Enable the MB as an TX object. MB is used for Tx & SRR must be set for Tx buffers. */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_CS_CONFIG( can_hw_offset, can_mb_ctrl_index, (uint32)(FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_SRR));

                            /* Configure only PRIO field of MBCS register of every Tx MB. */
                            if ( CAN_CONTROLLERCONFIG_LPRIO_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_LPRIO_EN) )
                            {
                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
                                can_mb_messageid = (uint32)((uint32)(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->LocalPriority) << FLEXCAN_MB_ID_PRIO_SHIFT) ;
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_MB_ID_CONFIG( can_hw_offset, can_mb_ctrl_index, can_mb_messageid );
                            }

                            if ( CAN_CONTROLLERCONFIG_TXPOL_EN != (CAN_CONTROLLERCONFIG_TXPOL_EN & can_ptrControlerDescriptor->Options) )
                            {
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                                if ( can_mb_ctrl_index >= FLEXCAN_MB_32 )
                                {
                                    Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK2_INDEX] |= ((uint32)1U << (can_mb_ctrl_index - FLEXCAN_MB_32));
                                }
                                else
                                {
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                                    Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX] |= ((uint32)1U << can_mb_ctrl_index);
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                                }
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                            }

                            /* Record for current controller the HTH/HRH assigned foe every MB. */
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                            Can_ControllerStatuses[Controller].Can_MBMapping[can_mb_ctrl_index] = (uint16)(((can_ptrMBConfigContainer->MessageBufferConfigsPtr) + can_mb_global_index)->HWObjID);

                            /* Increment current index for the controller on every RxMB configured. */
                            can_mb_ctrl_index++;

                    }
                }

                /* Increment the MB index for the controller even is Tx or Rx MB.
                  "can_mb_global_index" should parse all HOH or at least all the MBs for this controller are configured. */
                can_mb_global_index++;
            }

            if(can_ptrControlerDescriptor->MaxMBCount > 0U)
            {
                can_mb_max = can_ptrControlerDescriptor->MaxMBCount - 1U;
            }
            else
            {
                can_mb_max = 0U;
            }
            /* Set the number of MBs configured for this controller (Rx + Tx MBs). */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_SET_MCR_MAXMB( can_hw_offset, (uint32)can_mb_max );

/*
* @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
*/
#if defined(ERR_IPV_FLEXCAN_0002)
  #if (ERR_IPV_FLEXCAN_0002== STD_ON)
    /* Do not set the Abort Enable bit of the MCR */
  #else
    #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
  #endif
#elif defined(CAN_USE_MCR_ABORT_ENABLE)
  #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
    /* Do not set the Abort Enable bit of the MCR */
  #else
    #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
  #endif
#else
    #if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
            /* Abort Enable: Tx Cancelation supported and used for this Controller. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_SET_MCR_AEN ( can_hw_offset);
    #endif /* (CAN_HW_TRANSMIT_CANCELLATION==STD_ON) */
#endif

            /* Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) - If events are set for polling mode these bits are not set.
                Clear all INTs flags  .. for MBs (w1c bits). */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 )
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            /* Check whether Can controller supports 64 message buffers */
            if ( FLEXCAN_MB_64 == can_ptrControlerDescriptor->Can_NumberOfMB)
            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_IFLAG2_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */

            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_IFLAG1_CONFIG( can_hw_offset, FLEXCAN_32BITMASK);

            /* Clear bits for Tx/Rx/BusOff/Err/WakeUp (w1c bits). */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_ESR_CONFIG( can_hw_offset, (uint32)(FLEXCAN_ESR_BOFFINT | FLEXCAN_ESR_ERRINT | FLEXCAN_ESR_WAK_INT));

#if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* After controller is (re-)initialized the state is CAN_T_STOP. For this state the Wakeup support must not be enabled.
            Wakeup is used for the transition out of CAN_T_SLEEP state. */

            /* If internal WakeUp is supported clear Wakeup status int flag (w1c bit). */
            FLEXCAN_SET_ESR_WAK_INT( can_hw_offset);

#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

            /* Clear the Error Counters Register. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_ECR_CONFIG( can_hw_offset, (uint32)0UL);

            /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                unless the CPU reads the C/S word of another MB.*/
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_TIMER_READ( can_hw_offset);

        } /* (can_reset_return == CAN_OK) */
    }


/*================================================================================================*/
/**
* @brief          Service to Perform software triggered state transitions of the CAN controller State machine.
* @details        Transition controller to another state/mode.
*                 This routine is called by:
*                  - Can_SetControllerMode() from Can.c file.
*                  - Can_LLD_Process_BusOff() from Can.c file.
*                  - FlexCan_LLD_Process_Wakeup() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_ptrControlerDescriptor Pointer to controller descriptor configuration
* @param[in]      Transition Possible transitions
*
* @return         Can_ReturnType
* @retval         CAN_OK transition initiated
* @retval         CAN_NOT_OK development or production error
*
* @pre            Controller is configured and must be into a state that permit the valid transition to another different state.
* @post           Shall enable interrupts that are needed in the new state. Shall disable interrupts that are not allowed in the new state.
*
* @requirements   CAN283, CAN264
* @implements     DCAN01077, DCAN01078, DCAN01079, DCAN01080, DCAN01081, DCAN01082, DCAN01083, DCAN01084, DCAN01085, DCAN01086, DCAN01087, DCAN01088, DCAN01089, DCAN01090, DCAN01091, DCAN01092, DCAN01093, DCAN01094, DCAN01095, DCAN01096, DCAN01097, DCAN01098, DCAN01138, DCAN01139, DCAN01802, DCAN01803
*
*/
FUNC (Can_ReturnType, CAN_CODE) Can_LLD_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor,
                                                           VAR(Can_StateTransitionType, AUTOMATIC) Transition,
                                                           VAR(boolean, AUTOMATIC) canif_notification_required)
    {

        /* Variable for return status. */
        VAR(Can_ReturnType, AUTOMATIC)  Out_can_return = CAN_NOT_OK;
        /* Variable for indexing the MBs. */
        VAR(uint8, AUTOMATIC)           can_mb_ctrl_index = 0U;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)           can_hw_offset = 0U;
        /* Temporary variable for CTRL register. */
        VAR(uint32, AUTOMATIC)          can_ctrl_reg = 0U;
        /* Temporary variable for MB config register. */
        VAR(uint32, AUTOMATIC)          can_mb_config = 0U;
        /* Timeout counter. */
        VAR(uint32, AUTOMATIC)          can_timeout_count = 0U;
        VAR(uint32, AUTOMATIC)          can_temp_var = 0U;



        /* Get the hardware offset for this controller. */
        can_hw_offset = can_ptrControlerDescriptor->ControllerOffset;

        /*
          (CAN017) The function Can_SetControllerMode shall perform software triggered state transitions of the CAN controller State machine.
        */
        switch (Transition)
        {
            /* CANIF_CS_STARTED -> CANIF_CS_STOPPED. */
            /*
               (CAN283) The function Can_SetControllerMode(CAN_T_STOP) shall not call a cancellation notification.
            */
            case (CAN_T_STOP):
                /*
                   (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transision to a state that was already reached.
                */
                if ( CAN_STOPPED == Can_ControllerStatuses[Controller].ControllerState)
                {
                    /* If the controller is already in STOP state, return CAN_OK. */
                    Out_can_return = CAN_OK;
                }
                else
                {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    /* Valid transitions to Stop are only from Start and Wakeup. */
                    if ( CAN_STARTED != Can_ControllerStatuses[Controller].ControllerState)
                    {
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
                    }
                    else
                    {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                        /*
                          (CAN263) The function Can_SetControllerMode(CAN_T_STOP) shall set the bits inside the CAN hardware such that the CAN controller
                                   stops participating on the network.
                        */

                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_FRZ( can_hw_offset);
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_SET_MCR_HALT( can_hw_offset);

                        /*
                           (CAN264) The function Can_SetControllerMode(CAN_T_STOP) shall wait for a limited time until the CAN controller is really switched off. Compare to CAN371
                        */
                        /* This means will wait until MCR[FRZ_ACK] is set. */
                        can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
                        can_temp_var = (uint32)0U;
                        do {
                            /* ... stay in loop */
                           can_timeout_count--;
                             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_temp_var |= ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & (FLEXCAN_MCR_FRZACK));
                        } while ((can_timeout_count > (uint32)0x0U) && ( (FLEXCAN_MCR_FRZACK) != can_temp_var));

                        if ( (FLEXCAN_MCR_FRZACK) == can_temp_var )
                        {
                            /* Set the Stop state to the controller. */
                            Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
                            Out_can_return = CAN_OK;
                        }
                        else
                        /* software timeout */
                        {
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            Can_MCR_Configuration[Controller] = (uint32)FLEXCAN_MCR_READ( can_hw_offset);
                            Out_can_return = CAN_NOT_OK;
                        }
                        /* Check if Software BusOff Recovery is enabled. */
                        if ( CAN_CONTROLLERCONFIG_BUSOFFSWREC == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_BUSOFFSWREC) )
                        {
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_CLEAR_CTRL_BOFFREC( can_hw_offset);
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_SET_CTRL_BOFFREC( can_hw_offset);
                        }

                        /* Loop through all Tx MBs. -> must abort transmission for all MBs for Tx. */
                        for ( can_mb_ctrl_index = Can_ControllerStatuses[Controller].FirstTxMBIndex; can_mb_ctrl_index < can_ptrControlerDescriptor->MaxMBCount; can_mb_ctrl_index++)
                        {
                            /* Cancel the MB (just in case it is scheduled for Tx). This is a HARD ABORT, confirmation of whether the MB was transmitted or not is not required. */
                            /*
                               (CAN282) The function Can_SetControllerMode(CAN_T_STOP) shall cancel pending messages.
                               (CAN273)After bus-off detection, the Can module shall cancel still pending messages without raising a cancellation notification.
                            */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_mb_config = ( ((uint32)FLEXCAN_MB_READ( can_hw_offset, can_mb_ctrl_index) & ~FLEXCAN_MBCS_CODE) | FLEXCAN_MBCS_CODETX );
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_CS_CONFIG( can_hw_offset, can_mb_ctrl_index, can_mb_config);
                        }

                        /*
                        The Can module shall track all individual enabling and disabling of  interrupts
                            in other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored.
                        When Freeze mode (or Autosar equiv Stop mode) need to not participate on network ->
                            no interrupt is required to be enabled.
                        */
                        Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~(SWF_BOFF_MASK | SWF_ERR_MASK | SWF_MB_MASK | SWF_WRNINT_MASK));
#if (CAN_WAKEUP_SUPPORT == STD_ON)
                        Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~SWF_WAK_MASK);
#endif /*  (CAN_WAKEUP_SUPPORT == STD_ON)*/

                        /* Check if Ints are enabled by Can_EnableControllerInterrupts. */
                        if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                        {
                            /*
                               (CAN197) The function Can_SetControllerMode shall disable interrupts that are not allowed in the new state.
                               (CAN426)  Disabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
                            */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_CLEAR_CTRL_BOFFMSK( can_hw_offset);
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_CLEAR_CTRL_ERRMSK( can_hw_offset);
                            if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
                            {
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_CLEAR_CTRL_TWRNMSK( can_hw_offset);
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_CLEAR_CTRL_RWRNMSK( can_hw_offset);
                            }
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            /* Check whether Can controller supports 64 message buffers */
                            if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB )
                            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_IMASK2_CONFIG( can_hw_offset, (uint32)0U);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */

/* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_IMASK1_CONFIG( can_hw_offset, (uint32)0U);

#if (CAN_WAKEUP_SUPPORT == STD_ON)
                            /* No need for Wakeup support in Stop mode (only for Sleep). */
                            FLEXCAN_CLEAR_MCR_WAK_MSK(can_hw_offset);
                            /**@}*/
#endif /*  (CAN_WAKEUP_SUPPORT == STD_ON)*/
                        }

#if (CAN_WAKEUP_SUPPORT == STD_ON)
                        /* For internal wakeup the ESR[WAK_INT] bit is always activated  - it's a status bit that is masked by MCR[WAK_MSK].
                           This bit enables the Self Wake Up feature when FlexCAN is in Doze/Stop Mode. */
                        FLEXCAN_CLEAR_MCR_SLF_WAK( can_hw_offset);
#endif /*  (CAN_WAKEUP_SUPPORT == STD_ON)*/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                }
                if ((CAN_OK == Out_can_return) && ((boolean)TRUE == canif_notification_required))
                {
                    CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
                }
                break;

            /* CANIF_CS_STOPPED -> CANIF_CS_STARTED. */
            case (CAN_T_START):

#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    /* Valid transitions to Start mode are only from Stop state. */
                    if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState)
                    {
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
                    }
                    else
                    {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
#if (CAN_DUAL_CLOCK_MODE == STD_OFF)
                        /* (CAN384) Each time the CAN controller state machine is triggered with the state transition value CAN_T_START, the function
                        Can_SetControllerMode shall re-initialize the CAN controller with the same controller configuration set previously used by functions
                        Can_ChangeBaudrate or Can_Init.*/
                       Can_LLD_ChangeBaudrate( Controller);
#endif
                        /*
                         (CAN261) The function Can_SetControllerMode(CAN_T_START) shall set the hardware registers in a way that makes the CAN controller participating on the network.
                        */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_CLEAR_MCR_FRZ( can_hw_offset);
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_CLEAR_MCR_HALT( can_hw_offset);

                        /*
                        (CAN196) The function Can_SetControllerMode shall enable interrupts that are needed in the new state.
                        (CAN425)   Enabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
                         */
                        /*
                        The Can module shall track all individual enabling and disabling of interrupts in
                            other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored.
                        */
                        Can_ControllerStatuses[Controller].ControllerSWFlag |= (uint8)(SWF_MB_MASK);
                        if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
                        {
                            Can_ControllerStatuses[Controller].ControllerSWFlag |= (uint8)(SWF_WRNINT_MASK);
                        }

                        if ( CAN_CONTROLLERCONFIG_ERR_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_ERR_EN) )
                        {
                            Can_ControllerStatuses[Controller].ControllerSWFlag |= (uint8)(SWF_ERR_MASK);
                        }

                        if ( CAN_CONTROLLERCONFIG_BOPOL_EN != (CAN_CONTROLLERCONFIG_BOPOL_EN & can_ptrControlerDescriptor->Options))
                        {
                            Can_ControllerStatuses[Controller].ControllerSWFlag |= (uint8)(SWF_BOFF_MASK);
                        }
#if (CAN_WAKEUP_SUPPORT == STD_ON)
                        /* Wakeup interrupt is not required in Start mode. */
                        Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~SWF_WAK_MASK);

                        /* This bit enables the Self Wake Up feature when FlexCAN is in Doze/Stop Mode. */

                        FLEXCAN_CLEAR_MCR_SLF_WAK(can_hw_offset);


                        if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                        {

                            /* No need for Wakeup support in Run mode. */
                            FLEXCAN_CLEAR_MCR_WAK_MSK( can_hw_offset);
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_ctrl_reg = (uint32)FLEXCAN_CTRL_READ(can_hw_offset);
                            if ( CAN_CONTROLLERCONFIG_ERR_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_ERR_EN) )
                            {
                                can_ctrl_reg |= FLEXCAN_CTRL_ERRMSK;
                            }

                            if ( CAN_CONTROLLERCONFIG_BOPOL_EN != (CAN_CONTROLLERCONFIG_BOPOL_EN & can_ptrControlerDescriptor->Options))
                            {
                                can_ctrl_reg |= FLEXCAN_CTRL_BOFFMSK;
                            }

                            if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
                            {
                                can_ctrl_reg |= FLEXCAN_CTRL_TWRNMSK | FLEXCAN_CTRL_RWRNMSK;
                            }
                            /*
                            * @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                            */
                            FLEXCAN_CTRL_CONFIG( can_hw_offset, can_ctrl_reg);

#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            /* Check whether Can controller supports 64 message buffers */
                            if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB)
                            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_IMASK2_CONFIG( can_hw_offset, Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK2_INDEX]);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                            /*
                            * @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
                            */
                            FLEXCAN_IMASK1_CONFIG( can_hw_offset, Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX]);
#if (CAN_WAKEUP_SUPPORT == STD_ON)
                        }
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */


                        /* (CAN262) The function Can_SetControllerMode(CAN_T_START) shall wait for limited time until the CAN controller is fully operational. Compare to CAN371. */
                        can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
                        can_temp_var = (uint32)0U;
                        do {
                            /* ... stay in loop */
                            can_timeout_count--;
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_temp_var = ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & (FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT | FLEXCAN_MCR_NOTRDY));
                        } while ((can_timeout_count > (uint32)0x0U) && ( 0x0U != can_temp_var));

                        if ((uint32)0x0U == can_temp_var)
                        {
                            /* Set the Start State. */
                            Can_ControllerStatuses[Controller].ControllerState = CAN_STARTED;
                            Out_can_return = CAN_OK;
                        }
                        else
                        /* software timeout */
                        {
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            Can_MCR_Configuration[Controller] = (uint32)FLEXCAN_MCR_READ( can_hw_offset);
                            Out_can_return = CAN_NOT_OK;
                        }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                if (CAN_OK == Out_can_return)
                {
                    CanIf_ControllerModeIndication(Controller, CANIF_CS_STARTED);
                }
                break;

            /* CANIF_CS_STOPPED -> CANIF_CS_SLEEP. */
            case (CAN_T_SLEEP):

#if (CAN_WAKEUP_SUPPORT == STD_ON)
                /*
                   (PR-MCAL-3057) The Can driver shall not create a development error if the CanIf requests a transision to a state that was already reached.
                */
                if ( CAN_SLEEPED == Can_ControllerStatuses[Controller].ControllerState )
                {
                    /* If the controller is already in SLEEP state, return CAN_OK. */
                    Out_can_return = CAN_OK;
                }
                else
                {
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    /* Valid transitions to Sleep state are only from Stop state. */
                    if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState)
                    {
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
                    }
                    else
                    {
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                        /*
                           (CAN290)If the CAN HW does not support a sleep mode, the function Can_SetControllerMode(CAN_T_SLEEP) shall set the
                                    CAN controller to the logical sleep mode.
                           (CAN267) If the CAN HW does not support a sleep mode, the function Can_SetControllerMode(CAN_T_WAKEUP) shall return
                                    from the logical sleep mode, but have no effect to the CAN controller state (as the controller is already
                                    in stopped state).
                        */
                        /* If Wakeup is not supported no operation is done. */
                        if ( CAN_CONTROLLERCONFIG_WAKSUP_EN == (CAN_CONTROLLERCONFIG_WAKSUP_EN & can_ptrControlerDescriptor->Options))
                        {
                            if ( CAN_CONTROLLERCONFIG_WKPOL_EN != (CAN_CONTROLLERCONFIG_WKPOL_EN & can_ptrControlerDescriptor->Options))
                            {
                                /*
                                   (CAN294) The function Can_SetControllerMode shall disable the wake-up interrupt, while checking the wake-up status.
                                */
                                /* First of all, disable WakeUp interrupt. */
                                Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~SWF_WAK_MASK);

                                if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                                {
                                    FLEXCAN_CLEAR_MCR_WAK_MSK( can_hw_offset);
                                    FLEXCAN_CLEAR_MCR_SLF_WAK( can_hw_offset);

                                }

                                /*
                                   (CAN048) In case of a CAN bus wake-up during sleep transition, the function Can_SetControllerMode(CAN_T_WAKEUP) shall return CAN_NOT_OK.
                                */
                                /* Init this value with CAN_OK = 0x00. */
                                Out_can_return = CAN_OK;

                                /* Check for Wakeup flag status. */
                            #if (CAN_API_ERROR_STATUS == STD_ON)
                                Can_EsrRegStatus[Controller] = FLEXCAN_ESR_READ(can_hw_offset);
                                if ( FLEXCAN_ESR_WAK_INT == (FLEXCAN_ESR_WAK_INT & Can_EsrRegStatus[Controller]) )
                            #else
                                if ( FLEXCAN_ESR_WAK_INT == (FLEXCAN_ESR_WAK_INT & FLEXCAN_ESR_READ(can_hw_offset)) )
                            #endif
                                {
                                    /* Wakeup interrupt occurred, return with error. */
                                    Out_can_return = CAN_NOT_OK;
                                }

                                /*
                                  (CAN257) When the CAN hardware supports sleep mode, when transitioning into mode CANIF_CS_SLEEP, the Can module shall set the controller to a state from which the hardware can be woken over CAN Bus.
                                  (CAN197) The function Can_SetControllerMode shall disable interrupts that are not allowed in the new state.
                                        Disabling of CAN interrupts shall not be executed, when CAN interrupts have been disabled by function CAN_DisableControllerInterrupts.
                                */
                                if ( CAN_OK == Out_can_return )
                                {
                                    /* Enable interrupts that are needed in this state. */
                                    Can_ControllerStatuses[Controller].ControllerSWFlag |= (uint8)SWF_WAK_MASK;

                                    /* Disable interrupts that are not needed in this state. */
                                    Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~(SWF_BOFF_MASK | SWF_ERR_MASK | SWF_WRNINT_MASK | SWF_MB_MASK));

                                    if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                                    {
                                        /* Enable the Wakeup interrupt generation. */
                                        FLEXCAN_SET_MCR_WAK_MSK( can_hw_offset);
                                        FLEXCAN_CLEAR_CTRL_BOFFMSK( can_hw_offset);
                                        FLEXCAN_CLEAR_CTRL_ERRMSK( can_hw_offset);
                                        if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
                                        {
                                            FLEXCAN_CLEAR_CTRL_TWRNMSK( can_hw_offset);
                                            FLEXCAN_CLEAR_CTRL_RWRNMSK( can_hw_offset);
                                        }
    #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
      #if (CAN_MIX_MB_SUPPORT == STD_ON)
                                        /* Check whether Can controller supports 64 message buffers */
                                        if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB)
                                        {
      #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                                            FLEXCAN_IMASK2_CONFIG( can_hw_offset, (uint32)0U);
      #if (CAN_MIX_MB_SUPPORT == STD_ON)
                                        }
      #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
    #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                                        FLEXCAN_IMASK1_CONFIG( can_hw_offset, (uint32)0U);
                                    }
                                    /* This bit enables the Self Wake Up feature when FlexCAN is in Doze/Stop Mode.
                                       If a transition from recessive to dominant is detected during Stop Mode, then FlexCAN generates, if enabled to do so, a Wake Up interrupt to the CPU so that it can resume the clocks globally. */
                                    FLEXCAN_SET_MCR_SLF_WAK( can_hw_offset);

                                    Can_ControllerStatuses[Controller].ControllerState = CAN_SLEEPED;

                                    /* The hardware settings only differ from CANIF_CS_STOPPED for CAN hardware that support a sleep mode (wake-up over CAN bus directly supported by CAN hardware).  */
                                    /*
                                       (CAN265)The function Can_SetControllerMode(CAN_T_SLEEP) shall put the controller into sleep mode.
                                    */
                                    Out_can_return = CAN_OK;
                                }
                            }
                            else
                            /* POLLING mode */
                            {
                                /* For internal wakeup the ESR[WAK_INT] bit is always activated  - it's a status bit that is masked by MCR[WAK_MSK].
                                   This bit enables the Self Wake Up feature when FlexCAN is in Doze/Stop Mode. */
                                FLEXCAN_SET_MCR_SLF_WAK( can_hw_offset);

                                Can_ControllerStatuses[Controller].ControllerState = CAN_SLEEPED;
                                Out_can_return = CAN_OK;
                            }
                        }
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */


                    /*
                       (CAN266) If the CAN HW does support a sleep mode, the function Can_SetControllerMode(CAN_T_SLEEP) shall wait for a limited time until the CAN controller is in SLEEP state and it is assured that the CAN hardware is wake able. Compare to CAN371.
                    */
                    /* Now must assure that when return from this function Can controller is wakeable. For all state changes except the
                            change to state CANIF_CS_SLEEP, the function does not wait until the state change has really performed. */
                    can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
                    do {
                        /* ... stay in loop */
                        can_timeout_count--;
                        can_temp_var = (uint32)0U;

                        if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                        {
                            can_temp_var = ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_WAK_MSK );
                        }
                        /* Self Wakeup must be set. */
                        can_temp_var |= ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_SLF_WAK );
                    } while ((can_timeout_count > (uint32)0x0U) && ( (uint32)0x0U == can_temp_var));

                    if ((uint32)0x0U != can_temp_var)
                    {
                        Out_can_return = CAN_OK;
                    }
                    else
                    /* software timeout */
                    {
                        Can_MCR_Configuration[Controller] = (uint32)FLEXCAN_MCR_READ( can_hw_offset);
                        Out_can_return = CAN_NOT_OK;
                    }
                }
#else /* (CAN_WAKEUP_SUPPORT == STD_OFF) */
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    /* Valid transitions to Sleep state are only from Stop state. */
                    if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState)
                    {
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
                    }
                    else
                    {
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                        /* CAN258: When the CAN hardware does not support sleep mode and is triggered 
                        to transition into SLEEP state, the Can module shall emulate a logical SLEEP state 
                        from which it returns only, when it is triggered by software to transition into 
                        STOPPED state */
                        Can_ControllerStatuses[Controller].ControllerState = CAN_SLEEPED;

                        /* When Wakeup is not supported the driver should do nothing and return CAN_OK. */                        
                        Out_can_return = CAN_OK;
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

#endif /* (CAN_WAKEUP_SUPPORT == STD_OFF) */
                /*@violates @ref FlexCan_LLD_c_REF_18 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
                if (CAN_OK == Out_can_return)
                {
                    CanIf_ControllerModeIndication(Controller, CANIF_CS_SLEEP);
                }
                break;

            /* CANIF_CS_SLEEP -> CANIF_CS_STOPPED */
            case (CAN_T_WAKEUP):
                /*Controllers option for wakeup support(CAN_CONTROLLERCONFIG_WAKSUP_EN) is not necessarly to be checked because if this is not supported,
                the controller cannot be in state CAN_SLEEPED, so the Det_ReportError will be raised*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
                /*
                  (CAN268) The function Can_SetControllerMode(CAN_T_WAKEUP) shall be non-blocking.
                  (CAN270)On hardware wakeup (triggered by a wake-up event from CAN bus), the Can module shall transition into the state CAN_IF_CS_STOPPED.
                */
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* Valid transitions to Wakeup state are ony from Sleep state. */
                if (CAN_SLEEPED != Can_ControllerStatuses[Controller].ControllerState)
                {
                    Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
                }
                else
                {
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                    /*
                       (CAN294) The function Can_SetControllerMode shall disable the wake-up interrupt, while checking the wake-up status.
                    */

                    /* The Can module shall track all individual enabling and disabling of  interrupts in other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored. */
                    Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~SWF_WAK_MASK);

                    Can_ControllerStatuses[Controller].ControllerSWFlag &= (uint8)(~(SWF_BOFF_MASK | SWF_ERR_MASK | SWF_WRNINT_MASK | SWF_MB_MASK));

                    if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                    {
                        /* Disable WakeUp Interrupt. */
                            FLEXCAN_CLEAR_MCR_WAK_MSK( can_hw_offset);

                        FLEXCAN_CLEAR_CTRL_BOFFMSK( can_hw_offset);
                        FLEXCAN_CLEAR_CTRL_ERRMSK( can_hw_offset);
                        if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
                        {
                            FLEXCAN_CLEAR_CTRL_TWRNMSK( can_hw_offset);
                            FLEXCAN_CLEAR_CTRL_RWRNMSK( can_hw_offset);
                        }
  #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        /* Check whether Can controller supports 64 message buffers */
                        if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB))
                        {
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                            FLEXCAN_IMASK2_CONFIG( can_hw_offset, (uint32)0U);
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        }
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
  #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                        FLEXCAN_IMASK1_CONFIG( can_hw_offset, (uint32)0U);
                    }

                    FLEXCAN_CLEAR_MCR_SLF_WAK( can_hw_offset);

                    /* Set the Stop state. */
                    Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;

                    /* Report "transition initiated". */
                    Out_can_return = CAN_OK;

                    /*
                       CAN268: The function Can_SetControllerMode(CAN_T_WAKEUP) shall wait for a limited time until the CAN controller is in STOPPED state. Compare to CAN371.
                    */

                    can_timeout_count = (uint32)CAN_TIMEOUT_DURATION;
                    do {
                        /* ... stay in loop */
                        can_timeout_count--;
                        can_temp_var = (uint32)0U;
                        if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[Controller].InterruptMode )
                        {
                            can_temp_var = ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_WAK_MSK );
                        }
                        /* Self Wakeup must be set. */
                        can_temp_var |= ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_SLF_WAK );
                    } while ((can_timeout_count > (uint32)0x0U) && ( (uint32)0x0U != can_temp_var));

                    if ((uint32)0x0U == can_temp_var)
                    {
                        Out_can_return = CAN_OK;
                    }
                    else
                    /* software timeout */
                    {
                        Can_MCR_Configuration[Controller] = (uint32)FLEXCAN_MCR_READ( can_hw_offset);
                        Out_can_return = CAN_NOT_OK;
                    }
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
                }
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

#else /* (CAN_WAKEUP_SUPPORT == STD_OFF) */

                Can_ControllerStatuses[Controller].ControllerState = CAN_STOPPED;
                /* When Wakeup is not supported the driver should do nothing and return CAN_OK. */
                Out_can_return = CAN_OK;

#endif /* (CAN_WAKEUP_SUPPORT == STD_OFF) */
                /*@violates @ref FlexCan_LLD_c_REF_18 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
                if (CAN_OK == Out_can_return)
                {
                    CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
                }
                break;

            /* Unknown transition requested. */
            default:
                /*
                   (CAN200) If development error detection for the Can module is enabled: if an invalid transition has been requested, the function Can_SetControllerMode shall raise the error CAN_E_TRANSITION and return CAN_NOT_OK.
                */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                break;

        } /* end switch */

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Service disables all interrupts for the given CAN controller.
* @details        This routine is called by:
*                 - Can_DisableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_ptrControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Disable interrupts must be called prior to enable interrupts.
* @post           Clear all flags/bits that are needded for disabling the interrupts.
*
* @implements     DCAN01099, DCAN01100, DCAN02602
*
*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor)
    {

        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)   can_hw_offset = 0U;


        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00();
        /*
           (CAN202) When Can_DisableControllerInterrupts has been called several times, Can_EnableControllerInterrupts must be called
                    as many times before the interrupts are re-enabled.
        */
        Can_ControllerStatuses[Controller].IntDisableLevel++;

        /* If nesting level is zero or below zero; <0 needed for reentrancy. */
        /*
           (CAN049) The function Can_DisableControllerInterrupts shall disable all interrupts for this CAN controller only at the first call of this function.
        */
        if ( (sint8)1 == Can_ControllerStatuses[Controller].IntDisableLevel )
        {
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();

            /* Switch to disabled mode. */
            Can_ControllerStatuses[Controller].InterruptMode = (uint8)CAN_INTERRUPT_DISABLED;

            /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
            can_hw_offset = can_ptrControlerDescriptor->ControllerOffset;

            /*
               (CAN033) The Can module shall implement the interrupt service routines for all CAN Hardware Unit interrupts that are needed.
                        The Can module shall disable all unused interrupts in the CAN controller.
                        The Can module shall reset the interrupt flag at the end of the ISR (if not done automatically by hardware).
                        The Can module shall not set the configuration (i.e. priority) of the vector table entry.
            */
            /* Can_DisableControllerInterrupts and Can_EnableControllerInterrupts should not modify the software flags. */
            /* Disable MB Rx/Tx interrupts. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            /* Check whether Can controller supports 64 message buffers */
            if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB))
            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_IMASK2_CONFIG( can_hw_offset, (uint32)0x0UL);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_IMASK1_CONFIG( can_hw_offset, (uint32)0x0UL);

#if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Disable Wakeup interrupts. */
            FLEXCAN_CLEAR_MCR_WAK_MSK( can_hw_offset);

#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

            /* Disable BusOff, Error, TxW, RxW interrupts. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_CLEAR_CTRL_BOFFMSK( can_hw_offset);
             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_CLEAR_CTRL_ERRMSK( can_hw_offset);
            if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
            {
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_CLEAR_CTRL_TWRNMSK( can_hw_offset);
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                FLEXCAN_CLEAR_CTRL_RWRNMSK( can_hw_offset);

            }
        }
        else
        {
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
        }
    }


/*================================================================================================*/
/**
* @brief          Service enables all interrupts that shall be enabled according the current software status.
* @details        This routine is called by:
*                  - Can_EnableControllerInterrupts() from Can.c file.
*
* @param[in]      Controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_ptrControlerDescriptor Pointer to controller descriptor configuration
*
* @pre            Can be executed only if disable interrupts was called before.
* @post           Enable all interrupts that must be enabled according the current sw status.
*
* @implements     DCAN01101, DCAN01102, DCAN01104, DCAN01105
*
*/
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                          P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor )
    {

        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)   can_hw_offset = 0U;
        /* Variable that tells if disable ints was called at least once before. */
        VAR(uint8, AUTOMATIC)   can_dis_called_before = 0U;
        /* Variable that tells if at least one interrupt is enabled according to software flags - used only for Timeout checking. */
        VAR(uint8, AUTOMATIC)   can_int_set = 0U;


        /*
           (CAN202) When Can_DisableControllerInterrupts has been called several times, Can_EnableControllerInterrupts must be called as many
                   times before the interrupts are re-enabled.
        */
        if ( Can_ControllerStatuses[Controller].IntDisableLevel > (sint8)0 )
        {
            /* When IntDisableLevel is greater than 0  means Can_DisableControllerInterrupts was called at least once before this call of current function. */
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01();
            /* Decrement the nesting level. */
            Can_ControllerStatuses[Controller].IntDisableLevel--;

            can_dis_called_before = (uint8)0x1U;
        }

        /* Can_DisableControllerInterrupts and Can_EnableControllerInterrupts do not modify the software flags. */

        /*
           (CAN208) The function Can_EnableControllerInterrupts shall perform no action when Can_DisableControllerInterrupts has not been called before.
        */
        if ( ((sint8)0 == Can_ControllerStatuses[Controller].IntDisableLevel) && ((uint8)0x1U == can_dis_called_before) )
        {
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01();

            /* Switch to enabled mode. */
            Can_ControllerStatuses[Controller].InterruptMode = (uint8)CAN_INTERRUPT_ENABLED;

            /*
               (CAN050) The function Can_EnableControllerInterrupts shall enable all interrupts that must be enabled according the current software status.
            */
            /* Get the hardware offset for this controller. */
            can_hw_offset = can_ptrControlerDescriptor->ControllerOffset;
            if ( (CAN_CONTROLLERCONFIG_TXPOL_EN != (CAN_CONTROLLERCONFIG_TXPOL_EN & can_ptrControlerDescriptor->Options)) ||
                 (CAN_CONTROLLERCONFIG_RXPOL_EN != (CAN_CONTROLLERCONFIG_RXPOL_EN & can_ptrControlerDescriptor->Options)) )
            {
                if ( (uint8)SWF_MB_MASK == (Can_ControllerStatuses[Controller].ControllerSWFlag & (uint8)SWF_MB_MASK) )
                {
                    /* Enable INTs from MBs. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                    /* Check whether Can controller supports 64 message buffers */
                    if ( FLEXCAN_MB_64 == (can_ptrControlerDescriptor->Can_NumberOfMB))
                    {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_IMASK2_CONFIG( can_hw_offset, Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK2_INDEX]);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                    }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
                    /* Set here the interrupts for RX FIFO is FEN bit is set, but will clear the bits if functionality of Overflow or Warning is not enabled (below). */
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_IMASK1_CONFIG( can_hw_offset, Can_ControllerStatuses[Controller].MBInterruptMask[FLEXCAN_IMASK1_INDEX]);

                    /* Mark flag that tells if at least one INT is enabled. */
                    can_int_set |= (uint8)1U;
                }
            }

            /*
              (CAN204) The Can module shall track all individual enabling and disabling of interrupts in other functions (i.e. Can_SetControllerMode), so that the correct interrupt enable state can be restored.
            */
#if (CAN_WAKEUP_SUPPORT == STD_ON)
            if ( CAN_CONTROLLERCONFIG_WKPOL_EN != (CAN_CONTROLLERCONFIG_WKPOL_EN & can_ptrControlerDescriptor->Options) )
            {
                /* Check the software flag - if set then interrupt must be enabled. */
                if ( SWF_WAK_MASK == (Can_ControllerStatuses[Controller].ControllerSWFlag & SWF_WAK_MASK) )
                {
                    /* WakeUp - enable the interrupt. */
                    FLEXCAN_SET_MCR_WAK_MSK( can_hw_offset);
                    /* Mark flag that tells if at least one INT is enabled. */
                    can_int_set |= (uint8)1U;
                }
            }
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
            if ( CAN_CONTROLLERCONFIG_BOPOL_EN != (CAN_CONTROLLERCONFIG_BOPOL_EN & can_ptrControlerDescriptor->Options))
            {
                /* Check the software flag - if set then interrupt must be enabled. */
                if ( SWF_BOFF_MASK == (Can_ControllerStatuses[Controller].ControllerSWFlag & SWF_BOFF_MASK) )
                {
                    /* BusOff - enable the interrupt. */
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_SET_CTRL_BOFFMSK( can_hw_offset);
                    /* Mark flag that tells if at least one INT is enabled. */
                    can_int_set |= (uint8)1U;
                }
            }
            if ( CAN_CONTROLLERCONFIG_ERR_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_ERR_EN) )
            {
                /* Check the software flag - if set then interrupt must be enabled. */
                if ( SWF_ERR_MASK == (SWF_ERR_MASK & Can_ControllerStatuses[Controller].ControllerSWFlag))
                {
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_SET_CTRL_ERRMSK( can_hw_offset);
                    /* Mark flag that tells if at least one INT is enabled. */
                    can_int_set |= (uint8)1U;
                }
            }

            /* Check the software flag - if set then warning interrupts are enabled. */
            if ( CAN_CONTROLLERCONFIG_WRNINT_EN == (can_ptrControlerDescriptor->Options & CAN_CONTROLLERCONFIG_WRNINT_EN) )
            {
                if ( SWF_WRNINT_MASK == (SWF_WRNINT_MASK & Can_ControllerStatuses[Controller].ControllerSWFlag) )
                {
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_SET_CTRL_TWRNMSK( can_hw_offset);
                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_SET_CTRL_RWRNMSK( can_hw_offset);
                    /* Mark flag that tells if at least one INT is enabled. */
                    can_int_set |= (uint8)1U;
                }
            }
        }
        else
        {
            if ( Can_ControllerStatuses[Controller].IntDisableLevel > (sint8)0 )
            {
                SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01();
            }
        }
    }


/*================================================================================================*/
/**
* @brief          Local function for canceling low priority msg during Can Write operation.
* @details        This routine is called by:
*                  - Can_LLD_Write() from Can_FlexCan_LLD.c file.
*                  - Can_AbortMb() from Can.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex index of the message buffer to be canceled
*
* @pre            A Tx message with a higher priority was requested for a MB.
* @post           Inform CanIf about cancellation in case of success.
*
* @implements     DCAN01106, DCAN02202
*
*/
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_LLD_Cancel( VAR(uint8, AUTOMATIC) controller,
                                      VAR(uint8, AUTOMATIC) mbindex)
    {
        /* Unique identifier of a PDU within a software module */
        VAR(PduIdType, AUTOMATIC) Can_PduId;
        /* Store the basic information about a PDU */
        VAR(PduInfoType, AUTOMATIC) Can_CbkPduInfo;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)    can_hw_offset = 0U;
        /* Some temporary variables for registers read/write.  */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        VAR(uint8, AUTOMATIC)    can_iflag_reg_index = 0U;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
        /* Temporary variable for mbindex calculation. */
        VAR(uint32, AUTOMATIC)   can_temp_flag = 0U;
        /* Index of the IFLAG register for current MB. */
        VAR(uint32, AUTOMATIC)   can_iflag_reg = 0U;
        /* Configuration register for current MB. */
        VAR(uint32, AUTOMATIC)   can_mb_config = 0U;
#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
        /* Variable for region in Can Frame */
        VAR(uint8, AUTOMATIC)  Can_loop = 1U;
        VAR(uint32, AUTOMATIC) can_mb_content[4];
    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif
#endif

        /* Tell the interrupt routine that cancellation of this MB is in progress. */
        Can_ControllerStatuses[controller].CancelMBIndex = (Can_HwHandleType)mbindex;

        /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)

        do{
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
            /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
            Can_loop = Can_LLD_ForbiddenRegion(can_hw_offset, mbindex, can_mb_content);
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
          }while( 1U == Can_loop);

        if ( ((uint32)can_mb_content[0] & (uint32)(FLEXCAN_MBCS_CODE)) == (uint32)(FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXEN) )
        {
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else

        /* Check if the MB is still full. */
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXEN) )
        {
    #endif

    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
            /* MB still full -> deactivate it. */
        #if defined(ERR_IPV_FLEXCAN_0009)
            #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                can_mb_config = (can_mb_content[0] & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
            #else
                #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
            #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
        #else
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_config = ( FLEXCAN_MB_READ( can_hw_offset, mbindex) & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
        #endif /* ERR_IPV_FLEXCAN_0002 */

      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
      #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
            /* MB still full -> deactivate it. */
        #if defined(ERR_IPV_FLEXCAN_0009)
            #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                can_mb_config = (can_mb_content[0] & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
            #else
                #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
            #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
        #else
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_config = ( FLEXCAN_MB_READ( can_hw_offset, mbindex) & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
        #endif /* ERR_IPV_FLEXCAN_0009 */
      #else
        #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
            /* MB still full -> cancel it. */
        #if defined(ERR_IPV_FLEXCAN_0009)
            #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                can_mb_config = (can_mb_content[0] & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXABORT;
            #else
                #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
            #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
        #else
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_mb_config = ( FLEXCAN_MB_READ( can_hw_offset, mbindex) & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXABORT;
        #endif /* ERR_IPV_FLEXCAN_0009 */
    #endif
 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_MB_CS_CONFIG(can_hw_offset, mbindex, can_mb_config);

            /* Did the interrupt routine execute between the check and the abort command? i.e. did we possibly just try to cancel an empty MB? */
            if ( Can_ControllerStatuses[controller].CancelMBIndex == (Can_HwHandleType)mbindex)
            {
                /* INT routine did not execute and nobody else would clear the INT flag. We can continue checking the MB for cancellation.
                            Check whether the message has been cancelled. */
    /**
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
      /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                      if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX) )
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
      #if (CAN_USE_MCR_ABORT_ENABLE== STD_ON)
                      /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                      if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX) )
      #else
        #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXABORT) )
    #endif
                {
                    /* Message has been sucessfully aborted -> test the interrupt flag, is it set? */

                    /* Some temporary registers value. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                    /* Check whether Can controller supports 64 message buffers */
                    if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB)
                    {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                        /* Calculate the index of the IFLAG register and Txguard (index=0 for MB32...MB63, index=1 for MB0...MB31). */
                        can_iflag_reg_index = (uint8)((uint8)mbindex >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x01U;
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        can_iflag_reg = (((uint32)0x0U == (uint32)can_iflag_reg_index) ? (uint32)FLEXCAN_IFLAG2_READ(can_hw_offset) : (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset));
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                    }
                    else
                    {

                        can_iflag_reg = FLEXCAN_IFLAG1_READ(can_hw_offset);
                    }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    can_iflag_reg = FLEXCAN_IFLAG1_READ(can_hw_offset);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                    /* Calculate the flag value. */
                    can_temp_flag = ((uint32)0x01U) << ((uint32)mbindex & FLEXCAN_MASK_32BITS);

                    if ( (uint32)0x0UL == (can_iflag_reg & can_temp_flag) )
                    {
                        /* The INT flag = 0: the INT routine either already executed or will never execute for this cancellation. Is the message still marked as cancelled? */
    /**
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
      /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX) )
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
      #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
                        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX) )
      #else
        #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        if ( (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, mbindex) == (uint32)(FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXABORT) )
    #endif
                        {
 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            /* Variable for storing the Control and Status register of the MB. */
                            can_mb_config = (uint32)FLEXCAN_MB_READ( can_hw_offset, mbindex);

                            /* Transfer the DLC. */
                            Can_CbkPduInfo.SduLength = (uint32) ((can_mb_config & FLEXCAN_MBCS_LENGTH) >> FLEXCAN_MBCS_LENGTH_SHIFT);

                            /* Copy the Pdu handle. */
                            Can_PduId = Can_ControllerStatuses[controller].TxPduId[mbindex];
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            Can_CbkPduInfo.SduDataPtr =(uint8 *) FLEXCAN_MB_DATA(can_hw_offset, mbindex, 0);

            /**
            * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
            */
            #if defined(ERR_IPV_FLEXCAN_0002)
              #if (ERR_IPV_FLEXCAN_0002== STD_ON)

              #else
                #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
              #endif
            #elif defined(CAN_USE_MCR_ABORT_ENABLE)
              #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)

              #else
                #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
              #endif
            #else
                            /* Clear the Cancellation Flag. */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_mb_config = ((uint32)FLEXCAN_MB_READ( can_hw_offset, mbindex) & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
                             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_CS_CONFIG( can_hw_offset, mbindex, can_mb_config);
            #endif
                                
              /* Unlock the MB TxGuard. */
              #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            /* Check whether Can controller supports 64 message buffers. */
                            if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                            {
                #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                                Can_ControllerStatuses[controller].TxGuard[can_iflag_reg_index] &= (uint32)(~can_temp_flag);
                #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            }
                            else
                            {
                                Can_ControllerStatuses[controller].TxGuard[0U] &= (uint32)(~can_temp_flag);
                            }
                #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
              #else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                            Can_ControllerStatuses[controller].TxGuard[0U] &= (uint32)(~can_temp_flag);
              #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))                            
                                    /* MB Aborted Successfully, Set TX cancel status flag */
                                    if ( mbindex < (uint8)32 )/*for MB 32/64*/
                                    Can_TxCancelStatus[controller][0] |= ((uint32)0x01U << mbindex);
                      #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)                            
                                    else /*for MB 64*/
                                    Can_TxCancelStatus[controller][1] |= ((uint32)0x01U << (mbindex - (uint8)32));
                      #endif                            
                                    
                                    Can_PduIdBuff[controller][mbindex] = Can_PduId;
                                    Can_PduInfoBuff[controller][mbindex] =  Can_CbkPduInfo;
#else        
                            /* Call the CANCEL CONFIRMATION CALLBACK - This service is implemented in the CAN Interface and called by the
                            CAN Driver after a previous request for cancellation of a pending L-PDU transmit request was successfully performed. */

                            /*
                               (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with Ecu State Manager (ECUM))
                                        the CanIf module in a direct way. The driver only sees the CanIf module as origin and destination.
                               (CAN287) The Can module shall raise a notification when the cancellation was successful by calling the function CanIf_CancelTxConfirmation.
                            */
                            /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */

                            CanIf_CancelTxConfirmation(Can_PduId , &Can_CbkPduInfo);
#endif
                        }
                    }
                }
            }
            else
            {
                /* The MB either transmitted before it was cancelled (i.e. cancellation of an empty MB) and the interrupt routine already processed it.
                    Clear the cancellation flag (to take care of the first of the two possibilities) */
                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    can_mb_config = ((uint32)FLEXCAN_MB_READ( can_hw_offset, mbindex) & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX;
                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    FLEXCAN_MB_CS_CONFIG( can_hw_offset, mbindex, can_mb_config);
                /* No other action needed, the MB will now be empty and the interrupt routine has taken care of reporting to CanIf. */
            }
        }
    }

#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

/*================================================================================================*/
/**
* @brief          Process a message buffer abort
* @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
*                This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth - HW-transmit handler
*
* @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
*
* @implements     DCAN02809
*
*/
#if ((CAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON))

FUNC(void, CAN_CODE) Can_LLD_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth )
{
    VAR(uint8, AUTOMATIC) can_controller;
    /* Variable for indexing the MBs */
    VAR(uint8, AUTOMATIC) can_mb_index = 0U;





    can_controller = (Can_CurrentConfigPtr->Can_ControllerID_Mapping)[Hth];

    /* Here, we are positioning to the forst MessageBuffer that has ObjectId = Hth*/
    can_mb_index = Can_ControllerStatuses[can_controller].FirstTxMBIndex;
    while( (Can_ControllerStatuses[can_controller].Can_MBMapping[can_mb_index] != Hth) &&
    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
           (can_mb_index < Can_CurrentConfigPtr->ControlerDescriptors[can_controller].MaxMBCount) )
    {
        can_mb_index ++;
    }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test if controller is in valid range. */
            if ( (can_controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[can_controller].ControllerOffset)) )
            {
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ABORT_MB, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        #if ((Can_Abort_Only_One_MB==STD_OFF) && (CAN_MULTIPLEXED_TRANSMISSION==STD_ON))
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */

                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                 while( (can_mb_index < (Can_ControlerDescriptorsPtr[can_controller].MaxMBCount)) &&
                    (Can_ControllerStatuses[can_controller].Can_MBMapping[can_mb_index] == Hth) )
                {
                    Can_LLD_Cancel( can_controller, can_mb_index);
                    can_mb_index++;
                }
                #else /* Can_Abort_Only_One_MB==STD_OFF */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
             if( (can_mb_index < (Can_ControlerDescriptorsPtr[can_controller].MaxMBCount)) &&
                    (Can_ControllerStatuses[can_controller].Can_MBMapping[can_mb_index] == Hth) )
                {
                    Can_LLD_Cancel( can_controller, can_mb_index);
                }
                #endif   /* Can_Abort_Only_One_MB==STD_ON */

#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */
/*================================================================================================*/
/**
* @brief          Can_LLD_Write checks if hardware transmit object that is identified by the HTH is free.
* @details        Can_LLD_Write checks if hardware transmit object that is identified by the HTH is free.
*                     Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers/buffers.
*                         All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with CAN_OK.
*                     b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                         The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                         The transmission of the previous L-PDU is cancelled (asynchronously).
*                         The function returns with CAN_BUSY.
*                         This routine is called by:
*                         - Can_Write() from Can.c file.
*                     Algorithm Description:
*                     Case1: TxMUX supported = ON
*                           Can_Write receive the Hth handle and the PduInfo for transmission. It starts to check from the first MBs of the
*                           current controller to search for a free MB. On the first free MB it stops and place the PduInfo and activate the transmission.
*                           In this case function set CAN_OK for return value and all other functionality is skipped.
*                           If no MB is finded as free then the lowest priority MB is selected for comparing with the priority of the current PduInfo.
*                           If the current PduInfo has a higher priority than the current lower priority (from all MBs) then this lower priority MB is canceled.
*                    Case2: TxMUX supported = OFF
*                          CanWrite() receive the Hth handle and the PduInfo for transmission. It checks if MB with the same index as Hth is free and if yes prepare
*                          and sends the current PduInfo data. If that MB is bussy with another data then it checks the priority between these 2 structures.
*                          Depending by the last evaluation it decides what MB data to cancel.
*
* @param[in]      Hth information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use
*                 because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier
*
* @return          Can_ReturnType
* @retval          CAN_OK write command has been accepted
* @retval          CAN_NOT_OK development error occured
* @retval          CAN_BUSY no TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant
*
* @pre            The MB must be configured for Tx.
* @post           Transmit the data or ignore it in case of MB is full with another task.
*
* @implements     DCAN01107, DCAN01108, DCAN01109, DCAN01110, DCAN01111, DCAN01112, DCAN01113, DCAN01114, DCAN01115
*
*/
FUNC (Can_ReturnType, CAN_CODE) Can_LLD_Write( Can_HwHandleType Hth,
                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo )
    {

        /* Variable for return status. */
        VAR(Can_ReturnType, AUTOMATIC) Out_can_return = CAN_BUSY;
        /* Variable for keeping the controller Id. */
        VAR(uint8, AUTOMATIC)          can_ctrl_id = 0U;
        /* Variable for indexing the MBs. */
        VAR(uint8, AUTOMATIC)          can_mb_index = 0U;
        /* General purpose variable */
#if ((CAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON))
        /* Variables for keeping track of the lowest prio message. */
        VAR(uint8, AUTOMATIC)          can_mb_lprio_index = 0U;
        VAR(uint32, AUTOMATIC)         can_mb_lprio_id = 0U;
#endif /* ((CAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)) */
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)          can_hw_offset = 0U;
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        /* Variable for determining the IFLAG register for every MB: IFLAG1 or IFLAG2. */
        VAR(uint8, AUTOMATIC)          can_iflag_reg_index = 0U;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
        /* Variable for determining the mash bit in the IFLAGx register for current MB. */
        VAR(uint32, AUTOMATIC)         can_temp_flag = 0U;
        /* Variable for storing the value of IFLAG register. */
        VAR(uint32, AUTOMATIC)         can_iflag_reg = 0U;
        /* Variable for storing the ID of the MB from MB structure. */
        VAR(uint32, AUTOMATIC)         can_mb_messageid = 0U;
        /* Variable for storing the ConfigReg of the MB. */
        VAR(uint32, AUTOMATIC)         can_mb_config = 0U;
        /* Variable for byte index of the MB data. */
        VAR(uint8, AUTOMATIC)          can_mb_data_byte = 0U;
#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
        /* Variable for region in Can Frame */
        VAR(uint8, AUTOMATIC)  Can_loop = 1U;
        VAR(uint32, AUTOMATIC)  can_mb_content[4];
    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif
#endif

        /* Get the Controller ID for the current Hth MB. */
        can_ctrl_id = (Can_CurrentConfigPtr->Can_ControllerID_Mapping)[Hth];


#if ((CAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON))
        /* Define variable for keeping track of the lowest prio message. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        can_mb_lprio_index = Can_CurrentConfigPtr->ControlerDescriptors[can_ctrl_id].MaxMBCount - (uint8)0x1U;
#endif /* ((CAN_MULTIPLEXED_TRANSMISSION == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)) */

        /* Get the hardware offset for this controller. Note that hardware offset may not be the same with the controller index from the 'Can_ControlerDescriptorType' structure. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[can_ctrl_id].ControllerOffset;

        /* Calculate the MB index. When transmit multiplex is enabled search any MB to be free, MBs that have the same ObjectID
        When Multiplex is disabled ,you can have more than one controller, everyone having MBs configured. In this case the index of the MB is different from the
                one in the plugin */
        can_mb_index = Can_ControllerStatuses[can_ctrl_id].FirstTxMBIndex;
        while( (Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_mb_index] != Hth) &&
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
               (can_mb_index < Can_ControlerDescriptorsPtr[can_ctrl_id].MaxMBCount) )
        {
            can_mb_index ++;
        }
#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
        /* Need to find a free MB for transmission. This do-while block is executed only when multiplex transmission is ON because the data can be stored in any MB
                that has the same ObjectID. */
        do
        {
#endif /* (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) */

            /* Is the MB empty?
                 This test is a bit early; the TxGuard is not set yet and someone else can grab this MB before we reserve it
                 but it saves setting the guard on full or cancelled MBs only to discover they are not empty and clearing the guard again. */
                  /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)
            do{
                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06();
                /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                Can_loop = Can_LLD_ForbiddenRegion(can_hw_offset, can_mb_index, can_mb_content);
                SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06();
              }while( 1U == Can_loop);

            if ( FLEXCAN_MBCS_CODETX == (can_mb_content[0] & FLEXCAN_MBCS_CODE))
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else
    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            if ( FLEXCAN_MBCS_CODETX == (uint32)FLEXCAN_MB_READ_CS( can_hw_offset, can_mb_index) )
    #endif /* ERR_IPV_FLEXCAN_0009 */
            {
                /*
                   (CAN212) The function Can_Write shall perform following actions if the hardware transmit object is free: The mutex for that HTH is set to 'signaled';
                         the ID, DLC and SDU are put in a format appropriate for the hardware; All necessary control operations to initiate the transmit are done;
                         The mutex for that HTH is released; The function returns with CAN_OK.
                */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                /* Check whether Can controller supports 64 message buffers */
                if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[can_ctrl_id].Can_NumberOfMB))
                {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                    /* Calculate the index of the IFLAG register and Txguard (index=0 for MB32...MB63, index=1 for MB0...MB31). */
                    can_iflag_reg_index = (uint8)((uint8)can_mb_index >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x01U;
                    /* Get the content of IFLAG register for which corresponds this MB. */
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    can_iflag_reg = ((uint32)0x0U == (uint32)can_iflag_reg_index) ? (uint32)FLEXCAN_IFLAG2_READ(can_hw_offset) : (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                }
                else
                {
                    /* Get the content of IFLAG register for which corresponds this MB. */
                    can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
                }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                /* Get the content of IFLAG register for which corresponds this MB. */
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                /* Calculate the bit in the IFLAG register. */
                can_temp_flag = ((uint32)0x01U) << ((uint32)can_mb_index & FLEXCAN_MASK_32BITS);

                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02();

                /* Test the GUARD MASK and the INTERRUPT FLAG.
                     Cannot operate on locked out MBs (re-entry).. also cannot operate on MBs for which the Tx confirmation has not been sent yet.
                     Below is read-modify-write cycle for TxGuard flag which may be interrupted -> must use SchM_Enter_Can_CAN_EXCLUSIVE_AREA_XX() for preventing broken TxGuard value. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                if ( (uint32)0x0U == (Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] & can_temp_flag) )
#else /* (CAN_MAXMB_SUPPORTED != FLEXCAN_MB_64) */
                if ( (uint32)0x0U == (Can_ControllerStatuses[can_ctrl_id].TxGuard[0] & can_temp_flag) )
#endif /* (CAN_MAXMB_SUPPORTED != FLEXCAN_MB_64) */
                {
                    /* This MB is not signaled as used by another message. */
                    if ( (uint32)0x0U == (can_iflag_reg & can_temp_flag) )
                    {
                        /* Interrupt flag is not set for this MB this meaning MB is not in progress. */

                        /* The mutex for that HTH is set to 'signaled': The guard is 0, the MB is not locked out at the moment -> lock it out. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                        Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] |= can_temp_flag;
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                        Can_ControllerStatuses[can_ctrl_id].TxGuard[0] |= can_temp_flag;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                        /* TxGuard was set without any risk of broken data - now can free the Critical section. */
                        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();

                        /* Is the MB still empty? */
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        if ( FLEXCAN_MBCS_CODETX == (uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index) )
                        {
                            can_mb_messageid = (uint32)PduInfo->id;
                            can_mb_config = (FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXEN | FLEXCAN_MBCS_SRR | (((uint32)PduInfo->length) << (uint32)16U));

                            /* Set-up the MB content for Tx. Remember the PduId for reporting when the frame is transmitted. */
                            Can_ControllerStatuses[can_ctrl_id].TxPduId[can_mb_index] = PduInfo->swPduHandle;

#if (CAN_EXTENDEDID == STD_ON)
                            if ( (can_mb_messageid & FLEXCAN_MBC_ID_IDE) != (uint32)0U)
                            {
                                /* Set the IDE bit in the MBCS register of the MB */
                                can_mb_config |= FLEXCAN_MBCS_IDE;
                                /* Clear the MSB bit of the id - this is used for sending embedded information by CanIf to Can to say if it is an extended or standard message type. */
                                can_mb_messageid &= (~FLEXCAN_MBC_ID_IDE);
                            }
                            else
                            {
#endif /* (CAN_EXTENDEDID == STD_ON) */
                                /* Standard ID - need to shift left 18 bits. */
                                can_mb_messageid <<= FLEXCAN_STANDARD_ID_SHIFT;
#if (CAN_EXTENDEDID == STD_ON)
                            }
#endif /* (CAN_EXTENDEDID == STD_ON) */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_ID_CONFIG( can_hw_offset, can_mb_index, can_mb_messageid);
                            /* Copy the data into the MB memory. The driver will not read from a null pointer SDU. */
                            for ( can_mb_data_byte = (uint8)0U; can_mb_data_byte < PduInfo->length; can_mb_data_byte++)
                            {
                                 /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_MB_DATA_CONFIG( can_hw_offset, can_mb_index, can_mb_data_byte, (PduInfo->sdu)[can_mb_data_byte]);
                            }

                            /* Transmit the Data - now the data should be on Can Bus. Configure the DLC. */
                             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_MB_CS_CONFIG( can_hw_offset, can_mb_index, can_mb_config);

                            /* When the Abort feature is enabled (AEN in MCR is asserted), after the Interrupt Flag is
                            asserted for a MB configured as transmit buffer, the MB is blocked, therefore the CPU is not able to update
                            it until the Interrupt Flag be negated by CPU. It means that the CPU must clear the corresponding IFLAG
                            before starting to prepare this MB for a new transmission or reception.
                            TxGuard is a software flag and IFLAG are hardware flags */

                            /* Clear the guard, end of critical section. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                            Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] &= (uint32)(~can_temp_flag);
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                            Can_ControllerStatuses[can_ctrl_id].TxGuard[0] &= (uint32)(~can_temp_flag);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                            /* Set-up return value to indicate sucessful Tx.
                                The Transmit succesufull operation is signaled to CanIf when IFLAG bit will be handled by polling/interrupt routine (FlexCan_LLD_Process_Rx).*/
                            Out_can_return = CAN_OK;
                        }
                        else
                        /* MB not empty anymore, preempting code has grabbed it before we managed to set the guard bit. Clear the guard bit. */
                        {
                            /*
                               (CAN213) The function Can_Write shall perform no actions if the hardware transmit object is busy with another transmit request for an L-PDU that has higher priority than that for the current request:
                                  - The transmission of the L-PDU with higher priority shall not be cancelled and the function Can_Write is left without any actions.
                                  - The function Can_Write shall return CAN_BUSY.
                            */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                            Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] &= (uint32)(~can_temp_flag);
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                            Can_ControllerStatuses[can_ctrl_id].TxGuard[0] &= (uint32)(~can_temp_flag);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                            /* MB not TX empty anymore, preempting code has grabbed it before we managed to set the guard bit. Clear the guard, end of critical section. */
                            Out_can_return = CAN_BUSY;
                        }
                    }
                    else /* else of "if((uint32)0x0U==(can_iflag_reg&can_temp_flag))" */
                    /* MB is locked because it has the IFLAG bit set. */
                    {
                        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
                        /*
                        The fact that the return value of the function is the same irrespective of whether the MB is locked out or busy with a lower prio message is a deficiency in the AutoSAR spec.
                        CanIf has no way of telling whether the message was cancelled or not in the special case and a priority inversion can occur.
                        */
                        /*
                           (CAN214) The function Can_Write shall return CAN_BUSY if a preemptive call of Can_Write has been issued, that could not be
                                    handled reentrant (i.e. a call with the same HTH).
                        */
                        Out_can_return = CAN_BUSY;
                    }
                }
                else /* else of "if((uint32)0x0U==(Can_ControllerStatuses[can_ctrl_id].TxGuard[0]&can_temp_flag))" */
                {
                    /* MB is locked out because software flag (Guart bit) is set. */
                    Out_can_return = CAN_BUSY;

                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
#if ((CAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_MULTIPLEXED_TRANSMISSION == STD_ON))
                    /* Do not Cancel the locked out message when TXMUX is enabled. */
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    can_mb_lprio_index = Can_ControlerDescriptorsPtr[can_ctrl_id].MaxMBCount;
                    break;
#endif /* ((CAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)) */
                }

            }
            else /* else of "if(FLEXCAN_MBCS_CODETX==(uint32)FLEXCAN_MB_READ_CS(can_hw_offset,can_mb_index))" */
            /* MB is not empty */
            {
                /*
                   (CAN286) The Can module shall initiate a cancellation, when all available hardware transmit objects are busy and an L-PDU with
                            higher priority is requested to be transmitted.
                */

#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
                /* Keep track of the lowest prio message (highest ID). */
    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                can_mb_messageid = ((can_mb_content[0] & (uint32)FLEXCAN_MBCS_IDE) != (uint32)FLEXCAN_MBCS_IDE) ?
                                            ((can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_STANDARD)) >> (uint32)(18U)) :
                                            (can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_EXTENDED));
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                can_mb_messageid = (((uint32)FLEXCAN_MB_READ( can_hw_offset, can_mb_index) & (uint32)FLEXCAN_MBCS_IDE) != (uint32)FLEXCAN_MBCS_IDE) ? /* condition to test */
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                      (uint32)FLEXCAN_MB_READ_ID_STANDARD( can_hw_offset, can_mb_index) : /* value if condition is true */
                                       /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                      (uint32)FLEXCAN_MB_READ_ID_EXTENDED( can_hw_offset, can_mb_index); /* value if condition is false */
    #endif /* ERR_IPV_FLEXCAN_0009 */
  #if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
                    /*
                       (CAN402) The Can module shall support multiplexed transmission mechanisms for devices where either
                                - Multiple transmit hardware objects, which are grouped to a transmit entity can be filled over the same register set,
                                and the microcontroller stores the L-PDU into a free buffer autonomously,
                                or
                                - The Hardware provides registers or functions to identify a free transmit hardware object within a transmit entity.
                        (CAN403) The Can module shall support multiplexed transmission for devices, which send L-PDUs in order of L-PDU priority.
                    */

                /* @violates @ref FlexCan_LLD_c_REF_1 Violates MISRA 2004 Advisory Rule 12.1, se of mixed mode arithmetic. */
                if ( ((uint32)can_mb_lprio_id < (uint32)can_mb_messageid)
    #if (CAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                      || ((uint32)can_mb_lprio_id == (uint32)can_mb_messageid)
    #endif /* (CAN_IDENTICAL_ID_CANCELLATION == STD_ON) */
                    )
                {
                    /* Create a copy of the lowest priority ID and the index of MB which holds it. */
                    /* MISRA-C:2004 12.1 VIOLATION: Refer to REF 1 above */
                    can_mb_lprio_id = can_mb_messageid;
                    can_mb_lprio_index = can_mb_index;
                }

  #else /* (CAN_MULTIPLEXED_TRANSMISSION == STD_OFF) */
                /* If cancellation is enabled and TxMux is disabled, make now the cancellation if it's the case.
                     Check the priority of the current message that is already in the MB (temp_id) with the priority of the new message (PduInfo). */
                if ( ((uint32)can_mb_messageid > (uint32)PduInfo->id)
    #if (CAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                    || ((uint32)can_mb_messageid == (uint32)PduInfo->id)
    #endif
                    )
                {
                    /*
                       (CAN215) The function Can_Write shall perform following actions if the hardware transmit object is busy with another
                    transmit request for an L-PDU that has lower priority than that for the current request:
                    - The transmission of the L-PDU with lower priority shall be cancelled (asynchronously).
                    - The function CAN_Write shall return CAN_BUSY.
                    */
                    Can_LLD_Cancel( can_ctrl_id, can_mb_index);
                }
  #endif /* (CAN_MULTIPLEXED_TRANSMISSION == STD_OFF) */

#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

                /* MB is not empty. */
                Out_can_return = CAN_BUSY;
            }

#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
            /* Increment the MB index. */
            can_mb_index++;

        } while ( (Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_mb_index] == Hth) && (CAN_BUSY == Out_can_return));
#endif /* (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) */


#if ((CAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_MULTIPLEXED_TRANSMISSION == STD_ON))
        /* Was the message scheduled for transmission? */
        if ( CAN_OK != Out_can_return )
        {
            /* Did the search find a lower priority message? */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
            if ( can_mb_lprio_index < Can_ControlerDescriptorsPtr[can_ctrl_id].MaxMBCount)
            {
                /* Calculate the index of the Txguard (index = 0 for MB32...MB63, index = 1 fro MB0...MB31). */
  #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)

    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                /* Check whether Can controller supports 64 message buffers. */
                if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[can_ctrl_id].Can_NumberOfMB))
                {
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                    can_iflag_reg_index = (uint8)(can_mb_lprio_index >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x01U;
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                }
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */

  #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */

                /* Calculate the iflag value. */
                can_temp_flag = ((uint32)0x01U) << ((uint32)can_mb_lprio_index & FLEXCAN_MASK_32BITS);

                /* Cancel the lowest prio message providing it is of lower priority than the current message.
                  Lock the lowest prio MB out, no need to check if it is already locked (it was not locked during the search so it cannot be locked now). */
  #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)

    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                /* Check whether Can controller supports 64 message buffers. */
                if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[can_ctrl_id].Can_NumberOfMB))
                {
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                    Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] |= can_temp_flag;
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                }
                else
                {
                    Can_ControllerStatuses[can_ctrl_id].TxGuard[0U] |= can_temp_flag;
                }
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
  #else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                Can_ControllerStatuses[can_ctrl_id].TxGuard[0U] |= can_temp_flag;
  #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

        #if defined(ERR_IPV_FLEXCAN_0009)
            #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                can_mb_messageid = ((can_mb_content[0] & (uint32)FLEXCAN_MBCS_IDE) != (uint32)FLEXCAN_MBCS_IDE) ?
                                                                                       ((can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_STANDARD)) >> (uint32)(18U)) :
                                                                                       (can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_EXTENDED));
            #else
                #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
            #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
        #else
                /* @violates @ref FlexCan_LLD_c_REF_1 Violates MISRA 2004 Advisory Rule 12.1, se of mixed mode arithmetic. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* Check if the current message is standard to shift accordingly. */
                can_mb_messageid = ((FLEXCAN_MB_READ( can_hw_offset, can_mb_lprio_index) & (uint32)FLEXCAN_MBCS_IDE) != (uint32)FLEXCAN_MBCS_IDE) ? /* condition to test */
                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    (uint32)FLEXCAN_MB_READ_ID_STANDARD( can_hw_offset, can_mb_lprio_index) : /* value if condition is true */
                                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                    (uint32)FLEXCAN_MB_READ_ID_EXTENDED( can_hw_offset, can_mb_lprio_index); /* value if condition is false */
        #endif /* ERR_IPV_FLEXCAN_0009 */
                /* Check the priority of the current message is greater that the one requested to send. */
                if ( ((uint32)can_mb_messageid > (uint32)PduInfo->id)
  #if (CAN_IDENTICAL_ID_CANCELLATION == STD_ON)
                    || ((uint32)can_mb_messageid == (uint32)PduInfo->id)
  #endif
                    )
                {
                    /* Message currently in the MB has lower priority, cancel it.
                          If the message is transmitted in the meantime, the MB will be blocked until the interrupt flag is cleared.
                          However an interrupt may come in reaction to the flag and send Tx confirmation -> Can_Cancel must check that. */
                    Can_LLD_Cancel( can_ctrl_id, can_mb_lprio_index);
                }

                /* Unlock the MB TxGuard. */
  #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                /* Check whether Can controller supports 64 message buffers. */
                if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[can_ctrl_id].Can_NumberOfMB))
                {
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                    Can_ControllerStatuses[can_ctrl_id].TxGuard[can_iflag_reg_index] &= (uint32)(~can_temp_flag);
    #if (CAN_MIX_MB_SUPPORT == STD_ON)
                }
                else
                {
                    Can_ControllerStatuses[can_ctrl_id].TxGuard[0U] &= (uint32)(~can_temp_flag);
                }
    #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
  #else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                Can_ControllerStatuses[can_ctrl_id].TxGuard[0U] &= (uint32)(~can_temp_flag);
  #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
            }
        }
#endif /* ((CAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)) */

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Write if polling is selected or from ISR when Interrupt mode selected.
* @details        Processes Tx interrupt flags.
*               This routine is called by:
*                - Can_LLD_Process_Tx() from Can.c file.
*                - Can_LLD_MainFunction_Write() from Can_FlexCan_LLD.c file.
*                - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process.
* @param[in]      mbindex_end last MB to process.
*
* @pre            MB is configured for Tx.
* @post           CanIf is informed with cancellation or transmit success.
*
* @implements     DCAN01116, DCAN01117, DCAN01118, DCAN01119, DCAN01120, DCAN02202
*
*/
FUNC (void, CAN_CODE) FlexCan_LLD_Process_Tx( CONST(uint8, CAN_CONST) controller,
                                          CONST(uint8, CAN_CONST) mbindex_start,
                                          CONST(uint8, CAN_CONST) mbindex_end )
    {
        /* Variable for indexing the MBs. */
        VAR(uint8, AUTOMATIC)            can_mb_index = 0U;
        /* Pointer to the MBs structure configuration. */
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
        VAR(Can_PtrMBConfigContainerType, AUTOMATIC) can_ptrMBConfigContainer = NULL_PTR;
        /* Unique identifier of a PDU within a software module */
        VAR(PduIdType, AUTOMATIC) Can_PduId;
        /* Store the basic information about a PDU */
        VAR(PduInfoType, AUTOMATIC) Can_CbkPduInfo;
#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)            can_hw_offset = 0U;
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        /* Variable for determining the IFLAG register for every MB: IFLAG1 or IFLAG2. */
        VAR(uint8, AUTOMATIC)            can_iflag_reg_index = 0U;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
        /* Variable for determining the mash bit in the IFLAGx register for current MB. */
        VAR(uint32, AUTOMATIC)           can_temp_flag = 0U;
        /* Variable for storing the value of IFLAG register. */
        VAR(uint32, AUTOMATIC)           can_iflag_reg = 0U;
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
        /* Variable for storing the ConfigReg of the MB. */
        VAR(uint32, AUTOMATIC)           can_mb_config = 0U;
        /* Variable for storing the data. */
        VAR(uint8, AUTOMATIC)            can_mb_data[8];
        /* Index for data byte of MB. */
        VAR(uint8, AUTOMATIC)            can_databyte_index = 0U;
        /* Get the address of the MBConfigContainer in local pointer */
        can_ptrMBConfigContainer = &(Can_CurrentConfigPtr->MBConfigContainer);
#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

        /* Loop through all MBs to process. */
        for ( can_mb_index = mbindex_start; can_mb_index <= mbindex_end; can_mb_index++)
        {
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            /* Check whether Can controller supports 64 message buffers */
            if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
            {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                /* Calculate the index of the IFLAG register. */
                can_iflag_reg_index = (uint8)((uint8)can_mb_index >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x01U;
                /* Get the content of IFLAG register for which corresponds this MB. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                can_iflag_reg = ((uint32)0x0U == (uint32)can_iflag_reg_index) ? (uint32)FLEXCAN_IFLAG2_READ(can_hw_offset) : (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
            }
            else
            {
                can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
            }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
            /* Calculate the bit in the IFLAG register. */
            can_temp_flag = ((uint32)0x01U) << ((uint32)can_mb_index & FLEXCAN_MASK_32BITS);

            /* Check the interrupt flag of the current MB. */
            if ( (can_iflag_reg & can_temp_flag) != (uint32)0x0U)
            {
                /* The interrupt flag is set, message was either transmitted or cancelled.
                     This code does not check whether the TxGuard is set.
                     It does not have to do the check as it only operates on MBs with the interrupt flag set and CanWrite does not
                        operate on MBs which have the interrupt flag set.
                     Set the TxGuard. */

                /*
                   (CAN031) The function Can_MainFunction_Write shall perform the polling of TX confirmation and TX cancellation confirmation when CanTxProcessing is set to POLLING.
                */
    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref FlexCan_LLD_c_REF_14 MISRA 2004 Required Rule,Side effects of && and || */
                if((((uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index)) == FLEXCAN_MBCS_CODETX) && ( (Can_HwHandleType)can_mb_index == Can_ControllerStatuses[controller].CancelMBIndex))
                {
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
        #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref FlexCan_LLD_c_REF_14 MISRA 2004 Required Rule,Side effects of && and || */
                if((((uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index)) == FLEXCAN_MBCS_CODETX) && ( (Can_HwHandleType)can_mb_index == Can_ControllerStatuses[controller].CancelMBIndex))
                {
        #else
            #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                switch ( (uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index) )
                {
    #endif
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
                    /* The frame was aborted (cancelled). */
    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
                /*  {workaround - errata  specific code} */
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
        #if (CAN_USE_MCR_ABORT_ENABLE== STD_ON)
        /*  {workaround - errata  specific code} */
        #else
            #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
        #endif
    #else
                    case ( FLEXCAN_MBCS_CODETX | FLEXCAN_MBCS_CODETXABORT):
                    {
    #endif
                          /* The interrupt flag is set, message was either transmitted or cancelled.
                          This code does not check whether the TxGuard is set.
                          It does not have to do the check as it only operates on MBs with the interrupt flag set and CanWrite does not
                            operate on MBs which have the interrupt flag set.
                          Set the TxGuard. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        /* Check whether Can controller supports 64 message buffers */
                        if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                        {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                            Can_ControllerStatuses[controller].TxGuard[can_iflag_reg_index] |= can_temp_flag;
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        }
                        else
                        {
                            Can_ControllerStatuses[controller].TxGuard[0] |= can_temp_flag;
                        }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                        Can_ControllerStatuses[controller].TxGuard[0] |= can_temp_flag;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                        /* Check if Can_Write is currently trying to cancel this MB. If so, tell it that there is no need as the MB has just transmitted (or cancelled). */
                        if ( (Can_HwHandleType)can_mb_index == Can_ControllerStatuses[controller].CancelMBIndex)
                        {
                            Can_ControllerStatuses[controller].CancelMBIndex = can_ptrMBConfigContainer->MessageBufferConfigCount;
                        }

                        /* Read Control and Status Register of the MB. */
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        can_mb_config = (uint32)FLEXCAN_MB_READ( can_hw_offset, can_mb_index);

                        /* Transfer the DLC. */
                        Can_CbkPduInfo.SduLength = (uint32)((can_mb_config & FLEXCAN_MBCS_LENGTH) >> FLEXCAN_MBCS_LENGTH_SHIFT);

                        /*
                           (CAN276) The function Can_Write shall store the swPduHandle that is given inside the parameter PduInfo until the Can module
                                   calls the CanIf_TXConfirmation for this request where the swPduHandle is given as parameter.
                        */
                        Can_PduId = Can_ControllerStatuses[controller].TxPduId[can_mb_index];

                        /*
                           (CAN059) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                                    the CAN data byte which is sent out last is array element 7.
                        */
                        for ( can_databyte_index = (uint8)0U; can_databyte_index < Can_CbkPduInfo.SduLength; can_databyte_index++)
                        {
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            can_mb_data[can_databyte_index] = FLEXCAN_MB_READ_DATA_BYTE (can_hw_offset, can_mb_index, can_databyte_index);
                        }


                        /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */

                        Can_CbkPduInfo.SduDataPtr = can_mb_data;

                        /* Clear the interrupt flag - w1c. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        /* Check whether Can controller supports 64 message buffers */
                        if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                        {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_IFLAG_CONFIG( can_hw_offset, can_iflag_reg_index, can_temp_flag);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        }
                        else
                        {
                            FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
                        }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                        /* Clear the cancellation flag. */
                         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_MB_CS_CONFIG( can_hw_offset, can_mb_index, (uint32)((can_mb_config & (uint32)(~FLEXCAN_MBCS_CODE)) | FLEXCAN_MBCS_CODETX) );

                        /* Release the MB, from now on the MB is free for Tx -> Clear TxGuard. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        /* Check whether Can controller supports 64 message buffers */
                        if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                        {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                            Can_ControllerStatuses[controller].TxGuard[can_iflag_reg_index] &= (uint32)(~can_temp_flag);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        }
                        else
                        {
                            Can_ControllerStatuses[controller].TxGuard[0U] &= (uint32)(~can_temp_flag);
                        }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
                        Can_ControllerStatuses[controller].TxGuard[0U] &= (uint32)(~can_temp_flag);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                        /*
                           (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                                    The driver only sees the CanIf module as origin and destination.
                        */
                        /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */

                        CanIf_CancelTxConfirmation(Can_PduId , &Can_CbkPduInfo);

    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
                    /*  {workaround - errata  specific code} */
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
        #if (CAN_USE_MCR_ABORT_ENABLE== STD_ON)
                        /*  {workaround - errata  specific code} */
        #else
            #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
                    }
                        break;
    #endif

#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
                }
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref FlexCan_LLD_c_REF_14 MISRA 2004 Required Rule,Side effects of && and || */
                else if((((uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index)) == FLEXCAN_MBCS_CODETX) && ((Can_HwHandleType)can_mb_index != Can_ControllerStatuses[controller].CancelMBIndex))
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
          #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
        #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
                    }
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref FlexCan_LLD_c_REF_14 MISRA 2004 Required Rule,Side effects of && and || */
                    else if((((uint32)FLEXCAN_MB_READ_CS(can_hw_offset, can_mb_index)) == FLEXCAN_MBCS_CODETX) && ((Can_HwHandleType)can_mb_index != Can_ControllerStatuses[controller].CancelMBIndex))
          #else
            #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
                    /* Frame was transmitted */
                    case ( FLEXCAN_MBCS_CODETX ):
    #endif
                    {
                        /* Clear the interrupt flag - w1c. */
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        /* Check whether Can controller supports 64 message buffers */
                        if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                        {
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_IFLAG_CONFIG( can_hw_offset, can_iflag_reg_index, can_temp_flag);
  #if (CAN_MIX_MB_SUPPORT == STD_ON)
                        }
                        else
                        {
                            FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
                        }
  #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                        /*
                           (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                                    The driver only sees the CanIf module as origin and destination.
                        */
                        CanIf_TxConfirmation( Can_ControllerStatuses[controller].TxPduId[can_mb_index]);
                    }
    /*
    * @ errata ERR_IPV_FLEXCAN_0002 software errata - FlexCAN: Abort request blocks the CODE field.
    */
    #if defined(ERR_IPV_FLEXCAN_0002)
      #if (ERR_IPV_FLEXCAN_0002== STD_ON)
                else /* error condition, this should never occur */
                {
                        /* This case should never occurs. */
                        Cer_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_DEFAULT);
                        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                              Cer_ReportError() function implementation */
                }
      #else
        #error : the define ERR_IPV_FLEXCAN_0002 must not be STD_OFF
      #endif
    #elif defined(CAN_USE_MCR_ABORT_ENABLE)
        #if (CAN_USE_MCR_ABORT_ENABLE == STD_ON)
                else /* error condition, this should never occur */
                {
                        /* This case should never occurs. */
                        Cer_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_DEFAULT);
                        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                              Cer_ReportError() function implementation */
                }
      #else
        #error : the define CAN_USE_MCR_ABORT_ENABLE must not be STD_OFF
      #endif
    #else
                        break;
                    default:
                        /* This case should never occurs. */
                        Cer_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_DEFAULT);
                        /* Error condition, this should never occur. */
                        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                              Cer_ReportError() function implementation */
                        break;
                } /* end switch */
    #endif
            }
        }
    }


/*================================================================================================*/
/**
* @brief          Service to perform the polling of TX confirmation and TX cancellation confirmation
* @details        This routine is called by:
*               - Can_MainFunction_Write() from Can.c file.
*
* @pre            The controller must be configured for transmit in polling mode and at least one MB is configured for Tx.
* @post           Process the transmission data in case of availability.
*
* @implements     DCAN01116, DCAN01117, DCAN01118, DCAN01119, DCAN01120, DCAN02202
*
*/
#if (CAN_TXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_LLD_MainFunction_Write(void)
    {

        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC)   can_ctrl_index = 0U;
        /* First MB to process. */
        VAR(uint8, AUTOMATIC)   can_mb_first = 0U;
        /* Last MB to process. */
        VAR(uint8, AUTOMATIC)   can_mb_last = 0U;

        /* Loop through all configured controller descriptors. */
        for ( can_ctrl_index = 0U; can_ctrl_index < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_ctrl_index++)
        {
            /* Check whether the controller is enabled and whether Tx polling is used for this controller. */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( (FLEXCAN_NULL_OFFSET != Can_ControlerDescriptorsPtr[can_ctrl_index].ControllerOffset) &&
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                 ((uint32)0U != (CAN_CONTROLLERCONFIG_TXPOL_EN & (Can_ControlerDescriptorsPtr[can_ctrl_index].Options))) &&
                 /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                 ((uint8)0U != (Can_ControlerDescriptorsPtr[can_ctrl_index].MaxMBCount)) )
            {
                /* Init indexes that should be parsed for polling mode for current controller.
                  "FirstTxMBIndex" and "MaxMBCount" are updated considering RxFifo. */
                can_mb_first = (uint8)Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex;
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                can_mb_last = (uint8)Can_ControlerDescriptorsPtr[can_ctrl_index].MaxMBCount - (uint8)1U;

                /* Enabled & TxPoll used. Process Tx interrupt flags. Start with the first Tx MB and finish at the last used MB. */
                FlexCan_LLD_Process_Tx( (uint8)can_ctrl_index, (uint8)can_mb_first, (uint8)can_mb_last );
            }
        }
    }

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to writepoll
* @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Send the data from that MB that is configured for Tx.
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_MainFunction_Multiple_Write_Poll( VAR(uint8, AUTOMATIC) writepoll)
    {
        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC)  can_ctrl_id = 0U;
        /* First MB to process. */
        VAR(uint8, AUTOMATIC)  can_mb_index = 0U;
        /* Can Object ID to process. */
        VAR(uint32, AUTOMATIC)  can_object_id = 0U;
        /* Can Process Index of MB for the controller to process. */
        VAR(uint8, AUTOMATIC)  can_tx_process_index[CAN_MAXCTRL_SUPPORTED];

        if ( NULL_PTR != Can_CurrentConfigPtr )
        {
            #if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* Test whether the driver is already initialised. */
                if ( CAN_UNINIT == Can_DriverStatus )
                {
                    /*
                       (CAN179) If development error detection for the module Can is enabled: The function Can_MainFunction_Write shall raise
                               the error CAN_E_UNINIT if the driver is not yet initialized.
                    */
                    Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_WRITE, (uint8)CAN_E_UNINIT);
                }
                else
                {
            #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                    /* initialise the can_tx_process_index for the configured controller. */
                    for ( can_ctrl_id = (uint8)0U; can_ctrl_id < CAN_MAXCTRL_SUPPORTED; can_ctrl_id++)
                    {
                        can_tx_process_index[can_ctrl_id] = 0U;
                        #if (CAN_RXFIFO_ENABLE == STD_ON)
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                        if ( CAN_CONTROLLERCONFIG_RXFIFO == ((uint32)(Can_ControlerDescriptorsPtr[can_ctrl_id].Options) & CAN_CONTROLLERCONFIG_RXFIFO) )
                        {
                            /* Processing MB must start from index 8 if RxFifo is enabled when configure MBs. */
                            can_tx_process_index[can_ctrl_id] = FLEXCAN_FIFO_MB_COUNT;
                        }
                        #endif /* #if (CAN_RXFIFO_ENABLE == STD_ON) */
                    }
                    /* Parse through all TX configured message buffer */
                    for ( can_mb_index = (uint8)0U; can_mb_index < (uint8)Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigCount; can_mb_index++)
                    {
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        can_ctrl_id = Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].ControllerId;
                        /*  Poll only the Tx MB which is referenced by Can_LLD_MainFunction_Multiple_Write_Poll */
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        if ((writepoll == Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].CanMainFuncRWPeriodRef) &&
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            (FLEXCAN_NULL_OFFSET != Can_ControlerDescriptorsPtr[can_ctrl_id].ControllerOffset) &&
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            ((uint32)0U != (CAN_CONTROLLERCONFIG_TXPOL_EN & (Can_ControlerDescriptorsPtr[can_ctrl_id].Options))) &&
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            (CAN_TRANSMIT == (Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].MBType )))
                        {
                            /* CanOnjectID of the polled MB */
                             /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            can_object_id = (Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].HWObjID );
/* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            while ((can_object_id != (Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_tx_process_index[can_ctrl_id]])) && (can_tx_process_index[can_ctrl_id] < (Can_ControlerDescriptorsPtr[can_ctrl_id].MaxMBCount)))
                            {
                                /* increase the can_tx_process_index to check next can_object_id present */
                                can_tx_process_index[can_ctrl_id]++;
                            }
                            if (can_object_id == Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_tx_process_index[can_ctrl_id]])
                            {
                                /* Enabled & TxPoll used : process Tx interrupt flags, */
                                FlexCan_LLD_Process_Tx( (uint8)can_ctrl_id, (uint8)can_tx_process_index[can_ctrl_id], (uint8)can_tx_process_index[can_ctrl_id]);
                                /* increase the can_tx_process_index to check next can_object_id present */
                                can_tx_process_index[can_ctrl_id]++;
                            }
                        }
                    }
            #if (CAN_DEV_ERROR_DETECT == STD_ON)
                }
            #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        }
    }
#endif /* (CAN_TXPOLL_SUPPORTED == STD_ON) */



/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Read if polling is selected or from ISR when Interrupt mode selected.
* @details        Processes Rx interrupt flags.
                  This routine is called by:
                    - Can_LLD_Process_Rx() from Can.c file
                    - Can_LLD_MainFunction_Read() from Can_FlexCan_LLD.c file
                    - Can_IsrFC##FC##_UNI() / Can_IsrFC##FC##_##Name() from Can_Irq.c file
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process
* @param[in]      mbindex_end last MB to process
*
* @pre            MB is configured for Rx.
* @post           Inform CanIf in case a data frame was received.
*
* @implements     DCAN01121, DCAN01122, DCAN01123, DCAN01124, DCAN01140
*
*/
FUNC (void, CAN_CODE) FlexCan_LLD_Process_Rx( CONST(uint8, CAN_CONST) controller,
                                          CONST(uint8, CAN_CONST) mbindex_start,
                                          CONST(uint8, CAN_CONST) mbindex_end )
    {
        /* Variable for indexing the MBs. */
        VAR(Can_HwHandleType, AUTOMATIC)      can_mb_index = 0U;
        /* Number of data bytes. */
        VAR(uint8, AUTOMATIC)      can_mb_data_length = 0U;
        /* Physical data bytes. */
        VAR(uint8, AUTOMATIC)      can_mb_data[8];
        /* Index for data byte of MB. */
        VAR(uint8, AUTOMATIC)      can_databyte_index = 0U;
        /* Variable for storing the Hrh. */
        VAR(Can_HwHandleType, AUTOMATIC)      can_mb_hrh = 0U;
        /* Variables for storing the CanID. */
        VAR(Can_IdType, AUTOMATIC) can_mb_messageid = 0U;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)      can_hw_offset = 0U;
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        /* Variable for determining the IFLAG register for every MB: IFLAG1 or IFLAG2. */
        VAR(uint8, AUTOMATIC)      can_iflag_reg_index = 0U;
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64) */
        /* Variable for determining the mash bit in the IFLAGx register for current MB. */
        VAR(uint32, AUTOMATIC)     can_temp_flag = 0U;
        /* Variable for storing the value of IFLAG register. */
        VAR(uint32, AUTOMATIC)     can_iflag_reg = 0U;
        /* Variable for storing the ConfigReg of the MB. */
        VAR(uint32, AUTOMATIC)     can_mb_config = 0U;
        /* Is set when process an warning or overflow for RxFifo only. */
        VAR(uint8, AUTOMATIC)      can_mb_nodata = 0U;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Variable to store the state of DET error*/
        VAR(uint8, AUTOMATIC)      Det_Error_Occoured = 0U;
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */


#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
        /* Variable for region in Can Frame */
        VAR(uint32, AUTOMATIC)     Can_byte_mask = 0x000000FFU;
        VAR(uint8, AUTOMATIC)  Can_loop = 1U;
        VAR(uint32, AUTOMATIC) can_mb_content[4];
    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif
#endif
        MB_Busy = 0U;
        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

#if ((CAN_ISROPTCODESIZE == STD_OFF) && (CAN_RXPOLL_SUPPORTED == STD_OFF))
    #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        if(mbindex_start >= FLEXCAN_MB_32)
        {
            /* Get the content of IFLAG2 register for which corresponds this MB. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_iflag_reg = (uint32)FLEXCAN_IFLAG2_READ(can_hw_offset);
        }
        else
        {
    #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */
            /* Get the content of IFLAG1 register for which corresponds this MB. */
             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
    #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        }
    #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */
#endif /* ((CAN_ISROPTCODESIZE == STD_OFF) && (CAN_RXPOLL_SUPPORTED == STD_OFF))*/
        /*
        Loop through all MBs to process.
            Phase1: If RXFifo is activated Overflow and Warning interrupts are processed separated because implies no data transfer.
            Phase2: Frame Avaibale Fifo and all other MB interrupts are processes after and have the logic of normal data read from buffer and transmit to CanIf.
        */
        /*for ( can_mb_index = mbindex_start; can_mb_index <= mbindex_end; can_mb_index++)*/
        can_mb_index = mbindex_start;
        while(can_mb_index <= mbindex_end)
        {
#if ((CAN_ISROPTCODESIZE == STD_ON)|| (CAN_RXPOLL_SUPPORTED == STD_ON))
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
#if (CAN_MIX_MB_SUPPORT == STD_ON)
            /* Check whether Can controller supports 64 message buffers */
            if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
            {
#endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                /* Calculate the Index of the IFLAG register. */
                can_iflag_reg_index = (uint8)((uint8)can_mb_index >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x1U;
                /* Get the content of IFLAG register for which corresponds this MB. */
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                can_iflag_reg = ((uint32)can_iflag_reg_index == (uint32)0x0U) ? (uint32)FLEXCAN_IFLAG2_READ(can_hw_offset) : (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
#if (CAN_MIX_MB_SUPPORT == STD_ON)
            }
            else
            {
                /* Get the content of IFLAG register for which corresponds this MB. */
                can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
            }
#endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
            /* Get the content of IFLAG register for which corresponds this MB. */
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            can_iflag_reg = (uint32)FLEXCAN_IFLAG1_READ(can_hw_offset);
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
#endif /* ((CAN_ISROPTCODESIZE == STD_ON)|| (CAN_RXPOLL_SUPPORTED == STD_ON)) */
            /* Calculate the Flag value. */
            can_temp_flag = ((uint32)0x1U) << ((uint32)can_mb_index & FLEXCAN_MASK_32BITS);

                /* Check the interrupt flag. */
                if ( (uint32)0x0U != (can_iflag_reg & can_temp_flag) )
                {

    #if (CAN_ISROPTCODESIZE == STD_OFF)
        #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
                    /* Calculate the Index of the IFLAG register. */
                    can_iflag_reg_index = (uint8)((uint8)can_mb_index >> FLEXCAN_MB_SHIFT5BIT) ^ (uint8)0x1U;
        #endif /* CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 */
    #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #if (CAN_RXFIFO_ENABLE == STD_ON)
                    /* ********************* Phase1 ********************* */
                    /* Check if "mbindex" corresponds to flags for Int Fifo status: Overflow or Warning.
                                If Fifo is disabled, then current flags are normal MB interrupt bits. */
                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                    if ( CAN_CONTROLLERCONFIG_RXFIFO == ((Can_ControlerDescriptorsPtr[controller].Options) & CAN_CONTROLLERCONFIG_RXFIFO) )
                    {
                        if ( FLEXCAN_FIFOOVERFLOW_INT_INDEX == (uint32)can_mb_index )
                        {
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
                            if (NULL_PTR != Can_ControlerDescriptorsPtr[controller].Can_RxFifoOverflowNotification)
                            {
                                /* Call the handling routine for Overflow fifo event. */
                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
                                Can_ControlerDescriptorsPtr[controller].Can_RxFifoOverflowNotification();
                            }
                            can_mb_nodata = (uint8)1U;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                            /* set a variable to indicate overrun occured*/
                            Det_Error_Occoured = (uint8)1U;
                            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
#endif
                        }

                        if ( FLEXCAN_FIFOWARNING_INT_INDEX == (uint32)can_mb_index )
                        {
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used*/
                            if (NULL_PTR != Can_ControlerDescriptorsPtr[controller].Can_RxFifoWarningNotification)
                            {
                                /* Call Rx FIFO warning Notification. */
                                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                                Can_ControlerDescriptorsPtr[controller].Can_RxFifoWarningNotification();
                            }
                            can_mb_nodata = (uint8)1U;
                        }

                        if ( FLEXCAN_FIFOFRAME_INT_INDEX == (uint32)can_mb_index )
                        {
                            /* Access data available in MB0 when there is Buffer MB5 Interrupt - Frames Available in FIFO. */
                            can_mb_hrh = (Can_HwHandleType)can_mb_index;
                            can_mb_index = (Can_HwHandleType)0x0U;
                        }
                    }
    #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

                    /* ********************* Phase2 ********************* */
                    /* Check the interrupt flag. Execute this only if it is MB dat or RxFifo data. */
                    if (can_mb_nodata == (uint8)0U)
                    {
    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                        do{
                            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03();
                            /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                            /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                            Can_loop = Can_LLD_ForbiddenRegion(can_hw_offset, can_mb_index, can_mb_content);
                            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03();
                          }while( 1U == Can_loop);

                        can_mb_config = can_mb_content[0];
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else
                     /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                     can_mb_config = (uint32)FLEXCAN_MB_READ(can_hw_offset, can_mb_index);
                     if(FLEXCAN_MBCS_CODERXBUSY == (can_mb_config & FLEXCAN_MBCS_CODERXBUSY))
                     {
                        MB_Busy = 1U;
                     }
    #endif /* ERR_IPV_FLEXCAN_0009 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                        /* CAN395: If the development error detection for the Can module is enabled, the Can module shall raise the error CAN_E_DATALOST in
                                   case of OVERWRITE or OVERRUN event detection.*/
                        /* If FIFO is ON, then we must skip the first 8 MBs
                           If FIFO is OFF, we will check all MBs */
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                        if (CAN_CONTROLLERCONFIG_RXFIFO == ((Can_ControlerDescriptorsPtr[controller].Options) & CAN_CONTROLLERCONFIG_RXFIFO))
                        {
                            if (8U < (uint8)can_mb_index)
                            {
                                can_mb_nodata = (uint8)1U;
                            }
                        }
                        else
                        {
                            can_mb_nodata = (uint8)1U;
                        }
                        if ( (can_mb_nodata == (uint8)1U) && (FLEXCAN_MBCS_CODERXOVRR == (can_mb_config & FLEXCAN_MBCS_CODE)) )
                        {
                            /* set a variable to indicate overrun occured*/
                            Det_Error_Occoured = (uint8)1U;
                            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_DATALOST);
                            /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                                                                           unless the CPU reads the C/S word of another MB.*/
                            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_TIMER_READ(can_hw_offset);
                        }
                            can_mb_nodata = (uint8)0U;
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                     if( MB_Busy == 0U )
                     {
                            /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time.
                                Read the DLC; this read access also locks the MB. */
                            can_mb_data_length = (uint8)( (can_mb_config & FLEXCAN_MBCS_LENGTH) >> FLEXCAN_MBCS_LENGTH_SHIFT);
                        if( can_mb_data_length > 8U )
                        {
                            can_mb_data_length = 8U;
                        }

                            /* Get the ID of the message.
                              For extended IDs the most significant bit mus tbe set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/

    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)
                        can_mb_messageid = ((uint32)0x0U == (can_mb_config & (uint32)FLEXCAN_MBCS_IDE)) ? /* condition to test */
                                                (Can_IdType)(( can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_STANDARD)) >> (uint32)(18U) ) : /* value if condition is true */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                (Can_IdType)(can_mb_content[1] & FLEXCAN_MBID_ID_EXTENDED); /* value if condition is false */

                        /*
                           (CAN060) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                                   the CAN data byte which is sent out last is array element 7.
                           (CAN299) The Can module shall copy the L-SDU in a shadow buffer after reception, if the RX buffer cannot be protected (locked)
                                   by CAN Hardware against overwriting by a newly received message.
                           (CAN300) The Can module shall copy the L-SDU in a shadow buffer, if the CAN Hardware is not globally accessible.
                        */
                        /* can_mb_content[2] and can_mb_content[3] stores 4 bytes. Thats why we have to split them. */
                        for ( can_databyte_index = (uint8)0U; can_databyte_index < can_mb_data_length; can_databyte_index++)
                        {
                            /* Copy the data  */
                            if (can_databyte_index < 4U) /* the bytes from 0 to 3 are stored in  can_mb_content[2] */
                            {
                                /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                                can_mb_data[can_databyte_index] = (uint8)((can_mb_content[2] >> (8 * (3 - can_databyte_index)))  & Can_byte_mask);
                            }
                            else /* the bytes from 4 to 7 are stored in can_mb_content[3] */
                            {

                                /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                                can_mb_data[can_databyte_index] = (uint8)((can_mb_content[3] >> (8 * (7 - can_databyte_index)))  & Can_byte_mask);
                            }
                        }
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else
                            can_mb_messageid = ((uint32)0x0U == (can_mb_config & (uint32)FLEXCAN_MBCS_IDE)) ? /* condition to test */
                             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                (Can_IdType)((uint32)FLEXCAN_MB_READ_ID_STANDARD( can_hw_offset, can_mb_index)) : /* value if condition is true */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                (Can_IdType)((uint32)FLEXCAN_MB_READ_ID_EXTENDED( can_hw_offset, can_mb_index) | FLEXCAN_MBC_ID_IDE); /* value if condition is false */

                            /*
                               (CAN060) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                                       the CAN data byte which is sent out last is array element 7.
                               (CAN299) The Can module shall copy the L-SDU in a shadow buffer after reception, if the RX buffer cannot be protected (locked)
                                       by CAN Hardware against overwriting by a newly received message.
                               (CAN300) The Can module shall copy the L-SDU in a shadow buffer, if the CAN Hardware is not globally accessible.
                            */
                            for ( can_databyte_index = (uint8)0U; can_databyte_index < can_mb_data_length; can_databyte_index++)
                            {
                                /* Copy the data  */
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                can_mb_data[can_databyte_index] = FLEXCAN_MB_READ_DATA_BYTE (can_hw_offset, can_mb_index, can_databyte_index);
                            }
    #endif /* ERR_IPV_FLEXCAN_0009) */
                        /* Determine Hrh of the message. */
        #if (CAN_RXFIFO_ENABLE == STD_ON)
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used*/
                            if (CAN_CONTROLLERCONFIG_RXFIFO == ((Can_ControlerDescriptorsPtr[controller].Options) & CAN_CONTROLLERCONFIG_RXFIFO))
                            {
                                if(can_mb_index == (uint8)0U)
                                {
                                    /* Restore the MB index. */
                                    can_mb_index = (Can_HwHandleType)can_mb_hrh;
                                }

                                if(can_mb_index < FLEXCAN_FIFO_MB_COUNT)
                                {
                                    /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                                    can_mb_hrh = Can_CurrentConfigPtr->ControlerDescriptors[controller].FirstHrhIndex;
                                }
                                else
                                {
                                /* determine Hrh of the message , required to skip 1-7 MB index to calculate the correct hrh in case of
                                                                              FIFO enabled for message buffers greater than 7 */
                                    can_mb_hrh = (Can_HwHandleType)Can_ControllerStatuses[controller].Can_MBMapping[can_mb_index];
                                }
                            }
                            else
                            {
        #endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */
                                can_mb_hrh = (Can_HwHandleType)Can_ControllerStatuses[controller].Can_MBMapping[can_mb_index];
        #if (CAN_RXFIFO_ENABLE == STD_ON)
                            }
        #endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */


                            /* Clear the interrupt flag - w1c. */
        #if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
          #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            /* Check whether Can controller supports 64 message buffers. */
                            if ( FLEXCAN_MB_64 == (Can_ControlerDescriptorsPtr[controller].Can_NumberOfMB))
                            {
          #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
                                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                FLEXCAN_IFLAG_CONFIG( can_hw_offset, can_iflag_reg_index, can_temp_flag);
          #if (CAN_MIX_MB_SUPPORT == STD_ON)
                            }
                            else
                            {
                                FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
                            }
          #endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
        #else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_IFLAG1_CONFIG( can_hw_offset, can_temp_flag);
        #endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

                            /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                                unless the CPU reads the C/S word of another MB.*/
                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                            FLEXCAN_TIMER_READ( can_hw_offset);
                            
                            #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                            /* [CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
                            /* @violates @ref Can_Flexcan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                            /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                            if (TRUE == CanLPduReceiveCalloutFunction(u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
                            {
                            #endif
                               /*
                                  (CAN279)  On L-PDU reception, the Can module shall call the RX indication callback function with ID, DLC and pointer to the L-SDU buffer as parameter.
                               */
                               /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                               
                               CanIf_RxIndication( can_mb_hrh, can_mb_messageid, can_mb_data_length, can_mb_data);

                            #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
                            }
                            #endif
                        }
                    }
                }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            if( Det_Error_Occoured == (uint8)1U )
            {
                can_mb_index = mbindex_end;
                Det_Error_Occoured = (uint8)0U;
            }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            can_mb_index++;
        } /* end for */
    }



/*================================================================================================*/
/**
* @brief          Service to perform the polling of RX indications.
* @details        Processes Rx interrupt flags.
*                 This routine is called by:
*                    - Can_MainFunction_Read() from Can.c file.
*
* @pre            The controller must be configured for receive in polling mode and at least one MB is configured for Rx.
* @post           Process the reception data in case of availability.
*
* @implements     DCAN01125
*
*/
#if (CAN_RXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_LLD_MainFunction_Read( void)
    {

        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC)  can_ctrl_index = 0U;
        /* First MB to process. */
        VAR(uint8, AUTOMATIC)  can_mb_first = 0U;
        /* Last MB to process. */
        VAR(uint8, AUTOMATIC)  can_mb_last = 0U;

        /* Loop through all configured controller descriptors. */
        for ( can_ctrl_index = (uint8)0U; can_ctrl_index < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_ctrl_index++)
        {
            /*
               (CAN108) The function Can_MainFunction_Read shall perform the polling of RX indications when CanRxProcessing is set to POLLING.
            */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( (FLEXCAN_NULL_OFFSET != Can_ControlerDescriptorsPtr[can_ctrl_index].ControllerOffset) &&
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                 ((uint32)0U != (CAN_CONTROLLERCONFIG_RXPOL_EN & (Can_ControlerDescriptorsPtr[can_ctrl_index].Options))) &&
                 /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                 ((Can_ControlerDescriptorsPtr[can_ctrl_index].MaxMBCount) != (uint8)0U) )
            {
                /* Init last MB to process for RX. "FirstTxMBIndex" is updated considering RxFifo. */
                if (0U < Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex)
                {
                    can_mb_last = (uint8)(Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex - (uint8)1U);
                }
                else
                {
                    can_mb_last = (uint8)(Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex);
                }

                /* Enabled & RxPoll used : process Rx interrupt flags, start with the first Rx MB (0) and finish before the first Tx MB. */
                FlexCan_LLD_Process_Rx( (uint8)can_ctrl_index, (uint8)can_mb_first, (uint8)can_mb_last);
            }
        }
    }

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time, with polling of all the MessageBuffer referenced to .readpoll
* @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
* @pre            Driver must be initialized.
* @post           Receive the data from that MB that is configured for Rx.
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
/* @violates @ref FlexCan_LLD_c_REF_17 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_MainFunction_Multiple_Read_Poll( VAR(uint8, AUTOMATIC) readpoll)
    {
        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC)  can_ctrl_id = 0U;
        /* First MB to process. */
        VAR(uint8, AUTOMATIC)  can_mb_index = 0U;
        /* Can Object ID to process. */
        VAR(uint32, AUTOMATIC)  can_object_id = 0U;
        /* Can Process Index of MB for the controller to process. */
        VAR(uint8, AUTOMATIC)  can_rx_process_index[CAN_MAXCTRL_SUPPORTED];

        if ( NULL_PTR != Can_CurrentConfigPtr )
        {
            #if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* Test whether the driver is already initialised. */
                if ( CAN_UNINIT == Can_DriverStatus )
                {
                    /*
                       (CAN181) If development error detection for the Can module is enabled: The function Can_MainFunction_Read shall raise the
                               error CAN_E_UNINIT if the driver not yet initialized.
                    */
                    Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_UNINIT);
                }
                else
                {
            #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                    /* initialise the can_rx_process_index for all the configured controller. */
                    for ( can_ctrl_id = (uint8)0U; can_ctrl_id < CAN_MAXCTRL_SUPPORTED; can_ctrl_id++)
                    {
                        can_rx_process_index[can_ctrl_id] = 0U;
                        #if (CAN_RXFIFO_ENABLE == STD_ON)
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                        if ( CAN_CONTROLLERCONFIG_RXFIFO == ((uint32)(Can_ControlerDescriptorsPtr[can_ctrl_id].Options) & CAN_CONTROLLERCONFIG_RXFIFO) )
                        {
                            /* Processing MB must start from index 8 if RxFifo is enabled when configure MBs. */
                            can_rx_process_index[can_ctrl_id] = FLEXCAN_FIFO_MB_COUNT;
                        }
                        #endif /* #if (CAN_RXFIFO_ENABLE == STD_ON) */
                    }
                    /* Parse through all RX configured message buffer */
                    for ( can_mb_index = (uint8)0U; can_mb_index < (uint8)Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigCount; can_mb_index++)
                    {
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        can_ctrl_id = Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].ControllerId;
                        /*  Poll only the Rx MB which is referenced by Can_LLD_MainFunction_Multiple_Read_Poll */
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        if ((readpoll == Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].CanMainFuncRWPeriodRef) &&
                        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            (FLEXCAN_NULL_OFFSET != Can_ControlerDescriptorsPtr[can_ctrl_id].ControllerOffset) &&
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            ((uint32)0U != (CAN_CONTROLLERCONFIG_RXPOL_EN & (Can_ControlerDescriptorsPtr[can_ctrl_id].Options))) &&
                            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            (CAN_RECEIVE == Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].MBType ))
                        {
                            /* CanOnjectID of the polled MB */
                             /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            can_object_id = (Can_CurrentConfigPtr->MBConfigContainer.MessageBufferConfigsPtr[can_mb_index].HWObjID );
/* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
                            while ((can_object_id != (Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_rx_process_index[can_ctrl_id]])) && (can_rx_process_index[can_ctrl_id] < (Can_ControlerDescriptorsPtr[can_ctrl_id].MaxMBCount)))
                            {
                                /* increase the can_rx_process_index to check next can_object_id present */
                                can_rx_process_index[can_ctrl_id]++;
                            }
                            if (can_object_id == Can_ControllerStatuses[can_ctrl_id].Can_MBMapping[can_rx_process_index[can_ctrl_id]])
                            {
                                /* Enabled & RxPoll used : process Rx interrupt flags, */
                                FlexCan_LLD_Process_Rx( (uint8)can_ctrl_id, (uint8)can_rx_process_index[can_ctrl_id], (uint8)can_rx_process_index[can_ctrl_id]);
                                /* increase the can_rx_process_index to check next can_object_id present */
                                can_rx_process_index[can_ctrl_id]++;
                            }
                        }
                    }
            #if (CAN_DEV_ERROR_DETECT == STD_ON)
                }
            #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        }
    }
#endif /* (CAN_RXPOLL_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          Service to perform the polling of CAN status register flags to detect transition of CAN Controller state
* @details        The function Can_MainFunction_Mode shall implement the polling of CAN status register flags to detect transition of CAN Controller state
*
* @pre
* @post
*
*/

FUNC (void, CAN_CODE) Can_LLD_MainFunction_Mode( void)
    {

        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC)  can_ctrl_index = 0U;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)  can_hw_offset = 0U;
        /* Old and new MCR status Register*/
        VAR(uint32, AUTOMATIC)  can_old_mcr = 0U;
        VAR(uint32, AUTOMATIC)  can_new_mcr = 0U;
        /* Controller descriptor */
        P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor;

        /* Loop through all configured controller descriptors. */
        for ( can_ctrl_index = (uint8)0U; can_ctrl_index < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_ctrl_index++)
        {
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            if ( (FLEXCAN_NULL_OFFSET != Can_CurrentConfigPtr->ControlerDescriptors[can_ctrl_index].ControllerOffset) )
            {
                can_old_mcr = 0U;
                can_new_mcr = 0U;
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                can_ptrControlerDescriptor = &Can_CurrentConfigPtr->ControlerDescriptors[can_ctrl_index];
                /* Get the hardware offset for this controller. */

                can_hw_offset = can_ptrControlerDescriptor->ControllerOffset;

                /*
                    (CAN373) The function Can_Mainfunction_Mode shall call the function CanIf_ControllerModeIndication to notify the upper layer about a successful
                             state transition of the CAN controller, in case the state transition was triggered by function Can_SetControllerMode.
                */
                /* We have to look for all the possible transitions*/
                if(CAN_SLEEPED != Can_ControllerStatuses[can_ctrl_index].ControllerState)
                {
                    /* from CAN_STARTED to CAN_STOPPED (in CAN_STOPPED,  MCR[HALT] = 1 and MCR[FRZ] = 1)*/
                    can_old_mcr |= (Can_MCR_Configuration[can_ctrl_index] & FLEXCAN_MCR_FRZ) | (Can_MCR_Configuration[can_ctrl_index] & FLEXCAN_MCR_HALT);
                    /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                     can_new_mcr |= ((uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_FRZ) | ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_HALT ) ;

                     if( ( can_old_mcr != (FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT) ) && ( can_new_mcr == (FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT) )  && (CAN_STOPPED != Can_ControllerStatuses[can_ctrl_index].ControllerState) )
                     {
                         Can_ControllerStatuses[can_ctrl_index].ControllerState = CAN_STOPPED;
                         CanIf_ControllerModeIndication(can_ctrl_index, CANIF_CS_STOPPED);
                     }

                    /* from CAN_STOPPED to CAN_STARTED (in CAN_STARTED,  MCR[HALT] = 0 and MCR[FRZ] = 0)*/
                     if( ( can_old_mcr != 0U ) && ( can_new_mcr == 0U ) && (CAN_STARTED != Can_ControllerStatuses[can_ctrl_index].ControllerState))
                     {
                         Can_ControllerStatuses[can_ctrl_index].ControllerState = CAN_STARTED;
                         CanIf_ControllerModeIndication(can_ctrl_index, CANIF_CS_STARTED);
                     }                    
                } 

  #if (CAN_WAKEUP_SUPPORT == STD_ON)
                /* from CAN_STOPPED to CAN_SLEEPED (in CAN_SLEEPED,  MCR[WAK_SMK] = 1 and MCR[SLF_WAK] = 1)*/
                can_old_mcr = 0U;
                can_new_mcr = 0U;
                if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[can_ctrl_index].InterruptMode )
                {
                    can_new_mcr |= ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_WAK_MSK );
                    can_old_mcr |= (Can_MCR_Configuration[can_ctrl_index] & FLEXCAN_MCR_WAK_MSK);
                }
                /* Self Wakeup must be set. */
                can_new_mcr |= ( (uint32)FLEXCAN_MCR_READ( can_hw_offset) & FLEXCAN_MCR_SLF_WAK );
                can_old_mcr |= (Can_MCR_Configuration[can_ctrl_index] & FLEXCAN_MCR_SLF_WAK) ;

                /* with this test i am assuring that this trasition is the write one, if CAN_INTERRUPT_ENABLED == OFF then SLF_WAK mask is
                the only one that can change, and the change accured*/
                if ( can_old_mcr != can_new_mcr )
                {
                    if ( (uint8)CAN_INTERRUPT_ENABLED == Can_ControllerStatuses[can_ctrl_index].InterruptMode )
                    {
                        if( can_new_mcr ==  (FLEXCAN_MCR_WAK_MSK | FLEXCAN_MCR_SLF_WAK) )
                        {
                            CanIf_ControllerModeIndication(can_ctrl_index, CANIF_CS_SLEEP);
                        }

                    }
                    else /* polling mode */
                    {
                        CanIf_ControllerModeIndication(can_ctrl_index, CANIF_CS_SLEEP);
                    }
                }

                /* from CAN_SLEEPED to CAN_STOPPED (in CAN_STOPPED,  MCR[WAK_SMK] = 0 and MCR[SLF_WAK] = 0)*/

                /* with this test i am assuring that this trasition is the write one, if CAN_INTERRUPT_ENABLED == OFF then SLF_WAK mask is
                the only one that can change, and the change accured*/
                if ( (can_old_mcr != can_new_mcr) && (can_new_mcr == 0U) )
                {
                    CanIf_ControllerModeIndication(can_ctrl_index, CANIF_CS_STOPPED);
                }
  #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
            }
        }
    }

/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
* @details        Local function for calling notification function to notify upper layer during
*                 Can_MainFunction_BusOff if polling is selected or from ISR when Interrupt mode selected.
*                 This routine is called by:
*                  - Can_LLD_Process_BusOff() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            A busoff condition must to be fulfilled.
* @post           Status flag is cleared.
*
*/
FUNC (void, CAN_CODE) FlexCan_LLD_Process_BusOff( CONST(uint8, CAN_CONST) controller)
    {

        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC) can_hw_offset = 0U;


        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

        /* Clear the ESR[BOFF_INT] bus off interrupt flag (w1c). */
         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        FLEXCAN_SET_ESR_BOFFINT( can_hw_offset);
    }


/*================================================================================================*/
/**
* @brief          Local function for calling notification function to notify upper layer during Can_MainFunction_Wakeup if polling is selected or from ISR when Interrupt mode selected.
* @details        Local function for calling notification function to notify upper layer during
*                 Can_MainFunction_Wakeup if polling is selected or from ISR when Interrupt mode selected.
*                 This routine is called by:
*                  - Can_LLD_Process_Wakeup() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @pre            A wakeup condition must be fulfilled.
* @post           Clear the flag for wakeup condition.
*
*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)

FUNC (void, CAN_CODE) FlexCan_LLD_Process_Wakeup( CONST(uint8, CAN_CONST) controller)
    {

        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC) can_hw_offset = 0U;

        /* Get the hardware offset for this controller. */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

        /* Clear the ESR[WAK_INT]  WakeUp interrupt flag (w1c). */
        FLEXCAN_SET_ESR_WAK_INT( can_hw_offset);

    }

#endif /* (CAN_WAKEUP_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          This function checks if a Wakeup has occurred for the given controller.
* @details        This routine is called by:
*                  - Can_MainFunction_Wakeup() from Can.c file.
*                  - Can_CheckWakeup() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK wakeup detected
* @retval        E_NOT_OK wakeup not detected
*
* @pre            A request for wakeup checking is required.
* @post           Report the occurence or not for an wakeup event.
*
* @implements     DCAN01127
*/


FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckWakeup( VAR(uint8, AUTOMATIC) controller)
    {

        /* Return value. */
        Std_ReturnType        Out_can_return = (uint8)E_NOT_OK;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC) can_hw_offset = 0U;

        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

        /*
           (CAN361) The function Can_CheckWakeup shall check if the requested CAN controller has detected a wakeup.
                    If a wakeup event was successfully detected, the function shall return E_OK, otherwise E_NOT_OK.
        */
        #if (CAN_API_ERROR_STATUS == STD_ON)
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        Can_EsrRegStatus[controller] = FLEXCAN_ESR_READ(can_hw_offset);
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( FLEXCAN_ESR_WAK_INT == (FLEXCAN_ESR_WAK_INT & Can_EsrRegStatus[controller]) )
        #else
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( FLEXCAN_ESR_WAK_INT == (FLEXCAN_ESR_WAK_INT & (uint32)FLEXCAN_ESR_READ(can_hw_offset)) )
        #endif
        {
            /* Controller is in WakeUp state. */
            Out_can_return = (uint8)E_OK;
        }

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          This function checks if a BusOff has occurred for the given controller.
* @details        This routine is called by:
*                  - Can_MainFunction_BusOff() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK wakeup detected
* @retval        E_NOT_OK wakeup not detected
*
* @pre            A request for busoff checking is required.
* @post           Report the occurence or not for an busoff event.
*
* @implements     DCAN01141
*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckBusOff( VAR(uint8, CAN_VAR) controller)
    {

        /* Return value. */
        VAR(uint8, AUTOMATIC) Out_can_return = (uint8)E_NOT_OK;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC) can_hw_offset = 0U;


        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;
        
        /* Check Busoff flag if it's set. */
        #if (CAN_API_ERROR_STATUS == STD_ON)
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        Can_EsrRegStatus[controller] = (uint32)FLEXCAN_ESR_READ(can_hw_offset);
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( FLEXCAN_ESR_BOFFINT == (FLEXCAN_ESR_BOFFINT & Can_EsrRegStatus[controller]) )
        #else
        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( FLEXCAN_ESR_BOFFINT == (FLEXCAN_ESR_BOFFINT & (uint32)FLEXCAN_ESR_READ(can_hw_offset)) )
        #endif
        {
            /* Controller is in BusOff state. */
            Out_can_return = (uint8)E_OK;
        }

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Process Rx Fifo FrameAvailable events.
* @details        This routine is called by:
*                  - Can_LLD_RxFifoFrameAvNotif() from Can.c file.
*
* @param[in]      controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
*
* @return        Std_ReturnType
* @retval        E_OK wakeup detected
* @retval        E_NOT_OK wakeup not detected
*
* @pre            Driver must be initialized and RxFifo should be enabled.
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)

FUNC(void, CAN_CODE) FlexCan_LLD_RxFifoFrameAvNotif( CONST(uint8, CAN_CONST) controller)
    {
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)  can_hw_offset = 0U;
        /* Variable for indexing the MBs. */
        VAR(uint8, AUTOMATIC)    can_mb_index = 0U;
        /* Number of data bytes. */
        VAR(uint8, AUTOMATIC)    can_mb_data_length = 0U;
        /* Physical data bytes. */
        VAR(uint8, AUTOMATIC)    can_mb_data[8];
        /* Index for data byte of MB. */
        VAR(uint8, AUTOMATIC)    can_databyte_index = 0U;
        /* Variable for storing the Hrh. */
        VAR(uint8, AUTOMATIC)    can_hrh = 0U;
        /* Variables for storing the CanID. */
        VAR(Can_IdType, AUTOMATIC) can_mb_messageid = 0U;
        /* Temporary variable. */
        VAR(uint32, AUTOMATIC)   can_mb_config = 0U;

#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
        VAR(uint32, AUTOMATIC) Can_byte_mask = 0x000000FFU;
        VAR(uint8, AUTOMATIC)  Can_loop = 1U;
        VAR(uint32, AUTOMATIC) can_mb_content[4];
    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif
#endif

        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[controller].ControllerOffset;

        /* Check Frame Available int flag. */
         /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ( FLEXCAN_FIFO_AVAILABLE_INT_MASK == (FLEXCAN_IFLAG1_READ(can_hw_offset) & FLEXCAN_FIFO_AVAILABLE_INT_MASK) )
        {
    #if defined(ERR_IPV_FLEXCAN_0009)
        #if (ERR_IPV_FLEXCAN_0009== STD_ON)
            do{
                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04();
                /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                Can_loop = Can_LLD_ForbiddenRegion(can_hw_offset, can_mb_index, can_mb_content);
                SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04();
              }while( 1U == Can_loop);

            can_mb_config = can_mb_content[0];

            /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time. Read the DLC; this read access also locks the MB. */
            can_mb_data_length = (uint8)((can_mb_config & FLEXCAN_MBCS_LENGTH) >> FLEXCAN_MBCS_LENGTH_SHIFT);

                if( can_mb_data_length > 8U )
                {
                    can_mb_data_length = 8U;
                }
            can_mb_messageid = ((uint32)0x0U == (can_mb_config & (uint32)FLEXCAN_MBCS_IDE)) ? /* condition to test */
                                                (Can_IdType)(( can_mb_content[1] & (uint32)(FLEXCAN_MBID_ID_STANDARD)) >> (uint32)(18U) ) : /* value if condition is true */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                (Can_IdType)(can_mb_content[1] & FLEXCAN_MBID_ID_EXTENDED); /* value if condition is false */

                        /*
                           (CAN060) Data mapping by CAN to memory is defined in a way that the CAN data byte which is sent out first is array element 0,
                                   the CAN data byte which is sent out last is array element 7.
                           (CAN299) The Can module shall copy the L-SDU in a shadow buffer after reception, if the RX buffer cannot be protected (locked)
                                   by CAN Hardware against overwriting by a newly received message.
                           (CAN300) The Can module shall copy the L-SDU in a shadow buffer, if the CAN Hardware is not globally accessible.
                        */
                        /* can_mb_content[2] and can_mb_content[3] stores 4 bytes. Thats why we have to split them. */
                        for ( can_databyte_index = (uint8)0U; can_databyte_index < can_mb_data_length; can_databyte_index++)
                        {
                            /* Copy the data  */
                            if (can_databyte_index < 4U) /* the bytes from 0 to 3 are stored in can_mb_content[2] */
                            {
                                /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                                can_mb_data[can_databyte_index] = (uint8)((can_mb_content[2] >> (8 * (3 - can_databyte_index)))  & Can_byte_mask);
                            }
                            else /* the bytes from 4 to 7 are stored in can_mb_content[3] */
                            {

                                /* @violates @ref FlexCan_LLD_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
                                can_mb_data[can_databyte_index] = (uint8)((can_mb_content[3] >> (8 * (7 - can_databyte_index)))  & Can_byte_mask);
                            }
                        }
        #else
            #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
        #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON) */
    #else
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            /*@violates @ref FlexCan_LLD_c_REF_18 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
            can_mb_config = (uint32)FLEXCAN_MB_READ(can_hw_offset, can_mb_index);

            /* Create a local copy of the MB to ensure that it is locked out for minimum amount of time. Read the DLC; this read access also locks the MB. */
            can_mb_data_length = (uint8)((can_mb_config & FLEXCAN_MBCS_LENGTH) >> FLEXCAN_MBCS_LENGTH_SHIFT);

                if( can_mb_data_length > 8U )
                {
                    can_mb_data_length = 8U;
                }
            /* Get the ID of the message.
            For extended IDs the most significant bit must be set - according to Can_IdType requirement - chapter8.2.4 of SWS CAN.*/
            can_mb_messageid = ((uint32)0x0U == (can_mb_config & (uint32)FLEXCAN_MBCS_IDE)) ? /* condition to test */
             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */

                                    (Can_IdType)((uint32)FLEXCAN_MB_READ_ID_STANDARD(can_hw_offset, can_mb_index)) : /* value if condition is true */
                                                 /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                                                 /*@violates @ref FlexCan_LLD_c_REF_18 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
                                                            (Can_IdType)((uint32)FLEXCAN_MB_READ_ID_EXTENDED(can_hw_offset, can_mb_index) | FLEXCAN_MBC_ID_IDE); /* value if condition is false */

            /* Copy the data. */
            for ( can_databyte_index = (uint8)0U; can_databyte_index < can_mb_data_length; can_databyte_index++)
            {
            /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                can_mb_data[can_databyte_index] = FLEXCAN_MB_READ_DATA_BYTE (can_hw_offset, can_mb_index, can_databyte_index);
            }

    #endif /* ERR_IPV_FLEXCAN_0009 */
            /* Release the internal lock. Reading the Free Running Timer is not mandatory. If not executed the MB remains locked,
                unless the CPU reads the C/S word of another MB.*/
/* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */

            FLEXCAN_TIMER_READ( can_hw_offset);

            /*
            Call the RxIndication function - This service is implemented in the CAN Interface and called by the CAN Driver after a CAN L-PDU has been received.
            Within this service, the CAN Interface translates the CanId into the configured target PDU ID and routes this indication to the configured upper layer target service(s).
            */

            /* @violates @ref FlexCan_LLD_c_REF_5 Use of Pointer Arithematic */
            /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
            can_hrh = (uint8)(Can_CurrentConfigPtr->ControlerDescriptors[controller].FirstHrhIndex);

           #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
           /* [CAN444] If the L-PDU callout returns false, the L-PDU shall not be processed any further. */
           /* @violates @ref Can_Flexcan_c_REF_11 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
           /* @violates @ref Can_Flexcan_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
           if (TRUE ==    CanLPduReceiveCalloutFunction(u32MbHrh, u32MbMessageId, u8MbDataLength, u8CanMbData))
           {
           #endif
           
               /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
              CanIf_RxIndication( (Can_HwHandleType)can_hrh, (Can_IdType)can_mb_messageid, (uint8)can_mb_data_length, can_mb_data);
              
           #if (CAN_LPDU_NOTIFICATION_ENABLE == STD_ON)
           }
           #endif

            /* Ack interrupt flag - w1c bit. */
             /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            FLEXCAN_IFLAG1_CONFIG( can_hw_offset, FLEXCAN_FIFO_AVAILABLE_INT_MASK);
        }

    }

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*================================================================================================*/
/*
* @brief          Process a transition from one clock source to another.
* @details        This function is configuring Can controllers to run on the same baudrate, but having a different MCU source clock.
*                 This routine is called by:
*                  - Can_SetClockMode() from Can.c file.
*
* @param[in]      can_controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      can_clk_mode clock mode selection
*
* @return        Std_ReturnType Result of the clock switch operation.
* @retval        E_OK  Switch clock operation was ok.
* @retval        E_NOT_OK  Switch clock operation was not ok.
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @note           Not AUTOSAR required. This is user implementation.
*/

#if (CAN_DUAL_CLOCK_MODE == STD_ON)

FUNC(Std_ReturnType, CAN_CODE) Can_LLD_SetClockMode( VAR(uint8, AUTOMATIC) can_controller, VAR(Can_ClockMode, AUTOMATIC) can_clk_mode)
    {
        /* Return the operation success. */
        VAR(Std_ReturnType, AUTOMATIC) Out_can_return = (uint8)E_OK;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC)  can_hw_offset = 0U;
        /* Variable to hold the index of the current baudrate */
        VAR(uint8, AUTOMATIC) Baudrateindex = 0U;

        /* Get the index of the current baudrate */
        Baudrateindex = Can_ControllerStatuses[can_controller].CurrentBaudRateIndex;

        /* Get the hardware offset for this controller. */
        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
        can_hw_offset = Can_ControlerDescriptorsPtr[can_controller].ControllerOffset;

        switch (can_clk_mode)
        {
            case (CAN_NORMAL):
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                FLEXCAN_CTRL_CONFIG( can_hw_offset, (uint32)(Can_ControlerDescriptorsPtr[can_controller].ControllerBaudrateConfigsPtr[Baudrateindex].ControlRegister));
                break;

            case (CAN_ALTERNATE):
                /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4, pointer arithmetic other than array indexing used */
                FLEXCAN_CTRL_CONFIG( can_hw_offset, (uint32)(Can_ControlerDescriptorsPtr[can_controller].ControllerBaudrateConfigsPtr[Baudrateindex].ControlRegister_Alternate));
                break;

            default:
                Out_can_return = (uint8)E_NOT_OK;
                Cer_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SETCLOCKMODE, (uint8)CAN_E_DEFAULT);
                /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                      Cer_ReportError() function implementation */

                break;
        }

        return (Out_can_return);

    }

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

#if (CAN_API_ERROR_STATUS == STD_ON)
/*================================================================================================*/
/*
* @brief         This function checks the error status and intimated to upper layer.
* @details       This routine is called by:
*                 - Can_GetErrorStatus() from Can.c file.
* 
* @param[in]     controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* 
* @return        void
* 
* @pre           Driver must be initialized.
* @post          Inform CanIf about errorstatus .
* @notes         Not AUTOSAR required. This is user implementation.
*/
/*================================================================================================*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (uint32, CAN_CODE) Can_LLD_GetErrorStatus( VAR(uint8, AUTOMATIC) can_controller)
    {
        /* error status. */
        VAR(uint32, AUTOMATIC) can_error_status = 0U;
        /* Controller hardware offset on chip. */
        VAR(uint8, AUTOMATIC) can_hw_offset = 0U;
        /* Error Status Register value */
        VAR(uint32, AUTOMATIC) can_esr_reg = 0U;

        /* @violates @ref FlexCan_LLD_c_REF_8 Violates MISRA 2004 Advisory Rule 17.4,pointer arithmetic other than array indexing used */
        can_hw_offset = Can_CurrentConfigPtr->ControlerDescriptors[can_controller].ControllerOffset;

        /* @violates @ref FlexCan_LLD_c_REF_4 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        can_error_status = (uint32)FLEXCAN_ESR_READ(can_hw_offset);

        if((Can_EsrRegStatus[can_controller] | can_error_status) & FLEXCAN_ESR_ERRINT)
        {
            can_esr_reg = Can_EsrRegStatus[can_controller] | can_error_status;
        }else{
            can_esr_reg = CAN_NO_ACK_ERR;
        }

        Can_EsrRegStatus[can_controller] = 0x00U;
        
        return can_esr_reg;
    }
#endif /* CAN_API_ERROR_STATUS == STD_ON */

#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
/*================================================================================================*/
/*
@brief         This function checks the transmit cancel confirmation when can driver used in
               interrupt mode or in Polling mode.
@details       This routine is called by Can_CheckTxCancel() from Can.c.

@param[in]     none
@param[out]     none

@return        void

@pre           Driver must be initialized.
@post          Inform CanIf about transmit cancel confirmation.
@notes         Not AUTOSAR required. This is user implementation.
*/
/*================================================================================================*/
/* @violates @ref FlexCan_LLD_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_LLD_CheckTxCancel(void)
{
    /* Variable for indexing the controllers. */
    VAR(uint8, AUTOMATIC)   can_ctrl_index = 0U;
    /* First MB to process. */
    VAR(uint8, AUTOMATIC)  can_mb_index = 0U;    
    /* mbindex cancel status variable*/
    VAR(uint8, AUTOMATIC)  can_mbindexCancel = 0U;    
    /* Unique identifier of a PDU within a software module */
    VAR(PduIdType, AUTOMATIC) Can_PduId;
    /* Store the basic information about a PDU */
    VAR(PduInfoType, AUTOMATIC) Can_CbkPduInfo;    
    
    /* Loop through all configured controller descriptors. */
    for ( can_ctrl_index = 0U; can_ctrl_index < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_ctrl_index++)
    {
    can_mb_index = Can_ControllerStatuses[can_ctrl_index].FirstTxMBIndex;
        for ( can_mb_index = can_mb_index; can_mb_index < (uint8)CAN_MAXMB_CONFIGURED; can_mb_index++)
        {    
        
            if ( can_mb_index < (uint8)32 )
            {
                can_mbindexCancel = ((uint32)((uint32)1U << can_mb_index) & Can_TxCancelStatus[can_ctrl_index][0])?(uint8)0x1U:(uint8)0x0U;
            }
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)        
            else
            {
                can_mbindexCancel = ((uint32)((uint32)1U << (can_mb_index - (uint8)32)) & Can_TxCancelStatus[can_ctrl_index][1])?(uint8)1U:(uint8)0U;
            }
#endif    
        
        if(can_mbindexCancel == (uint8)0x01U )
            {
                Can_PduId = Can_PduIdBuff[can_ctrl_index][can_mb_index];
                Can_CbkPduInfo = Can_PduInfoBuff[can_ctrl_index][can_mb_index];
                /*
                        * (CAN058) The Can module interacts among other modules (eg. Diagnostic Event Manager (DEM), Development Error Tracer (DET)) with the CanIf module in a direct way.
                        * The driver only sees the CanIf module as origin and destination.
                        */
                /* @violates @ref FlexCan_LLD_c_REF_6 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
                CanIf_CancelTxConfirmation(Can_PduId , &Can_CbkPduInfo);

                /* Clear TX Cancel status flag */
                if ( can_mb_index < (uint8)32 )/* for 32/64 message buffer*/
                Can_TxCancelStatus[can_ctrl_index][0] &= ~((uint32)((uint32)0x01U << can_mb_index));
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)                
                else /* for 64 message buffer*/
                Can_TxCancelStatus[can_ctrl_index][1] &= ~((uint32)((uint32)0x01U << (can_mb_index - (uint8)32)));
#endif                            
                can_mbindexCancel = (uint8)0;
            }
            else
            {
            can_mbindexCancel = (uint8)0; /* clear can_mb_index cancel status flag*/
        }
    }
}
}
#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */

#define CAN_STOP_SEC_CODE
/* @violates @ref FlexCan_LLD_c_REF_2 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref FlexCan_LLD_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
