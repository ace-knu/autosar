/**
*   @file    Port.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - PORT driver high level driver.
*   @details Implementation of the AutoSar high level PORT driver.
*
*   @addtogroup Port
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF11_ASR_REL_4_0_REV_0003_20161011
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
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
* @section PORT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section PORT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section PORT_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section PORT_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section PORT_C_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer 
* arithmetic but used due to the code complexity.
*
* @section PORT_C_REF_6
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements DPORT00003 */
#include "Port.h"

/* @implements DPORT00005 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/* @implements DPORT00006 */
#include "Port_LLD.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @implements DPORT03005
*/
#define PORT_VENDOR_ID_C                    43
/*
* @violates @ref PORT_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_C     4
/*
* @violates @ref PORT_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_C     0
/*
* @violates @ref PORT_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref PORT_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_C  3
#define PORT_SW_MAJOR_VERSION_C             1
#define PORT_SW_MINOR_VERSION_C             0
#define PORT_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*
* @file    Port.c
* @implements DPORT06001
*/
/* Check if source file and Port header file are of the same vendor */
#if (PORT_VENDOR_ID_C != PORT_VENDOR_ID)
    #error "Port.c and Port.h have different vendor ids"
#endif

/* Check if source file and Port header file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION))
   #error "AutoSar Version Numbers of Port.c and Port.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION))
  #error "Software Version Numbers of Port.c and Port.h are different"
#endif

/* Check if source file and Port_LLD.h file are of the same vendor */
#if (PORT_VENDOR_ID_C != PORT_VENDOR_ID_LLD_H)
    #error "Port.c and Port_LLD.h have different vendor ids"
#endif

/* Check if the source file and Port_LLD.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION_LLD_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION_LLD_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION_LLD_H))
   #error "AutoSar Version Numbers of Port.c and Port_LLD.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION_LLD_H) || \
     (PORT_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION_LLD_H) || \
     (PORT_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION_LLD_H))
  #error "Software Version Numbers of Port.c and Port_LLD.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

   #if (PORT_DEV_ERROR_DETECT == STD_ON)
   /* Check if the files Port.h and Det.h are of the same version */
     #if ((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Port.h and Det.h are different"
     #endif
   #endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
* @brief Segment descriptor for data arranged in array
*/
/*
* @violates @ref PORT_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_START_SEC_VAR_INIT_UNSPECIFIED
/* @implements DPORT00009 */
/* @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include' */
/* 
* @violates @ref PORT_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/**
* @brief Pointer initialized during init with the address of the received configuration structure.
* @details Will be used by all functions to access the configuration data.
*/
/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
P2CONST(Port_ConfigType, PORT_VAR, PORT_APPL_CONST) Port_Cfg_Ptr = NULL_PTR;

