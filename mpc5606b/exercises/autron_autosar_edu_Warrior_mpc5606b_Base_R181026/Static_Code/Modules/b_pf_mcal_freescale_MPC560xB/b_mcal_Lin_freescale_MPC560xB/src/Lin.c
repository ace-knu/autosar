/**
*   @file    Lin.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - High level part of LIN driver.
*   @details This file contains the functions defined by AutoSAR.
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
* @section Lin_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a 
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_c_REF_5
* Violates MISRA 2004 Required Rule 10.1,
* The value of an expression of integer type shall not be implicitly
* converted to a different underlying type.
*
* @section Lin_c_REF_6
* Violates MISRA 2004 Advisory Rule 16.7,
* A pointer parameter in a function prototype should be declared as
* pointer to constif the pointer is not used to modify the addressed
* object.
*
* @section Lin_c_REF_7
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
/* @implements     DLIN02080 */
#include "Lin.h"
#include "Lin_LLD.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @implements     DLIN05019 */
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DLIN02071 */
#define LIN_VENDOR_ID_C                      43
#define LIN_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Lin_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_C    3
#define LIN_SW_MAJOR_VERSION_C               1
#define LIN_SW_MINOR_VERSION_C               0
#define LIN_SW_PATCH_VERSION_C               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION))
    #error "Software Version Numbers of Lin.c and Lin.h are different"
#endif
/* Check if current file and Lin_LLD header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION_LLD) || \
     (LIN_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION_LLD) || \
     (LIN_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION_LLD))
    #error "AutoSar Version Numbers of Lin.c and Lin_LLD.h are different"
#endif
/* Check if current file and Lin_LLD header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION_LLD) || \
     (LIN_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION_LLD))
    #error "Software Version Numbers of Lin.c and Lin_LLD.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and Std_Types header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_C != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Std_Types.h are different"
  #endif
#ifdef LIN_GLOBAL_WAKEUP_SUPPORT
  /* Check if the source file and EcuM_Cbk header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_C != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Lin.c and EcuM_Cbk.h are different"
  #endif
  /* Check if the source file and EcuM_Cfg header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != ECUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_C != ECUM_CFG_AR_RELEASE_MINOR_VERSION))
      #error "Software Version Numbers of Lin.c and EcuM_Cfg.h are different"
  #endif
#endif /* LIN_GLOBAL_WAKEUP_SUPPORT */
  #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
  /* Check if the source file and Dem header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Lin.c and Dem.h are different"
  #endif
  #endif
#endif
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Det header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin.c and Det.h are different"
    #endif
  #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* put all LIN variables into defined section */
/* @violates @ref Lin_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
* @implements     DLIN02062
*/
P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) Lin_Cfg_Ptr = NULL_PTR;

/* @violates @ref Lin_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"


/* @violates @ref Lin_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
* @implements     DLIN02061
*/
P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST) Lin_Channel_Cfg_Ptr[LIN_HW_MAX_MODULES];

/* @violates @ref Lin_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"



#define LIN_START_SEC_VAR_INIT_8
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief          LIN driver status variable.
* @details        LIN driver state machine.
* @implements     DLIN02064
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
VAR(uint8,LIN_VAR)Lin_LinDrvStatus = LIN_UNINIT;


#define LIN_STOP_SEC_VAR_INIT_8
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"



#define LIN_START_SEC_VAR_NO_INIT_8
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief          LIN channel state variable.
* @details        LIN channel state machine.
* @implements     DLIN02063
*/
volatile VAR(uint8,LIN_VAR)Lin_LinChStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN frame state variable.
* @details        LIN frame state.
* @implements     DLIN02065
*/
volatile VAR(uint8,LIN_VAR)Lin_LinChFrameStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN Frame header state variable.
* @details        LIN Frame header state.
* @implements     DLIN02066
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
volatile VAR(uint8,LIN_VAR)Lin_LinChHeaderStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN Frame error status variable.
* @details        LIN Frame error status.
* @implements     DLIN02067
*/
volatile VAR(uint8,LIN_VAR)Lin_LinChFrameErrorStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN channel hardware map variable.
* @details        Lin channel hardware map.
* @implements     DLIN02068
*/
VAR(sint8,LIN_VAR)Lin_ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

