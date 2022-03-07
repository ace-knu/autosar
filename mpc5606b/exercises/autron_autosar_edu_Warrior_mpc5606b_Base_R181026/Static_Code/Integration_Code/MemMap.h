/*******************************************************************************
**  (C) 2014-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemMap.h                                                      **
**                                                                            **
**  TARGET    : MCU(MPC, RH850, ..) using GHS complier                        **
**                                                                            **
**  PRODUCT   : AUTOSAR BSW R4.0.3 Modules                                    **
**                                                                            **
**  PURPOSE   : Provision for sections for memory mapping.                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By     Description                                 **
********************************************************************************
** 1.1.18    25-09-2017    #10074                                             **
** 1.1.17    19-09-2017    #9992                                              **
** 1.1.16    30-08-2017    #9878                                              **
** 1.1.15    30-08-2017    #6139                                              **
** 1.1.14    29-08-2017    #9726                                              **
** 1.1.13    11-07-2017    #8576                                              **
** 1.1.11    29-06-2017    #8988                                              **
** 1.1.10    27-06-2017    #8988                                              **
** 1.1.9     23-05-2017    #8599                                              **
** 1.1.8     15-05-2017    #8516                                              **
** 1.1.7     24-04-2017    #7921                                              **
** 1.1.5     04-04-2017    #8062, #8063                                       **
** 1.1.4     23-03-2017    #7406                                              **
** 1.1.3     22-03-2017    #7406                                              **
** 1.1.2     10-02-2017    #7471                                              **
** 1.1.0     23-01-2017    #7229                                              **
** 1.0.6     19-01-2017    #7166                                              **
** 1.0.5     01-12-2016    #6829                                              **
** 1.0.4     29-11-2016    #6781 #6782 #6796                                  **
** 1.0.3     21-11-2016    #5032                                              **
** 1.0.2     15-11-2016    Integrated Memmap for GHS compiler                 **
** 1.0.1     09-11-2016    Integrated Memmap for GHS compiler                 **
** 1.0.0     29-Apr-2014   MJ.Woo Initial Version                             **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for varification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "HwResource.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MEMMAP_AR_MAJOR_VERSION   4
#define MEMMAP_AR_MINOR_VERSION   0
#define MEMMAP_AR_PATCH_VERSION   3

/* File version information */
#define MEMMAP_SW_MAJOR_VERSION   1
#define MEMMAP_SW_MINOR_VERSION   0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols.
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/*                                ATM                                         */
/* -------------------------------------------------------------------------- */
#elif defined (ATM_START_SEC_CONST_8)
  #undef       ATM_START_SEC_CONST_8

////  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ATM_STOP_SEC_CONST_8)
  #undef       ATM_STOP_SEC_CONST_8

////  #pragma ghs section

#elif defined (ATM_START_SEC_CONST_UNSPECIFIED)
  #undef       ATM_START_SEC_CONST_UNSPECIFIED

////  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (ATM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ATM_STOP_SEC_CONST_UNSPECIFIED
// #pragma ghs section

#elif defined (ATM_START_SEC_CODE)
  #undef       ATM_START_SEC_CODE

// #pragma ghs section text=".text.ATM_CODE"
////  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
////  #pragma ghs section bss=".bss.ATM_RAM_VAR_CLEARED"
////  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ATM_STOP_SEC_CODE)
  #undef       ATM_STOP_SEC_CODE
////  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                CANTP                                       */
/* -------------------------------------------------------------------------- */
#elif defined (CANTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_8)
  #undef       CANTP_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_16)
  #undef       CANTP_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_16)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_8)
  #undef       CANTP_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_8)
  #undef       CANTP_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_16)
  #undef       CANTP_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_16)
  #undef       CANTP_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (CANTP_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_8)
  #undef       CANTP_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_8)
  #undef       CANTP_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (CANTP_START_SEC_VAR_INIT_16)
  #undef       CANTP_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_VAR_INIT_16)
  #undef       CANTP_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (CANTP_START_SEC_CODE)
  #undef       CANTP_START_SEC_CODE

//  #pragma ghs section text=".text.CANTP_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTP_STOP_SEC_CODE)
  #undef       CANTP_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 DCM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_NO_INIT_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_8)
  #undef       DCM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_16)
  #undef       DCM_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_16)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_32)
  #undef       DCM_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_8)
  #undef       DCM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_8)
  #undef       DCM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_16)
  #undef       DCM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_16)
  #undef       DCM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_32)
  #undef       DCM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_32)
  #undef       DCM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_8)
  #undef       DCM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_8)
  #undef       DCM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_16)
  #undef       DCM_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_16)
  #undef       DCM_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_32)
  #undef       DCM_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_32)
  #undef       DCM_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_BOOLEAN)
  #undef       DCM_START_SEC_CONST_BOOLEAN

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_BOOLEAN)
  #undef       DCM_STOP_SEC_CONST_BOOLEAN
//  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_8)
  #undef       DCM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_8)
  #undef       DCM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_16)
  #undef       DCM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_16)
  #undef       DCM_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       DCM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DCM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (DCM_START_SEC_CODE)
  #undef       DCM_START_SEC_CODE

//  #pragma ghs section text=".text.DCM_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_CODE)
  #undef       DCM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (DCM_START_SEC_CALLOUT_CODE)
  #undef       DCM_START_SEC_CALLOUT_CODE

//  #pragma ghs section text=".text.DCM_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DCM_STOP_SEC_CALLOUT_CODE)
  #undef       DCM_STOP_SEC_CALLOUT_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             Dem                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DEM_START_SEC_CONST_BOOLEAN)
  #undef       DEM_START_SEC_CONST_BOOLEAN

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DEM_STOP_SEC_CONST_BOOLEAN)
  #undef       DEM_STOP_SEC_CONST_BOOLEAN
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_8)
  #undef       DEM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_8)
  #undef       DEM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_16)
  #undef       DEM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_16)
  #undef       DEM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_32)
  #undef       DEM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_32)
  #undef       DEM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_NO_INIT_8)
  #undef       DEM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DEM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section