/*
* @violates @ref PORT_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @implements DPORT00009 */
/* @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include' */
/*
* @violates @ref PORT_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define PORT_START_SEC_CODE
/* @implements DPORT00009 */
/* @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include' */
/*
* @violates @ref PORT_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Initializes the Port Driver module.
* @details The function @p Port_Init() will initialize ALL ports and port pins
*          with the configuration set pointed to by the parameter @p ConfigPtr.
* @post    Port_Init() must be called before all other Port Driver module's functions
*          otherwise no operation can occur on the MCU ports and port pins.
*
* @param[in] ConfigPtr     A pointer to the structure which contains
*                          initialization parameters.
*
* @implements      DPORT03006
*
* @api
*/
/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr
)
{
#ifndef PORT_PRECOMPILE_SUPPORT
/* @implements    DPORT06002 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* @implements    DPORT06003 */
    if (ConfigPtr == NULL_PTR)
    {
        /* @implements    DPORT06004 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_INIT_ID, (uint8)PORT_E_PARAM_CONFIG);
    }
    else
#endif /*PORT_DEV_ERROR_DETECT */
#endif /* PORT_PRECOMPILE_SUPPORT*/
    {

#ifdef PORT_PRECOMPILE_SUPPORT
        if (ConfigPtr == NULL_PTR)
        {
            /* @implements    DPORT06005 */
            /*If Development Error Detection is disabled and configPtr is a NULL Pointer, it's
            initialized to the default configuration */
            ConfigPtr = &Port_ConfigPC;

        }
#endif /* PORT_PRECOMPILE_SUPPORT*/

        /* @implements   DPORT06006 */
        /* Call Initialization function depending of the platform */
        PORT_LLD_Init(ConfigPtr);

        /* Save pointer in global variable for refreshing pin directions */
        Port_Cfg_Ptr = ConfigPtr;
    }
}

/* @implements   DPORT06007 */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief   Sets the port pin direction.
* @details The function @p Port_SetPinDirection() will set the port pin direction
*          during runtime.
* @pre     @p Port_Init() must have been called first. In order to change the
*          pin direction the PortPinDirectionChangeable flag must have been set
*          to @p TRUE.
*
* @param[in] Pin           Pin ID number.
* @param[in] Direction     Port Pin direction.
*
* @implements      DPORT03007
* @api
*
*/

/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_SetPinDirection
(
    VAR(Port_PinType, AUTOMATIC) Pin,
    VAR(Port_PinDirectionType, AUTOMATIC) Direction
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Variable used to get current Pin configuration. */
    VAR(uint8, AUTOMATIC) pinDirError;
#endif /* PORT_DEV_ERROR_DETECT */

/* @implements   DPORT06008 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    
    /* Check if port is initialized */
    /* @implements    DPORT06009 */
    if (Port_Cfg_Ptr == NULL_PTR)
    {
        /*
        * @implements    DPORT06010
        */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
    }
    /* Check port pin validity */
    /* @implements    DPORT06011 */
    else if (Pin >= (Port_PinType)Port_Cfg_Ptr->numPins)
    {
        /* @implements    DPORT06012 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_PARAM_PIN);
    }
    /* Check port pin Direction validity */
    else if (!((Direction == PORT_PIN_IN) || (Direction == PORT_PIN_OUT)))
    {
        /* @implements    DPORT06041 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_INVALID_DIRECTION);
    }
    else
    {
        /* @implements    DPORT06013 */
        pinDirError = (uint8)PORT_LLD_SetPinDirection(Pin, (Port_PinDirectionType)Direction );
#else
        PORT_LLD_SetPinDirection(Pin, (Port_PinDirectionType)Direction );
#endif /* PORT_DEV_ERROR_DETECT */

/* @implements   DPORT06014 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* @implements    DPORT06015 */
        if (pinDirError)
        {
        /* @implements    DPORT06016 */
            Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_DIRECTION_UNCHANGEABLE);
        }
    }
#endif /* PORT_DEV_ERROR_DETECT */
}
#endif
/**
* @brief   Refreshes port direction.
* @details This function will refresh the direction of all configured ports to
*          the configured direction.
*          The PORT driver will exclude from refreshing those port pins that
*          are configured as "pin direction changeable during runtime".
* @pre     @p Port_Init() must have been called first.
*
* @implements      DPORT03008
*
* @api
*/
/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_RefreshPortDirection
(
    void
)
{
/* @implements   DPORT06017 */
#if(PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if port is initialized */
    /* @implements    DPORT06018 */
    if (Port_Cfg_Ptr == NULL_PTR)
    {
        /* @implements    DPORT06019 */
         Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_REFRESHPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
    }
    else
#endif /* PORT_DEV_ERROR_DETECT */
    {
        /* @implements    DPORT06020 */
        PORT_LLD_RefreshPortDirection(Port_Cfg_Ptr->numPins);
    }
}

#if (PORT_SET_PIN_MODE_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief   Sets the port pin mode.
* @details The function @p Port_SetPinMode() will set the port pin mode of the
*          referenced pin during runtime.
* @pre     @p Port_Init() must have been called first.
*
* @param[in] Pin       Pin ID number.
* @param[in] Mode      New Port Pin mode to be set on port pin.
*
* @implements      DPORT03009
* @api
*/
/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_SetPinMode
(
    VAR(Port_PinType, AUTOMATIC) Pin,
    VAR(Port_PinModeType, AUTOMATIC) Mode
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC) pinModeError = (uint8)0U;
#endif /* PORT_DEV_ERROR_DETECT */

/* @implements   DPORT06021 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if port is initialized */
    /* @implements    DPORT06022 */
    if (Port_Cfg_Ptr == NULL_PTR)
    {
        /* @implements    DPORT06023 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_UNINIT);
    }
    /* Check port pin validity */
    /* @implements    DPORT06024 */
    else if (Pin >= (Port_PinType)Port_Cfg_Ptr->numPins)
    {
         /* @implements    DPORT06025 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_PIN);
    }
    /* Check port pin mode Unchangeable */
    /* @implements    DPORT06026 */
    /* 
    * @violates @ref PORT_C_REF_5 Array indexing shall be the only allowed form of pointer arithmetic
    */
    else if((boolean) Port_Cfg_Ptr->Port_LLD_PinConfPtr[Pin].MC == (boolean)FALSE)
    {
        /* @implements    DPORT06027 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
        /* Sets the port pin direction */
        /* @implements      DPORT06028 */
         pinModeError = (uint8)PORT_LLD_SetPinMode(Pin, Mode);
#else
        PORT_LLD_SetPinMode(Pin, Mode);
#endif /* PORT_DEV_ERROR_DETECT */

/* @implements   DPORT06029 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* @implements    DPORT06030 */
        if (pinModeError != (uint8)0)
        {
           /* @implements    DPORT06031 */
            Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)pinModeError);
        }
    }
#endif /* PORT_DEV_ERROR_DETECT */
}
#endif

/* @implements    DPORT06032 */
#if  (PORT_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief   Returns the version information of this module.
* @details The function @p Port_GetVersionInfo() will return the version
*          information of this module. The version information includes:<br>
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*
* @param[in,out] pVersionInfo      Pointer to where to store the version
*                                  information of this module.
*
*
* @implements   DPORT03010
* @api
*/

/*
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
extern FUNC (void, PORT_CODE) Port_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) pVersionInfo)
{
/* @implements   DPORT06033 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if port is initialized */
    /* @implements    DPORT06039 */
    if (Port_Cfg_Ptr == NULL_PTR)
    {
        /* @implements    DPORT06038 */
        Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_GETVERSIONINFO_ID, (uint8)PORT_E_UNINIT);
    }
    else
    {
    /* Check pVersionInfo pointer */
    /* @implements    DPORT06034 */
    if (pVersionInfo == NULL_PTR)
    {
        /* @implements    DPORT06035 */
         Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_GETVERSIONINFO_ID, (uint8)PORT_E_PARAM_POINTER);
    }
    else
#endif /*PORT_DEV_ERROR_DETECT */
    {
       /* @implements    DPORT06036 */
       (pVersionInfo)->vendorID = (uint16)PORT_VENDOR_ID;
       (pVersionInfo)->moduleID = (uint16)PORT_MODULE_ID;
       (pVersionInfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
       (pVersionInfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
       (pVersionInfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    }
#endif  /*PORT_DEV_ERROR_DETECT */
}
#endif /* PORT_VERSION_INFO_API == STD_ON */

#define PORT_STOP_SEC_CODE

/* @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include' */
/*
* @violates @ref PORT_C_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
