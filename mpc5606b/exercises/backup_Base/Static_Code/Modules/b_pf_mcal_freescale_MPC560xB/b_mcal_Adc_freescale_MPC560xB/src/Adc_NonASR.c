/**
*   @file    Adc_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Common Level Driver source file.
*   @details Non Autosar common layer of ADC MCAL driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
*   Dependencies         : none
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
* @section Adc_NonASR_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_NonASR_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the 
* contents of a header being included twice. 
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_NonASR_c_REF_3
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Adc_NonASR_c_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_NonASR_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, return statement before end of function. The return
* statement are used to simplify the code structure and easier readability.
*
* @section Adc_NonASR_c_REF_6
* Violates MISRA 2004 Advisory Rule 12.6, The operands of logical operators (&&, || and !)
* should be effectively Boolean. Expressions that are effectively Boolean should not be used
* as poerands to operators other than (&&, || and !).
*
* @section Adc_NonASR_c_REF_7
* Violates MISRA 2004 Required Rule 12.5, The operands of a logical && or || shall be primary-expressions
*
* @section Adc_NonASR_c_REF_8
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted
*
* @section Adc_NonASR_c_REF_9
* Violates MISRA 2004 Required Rule 10.1, Cast from integer type to different type or a wider integer type
* This is used for the Speed optimization of the memory access.
*
* @section Adc_NonASR_c_REF_10
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_NonASR_c_REF_11
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00003 */
#include "Adc.h"
#include "Adc_NonASR.h"
#include "Adc_LLD.h"
#include "SchM_Adc.h"

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Dem.h"
#endif

