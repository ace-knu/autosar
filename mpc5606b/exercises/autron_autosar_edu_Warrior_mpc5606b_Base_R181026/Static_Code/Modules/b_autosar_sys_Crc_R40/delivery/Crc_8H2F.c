/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc_8H2F.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of 8-bit CRC functions with polynomial 0x2F    **
**              for Crc Library Module                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Crc.h"                     /* Crc Header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CRC_8H2F_C_AR_RELEASE_MAJOR_VERSION      4
#define CRC_8H2F_C_AR_RELEASE_MINOR_VERSION      0
#define CRC_8H2F_C_AR_RELEASE_REVISION_VERSION   3

/* Software Version Information */
#define CRC_8H2F_C_SW_MAJOR_VERSION      1
#define CRC_8H2F_C_SW_MINOR_VERSION      0
#define CRC_8H2F_C_SW_PATCH_VERSION      0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(CRC_AR_RELEASE_MAJOR_VERSION != CRC_8H2F_C_AR_RELEASE_MAJOR_VERSION)
   #error "Crc_8H2F.c : Mismatch in Specification Major Version"
#endif
#if(CRC_AR_RELEASE_MINOR_VERSION != CRC_8H2F_C_AR_RELEASE_MINOR_VERSION)
   #error "Crc_8H2F.c : Mismatch in Specification Minor Version"
#endif
#if(CRC_AR_RELEASE_REVISION_VERSION != CRC_8H2F_C_AR_RELEASE_REVISION_VERSION)
   #error "Crc_8H2F.c  : Mismatch in Specification Revision Version"
#endif
#if(CRC_SW_MAJOR_VERSION != CRC_8H2F_C_SW_MAJOR_VERSION)
  #error "Crc_8H2F.c  : Mismatch in Major version"
#endif
#if(CRC_SW_MINOR_VERSION != CRC_8H2F_C_SW_MINOR_VERSION)
  #error "Crc_8H2F.c  : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if(CRC_8H2F_MODE == CRC_8H2F_TABLE)
#define CRC_START_SEC_CONST_8
#include "MemMap.h"
/* Global look up table for 8 bit 0x2F polynomial table based CRC calculation */
/* Explicit typecasting not added as it is not required */

CONST(uint8, CRC_CONST) Crc_GaaTable8H2F[CRC_COUNT256] =
{
  0x00, 0x2F, 0x5E, 0x71, 0xBC, 0x93, 0xE2, 0xCD, 0x57, 0x78, 0x9, 0x26, 0xEB,
  0xC4, 0xB5, 0x9A, 0xAE, 0x81, 0xF0, 0xDF, 0x12, 0x3D, 0x4C, 0x63, 0xF9, 0xD6,
  0xA7, 0x88, 0x45, 0x6A, 0x1B, 0x34, 0x73, 0x5C, 0x2D, 0x2, 0xCF, 0xE0, 0x91,
  0xBE, 0x24, 0xB, 0x7A, 0x55, 0x98, 0xB7, 0xC6, 0xE9, 0xDD, 0xF2, 0x83, 0xAC,
  0x61, 0x4E, 0x3F, 0x10, 0x8A, 0xA5, 0xD4, 0xFB, 0x36, 0x19, 0x68, 0x47, 0xE6,
  0xC9, 0xB8, 0x97, 0x5A, 0x75, 0x4, 0x2B, 0xB1, 0x9E, 0xEF, 0xC0, 0xD, 0x22,
  0x53, 0x7C, 0x48, 0x67, 0x16, 0x39, 0xF4, 0xDB, 0xAA, 0x85, 0x1F, 0x30, 0x41,
  0x6E, 0xA3, 0x8C, 0xFD, 0xD2, 0x95, 0xBA, 0xCB, 0xE4, 0x29, 0x6, 0x77, 0x58,
  0xC2, 0xED, 0x9C, 0xB3, 0x7E, 0x51, 0x20, 0xF, 0x3B, 0x14, 0x65, 0x4A, 0x87,
  0xA8, 0xD9, 0xF6, 0x6C, 0x43, 0x32, 0x1D, 0xD0, 0xFF, 0x8E, 0xA1, 0xE3, 0xCC,
  0xBD, 0x92, 0x5F, 0x70, 0x1, 0x2E, 0xB4, 0x9B, 0xEA, 0xC5, 0x8, 0x27, 0x56,
  0x79, 0x4D, 0x62, 0x13, 0x3C, 0xF1, 0xDE, 0xAF, 0x80, 0x1A, 0x35, 0x44, 0x6B,
  0xA6, 0x89, 0xF8, 0xD7, 0x90, 0xBF, 0xCE, 0xE1, 0x2C, 0x3, 0x72, 0x5D, 0xC7,
  0xE8, 0x99, 0xB6, 0x7B, 0x54, 0x25, 0xA, 0x3E, 0x11, 0x60, 0x4F, 0x82, 0xAD,
  0xDC, 0xF3, 0x69, 0x46, 0x37, 0x18, 0xD5, 0xFA, 0x8B, 0xA4, 0x5, 0x2A, 0x5B,
  0x74, 0xB9, 0x96, 0xE7, 0xC8, 0x52, 0x7D, 0xC, 0x23, 0xEE, 0xC1, 0xB0, 0x9F,
  0xAB, 0x84, 0xF5, 0xDA, 0x17, 0x38, 0x49, 0x66, 0xFC, 0xD3, 0xA2, 0x8D, 0x40,
  0x6F, 0x1E, 0x31, 0x76, 0x59, 0x28, 0x7, 0xCA, 0xE5, 0x94, 0xBB, 0x21, 0xE,
  0x7F, 0x50, 0x9D, 0xB2, 0xC3, 0xEC, 0xD8, 0xF7, 0x86, 0xA9, 0x64, 0x4B, 0x3A,
  0x15, 0x8F, 0xA0, 0xD1, 0xFE, 0x33, 0x1C, 0x6D, 0x42
};
#define CRC_STOP_SEC_CONST_8
#include "MemMap.h"

