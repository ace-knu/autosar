/**
*   @file    Port_Siul_LLD.c
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - SIUL Low level driver implementation.
*   @details Implementation of the SIUL low level driver.
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

#ifndef PORT_SIUL_LLD_C
#define PORT_SIUL_LLD_C

#ifdef __cplusplus
extern "C" {
#endif

/**
*  @page misra_violations MISRA-C:2004 violations
*
*  @section Port_Siul_LLD_C_REF_2
*  Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*  '#include'. This is an Autosar requirement about the memory management.
*
*  @section Port_Siul_LLD_C_REF_4
*  Violates MISRA 2004 Required Rule 14.7, return statement before end of function. The return
*  statement are used to simplify the code structure and easier readability.
*
*  @section Port_Siul_LLD_C_REF_6
*  Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*  There are different kinds of execution code sections.
*
*  @section Port_Siul_LLD_C_REF_7
*  Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int),
*  FALSE: the quantity is unsigned.
*
*  @section Port_Siul_LLD_C_REF_9
*  Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
*  specifications although it exceeds the max length of 31 characters
*
*  @section Port_Siul_LLD_C_REF_10
*  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*  This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
*  is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
*  @section Port_Siul_LLD_C_REF_11
*  Violates MISRA 2004 Advisory Rule 12.6, boolean expression required for operator:
*  '||'; the -strong(B,...) option can help provide Boolean-by-enforcement.
*  Booleans operands are not used for logical operators '&&', '||' and '!'
*
*  @section Port_Siul_LLD_C_REF_12
*  Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used.
*  This violation is due to the use of pointer arithematic, to access the channel parameters,
*  the indexing of the pointer is taken care and hence the unintended memory location will not
*  be accessed.
*
* @section Port_Siul_LLD_C_REF_16
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
/*
* @file       Port_Siul_LLD.c
* @note       File included for legacy.
* @implements DPORT00022
*/
#include "modules.h"

/*
* @file       Port_Siul_LLD.c
* @implements DPORT00023
*/
#include "Reg_Macros.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @brief Module ID where this file is placed.
* @details Used to make sure that the file content is not compile twice if at least 2 modules using
* it are compiled in the project
*/
#define SIUL_LLD_MODULE_ID        124

/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
* @implements DPORT05004
*/
#define SIUL_VENDOR_ID_LLD_C                     43
/*
*  @violates @ref Port_Siul_LLD_C_REF_9 Violates MISRA 2004 Required Rule 1.4
*/
/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define SIUL_AR_RELEASE_MAJOR_VERSION_LLD_C      4
/*
*  @violates @ref Port_Siul_LLD_C_REF_9 Violates MISRA 2004 Required Rule 1.4
*/
/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define SIUL_AR_RELEASE_MINOR_VERSION_LLD_C      0
/*
*  @violates @ref Port_Siul_LLD_C_REF_9 Violates MISRA 2004 Required Rule 1.4
*/
/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define SIUL_AR_RELEASE_REVISION_VERSION_LLD_C   3
#define SIUL_SW_MAJOR_VERSION_LLD_C              1
#define SIUL_SW_MINOR_VERSION_LLD_C              0
#define SIUL_SW_PATCH_VERSION_LLD_C              1


#if ( (USE_PORT_MODULE == STD_ON) && (SIUL_LLD_MODULE_ID == 124) )
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file   Port_Siul_LLD.c
* @implements DPORT00024
*/
#include "Port.h"
/*
* @file   Port_Siul_LLD.c
* @implements DPORT00025
*/
#include "Reg_eSys_SIUL.h"
/*
* @file   Port_Siul_LLD.c
* @implements DPORT00026
*/
#include "Port_Siul_LLD.h"

/**
* @file   Port_Siu_LLD.c
* @implements DPORT00028
*/
#include "SchM_Port.h"

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/*
* @file    Port_Siul_LLD.c
* @implements   DPORT06001
*/
/* Check if Port_Siul_LLD.c and Port.h are of the same vendor */
#if (SIUL_VENDOR_ID_LLD_C != PORT_VENDOR_ID)
    #error "Port_Siul_LLD.c and Port.h have different vendor ids"