#elif defined (DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section



#elif defined (DEM_START_SEC_CONST_UNSPECIFIED)
  #undef       DEM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DEM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (DEM_START_SEC_CODE)
  #undef       DEM_START_SEC_CODE

//  #pragma ghs section text=".text.DEM_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DEM_STOP_SEC_CODE)
  #undef       DEM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (DEM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                              Det                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DET_START_SEC_VAR_NO_INIT_16)
  #undef       DET_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DET_STOP_SEC_VAR_NO_INIT_16)
  #undef       DET_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (DET_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DET_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (DET_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (DET_START_SEC_CONST_UNSPECIFIED)
  #undef       DET_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DET_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DET_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (DET_START_SEC_CODE)
  #undef       DET_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DET_STOP_SEC_CODE)
  #undef       DET_STOP_SEC_CODE
//  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                                 E2E                                        */
/* -------------------------------------------------------------------------- */

//#elif defined (E2E_START_SEC_CODE)
 // #undef       E2E_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
//#elif defined (E2E_STOP_SEC_CODE)
//  #undef       E2E_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 RegMon                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (REGMON_START_SEC_CODE)
  #undef       REGMON_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (REGMON_STOP_SEC_CODE)
  #undef       REGMON_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (REGMON_START_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_START_SEC_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (REGMON_STOP_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_VAR_UNSPECIFIED
//  #pragma ghs section

#elif defined (REGMON_START_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (REGMON_STOP_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 OS                                         */
/* -------------------------------------------------------------------------- */

#elif defined (OS_START_SEC_VAR_NO_INIT_8)
  #undef       OS_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OS_STOP_SEC_VAR_NO_INIT_8)
  #undef       OS_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_8)
  #undef       OS_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_8)
  #undef       OS_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_16)
  #undef       OS_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_16)
  #undef       OS_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_32)
  #undef       OS_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_32)
  #undef       OS_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_SAFETY_VAR_CLEARED"
#elif defined (OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OS_START_SEC_USER_STACK)
  #undef       OS_START_SEC_USER_STACK

//  #pragma ghs section bss=".USR_STACK"
#elif defined (OS_STOP_SEC_USER_STACK)
  #undef       OS_STOP_SEC_USER_STACK
//  #pragma ghs section

#elif defined (OS_START_SEC_APP_STACK)
  #undef       OS_START_SEC_APP_STACK
//  #pragma ghs section bss=".OSAPP_STACK"
#elif defined (OS_STOP_SEC_APP_STACK)
  #undef       OS_STOP_SEC_APP_STACK
//  #pragma ghs section

#elif defined (OS_START_SEC_TASK_STACK)
  #undef       OS_START_SEC_TASK_STACK
//  #pragma ghs section bss=".OSTASK_STACK"
#elif defined (OS_STOP_SEC_TASK_STACK)
  #undef       OS_STOP_SEC_TASK_STACK
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_32)
  #undef       OS_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_32)
  #undef       OS_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (OS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OS_START_SEC_CONST_32)
  #undef       OS_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OS_STOP_SEC_CONST_32)
  #undef       OS_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (OS_START_SEC_CONST_UNSPECIFIED)
  #undef       OS_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OS_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (OS_START_SEC_CODE)
  #undef       OS_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OS_STOP_SEC_CODE)
  #undef       OS_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (OS_START_SEC_API_CODE)
  #undef       OS_START_SEC_API_CODE

//  #pragma ghs section text=".text.OS_API_CODE"
#elif defined (OS_STOP_SEC_API_CODE)
  #undef       OS_STOP_SEC_API_CODE
//  #pragma ghs section

#elif defined (OS_START_SEC_EXCEPTION_VECTOR)
  #undef       OS_START_SEC_EXCEPTION_VECTOR

//  #pragma ghs section text=".vector.EXCEPTION"
#elif defined (OS_STOP_SEC_EXCEPTION_VECTOR)
  #undef       OS_STOP_SEC_EXCEPTION_VECTOR
//  #pragma ghs section

#elif defined (OS_START_SEC_INTERRUPT_VECTOR)
  #undef       OS_START_SEC_INTERRUPT_VECTOR

//  #pragma ghs section text=".vector.INTERRUPT"
#elif defined (OS_STOP_SEC_INTERRUPT_VECTOR)
  #undef       OS_STOP_SEC_INTERRUPT_VECTOR
//  #pragma ghs section

