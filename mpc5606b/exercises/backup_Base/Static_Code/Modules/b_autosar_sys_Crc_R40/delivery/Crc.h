/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Provision of API Prototype Declarations                       **
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
#ifndef CRC_H
#define CRC_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Crc_Cfg.h"                 /* Crc Configuration Header File */
#include "Crc_Types.h"               /* Crc Type Definition Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#if((CRC_8_MODE == CRC_8_RUNTIME) || (CRC_8_MODE == CRC_8_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((CRC_8H2F_MODE == CRC_8H2F_RUNTIME) || (CRC_8H2F_MODE == CRC_8H2F_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((CRC_16_MODE == CRC_16_RUNTIME) || (CRC_16_MODE == CRC_16_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((CRC_32_MODE == CRC_32_RUNTIME) || (CRC_32_MODE == CRC_32_TABLE))
#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CRC_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CRC_CODE) Crc_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA)Versioninfo);
#define CRC_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* CRC_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