#endif
/* Check if Port_Siul_LLD.c and Port.h are of the same Autosar version */
#if ((SIUL_AR_RELEASE_MAJOR_VERSION_LLD_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL_AR_RELEASE_MINOR_VERSION_LLD_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (SIUL_AR_RELEASE_REVISION_VERSION_LLD_C != PORT_AR_RELEASE_REVISION_VERSION))
   #error "AutoSar Version Numbers of Port_Siul_LLD.c and Port.h are different"
#endif
/* Check if Port_Siul_LLD.c and Port.h are of the same software version */
#if ((SIUL_SW_MAJOR_VERSION_LLD_C != PORT_SW_MAJOR_VERSION) || \
     (SIUL_SW_MINOR_VERSION_LLD_C != PORT_SW_MINOR_VERSION) || \
     (SIUL_SW_PATCH_VERSION_LLD_C != PORT_SW_PATCH_VERSION))
  #error "Software Version Numbers of Port_Siul_LLD.c and Port.h are different"
#endif
/* Check if Port_Siul_LLD.c and Reg_eSys_SIUL.h are of the same vendor */
#if (SIUL_VENDOR_ID_LLD_C != SIUL_VENDOR_ID_REG)
    #error "Port_Siul_LLD.c and Reg_eSys_SIUL.h have different vendor ids"
#endif
/* Check if Port_Siul_LLD.c and Reg_eSys_SIUL.h are of the same Autosar version */
#if ((SIUL_AR_RELEASE_MAJOR_VERSION_LLD_C    != SIUL_AR_RELEASE_MAJOR_VERSION_REG) || \
     (SIUL_AR_RELEASE_MINOR_VERSION_LLD_C    != SIUL_AR_RELEASE_MINOR_VERSION_REG) || \
     (SIUL_AR_RELEASE_REVISION_VERSION_LLD_C != SIUL_AR_RELEASE_REVISION_VERSION_REG))
   #error "AutoSar Version Numbers of Port_Siul_LLD.c and Reg_eSys_SIUL.h are different"
#endif
/* Check if Port_Siul_LLD.c and Reg_eSys_SIUL.h are of the same software version */
#if ((SIUL_SW_MAJOR_VERSION_LLD_C != SIUL_SW_MAJOR_VERSION_REG) || \
     (SIUL_SW_MINOR_VERSION_LLD_C != SIUL_SW_MINOR_VERSION_REG) || \
     (SIUL_SW_PATCH_VERSION_LLD_C != SIUL_SW_PATCH_VERSION_REG))
  #error "Software Version Numbers of Port_Siul_LLD.c and Reg_eSys_SIUL.h are different"
#endif
/* Check if Port_Siul_LLD.c and Reg_eSys_SIUL.h are of the same vendor */
#if (SIUL_VENDOR_ID_LLD_C != SIUL_VENDOR_ID_LLD_H)
    #error "Port_Siul_LLD.c and Port_Siul_LLD.h have different vendor ids"
#endif
/* Check if Port_Siul_LLD.c and Port_Siul_LLD.h are of the same Autosar version */
#if ((SIUL_AR_RELEASE_MAJOR_VERSION_LLD_C    != SIUL_AR_RELEASE_MAJOR_VERSION_LLD_H) || \
     (SIUL_AR_RELEASE_MINOR_VERSION_LLD_C    != SIUL_AR_RELEASE_MINOR_VERSION_LLD_H) || \
     (SIUL_AR_RELEASE_REVISION_VERSION_LLD_C != SIUL_AR_RELEASE_REVISION_VERSION_LLD_H))
   #error "AutoSar Version Numbers of Port_Siul_LLD.c and Port_Siul_LLD.h are different"
#endif
/* Check if Port_Siul_LLD.c and Port_Siul_LLD.h are of the same software version */
#if ((SIUL_SW_MAJOR_VERSION_LLD_C != SIUL_SW_MAJOR_VERSION_LLD_H) || \
     (SIUL_SW_MINOR_VERSION_LLD_C != SIUL_SW_MINOR_VERSION_LLD_H) || \
     (SIUL_SW_PATCH_VERSION_LLD_C != SIUL_SW_PATCH_VERSION_LLD_H))
  #error "Software Version Numbers of Port_Siul_LLD.c and Port_Siul_LLD.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
*  @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Required Rule 19.15
*/
#include "MemMap.h"
/*
* @brief Segment descriptor for data arranged in array
* @implements DPORT05005
*/