/* OS IOC - INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED
//  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE0_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED
//  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE1_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED
//  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_CORE2_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section data=".data.IOC_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

/* OS IOC - NO_INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
//  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE0_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
//  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE1_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
//  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_CORE2_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
//  #pragma ghs section
#elif defined (IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section bss=".bss.IOC_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 LinSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINSM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINSM_START_SEC_CONST_8)
  #undef       LINSM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINSM_STOP_SEC_CONST_8)
  #undef       LINSM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINSM_START_SEC_VAR_CLEARED_8)
  #undef       LINSM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_8)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (LINSM_START_SEC_CODE)
  #undef       LINSM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINSM_STOP_SEC_CODE)
  #undef       LINSM_STOP_SEC_CODE
//  #pragma ghs section



/* -------------------------------------------------------------------------- */
/*                 LinTrcv                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINTRCV_START_SEC_CODE)
  #undef       LINTRCV_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTRCV_STOP_SEC_CODE)
  #undef       LINTRCV_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINTRCV_7259GE_START_SEC_CODE)
  #undef       LINTRCV_7259GE_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTRCV_7259GE_STOP_SEC_CODE)
  #undef       LINTRCV_7259GE_STOP_SEC_CODE
//  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                             LinNm                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINNM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINNM_START_SEC_CODE)
  #undef       LINNM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINNM_STOP_SEC_CODE)
  #undef       LINNM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             FiM                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (FIM_START_SEC_CODE)
  #undef       FIM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FIM_STOP_SEC_CODE)
  #undef       FIM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (FIM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (FIM_START_SEC_CONST_UNSPECIFIED)
  #undef       FIM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FIM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FIM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                 FRSM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (FRSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

  #elif defined (FRSM_START_SEC_VAR_CLEARED_8)
  #undef       FRSM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_8)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_NO_INIT_8)
  #undef       FRSM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (FRSM_START_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRSM_START_SEC_CODE)
  #undef       FRSM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FRSM_STOP_SEC_CODE)
  #undef       FRSM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             FrIf                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (FRIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRIF_START_SEC_VAR_CLEARED_16)
  #undef       FRIF_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_16)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_8)
  #undef       FRIF_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_8)
  #undef       FRIF_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (FRIF_START_SEC_CODE)
  #undef       FRIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (FRIF_STOP_SEC_CODE)
  #undef       FRIF_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CANIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (CANIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_CLEARED_8)
  #undef       CANIF_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_8)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_NO_INIT_8)
  #undef       CANIF_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (CANIF_START_SEC_CONST_8)
  #undef       CANIF_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANIF_STOP_SEC_CONST_8)
  #undef       CANIF_STOP_SEC_CONST_8
//  #pragma ghs section

 #elif defined (CANIF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANIF_START_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

 #elif defined (CANIF_START_SEC_CODE)
  #undef        CANIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANIF_STOP_SEC_CODE)
  #undef       CANIF_STOP_SEC_CODE
//  #pragma ghs section

  /* -------------------------------------------------------------------------- */
  /*                 CANTRCV                                                    */
  /* -------------------------------------------------------------------------- */
#elif defined (CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

//#elif defined (CANTRCV_START_SEC_VAR_CLEARED_16)
//  #undef       CANTRCV_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_16)
// #undef       CANTRCV_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

//#elif defined (CANTRCV_START_SEC_VAR_CLEARED_32)
//  #undef       CANTRCV_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_32)
//  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANTRCV_STOP_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_8)
  #undef       CANTRCV_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_8)
  #undef       CANTRCV_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_16)
  #undef       CANTRCV_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_16)
  #undef       CANTRCV_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

 #elif defined (CANTRCV_START_SEC_CODE)
  #undef        CANTRCV_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_CODE)
  #undef       CANTRCV_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_8)
  #undef       CANTRCV_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_8)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (CANTRCV_START_SEC_VAR_INIT_16)
  #undef       CANTRCV_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_16)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 BswM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (BSWM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (BSWM_START_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (BSWM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (BSWM_START_SEC_CODE)
  #undef       BSWM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWM_STOP_SEC_CODE)
  #undef       BSWM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             ComM                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_8)
  #undef       COMM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_16)
  #undef       COMM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_32)
  #undef       COMM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_32)
  #undef       COMM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_8)
  #undef       COMM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_16)
  #undef       COMM_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_32)
  #undef       COMM_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_32)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_16
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_16
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_8
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section

#elif defined (COMM_START_SEC_CONST_8)
  #undef       COMM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMM_STOP_SEC_CONST_8)
  #undef       COMM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (COMM_START_SEC_CONST_UNSPECIFIED)
  #undef       COMM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COMM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COMM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (COMM_START_SEC_CODE)
  #undef       COMM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COMM_STOP_SEC_CODE)
  #undef       COMM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             LINIF                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINIF_START_SEC_CODE)
  #undef       LINIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINIF_STOP_SEC_CODE)
  #undef       LINIF_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_8)
  #undef       LINIF_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (LINIF_STOP_SEC_CONST_8)
  #undef       LINIF_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINIF_START_SEC_VAR_NO_INIT_8)
  #undef       LINIF_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             LINTP                                                          */
/* -------------------------------------------------------------------------- */

#elif defined (LINTP_START_SEC_CODE)
  #undef       LINTP_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (LINTP_STOP_SEC_CODE)
  #undef       LINTP_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_CLEARED_16)
  #undef       LINTP_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_16)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (LINTP_START_SEC_VAR_NO_INIT_8)
  #undef       LINTP_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (LINTP_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (LINTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             Com                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_8)
  #undef       COM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_16)
  #undef       COM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_8)
  #undef       COM_START_SEC_VAR_NOINIT_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_8)
  #undef       COM_STOP_SEC_VAR_NOINIT_8
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_16)
  #undef       COM_START_SEC_VAR_NOINIT_16
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_16)
  #undef       COM_STOP_SEC_VAR_NOINIT_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_32)
  #undef       COM_START_SEC_VAR_NOINIT_32
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_32)
  #undef       COM_STOP_SEC_VAR_NOINIT_32
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_16
//  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_8
//  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_8
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_SAVED_RAM"
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_CONST_8)
  #undef       COM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_8)
  #undef       COM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (COM_START_SEC_CONST_16)
  #undef       COM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_16)
  #undef       COM_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (COM_START_SEC_CONST_32)
  #undef       COM_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_32)
  #undef       COM_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (COM_START_SEC_CONST_UNSPECIFIED)
  #undef       COM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_CODE)
  #undef       COM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_CODE)
  #undef       COM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (COM_START_SEC_APPL_CODE)
  #undef       COM_START_SEC_APPL_CODE

//  #pragma ghs section text=".text.DEFAULT_APPL_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_APPL_CODE)
  #undef       COM_STOP_SEC_APPL_CODE
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NOINIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_8)
  #undef       COM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_16)
  #undef       COM_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_16)
  #undef       COM_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_NO_INIT_16)
  #undef       COM_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (COM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COM_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_32)
  #undef       COM_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_32)
  #undef       COM_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (COM_START_SEC_VAR_INIT_8)
  #undef       COM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COM_STOP_SEC_VAR_INIT_8)
  #undef       COM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             			PduR                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (PDUR_START_SEC_CODE)
  #undef       PDUR_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_CODE)
  #undef       PDUR_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_START_SEC_VAR_CLEARED_BOOLEAN

