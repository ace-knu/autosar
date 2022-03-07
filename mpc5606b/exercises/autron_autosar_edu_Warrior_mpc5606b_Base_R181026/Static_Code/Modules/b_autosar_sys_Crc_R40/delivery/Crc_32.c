/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc_32.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of 32-bit CRC functions for Crc Library Module **
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
#include "Crc_Internal.h"            /* Crc Internal Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CRC_32_C_AR_RELEASE_MAJOR_VERSION      4
#define CRC_32_C_AR_RELEASE_MINOR_VERSION      0
#define CRC_32_C_AR_RELEASE_REVISION_VERSION   3

/* Software Version Information */
#define CRC_32_C_SW_MAJOR_VERSION      1
#define CRC_32_C_SW_MINOR_VERSION      0
#define CRC_32_C_SW_PATCH_VERSION      0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(CRC_AR_RELEASE_MAJOR_VERSION != CRC_32_C_AR_RELEASE_MAJOR_VERSION)
  #error "Crc_32.c : Mismatch in Specification Major Version"
#endif

#if(CRC_AR_RELEASE_MINOR_VERSION != CRC_32_C_AR_RELEASE_MINOR_VERSION)
  #error "Crc_32.c : Mismatch in Specification Minor Version"
#endif

#if(CRC_AR_RELEASE_REVISION_VERSION != CRC_32_C_AR_RELEASE_REVISION_VERSION)
  #error "Crc_32.c  : Mismatch in Specification Revision Version"
#endif

#if(CRC_SW_MAJOR_VERSION != CRC_32_C_SW_MAJOR_VERSION)
  #error "Crc_32.c  : Mismatch in Major version"
#endif

#if(CRC_SW_MINOR_VERSION != CRC_32_C_SW_MINOR_VERSION)
  #error "Crc_32.c  : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if(CRC_32_MODE == CRC_32_TABLE)
#define CRC_START_SEC_CONST_32
#include "MemMap.h"
/* Global look up table (reflected) for 32 bit table based CRC calculation */
/* Explicit typecasting done due to MISRA warning */

