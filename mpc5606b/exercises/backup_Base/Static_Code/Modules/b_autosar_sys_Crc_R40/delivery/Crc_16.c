/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc_16.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of 16-bit CRC functions for Crc Library Module **
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
#define CRC_16_C_AR_RELEASE_MAJOR_VERSION      4
#define CRC_16_C_AR_RELEASE_MINOR_VERSION      0
#define CRC_16_C_AR_RELEASE_REVISION_VERSION   3

/* Software Version Information */
#define CRC_16_C_SW_MAJOR_VERSION      1
#define CRC_16_C_SW_MINOR_VERSION      0
#define CRC_16_C_SW_PATCH_VERSION      0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(CRC_AR_RELEASE_MAJOR_VERSION != CRC_16_C_AR_RELEASE_MAJOR_VERSION)
  #error "Crc_16.c : Mismatch in Specification Major Version"
#endif
#if(CRC_AR_RELEASE_MINOR_VERSION != CRC_16_C_AR_RELEASE_MINOR_VERSION)
  #error "Crc_16.c : Mismatch in Specification Minor Version"
#endif
#if(CRC_AR_RELEASE_REVISION_VERSION != CRC_16_C_AR_RELEASE_REVISION_VERSION)
  #error "Crc_16.c  : Mismatch in Specification Revision Version"
#endif
#if(CRC_SW_MAJOR_VERSION != CRC_16_C_SW_MAJOR_VERSION)
  #error "Crc_16.c  : Mismatch in Major version"
#endif
#if(CRC_SW_MINOR_VERSION != CRC_16_C_SW_MINOR_VERSION)
  #error "Crc_16.c  : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if(CRC_16_MODE == CRC_16_TABLE)
#define CRC_START_SEC_CONST_16
#include "MemMap.h"
/* Global look up table for 16 bit table based CRC calculation */
/* Explicit typecasting not added as it is not required */

CONST(uint16, CRC_CONST) Crc_GaaTable16[CRC_COUNT256] =
{
  0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
  0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
  0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
  0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
  0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
  0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
  0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
  0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
  0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
  0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
  0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
  0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
  0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
  0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
  0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
  0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
  0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
  0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
  0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
  0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
  0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
  0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
  0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
  0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
  0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
  0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
  0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
  0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
  0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
  0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
  0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
  0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};
#define CRC_STOP_SEC_CONST_16
#include "MemMap.h"

#endif /* End if(CRC_16_MODE == CRC_16_TABLE) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Crc_CalculateCRC16                                  **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This function returns the 16 bit checksum calculated**
**                        by runtime and table based method.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue16,          **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 16 bit result of CRC calculation                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Crc_GaaTable16[]           **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if((CRC_16_MODE == CRC_16_RUNTIME) || (CRC_16_MODE == CRC_16_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
  /* Pointer to hold data byte */
  P2CONST(uint8, CRC_CONST, CRC_CONST) LpDataPtr;
  /*
   * MISRA Rule         : 18.4
   * Message            : An object of union type has been defined.
   * Reason             : Even if it returns Error code,
   *                      Unions have been used to access the sub-parts
   *                      of larger data types to reduce the memory.
   * Verification       : However, part of the code is verified manually
   *                      and it is not having any impact.
   */

  /* Union object of type Crc_Word16 to hold start value */
  Crc_Word16 LunCrc16;

  /* Variable to hold CRC Length */
  uint32 LulCrcLen;

  #if(CRC_16_MODE == CRC_16_RUNTIME)
  /*
   * MISRA Rule         : 18.4
   * Message            : An object of union type has been defined.
   * Reason             : Even if it returns Error code,
   *                      Unions have been used to access the sub-parts
   *                      of larger data types to reduce the memory.
   * Verification       : However, part of the code is verified manually
   *                      and it is not having any impact.
   */

  /* Union object of type Crc_Word16 to hold data byte */
  Crc_Word16 LunNxtData;
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #else
  /* Index of the Table */
  uint8 LucTableIndex;
  #endif /* End if(CRC_16_MODE == CRC_16_RUNTIME) */

  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == CRC_TRUE)
  {
    /* Initial value for 16bit */
    LunCrc16.WordReg16 = CRC_INITIAL_VALUE16;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LunCrc16.WordReg16 = Crc_StartValue16;
  }
  /* Local copy of pointer to start of data */
  LpDataPtr = Crc_DataPtr;
  /* Loop for no. of data bytes */
  while(LulCrcLen > (uint32)CRC_ZERO)
  {
    #if(CRC_16_MODE == CRC_16_RUNTIME)
    /* Copy the data byte into MsByte */
    LunNxtData.Byte.MsByte = *LpDataPtr;
    /* Pad zero into LsByte */
    LunNxtData.Byte.LsByte = CRC_ZERO;
    /* Perform XOR of entire data byte with CRC result */
    LunCrc16.WordReg16 = (LunCrc16.WordReg16 ^ LunNxtData.WordReg16);
    /* Reinitialize Loop Index */
    LucLoopIndex = CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MSB16 == (LunCrc16.WordReg16 & CRC_MSB16))
      {
        LunCrc16.WordReg16 = ((LunCrc16.WordReg16 << (uint16)CRC_ONE) ^
          CRC_POLY16);
      }
      else
      {
        /* If MSB is unset */
        LunCrc16.WordReg16 = (LunCrc16.WordReg16 << (uint16)CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /*
     * Get table index by accessing directly the MSB of the 16 bit register
     * simulating a right shift by 8 bits.
     */
    LucTableIndex = (LunCrc16.Byte.MsByte ^ (*LpDataPtr));

    /* Copy LSB into MSB for simulation of a left shift by 8 bits */
    LunCrc16.Byte.MsByte = LunCrc16.Byte.LsByte;

    /* Clear LSB for completing the left shift by 8 bits */
    LunCrc16.Byte.LsByte = CRC_ZERO;

    /* XOR Crc Register with precomputed table entry using the index */
    LunCrc16.WordReg16 = (LunCrc16.WordReg16 ^
      Crc_GaaTable16[LucTableIndex]);
    #endif /* End if(CRC_16_MODE == CRC_16_RUNTIME) */
    /* Decrement the count of the no. of bytes */
    LulCrcLen--;
    /*
     *  MISRA Rule         : 17.4
     *  Message            : Increment or decrement operation performed on
     *                       pointer.
     *  Reason             : Increment operator is used to achieve better
     *                       throughput.
     *  Verification       : However, part of the code is verified manually and
     *                       it is not having any impact.
     */
    /* Point to next data byte */
    LpDataPtr++;
  } /* End while(LulCrcLen > (uint32)CRC_ZERO) */

  /* Return the CRC result */
  return (LunCrc16.WordReg16);
}
#define CRC_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End if((CRC_16_MODE == CRC_16_RUNTIME) ||(CRC_16_MODE == ...) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