/**
* @brief          LIN header command type variable.
* @details        LIN header command type.
* @implements     DLIN02069
*/
VAR(uint8, LIN_VAR) TransmitHeaderCommand[LIN_HW_MAX_MODULES];

/**
* @brief          LIN SDU buffer variable.
* @details        LIN SDU buffer to be returned.
* @implements     DLIN02070
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
VAR(uint8, AUTOMATIC) LinSduBuffAddress[LIN_HW_MAX_MODULES][LIN_MAX_DATA_LENGTH];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @note put all LIN code into defined section
*/
#define LIN_START_SEC_CODE
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN 
*          driver: 
*          - Clears the shadow buffer of all available Lin channels
*          - Set LIN channel state machine of all available Lin
*            channels to LIN_CH_OPERATIONAL_STATE
*          - Set frame operation state machine of all available LIN
*            channels to LIN_CH_READY_STATE
*          - Set driver state machine to LIN_INIT.
*
* @param[in] Config        Pointer to LIN driver configuration set.
*
* @return  void
*
* @api
*
* @implements   DLIN07400, DLIN07401, DLIN07402,
*               DLIN07403, DLIN07404, DLIN07405,
*               DLIN07406, DLIN07407, DLIN07408,
*               DLIN07409, DLIN07410, DLIN07411,
*               DLIN09003
* @note    Autosar Service ID: 0x00.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(void, LIN_CODE) Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config)
    {
    VAR(uint8,AUTOMATIC) Lin_ChLoop;
    VAR(uint8,AUTOMATIC) Lin_Hw_ChLoop;
    VAR(uint8,AUTOMATIC) Length;
    /* Check whether the LIN driver is in LIN_UNINIT state */
    /* @implements DLIN07405, DLIN07406 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)    
    if (Lin_LinDrvStatus != LIN_UNINIT)
        {
        /* LIN driver has been already initialized */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_INIT_ID,\
                (uint8)LIN_E_STATE_TRANSITION);
        }
        else
        {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
        /* In case of Variant PC: The configuration pointer which is passed to Lin_Init */
        /* shall be a NULL pointer. IN this case update the config pointer with default */
        /* configuration. */
        /* @implements DLIN07411 */
        Lin_Cfg_Ptr = &Lin_ConfigPC;
#endif /* #if (LIN_PRECOMPILE_SUPPORT == STD_ON) */

#if (LIN_PRECOMPILE_SUPPORT == STD_OFF)
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
            if ( NULL_PTR == Config )
            {
                /* Invalid pointer */
                /* @implements DLIN07403, DLIN07404 */
                Det_ReportError ((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_INIT_ID,\
                 (uint8)LIN_E_INVALID_POINTER);
            }
            else
            {
    #endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

                /* Copy pointer to current Lin Driver configuration. */
                /* @implements DLIN07401 */
                Lin_Cfg_Ptr = Config;
#endif /* #if (LIN_PRECOMPILE_SUPPORT == STD_OFF) */

                for(Lin_Hw_ChLoop=(uint8)0U;Lin_Hw_ChLoop<LIN_HW_MAX_AVAILABLE_MODULES;Lin_Hw_ChLoop++)
                {
                    Lin_ChannelHardwareMap[Lin_Hw_ChLoop]= -1;
                }
                for(Lin_ChLoop=(uint8)0U;Lin_ChLoop<LIN_HW_MAX_MODULES;Lin_ChLoop++)
                {
                    for(Length=(uint8)0U;Length<LIN_MAX_DATA_LENGTH;Length++)
                    {
                        LinSduBuffAddress[Lin_ChLoop][Length]= (uint8)0;
                    }
                }
                for(Lin_ChLoop=(uint8)0U;Lin_ChLoop<LIN_HW_MAX_MODULES;Lin_ChLoop++)
                {
                    Lin_Channel_Cfg_Ptr[Lin_ChLoop] = Lin_Cfg_Ptr->Lin_Channel[Lin_ChLoop];
                    /* @implements DLIN07408 */
                    Lin_LLD_InitChannel(Lin_ChLoop);
                    /* Set LIN channel state machine to LIN_CH_OPERATIONAL_STATE */
                    /* @implements DLIN07409 */
                    Lin_LinChStatus[Lin_ChLoop] = LIN_CH_OPERATIONAL_STATE;
                    /* Set LIN channel frame operation status to LIN_CH_READY_STATE */
                    Lin_LinChFrameStatus[Lin_ChLoop] = LIN_CH_READY_STATE;
                    /* Header status flag */
                    Lin_LinChHeaderStatus[Lin_ChLoop] = (uint8)FALSE;
                    /* Reset header command type */
                    TransmitHeaderCommand[Lin_ChLoop] = LIN_TX_NO_COMMAND;
                    /* Reset error status global flag */
                    Lin_LinChFrameErrorStatus[Lin_ChLoop] = LIN_NO_ERROR;
                    /* Map configured hardware channel to logical channel */
                    Lin_ChannelHardwareMap[Lin_Channel_Cfg_Ptr[Lin_ChLoop]->LinChannelID] = (sint8)Lin_ChLoop;
                }
                /* Update LIN driver status to LIN_INIT */
                /* @implements DLIN07402 */
                Lin_LinDrvStatus = LIN_INIT;
#if (LIN_PRECOMPILE_SUPPORT == STD_OFF)
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
            }
    #endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
#endif /* #if (LIN_PRECOMPILE_SUPPORT == STD_OFF) */
#if (LIN_DEV_ERROR_DETECT == STD_ON)    
        }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return; /* Exit function with no return */
    }