/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Mcal.h"
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DADC03028 */
#define ADC_NONASR_C_VENDOR_ID                      (43)
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION       (4)
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_NONASR_C_AR_RELEASE_MINOR_VERSION       (0)
/*
* @violates @ref Adc_NonASR_c_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_NONASR_C_AR_RELEASE_REVISION_VERSION    (3)
#define ADC_NONASR_C_SW_MAJOR_VERSION               (1)
#define ADC_NONASR_C_SW_MINOR_VERSION               (0)
#define ADC_NONASR_C_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06003 */
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_NONASR_C_VENDOR_ID != ADC_VENDOR_ID)
#error "Adc_NonASR.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_NonASR.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_NONASR_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)  || \
     (ADC_NONASR_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION)  || \
     (ADC_NONASR_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_NonASR.c and Adc.h are different"
#endif

#if (ADC_NONASR_C_VENDOR_ID != ADC_NONASR_VENDOR_ID)
#error "Adc_NonASR.c and Adc_NonASR.h have different vendor ids"
#endif

/* Check if source file and Adc_NonASR header file are of the same Autosar version */
#if ((ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION != ADC_NONASR_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_MINOR_VERSION != ADC_NONASR_AR_RELEASE_MINOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_REVISION_VERSION != ADC_NONASR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_NonASR.c and Adc_NonASR.h are different"
#endif

/* Check if source file and Adc_NonASR header file are of the same Software version */
#if ((ADC_NONASR_C_SW_MAJOR_VERSION != ADC_NONASR_SW_MAJOR_VERSION)  || \
     (ADC_NONASR_C_SW_MINOR_VERSION != ADC_NONASR_SW_MINOR_VERSION)  || \
     (ADC_NONASR_C_SW_PATCH_VERSION != ADC_NONASR_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_NonASR.c and Adc_NonASR.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same vendor */
#if (ADC_NONASR_C_VENDOR_ID != ADC_LLD_H_VENDOR_ID)
    #error "Adc_NonASR.c and Adc_LLD.h have different vendor ids"
#endif

/* Check if source file and ADC LLD header file are of the same Autosar version */
#if ((ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION != ADC_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_MINOR_VERSION != ADC_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_NONASR_C_AR_RELEASE_REVISION_VERSION != ADC_LLD_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_NonASR.c and Adc_LLD.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same Software version */
#if ((ADC_NONASR_C_SW_MAJOR_VERSION != ADC_LLD_H_SW_MAJOR_VERSION) || \
     (ADC_NONASR_C_SW_MINOR_VERSION != ADC_LLD_H_SW_MINOR_VERSION) || \
     (ADC_NONASR_C_SW_PATCH_VERSION != ADC_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_NonASR.c and Adc_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    /* Check if source file and Dem header file are of the same version */
    #if ((ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_NONASR_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc_NonASR.c and Dem.h are different"
    #endif
  #endif

 /* Check if source file and DET header file are of the same version */
 #if (ADC_DEV_ERROR_DETECT == STD_ON)
    #if ((ADC_NONASR_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_NONASR_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc_NonASR.c and Det.h are different"
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

/**
* @brief          Unit status structure
* @details        Structure for the unit status.
*
* @implements     DADC06011
*
*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)

/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

VAR(Adc_NCMR_Type, ADC_VAR) Adc_NCMRx_Mask[ADC_NO_OF_ENABLE_CH_DISABLE_CH_GROUPS];

/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/* @violates @ref Adc_NonASR_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

/* For Bolero 3M only */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_NonASR_c_REF_2 repeated inclusion of file MemMap.h */
/* @violates @ref Adc_NonASR_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

 #if (ADC_DUAL_CLOCK_MODE == STD_ON )
/**
* @brief          Set Clock Mode.
* @details        This flag is used to set Alternate Timing for Bolero 3M.
*
*/
VAR(Adc_NonASR_DualClockModeType, ADC_VAR) Adc_ClockMode;
 #endif /* ADC_DUAL_CLOCK_MODE == STD_ON == STD_ON */
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* Bolero 3M */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/* @violates @ref Adc_NonASR_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if (ADC_SET_MODE_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Set the ADC mode either to powerdown or normal.
* @details        Set the ADC either to powerdown or normal mode.
*
* @param[in]      SetMode         Normal or powerdown mode.
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           In case of successfull settings.
* @retval         E_NOT_OK:       In case of unsuccessfull settings.
*
* @api
*
* @implements     DADC03029
*
* @note           The function Non Autosar Service ID[hex]: 0x10.
* @note           Synchronous.
* @note           Non Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC (Std_ReturnType, ADC_CODE) Adc_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) SetMode
)
{
    /* Return standard value */
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_NOT_OK;
    VAR(uint8,AUTOMATIC) Group = 0U; /* Group index */

    if(Adc_Cfg_Ptr == NULL_PTR)
    {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        Det_ReportError((uint16) ADC_MODULE_ID,
                        (uint8) 0U,
                        (uint8) ADC_SETMODE_ID,
                        (uint8) ADC_E_UNINIT);
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* @violates @ref Adc_NonASR_c_REF_5 return statement before end of function. */
        return (TempReturn);
    }
    if(SetMode == ADC_POWER_DOWN_MODE)
    {
        VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0; /* HW unit index */
        VAR(boolean, AUTOMATIC) Returnval = (boolean)FALSE;
        for(unit=(uint8)0U; unit<(Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); unit++)
        {
            if((ADC_UnitStatus[unit].Status == ADC_BUSY)
        #if (ADC_HW_TRIGGER_API == STD_ON)
            ||(ADC_GroupsInHwQueue(unit)!=(Adc_QueueIndexType)0)
        #endif
            ) /* In this case any conversion is ongoing */
            {
                Returnval = (boolean)TRUE;
            }
        }
        /*
         * @violates @ref Adc_NonASR_c_REF_6 The operands of logical operators (&&, || and !)
         * @violates @ref Adc_NonASR_c_REF_7 The operands of a logical && or || shall be primary-expressions
         * @violates @ref Adc_NonASR_c_REF_8 Boolean operations whose results are invariant shall not be permitted
         * @violates @ref Adc_NonASR_c_REF_9 cast from integer type to a other type or a wider integer type
        */
        for(;((Group<(uint8)ADC_MAX_GROUPS) && (Returnval == (boolean)FALSE));Group++)
        {
           if((ADC_GroupStatus[Group].Conversion != ADC_IDLE)&&
              (ADC_GroupStatus[Group].Conversion != ADC_STREAM_COMPLETED))
           {
               Returnval = (boolean)TRUE;
           }
        }
        if(Returnval == (boolean)TRUE)
        {
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
            /* Can't enter into powerdown mode report error to DET */
            Det_ReportError((uint16) ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_SETMODE_ID,
                            (uint8)ADC_E_SET_MODE);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            /* @violates @ref Adc_NonASR_c_REF_5 return statement before end of function. */
            return (TempReturn);
        }
    }
    if ((SetMode == ADC_NORMAL_MODE)||(SetMode == ADC_POWER_DOWN_MODE))
    {
        /* @violates @ref Adc_NonASR_c_REF_5 return statement before end of function. */
        return(Adc_LLD_SetMode(SetMode));
    }
    else
    {   
         /* @violates @ref Adc_NonASR_c_REF_5 return statement before end of function. */
         return (TempReturn);
    }
}
#endif /* (ADC_SET_MODE_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__)
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enable the TriggerSource for group selected by Group parameter.
* @details        This non autosar API is used to enable any one of the configured
*                 TriggerSource of the Group. When this non autosar API is used to
*                 enable the trigger source the CTU interrupt will be disabled by the driver.
*                 So user has to call the non autosar API Adc_HwResultReadGroup to read
*                 the converted result from the ADC hardware register.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be used for the group.
*                                  (Configuration file should contain it for that group).
*
* @return         void
*
* @api
*
* @implements     DADC03030
*
* @note           The function Service ID[hex]: 0x0E.
* @note           Synchronous.
* @note           Non Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
 #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
    #if (ADC_ENABLE_QUEUING == STD_OFF)
      /* ADC Hardware Unit on which the requested group will run */
      VAR(Adc_HwUnitType,AUTOMATIC) unit = (Adc_HwUnitType)0;
      /* number of groups in software queue */
      VAR(Adc_QueueIndexType,AUTOMATIC) noGroupsInSWQueue = (Adc_QueueIndexType)0;
      /* number of groups in hardware queue */
      VAR(Adc_QueueIndexType,AUTOMATIC) noGroupsInHWQueue = (Adc_QueueIndexType)0;
    #endif /* (ADC_ENABLE_QUEUING == STD_OFF)  */
 #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    /*  Flag when error is reported */
    VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC297 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLECTUTRIGGER_ID,
                        (uint8)ADC_E_UNINIT);
        Error_flag = (boolean)TRUE;
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC128 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLECTUTRIGGER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
        Error_flag = (boolean)TRUE;
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount > (Adc_ChannelType)1U)
    {
        /* Error: Number of channels assigned greater than 1 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLECTUTRIGGER_ID,
                        (uint8)ADC_E_INVALID_CHANNEL_CONFIG);
        Error_flag = (boolean)TRUE;
    }
    else {
      /* do nothig for misra */
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Error_flag == (boolean)FALSE)
    {
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
        #if (ADC_ENABLE_QUEUING == STD_OFF)
            /* Get the unit to which the group belongs to */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            unit = ADC_GroupUnit(Group);
        #endif /* (ADC_ENABLE_QUEUING == STD_OFF) */
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        if (Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW)
        {
            /* ADC136 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_ENABLECTUTRIGGER_ID,
                            (uint8)ADC_E_WRONG_TRIGG_SRC);
        }
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        else if ((Adc_Cfg_Ptr->Groups[Group].mode) != ADC_CONV_MODE_ONESHOT)
        {
            /* ADC281 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_ENABLECTUTRIGGER_ID,
                            (uint8)ADC_E_WRONG_CONV_MODE);
        }
        else
        {
            /* enter critical section to protect agains queue modifications */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20();
            #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
             #if (ADC_ENABLE_QUEUING == STD_OFF)
            /* read now the HW and SW queue sizes */
            noGroupsInHWQueue= ADC_GroupsInHwQueue(unit); /* hardware queue size */
            noGroupsInSWQueue= ADC_UnitStatus[unit].QueueIndex; /* software queue size */
            /* In this case any conversion is ongoing */
            if ((noGroupsInSWQueue!=(Adc_QueueIndexType)0)||
                (noGroupsInHWQueue!=(Adc_QueueIndexType)0))
            {
                /* error occured, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20();
                /* ADC321 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLECTUTRIGGER_ID,
                                (uint8)ADC_E_BUSY);
            }
            else
             #endif/* (ADC_ENABLE_QUEUING == STD_OFF) */
            #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
            {
            /* everything ok, exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20();
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
                {
                    Adc_LLD_EnableCtuTrigger(Group,TriggerSource);
                }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            }
        }
    } /* (Error_flag == (boolean)FALSE) */
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}

/**
* @brief          Disable the TriggerSource for group selected by Group parameter.
* @details        This non autosar API is used to disable the already enabled
*                 TriggerSource of the Group.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be disabled for the group.
*                                  (Configuration file should contain it for that group).
*
* @return         void
*
* @api
*
* @implements     DADC03031.
*
* @note           The function Service ID[hex]: 0x0F.
* @note           Synchronous.
* @note           Non Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC298 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC129 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW)
    {
        /* ADC137 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if ((Adc_Cfg_Ptr->Groups[Group].mode) != ADC_CONV_MODE_ONESHOT)
    {
        /* ADC282 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_WRONG_CONV_MODE);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount > (Adc_ChannelType)1U)
    {
        /* Error: Number of channels assigned greater than 1 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_INVALID_CHANNEL_CONFIG);
    }
    else
#endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        Adc_LLD_DisableCtuTrigger(Group, TriggerSource);
    }
}

/**
* @brief          Read the result of the hardware triggered groups conversion result.
* @details        This non autosar API is used to read the result of the hardware
*                 triggered groups conversion result from the ADC hardware register
*                 in this case the CTU interrupt will be disabled for the group.
*                 The VALID bit CDR register will be cleared automatically when we read the results
*                 from the channel data register. If the user calls non-autosar function
*                 Adc_HwResultReadGroup() once again before the next conversion takes place, the
*                 Adc_HwResultReadGroup() returns E_NOT_OK.
*
* @param[in]      Group      Index of group.
* @param[in]      DataPtr    Pointer to a buffer which will be filled by the
*                            conversion results.
* @return         Std_ReturnType Standard return type.
* @retval         E_OK:          results are available and written to the
*                                data buffer.
* @retval         E_NOT_OK:      no results are available or development
*                                error occured.
* @api
*
* @implements     DADC03032.
*
* @note           The function Service ID[hex]: 0x0D.
* @note           Synchronous.
* @note           Non Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
)
{
    /* Standard return value */
    VAR(Std_ReturnType, AUTOMATIC) Adc_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC296 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_HWRESULTREADGROUP_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC152 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_HWRESULTREADGROUP_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    else
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        Adc_ReadGroupRet = Adc_LLD_HwResultReadGroup(Group, DataPtr);
    }

    return(Adc_ReadGroupRet);
}
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Set the ADC clock prescaler if avaialable and modify the conversion timings.
* @details        This function set the ADC clock prescaler (Analog clock frequency selector)
*
* @param[in]      ClockMode       Normal or Alternate mode.
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           In case of successfull settings.
* @retval         E_NOT_OK:       In case of unsuccessfull settings.
*
* @api
*
* @implements     DADC03033.
*
* @note           The function Service ID[hex]: 0x11.
* @note           Synchronous.
* @note           Non Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetClockMode
(
  VAR(Adc_NonASR_DualClockModeType, AUTOMATIC) ClockMode
)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Adc_Cfg_Ptr)
    {
        /* Error  */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_SETCLOCKMODE_ID,
                        (uint8)ADC_E_UNINIT);
        ret = (Std_ReturnType)E_NOT_OK;
    }
#endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON)*/
    /* @violates @ref Adc_NonASR_c_REF_8 Boolean operations whose results are invariant shall not be permitted */
    if ((Std_ReturnType)E_OK == ret)
    {
        ret = Adc_LLD_SetClockMode(ClockMode);
    }

    return ret;
}
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enable a channel inside a group.
* @details        This function allows to active a channel assigned to a group for SW normal conversion
*
* @param[in]      GroupId         Symbolic name of group.
* @param[in]      ChannelId       Symbolic name of channel.
*
* @return         void
*
* @api
*
* @implements     DADC06012.
*
* @note           The function Service ID[hex]: 0x12.
* @note           Synchronous.
* @note           Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableChannel
(
   VAR(Adc_GroupType, AUTOMATIC) GroupId,
   VAR(Adc_ChannelType, AUTOMATIC)ChannelId
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC) index = (uint8)0;
    VAR(boolean, AUTOMATIC) channelFound = (boolean)FALSE;
#endif
    VAR(Adc_ChannelType, AUTOMATIC) Adc_IdCh;
    VAR(Adc_GroupType, AUTOMATIC) Adc_GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
    VAR(Adc_HwUnitType, AUTOMATIC) UnitId = (Adc_HwUnitType)0;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* Error (ADC302): called prior to initializing */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLE_CHANNEL_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (GroupId >= Adc_Cfg_Ptr->GroupCount)
    {
        /* Error (ADC218): non-existing group ID */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLE_CHANNEL_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[GroupId].TriggerSource != ADC_TRIGG_SRC_SW)
    {
        /* Error (ADC133): trigger source configured as hardware */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if(Adc_Cfg_Ptr->Groups[GroupId].type != ADC_CONV_TYPE_NORMAL)
    {
        /* Error: If it is not the normal group converstion */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_CONV_MODE);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if((Adc_GroupType)Adc_Cfg_Ptr->Groups[GroupId].EnableChDisableChGroupIndex == 
             ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX)
    {
        /* Error: The Group does not support the individual channel enable or disable support */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP);
    }
    else
    {
        P2CONST(Adc_GroupDefType, AUTOMATIC, ADC_APPL_CONST) GroupChIndexPtr; /* Ptr to AdcGroupChIndex */
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        GroupChIndexPtr = Adc_Cfg_Ptr->Groups[GroupId].Assignment;

        /* Check if ChannelId is valid: assigned to that group */
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        for(index=(uint8)0;index<(uint8)(Adc_Cfg_Ptr->Groups[GroupId].AssignedChannelCount);index++)
        {
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            if((Adc_ChannelType)ChannelId == (Adc_ChannelType)GroupChIndexPtr[index])
            {
                channelFound = (boolean)TRUE;
                break;
            }
        }
    
        /* Further steps must only be done if the ChannelId is valid */
        if(channelFound != (boolean)TRUE)
        {
            /* Error: The Group doesnot support the individual channel enable or disable support */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_ENABLE_CHANNEL_ID,
                            (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID);
        }
        else
#endif
        {
            /* Get the unit to which the group belongs to */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            UnitId = ADC_GroupUnit(GroupId);
            
            /* Calculate HwChannelId of AdcChannel */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_IdCh = Adc_Cfg_Ptr->Channels[UnitId][ChannelId].ChId;

            /* Get the group index of the channels which supports individual channel enable or disable support */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_GroupId = (Adc_GroupType)Adc_Cfg_Ptr->Groups[GroupId].EnableChDisableChGroupIndex;

            /* Global Interrupt disable to protect code section */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25();

            if(Adc_IdCh < ADC_ST_EXTENDED_CH)
            {   /* Precision channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR0 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR0)|((uint32)(1U)<<Adc_IdCh));
            }
            else if ((Adc_IdCh >= ADC_ST_EXTENDED_CH) && (Adc_IdCh <= ADC_ED_EXTENDED_CH))
            {   /* Standard channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR1 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR1)|((uint32)(1U)<<(Adc_IdCh-ADC_ST_EXTENDED_CH)));
            }
            else if ((Adc_IdCh >= ADC_ST_EXTERNAL_CH) && (Adc_IdCh <= ADC_ED_EXTERNAL_CH))
            {   /* External multiplexed channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR2 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR2)|((uint32)(1U)<<(Adc_IdCh-ADC_ST_EXTERNAL_CH)));
            }
            else
            {
                /* Catastrophic Errors Recovery (CER) */
                Cer_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLE_CHANNEL_ID,
                                (uint8)ADC_CER_CHANNEL_ID_CORRUPTED_TYPE);
            }

            /* Global Interrupt enable to protect code section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25();
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
* @brief          Disable a channel inside a group.
* @details        This function allows to de-active a channel assigned to a group for SW normal conversion
*
* @param[in]      GroupId         Symbolic name of group.
* @param[in]      ChannelId       Symbolic name of channel.
*
* @return         void
*
* @api
*
* @implements     DADC06013.
*
* @note           The function Service ID[hex]: 0x13.
* @note           Synchronous.
* @note           Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableChannel
(
  VAR(Adc_GroupType, AUTOMATIC)GroupId,
  VAR(Adc_ChannelType, AUTOMATIC)ChannelId
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC) index = (uint8)0;
    VAR(boolean, AUTOMATIC) channelFound = (boolean)FALSE;
#endif
    VAR(Adc_ChannelType, AUTOMATIC) Adc_IdCh;
    VAR(Adc_GroupType, AUTOMATIC) Adc_GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
    VAR(Adc_HwUnitType, AUTOMATIC) UnitId = (Adc_HwUnitType)0;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* Error (ADC302): called prior to initializing */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLE_CHANNEL_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (GroupId >= Adc_Cfg_Ptr->GroupCount)
    {
        /* Error (ADC218): non-existing group ID */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLE_CHANNEL_ID,
                        (uint8) ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[GroupId].TriggerSource != ADC_TRIGG_SRC_SW)
    {
        /* Error (ADC133): trigger source configured as hardware */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if(Adc_Cfg_Ptr->Groups[GroupId].type != ADC_CONV_TYPE_NORMAL)
    {
        /* Error: If it is not the normal group converstion */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_CONV_MODE);
    }
    /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
    else if((Adc_GroupType)Adc_Cfg_Ptr->Groups[GroupId].EnableChDisableChGroupIndex == 
             ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX)
    {
        /* Error: The Group doesnot support the individual channel enable or disable support */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLE_CHANNEL_ID,
                        (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP);
    }
    else
    {
        P2CONST(Adc_GroupDefType, AUTOMATIC, ADC_APPL_CONST) GroupChIndexPtr; /* Ptr to AdcGroupChIndex */
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        GroupChIndexPtr = Adc_Cfg_Ptr->Groups[GroupId].Assignment;

        /* Check if ChannelId is valid */
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        for(index=(uint8)0;index<(uint8)(Adc_Cfg_Ptr->Groups[GroupId].AssignedChannelCount);index++)
        {
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            if((Adc_ChannelType)ChannelId == (Adc_ChannelType)GroupChIndexPtr[index])
            {
                channelFound = (boolean)TRUE;
                break;
            }
        }
    
        /* Further steps must only be done if the ChannelId is valid */
        if(channelFound != (boolean)TRUE)
        {
            /* Error: The Group doesnot support the individual channel enable or disable support */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_DISABLE_CHANNEL_ID,
                            (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID);
        }
        else
#endif
        {
            /* Get the unit to which the group belongs to */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            UnitId = ADC_GroupUnit(GroupId);

            /* Calculate HwChannelId of AdcChannel */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_IdCh = Adc_Cfg_Ptr->Channels[UnitId][ChannelId].ChId;

            /* Get the group index of the channels which supports individual channel enable or disable support */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_GroupId = (Adc_GroupType)Adc_Cfg_Ptr->Groups[GroupId].EnableChDisableChGroupIndex;

            /* Global Interrupt disable to protect code section */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25();

            if(Adc_IdCh < ADC_ST_EXTENDED_CH)
            {   /* Precision channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR0 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR0)&(~((uint32)(1U)<<Adc_IdCh)));
            }
            else if ((Adc_IdCh >= ADC_ST_EXTENDED_CH) && (Adc_IdCh <= ADC_ED_EXTENDED_CH))
            {   /* Standard channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR1 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR1)&(~((uint32)(1U)<<(Adc_IdCh-ADC_ST_EXTENDED_CH))));
            }
            else if ((Adc_IdCh >= ADC_ST_EXTERNAL_CH) && (Adc_IdCh <= ADC_ED_EXTERNAL_CH))
            {   /* External multiplexed channel */
                Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR2 = ((Adc_NCMRx_Mask[Adc_GroupId].Adc_NCMR2)&(~((uint32)(1U)<<(Adc_IdCh-ADC_ST_EXTERNAL_CH))));
            }
            else
            {
                /* Catastrophic Errors Recovery (CER) */
                Cer_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_DISABLE_CHANNEL_ID,
                                (uint8)ADC_CER_CHANNEL_ID_CORRUPTED_TYPE);
            }

            /* Global Interrupt enable to protect code section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25();
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Get the injected conversions status.
* @details        This function checks if an injected conversion (HW/SW) is ongoing
*
* @param[in]      unit            ADC Unit id.
*
* @return         Adc_StatusType  Status of the ADC HW unit.
* @retval         ADC_IDLE:       SW/HW Injection or Hardware Trigger group are idle.
* @retval         ADC_BUSY:       SW/HW Injection or Hardware Trigger is inprogress.
*
* @api
*
* @implements     DADC06014.
*
* @note           The function Service ID[hex]: 0x14.
* @note           Synchronous.
* @note           Reentrant function.
* @note           Not usable for ANDORRA.
*/
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetInjectedConversionStatus
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
    VAR(Adc_StatusType, AUTOMATIC) tempReturn = (Adc_StatusType)ADC_IDLE;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* Error (ADC301): called prior to initializing */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETINJECTEDCONVERSIONSTATUS_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (unit >= ADC_MAX_HW_UNITS)
    {
        /* Error (ADC225): non-existing group ID */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETINJECTEDCONVERSIONSTATUS_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    else
#endif
    { 
        if (ADC_UnitStatus[unit].SwInjQueueIndex > (Adc_QueueIndexType)0)
        {
            tempReturn = (Adc_StatusType)ADC_BUSY;
        }
        #if (STD_ON==ADC_HW_TRIGGER_API)
        else if (ADC_UnitStatus[unit].HwQueueIndex > (Adc_QueueIndexType)0)
        {
            tempReturn = (Adc_StatusType)Adc_LLD_GetInjectedConversionStatus(unit);
        }
        #endif
        else
        {
            tempReturn = (Adc_StatusType)ADC_IDLE;
        }
    }
    return (tempReturn);
}
#endif /* (ADC_GET_INJECTED_CONVERSION_STATUS_API) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
 * @brief   Function to reconfigure High and Low thresholds for a given group.
 *
 * @details This Non Autosar API is used to reconfigure High and Low thresholds for a given group.
 *
 * @note    The function Service ID[hex]: 0x14.
 *
 * @param[in]  GroupId          Index of group
 * @param[in]  LowValue         Low threshold value for channels in the group
 * @param[in]  HighValue        High threshold value for channels in the group
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successfull Configure Threshold.
 * @retval         E_NOT_OK        In case of unsuccessfull ConfigureThreshold.
 *
 * @remarks Implements
 *
 * @api
 */
/* @violates @ref Adc_NonASR_c_REF_3 Declaration and definition of objects or function */
FUNC(Std_ReturnType, ADC_CODE) Adc_ConfigureThreshold
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
  VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ChCount = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  VAR(boolean, AUTOMATIC) ThresholdEnabled = (boolean)FALSE;
  VAR(uint32, AUTOMATIC) MaxHighValue = (uint32)0;
  VAR(uint8, AUTOMATIC) HwIndex = (uint8)0;
  #endif /* if (ADC_DEV_ERROR_DETECT == STD_ON) */

  VAR(Std_ReturnType, AUTOMATIC) Adc_ConThdRet = (Std_ReturnType)E_NOT_OK;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      /* Error (ADC302): called prior to initializing */
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CONFIGURE_THRESHOLD_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (GroupId >= Adc_Cfg_Ptr->GroupCount)
    {
      /* Error (ADC218): non-existing group ID */
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CONFIGURE_THRESHOLD_ID,
                      (uint8) ADC_E_PARAM_GROUP);
      Error_flag = (boolean)TRUE;
    }
    else if (HighValue < LowValue)
    {
      /* Error if High Threshold value is less than Low Threshold value */
      Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_CONFIGURE_THRESHOLD_ID,
                        (uint8)ADC_E_WRONG_CONF_THRHLD_VALUE);
      Error_flag = (boolean)TRUE;
    }
    else
    {
      /* Check for Error: group has no channels with threshold enabled */
      /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
      unit = ADC_GroupUnit(GroupId);
      if(ADC_HW_UNITS(unit) == (uint8)STD_ON)
      {
        for(HwIndex = 0U; HwIndex < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); HwIndex++)
        {
            /* Get the index of hardware unit in structure which will match with the hardware unit ID*/
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->ADC[HwIndex].AdcHardwareUnitId == unit)
            {
            break;
            }
        }
        /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
        for(ChCount=(Adc_ChannelType)0U; \
            ((boolean)FALSE == ThresholdEnabled) && (ChCount <Adc_Cfg_Ptr->Groups[GroupId].AssignedChannelCount); \
            ChCount++)
        {
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            ch = Adc_Cfg_Ptr->Groups[GroupId].Assignment[ChCount];
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Channels[unit][ch].ThValues != ADC_UNUSED_THRESHOLD)
            {
            ThresholdEnabled = (boolean)TRUE;
            }
        }
    
        if ((boolean)FALSE == ThresholdEnabled)
        {
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_CONFIGURE_THRESHOLD_ID,
                            (uint8) ADC_E_WRONG_CONF_THRHLD_GROUP);
            Error_flag = (boolean)TRUE;
        }
        else
        {
            /* Test that the High value is within range */
            /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
            MaxHighValue = ADC_HIGH_TH_VALUE((((uint32)1 << Adc_Cfg_Ptr->ADC[HwIndex].Res) - (uint32)1));
    
            if (MaxHighValue < ADC_HIGH_TH_VALUE(HighValue))
            {
            Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_CONFIGURE_THRESHOLD_ID,
                                (uint8)ADC_E_WRONG_CONF_THRHLD_VALUE);
            Error_flag = (boolean)TRUE;
            }
        } /* else if ((boolean)TRUE == ThresholdEnabled) */
      }
    }

    if((boolean)FALSE == Error_flag)
    {
  #endif /* if (ADC_DEV_ERROR_DETECT == STD_ON) */
      SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26();
      Adc_ConThdRet = Adc_LLD_ConfigureThreshold(GroupId, LowValue, HighValue);
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26();
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
  #endif

  return Adc_ConThdRet;
}
#endif /* if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */

#ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD
#if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON) || defined(__DOXYGEN__)
/**
 * @brief   Function to get the last converted sample position into the CTUV2 DMA user buffer.
 *
 * @details The DMA interrupts the CPU on each completed sample. The last transferred DMA result is
 *          updated in the ISR and can be retrieved using this function. If no-transfers have been 
 *          completed, the function will return the error E_NOT_OK.
 *          This Non Autosar API is used to get the index of last converted sample into the CTUV2
 *          DMA User Buffer. Each index thus returned will be the position of the first channel
 *          of the sample. All positions from return index till (return index + no. of channels - 1)
 *          will contain the values for the last sample. 
 *          
 *
 * @note    The function Service ID[hex]: 0x32.
 *
 * @param[in]  CtuIdx       Index of the CTU Unit. 0 for CTU0, 1 for CTU1.
 * @param[in]  FifoIdx      The Fifo Index of the requested CTU Unit. 0 for FIFO_0, 1 for FIFO_1..
 * @param[out] PtrToIndex   Pointer that will contain the index of the last completed sample
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successfull Configure Threshold.
 * @retval         E_NOT_OK        In case of unsuccessfull ConfigureThreshold.
 *
 * @remarks Implements
 *
 * @api
 */
/*
* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_GetCTU2DmaLastSampleIndex
(
  VAR(uint8, AUTOMATIC) CtuIdx,
  VAR(uint8, AUTOMATIC) FifoIdx,
  P2VAR(uint16, AUTOMATIC, ADC_APPL_DATA) PtrToSampleIndex
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_OK;
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_AUTODMAFIFOTHRESHOLD_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (CtuIdx >= CTU_MAX_HW_UNITS)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_AUTODMAFIFOTHRESHOLD_ID,
                      (uint8)ADC_E_WRONG_CTUV2UNIT_INDEX);
      Error_flag = (boolean)TRUE;
    }
    else if (FifoIdx >= (uint8)CTUV2_MAX_FIFOS)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_AUTODMAFIFOTHRESHOLD_ID,
                      (uint8)ADC_E_WRONG_CTUV2FIFO_INDEX);
      Error_flag = (boolean)TRUE;
    }
    else
    {
    /* code never reached just for Misra */
    }
  #endif
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if((boolean)TRUE == Error_flag)
  {
    Adc_Ret = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    Adc_Ret = CTUV2_LLD_GetDmaLastSampleIndex(CtuIdx, FifoIdx, PtrToSampleIndex);
  }
  
  return Adc_Ret;
}
#endif /* if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON) || defined(__DOXYGEN__) */
#endif /* ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD */

#ifdef ADC_ENABLE_BCTU
#if (ADC_ENABLE_BCTU == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)

/**
* @brief          This function start the software trigger for input trigger source.
* @details        Software start the input trigger of the module.
*
* @param[in]      uint8
*
* @return         Std_ReturnType
*
* @api
*/
/* @violates @ref Adc_NonASR_c_REF_3 Declaration and definition of objects or function */
FUNC(Std_ReturnType, ADC_CODE) Adc_BCtuStartSoftwareTrigger
(
  VAR(uint8, AUTOMATIC) InputTrigger
)
{
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Adc_Cfg_Ptr)
    {
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_BCTU_SOFTWARE_TRIG_ID,
                        (uint8)ADC_E_UNINIT);
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }
    else if (InputTrigger >= (uint8)BCTU_MAX_TRG_CFG)
    {
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_BCTU_SOFTWARE_TRIG_ID,
                        (uint8)ADC_BCTU_E_PARAM_TRIG);
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Nothing for Misra */
    }
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    if ((Std_ReturnType)E_OK == TempReturn)
    {
        TempReturn = Adc_LLD_BCtuStartSoftwareTrigger(InputTrigger);
    }
    return TempReturn;
}

#if (BCTU_SET_MODE_API == STD_ON)
/**
* @brief          This function set operation mode for BCTU module.
* @details        Set operation mode for BCTU module: Normal mode or power down mode
*
* @param[in]      BCtu_OperationMode
*
* @return         Std_ReturnType
*
* @api
*/
/* @violates @ref Adc_NonASR_c_REF_3 Declaration and definition of objects or function */
FUNC(Std_ReturnType, ADC_CODE) Adc_BCtuSetMode
(
    VAR(BCtu_OperationMode, AUTOMATIC) OperationMode
)
{
    /* Return standard value */
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;
    
    if(Adc_Cfg_Ptr == NULL_PTR)
    {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        Det_ReportError((uint16) ADC_MODULE_ID,
                        (uint8) 0U,
                        (uint8) ADC_BCTU_SETMODE_ID,
                        (uint8) ADC_E_UNINIT);
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    else if((OperationMode != BCTU_POWER_DOWN_MODE) && (OperationMode != BCTU_NORMAL_MODE))
    {
        /* Report error to DET */
        Det_ReportError((uint16) ADC_MODULE_ID,
                        (uint8) 0U,
                        (uint8) ADC_BCTU_SETMODE_ID,
                        (uint8) ADC_BCTU_E_SETMODE);
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }
    else if(OperationMode == BCTU_POWER_DOWN_MODE)
    {
        VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0; /* HW unit index */
        for(;unit<(Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); unit++)
        {
            if((Adc_QueueIndexType)0 != ADC_GroupsInHwQueue(unit))
            {
                /* HW trigger conversion if ongoing */
                /* Report error to DET */
                Det_ReportError((uint16) ADC_MODULE_ID,
                                (uint8) 0U,
                                (uint8) ADC_BCTU_SETMODE_ID,
                                (uint8) ADC_E_BUSY);
                TempReturn = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    else
    {
        /* Nothing for Misra */
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    if((Std_ReturnType)E_OK == TempReturn)
    {
        TempReturn = (Std_ReturnType)Adc_LLD_BCtuSetMode(OperationMode);
    }
    return (TempReturn);
}
#endif /* BCTU_SET_MODE_API */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* #ifdef ADC_BCTU_ENABLED */

#ifdef ADC_NOTIFY_ON_STREAM_COMPLETED
#if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED)
#if (STD_ON == ADC_GROUP_UPDATE_NUMBER_SAMPLES_API)
/**
* @brief       This function modifies the number of samples to transferred using DMA.
*              This function will be available only if there is any group that has
*              NotifyOnStreamCompleteOnly = 1 in the configuration
*
* @details     This function provides a method to change the number of samples to be
*              transferred using DMA. Note that the new number_of_samples may not exceed
*              the Number of Streaming Samples provided in the configuration.
*
* @param[in]   Group - Index of group.
*
* @return      Std_ReturnType - E_OK or E_NOT_OK.
*
* @api
*
* @implements     DADC03035.
*
* @note           Synchronous.
* @note           Reentrant function.
*/
/* @violates @ref Adc_NonASR_c_REF_3 Definitions shall have internal linkage */
FUNC(Std_ReturnType, ADC_CODE) Adc_GroupUpdateNumberSamples
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) NumDMASamples
)
{
  VAR(Std_ReturnType, AUTOMATIC) Adc_UpdateSamplesRet = (Std_ReturnType)E_NOT_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
  if (Adc_Cfg_Ptr == NULL_PTR)
  {
    /* Error (ADC294): called prior to initializing */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_UPDATEGROUPNUMBERSAMPLES_ID, (uint8)ADC_E_UNINIT);
  }
  else if (Group >= Adc_Cfg_Ptr->GroupCount)
  {
    /* Error (ADC423): non-existing group ID */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_UPDATEGROUPNUMBERSAMPLES_ID, (uint8)ADC_E_PARAM_GROUP);
  }
  /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
  else if ((1U != Adc_Cfg_Ptr->Groups[Group].NotifyOnStreamCompleteOnly) ||
      /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
      (Adc_Cfg_Ptr->Groups[Group].NumSamples < NumDMASamples))
  {
    /* Error */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_UPDATEGROUPNUMBERSAMPLES_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
  }
  else
  {
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
    if (ADC_IDLE != ADC_GroupStatus[Group].Conversion)
    {
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
      /* Error */
      Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_UPDATEGROUPNUMBERSAMPLES_ID, (uint8)ADC_E_BUSY);
      /* @violates @ref Adc_NonASR_c_REF_5 return statement before end of function. */
      return Adc_UpdateSamplesRet;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
#else
    {
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */

      /* enter critical region to work on DMA */
      SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
      ADC_GroupStatus[Group].CurrentNumDMASamples = NumDMASamples;
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();

      Adc_UpdateSamplesRet = (Std_ReturnType)E_OK;
    }

    return Adc_UpdateSamplesRet;
}
#endif /* #if (STD_ON == ADC_GROUP_UPDATE_NUMBER_SAMPLES_API) */

#if (STD_ON == ADC_GROUP_GET_LAST_SAMPLE_API) || defined(__DOXYGEN__)
/**
* @brief       This function returns the samples already transferred for a Group with
*              Notify_On_Stream_Complete_Only attribute enabled.
*
* @details     This function checks the number of samples already transferred by DMA and
*              copies the data from the ResultsBufferPtr to the user buffer. It also returns
*              index of the last completed sample in the Results Buffer.
*
* @param[in]   Group - Index of group.
* @param[out]  PtrNumberSamples - Pointer to the index of the last completed sample.
* @param[out]  PtrSampleValues - Pointer to destination user buffer where the conversion
*                                results till the last completed sample will be copied to.
*
* @return      Std_ReturnType - E_OK or E_NOT_OK.
*
* @retval      E_OK:        Last completed sample was fetched sucessfully.
* @retval      E_NOT_OK:    Development error occured or no sample was converted yet.
*
* @api
*
* @implements     DADC03036.
*
* @note           Synchronous.
* @note           Reentrant function.
*/
/* @violates @ref Adc_NonASR_c_REF_3 Definitions shall have internal linkage */
FUNC(Std_ReturnType, ADC_CODE) Adc_GroupGetLastSamples
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_StreamNumSampleType, AUTOMATIC, ADC_APPL_DATA) PtrNumberSamples,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrSampleValues
)
{
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_NOT_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
  if (Adc_Cfg_Ptr == NULL_PTR)
  {
    /* Error (ADC294): called prior to initializing */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETLASTSAMPLES_ID, (uint8)ADC_E_UNINIT);
  }
  else if (Group >= Adc_Cfg_Ptr->GroupCount)
  {
    /* Error (ADC423): non-existing group ID */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETLASTSAMPLES_ID, (uint8)ADC_E_PARAM_GROUP);
  }
  /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
  else if (1U != Adc_Cfg_Ptr->Groups[Group].NotifyOnStreamCompleteOnly)
  {
    /* Error */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETLASTSAMPLES_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
  } else
  {
    /* enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
    if ( (ADC_GroupStatus[Group].Conversion == ADC_IDLE) && (ADC_GroupStatus[Group].AlreadyConverted == ADC_NOT_YET_CONVERTED) )
    {
      /* exit critical section */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
      /* Error (ADC388): conversion not started */
      Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETLASTSAMPLES_ID, (uint8)ADC_E_IDLE);
    }else
    {

      /* exit critical section */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();

#else
      {
        {
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
          Adc_Ret = Adc_LLD_GroupGetLastSamples(Group, PtrNumberSamples, PtrSampleValues);
        }
      }
      return Adc_Ret;
}
#endif /* if (STD_ON == ADC_GROUP_GET_LAST_SAMPLE_API) */