//	#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN

#elif defined (PDUR_START_SEC_VAR_INIT_32)
  #undef       PDUR_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_VAR_INIT_32)
  #undef       PDUR_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (PDUR_START_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (PDUR_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_8)
  #undef       PDUR_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_8)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_8)
  #undef       PDUR_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_8)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED

//	#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (PDUR_START_SEC_VAR_NO_INIT_16)
  #undef       PDUR_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_16)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             IpduM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_8)
  #undef       IPDUM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_8)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_16)
  #undef       IPDUM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_16)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_32)
  #undef       IPDUM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_32)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_8)
  #undef       IPDUM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_16)
  #undef       IPDUM_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_32)
  #undef       IPDUM_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_BOOLEAN)
  #undef       IPDUM_START_SEC_CONST_BOOLEAN

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_BOOLEAN)
  #undef       IPDUM_STOP_SEC_CONST_BOOLEAN
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_8)
  #undef       IPDUM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_8)
  #undef       IPDUM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_16)
  #undef       IPDUM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_16)
  #undef       IPDUM_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IPDUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (IPDUM_START_SEC_CODE)
  #undef       IPDUM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IPDUM_STOP_SEC_CODE)
  #undef       IPDUM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             			CanSM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANSM_START_SEC_CODE)
  #undef       CANSM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_CODE)
  #undef       CANSM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_8)
  #undef       CANSM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_8)
  #undef       CANSM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (CANSM_START_SEC_CONST_16)
  #undef       CANSM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANSM_STOP_SEC_CONST_16)
  #undef       CANSM_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_16)
  #undef       CANSM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_CLEARED_8)
  #undef       CANSM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_8)
  #undef       CANSM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_8)
  #undef       CANSM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_16)
  #undef       CANSM_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_16)
  #undef       CANSM_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (CANSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*             			CanNM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANNM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANNM_START_SEC_CODE)
  #undef       CANNM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANNM_STOP_SEC_CODE)
  #undef       CANNM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CANNM_START_SEC_CONST_8)
  #undef       CANNM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANNM_STOP_SEC_CONST_8)
  #undef       CANNM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANNM_STOP_SEC_VAR_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (CANNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       CANNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (CANNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             			CanCM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANCM_START_SEC_CONST_8)
  #undef      CANCM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANCM_STOP_SEC_CONST_8)
  #undef      CANCM_STOP_SEC_CONST_8
//  #pragma ghs section
#elif defined (CANCM_START_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CANCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section
#elif defined (CANCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section
#elif defined (CANCM_START_SEC_CODE)
  #undef      CANCM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CANCM_STOP_SEC_CODE)
  #undef      CANCM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             			OSEKNm                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (OSEKNM_START_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSEKNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CODE)
  #undef       OSEKNM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSEKNM_STOP_SEC_CODE)
  #undef       OSEKNM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_CONST_8)
  #undef       OSEKNM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSEKNM_STOP_SEC_CONST_8)
  #undef       OSEKNM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section
//#elif defined (OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
// #undef       OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
//  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
 #elif defined (OSEKNM_STOP_SEC_VAR_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section
#elif defined (OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSEKNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (OSEKNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             			ECUM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CODE)
  #undef       ECUM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ECUM_STOP_SEC_CODE)
  #undef       ECUM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CONFIG_CONST_32)
  #undef       ECUM_START_SEC_CONFIG_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG_CONST"
#elif defined (ECUM_STOP_SEC_CONFIG_CONST_32)
  #undef       ECUM_STOP_SEC_CONFIG_CONST_32
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_32)
  #undef       ECUM_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_32)
  #undef       ECUM_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_8)
  #undef       ECUM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_8)
  #undef       ECUM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ECUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (ECUM_START_SEC_CALLOUT_CODE)
  #undef       ECUM_START_SEC_CALLOUT_CODE

//  #pragma ghs section text=".text.DEFAULT_CALLOUT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ECUM_STOP_SEC_CALLOUT_CODE)
  #undef       ECUM_STOP_SEC_CALLOUT_CODE
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_32)
  #undef       ECUM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_32)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_16
// #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_CLEARED_8)
  #undef       ECUM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_8)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_NO_INIT_8)
  #undef       ECUM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_8
// #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 NM                                                         */
/* -------------------------------------------------------------------------- */

#elif defined (NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_8
//  #pragma ghs section

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_16
//  #pragma ghs section

#elif defined (NM_START_SEC_CONST_UNSPECIFIED)
  #undef       NM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NM_STOP_SEC_CONST_UNSPECIFIED
// #pragma ghs section

#elif defined (NM_START_SEC_CODE)
  #undef       NM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NM_STOP_SEC_CODE)
  #undef       NM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (NM_START_SEC_VAR_NO_INIT_8)
  #undef       NM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NM_STOP_SEC_VAR_NO_INIT_8
// #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 MemIf                                      */
/* -------------------------------------------------------------------------- */

#elif defined (MEMIF_START_SEC_CODE)
  #undef       MEMIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (MEMIF_STOP_SEC_CODE)
  #undef       MEMIF_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 Crc                                        */
/* -------------------------------------------------------------------------- */

#elif defined (CRC_START_SEC_CODE)
  #undef       CRC_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CRC_STOP_SEC_CODE)
  #undef       CRC_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_8)
  #undef       CRC_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_8)
  #undef       CRC_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_16)
  #undef       CRC_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_16)
  #undef       CRC_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (CRC_START_SEC_CONST_32)
  #undef       CRC_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CRC_STOP_SEC_CONST_32)
  #undef       CRC_STOP_SEC_CONST_32
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 NvM                                        */
/* -------------------------------------------------------------------------- */
#elif defined (NVM_START_SEC_CODE)
  #undef       NVM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NVM_STOP_SEC_CODE)
  #undef       NVM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_8)
  #undef       NVM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_8)
  #undef       NVM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_16)
  #undef       NVM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16
