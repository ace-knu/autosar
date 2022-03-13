/**
*   @file    Adc.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Common Level Driver source file.
*   @details Autosar layer of ADC MCAL driver.
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
* @section Adc_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement
*
* @section Adc_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the 
* contents of a header being included twice. 
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_c_REF_3
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Adc_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer 
* arithmetic but used due to the code complexity.
*
* @section Adc_c_REF_5
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_c_REF_6
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not
* be permitted
*
* @section Adc_c_REF_7
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00004 */
#include "Adc.h"
#include "Adc_LLD.h"
#include "SchM_Adc.h"

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Dem.h"
#endif
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DADC03008 */
#define ADC_VENDOR_ID_C                         (43)
#define ADC_AR_RELEASE_MAJOR_VERSION_C          (4)
#define ADC_AR_RELEASE_MINOR_VERSION_C          (0)
/*
* @violates @ref Adc_c_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_c_REF_7 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_REVISION_VERSION_C       (3)
#define ADC_SW_MAJOR_VERSION_C                  (1)
#define ADC_SW_MINOR_VERSION_C                  (0)
#define ADC_SW_PATCH_VERSION_C                  (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06004 */
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_C != ADC_VENDOR_ID)
#error "Adc.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc.c and Adc.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same vendor */
#if (ADC_VENDOR_ID_C != ADC_LLD_H_VENDOR_ID)
    #error "Adc.c and Adc_LLD.h have different vendor ids"
#endif

/* Check if source file and ADC LLD header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_C != ADC_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_C != ADC_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_C != ADC_LLD_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc.c and Adc_LLD.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_C != ADC_LLD_H_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_C != ADC_LLD_H_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_C != ADC_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc.c and Adc_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    /* Check if source file and Dem header file are of the same version */
    #if ((ADC_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc.c and Dem.h are different"
    #endif
  #endif

 /* Check if source file and DET header file are of the same version */
 #if (ADC_DEV_ERROR_DETECT == STD_ON)
    #if ((ADC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc.c and Det.h are different"
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

/* @violates @ref Adc_c_REF_7 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/**
* @brief          Global Configuration Pointer
* @details        Data structure containing the set of configuration parameters required for 
*                 initializing the ADC Driver and ADC HW Unit(s).
*
* @implements     DADC03009
*
*/
P2CONST(Adc_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_Cfg_Ptr = NULL_PTR;

/* @violates @ref Adc_c_REF_7 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/* @violates @ref Adc_c_REF_7 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/**
* @brief          Group status array structure
* @details        Array to hold all the group status information.
*
* @implements     DADC03010
*
*/
VAR(Adc_GroupStatusType, ADC_VAR) ADC_GroupStatus[ADC_MAX_GROUPS];

/**
* @brief          Unit status structure
* @details         Structure for the unit status.
*
* @implements     DADC03011
*
*/
VAR(Adc_UnitStatusType, ADC_VAR) ADC_UnitStatus[ADC_MAX_HW_UNITS];


/* @violates @ref Adc_c_REF_7 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
/* @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief          Initializes the ADC hardware unit and the driver.
* @details        This function will initialize both the ADC HW unit and the driver structures.
*
* @param[in]      ConfigPtr   Pointer to configuration set in Variant PB
*                             (Variant PC requires a NULL_PTR).
* @return         void
*
* @api            
*
* @post           Initializes the driver.
*
* @implements     DADC03012.
*
* @note           The function Autosar Service ID[hex]: 0x00.
* @note           Synchronous.
* @note           Non Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr
)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* ADC107 */
    if (Adc_Cfg_Ptr != NULL_PTR)
    {
        /* Error: ADC already initialized */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_INIT_ID,
                        (uint8)ADC_E_ALREADY_INITIALIZED);
    }
    #ifdef ADC_PRECOMPILE_SUPPORT
    /* ADC344 */
    else if (ConfigPtr != NULL_PTR)
    {
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_INIT_ID,
                        (uint8)ADC_E_PARAM_CONFIG);
    }
    #else
    /* ADC343 */
    else if (ConfigPtr == NULL_PTR)
    {
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_INIT_ID,
                        (uint8)ADC_E_PARAM_CONFIG);
    }
    #endif /* ADC_PRECOMPILE_SUPPORT */
    else
    {
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    #ifdef ADC_PRECOMPILE_SUPPORT
    /* ADC342 */
    Adc_Cfg_Ptr = &Adc_ConfigPC;
    /* to remove warning */
    /* @violates @ref Adc_c_REF_6 Boolean operations whose results are invariant shall not be permitted */
    if (NULL_PTR == ConfigPtr)
    {
        /* do nothing*/
    }
    #else
    /* ADC054 */
    Adc_Cfg_Ptr = ConfigPtr;
    #endif /*  ADC_PRECOMPILE_SUPPORT */
    Adc_LLD_Init(Adc_Cfg_Ptr);
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif  /* ADC_DEV_ERROR_DETECT == STD_ON */
}