#if (STD_ON == ADC_READ_GROUP_SAMPLE_RESULT_API) || defined(__DOXYGEN__)
/**
* @brief       This function reads the conversion results of given sample-index for a Group (with
*              Notify_On_Stream_Complete_Only attribute enabled).
*
* @details     This function checks the number of samples already transferred by DMA and copies
*              the converted data of all channels at the given SampleIndex to the user buffer.
*
* @param[in]   Group - Index of group.
* @param[in]   SampleIndex - The Sample Index to read. This should be less than number of
*              currently completed samples.
* @param[out]  PtrSampleValues - Pointer to destination user buffer where the conversion
*                                results will be copied to.
*
* @return      Std_ReturnType - E_OK or E_NOT_OK.
*
* @retval      E_OK:        Given sample results was fetched sucessfully.
* @retval      E_NOT_OK:    Development error occured or the given sample was converted yet.
*
* @api
*
* @implements  DADC03037.
*
* @note        Synchronous.
* @note        Reentrant function.
*/
/* @violates @ref Adc_NonASR_c_REF_3 Definitions shall have internal linkage */
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroupSampleResult
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_StreamNumSampleType, AUTOMATIC) SampleIndex,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrSampleValues
)
{
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_NOT_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
  if (Adc_Cfg_Ptr == NULL_PTR)
  {
    /* Error (ADC294): called prior to initializing */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSAMPLERESULT_ID, (uint8)ADC_E_UNINIT);
  }
  else if (Group >= Adc_Cfg_Ptr->GroupCount)
  {
    /* Error (ADC423): non-existing group ID */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSAMPLERESULT_ID, (uint8)ADC_E_PARAM_GROUP);
  }
  /* @violates @ref Adc_NonASR_c_REF_11 Array indexing shall be the only allowed form of pointer arithmetic */
  else if (1U != Adc_Cfg_Ptr->Groups[Group].NotifyOnStreamCompleteOnly)
  {
    /* Error */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSAMPLERESULT_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
  }
  else if (SampleIndex >= ADC_GroupStatus[Group].CurrentNumDMASamples )
  {
    /* Error */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSAMPLERESULT_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
  }
  else
  {
    /* enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
    if ( (ADC_GroupStatus[Group].Conversion == ADC_IDLE) && (ADC_GroupStatus[Group].AlreadyConverted == ADC_NOT_YET_CONVERTED) )
    {
      /* exit critical section */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
      /* Error (ADC388): conversion not started */
      Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSAMPLERESULT_ID, (uint8)ADC_E_IDLE);
    }else
    {

      /* exit critical section */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();

#else
      {
        {
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
          Adc_Ret = Adc_LLD_ReadGroupSampleResult(Group, SampleIndex, PtrSampleValues);
        }
      }

      return Adc_Ret;
}
#endif /* if (STD_ON == ADC_READ_GROUP_SAMPLE_RESULT_API)*/
#endif /* if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED) */
#endif /* ifdef ADC_NOTIFY_ON_STREAM_COMPLETED */