// #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_8)
  #undef       NVM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_START_SEC_VAR_NO_INIT_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_CLEARED_BOOLEAN
// #pragma ghs section

#elif defined (NVM_START_SEC_CONST_8)
  #undef       NVM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_8)
  #undef       NVM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (NVM_START_SEC_CONST_16)
  #undef       NVM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_16)
  #undef       NVM_STOP_SEC_CONST_16
//  #pragma ghs section


#elif defined (NVM_START_SEC_CONST_UNSPECIFIED)
  #undef       NVM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (NVM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NVM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_16)
  #undef       NVM_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_16)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_NO_INIT_32)
  #undef       NVM_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_32)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (NVM_START_SEC_VAR_INIT_8)
  #undef       NVM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (NVM_STOP_SEC_VAR_INIT_8)
  #undef       NVM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 Eep                                        */
/* -------------------------------------------------------------------------- */
#elif defined (EEP_START_SEC_CODE)
  #undef       EEP_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EEP_STOP_SEC_CODE)
  #undef       EEP_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_8)
  #undef       EEP_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_16)
  #undef       EEP_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_CLEARED_32)
  #undef       EEP_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16
//  #pragma ghs section

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32
//  #pragma ghs section

#elif defined (EEP_START_SEC_CONST_UNSPECIFIED)
  #undef       EEP_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (EEP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EEP_STOP_SEC_CONST_UNSPECIFIED
// #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 Ea                                         */
/* -------------------------------------------------------------------------- */
#elif defined (EA_START_SEC_CODE)
  #undef       EA_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EA_STOP_SEC_CODE)
  #undef       EA_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_START_SEC_NO_INIT_VAR_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_STOP_SEC_NO_INIT_VAR_BOOLEAN
//  #pragma ghs section

#elif defined (EA_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_SAVED_ZONE"
#elif defined (EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
//  #pragma ghs section

#elif defined (EA_START_SEC_CONST_16)
  #undef       EA_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (EA_STOP_SEC_CONST_16)
  #undef       EA_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (EA_START_SEC_CONST_UNSPECIFIED)
  #undef       EA_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (EA_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EA_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_16)
  #undef       EA_START_SEC_NO_INIT_VAR_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_16)
  #undef       EA_STOP_SEC_NO_INIT_VAR_16
//  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_8)
  #undef       EA_START_SEC_NO_INIT_VAR_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_8)
  #undef       EA_STOP_SEC_NO_INIT_VAR_8
//  #pragma ghs section

#elif defined (EA_START_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_START_SEC_NO_INIT_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 RTE                                                        */
/* -------------------------------------------------------------------------- */

#elif defined (BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_START_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_STOP_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_PERINSTANCEPARAMETER_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CAL                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CAL_START_SEC_CODE)
  #undef       CAL_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CAL_STOP_SEC_CODE)
  #undef       CAL_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CAL_START_SEC_CONST_32)
  #undef       CAL_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CAL_STOP_SEC_CONST_32)
  #undef       CAL_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (CAL_START_SEC_CONST_UNSPECIFIED)
  #undef       CAL_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CAL_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CAL_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CSM                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CSM_START_SEC_CODE)
  #undef       CSM_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CSM_STOP_SEC_CODE)
  #undef       CSM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (CSM_START_SEC_CONST_8)
  #undef       CSM_START_SEC_CONST_8
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CSM_STOP_SEC_CONST_8)
  #undef       CSM_STOP_SEC_CONST_8
//  #pragma ghs section
  
#elif defined (CSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CSM_START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
  
#elif defined (CSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section
  
#elif defined (CSM_START_SEC_VAR_CLEARED_8)
  #undef       CSM_START_SEC_VAR_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section
  
#elif defined (CSM_START_SEC_VAR_CLEARED_32)
  #undef       CSM_START_SEC_VAR_CLEARED_32
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

//#elif defined (CSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
//  #undef       CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//#elif defined (CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
//  #undef       CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 WDGIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (WDGIF_START_SEC_CODE)
  #undef       WDGIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGIF_STOP_SEC_CODE)
  #undef       WDGIF_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (WDGIF_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* ---------------------------------------------------------------------------*/
/*                           WDG_76_ACW                                       */
/* -------------------------------------------------------------------------- */
#elif defined (WDG_76_ACW_START_SEC_CODE)
  #undef       WDG_76_ACW_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDG_76_ACW_STOP_SEC_CODE)
  #undef       WDG_76_ACW_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_VAR_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_8)
  #undef       WDG_76_ACW_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_8)
  #undef       WDG_76_ACW_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_16)
  #undef       WDG_76_ACW_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_16)
  #undef       WDG_76_ACW_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_32)
  #undef       WDG_76_ACW_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_32)
  #undef       WDG_76_ACW_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (WDG_76_ACW_START_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 WDGM                                                       */
/* -------------------------------------------------------------------------- */

#elif defined (WDGM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (WDGM_START_SEC_CODE)
  #undef       WDGM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGM_STOP_SEC_CODE)
  #undef       WDGM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (WDGM_START_SEC_PUBLIC_CODE)
  #undef       WDGM_START_SEC_PUBLIC_CODE

//  #pragma ghs section text=".text.DEFAULT_PUBLIC_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (WDGM_STOP_SEC_PUBLIC_CODE)
  #undef       WDGM_STOP_SEC_PUBLIC_CODE
//  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_8)
  #undef       WDGM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_8)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_16)
  #undef       WDGM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_16)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_8)
  #undef       WDGM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_8)
  #undef       WDGM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (WDGM_START_SEC_CONST_16)
  #undef       WDGM_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (WDGM_STOP_SEC_CONST_16)
  #undef       WDGM_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (WDGM_START_SEC_VAR_CLEARED_32)
  #undef       WDGM_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_32)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*			  Xcp												                                          */