/**
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          the addressed LIN Channel is not
*                          in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements   DLIN07700, DLIN07701, DLIN07702,
*               DLIN07703, DLIN07704, DLIN07705,
*               DLIN07707, DLIN07708, DLIN07709,
*               DLIN07710, DLIN07711
* @note    Autosar Service ID: 0x0A.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07701, DLIN07702 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_CHECKWAKEUP_ID, \
                (uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = (uint8)E_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07712, DLIN07713 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_CHECKWAKEUP_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn = (uint8)E_NOT_OK;
            }
        else
            {
               tempReturn = (uint8)E_OK;
               /* The addressed LIN channel is initialized */
               /* chInSleep = 0U;*/
               /* Check if the addressed LIN channel is in */
               /* LIN_CH_SLEEP_STATE state */
                if (Lin_LinChStatus[Channel] == LIN_CH_SLEEP_STATE)
                    {
                    /* 'Channel' is in LIN_CH_SLEEP_STATE state */
                    /*chInSleep++;*/
                    /* Check if 'Channel' has detected a wake-up and */
                    /* its wake up ISR is disabled */
                    /* @implements DLIN07710 */
                    if (Lin_LLD_CheckWakeup(Channel) == (uint8)TRUE)
                        {
                           /* @implements DLIN07708 */
#ifdef LIN_GLOBAL_WAKEUP_SUPPORT
                           /* @implements DLIN07709 */
                           /* Indicates a valid timer wakeup event to ECU State Manager */
                           EcuM_SetWakeupEvent(Lin_Channel_Cfg_Ptr[Channel]->LinChannelEcuMWakeupSource);
#endif
                           /* Update LIN channel status to LIN_CH_OPERATIONAL_STATE */
                           /* @implements DLIN07711 */
                           Lin_LinChStatus[Channel] = LIN_CH_OPERATIONAL_STATE;

                           /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                           Lin_LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
                        }
                    }
            }
            /* @implements DLIN07703, DLIN07704 */
/*#if (LIN_DEV_ERROR_DETECT == STD_ON)
            if(chInSleep == 0U)
                {*/
                /* no LIN channel in sleep */
                /* Report error to development error tracer */
/*                Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0, (uint8)LIN_CHECKWAKEUP_ID, \
                    (uint8)LIN_E_STATE_TRANSITION);
                  tempReturn = (uint8)E_NOT_OK;
                }*/