CONST(uint32, CRC_CONST) Crc_GaaTable32[CRC_COUNT256] =
{
  0x00000000UL,  0x77073096UL,  0xEE0E612CUL,  0x990951BAUL,  0x076DC419UL,
  0x706AF48FUL,  0xE963A535UL,  0x9E6495A3UL,  0x0EDB8832UL,  0x79DCB8A4UL,
  0xE0D5E91EUL,  0x97D2D988UL,  0x09B64C2BUL,  0x7EB17CBDUL,  0xE7B82D07UL,
  0x90BF1D91UL,  0x1DB71064UL,  0x6AB020F2UL,  0xF3B97148UL,  0x84BE41DEUL,
  0x1ADAD47DUL,  0x6DDDE4EBUL,  0xF4D4B551UL,  0x83D385C7UL,  0x136C9856UL,
  0x646BA8C0UL,  0xFD62F97AUL,  0x8A65C9ECUL,  0x14015C4FUL,  0x63066CD9UL,
  0xFA0F3D63UL,  0x8D080DF5UL,  0x3B6E20C8UL,  0x4C69105EUL,  0xD56041E4UL,
  0xA2677172UL,  0x3C03E4D1UL,  0x4B04D447UL,  0xD20D85FDUL,  0xA50AB56BUL,
  0x35B5A8FAUL,  0x42B2986CUL,  0xDBBBC9D6UL,  0xACBCF940UL,  0x32D86CE3UL,
  0x45DF5C75UL,  0xDCD60DCFUL,  0xABD13D59UL,  0x26D930ACUL,  0x51DE003AUL,
  0xC8D75180UL,  0xBFD06116UL,  0x21B4F4B5UL,  0x56B3C423UL,  0xCFBA9599UL,
  0xB8BDA50FUL,  0x2802B89EUL,  0x5F058808UL,  0xC60CD9B2UL,  0xB10BE924UL,
  0x2F6F7C87UL,  0x58684C11UL,  0xC1611DABUL,  0xB6662D3DUL,  0x76DC4190UL,
  0x01DB7106UL,  0x98D220BCUL,  0xEFD5102AUL,  0x71B18589UL,  0x06B6B51FUL,
  0x9FBFE4A5UL,  0xE8B8D433UL,  0x7807C9A2UL,  0x0F00F934UL,  0x9609A88EUL,
  0xE10E9818UL,  0x7F6A0DBBUL,  0x086D3D2DUL,  0x91646C97UL,  0xE6635C01UL,
  0x6B6B51F4UL,  0x1C6C6162UL,  0x856530D8UL,  0xF262004EUL,  0x6C0695EDUL,
  0x1B01A57BUL,  0x8208F4C1UL,  0xF50FC457UL,  0x65B0D9C6UL,  0x12B7E950UL,
  0x8BBEB8EAUL,  0xFCB9887CUL,  0x62DD1DDFUL,  0x15DA2D49UL,  0x8CD37CF3UL,
  0xFBD44C65UL,  0x4DB26158UL,  0x3AB551CEUL,  0xA3BC0074UL,  0xD4BB30E2UL,
  0x4ADFA541UL,  0x3DD895D7UL,  0xA4D1C46DUL,  0xD3D6F4FBUL,  0x4369E96AUL,
  0x346ED9FCUL,  0xAD678846UL,  0xDA60B8D0UL,  0x44042D73UL,  0x33031DE5UL,
  0xAA0A4C5FUL,  0xDD0D7CC9UL,  0x5005713CUL,  0x270241AAUL,  0xBE0B1010UL,
  0xC90C2086UL,  0x5768B525UL,  0x206F85B3UL,  0xB966D409UL,  0xCE61E49FUL,
  0x5EDEF90EUL,  0x29D9C998UL,  0xB0D09822UL,  0xC7D7A8B4UL,  0x59B33D17UL,
  0x2EB40D81UL,  0xB7BD5C3BUL,  0xC0BA6CADUL,  0xEDB88320UL,  0x9ABFB3B6UL,
  0x03B6E20CUL,  0x74B1D29AUL,  0xEAD54739UL,  0x9DD277AFUL,  0x04DB2615UL,
  0x73DC1683UL,  0xE3630B12UL,  0x94643B84UL,  0x0D6D6A3EUL,  0x7A6A5AA8UL,
  0xE40ECF0BUL,  0x9309FF9DUL,  0x0A00AE27UL,  0x7D079EB1UL,  0xF00F9344UL,
  0x8708A3D2UL,  0x1E01F268UL,  0x6906C2FEUL,  0xF762575DUL,  0x806567CBUL,
  0x196C3671UL,  0x6E6B06E7UL,  0xFED41B76UL,  0x89D32BE0UL,  0x10DA7A5AUL,
  0x67DD4ACCUL,  0xF9B9DF6FUL,  0x8EBEEFF9UL,  0x17B7BE43UL,  0x60B08ED5UL,
  0xD6D6A3E8UL,  0xA1D1937EUL,  0x38D8C2C4UL,  0x4FDFF252UL,  0xD1BB67F1UL,
  0xA6BC5767UL,  0x3FB506DDUL,  0x48B2364BUL,  0xD80D2BDAUL,  0xAF0A1B4CUL,
  0x36034AF6UL,  0x41047A60UL,  0xDF60EFC3UL,  0xA867DF55UL,  0x316E8EEFUL,
  0x4669BE79UL,  0xCB61B38CUL,  0xBC66831AUL,  0x256FD2A0UL,  0x5268E236UL,
  0xCC0C7795UL,  0xBB0B4703UL,  0x220216B9UL,  0x5505262FUL,  0xC5BA3BBEUL,
  0xB2BD0B28UL,  0x2BB45A92UL,  0x5CB36A04UL,  0xC2D7FFA7UL,  0xB5D0CF31UL,
  0x2CD99E8BUL,  0x5BDEAE1DUL,  0x9B64C2B0UL,  0xEC63F226UL,  0x756AA39CUL,
  0x026D930AUL,  0x9C0906A9UL,  0xEB0E363FUL,  0x72076785UL,  0x05005713UL,
  0x95BF4A82UL,  0xE2B87A14UL,  0x7BB12BAEUL,  0x0CB61B38UL,  0x92D28E9BUL,
  0xE5D5BE0DUL,  0x7CDCEFB7UL,  0x0BDBDF21UL,  0x86D3D2D4UL,  0xF1D4E242UL,
  0x68DDB3F8UL,  0x1FDA836EUL,  0x81BE16CDUL,  0xF6B9265BUL,  0x6FB077E1UL,
  0x18B74777UL,  0x88085AE6UL,  0xFF0F6A70UL,  0x66063BCAUL,  0x11010B5CUL,
  0x8F659EFFUL,  0xF862AE69UL,  0x616BFFD3UL,  0x166CCF45UL,  0xA00AE278UL,
  0xD70DD2EEUL,  0x4E048354UL,  0x3903B3C2UL,  0xA7672661UL,  0xD06016F7UL,
  0x4969474DUL,  0x3E6E77DBUL,  0xAED16A4AUL,  0xD9D65ADCUL,  0x40DF0B66UL,
  0x37D83BF0UL,  0xA9BCAE53UL,  0xDEBB9EC5UL,  0x47B2CF7FUL,  0x30B5FFE9UL,
  0xBDBDF21CUL,  0xCABAC28AUL,  0x53B39330UL,  0x24B4A3A6UL,  0xBAD03605UL,
  0xCDD70693UL,  0x54DE5729UL,  0x23D967BFUL,  0xB3667A2EUL,  0xC4614AB8UL,
  0x5D681B02UL,  0x2A6F2B94UL,  0xB40BBE37UL,  0xC30C8EA1UL,  0x5A05DF1BUL,
  0x2D02EF8DUL
};
#define CRC_STOP_SEC_CONST_32
#include "MemMap.h"

