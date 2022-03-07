/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspOBDInternals.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspOBDInternals                              **
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

#ifndef DCM_DSPOBDINTERNALS_H
#define DCM_DSPOBDINTERNALS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"
#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON) || \
    (DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON) || \
    (DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON) || \
    (DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON))

/*To find whether the PID belongs to configured PIDs or Availability PIDs or
* not
*/
extern FUNC(uint8, DCM_CODE) Dcm_DspGetAvailibiltyIDStatus
  (uint8 LucIDType,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) ReqBuffer, uint8 LucIDCount,
  uint8 LucMix_DemRPort );
/* To get the Configured IDs */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspGetConfigIDS
  (uint8 LucIDValue, uint8 LucIDType,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpSizeOfID );

/* To get the Configured IDs */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspGetConfigIDS1
  (uint8 LucIDValue, uint8 LucIDType,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpSizeOfID );

/* Get the response length of requested PIDs */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspGetSizeOfIDS
  (uint8 LucIDType, uint8 LucIDCount,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) LpRespLenOfConfigPIDS,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) LpReqResData,
  uint8 LucSID);

/* Get ID index */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetIDIndex(uint8 LucIDType,
  uint8 LucIDValue, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpIDIndex);

/* To get the Availability list of service 0x01 */
extern FUNC(uint32, DCM_CODE) Dcm_DspReadOBD_AvlInfo
 (P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) LpRxBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer,
  uint32 LulBufferSize, uint8 LucPIDCount, uint8 LucIDType );

/* To get the non Availability list of service 0x01 */
extern FUNC(uint16, DCM_CODE) Dcm_DspReadOBD_1_DemInfo
  (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRxBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) LpRespLength,
  uint8 LucPIDCount);

#endif

#if((DCM_OBD_GETDTC_03_SERVICE == STD_ON) || \
 (DCM_OBD_GETDTC_07_SERVICE == STD_ON) || (DCM_OBD_GETDTC_0A_SERVICE == STD_ON))

/* To get the number of Filtered OBD DTCs for services 0x03,0x07,0x0A */
extern FUNC(void, DCM_CODE) Dcm_DemGetNumberOfOBDDTC(void);

/* To get the Filtered OBD DTCs for services 0x03,0x07,0x0A */
extern FUNC(uint32, DCM_CODE) Dcm_DspReadOBDDTCInfo(uint32 LulBufferSize);

#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPOBDINTERNALS_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
