/**
*   @file    Fee.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Include File.
*   @details Include all external API declarations and definitions of 
*            all pre-compile parameters.
*
*   @addtogroup FEE
*   @{

*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : none
*   Dependencies         : Fls
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF7_ASR_REL_4_0_REV_0003_20150304
*
*   (c) Copyright 2006-2015 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Cfg.h"
#include "Fee_Version.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* AUTOSAR module vendor identification */
#define FEE_VENDOR_ID            43U

/* AUTOSAR module identification */
#define FEE_MODULE_ID            21U

/* AUTOSAR module instance identification */
#define FEE_INSTANCE_ID          0U

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fee configuration header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_VENDOR_ID_CFG)
#error "Fee.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fee configuration header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION    != FEE_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_MINOR_VERSION    != FEE_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_REVISION_VERSION != FEE_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif
/* Check if current file and Fee configuration header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_CFG) || \
     (FEE_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_CFG) || \
     (FEE_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/** 
* @brief        All service IDs (passed to DET)
* @implements   DFEE03002
*/
#define FEE_INIT_ID                    0x00U
#define FEE_SETMODE_ID                 0x01U
#define FEE_READ_ID                    0x02U
#define FEE_WRITE_ID                   0x03U
#define FEE_CANCEL_ID                  0x04U
#define FEE_GETSTATUS_ID               0x05U
#define FEE_GETJOBRESULT_ID            0x06U
#define FEE_INVALIDATEBLOCK_ID         0x07U
#define FEE_GETVERSIONINFO_ID          0x08U
#define FEE_ERASEIMMEDIATEBLOCK_ID     0x09U
#define FEE_JOBENDNOTIFICATION_ID      0x10U
#define FEE_JOBERRORNOTIFICATION_ID    0x11U
#define FEE_MAINFUNCTION_ID            0x12U
/* Vendor specific API */
#define FEE_GETRUNTIMEINFO_ID          0x13U
#define FEE_FORCESWAPONNEXTWRITE_ID    0x14U


/** 
* @brief Development error codes (passed to CER)
*/
#define FEE_E_JOB_UNKNOW               0x13U
/** 
* @brief All service IDs (passed to CER)
*/
#define FEE_JOBSCHEDULE_ID             0x14U


/** 
* @brief        Development error codes (passed to DET)
*
* @implements   DFEE03001
*/
#define FEE_E_UNINIT                  0x01U /**< @brief API called when module was not initialized */
#define FEE_E_INVALID_BLOCK_NO        0x02U /**< @brief API called with invalid block number */
#define FEE_E_INVALID_BLOCK_OFS       0x03U /**< @brief API called with invalid block offset */
#define FEE_E_INVALID_DATA_PTR        0x04U /**< @brief API called with invalid data pointer */
#define FEE_E_INVALID_BLOCK_LEN       0x05U /**< @brief API called with invalid length information */
#define FEE_E_BUSY                    0x06U /**< @brief API called while module is busy processing a user request */
#define FEE_E_BUSY_INTERNAL           0x07U /**< @brief API called while module is busy doing internal management operations */
#define FEE_E_INVALID_CANCEL          0x08U /**< @brief API called while module is not busy because there is no job to cancel */ 
/* Vendor Specific Define */
#define FEE_E_CANCEL_API              0x0AU /**< @brief API called when underlying driver has cancel api disabled */
#define FEE_E_CLUSTER_GROUP_IDX       0x0BU /**< @brief API called with invalid cluster group index */

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define FEE_START_SEC_CODE
/* @violates @ref Fee_h_REF_1 Repeatedly included but does not have a standard include guard */
#include "MemMap.h"

extern FUNC( void, FEE_CODE ) Fee_Init( void );

#if( FEE_SETMODE_API_SUPPORTED == STD_ON )
extern FUNC( void, FEE_CODE ) Fee_SetMode(
    VAR( MemIf_ModeType, AUTOMATIC ) Mode );
#endif /* FEE_SETMODE_API_SUPPORTED == STD_ON */ 

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_Read(
    VAR( uint16, AUTOMATIC ) BlockNumber,
    VAR( uint16, AUTOMATIC ) BlockOffset,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr,
    VAR( uint16, AUTOMATIC ) Length );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_Write(
   VAR( uint16, AUTOMATIC ) BlockNumber,
   P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr);

extern FUNC( void, FEE_CODE ) Fee_Cancel( void );

extern FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void );

extern FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock(
    VAR( uint16, AUTOMATIC ) BlockNumber );

#if( FEE_VERSION_INFO_API == STD_ON )
extern FUNC( void, FEE_CODE ) Fee_GetVersionInfo(
    P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) VersionInfoPtr );
#endif /* FEE_VERSION_INFO_API == STD_ON */

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock(
    VAR( uint16, AUTOMATIC ) BlockNumber );

extern FUNC( void, FEE_CODE ) Fee_MainFunction( void );

extern FUNC( Fee_ClusterGroupRuntimeInfoType, FEE_CODE ) Fee_GetRunTimeInfo( 
    VAR( uint8, AUTOMATIC ) clrGrpIndex );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite ( 
    VAR( uint8, AUTOMATIC ) clrGrpIndex ); 


#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_h_REF_1 Repeatedly included but does not have a standard include guard */
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* FEE_H */
/** @} */