/* Port_GPIODirection variable is only used by PORT_Siul_SetPinDirection and PORT_Siul_SetPinMode
functions */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON)
STATIC VAR(uint16, PORT_VAR) Port_GPIODirection[PAD_16BLOCK_NO];
#endif

/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
*  @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Required Rule 19.15
*/
/*
*  @violates @ref Port_Siul_LLD_C_REF_2 Violates MISRA 2004 Advisory Rule 19.1
*/
#include "MemMap.h"

/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define PORT_START_SEC_VAR_INIT_UNSPECIFIED
/*
*  @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Required Rule 19.15
*/
/*
*  @violates @ref Port_Siul_LLD_C_REF_2 Violates MISRA 2004 Advisory Rule 19.1
*/
#include "MemMap.h"
/*
* @brief Pointer that after init will contain the address of the low level initialization structure
* @implements DPORT05006
*/
STATIC P2CONST(Port_ConfigType, PORT_VAR, PORT_APPL_CONST) Port_ConfigPtr = NULL_PTR;
/*
* @violates @ref Port_Siul_LLD_C_REF_16 Violates MISRA 2004 Required Rule 5.1
*/
#define PORT_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
*  @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Required Rule 19.15
*/
/*
*  @violates @ref Port_Siul_LLD_C_REF_2 Violates MISRA 2004 Advisory Rule 19.1
*/
#include "MemMap.h"
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#define PORT_START_SEC_CODE
/*
* @file    Port_Siul_LLD.c
* @implements DPORT00027
* @violates @ref Port_Siul_LLD_C_REF_2 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
* @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"

#if (PORT_SET_PIN_MODE_API == STD_ON)
/* @brief      Sets the PSMI registers */
 STATIC FUNC(void, PORT_CODE) Siul_PSMI_PadSet
(
    VAR(uint8, AUTOMATIC) pinPad,
    VAR(uint8, AUTOMATIC) pinModeIndex
);
#endif