/*#endif*/ /* (LIN_DEV_ERROR_DETECT == STD_ON) */

        }
    return tempReturn;
    }

/**
* @brief   Gets the status of the LIN driver.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in] Channel       LIN channel to be checked.
*
* @param[out] Lin_SduPtr   Lin_SduPtr pointer to pointer to a shadow
*                          buffer or memory mapped LIN Hardware
*                          receive buffer where the current SDU is
*                          stored.
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error rised
*                          none of the below conditions.
* @retval LIN_TX_OK        Successful transmission.
* @retval LIN_TX_BUSY      Ongoing transmission of header or response.
* @retval LIN_TX_HEADER_ERROR Error occurred during header 
*                          transmission.
* @retval LIN_TX_ERROR     Error occurred during response 
*                          transmission.
* @retval LIN_RX_OK        Reception of correct response.
* @retval LIN_RX_BUSY      Ongoing reception where at least one byte
*                          has been received.
* @retval LIN_RX_ERROR     Error occurred during reception.
* @retval LIN_RX_NO_REPONSE No data byte has been received yet.
* @retval LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data are available.
* @retval LIN_CH_SLEEP     Channel is in sleep mode.
*
* @api
*
* @implements   DLIN07750, DLIN07751, DLIN07752,
*               DLIN07753, DLIN07754, DLIN07755,
*               DLIN07756, DLIN07757, DLIN07758,
*               DLIN07759, DLIN07760, DLIN07761,
*               DLIN07762, DLIN07763
* @note    Autosar Service ID: 0x08.
* @note    Synchronous, non reentrant function.
*
*/
/* 
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, \
                                         P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
    {
    VAR(Lin_StatusType, AUTOMATIC) tempReturn = LIN_NOT_OK;
    /* Check whether the LIN driver is in LIN_INIT state */
    if(Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07753, DLIN07754, DLIN07755 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GETSTATUS_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = LIN_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07753, DLIN07756, DLIN07757 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GETSTATUS_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn = LIN_NOT_OK;
            }
        else
            {
                /* Check PduInfoPtr for not being a null pointer */
                if(Lin_SduPtr == NULL_PTR)
                    {
                    /* Invalid pointer */
                    /* @implements DLIN07753, DLIN07758, DLIN07759 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GETSTATUS_ID,\
                        (uint8)LIN_E_PARAM_POINTER);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    tempReturn = LIN_NOT_OK;
                    }
                else
                    {
                        /* LIN channel state */
                        /* @implements DLIN07760 */
                        switch(Lin_LinChStatus[Channel])
                            {
                            case LIN_CH_SLEEP_STATE:
                                /* @implements DLIN07762 */
                                tempReturn = LIN_CH_SLEEP;
                                break;
                            case LIN_CH_OPERATIONAL_STATE:
                                /* LIN Channel frame state */
                                /* Initialize the pointer to return with */
                                /* the address of the data receive buffer */
                                /* @implements DLIN07751 */
                                *Lin_SduPtr = LinSduBuffAddress[Channel];

                                /* @implements DLIN07752, DLIN07763 */
                                tempReturn = Lin_LLD_HardwareGetStatus(Channel, LinSduBuffAddress[Channel]);
                                break;
                            default :
                /* @implements DLIN07761 */
                Cer_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GETSTATUS_ID,(uint8)LIN_E_DEFAULT);
                        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                              Cer_ReportError() function implementation */
                                break;
                            }

                    }
                }

        }
    return tempReturn;
    }