#endif /* End if(CRC_32_MODE == CRC_32_TABLE) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Crc_CalculateCRC32                                  **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function returns the 32 bit checksum calculated**
**                        by runtime and table based method.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue32,          **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 32 bit result of CRC calculation                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Crc_GaaTable32[]           **
**                        Function(s) invoked    : Crc_Reflect                **
*******************************************************************************/
#if((CRC_32_MODE == CRC_32_RUNTIME) || (CRC_32_MODE == CRC_32_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
  /* Pointer to data byte */
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
  /* Create a union object of type Crc_Dword32 */
  Crc_Dword32 LunCrc32;

  /* Variable to hold CRC Length */
  uint32 LulCrcLen;

  #if(CRC_32_MODE == CRC_32_RUNTIME)
  /*
   * MISRA Rule         : 18.4
   * Message            : An object of union type has been defined.
   * Reason             : Even if it returns Error code,
   *                      Unions have been used to access the sub-parts
   *                      of larger data types to reduce the memory.
   * Verification       : However, part of the code is verified manually
   *                      and it is not having any impact.
   */
  /* Create a union object of type Crc_Dword32 */
  Crc_Dword32 LunNxtData;
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #else
  /* Local variable to hold CRC byte */
  uint8 LucTempCrcByte;
  #endif /* End if(CRC_32_MODE == CRC_32_RUNTIME) */

  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == CRC_TRUE)
  {
    /* Initial value for 32bit */
    LunCrc32.LongReg32 = CRC_INITIAL_VALUE32;
  }
  else
  {
    #if(CRC_32_MODE == CRC_32_RUNTIME)
    /* Initialize CRC result  with previous result's reflected value */
    LunCrc32.LongReg32 = Crc_Reflect((Crc_StartValue32 ^ CRC_XOR_OUT32),
      CRC_THIRTYTWO);
    #else
    /* Initialize CRC result  with previous result */
    LunCrc32.LongReg32 = Crc_StartValue32;
    #endif
  }
  /* Local copy of pointer to start of data */
  LpDataPtr = Crc_DataPtr;
  /* Loop for no. of data bytes */
  while(LulCrcLen > (uint32)CRC_ZERO)
  {
    #if(CRC_32_MODE == CRC_32_RUNTIME)
    /* 32 bit field filled with zero */
    LunNxtData.LongReg32 = (uint32)CRC_ZERO;
    /* Store next data byte into MSB, simulating left shift by 24 bits */
    LunNxtData.Byte.MsByte = *LpDataPtr;
    /* Call to Reflect input data around central bit */
    LunNxtData.Byte.MsByte = (uint8)Crc_Reflect(LunNxtData.Byte.MsByte,
      CRC_EIGHT);
    LunCrc32.LongReg32 = (LunCrc32.LongReg32 ^ LunNxtData.LongReg32);
    /* Loop for Mod-2 division for each bit */
    LucLoopIndex = CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MS_BIT_LWORD == (LunCrc32.LongReg32 & CRC_MS_BIT_LWORD))
      {
        LunCrc32.LongReg32 = ((LunCrc32.LongReg32 << CRC_ONE) ^ CRC_POLY32);
      }
      else
      {
        /* If MSB is unset */
        LunCrc32.LongReg32 = (LunCrc32.LongReg32 << CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /* Move the content of the LsByte to temporary variable */
    LucTempCrcByte = LunCrc32.Byte.LsByte;
    /* Perform right shift by 8 bits using union */
    LunCrc32.Byte.LsByte = LunCrc32.Byte.MidLowByte;
    LunCrc32.Byte.MidLowByte = LunCrc32.Byte.MidHiByte;
    LunCrc32.Byte.MidHiByte = LunCrc32.Byte.MsByte;
    LunCrc32.Byte.MsByte = CRC_ZERO;
    /* Xor CRC value with precomputed table value */
    LunCrc32.LongReg32 = (LunCrc32.LongReg32 ^
      (uint32)Crc_GaaTable32[(LucTempCrcByte ^ *LpDataPtr)]);
    #endif /* End if(CRC_32_MODE == CRC_32_RUNTIME) */
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
  #if(CRC_32_MODE == CRC_32_RUNTIME)
  /* Reflect final checksum and XOR with 0xFFFFFFFFUL */
  LunCrc32.LongReg32 = Crc_Reflect(LunCrc32.LongReg32, CRC_THIRTYTWO);
  #endif
  /* XOR final value with 0xFFFFFFFFUL */
  LunCrc32.LongReg32 = (LunCrc32.LongReg32 ^ CRC_XOR_OUT32);
  /* Return the reflected data */
  return (LunCrc32.LongReg32);
}
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End if((CRC_32_MODE == CRC_32_RUNTIME) || (CRC_32_MODE == ...)) */

/*******************************************************************************
** Function Name        : Crc_Reflect                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the symmetric reflection      **
**                        of input.                                           **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LulData, LucNbits                                   **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LulReflection                                       **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(CRC_32_MODE == CRC_32_RUNTIME)
#define CRC_START_SEC_CODE
#include "MemMap.h"

FUNC(uint32, CRC_CODE) Crc_Reflect
  (uint32 LulData, CONST(uint8, CRC_CONST) LucNbits)
{
  /* Value of reflection */
  uint32 LulReflection;
  /* Value of MS bit */
  uint32 LulBit;
  /* Count of no. of bits */
  uint8 LucBitCount;
  /* Initial value of reflection */
  LulReflection = (uint32)CRC_ZERO;
  /* Start of count */
  LucBitCount = CRC_ZERO;
  /* Check for no. of bits */
  if(LucNbits == CRC_EIGHT)
  {
    /* Set MS bit for one byte data  */
    LulBit = CRC_MSB8;
  }
  else
  {
    /* Set MS bit for Long word data */
    LulBit = CRC_MS_BIT_LWORD;
  }
  while(LucBitCount != LucNbits)
  {
    /* AND data with 0x01L to check if the LSB of data is set */
    if((uint32)CRC_TRUE == (LulData & (uint32)CRC_ONE))
    {
      /* Take mirror image of nth bit at bit position (Nbits-n) */
      LulReflection = LulReflection | LulBit;
    }
    /* Right shift by one bit */
    LulBit = LulBit >> CRC_ONE;
    LulData = LulData >> CRC_ONE;
    /* Increment bit count */
    LucBitCount++;
  }
  /* Return the reflected data */
  return (LulReflection);
}
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End if(CRC_32_MODE == CRC_32_RUNTIME) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
