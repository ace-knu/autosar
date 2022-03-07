/**
*   @file    Lin_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Lin module NonAutosar API header.
*   @details Lin NonAutosar APIs and defines.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF5_ASR_REL_4_0_REV_0003_20140822
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_NONASR_H
#define LIN_NONASR_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_NonASR_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_NonASR_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Lin_NonASR_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_NonASR_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DLIN02055 */
#define LIN_VENDOR_ID_NONASR                    43
#define LIN_MODULE_ID_NONASR                    82

/* @violates @ref Lin_NonASR_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_NONASR     4

/* @violates @ref Lin_NonASR_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_NONASR     0
/*
* @violates @ref Lin_NonASR_h_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_NonASR_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_NONASR  3
#define LIN_SW_MAJOR_VERSION_NONASR             1
#define LIN_SW_MINOR_VERSION_NONASR             0
#define LIN_SW_PATCH_VERSION_NONASR             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LIN configuration header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR    != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR    != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR != LIN_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Lin_NonASR.h and Lin_Cfg.h are different"
#endif
/* Check if current file and LIN configuration header file are of the same software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_SW_MINOR_VERSION_NONASR != LIN_SW_MINOR_VERSION_CFG) || \
     (LIN_SW_PATCH_VERSION_NONASR != LIN_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Lin_NonASR.h and Lin_Cfg.h are different"
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#if (LIN_DUAL_CLOCK_MODE == STD_ON)

/**
* @brief          Clock modes.
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @implements     DLIN02057
* @note           Possible clock modes: LIN_NORMAL (normal execution mode),
*                 LIN_ALTERNATE (low power mode).
*
*/
typedef enum
{
    LIN_NORMAL     =   (uint8)0x01U, /**< @brief
                                               LIN_NORMAL mode.*/
    LIN_ALTERNATE  =   (uint8)0x02U  /**< @brief
                                               LIN_ALTERNATE mode.*/
} Lin_ClockModes;

#endif /* #if LIN_DUAL_CLOCK_MODE == STD_ON */


#ifdef LIN_USE_MSC

/**
* @brief          Micro Second Channel status type.
* @pre            LIN_USE_MSC must be defined.
*
* @implements     DLIN02056
* @note           MSC channel frame operation status, as returned by the
*                 API service Msc_GetStatus().
*
*/
typedef enum
{
    MSC_IDLE = 0,      /**< @brief Receiver is disabled and no
                                   reception is running.*/
    MSC_READY,         /**< @brief Receiver is enabled and no
                                   reception is running.*/
    MSC_RUN,           /**< @brief Receiver is enabled and
                                   reception is running.*/
    MSC_WAKEUP,        /**< @brief Receiver is in wakeup mode.*/
    MSC_OVERRUN_ERROR, /**< @brief Erroneous reception due to
                                   an OR error.*/
    MSC_FRAMING_ERROR, /**< @brief Erroneous reception due to
                                   a FE error.*/
    MSC_PARITY_ERROR,  /**< @brief Erroneous reception due to
                                   a PE error.*/
    MSC_NOISE_ERROR    /**< @brief Erroneous reception due to
                                   an NF error.*/
} Msc_StatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Micro Second Channel data type.
* @pre            LIN_USE_MSC must be defined.
*
* @implements     DLIN02058
* @note           This type is used to provide Address, data, and any possible
*                 errors from the MSC driver to the application.
*
*/
typedef struct
{
    uint8 Data;     /**< @brief Payload of the upstream MSC frame.*/
    uint8 Address;  /**< @brief address of the receive data buffer.*/
    uint8 Errors;   /**< @brief upstream MSC frame error type.*/
    Msc_StatusType  State;   /**< @brief upstream MSC channel state.*/
} MSC_DataType;

#endif    /* #ifdef LIN_USE_MSC */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (LIN_DUAL_CLOCK_MODE == STD_ON)

    #define LIN_START_SEC_VAR_INIT_UNSPECIFIED
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"

    extern VAR(Lin_ClockModes,LIN_VAR)LinClock;
    
    #define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"
    
#endif    /* #if LIN_DUAL_CLOCK_MODE == STD_ON */


#ifdef LIN_USE_MSC

    #define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"
    
    volatile extern VAR(MSC_DataType,LIN_VAR)MscBuffer[LIN_HW_MAX_MODULES];

    #define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"


    #define LIN_START_SEC_VAR_NO_INIT_8
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"

    extern VAR(sint8,LIN_VAR)Lin_ChannelHardwareMap[];

    #define LIN_STOP_SEC_VAR_NO_INIT_8
    /*
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    */
    /*
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
    *                            statements and comments before '#include'
    */
    #include "MemMap.h"

#endif    /* #ifdef LIN_USE_MSC */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/*
* @violates @ref Lin_NonASR_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#if LIN_DUAL_CLOCK_MODE == STD_ON
 extern FUNC (Std_ReturnType, LIN_CODE) Lin_SetClockMode(VAR(Lin_ClockModes, AUTOMATIC) ClockMode);
#endif

#ifdef LIN_USE_MSC

 /* @implements     DLIN02054 */
 extern FUNC(void, LIN_CODE) Msc_InitChannel( CONST(uint8, AUTOMATIC) Channel,\
                  P2CONST(Lin_ChannelConfigType, AUTOMATIC, LIN_APPL_CONST) Config);
 /* @implements     DLIN02051 */
 extern FUNC (void, LIN_CODE) Msc_DeInitChannel( CONST(uint8, AUTOMATIC) Channel);

 /* @implements     DLIN02052 */
 extern FUNC(Msc_StatusType, LIN_CODE) Msc_GetStatus( CONST(uint8, AUTOMATIC) Channel);

 /* @implements     DLIN02053 */
 extern FUNC (void, LIN_CODE) Msc_Polling( CONST(uint8, AUTOMATIC) Channel);

#endif

#define LIN_STOP_SEC_CODE
/*
* @violates @ref Lin_NonASR_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LIN_NONASR_H */

/** @} */