#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
* @brief      Sets the PSMI registers
* @details    Sets the PSMI according to the mode to be set.
*
* @param[in]     pinPad          Pin ID number
* @param[in]     pinModeIndex    Search index according to the mode to be set
*
* @return none
*
* @pre Port_Init must have been called
* @post none
* @implements DPORT05007
*/
STATIC FUNC(void, PORT_CODE) Siul_PSMI_PadSet
(
    VAR(uint8, AUTOMATIC) pinPad,
    VAR(uint8, AUTOMATIC) pinModeIndex
)
{
    VAR(Pad_PSMI_Setting,AUTOMATIC) padPSMIData = Pad_funct_extrasettings[pinPad][pinModeIndex];

    /* The code to be used for pad selection */
    VAR(uint8, AUTOMATIC) pinPSMIvalue = padPSMIData.PSMI_code;

    /* The number of the used PSMI */
    VAR(uint8, AUTOMATIC) pinPSMInumber = padPSMIData.PSMI_id;

    VAR(uint8, AUTOMATIC) pinPSMIoffset = pinPSMInumber & (uint8)3U;
    VAR(uint8, AUTOMATIC) pinPSMIindex = pinPSMInumber & (uint8)0xFC;
    VAR(uint8, AUTOMATIC) pinPSMIRegNum = pinPSMInumber >> 2;
    if ( pinPSMIRegNum  < PORT_NMBR_PSMI_REGS ){
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    VAR(uint32, AUTOMATIC) pinPSMIlocal = REG_READ32(SIUL_PSMI(pinPSMIindex)) &
                          (uint32)(~(SIUL_PSMI_PADSEL0>>((uint8)8*pinPSMIoffset)) );
    pinPSMIoffset = (uint8)3U - pinPSMIoffset;
    pinPSMIlocal |= (uint32)( ((uint32)pinPSMIvalue) << ((uint32)8UL*(uint32)pinPSMIoffset) );
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    REG_WRITE32( SIUL_PSMI(pinPSMIindex), pinPSMIlocal );
    }

}
/* PORT_SET_PIN_MODE_API == STD_ON */
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Initializes the SIUL IP Driver
* @details      The function PORT_Siul_Init will initialize ALL ports and port pins with the
*               configuration set pointed to by the parameter ConfigPtr.
*
* @param[in]     ConfigPtr      A pointer to the structure which contains initialization parameters
*
* @return none
*
* @pre    none
* @post   No function of the driver is executed without the initialisation of the module.
*
* @implements DPORT05008
*/
FUNC(void, PORT_CODE) PORT_Siul_Init
(
    P2CONST(Port_ConfigType,AUTOMATIC,PORT_APPL_CONST) ConfigPtr
)
{
    /* Initialize all variables */
    VAR(uint8, AUTOMATIC) iu8PinIndex;
    VAR(uint8, AUTOMATIC) iu8PSMIIndex;
    VAR(uint16, AUTOMATIC) iu16UnUsedpinIndex;
    VAR(uint16, AUTOMATIC) iu16pcrpin;
    VAR(uint8, AUTOMATIC) numPins = (uint8)(ConfigPtr->numPins);

    VAR(uint16, AUTOMATIC) NoUnUsedPins = (uint8)(ConfigPtr->NoUnUsedPins);
    /* [PORT005]: Initialize All Default Port Pins */
    for (iu16UnUsedpinIndex = (uint16)0U; iu16UnUsedpinIndex < NoUnUsedPins; iu16UnUsedpinIndex++)
    {
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        iu16pcrpin = (uint16)(ConfigPtr->Port_NoUnUsedPadsArray[iu16UnUsedpinIndex]);
        /* Write PCR configuration from Configuration tool */
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        REG_WRITE16(SIUL_PCR(iu16pcrpin), (uint16)(ConfigPtr->Port_LLD_UnUsedPinPtr[0].PCR));
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        REG_WRITE8(SIUL_GPDO(iu16pcrpin), (uint8)(ConfigPtr->Port_LLD_UnUsedPinPtr[0].PDO));
    }
    /* Initialize Pad configuration registers to reset value */
    for (iu8PSMIIndex= (uint8)0U; iu8PSMIIndex < PORT_NMBR_PSMI_REGS; iu8PSMIIndex++)
    {
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        REG_WRITE32( SIUL_PSMI(((uint32)iu8PSMIIndex)<<2), (uint32)(SIUL_PSMI_RESET) );
    }
    /* Initialize All Configured Port Pins */
    for (iu8PinIndex= (uint8)0U; (uint8)iu8PinIndex < (uint8)numPins; (iu8PinIndex)++)
    {
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        VAR(uint8, AUTOMATIC) pinPad = (uint8)(ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].SIUPin);

        /* Set pin to High value */
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ((uint8)1 == (uint8)(ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].PDO))
        {
            /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
            /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_WRITE8( SIUL_GPDO(pinPad), (uint8)STD_HIGH );
        }
        /* Set pin to Low value */
        else
        {
            /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
            /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_WRITE8( SIUL_GPDO(pinPad), (uint8)STD_LOW );
        }
        
       /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
       /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        REG_WRITE16( SIUL_PCR(pinPad), (uint16)(ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].PCR));
    }
    /* Write Pad configuration registers from Configuration tool */
    for (iu8PSMIIndex= (uint8)0U; iu8PSMIIndex < PORT_NMBR_PSMI_REGS; iu8PSMIIndex++)
    {
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        REG_WRITE32( SIUL_PSMI(((uint32)iu8PSMIIndex)<<2), (uint32)(ConfigPtr->Port_LLD_PadSelConfPtr[iu8PSMIIndex]) );
    }

    /* Port_GPIODirection is only used by PORT_Siul_SetPinDirection and PORT_Siul_SetPinMode
       functions */
    #if (PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON)
    /* Initialize the Array with Change Direction Flags for GPIO */
    for (iu8PinIndex= (uint8)0U; iu8PinIndex < PAD_16BLOCK_NO; iu8PinIndex++)
    {
        Port_GPIODirection[iu8PinIndex] = (uint16)0UL;
    }
    #endif

    /* Save pointer to LLD configuration structure */
    Port_ConfigPtr = ConfigPtr;
}


