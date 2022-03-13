/**
* @file    Port_Cfg.c
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup  Port
* @{
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
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section PORT_CFG_REF_2
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* Many type conversions are implemented in MACROS. The code was tested successfully with 3 different compilers.
*
* @section PORT_CFG_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section PORT_CFG_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section PORT_CFG_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section PORT_CFG_REF_6
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
/**
* @file    Port_Cfg.c
* @implements   DPORT00011
*/
#include "Port.h"


#ifdef PORT_PRECOMPILE_SUPPORT
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file         Port_Cfg.c
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
* @implements   DPORT04022
*/
#define PORT_VENDOR_ID_CFG_C                       43
/*
* @violates @ref PORT_CFG_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref PORT_CFG_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
/*
* @violates @ref PORT_CFG_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref PORT_CFG_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        0
/*
* @violates @ref PORT_CFG_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref PORT_CFG_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     3
#define PORT_SW_MAJOR_VERSION_CFG_C                1
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @file         Port_Cfg.c
* @implements   DPORT06001
*/
/* Check if Port_Cfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif

/* Check if Port_Cfg.c and Port.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION))
   #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/* Check if Port_Cfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*
* @violates @ref PORT_CFG_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @file  Port_Cfg.c
* @implements   DPORT00012
*/
/* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include' */
/*
* @violates @ref PORT_CFG_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"



/*
* @violates @ref PORT_CFG_REF_2 Violates MISRA 2004 Required Rules 10.1,Implicit conversion changes signedness.
*/
#if (Port_NoUnUsedPins != 0)
/**
 * @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
 */
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST(uint16, PORT_CONST) Port_NoUnUsedPadsArrayDefault[Port_NoUnUsedPins]=
{
(uint16)123,
(uint16)124,
(uint16)125,
(uint16)126,
(uint16)127,
(uint16)128,
(uint16)129,
(uint16)130,
(uint16)131,
(uint16)132,
(uint16)133,
(uint16)134,
(uint16)135,
(uint16)136,
(uint16)137,
(uint16)138,
(uint16)139,
(uint16)140,
(uint16)141,
(uint16)142,
(uint16)143,
(uint16)144,
(uint16)145,
(uint16)146,
(uint16)147,
(uint16)148
};
#endif

/**
 * @brief Default Configuration for Pins not initialized
 */
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST(Port_LLD_UnUsedPinConfigType, PORT_CONST) Port_LLD_UnUsedPin[1] =
{
 /**
   * @note: Configuration of Default pin
   */
      {(uint16)0x0000, (sint8)0}
   };
/*
* @violates @ref PORT_CFG_REF_5 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
CONST(Port_LLD_PinConfigType, PORT_CONST) Port_LLD_PinConfigDefault[PORT_MAX_PIN_SETTINGS]=
{
/**
* @violates @ref PORT_CFG_REF_2 Violates MISRA 2004 Required Rules 10.1,Implicit conversion changes signedness.
*/
  {(uint8)0, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)TRUE},
  {(uint8)1, (uint16)0x0103, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)2, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)3, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)4, (uint16)0x0603, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)5, (uint16)0x0502, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)6, (uint16)0x0502, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)7, (uint16)0x0502, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)8, (uint16)0x0502, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)9, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)TRUE},
  {(uint8)10, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)11, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)12, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)13, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)14, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)15, (uint16)0x0200, (sint8)1, (boolean)TRUE, (boolean)FALSE},
  {(uint8)16, (uint16)0x0203, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)17, (uint16)0x0103, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)18, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)19, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)20, (uint16)0x2000, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)21, (uint16)0x2000, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)22, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)23, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)24, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)25, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)26, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)27, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)28, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)29, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)30, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)31, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)32, (uint16)0x0900, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)33, (uint16)0x0a00, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)34, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)35, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)36, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)37, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)38, (uint16)0x0600, (sint8)1, (boolean)TRUE, (boolean)FALSE},
  {(uint8)39, (uint16)0x0100, (sint8)1, (boolean)TRUE, (boolean)FALSE},
  {(uint8)40, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)41, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)42, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)43, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)44, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)45, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)46, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)47, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)48, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)49, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)50, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)51, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)52, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)53, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)54, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)55, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)56, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)57, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)58, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)59, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)60, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)61, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)62, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)63, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)64, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)65, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)66, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)67, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)68, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)69, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)70, (uint16)0x0200, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)71, (uint16)0x0600, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)72, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)73, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)74, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)75, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)76, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)77, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)78, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)79, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)80, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)81, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)82, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)83, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)84, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)85, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)86, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)87, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)88, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)89, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)90, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)91, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)92, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)93, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)94, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)95, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)96, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)97, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)98, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)99, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)100, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)101, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)102, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)103, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)104, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)105, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)106, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)107, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)108, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)109, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)110, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)111, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)112, (uint16)0x0100, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)113, (uint16)0x0a00, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)114, (uint16)0x0a00, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)115, (uint16)0x0900, (sint8)0, (boolean)FALSE, (boolean)FALSE},
  {(uint8)116, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)117, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)118, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)119, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)120, (uint16)0x0100, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)121, (uint16)0x0900, (sint8)0, (boolean)TRUE, (boolean)FALSE},
  {(uint8)122, (uint16)0x0900, (sint8)0, (boolean)TRUE, (boolean)FALSE}
};