/**
* @brief          Initializes the group specific ADC result buffer pointer as
*                 configured to point to the DataBufferPtr address which is
*                 passed as parameter.
* @details        Initializes ADC driver with the group specific result buffer 
*                 start address where the conversion results will be stored. 
*                 The application has to ensure that the application buffer, 
*                 where DataBufferPtr points to, can hold all the conversion 
*                 results of the specified group. The initialization with 
*                 Adc_SetupResultBuffer is required after reset, before a group 
*                 conversion can be started.
*
* @param[in]      Group           Numeric ID of requested ADC channel group.
* @param[in]      DataBufferPtr   Pointer to result data buffer
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Result buffer pointer initialized correctly.
* @retval         E_NOT_OK:       Operation failed or development error
*                                 occured.
*
* @api
*
* @pre            ADC422.
*
* @implements     DADC03013.
*
* @note           The function Autosar Service ID[hex]: 0x0C.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
)
{
    P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr = NULL_PTR;
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_NOT_OK;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC434 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_SETUPRESULTBUFFER_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (DataBufferPtr == NULL_PTR)
    {
        /* ADC457 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_SETUPRESULTBUFFER_ID,
                        (uint8)ADC_E_PARAM_POINTER);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC423 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_SETUPRESULTBUFFER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    else if (ADC_GroupStatus[Group].Conversion != ADC_IDLE)
    {
        /* ADC433 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_SETUPRESULTBUFFER_ID,
                        (uint8)ADC_E_BUSY);
    }
    else
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        GroupPtr = &Adc_Cfg_Ptr->Groups[Group];
        /* ADC420 */
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */  
        (GroupPtr->ResultsBufferPtr[Group]) = DataBufferPtr;
        TempReturn = (Std_ReturnType)E_OK;
    }
    return(TempReturn);
}