#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/**
* @brief   Sets the port pin direction
* @details Sets the pin direction at runtime, changing it only if the pin is configurated as
*          changeable.
*
* @param[in]     iu8PinIndex             Pin ID number
* @param[in]     chenDirection           Port Pin direction
*
* @return Error code after execution
* @retval 0   No error occured
* @retval 1   Pin direction cannot be changed
*
* @pre Port_Init must have been called
* @post none
*
* @implements DPORT05009
*/
FUNC(uint8, PORT_CODE) PORT_Siul_SetPinDirection
(
    VAR(Port_PinType, AUTOMATIC) iu8PinIndex,
    VAR(Port_PinDirectionType, AUTOMATIC) chenDirection
)
{
    /* Point to the Port Pin PCR register address */
    /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    VAR(uint8, AUTOMATIC) pinPad = (uint8)Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].SIUPin;

    /* Return value */
    VAR(uint8, AUTOMATIC) pinDirError = (uint8)0U;

    /* Bit Offset and Table value for change direction flag word*/
    VAR(uint8, AUTOMATIC) pinDescBitOffset = (uint8)(pinPad & SIUL_MODE_BIT_OFFSET_MASK);
    VAR(uint16, AUTOMATIC) pinChangeDirFlagWord = Port_GPIODirection[(uint8)((uint8)pinPad>>4)];

    /* Enter critical region */
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
    /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* Check the Direction changeability option */
    if ((Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].DC) || (pinChangeDirFlagWord &
    /* @violates @ref Port_Siul_LLD_C_REF_11 MISRA 2004 Rule 12.6,
       boolean expression required for operator: '||'; the -strong(B,...) option can help provide Boolean-by-enforcement. */
       (uint16)(1UL<<pinDescBitOffset)) )
    {
        /* Configures Port Pin as Output */
        if (chenDirection == PORT_PIN_OUT)
        {
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_BIT_CLEAR16(SIUL_PCR(pinPad), SIUL_PCR_IBE_ON);
    /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_BIT_SET16(SIUL_PCR(pinPad), SIUL_PCR_OBE_ON);
        }
        /* Configures Port Pin as Input */
        else
        {
     /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_BIT_CLEAR16(SIUL_PCR(pinPad), SIUL_PCR_OBE_ON);
     /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */   
            REG_BIT_SET16(SIUL_PCR(pinPad), SIUL_PCR_IBE_ON);
        }
    }
    /* Direction changeability is NOT supported */
    else
    {
        pinDirError = (uint8)1U;
    }
    /* Exit critical region */
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
    return pinDirError;
}
/* PORT_SET_PIN_DIRECTION_API == STD_ON */
#endif

/**
* @brief   Refreshes port direction.
* @details This service shall refresh the direction of all configured ports to the configured
*          direction. The PORT driver shall exclude from refreshing those port pins that are
*          configured as pin direction changeable during runtime.
*
* @param[in]     numPins    Number of pins to be refreshed
* @return none
*
* @pre Port_Init must have been called
* @post none
*
* @implements     DPORT05010
*/
FUNC(void, PORT_CODE) PORT_Siul_RefreshPortDirection
(
    VAR(uint8, AUTOMATIC) numPins
)
{
    /* Index of the port table */
    VAR(uint8, AUTOMATIC) iu8PinIndex = (uint8)0U;

    /* Initialize All Configured Port Pins that aren't direction changable */
    for (iu8PinIndex = (uint8)0U; iu8PinIndex < numPins; iu8PinIndex++)
    {
        /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        if ((boolean)FALSE == Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].DC)
        {
       /* Point to the Port Pin PCR register address*/
       /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
       /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
       VAR(uint8, AUTOMATIC) pinPad = (uint8)Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].SIUPin;

           /* Enter critical region */
           SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
           /* Configures Port Pin as Output */
           /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
           /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
           if (Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].PCR & SIUL_PCR_OBE)
           {
/* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
              REG_BIT_SET16(SIUL_PCR(pinPad), SIUL_PCR_OBE);
           }
           else
           {
/* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
              REG_BIT_CLEAR16(SIUL_PCR(pinPad), SIUL_PCR_OBE);
           }
           /* Configures Port Pin as Input */
           /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
           /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
           if (Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].PCR & SIUL_PCR_IBE)
           {
/* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
              REG_BIT_SET16(SIUL_PCR(pinPad), SIUL_PCR_IBE);
           }
           else
           {
/* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
              REG_BIT_CLEAR16(SIUL_PCR(pinPad), SIUL_PCR_IBE);
           }
           /* Exit critical region */
           SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
        }
    }
}