/**
 * @brief Pad selection default configuration
 */
 /*
* @violates @ref PORT_CFG_REF_2 Violates MISRA 2004 Required Rule 10.1, Implicit
* conversion changes signedness.
*/
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST(Port_LLD_PadSelConfigType, PORT_CONST) Port_LLD_PadSelConfigDefault[PORT_NMBR_PSMI_REGS]=
{
         (uint32)0x01000000,
         (uint32)0x00000002,
         (uint32)0x02030000,
         (uint32)0x00000000,
         (uint32)0x00000000,
      (uint32)0x00000000,
         (uint32)0x00000000,  
         (uint32)0x00000000,    
         (uint32)0x00000000,      
         (uint32)0x00000000,        
         (uint32)0x00000000,          
         (uint32)0x00000000,            
         (uint32)0x00000000,              
         (uint32)0x00000000,                
         (uint32)0x00000000,                  
         (uint32)0x00000000
};
                                                                                          

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the pre-compiled mode
*/
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST(Port_ConfigType, PORT_CONST) Port_ConfigPC =
{
  PORT_MAX_PIN_SETTINGS,
  Port_NoUnUsedPins,
/*
* @violates @ref PORT_CFG_REF_2 Violates MISRA 2004 Required Rule 10.1, Implicit
* conversion changes signedness.
*/ 
#if (Port_NoUnUsedPins != 0)
  Port_NoUnUsedPadsArrayDefault,
#else
  NULL_PTR,
#endif
  Port_LLD_UnUsedPin,
  Port_LLD_PinConfigDefault,
/*
* @violates @ref PORT_CFG_REF_2 Violates MISRA 2004 Required Rule 10.1, Implicit
* conversion changes signedness.
*/
  Port_LLD_PadSelConfigDefault
};


#if (PORT_SET_PIN_MODE_API == STD_ON)

