#if (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Returns all ADC HW Units to a state comparable to their
*                 power on reset state.
* @details        Returns all ADC HW Units to a state comparable to their
*                 power on reset state, and de-initialize the ADC MCAL driver.
*
* @return         void
*
* @api
*
* @implements     DADC03014.
*
* @note          The function Autosar Service ID[hex]: 0x01.
* @note          Synchronous.
* @note          Non Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DeInit(void)
{
    /* Group index */
    VAR(uint8,AUTOMATIC) Group = 0U;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /*  flag to set if ADC is still converting */
    VAR(boolean,AUTOMATIC) flag = (boolean)FALSE;

    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC154 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DEINIT_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else
    {
        /*  Check if ADC is still converting */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
        for(;Group<(uint8)ADC_MAX_GROUPS;Group++)
        {
            if((ADC_GroupStatus[Group].Conversion != ADC_IDLE)&&
               (ADC_GroupStatus[Group].Conversion != ADC_STREAM_COMPLETED))
            {
                flag = (boolean)TRUE;
                break;
            }
        }
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
        if (flag == (boolean)TRUE)
        {
            /* ADC112 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_DEINIT_ID,
                            (uint8)ADC_E_BUSY);
        }
        else
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        {
            for(Group=(uint8)0;Group<(uint8)(Adc_Cfg_Ptr->GroupCount);Group++)
            {
                /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] = NULL_PTR;
            }
            Adc_LLD_DeInit();
            /* Undefine the global pointer to the configuration */
            Adc_Cfg_Ptr = NULL_PTR;
        }
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Starts the conversion of all channels of
*                 the requested ADC Channel group.
* @details        This function will start the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03034.
*
* @note           The function Autosar Service ID[hex]: 0x02.
* @note           Asynchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_StartGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
        VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        VAR(boolean,AUTOMATIC) flag = (boolean)FALSE;
        VAR(uint8,AUTOMATIC) index = (uint8)0;
    #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    #if (ADC_ENABLE_QUEUING == STD_ON)
        VAR(boolean,AUTOMATIC) Implicity = (boolean)FALSE;
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC294 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_STARTGROUPCONVERSION_ID,
                        (uint8)ADC_E_UNINIT);
        Error_flag = (boolean)TRUE;
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC125 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_STARTGROUPCONVERSION_ID,
                        (uint8)ADC_E_PARAM_GROUP);
        Error_flag = (boolean)TRUE;
    } else {
        /* do nothig for misra */
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Error_flag == (boolean)FALSE)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* Get the unit to which the group belongs to */
        /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        unit = ADC_GroupUnit(Group);
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
            #if (ADC_ENABLE_QUEUING == STD_ON)
                /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                if((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)|| \
                    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    ((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_CONTINUOUS)&& \
                    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    (Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&& \
                    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)))
                {
                    /* The current group can be implicitly stopped */
                    Implicity = (boolean)TRUE;
                }
                else
                {
                    /* The current group cannot be implicitly stopped */
                    Implicity = (boolean)FALSE;
                }
            #endif  /* (ADC_ENABLE_QUEUING == STD_ON) */
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (Adc_Cfg_Ptr->Groups[Group].TriggerSource  != ADC_TRIGG_SRC_SW)
            {
                /* ADC133 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_STARTGROUPCONVERSION_ID,
                                (uint8)ADC_E_WRONG_TRIGG_SRC);
            }
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            else if (Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] == NULL_PTR)
            {
                /* ADC424 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_STARTGROUPCONVERSION_ID,
                                (uint8)ADC_E_BUFFER_UNINIT);
            }
        else
        {
               /* enter critical section to protect against ISR updating the global
               variables used in tests - consistency */
               SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();
               #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
                #if (ADC_ENABLE_QUEUING == STD_OFF)
                /* In this case any SW conversion is ongoing */
                if (ADC_UnitStatus[unit].QueueIndex != (Adc_QueueIndexType)0)
                {
                  #if (ADC_SW_INJ_CONFIGURED == STD_ON)
                  /* Injected conversion mode */
                  if (Adc_Cfg_Ptr->Groups[Group].type != (Adc_GroupConvType)ADC_CONV_TYPE_INJECTED)
                  #endif /* (ADC_SW_INJ_CONFIGURED == STD_ON) */
                  {
                    /* error occured, exit critical section */
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                    /* ADC346, ADC426 */
                    Det_ReportError((uint16)ADC_MODULE_ID,
                                    (uint8)0U,
                                    (uint8)ADC_STARTGROUPCONVERSION_ID,
                                    (uint8)ADC_E_BUSY);
                  }
                }
                #else /* (ADC_ENABLE_QUEUING == STD_ON) */
                if ((Implicity == (boolean)FALSE)&&
                    (ADC_GroupStatus[Group].Conversion != ADC_IDLE))
                {
                  /* error occured, exit critical section */
                  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                  /* ADC351 */
                  Det_ReportError((uint16)ADC_MODULE_ID,
                                  (uint8)0U,
                                  (uint8)ADC_STARTGROUPCONVERSION_ID,
                                  (uint8)ADC_E_BUSY);
                }
                else if ((Implicity == (boolean)TRUE)&&
                         (ADC_GroupStatus[Group].Conversion != ADC_IDLE)&&
                         (ADC_GroupStatus[Group].Conversion != ADC_STREAM_COMPLETED))
                {
                  /* error occured, exit critical section */
                  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                  /* ADC428 */
                  Det_ReportError((uint16)ADC_MODULE_ID,
                                  (uint8)0U,
                                  (uint8)ADC_STARTGROUPCONVERSION_ID,
                                  (uint8)ADC_E_BUSY);
                }
                #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
               #else /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
                if(ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0)
                {
                    for(index = (uint8)0; index < ADC_UnitStatus[unit].QueueIndex; index++)
                    {
                        if(ADC_GroupInQueue(unit,index) == Group)
                        {
                            flag = (boolean)TRUE;
                        }
                    }
                }
                if ((((ADC_UnitStatus[unit].Queue[0] == Group)&&
                      (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0))||
                      (flag == (boolean)TRUE))&&
                      (Implicity == (boolean)FALSE))
                {
                    /* error occured, exit critical section */
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                    /* ADC348, ADC335 */
                    Det_ReportError((uint16)ADC_MODULE_ID,
                                   (uint8)0U,
                                   (uint8)ADC_STARTGROUPCONVERSION_ID,
                                   (uint8)ADC_E_BUSY);
                }
                else if (((ADC_GroupStatus[Group].Conversion != ADC_IDLE)&&
                          (ADC_GroupStatus[Group].Conversion != ADC_STREAM_COMPLETED))&&
                          (Implicity == (boolean)TRUE))
                {
                    /* error occured, exit critical section */
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                     /* ADC427, ADC335 */
                    Det_ReportError((uint16)ADC_MODULE_ID,
                                    (uint8)0U,
                                    (uint8)ADC_STARTGROUPCONVERSION_ID,
                                    (uint8)ADC_E_BUSY);
                }
               #endif  /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
            else if(ADC_UnitStatus[unit].QueueIndex >= (ADC_QUEUE_MAX_DEPTH_MAX))
            {
                /* error occured, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
                /* Error: queue is full */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_STARTGROUPCONVERSION_ID,
                                (uint8)ADC_E_QUEUE_FULL);
            }
            else
            {
                /* everything ok, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
    #else   /* open code blocks used if DET is on */
    {
        {
            {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            Adc_LLD_StartGroupConversion(Group,unit);
            }
        }
    } /* (Error_flag == (boolean)FALSE) */
}