#ifdef ADC_CTUV2_COMMON_ENABLE_NEW_API
#if (ADC_CTUV2_COMMON_ENABLE_NEW_API == STD_ON) || defined(__DOXYGEN__)
/**
 * @brief   Function to set the trigger handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU THCR1 & THCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and the mask (8 bit)
 *          to enable the External Trigger and Timer output for that Trigger, without considering
 *          the ADC command output enable.
 *          See from the RM the THCR1 and THCR2 registers for the right Thcr_value to use.
 *
 * @note    The function Service ID[hex]: 0x35.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  Thcr_value   THCRx mask value (only with bits for Ext. Trigger and Timer) for the selected input trigger.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successfull settings.
 * @retval         E_NOT_OK        In case of unsuccessfull settings.
 *
 * @remarks Implements
 *
 * @api
 */
  /* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2TriggerHandlerCtrlRegs
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint8, AUTOMATIC) Thcr_value
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_OK;
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_TRG_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (Trigger >= ((uint8)CTUV2_MAX_TRIGGERS))
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_TRG_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_WRONG_CTUV2_TRIGGER);
      Error_flag = (boolean)TRUE;
    }
    else
    {
      /* code useless*/
    }
  #endif
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if((boolean)TRUE == Error_flag)
  {
    Adc_Ret = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    Adc_Ret = CTUV2_LLD_SetCTU2TriggerHandlerCtrlRegs(Trigger, Thcr_value);
  }
  
  return Adc_Ret;
}

