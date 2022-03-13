/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Provision of Macros, unions for accessing byte fields and     **
**              global array declarations                                     **
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
#ifndef CRC_TYPES_H
#define CRC_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CRC_TYPES_AR_MAJOR_VERSION         CRC_AR_RELEASE_MAJOR_VERSION
#define CRC_TYPES_AR_MINOR_VERSION         CRC_AR_RELEASE_MINOR_VERSION
#define CRC_TYPES_AR_RELEASE_REVISION_VERSION \
  CRC_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define CRC_TYPES_SW_MAJOR_VERSION   CRC_AR_RELEASE_MAJOR_VERSION
#define CRC_TYPES_SW_MINOR_VERSION   CRC_AR_RELEASE_MINOR_VERSION
#define CRC_TYPES_SW_PATCH_VERSION   CRC_SW_PATCH_VERSION

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Macro for 8bit Table Mode of CRC Calculation */
#define CRC_8_TABLE              0x00

/* Macro for 8bit Runtime Mode of CRC Calculation */
#define CRC_8_RUNTIME            0x01

/* Macro for 8bit with polynomial 0x2F Table Mode of CRC Calculation */
#define CRC_8H2F_TABLE           0x00

/* Macro for 8bit with polynomial 0x2F Runtime Mode of CRC Calculation */
#define CRC_8H2F_RUNTIME         0x01

/* Macro for 16bit Table Mode of CRC Calculation */
#define CRC_16_TABLE             0x00

/* Macro for 16bit Runtime Mode of CRC Calculation */
#define CRC_16_RUNTIME           0x01

/* Macro for 32bit Table Mode of CRC Calculation */
#define CRC_32_TABLE             0x00

/* Macro for 32bit Runtime Mode of CRC Calculation */
#define CRC_32_RUNTIME           0x01

/* Macro to be used when none of the modes are configured */
#define CRC_NOT_CFG              0x02

#define CRC_TRUE                 (boolean)1

#define CRC_ONE                  0x01L

#define CRC_EIGHT                0x08

#define CRC_THIRTYTWO            (uint8)32

#define CRC_ZERO                 (uint8)0

/* 8 bit MSB mask */
#define CRC_MSB8                 0x80

/* 16 bit MSB mask */
#define CRC_MSB16                (uint16)0x8000

/* 32 bit MSB mask */
#define CRC_MS_BIT_LWORD         0x80000000UL

/* CRC-SAE-J1850  standard 8 bit generator polynomial */
#define CRC_POLY8                (uint8)0x1D

/* CRC-8 bit 0x2F polynomial */
#define CRC_POLY8H2F             (uint8)0x2F

/* CRC-CCITT standard 16 bit generator polynomial */
#define CRC_POLY16               (uint16)0x1021

/* IEEE-802.3 standard 32 bit generator polynomial */
#define CRC_POLY32               (uint32)0x04C11DB7L

/* Final XOR value for 8 bit checksum */
#define CRC_XOR_OUT8             (uint8)0xFF

/* Final XOR value for 8 bit checksum with 0x2F polynomial*/
#define CRC_XOR_OUT8H2F          (uint8)0xFF

/* Final XOR value for 32 bit checksum */
#define CRC_XOR_OUT32            0xFFFFFFFFUL

/* Array index of Table to perform CRC calculation */
#define CRC_COUNT256             (uint16)256

/* Macro for the Initial value of 8 bit CRC calculation */
#define CRC_INITIAL_VALUE8       (uint8)0xFF

/* Macro for the Initial value of 8 bit 0x2F CRC calculation */
#define CRC_INITIAL_VALUE8H2F    (uint8)0xFF

/* Macro for the Initial value of 16 bit CRC calculation */
#define CRC_INITIAL_VALUE16      (uint16)0xFFFF

/* Macro for the Initial value of 32 bit CRC calculation */
#define CRC_INITIAL_VALUE32      (uint32)0xFFFFFFFFUL

/* Define union for direct manipulation of 16 bit data */
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)

typedef union
{
  struct                                   /* Defining byte fields */
  {
    uint8 LsByte;                          /* Least significant byte */
    uint8 MsByte;                          /* Most significant byte */
  } Byte;

  uint16 WordReg16;                        /* 16 bit CRC field*/

}Crc_Word16;

/* Define union for Big Endian */
#else

typedef union
{
  /* Structure for accessing byte fields */
  struct
  {
    uint8 MsByte;                          /* Most significant byte */
    uint8 LsByte;                          /* Least significant byte */
  } Byte;

  uint16 WordReg16;                        /* 16 bit CRC field */

} Crc_Word16;

#endif /* End if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

/* Union for direct manipulation of 32 bit register */
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)

typedef union                              /* Little Endian Ordering */
{
 struct
 {
   uint8 LsByte;                           /* Least Significant byte (0)*/
   uint8 MidLowByte;                       /* Byte (1)*/
   uint8 MidHiByte;                        /* Byte (2) */
   uint8 MsByte;                           /* Most Significant byte (3) */
 } Byte;

 uint32 LongReg32;                         /* 32 bit field */

} Crc_Dword32;

#else

typedef union                              /* Big Endian Ordering */
{
  struct
  {
    uint8 MsByte;                          /* Most Significant byte (3) */
    uint8 MidHiByte;                       /* Byte (2)*/
    uint8 MidLowByte;                      /* Byte (1)*/
    uint8 LsByte;                          /* Least Significant byte (0) */
  } Byte;

  uint32 LongReg32;                        /* 32 bit field */

} Crc_Dword32;

#endif /* End if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

/* Global Constants used in Table based calculation */
#if(CRC_8_MODE == CRC_8_TABLE)
#define CRC_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, CRC_CONST) Crc_GaaTable8[];
#define CRC_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(CRC_8H2F_MODE == CRC_8H2F_TABLE)
#define CRC_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, CRC_CONST) Crc_GaaTable8H2F[];
#define CRC_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(CRC_16_MODE == CRC_16_TABLE)
#define CRC_START_SEC_CONST_16
#include "MemMap.h"
extern CONST(uint16, CRC_CONST) Crc_GaaTable16[];
#define CRC_STOP_SEC_CONST_16
#include "MemMap.h"
#endif

#if(CRC_32_MODE == CRC_32_TABLE)
#define CRC_START_SEC_CONST_32
#include "MemMap.h"
extern CONST(uint32, CRC_CONST) Crc_GaaTable32[];
#define CRC_STOP_SEC_CONST_32
#include "MemMap.h"
#endif
/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/

#endif /* CRC_TYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