#endif /* End if(CRC_8H2F_MODE == CRC_8H2F_TABLE) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Crc_CalculateCRC8H2F                                **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This function returns the 8 bit checksum calculated **
**                        using polynomial 0x2F by runtime and table method.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue8H2F,        **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 8 bit result of CRC for polynomial calculation      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Crc_GaaTable8H2F[]         **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if((CRC_8H2F_MODE == CRC_8H2F_RUNTIME) || (CRC_8H2F_MODE == CRC_8H2F_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall)
{
  /* Pointer to data byte */
  P2CONST(uint8, CRC_CONST, CRC_CONST) LpDataPtr;
  /* Variable to hold CRC Length */
  uint32 LulCrcLen;
  /* Variable to hold data byte */
  uint8 LucNxtDataWord;
  /* Start value or Initial value of CRC result as passed by NVRAM Manager */
  uint8 LucCrcRegister;
  #if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #endif

  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == CRC_TRUE)
  {
    /* Initial value for 8bit 0x2F */
    LucCrcRegister = CRC_INITIAL_VALUE8H2F;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LucCrcRegister = (Crc_StartValue8H2F ^ CRC_XOR_OUT8H2F);
  }
  /* Local copy of pointer to start of data */
  LpDataPtr = Crc_DataPtr;
  /* Loop for no. of data bytes */
  while(LulCrcLen > (uint32)CRC_ZERO)
  {
    /* Copy the data byte into local variable */
    LucNxtDataWord = *LpDataPtr;
    /* Perform XOR of data byte with CRC result */
    LucCrcRegister = (LucCrcRegister ^ LucNxtDataWord);
    #if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
    /* Reinitialize Loop Index */
    LucLoopIndex = CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MSB8 == (LucCrcRegister & CRC_MSB8))
      {
        LucCrcRegister = ((LucCrcRegister << (uint8)CRC_ONE) ^ CRC_POLY8H2F);
      }
      else
      {
        /* If MSB is unset */
        LucCrcRegister = (LucCrcRegister << (uint8)CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /* Fetch value from the Table */
    LucCrcRegister = Crc_GaaTable8H2F[LucCrcRegister];
    #endif /* End if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME) */
    /* Decrement the count of the no. of bytes */
    LulCrcLen--;
    /*
     * MISRA Rule         : 17.4
     * Message            : Increment or decrement operation performed on
     *                      pointer.
     * Reason             : Increment operator is used to achieve better
     *                      throughput.
     * Verification       : However, part of the code is verified manually and
     *                      it is not having any impact.
     */
    /* Point to next data byte */
    LpDataPtr++;
  } /* End while(LulCrcLen > (uint32)CRC_ZERO) */

  /* XOR final value with 0xFF */
  LucCrcRegister = (LucCrcRegister ^ CRC_XOR_OUT8H2F);
  /* Return the CRC result */
  return (LucCrcRegister);
}
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End if((CRC_8H2F_MODE == CRC_8H2F_RUNTIME) || (...)) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