/**
* @brief   Function to set/clear the bit Tx_E of the trigger handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU THCR1 & THCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and a Boolean to set/clear the right trigger bit.
 *          See from the RM the THCR1 and THCR2 registers for the right API use.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  Enable   if True, the bit Tx_E shall be set to 1, 0 otherwise
 *
 * @note    The function Service ID[hex]: 0x36.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @remarks Implements
 *
 * @api
 */
  /* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
FUNC(Std_ReturnType, ADC_CODE) Adc_CTU2TriggerHandlerCtrlRegsEnableDisable
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(boolean, AUTOMATIC) Enable
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_OK;
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_EN_DIS_TRG_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (Trigger >= ((uint8)CTUV2_MAX_TRIGGERS))
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_EN_DIS_TRG_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_WRONG_CTUV2_TRIGGER);
      Error_flag = (boolean)TRUE;
    }
    else
    {
      /* code useless*/
    }
  #endif
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if((boolean)TRUE == Error_flag)
  {
    Adc_Ret = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    Adc_Ret = CTUV2_LLD_SetCTU2TriggerHandlerCtrlRegsEnableDisable(Trigger, Enable);
  }
  
  return Adc_Ret;
}

/**
* @brief   Function to set the cmd list handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CLCR1 & CLCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and  the position of the first
 *          command in the command list.
 *          See from the RM the CLCR1 and CLCR2 registers for the right API use.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  clcr_value   Position of the first command
 *
 * @note    The function Service ID[hex]: 0x37.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @remarks Implements
 *
 * @api
 */
 /* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2CmdListHandlerCtrlRegs
/* @violates @ref Adc_NonASR_c_REF_10 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint8, AUTOMATIC) clcr_value
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_OK;
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (Trigger >= ((uint8)CTUV2_MAX_TRIGGERS))
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_WRONG_CTUV2_TRIGGER);
      Error_flag = (boolean)TRUE;
    }
    else if (clcr_value >= ((uint8)CTUV2_MAX_ADC_COMMANDS))
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID,
                      (uint8)ADC_E_WRONG_CTUV2_CLCR_TRIGGER);
      Error_flag = (boolean)TRUE;
    }
    else
    {
      /* code useless*/
    }
  #endif
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if((boolean)TRUE == Error_flag)
  {
    Adc_Ret = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    Adc_Ret = CTUV2_LLD_SetCTU2CmdListHandlerCtrlRegs(Trigger,clcr_value);
  }
  
  return Adc_Ret;
}
/**
 * @brief   Function to set the trigger compare registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU TxCR registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and the comparator value
 *          See from the RM the TxCR trigger compare registers for the right compare_value to use.
 *
 * @note    The function Service ID[hex]: 0x38.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  compare_value  value to set in the register TxCR.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successfull settings.
 * @retval         E_NOT_OK        In case of unsuccessfull settings.
 *
 * @remarks Implements
 *
 * @api
 */
 /* @violates @ref Adc_NonASR_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2TriggerCompareRegs
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint16, AUTOMATIC) compare_value
)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) Adc_Ret = (Std_ReturnType)E_OK;
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_TRIGGER_COMPARE_REGS_ID,
                      (uint8)ADC_E_UNINIT);
      Error_flag = (boolean)TRUE;
    }
    else if (Trigger >= ((uint8)CTUV2_MAX_TRIGGERS))
    {
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_CTUV2_SET_TRIGGER_COMPARE_REGS_ID,
                      (uint8)ADC_E_WRONG_CTUV2_TRIGGER);
      Error_flag = (boolean)TRUE;
    }
    else
    {
      /* code useless*/
    }
  #endif
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  if((boolean)TRUE == Error_flag)
  {
    Adc_Ret = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    Adc_Ret = CTUV2_LLD_SetCTU2TriggerCompareRegs(Trigger, compare_value);
  }
  return Adc_Ret;
}
#endif /* if (ADC_CTUV2_COMMON_ENABLE_NEW_API == STD_ON) || defined(__DOXYGEN__) */
#endif /* ifdef ADC_CTUV2_COMMON_ENABLE_NEW_API */


#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_NonASR_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_NonASR_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