/**
* @brief   The service instructs the driver to transmit a
*          go-to-sleep-command on the addressed LIN channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command
*          frame with ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF,
*          0xFF, 0xFF, 0xFF, 0xFF). State transition in
*          LIN_CH_SLEEP_STATE shall be done after the completion of
*          the sleep command transmission regardless of the success
*          (therefore the ISR is responsible to put the channel in
*          LIN_CH_SLEEP_STATE).
*
* @param[in] Channel       LIN channel to be checked.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements   DLIN07800, DLIN07801, DLIN07802,
*               DLIN07803, DLIN07804, DLIN07805,
*               DLIN07806, DLIN07807, DLIN07808,
*               DLIN07809, DLIN07810, DLIN07811
* @note    Autosar Service ID: 0x06.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    /* Check whether the LIN driver is in LIN_INIT state */
    if (Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07803, DLIN07804 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = (uint8)E_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07805, DLIN07806 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEP_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn = (uint8)E_NOT_OK;
            }
        else
            {
                /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
                if(Lin_LinChStatus[Channel] == LIN_CH_SLEEP_STATE)
                    {
                    /* LIN channel is in sleep mode */
                    /* @implements DLIN07807, DLIN07808 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEP_ID,\
                        (uint8)LIN_E_STATE_TRANSITION);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    tempReturn = (uint8)E_NOT_OK;
                    }
                else
                    {
                    TransmitHeaderCommand[Channel] = LIN_TX_SLEEP_COMMAND;
                    /* @implements DLIN07801, DLIN07809, DLIN07810 */
                    if(Lin_LLD_GoToSleep(Channel) == (uint8)E_NOT_OK)
                        {
                        /* Report Production error */
                        /* @implements DLIN07802 */
                        #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                        /*
                        * @violates @ref Lin_c_REF_5 The value of an expression of
                        * integer type shall not be implicitlyconverted to a different
                        * underlying type
                        */
                        if (STD_ON == Lin_Cfg_Ptr->Lin_E_TimeoutCfg.state)
                        {
                          Dem_ReportErrorStatus((Dem_EventIdType)Lin_Cfg_Ptr->Lin_E_TimeoutCfg.id,\
                                                DEM_EVENT_STATUS_FAILED);
                        }    
                        #endif
                        tempReturn = (uint8)E_NOT_OK;
                        }
                    else
                        {
                        tempReturn = (uint8)E_OK;
                        }
                    }
            }
        }
    return tempReturn;
    }

