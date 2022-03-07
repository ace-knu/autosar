/**
*   @file    Lin_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Lin NonAutosar high level interface implementation.
*   @details Lin NonAutosar high level interface implementation.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_NonASR_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_NonASR_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_NonASR_c_REF_3
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
/**
* @file           Lin_NonASR.c
*/
#include "Lin.h"
#include "Lin_NonASR.h"
#include "Lin_LLD.h"
#include "Lin_Linflex_LLD.h"
#include "Reg_Macros.h"
/*
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in 
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "Reg_eSys.h"
#include "Reg_eSys_LINFlex.h"
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Lin_NonASR.c
* @implements     DLIN02076
*/
#define LIN_VENDOR_ID_NONASR_C                      43
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_NonASR_c_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C       4
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_NonASR_c_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_NONASR_C       0
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_NonASR_c_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_NONASR_C    3
#define LIN_SW_MAJOR_VERSION_NONASR_C               1
#define LIN_SW_MINOR_VERSION_NONASR_C               0
#define LIN_SW_PATCH_VERSION_NONASR_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID)
    #error "Lin_NonASR.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin_LLD header file are of the same version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_LLD) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_LLD) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_LLD))
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_LLD.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if current file and LIN header file are of the same Autosar version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != STD_TYPES_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Lin_NonASR.c and Std_Types.h are different"
  #endif
  #ifdef LIN_GLOBAL_WAKEUP_SUPPORT
    /* Check if current file and LIN header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin_NonASR.c and EcuM_Cbk.h are different"
    #endif
  #endif /* LIN_GLOBAL_WAKEUP_SUPPORT */
  /* Check if current file and LIN header file are of the same Autosar version */
  #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin_NonASR.c and Dem.h are different"
    #endif
  #endif
#endif
/* Check if current file and DET header file are of the same version */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin_NonASR.c and Det.h are different"
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
/* @violates @ref Lin_NonASR_c_REF_3 This is required as per Autosar Requirement. */
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Lin_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
/*
* @violates @ref Lin_NonASR_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "MemMap.h"
/**
* @brief          Lin clock modes.
* @details        Global variable to allow the appication
*                 to switch to the alternate clock mode.
*
* @implements     DLIN07202
*
* @note           Possible clock modes: LIN_NORMAL (normal execution mode),
*                 LIN_ALTERNATE (low power mode).
*/

#if LIN_DUAL_CLOCK_MODE == STD_ON
VAR(Lin_ClockModes,LIN_VAR)LinClock = LIN_NORMAL;
#endif

/* @violates @ref Lin_NonASR_c_REF_3 This is required as per Autosar Requirement. */
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Lin_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
/*
* @violates @ref Lin_NonASR_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
/*
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if LIN_DUAL_CLOCK_MODE == STD_ON

/**
* @brief          Lin_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the 
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all 
*                 the Lin channels.
*
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @implements     DLIN07202
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_SetClockMode(VAR(Lin_ClockModes,
                                                AUTOMATIC) ClockMode)
{
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (uint8)E_OK;
    VAR(uint8,AUTOMATIC) chLoop;
    VAR(uint8,AUTOMATIC) Lin_LINFlex;
    VAR(Lin_StatusType,AUTOMATIC) LinStatus = LIN_NOT_OK;
    VAR(uint8,AUTOMATIC) *linSduPtr[1];
    VAR(uint8,AUTOMATIC) linSdu[8] = {(uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0};
    linSduPtr[0] = linSdu;

    for(chLoop=(uint8)0U; chLoop < LIN_HW_MAX_MODULES; chLoop++)
    {
      /* Get the hardware Lin channel from logical channel */
      Lin_LINFlex = Lin_Channel_Cfg_Ptr[chLoop]->LinChannelID;

      LinStatus = Lin_GetStatus(chLoop, linSduPtr);

      switch (LinStatus)
      {
          case LIN_NOT_OK :

          /* If the LIN driver or some channels are not initialized it's not possible to
             change the baudrate */
               TempReturn = (uint8)E_NOT_OK;

               break;

          default :

          /* Switch to Initialization mode */
              LINFLEX_LLM_ENTER_INIT_MODE(Lin_LINFlex);

          /* Clear sleep mode */
              LINFLEX_LLM_EXIT_SLEEP_MODE(Lin_LINFlex);

              if (ClockMode == LIN_NORMAL)
              {
               LINFLEX_LLM_SET_BAUDRATE(Lin_LINFlex, Lin_Cfg_Ptr->Lin_Channel[chLoop]->Lin_BaudRate_RegValue);
              }
              else
              {
               LINFLEX_LLM_SET_BAUDRATE(Lin_LINFlex, Lin_Cfg_Ptr->Lin_Channel[chLoop]->Lin_BaudRate_RegValue_Alternate);
              }

          /* Exit Init mode and switch to Normal mode */
              LINFLEX_LLM_EXIT_INIT_MODE(Lin_LINFlex);

          break;
      }
    }
     return TempReturn;
  }

#endif /* DUAL CLOCK MODE */

#define LIN_STOP_SEC_CODE
/*
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