/* -------------------------------------------------------------------------- */
#elif defined (XCP_START_SEC_VAR_CLEARED_8)
  #undef       XCP_START_SEC_VAR_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_16)
  #undef       XCP_START_SEC_VAR_CLEARED_16
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_16)
  #undef       XCP_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (XCP_START_SEC_CONST_8)
  #undef       XCP_START_SEC_CONST_8
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_CONST_8)
  #undef       XCP_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_32)
  #undef       XCP_START_SEC_VAR_CLEARED_32
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_32)
  #undef       XCP_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_START_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_8)
  #undef       XCP_START_SEC_VAR_NO_INIT_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_8)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_32)
  #undef       XCP_START_SEC_VAR_NO_INIT_32
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_32)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (XCP_START_SEC_CONST_UNSPECIFIED)
  #undef       XCP_START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       XCP_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (XCP_START_SEC_CODE)
  #undef       XCP_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (XCP_STOP_SEC_CODE)
  #undef       XCP_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
  #pragma alignvar (4)
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_ROM
  #pragma alignvar (4)
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CALIBRATION_ROM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_ROM
//  #pragma ghs section

#elif defined (XCP_START_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_RAM
  #pragma alignvar (4)
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CALIBRATION_RAM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_RAM
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 CoSvAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (COSVAB_START_SEC_CODE)
  #undef       COSVAB_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COSVAB_STOP_SEC_CODE)
  #undef       COSVAB_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (COSVAB_START_SEC_VAR_INIT_8)
  #undef       COSVAB_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (COSVAB_STOP_SEC_VAR_INIT_8)
  #undef       COSVAB_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (COSVAB_START_SEC_VAR_CLEARED_32)
  #undef       COSVAB_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (COSVAB_STOP_SEC_VAR_CLEARED_32)
  #undef       COSVAB_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (COSVAB_START_SEC_CONST_32)
  #undef       COSVAB_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COSVAB_STOP_SEC_CONST_32)
  #undef       COSVAB_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (COSVAB_START_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (COSVAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 IoHwAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (IOHWAB_START_SEC_CODE)
  #undef       IOHWAB_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IOHWAB_STOP_SEC_CODE)
  #undef       IOHWAB_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_8)
  #undef       IOHWAB_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_8)
  #undef       IOHWAB_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_16)
  #undef       IOHWAB_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_16)
  #undef       IOHWAB_STOP_SEC_CONST_16
// #pragma ghs section

#elif defined (IOHWAB_START_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IOHWAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_CONST_UNSPECIFIED
// #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939TP                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939TP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_8)
  #undef       J1939TP_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_8)
  #undef       J1939TP_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_16)
  #undef       J1939TP_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_16)
  #undef       J1939TP_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (J1939TP_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939TP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

#elif defined (J1939TP_START_SEC_CODE)
  #undef       J1939TP_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939TP_STOP_SEC_CODE)
  #undef       J1939TP_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Rm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939RM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN
 #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_8)
  #undef       J1939RM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_CLEARED_16)
  #undef       J1939RM_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_16)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_8)
  #undef       J1939RM_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_32)
  #undef       J1939RM_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_32)
  #undef       J1939RM_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_CONST_8)
  #undef       J1939RM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (J1939RM_STOP_SEC_CONST_8)
  #undef       J1939RM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (J1939RM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_CODE)
  #undef       J1939RM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939RM_STOP_SEC_CODE)
  #undef       J1939RM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Nm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_CLEARED_8)
  #undef       J1939NM_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_CONST_8)
  #undef       J1939NM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939NM_STOP_SEC_CONST_8)
  #undef       J1939NM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939NM_START_SEC_CODE)
  #undef       J1939NM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939NM_STOP_SEC_CODE)
  #undef       J1939NM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                               J1939Dcm                                     */
/* -------------------------------------------------------------------------- */
#elif defined (J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST_INIT"
#elif defined (J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_8)
  #undef       J1939DCM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_8)
  #undef       J1939DCM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_32)
  #undef       J1939DCM_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_32)
  #undef       J1939DCM_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (J1939DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (J1939DCM_START_SEC_CODE)
  #undef       J1939DCM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (J1939DCM_STOP_SEC_CODE)
  #undef       J1939DCM_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             OS Profiler                                    */
/* -------------------------------------------------------------------------- */
#elif defined (OPF_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_NO_INIT_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_8)
  #undef       OPF_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_8)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_8

//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_16)
  #undef       OPF_START_SEC_VAR_NO_INIT_16
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_16)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_32)
  #undef       OPF_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_32)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_8)
  #undef       OPF_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_SEC_VAR_CLEARED_8
 #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_16)
  #undef       OPF_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_32)
  #undef       OPF_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_8)
  #undef       OPF_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_8)
  #undef       OPF_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_16)
  #undef       OPF_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_16)
  #undef       OPF_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_32)
  #undef       OPF_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_32)
  #undef       OPF_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (OPF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_BOOLEAN)
  #undef       OPF_START_SEC_CONST_BOOLEAN

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_BOOLEAN)
  #undef       OPF_STOP_SEC_CONST_BOOLEAN
//  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_8)
  #undef       OPF_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_8)
  #undef       OPF_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_16)
  #undef       OPF_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (OPF_STOP_SEC_CONST_16)
  #undef       OPF_STOP_SEC_CONST_16

//  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_32)
  #undef       OPF_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"

#elif defined (OPF_STOP_SEC_CONST_32)
  #undef       OPF_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (OPF_START_SEC_CONST_UNSPECIFIED)
  #undef       OPF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OPF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OPF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (OPF_START_SEC_CODE)
  #undef       OPF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OPF_STOP_SEC_CODE)
  #undef       OPF_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                             OS Profiler CDD                                */
/* -------------------------------------------------------------------------- */

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_32

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN

//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_8

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_8
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_16

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_16
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_32

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_32
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_CONST_BOOLEAN

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_8)
  #undef       OSPROFILERCDD_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_8)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_16)
  #undef       OSPROFILERCDD_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_16)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_32)
  #undef       OSPROFILERCDD_START_SEC_CONST_32

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_32)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_32
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (OSPROFILERCDD_START_SEC_CODE)
  #undef       OSPROFILERCDD_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OSPROFILERCDD_STOP_SEC_CODE)
  #undef       OSPROFILERCDD_STOP_SEC_CODE
//  #pragma ghs section


/* -------------------------------------------------------------------------- */
/*                                 RamTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (RAMTST_START_SEC_CODE)
  #undef       RAMTST_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (RAMTST_STOP_SEC_CODE)
  #undef       RAMTST_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       RAMTST_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (RAMTST_START_SEC_CONST_UNSPECIFIED)
  #undef       RAMTST_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (RAMTST_STOP_SEC_CONST_UNSPECIFIED)
  #undef       RAMTST_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (RAMTST_START_SEC_VAR_CLEARED_8)
  #undef      RAMTST_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_8)
  #undef      RAMTST_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHIF_START_SEC_CODE)
  #undef       ETHIF_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHIF_STOP_SEC_CODE)
  #undef       ETHIF_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHIF_START_SEC_VAR_CLEARED_8)
  #undef       ETHIF_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_8)
  #undef       ETHIF_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHIF_START_SEC_CONST_8)
  #undef       ETHIF_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHIF_STOP_SEC_CONST_8)
  #undef       ETHIF_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (ETHIF_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHIF_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHIF_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                 ETHSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSM_START_SEC_CODE)
  #undef       ETHSM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSM_STOP_SEC_CODE)
  #undef       ETHSM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHSM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHSM_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHSM_START_SEC_CONST_8)
  #undef       ETHSM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHSM_STOP_SEC_CONST_8)
  #undef       ETHSM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHSM_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHSM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHTRCV                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHTRCV_START_SEC_CODE)
  #undef      ETHTRCV_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHTRCV_STOP_SEC_CODE)
  #undef      ETHTRCV_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_CODE)
  #undef      ETHTRCV_BCM89811_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CODE)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 ETHSWT                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSWT_START_SEC_CODE)
  #undef      ETHSWT_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_STOP_SEC_CODE)
  #undef      ETHSWT_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_CODE)
  #undef      ETHSWT_BCM89531_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CODE)
  #undef      ETHSWT_BCM89531_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                 SOAD                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (SOAD_START_SEC_CODE)
  #undef       SOAD_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (SOAD_STOP_SEC_CODE)
  #undef       SOAD_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (SOAD_START_SEC_VAR_CLEARED_8)
  #undef       SOAD_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_8)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (SOAD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       SOAD_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (SOAD_START_SEC_VAR_CLEARED_16)
  #undef       SOAD_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_16)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (SOAD_START_SEC_CONST_UNSPECIFIED)
  #undef       SOAD_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (SOAD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       SOAD_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             DOIP                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (DOIP_START_SEC_CODE)
  #undef       DOIP_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DOIP_STOP_SEC_CODE)
  #undef       DOIP_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (DOIP_START_SEC_CONST_UNSPECIFIED)
  #undef       DOIP_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (DOIP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_NO_INIT_8)
  #undef       DOIP_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_8)
  #undef       DOIP_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DOIP_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
 #pragma ghs section

#elif defined (DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             UDPNM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (UDPNM_START_SEC_CODE)
  #undef       UDPNM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (UDPNM_STOP_SEC_CODE)
  #undef       UDPNM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       UDPNM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONFIG"
#elif defined (UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_8)
  #undef       UDPNM_START_SEC_VAR_NO_INIT_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       UDPNM_STOP_SEC_VAR_NO_INIT_8
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_NO_INIT"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_CONST_8)
  #undef       UDPNM_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (UDPNM_STOP_SEC_CONST_8)
  #undef       UDPNM_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_CONST_UNSPECIFIED)
  #undef       UDPNM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (UDPNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*             TCPIP                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (TCPIP_START_SEC_CODE)
  #undef       TCPIP_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (TCPIP_STOP_SEC_CODE)
  #undef       TCPIP_STOP_SEC_CODE
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 CtrlRam                                    */
/* -------------------------------------------------------------------------- */
#elif defined (CTRLRAM_START_SEC_CODE)
  #undef       CTRLRAM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CTRLRAM_STOP_SEC_CODE)
  #undef       CTRLRAM_STOP_SEC_CODE
// #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CTRLRAM_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CTRLRAM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CTRLRAM_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (CTRLRAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CTRLRAM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_8)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_8

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_8"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_8)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_8
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_16)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_16

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_16"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_16)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_16
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_32)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_32

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_32"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_32)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_32
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_UNSPECIFIED

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
// #pragma ghs section

/* Controlled RAM Section : This is considered by NO INIT or POWER_ON_CLEARED */

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_BEGIN)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_BEGIN

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_BEGIN"
 #elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_BEGIN)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_BEGIN
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_NOINIT_END)
  #undef       CTRLRAM_START_SEC_VAR_NOINIT_END

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_NO_INIT_END"
#elif defined (CTRLRAM_STOP_SEC_VAR_NOINIT_END)
  #undef       CTRLRAM_STOP_SEC_VAR_NOINIT_END
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_8

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_8
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_16

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_16
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_32

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_32"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_32
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".CTRLRAM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
#elif defined (CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (CTRLRAM_START_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.CTRLRAM_ROM_CONST"
#elif defined (CTRLRAM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 Ocu                                        */
/* -------------------------------------------------------------------------- */
#elif defined (OCU_START_SEC_CODE)
  #undef       OCU_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
#elif defined (OCU_STOP_SEC_CODE)
  #undef       OCU_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (OCU_START_SEC_CODE_FAST)
  #undef       OCU_START_SEC_CODE_FAST

//  #pragma ghs section text=".text.DEFAULT_CODE"
#elif defined (OCU_STOP_SEC_CODE_FAST)
  #undef       OCU_STOP_SEC_CODE_FAST