/**
* @brief          Stops the conversion of all channels of the requested ADC
*                 Channel group.
* @details        This function will stop the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03015.
*
* @note           The function Autosar Service ID[hex]: 0x03.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_StopGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC295 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_STOPGROUPCONVERSION_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC126 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_STOPGROUPCONVERSION_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    else if ((Adc_Cfg_Ptr->Groups[Group].TriggerSource) != ADC_TRIGG_SRC_SW)
    {
        /* ADC164 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_STOPGROUPCONVERSION_ID,
                        (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    else
    {
        /* enter critical section */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19();
        if(ADC_GroupStatus[Group].Conversion == ADC_IDLE)
        {
            /* error occured, exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19();
            /* ADC241 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_STOPGROUPCONVERSION_ID,
                            (uint8)ADC_E_IDLE);
        }
        else
        {
            /* exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19();
    #else
    {
        {
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            /* Get the unit to which the group belongs to */
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            unit = ADC_GroupUnit(Group);
            Adc_LLD_StopGroupConversion(Group,unit);
        }
    }
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_READ_GROUP_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Reads the group conversion results.
* @details        Reads the group conversion results of the last completed
                  conversion round of the requested group and stores the
                  channel values starting at the DataBufferPtr address.
                  The group channel values are stored in ascending channel
                  number order (in contrast to the storage layout of the
                  result buffer if streaming access is configured).
