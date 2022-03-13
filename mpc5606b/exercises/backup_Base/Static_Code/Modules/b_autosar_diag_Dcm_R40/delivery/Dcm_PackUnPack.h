/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_PackUnPack.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_PackUnPack                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_PACKUNPACK_H
#define DCM_PACKUNPACK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, DCM_CODE) Dcm_UnPackOneByte(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_UnPackBytes
(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_UnPackFiveBytes
(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);
extern FUNC(void, DCM_CODE) Dcm_UnPackByteOrdering
(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_UnPackFiveByteOrdering
(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_UnPackNBytes
(
   Dcm_PackUnpackSignalData LddUnPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
   P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackOneByte(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackBytes(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_CONST)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackFiveBytes(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_CONST)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackByteOrdering(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_CONST)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackFiveByteOrdering(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_CONST)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_PackNBytes(
   Dcm_PackUnpackSignalData LddPackSignal,
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
   P2CONST(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_UnPack16(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr,
  Dcm_MIdWord_Access LunSignalValue);

extern FUNC(void, DCM_CODE)Dcm_UnPack24(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr,
  Dcm_MIdWord_Access LunSignalValue);

extern FUNC(void, DCM_CODE) Dcm_UnPack32(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr,
  Dcm_MIdWord_Access LunSignalValue);

extern FUNC(void, DCM_CODE) Dcm_Pack16(
   Dcm_MIdWord_Access *LunSignalValue,
   P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_Pack24(
Dcm_MIdWord_Access *LunSignalValue,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

extern FUNC(void, DCM_CODE) Dcm_Pack32(
   Dcm_MIdWord_Access *LunSignalValue,
   P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPMEMORYSERVICES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