//  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_8)
  #undef       OCU_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_8)
  #undef       OCU_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_16)
  #undef       OCU_START_SEC_VAR_CLEARED_16

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_16)
  #undef       OCU_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OCU_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (OCU_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OCU_START_SEC_VAR_INIT_UNSPECIFIED

//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (OCU_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OCU_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_8)
  #undef       OCU_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_8)
  #undef       OCU_STOP_SEC_CONST_8
//  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_16)
  #undef       OCU_START_SEC_CONST_16

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_16)
  #undef       OCU_STOP_SEC_CONST_16
//  #pragma ghs section

#elif defined (OCU_START_SEC_CONST_UNSPECIFIED)
  #undef       OCU_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (OCU_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OCU_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
/* -------------------------------------------------------------------------- */
/*                                 Pm                                         */
/* -------------------------------------------------------------------------- */
#elif defined (PM_START_SEC_CODE)
  #undef       PM_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (PM_STOP_SEC_CODE)
  #undef       PM_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (PM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PM_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (PM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (PM_START_SEC_CONST_UNSPECIFIED)
  #undef       PM_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (PM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 RomTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (ROMTST_START_SEC_CODE)
  #undef       ROMTST_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (ROMTST_STOP_SEC_CODE)
  #undef       ROMTST_STOP_SEC_CODE
//  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ROMTST_START_SEC_VAR_CLEARED_BOOLEAN

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
//  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section

#elif defined (ROMTST_START_SEC_CONST_UNSPECIFIED)
  #undef       ROMTST_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (ROMTST_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ROMTST_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section

#elif defined (ROMTST_START_SEC_VAR_CLEARED_8)
  #undef      ROMTST_START_SEC_VAR_CLEARED_8

//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_8)
   #undef      ROMTST_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section

/* -------------------------------------------------------------------------- */
/*                                 UART                                       */
/* -------------------------------------------------------------------------- */
#elif defined (UART_START_SEC_CODE)
  #undef       UART_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (UART_STOP_SEC_CODE)
  #undef       UART_STOP_SEC_CODE
//  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                                  EOL                                      */
/* --------------------------------------------------------------------------*/
#elif defined (EOL_START_SEC_CODE)
  #undef EOL_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (EOL_STOP_SEC_CODE)
  #undef EOL_STOP_SEC_CODE
//  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                               CDD_ROUTER                                  */
/* --------------------------------------------------------------------------*/
#elif defined (CDD_ROUTER_START_SEC_CONST_8)
  #undef CDD_ROUTER_START_SEC_CONST_8

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CDD_ROUTER_STOP_SEC_CONST_8)
  #undef CDD_ROUTER_STOP_SEC_CONST_8
//  #pragma ghs section
#elif defined (CDD_ROUTER_START_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_START_SEC_CONST_UNSPECIFIED

//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
#elif defined (CDD_ROUTER_START_SEC_CODE)
  #undef CDD_ROUTER_START_SEC_CODE

//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (CDD_ROUTER_STOP_SEC_CODE)
  #undef CDD_ROUTER_STOP_SEC_CODE
//  #pragma ghs section

/* --------------------------------------------------------------------------*/
/*                               IDSM                                        */
/* --------------------------------------------------------------------------*/
#elif defined (IDSM_START_SEC_CONST_8)
  #undef IDSM_START_SEC_CONST_8
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_8)
  #undef IDSM_STOP_SEC_CONST_8
//  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_16)
  #undef       IDSM_START_SEC_CONST_16
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_16)
  #undef       IDSM_STOP_SEC_CONST_16
//  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_32)
  #undef       IDSM_START_SEC_CONST_32
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_32)
  #undef       IDSM_STOP_SEC_CONST_32
//  #pragma ghs section
#elif defined (IDSM_START_SEC_CONST_UNSPECIFIED)
  #undef IDSM_START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
#elif defined (IDSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef IDSM_STOP_SEC_CONST_UNSPECIFIED
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_8)
  #undef       IDSM_START_SEC_VAR_CLEARED_8
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_8)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_8
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_16)
  #undef       IDSM_START_SEC_VAR_CLEARED_16
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_16)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_16
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_32)
  #undef       IDSM_START_SEC_VAR_CLEARED_32
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_32)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_32
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_8)
  #undef       IDSM_START_SEC_VAR_INIT_8
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_8)
  #undef       IDSM_STOP_SEC_VAR_INIT_8
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_16)
  #undef       IDSM_START_SEC_VAR_INIT_16
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_16)
  #undef       IDSM_STOP_SEC_VAR_INIT_16
//  #pragma ghs section
#elif defined (IDSM_START_SEC_VAR_INIT_32)
  #undef       IDSM_START_SEC_VAR_INIT_32
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_32)
  #undef       IDSM_STOP_SEC_VAR_INIT_32
//  #pragma ghs section  
#elif defined (IDSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"
#elif defined (IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED
//  #pragma ghs section
#elif defined (IDSM_START_SEC_CODE)
  #undef IDSM_START_SEC_CODE
//  #pragma ghs section text=".text.DEFAULT_CODE"
//  #pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST"
//  #pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED"
//  #pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT"  
#elif defined (IDSM_STOP_SEC_CODE)
  #undef IDSM_STOP_SEC_CODE
//  #pragma ghs section
/******************************END*********************************************/

#else
  #define SECTION_NOT_FOUND

  #if defined (SECTION_NOT_FOUND)
   #undef SECTION_NOT_FOUND
    #include "Rte_MemMap.h"
  #endif

 #if defined (SECTION_NOT_FOUND)
    #undef SECTION_NOT_FOUND
    #include "Mcal_MemMap.h"
  #endif

  #if defined (SECTION_NOT_FOUND)
    #error "MemMap.h: No valid section define found"
  #endif
#endif  /* START_WITH_IF */




/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/* polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