*
* @param[in]      Group          Numeric ID of requested ADC Channel group.
* @param[in]      DataBufferPtr  ADC results of all channels of the selected group 
*                                are stored in the data buffer addressed with the pointer.
* @return         Std_ReturnType Standard return type.
* @retval         E_OK:          results are available and written to the
*                                data buffer.
* @retval         E_NOT_OK:      no results are available or development
*                                error occured.
* @api
*
* @pre            Preconditions as text description. Optional tag.
* @post           Postconditions as text description. Optional tag.
*
* @implements     DADC03016.
*
* @note           The function Autosar Service ID[hex]: 0x04.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
)
{
    /* Return Value */
    VAR(Std_ReturnType, AUTOMATIC) Adc_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC296 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_VALUEREADGROUP_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC152 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_VALUEREADGROUP_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    else
    {
        /* enter critical section */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
        if ((ADC_GroupStatus[Group].Conversion == ADC_IDLE)&&
            (ADC_GroupStatus[Group].AlreadyConverted == ADC_NOT_YET_CONVERTED))
        {
            /* error occured, exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
            /* ADC388 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_VALUEREADGROUP_ID,
                            (uint8)ADC_E_IDLE);
        }
        #ifdef ADC_NOTIFY_ON_STREAM_COMPLETED
        #if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED)
        else if (1U == Adc_Cfg_Ptr->Groups[Group].NotifyOnStreamCompleteOnly)
        {
            /* exit critical section */
             SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
             /* Error This function is not used for the group has only an interrupt at stream complete  */
             Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_VALUEREADGROUP_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
        }
        #endif /* if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED) */
        #endif /* ifdef ADC_NOTIFY_ON_STREAM_COMPLETED */
        else
        {
            /* exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
    #else
    {
        {
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            Adc_ReadGroupRet = Adc_LLD_ReadGroup(Group, DataBufferPtr);
        }
    }
    return(Adc_ReadGroupRet);
}
#endif /* (ADC_READ_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enables the hardware trigger for the requested ADC Channel group.
* @details        This function will enable the HW trigger source for the requested
*                 ADC channel group. This function does set the CTU register for all 
*                 platform that have the CTU Hw Unit.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03017.
*
* @note           The function Autosar Service ID[hex]: 0x05.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware Unit on which the requested group will run */
    VAR(Adc_HwUnitType,AUTOMATIC) unit = (Adc_HwUnitType)0;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* flag when error is reported */
    VAR(boolean, AUTOMATIC) Error_flag = (boolean)FALSE;
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC297 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_UNINIT);
        Error_flag = (boolean)TRUE;
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC128 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
        Error_flag = (boolean)TRUE;
    }
    else {
        /* do nothig for misra */
    }
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Error_flag == (boolean)FALSE)
    {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* Get the unit to which the group belongs to */
        /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        unit = ADC_GroupUnit(Group);
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] == NULL_PTR)
            {
                /* ADC425 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                (uint8)ADC_E_BUFFER_UNINIT);
            }
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            else if (Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW)
            {
                /* ADC136 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                (uint8)ADC_E_WRONG_TRIGG_SRC);
            }
            /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            else if ((Adc_Cfg_Ptr->Groups[Group].mode) != ADC_CONV_MODE_ONESHOT)
            {
                /* ADC281 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                (uint8)ADC_E_WRONG_CONV_MODE);
            }
        else
        {
            /* number of groups in the hardware queue */
            VAR(Adc_QueueIndexType,AUTOMATIC) noGroupsInHWQueue = (Adc_QueueIndexType)0;
            #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
                #if (ADC_ENABLE_QUEUING == STD_OFF)
                    /* number of groups in the software queue */
                    VAR(Adc_QueueIndexType,AUTOMATIC) noGroupsInSWQueue = (Adc_QueueIndexType)0;
                #endif /* (ADC_ENABLE_QUEUING == STD_OFF) */
            #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
            /* enter critical section to protect agains queue modifications */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
            /* read now the HW queue sizes */
            noGroupsInHWQueue= ADC_GroupsInHwQueue(unit);
            #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
                #if (ADC_ENABLE_QUEUING == STD_OFF)
                    /* Read now the SW queue size */
                    noGroupsInSWQueue= ADC_UnitStatus[unit].QueueIndex;
                    /* In this case any conversion is ongoing */
                    if ((noGroupsInSWQueue != (Adc_QueueIndexType)0)||
                        (noGroupsInHWQueue!=(Adc_QueueIndexType)0))
                    {
                        /* error occured, exit critical section */
                        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
                        /* ADC321 */
                        Det_ReportError((uint16)ADC_MODULE_ID,
                                        (uint8)0U,
                                        (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                        (uint8)ADC_E_BUSY);
                    }
                    else
                #endif /* (ADC_ENABLE_QUEUING == STD_OFF) */
            #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */
            #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
            if ((ADC_GroupStatus[Group].HwTriggering == ADC_HWTRIGGER_ENABLED)||
                (noGroupsInHWQueue >= (uint8)ADC_HW_QUEUE))
            #else
            if ((ADC_GroupStatus[Group].HwTriggering == ADC_HWTRIGGER_ENABLED)&& \
                /* @violates @ref Adc_c_REF_6 Boolean operations whose results are invariant shall not be permitted */
                (noGroupsInHWQueue!= (uint8)0))
            #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
            {
                /* error occured, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
                /* ADC349 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                (uint8)ADC_E_BUSY);
            }
            /* @violates @ref Adc_c_REF_6 Boolean operations whose results are invariant shall not be permitted */
            else if (noGroupsInHWQueue >= (Adc_QueueIndexType)ADC_HW_QUEUE)
            {
                /* error occured, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
                /* ADC353 */
                Det_ReportError((uint16)ADC_MODULE_ID,
                                (uint8)0U,
                                (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                                (uint8)ADC_E_QUEUE_FULL);
            }
            else
            {
                /* everything ok, exit critical section */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
    #else
        /* open code blocks used if DET is on */
    {
        {
            {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            Adc_LLD_EnableHardwareTrigger(Group,unit);
            }
        }
  } /* (Error_flag == (boolean)FALSE) */
}

/**
* @brief          Disables the hardware trigger for the requested ADC Channel group.
* @details        This function will disable the HW trigger source for the requested
*                 ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03018.
*
* @note           The function Autosar Service ID[hex]: 0x06.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware Unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC298 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC129 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW)
    {
        /* ADC137 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    else if ((Adc_Cfg_Ptr->Groups[Group].mode) != ADC_CONV_MODE_ONESHOT)
    {
        /* ADC282 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_WRONG_CONV_MODE);
    }
    #if (defined(ADC_ENABLE_CTUV2) || defined(ADC_ENABLE_BCTU))
      #if (defined(ADC_ENABLE_CTUV2) && (ADC_ENABLE_CTUV2 == STD_OFF))
        else if (ADC_GroupStatus[Group].HwTriggering == ADC_HWTRIGGER_DISABLED)
        {
            /* ADC304 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_IDLE);
        }
      #elif (defined(ADC_ENABLE_BCTU) && (ADC_ENABLE_BCTU == STD_OFF))
        else if (ADC_GroupStatus[Group].HwTriggering == ADC_HWTRIGGER_DISABLED)
        {
            /* ADC304 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_IDLE);
        }
      #endif
    #else /* (!defined(ADC_ENABLE_CTUV2) && !defined(ADC_ENABLE_BCTU)) */
        else if (ADC_GroupStatus[Group].HwTriggering == ADC_HWTRIGGER_DISABLED)
        {
            /* ADC304 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_IDLE);
        }
    #endif /* (defined(ADC_ENABLE_CTUV2) || defined(ADC_ENABLE_BCTU)) */
    else
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Get the unit to which the group belongs to */
        /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        unit = ADC_GroupUnit(Group);
        Adc_LLD_DisableHardwareTrigger(Group,unit);
    }
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will enable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03019.
*
* @note           The function Autosar Service ID[hex]: 0x07.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr==NULL_PTR)
    {
        /* ADC299 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC130 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].Notification == NULL_PTR)
    {
        /* ADC165 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_NOTIF_CAPABILITY);
    }
    else
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        /* ADC057 */
        /* enter critical section to protect agains ADC_GroupStatus modifications */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
        ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_ENABLED;
        /* exit critical section */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
    }
}

/**
* @brief          Disables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will disable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
*
* @return         void
*
* @api
*
* @implements     DADC03020.
*
* @note           The function Autosar Service ID[hex]: 0x08.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC300 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC131 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_PARAM_GROUP);
    }
    /* @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].Notification == NULL_PTR)
    {
        /* ADC166 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLEGROUPNOTIFICATION_ID,
                        (uint8)ADC_E_NOTIF_CAPABILITY);
    }
    else
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        /* ADC058 */
        /* enter critical section to protect agains ADC_GroupStatus modifications */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();
        ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
        /* exit critical section */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();
    }
}
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) || defined(__DOXYGEN__) */