/**
* @brief   Put a Lin channel in the internal sleep state.
* @details Stops any ongoing transmission, sets the channel
*          state to LIN_CH_SLEEP and put the LIN
*          hardware unit to a reduced power operation mode.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements   DLIN07300, DLIN07301, DLIN07302,
*               DLIN07303, DLIN07304, DLIN07305,
*               DLIN07306, DLIN07307, DLIN07308,
*               DLIN07309, DLIN07310, DLIN07311,
*               DLIN07312, DLIN07313, DLIN07314,
*               DLIN07315, DLIN07316
* @note    Autosar Service ID: 0x09.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    /* Check whether the LIN driver is in LIN_INIT state */
    if (Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07310, DLIN07311 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEPINTERNAL_ID,\
                (uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = (uint8)E_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07308, DLIN07309 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEPINTERNAL_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn =  (uint8)E_NOT_OK;
            }
        else
            {
                /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
                if (Lin_LinChStatus[Channel] == LIN_CH_SLEEP_STATE)
                    {
                    /* LIN channel is in sleep mode */
                    /* @implements DLIN07306, DLIN07307 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Det_ReportError((uint16) LIN_MODULE_ID, (uint8) 0, \
                (uint8) LIN_GOTOSLEEPINTERNAL_ID, (uint8) LIN_E_STATE_TRANSITION);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    tempReturn = (uint8)E_NOT_OK;
                    }
                else
                    {
                    /* Call LLD function */
                    /* @implements DLIN07313, DLIN07314, DLIN07315, DLIN07316 */
                    if(Lin_LLD_GoToSleepInternal(Channel) == (uint8)E_NOT_OK)
                        {
                        /* Report Production error */
                        /* @implements DLIN07302 */
                        #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                        /*
                        * @violates @ref Lin_c_REF_5 The value of an expression of
                        * integer type shall not be implicitlyconverted to a different
                        * underlying type
                        */
                        if (STD_ON == Lin_Cfg_Ptr->Lin_E_TimeoutCfg.state)
                        {
                          Dem_ReportErrorStatus((Dem_EventIdType)Lin_Cfg_Ptr->Lin_E_TimeoutCfg.id,\
                                                DEM_EVENT_STATUS_FAILED);
                        }    
                        #endif
                        tempReturn = (uint8)E_NOT_OK;
                        }
                    else
                        {
                        /* Update LIN channel status to LIN_CH_SLEEP_STATE */
                        /* @implements DLIN07305 */
                        Lin_LinChStatus[Channel] = LIN_CH_SLEEP_STATE;
                        /* Update LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
                        Lin_LinChFrameStatus[Channel] = LIN_CH_NOT_READY_STATE;
                        tempReturn = (uint8)E_OK;
                        }
                    }
            }
        }
    return tempReturn;
    }

/**
* @brief   Sends a LIN frame.
* @details Sends a LIN header and a LIN response, if necessary. The
*          direction of the frame response (master response, slave
*          response, slave-to-slave communication) is provided by
*          the PduInfoPtr.
*
* @param[in] Channel       LIN channel to be addressed.
* @param[in] PduInfoPtr    pointer to PDU containing the PID,
*                          Checksum model, Response type, Dl and SDU
*                          data pointer.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          PduInfoPtr is NULL or
*                          a timeout occurs or
*                          LIN Channel is in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements   DLIN07500, DLIN07501, DLIN07502,
*               DLIN07503, DLIN07504, DLIN07505,
*               DLIN07506, DLIN07507, DLIN07508,
*               DLIN07509, DLIN07510, DLIN07511,
*               DLIN07512, DLIN07513, DLIN07514,
*               DLIN07515, DLIN07516, DLIN07517,
*               DLIN07518, DLIN07519, DLIN07520,
*               DLIN07521, DLIN07522
* @note    Autosar Service ID: 0x04.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, \
                            P2VAR(Lin_PduType, AUTOMATIC, LIN_APPL_DATA) PduInfoPtr)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    /* Check whether the LIN driver is in LIN_INIT state */
    if (Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07511, DLIN07512 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_SENDFRAME_ID,\
                (uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = (uint8)E_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07509, DLIN07510 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_SENDFRAME_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn = (uint8)E_NOT_OK;
            }
        else
            {
                /* Check PduInfoPtr for not being a null pointer */
                if (PduInfoPtr == NULL_PTR)
                    {
                    /* Invalid pointer */
                    /* @implements DLIN07513, DLIN07514 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_SENDFRAME_ID,\
                        (uint8)LIN_E_PARAM_POINTER);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    tempReturn = (uint8)E_NOT_OK;
                    }
                else
                    {
                    /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
                    if (Lin_LinChStatus[Channel] == LIN_CH_SLEEP_STATE)
                        {
                        /* LIN channel is in sleep mode */
                        /* @implements DLIN07507, DLIN07508 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_SENDFRAME_ID,\
                            (uint8)LIN_E_STATE_TRANSITION);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                        tempReturn = (uint8)E_NOT_OK;
                        }
                    else
                        {
                        /* Reset error status global flag */
                        Lin_LinChFrameErrorStatus[Channel] = LIN_NO_ERROR;
                        /* Set header status to TRUE if master wants to send the response frame */
                        if (PduInfoPtr->Drc == LIN_MASTER_RESPONSE)
                            {
                            Lin_LinChHeaderStatus[Channel]= (uint8)TRUE;
                            TransmitHeaderCommand[Channel] = LIN_TX_MASTER_RES_COMMAND;
                            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                            Lin_LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
                            }
                        else
                            {
                            TransmitHeaderCommand[Channel] = LIN_TX_SLAVE_RES_COMMAND;
                            Lin_LinChFrameStatus[Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
                            }
                        /* @implements DLIN07502, DLIN07515 */
                        if(Lin_LLD_SendHeader(Channel,PduInfoPtr) == (uint8)E_NOT_OK)
                            {
                            /* Report Production error */
                            /* @implements DLIN07501 */
                            #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                            /*
                            * @violates @ref Lin_c_REF_5 The value of an expression of
                            * integer type shall not be implicitlyconverted to a different
                            * underlying type
                            */
                            if (STD_ON == Lin_Cfg_Ptr->Lin_E_TimeoutCfg.state)
                            {
                            Dem_ReportErrorStatus((Dem_EventIdType)Lin_Cfg_Ptr->Lin_E_TimeoutCfg.id,\
                                                DEM_EVENT_STATUS_FAILED);
                            }    
                            #endif
                            tempReturn = (uint8)E_NOT_OK;
                            }
                        else
                            {
                              /* Lin_SendHeader() function should be called first */
                              if (Lin_LinChHeaderStatus[Channel] != (uint8)FALSE)
                                  {
                                  Lin_LinChHeaderStatus[Channel] = (uint8)FALSE;
                                  /* @implements DLIN07503 */
                                  Lin_LLD_SendResponse(Channel,PduInfoPtr);
                                  tempReturn = (uint8)E_OK;
                                  }
                              else
                                  {
                                  tempReturn = (uint8)E_OK;
                                  }
                            }
                        }
                    }

            }
        }
    return tempReturn;
    /*
    * @violates @ref Lin_c_REF_6 The parameter be declared as pointer according to ASR standard.
    */
    }

/**
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL_STATE state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements   DLIN07600, DLIN07601, DLIN07602,
*               DLIN07603, DLIN07604, DLIN07605,
*               DLIN07606, DLIN07607, DLIN07608,
*               DLIN07609, DLIN07610, DLIN07611
* @note    Autosar Service ID: 0x07.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    /* Check whether the LIN driver is in LIN_INIT state */
    if (Lin_LinDrvStatus != LIN_INIT)
        {
        /* LIN driver has not been initialized yet */
        /* @implements DLIN07606, DLIN07607 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_WAKEUP_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        tempReturn = (uint8)E_NOT_OK;
        }
    else
        {
        /* Check for invalid channel */
        if (Channel >= LIN_HW_MAX_MODULES)
            {
            /* Invalid channel */
            /* @implements DLIN07602, DLIN07603 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_WAKEUP_ID,\
                    (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            tempReturn = (uint8)E_NOT_OK;
            }
        else
            {
                /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
                if (Lin_LinChStatus[Channel] != LIN_CH_SLEEP_STATE)
                    {
                    /* LIN channel is not in sleep mode */
                    /* @implements DLIN07604, DLIN07605 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_WAKEUP_ID,\
                        (uint8)LIN_E_STATE_TRANSITION);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    tempReturn = (uint8)E_NOT_OK;
                    }
                else
                    {
                    /* Update LIN channel status to LIN_CH_OPERATIONAL_STATE */
                    /* @implements DLIN07601 */
                    Lin_LinChStatus[Channel] = LIN_CH_OPERATIONAL_STATE;
                    /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                    Lin_LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
                    /* Call LLD function */
                    /* @implements DLIN07608 */
                    Lin_LLD_WakeUp(Channel);
                    tempReturn = (uint8)E_OK;
                    }
            }
        }
    return tempReturn;
    }

/* @implements DLIN07102 */
#if (LIN_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not 
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return                  void.
*
* @api
*
* @pre            Preconditions as text description. Optional tag.
*
* @implements   DLIN07100, DLIN07101, DLIN07102,
*               DLIN07103, DLIN07104, DLIN07105,
*               DLIN07106
* @note    Autosar Service ID: 0x01.
* @note    Synchronous, non reentrant function.
*
*/
/*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
*                or functions at file scope shall have internal linkage
*                unless external linkage is required.
*/
FUNC (void, LIN_CODE) Lin_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, \
    LIN_APPL_DATA) versioninfo)
{
/* @implements DLIN07103, DLIN07104 */
#if( LIN_DEV_ERROR_DETECT == STD_ON )
    if( versioninfo == NULL_PTR )
    {
      Det_ReportError( (uint16)LIN_MODULE_ID,(uint8)0, (uint8)LIN_GETVERSIONINFO_ID, \
                       (uint8) LIN_E_PARAM_POINTER );
    }
    else
    {
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        (versioninfo)->vendorID = (uint16) LIN_VENDOR_ID;
        (versioninfo)->moduleID = (uint8) LIN_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) LIN_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) LIN_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) LIN_SW_PATCH_VERSION;
#if( LIN_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LIN_VERSION_INFO_API == STD_ON */ 

#define LIN_STOP_SEC_CODE
/*
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