/**
 * @brief Port Pin description data
 * @remarks Covers MCAL2881
 */
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST (uint16, PORT_VAR) Port_PinDescription[9][10] =
{  
{ (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0xFFFF, (uint16)0x001F },
{ (uint16)0xEFFF, (uint16)0xF80D, (uint16)0xF57C, (uint16)0xF000, (uint16)0xEDFF, (uint16)0xFF7F, (uint16)0xFFFD, (uint16)0xF9FF, (uint16)0xB0FF, (uint16)0x001D },
{ (uint16)0xFDAB, (uint16)0x000F, (uint16)0xE7EF, (uint16)0xF000, (uint16)0xFFFA, (uint16)0x5FFF, (uint16)0x7DDF, (uint16)0x7F8E, (uint16)0x00F5, (uint16)0x0010 },
{ (uint16)0xF65D, (uint16)0xF807, (uint16)0x0FFC, (uint16)0x0000, (uint16)0x05E0, (uint16)0x4500, (uint16)0x0300, (uint16)0xF9C0, (uint16)0x0000, (uint16)0x0000 },
{ (uint16)0x0C88, (uint16)0xFFF0, (uint16)0x0000, (uint16)0xFFFF, (uint16)0x1000, (uint16)0x00FF, (uint16)0x0000, (uint16)0x0000, (uint16)0xFF00, (uint16)0x000F },
{ (uint16)0x9957, (uint16)0x070A, (uint16)0x1A98, (uint16)0x0003, (uint16)0x1A05, (uint16)0xAA00, (uint16)0x86AA, (uint16)0x0001, (uint16)0x480A, (uint16)0x0002 },
{ (uint16)0x0000, (uint16)0x0300, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000 },
{ (uint16)0x0000, (uint16)0x000A, (uint16)0x0818, (uint16)0x0000, (uint16)0x0200, (uint16)0x8200, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000 },
{ (uint16)0x59C8, (uint16)0x0000, (uint16)0xD03C, (uint16)0x0000, (uint16)0x54D4, (uint16)0x8000, (uint16)0x0102, (uint16)0x0000, (uint16)0x0000, (uint16)0x0000 }
};
  
/**
 * @brief Port PSMI settings data
 */
/*
* @violates @ref PORT_CFG_REF_5 Violates MISRA 2004 Required Rule 8.10
*/
CONST(Pad_PSMI_Setting,PORT_CONST) Pad_funct_extrasettings[149][7]=
{  
{ {(uint8)  38,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  21,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  39,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  13,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  14,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  60,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  15,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  16,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  59,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  17,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  22,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)  31,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  18,(uint8)  0}, {(uint8)  30,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  19,(uint8)  0}, {(uint8)  29,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  58,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  40,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  41,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)   5,(uint8)  0}, {(uint8)   6,(uint8)  0}, {(uint8)  38,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)   6,(uint8)  1}, {(uint8)   5,(uint8)  1}, {(uint8)  39,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  42,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  43,(uint8)  0}, {(uint8)  62,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  30,(uint8)  1}, {(uint8)  42,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  43,(uint8)  1}, {(uint8)  29,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  62,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  13,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)   6,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  14,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  15,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  16,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  17,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)   7,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)   9,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   0,(uint8)  0}, {(uint8)   3,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  57,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   8,(uint8)  0}, {(uint8)   2,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  54,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  55,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  13,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  17,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)  58,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   0,(uint8)  1}, {(uint8)   3,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  20,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  11,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  21,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  22,(uint8)  0}, {(uint8)  10,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  12,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  25,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)   9,(uint8)  1}, {(uint8)  26,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  27,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  28,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   4,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   8,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)   7,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)   9,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  23,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  24,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  23,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  24,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)   1,(uint8)  0}, {(uint8)   2,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  56,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  25,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  31,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  11,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  10,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  12,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  18,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  19,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  20,(uint8)  1}, {(uint8)  12,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  21,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  22,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  23,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  24,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  44,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   1,(uint8)  1}, {(uint8)   2,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  45,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  46,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)  59,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  51,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  52,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  60,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  53,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  47,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   0,(uint8)  2}, {(uint8)   3,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   4,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  34,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  32,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  33,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  56,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  49,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  50,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  10,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  25,(uint8)  1}, {(uint8)  57,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)  36,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  26,(uint8)  1}, {(uint8)  37,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  27,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  28,(uint8)  1}, {(uint8)  35,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  44,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  61,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  45,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)   8,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  46,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  47,(uint8)  0}, {(uint8)   7,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  48,(uint8)  0}, {(uint8)   9,(uint8)  3}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  37,(uint8)  1}, {(uint8)  48,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  32,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)  51,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  34,(uint8)  1}, {(uint8)  52,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  35,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)  53,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  49,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  40,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  41,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  61,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  42,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  43,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  54,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  55,(uint8)  1}, {(uint8)  35,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  56,(uint8)  2}, {(uint8)  37,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  57,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  33,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  34,(uint8)  2}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)  36,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)  37,(uint8)  3}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0} },
{ {(uint8)0xFF,(uint8)  0}, {(uint8)  50,(uint8)  1}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}, {(uint8)0xFF,(uint8)  0}}
};
  #endif

/*
* @violates @ref PORT_CFG_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
 * @file  Port_Cfg.c
 * @violates @ref PORT_CFG_REF_1 Declaration before '#include'
 * @violates @ref PORT_CFG_REF_3 Repeated include file MemMap.h
 */
#include "MemMap.h"

#endif    /* PORT_PRECOMPILE_SUPPORT*/

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