/**
* @brief          Returns the conversion status of the requested ADC Channel group.
* @details        This function will return the converison status of the requested
*                 ADC channel group.
*
* @param[in]      Group             Numeric ID of requested ADC channel group.
*
* @return         Adc_StatusType    Conversion status for the requested group.
* @retval         ADC_IDLE          in case of errors.
* @retval         conversion status in case of no errors.
* @api
*
* @implements     DADC03021.
*
* @note           The function Autosar Service ID[hex]: 0x09.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_StatusType, AUTOMATIC) tempReturn = ADC_IDLE;

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC301 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETGROUPSTATUS_ID,
                        (uint8)ADC_E_UNINIT);
        tempReturn = ADC_IDLE;
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC225 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETGROUPSTATUS_ID,
                        (uint8)ADC_E_PARAM_GROUP);
        tempReturn = ADC_IDLE;
    }
    else
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        /* ADC226 */
        /* enter critical section to protect ADC_GroupStatus read */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02();
        /* ADC220 */
        tempReturn = ADC_GroupStatus[Group].Conversion;    
         /* exit critical section */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();
    }
    return(tempReturn);
}

/**
* @brief          Returns the number of valid samples per channel.
* @details        Returns the number of valid samples per channel, stored in
*                 the result buffer. Reads a pointer, pointing to a position
*                 in the group result buffer. With the pointer position, the
*                 results of all group channels of the last completed conversion
*                 round can be accessed. With the pointer and the return value,
*                 all valid group conversion results can be accessed (the user
*                 has to take the layout of the result buffer into account).
*
* @param[in]      Group             Numeric ID of requested ADC channel group.
*
* @param[out]     PtrToSamplePtr    Pointer to result buffer pointer.
*
* @return         Adc_StreamNumSampleType Number of valid samples per channel.
* @retval         0                 in case of errors.
* @retval         >0                Number of valid samples per channel.
* @api
*
* @implements     DADC03022.
*
* @note           The function Autosar Service ID[hex]: 0x0B.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
)
{
    /* number of samples to return */
    VAR(Adc_StreamNumSampleType, AUTOMATIC) NumberOfResults = (Adc_StreamNumSampleType)0U;
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (Adc_Cfg_Ptr == NULL_PTR)
    {
        /* ADC302 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETSTREAMLASTPOINTER_ID,
                        (uint8)ADC_E_UNINIT);
        *PtrToSamplePtr = NULL_PTR;
    }
    else if (Group >= Adc_Cfg_Ptr->GroupCount)
    {
        /* ADC218 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETSTREAMLASTPOINTER_ID,
                        (uint8)ADC_E_PARAM_GROUP);
        *PtrToSamplePtr = NULL_PTR;
    }
    else
    {
        /* enter critical region to protect checks on ADC_GroupStatus */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17();

        if (ADC_GroupStatus[Group].Conversion == ADC_IDLE)
        {
            /* exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();
            /* ADC215 */
            Det_ReportError((uint16)ADC_MODULE_ID,
                            (uint8)0U,
                            (uint8)ADC_GETSTREAMLASTPOINTER_ID,
                            (uint8)ADC_E_IDLE);
            *PtrToSamplePtr = NULL_PTR;
        }
        #ifdef ADC_NOTIFY_ON_STREAM_COMPLETED
        #if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED)
        else if (1U == Adc_Cfg_Ptr->Groups[Group].NotifyOnStreamCompleteOnly)
        {
            /* exit critical section */
             SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();
             /* Error This function is not used for the group has only an interrupt at stream complete  */
             Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, (uint8)ADC_GETSTREAMLASTPOINTER_ID, (uint8)ADC_E_PARAM_GROUP_SAMPLES);
        }
        #endif /* ifdef ADC_NOTIFY_ON_STREAM_COMPLETED */
        #endif /* if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED) */
        else
        {
            /* exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();
    #else
    {
        {
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            NumberOfResults = Adc_LLD_GetStreamLastPointer(Group, PtrToSamplePtr);
        }
    }
    return(NumberOfResults);
}

#if (ADC_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Returns the version information of this module.
* @details        Returns the version information of this module.
*
* @param[out]     versioninfo     Pointer to where to store the version
*                                 information of this module.
* @retval         structure       in case of no errors.
*
* @api
*
* @implements     DADC03023.
*
* @note           The function Autosar Service ID[hex]: 0x0A.
* @note           Synchronous.
* @note           Reentrant function.
*/
/*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType , AUTOMATIC, ADC_APPL_DATA) versioninfo
)
{
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (versioninfo == NULL_PTR)
    {
        /* ADC458 */
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_GETVERSIONINFO_ID,
                        (uint8)ADC_E_PARAM_POINTER);
    }
    else
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    {
        /* ADC236 */
        (versioninfo)->vendorID = (uint16)ADC_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)ADC_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ADC_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ADC_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ADC_SW_PATCH_VERSION;
    }
}
#endif /* (ADC_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__) */

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
