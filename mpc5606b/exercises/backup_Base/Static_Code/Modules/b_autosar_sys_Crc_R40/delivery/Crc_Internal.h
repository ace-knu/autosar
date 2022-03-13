/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc_Internal.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Provision of Internal function prototypes                     **
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
#ifndef CRC_INTERNAL_H
#define CRC_INTERNAL_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Crc.h"                 /* Crc Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define CRC_INTERNAL_AR_MAJOR_VERSION      CRC_AR_RELEASE_MAJOR_VERSION
#define CRC_INTERNAL_AR_MINOR_VERSION       CRC_AR_RELEASE_MINOR_VERSION
#define CRC_INTERNAL_AR_RELEASE_REVISION_VERSION \
  CRC_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define CRC_INTERNAL_SW_MAJOR_VERSION      CRC_SW_MAJOR_VERSION
#define CRC_INTERNAL_SW_MINOR_VERSION      CRC_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#if(CRC_32_MODE == CRC_32_RUNTIME)
#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint32, CRC_CODE) Crc_Reflect(uint32 LulData,
  CONST(uint8, CRC_CONST) LucNbits);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif  /* CRC_INTERNAL_H */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