#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
* @brief   Sets the port pin mode.
* @details The function will set the port pin mode of the referenced pin during runtime
*
* @param[in]     iu8PinIndex     Pin ID number
* @param[in]     chu8Mode        New Port Pin mode to be set on port pin
*
* @return Error code after execution
* @retval 0   No error occured
* @retval PORT_E_MODE_UNCHANGEABLE   Pin mode cannot be changed
* @retval PORT_E_PARAM_INVALID_MODE  Invalid mode
*
* @pre Port_Init must have been called
* @post none
*
* @implements     DPORT05011
*/
FUNC(uint8, PORT_CODE) PORT_Siul_SetPinMode
(
    VAR(Port_PinType, AUTOMATIC) iu8PinIndex,
    VAR(Port_PinModeType, AUTOMATIC) chu8Mode
)
{
    /* Pin desccription variables */
    VAR(uint16, AUTOMATIC) pinDescWord;
    VAR(uint16, AUTOMATIC) pinDirFlagWord;
    VAR(uint8, AUTOMATIC) pinModeIndex;
    VAR(uint8, AUTOMATIC) pinDescBitOffset;

    /* Return value */
    VAR(uint8, AUTOMATIC) pinModeError = (uint8)0x0U;

    /* Point to the Port Pin PCR register address*/
    /* @violates @ref Port_Siul_LLD_C_REF_12 Violates MISRA 2004 Required Rule 17.4 */
    VAR(uint8, AUTOMATIC) pinPad = (uint8)Port_ConfigPtr->Port_LLD_PinConfPtr[iu8PinIndex].SIUPin;

    if ((uint8)chu8Mode >= PAD_MODE_OPTIONS)
    {
        /* @violates @ref Port_Siul_LLD_C_REF_4 Violates MISRA 2004 Required Rules 14.7,
           Return statement before end of function. */
        return (uint8)PORT_E_PARAM_INVALID_MODE;
    }

    /* Code of the pin mode */
    pinModeIndex = (uint8)chu8Mode;

    /* Bit offset of Pin index inside the pin description matrix */
    pinDescBitOffset = (uint8)(pinPad & SIUL_MODE_BIT_OFFSET_MASK);

    /* Selected word inside the pin description matrix */
    pinDescWord = (uint16)Port_PinDescription[pinModeIndex][(uint8)((uint8)pinPad>>4)];

    /* Check if desired mode is valid for selected pin */
    if (pinDescWord & (uint16)(1UL<<pinDescBitOffset))
    {
        pinDirFlagWord = Port_GPIODirection[(uint8)((uint8)pinPad>>4)];
        if (chu8Mode == PORT_GPIO_MODE)
        {   /* Set the change direction flag */
            pinDirFlagWord |= (uint16)(1UL<<pinDescBitOffset);
        }
        else
        {   /* Reset the change direction flag */
            pinDirFlagWord &= (uint16)(~((uint16)(1UL<<pinDescBitOffset)));
        }
        Port_GPIODirection[(uint8)((uint8)pinPad>>4U)] = pinDirFlagWord;

        /* Enter critical region */
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
        if (chu8Mode == PORT_ANALOG_INPUT_MODE)
        {
            /* Set the ANALOGICAL mode in PCR */
            /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_WRITE16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_APC);
        }
        #if ((IPV_SIUL == IPV_SIUL_01_00_01_15)||(IPV_SIUL == IPV_SIUL_01_00_01_17)||(IPV_SIUL ==IPV_SIUL_01_00_02_02))
            /* Perform no operation */
        #else
        else if (chu8Mode == PORT_OSC_SIGNAL_MODE)
        {
            /* Set the OSCILLATOR mode in PCR */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_WRITE16(SIUL_PCR(pinPad), (uint16)0x0UL);
        }
        #endif
        else
        {
            if (chu8Mode == PORT_ONLY_INPUT_MODE)
            {
                /* Set the INPUT mode in PCR */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_WRITE16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_IBE);

                /* Prepare the index for PSMI table */
                pinModeIndex = (uint8)3U;
                /* Enter critical region */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
                /* Set the proper mode in PSMI */
                Siul_PSMI_PadSet(pinPad,pinModeIndex);
                /* Exit critical region */
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
            }
            else if (chu8Mode == PORT_EXTRA_INPUT_MODE)
            {
                /* Set the INPUT mode in PCR */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_WRITE16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_IBE);

                /* Prepare the index for PSMI table */
                pinModeIndex = (uint8)4U;
                /* Enter critical region */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
                /* Set the proper mode in PSMI */
                Siul_PSMI_PadSet(pinPad,pinModeIndex);
                /* Exit critical region */
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
            }
            #if ((IPV_SIUL == IPV_SIUL_01_00_01_15)||(IPV_SIUL == IPV_SIUL_01_00_01_17))
              /* Perform no operation */
            #else
            else if (chu8Mode == PORT_EXTRA2_INPUT_MODE)
            {
                /* Set the INPUT mode in PCR */
        /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_WRITE16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_IBE);
                /* Prepare the index for PSMI table */
                pinModeIndex = (uint8)6U;
                /* Enter critical region */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
                /* Set the proper mode in PSMI */
                Siul_PSMI_PadSet(pinPad,pinModeIndex);
                /* Exit critical region */
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
            }
            else if (chu8Mode == PORT_ALT4_FUNC_MODE)
            {
                /* Clear the previous mode */
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_BIT_CLEAR16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_APC);
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
            REG_BIT_CLEAR16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_PA);
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_BIT_SET16(SIUL_PCR(pinPad), ((uint16)4<<SIUL_PCR_PA_OFFSET));
                /* Prepare the index for PSMI table */
                pinModeIndex = (uint8)5U;
                /* Enter critical region */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
                /* Set the proper mode in PSMI */
                Siul_PSMI_PadSet(pinPad,pinModeIndex);
                /* Exit critical region */
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
            }
            #endif
            else
            {
                /* Clear the previous mode */
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_BIT_CLEAR16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_APC);
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                REG_BIT_CLEAR16(SIUL_PCR(pinPad), (uint16)SIUL_PCR_PA);
                /* @violates @ref Port_Siul_LLD_C_REF_10 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* Set the new mode in PCR */
                REG_BIT_SET16(SIUL_PCR(pinPad), ((uint16)chu8Mode<<SIUL_PCR_PA_OFFSET));

                /* For alternative functionality - not GPIO */
                if (chu8Mode != (Port_PinModeType)0)
                {
                    /* Prepare the index for PSMI table */
                    pinModeIndex = (uint8)chu8Mode - (uint8)1U;
                    /* Enter critical region */
                    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
                    /* Set the proper mode in PSMI */
                    Siul_PSMI_PadSet(pinPad,pinModeIndex);
                    /* Exit critical region */
                    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
                }
            }
        }
        /* Exit critical region */
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
    }
    else
    {
        /* Check if exist a possible alternative mode for this pin */
        for (pinModeIndex = (uint8)0x1U; pinModeIndex < PAD_MODE_OPTIONS; pinModeIndex++)
        {
            pinDescWord = (uint16)Port_PinDescription[pinModeIndex][(uint8)(pinPad>>(uint8)4U)];

/* @violates @ref Port_Siul_LLD_C_REF_7 Violates MISRA 2004 Required Rules 10.5, Shift left of
   signed quantity(int), FALSE: the quantity is unsigned. */
            /* A possible mode has found */
            if (pinDescWord & (uint16)((uint16)1UL<<pinDescBitOffset))
            {
               break;
            }
        }
        /* No possible modes for this pin. The mode is unchangeable */
        if (pinModeIndex == PAD_MODE_OPTIONS)
        {
            pinModeError = (uint8)PORT_E_MODE_UNCHANGEABLE;
        }
        /* Desired mode is NOT valid for this pin. The mode is invalid */
        else
        {
            pinModeError = (uint8)PORT_E_PARAM_INVALID_MODE;
        }
    }
    return pinModeError;
}
/* (PORT_SET_PIN_MODE_API == STD_ON) */
#endif

#define PORT_STOP_SEC_CODE
/**
* @file  Port_Siul_LLD.c
* @implements DPORT00027
* @violates @ref Port_Siul_LLD_C_REF_2 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
* @violates @ref Port_Siul_LLD_C_REF_6 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"

#endif


#ifdef __cplusplus
}
#endif
/* PORT_SIUL_LLD_C */
#endif
/** @} */
