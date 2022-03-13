/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Rte_SWC_DiagnosticService.h"


//#include "Cal.h"
#include "Dcm_Ram.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Dcm_GaaSeed �� Tester ���� ���� Seed */
//Cal_RandomCtxBufType Dcm_GddSeedCtxBuf = {0};
uint8 KeyBuf[4] = {0};

uint8 Roe_Flag=0U;
uint32 my_DIDInvokeCount=0U;

/* extern int gEcuIsBusy; */
uint8 gEcuIsBusy = 0U;
#define AC 0x0A
uint8 gActualtorValue = AC;
#define RPM_HIGH 0x07
#define RPM_LOW 0x50
uint8 gRPM[] = {RPM_HIGH,RPM_LOW};
uint8 gECT[] = {0xa6};
uint8 gBatVolt[] = {0x8c};
uint8 DcmData[255];
uint8 gSID = 0;
uint8 gReqType = 0;
uint16 gSourceAddress = 0;
uint16 gDataSize = 0;
Dcm_ConfirmationStatusType gConfirmationStatus = 0;

/******************************************************************************
* FUNCTION DEFINITION
******************************************************************************/

FUNC(void,SWC_DiagnosticService_CODE)AppDcm_DiagnosticSessionControlNotification(void)
{
  Rte_ModeType_DcmDiagnosticSessionControl LddPrevMode, LddNextMode;
  Rte_Mode_modeNotificationPort_SessionControl_DcmDiagnosticSessionControl(&LddPrevMode, &LddNextMode);
  
} 

/* Possible Errors:
 * RTE_E_OK                   - Operation was successful
 * RTE_E_CallbackDCMRequestServices_E_NOT_OK               - Operation was not successful
 * RTE_E_CallbackDCMRequestServices_E_PROTOCOL_NOT_ALLOWED - conditions in application allows no further procession of protocol
 */
FUNC(Std_ReturnType, RTE_CODE) AppDcm_StartProtocol(
  IN Dcm_ProtocolType ProtocolID)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  
  return LddRetVal;
}

/* Possible Errors:
 * RTE_E_OK     - Operation was successful
 * RTE_E_CallbackDCMRequestServices_E_NOT_OK - Operation was not successful
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_StopProtocol(
  IN Dcm_ProtocolType ProtocolID)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_ActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    LddRetVal = RTE_E_OK;
  }

  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_FreezeCurrentState_ActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    LddRetVal = RTE_E_OK;
  }
  
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 *
 * Comment:
 * The server is not allowed to return E_NOT_OK, but shall always provide a valid data value
 * (e.g. a default/replacement value in an error-case) to Dcm/Dem nevertheless the signature of the
 * operation includes E_NOT_OK to ensure compatibility between server runnable and RTE Call
 * API, since the RTE may return negative Std_Return values in certain cases (e.g. partition of
 * server stopped)
 */


FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_ActuatorControl(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  Data[0] = gActualtorValue;

  LddRetVal = RTE_E_OK;


  return LddRetVal;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteData_ActuatorControl(
    IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

  VAR(Std_ReturnType, RTE_DATA) LddRetVal;



  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    gActualtorValue = Data[0];
    LddRetVal = RTE_E_OK;
  }

  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ResetToDefault_ActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    gActualtorValue = AC;

    LddRetVal = RTE_E_OK;
  }
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReturnControlToECU_ActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  if (1 != gEcuIsBusy)
  {
    gActualtorValue = AC;

    LddRetVal = RTE_E_OK;
  }
  else
  {
    gEcuIsBusy = 0;

    *ErrorCode = 0x22;

    LddRetVal = E_NOT_OK;

  }
  return LddRetVal;
}
/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_ActuatorControl_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_ActuatorControl_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ShortTermAdjustment_ActuatorControl(
    IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlOptionRecord,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    gActualtorValue = ControlOptionRecord[0];

    LddRetVal = RTE_E_OK;
  }
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_IsDidAvailable_DID_0100h_0110h(
  IN uint16 DID,
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) supported)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if ((DID >= 0x0100)  && (DID <= 0x0109))
  {
    LddRetVal = RTE_E_OK;
    *supported = 1U;
  }
  else
  {
    LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;
    *supported = 0U;
  }

  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadDidData_DID_0100h_0110h(
  IN uint16 DID,
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DataLength,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;
  
  switch(DID)
  {
  case 0x0100:
    *DataLength = 1;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    break;
  case 0x0101:
    *DataLength = 27;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    break;
  case 0x0102:
    *DataLength = 1;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    break;
  case 0x0103:
    *DataLength = 5;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    break;
  case 0x0104:
      *DataLength = 0;
      *ErrorCode = 0x22;
      break;
  default:
    /* LddRetVal is NOT OK ? */
    *DataLength = 0;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    break;
  }
  if (0u != *DataLength)
  {
    uint16 iteratorData;
    for(iteratorData = 0U; iteratorData < *DataLength; iteratorData++)
    {
      Data[iteratorData] = iteratorData+1;
    }
    LddRetVal = RTE_E_OK;
  }

  

  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK      - Request was not successful
 * RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteDidData_DID_0100h_0110h(
  IN uint16 DID,
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
  IN Dcm_OpStatusType OpStatus,
  IN uint16 DataLength,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  uint16 iteratorData;

  LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;

  switch(DID)
  {
  case 0x0100:/* no break */
  case 0x0101:/* no break */
  case 0x0102:/* no break */
  case 0x0103:
    for (iteratorData = 0U;iteratorData < DataLength; iteratorData++)
    {
      DcmData[iteratorData] = Data[iteratorData];
    }
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    LddRetVal = RTE_E_OK;
    break;
  case 0x0104:
    /* LddRetVal is NOT OK ? */
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    break;
  case 0x0110:
    /* generalProgrammingFailure  */
    *ErrorCode = 0x72;
    break;
  default:
    /* LddRetVal is NOT OK ? */
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;    
    break;
  }
  return LddRetVal;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_SystemSupplierECUHardwareVersionNumber_E_NOT_OK - Request was not successful 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_SystemSupplierECUHardwareVersionNumber(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
/*  VAR(Std_ReturnType, RTE_DATA) LddRetVal;  
  LddRetVal = RTE_E_DataServices_SystemSupplierECUHardwareVersionNumber_E_OK;
*/
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_SystemSupplierECUHardwareVersionNumber_E_NOT_OK - Request was not successful 
 *
 * Comments:
 * The server is not allowed to return E_NOT_OK, but shall always provide a valid data value 
 * (e.g. a default/replacement value in an error-case) to Dcm/Dem nevertheless the signature of the 
 * operation includes E_NOT_OK to ensure compatibility between server runnable and RTE Call 
 * API, since the RTE may return negative Std_Return values in certain cases (e.g. partition of 
 * server stopped)
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_SystemSupplierECUHardwareVersionNumber(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  Data[0] = 0x00U;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_SystemSupplierECUSoftwareNumber_E_NOT_OK - Request was not successful 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_SystemSupplierECUSoftwareNumber(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;  
  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_SystemSupplierECUSoftwareNumber_E_NOT_OK - Request was not successful 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_SystemSupplierECUSoftwareNumber(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  Data[0] = 0x00U;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_VehicleManufacturerECUSoftwareVersionNumber_E_NOT_OK - Request was not successful 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_VehicleManufacturerECUSoftwareVersionNumber(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;  
  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_SYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK     - Request was successful
 * RTE_E_DataServices_VehicleManufacturerECUSoftwareVersionNumber_E_NOT_OK - Request was not successful 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_VehicleManufacturerECUSoftwareVersionNumber(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  Data[0] = 0x00U;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_VehicleSpeed_E_NOT_OK       - Request was not successful
 * RTE_E_DataServices_VehicleSpeed_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_VehicleSpeed(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_VehicleSpeed_E_NOT_OK       - Request was not successful
 * RTE_E_DataServices_VehicleSpeed_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_GetScalingInformation_VehicleSpeed(

  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ScalingInfo,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  /*
    s#1 {unsigned numeric, 1 data byte}          0x01
    s#2 {formula, 5 data bytes}                      0x95
    e#2 [ byte#1 ]{formulaIdentifier=C0*x+C1}   0x00
    e#2 [ byte#2 ]  {C0 high byte}                   0xE0
    e#2 [byte#3]{C0 low byte}[C0=75*10P-2P]    0x4B
    e#2 [ byte#4 ]  {C1 high byte}                   0x00
    e#2 [byte#5]{C1 low byte}[C1=30*10P0P]      0x1E
    s#3 {unit / format, 1 data byte}                  0xA1
    e#3 [ byte#1 ]  {unit ID, km/h}                   0x30
   * */

  ScalingInfo[0] = (uint8)0x01U;
  ScalingInfo[1] = (uint8)0x95U;
  ScalingInfo[2] = (uint8)0x00U;
  ScalingInfo[3] = (uint8)0xE0U;
  ScalingInfo[4] = (uint8)0x4BU;
  ScalingInfo[5] = (uint8)0x00U;
  ScalingInfo[6] = (uint8)0x1EU;
  ScalingInfo[7] = (uint8)0xA1U;
  ScalingInfo[8] = (uint8)0x30U;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  LddRetVal = RTE_E_OK;

  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK          - Request was successful
 * RTE_E_DataServices_VehicleSpeed_E_NOT_OK       - Request was not successful
 * RTE_E_DataServices_VehicleSpeed_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 *
 * Comments:
 * The server is not allowed to return E_NOT_OK, but shall always provide a valid data value 
 * (e.g. a default/replacement value in an error-case) to Dcm/Dem nevertheless the signature of the 
 * operation includes E_NOT_OK to ensure compatibility between server runnable and RTE Call 
 * API, since the RTE may return negative Std_Return values in certain cases (e.g. partition of 
 * server stopped)
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_VehicleSpeed(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;

  Data[0] = 0x00;

  return LddRetVal;
}

/* Port : 
 * ASYNCH_CLIENT_SERVER
 *
 * Possible Errors:
 * RTE_E_OK  Operation successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK -  Request was not successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP
 * - application request the transmission of a response Response Pending (NRC 0x78)
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 * DCM_FORCE_RCRRP_OK - Confirm a response pending transmission
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_RequestResults_CalibrationActuator(
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(RequestDataOutType_RID_0200h_CalibrationActuator_routineStatus_ResOutSignal, AUTOMATIC, RTE_APPL_DATA) DataOut1,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;

  DataOut1[0] = 0x71;

  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}

/* Port : 
 * ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK  Operation successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK -  Request was not successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP
 * - application request the transmission of a response Response Pending (NRC 0x78)
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 * DCM_FORCE_RCRRP_OK - Confirm a response pending transmission
 */
FUNC(Std_ReturnType, RTE_CODE)AppDcm_Start_CalibrationActuator(
  IN StartDataInType_RID_0200h_CalibrationActuator_routineControlOption_StartInSignal DataIn1,
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(StartDataOutType_RID_0200h_CalibrationActuator_routineStatus_StartOutSignal, AUTOMATIC, RTE_APPL_DATA) DataOut1,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  

    LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  DataOut1[0] = DataIn1;

  return LddRetVal;
}

/* Port : 
 * ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK  Operation successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK -  Request was not successful
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING - Request is not yet finished. Further call(s) required to finish.
 * RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP
 * - application request the transmission of a response Response Pending (NRC 0x78)
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 * DCM_FORCE_RCRRP_OK - Confirm a response pending transmission
 *
 * 

*/
FUNC(Std_ReturnType, RTE_CODE)AppDcm_Stop_CalibrationActuator(
  IN StopDataInType_RID_0200h_CalibrationActuator_DcmDspRoutineStopInSignal0 DataIn1,
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(StopDataInType_RID_0200h_CalibrationActuator_DcmDspRoutineStopInSignal0, AUTOMATIC, RTE_APPL_DATA) DataOut1,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  
  LddRetVal = RTE_E_OK;
  DataOut1[0] = DataIn1;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}

/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_OK                     - Request was successful
 * RTE_E_SecurityAccess_L1_E_NOT_OK                 - Request was not successful
 * RTE_E_SecurityAccess_L1_DCM_E_PENDING            - Request is not yet finished. Further call(s) required to finish.
 * RTE_E_SecurityAccess_L1_DCM_E_COMPARE_KEY_FAILED - Key did not match.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 *  
 * Comments:
 * Key, which needs to be compare
*/
FUNC(Std_ReturnType, RTE_CODE)AppDcm_CompareKey_L1(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
  IN Dcm_OpStatusType OpStatus)
{
  Std_ReturnType LddRetVal = E_OK;
  uint8 lucIndex;

  for(lucIndex = 0; lucIndex < 4; lucIndex++)
  {
    if(KeyBuf[lucIndex] != Key[lucIndex])
    {
      LddRetVal = E_NOT_OK;
    }
  }

  return LddRetVal;
}


/* Port : 
 * USE_DATA_ASYNCH_CLIENT_SERVER
 * 
 * Possible Errors:
 * RTE_E_SecurityAccess_L1_E_OK                     - Request was successful
 * RTE_E_SecurityAccess_L1_E_NOT_OK                 - Request was not successful
 * RTE_E_SecurityAccess_L1_DCM_E_PENDING            - Request is not yet finished. Further call(s) required to finish.
 *
 * OpStatus:
 * DCM_INITIAL - Indicates the initial call to the operation
 * DCM_PENDING - Indicates that a pending return has been done on the previous call of the operation
 * DCM_CANCEL  - Indicates  that  the  DCM  requests  to  cancel  the pending operation 
 *  
 * Comments:
 * Seed, Pointer for provided seed
*/
FUNC(Std_ReturnType, RTE_CODE)AppDcm_GetSeed_L1(
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal; //= E_OK;
  //Cal_ReturnType LddCalRetVal = CAL_E_NOT_OK;
  //Cal_HashCtxBufType DcmTest_GddHashCtxBuf = {0, };
  //uint32 LulResultLength = 4; /* The initial value of LulResultLength must be 4 */
  //uint8 lucIndex;

  /********************** ���� ���� �ܰ�  ************************/
//  LddCalRetVal = Cal_RandomGenerate(CAL_AUTRANDOMGENERATE_INDEX,
//  if(CAL_E_NOT_OK == LddCalRetVal)
//  {
//    LddRetVal = E_NOT_OK;
//  }
  /****************************************************************/

  /********************** key ���� �ܰ�  **************************/
//  LddCalRetVal = Cal_HashStart(CAL_AUTSEEDKEY_INDEX, DcmTest_GddHashCtxBuf);
//  if(CAL_E_NOT_OK == LddCalRetVal)
//  {
//    LddRetVal = E_NOT_OK;
//  }

  //LddCalRetVal = Cal_HashUpdate(CAL_AUTSEEDKEY_INDEX, DcmTest_GddHashCtxBuf,
//                 (uint8*)(Dcm_GaaSeed), 4);
//  if(CAL_E_NOT_OK == LddCalRetVal)
//  {
//    LddRetVal = E_NOT_OK;
//  }

//  LddCalRetVal = Cal_HashFinish(CAL_AUTSEEDKEY_INDEX, DcmTest_GddHashCtxBuf,
 //                (uint8*)KeyBuf, &LulResultLength, FALSE);
 // if(CAL_E_NOT_OK == LddCalRetVal)
 // {
 //   LddRetVal = E_NOT_OK;
 // }
  /****************************************************************/

//  for(lucIndex = 0; lucIndex < 4; lucIndex++)
//  {
//    Seed[lucIndex] = Dcm_GaaSeed[lucIndex];
//  }

  if (1 != gEcuIsBusy)
  {
    Seed[0] = 0x01;
    Seed[1] = 0x02;
    Seed[2] = 0x03;
    Seed[3] = 0x04;

    LddRetVal = RTE_E_OK;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
  }
  else
  {
    gEcuIsBusy = 0;
    *ErrorCode = 0x22;
    LddRetVal = E_NOT_OK;
  }


  return LddRetVal;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_VINDataIdentifier(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

  *ErrorCode = DCM_E_POSITIVERESPONSE;

  return RTE_E_OK;
}

/* VIN : 17Bytes */

FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_VINDataIdentifier(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  uint16 iteratorData;

  for (iteratorData = 0;iteratorData<17U;iteratorData++)
  {
    Data[iteratorData] = iteratorData+1;
  }



  return RTE_E_OK;
}

uint8 VIN[17];
FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteData_VINDataIdentifier(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  uint16 iteratorData;
  Std_ReturnType ret =E_NOT_OK;

  if (Data[0] == 0x57) /* 0x57 = 'W' */
  {
    for (iteratorData = 0; iteratorData < 17u ; iteratorData++)
    {
      VIN[iteratorData] = Data[iteratorData];
    }
    ret = RTE_E_OK;
    *ErrorCode = DCM_E_POSITIVERESPONSE;
  }
  else
  {
    *ErrorCode = 0x31;
  }




  return ret;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_GetScalingInformation_VINDataIdentifier(

  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ScalingInfo,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  /*Note)
  6F = scalingByte#1  {ASCII, 15 data bytes}
  62 = scalingByte#2  {ASCII, 2 data bytes}
  */
  ScalingInfo[0] = 0x6F;
  ScalingInfo[1] = 0x62;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;
}




FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_BatVolt(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  
  return LddRetVal;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_BatVolt(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{

VAR(Std_ReturnType, RTE_DATA) LddRetVal;
Data[0] = gBatVolt[0];
LddRetVal = RTE_E_OK;

    return LddRetVal;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_ECT(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return LddRetVal;
}
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_ECT(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{

VAR(Std_ReturnType, RTE_DATA) LddRetVal;

 Data[0] = gECT[0];

LddRetVal = RTE_E_OK;

    return LddRetVal;
}
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ConditionCheckRead_RPM(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  LddRetVal = RTE_E_OK;
  *ErrorCode = DCM_E_POSITIVERESPONSE;    

  return LddRetVal;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReadData_RPM(
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  Data[0] = gRPM[0];
  Data[1] = gRPM[1];

  LddRetVal = RTE_E_OK;


  return LddRetVal;
}

/*
FUNC(Std_ReturnType, RTE_CODE)AppDcm_FreezeCurrentState_MultipleActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    LddRetVal = RTE_E_OK;
  }
    return LddRetVal;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReturnControlToECU_MultipleActuatorControl(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if (ErrorCode == NULL_PTR)
  {
    LddRetVal = E_NOT_OK;
  }

  if (1 != gEcuIsBusy)
  {
    LddRetVal = RTE_E_OK;
  }
  else
  {

    gEcuIsBusy = 0;

    *ErrorCode = 0x22;

    LddRetVal = E_NOT_OK;
  }

  return LddRetVal;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_ShortTermAdjustment_MultipleActuatorControl(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlOptionRecord,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

VAR(Std_ReturnType, RTE_DATA) LddRetVal;
  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    LddRetVal = RTE_E_OK;
  }
    return LddRetVal;
}

*/
FUNC(Std_ReturnType, RTE_CODE)AppDcm_FreezeCurrentState_RPM(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    LddRetVal = RTE_E_OK;
  }
  return LddRetVal;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_ReturnControlToECU_RPM(

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if (1 != gEcuIsBusy)
  {
    gRPM[0] = RPM_HIGH;
    gRPM[1] = RPM_LOW;

    LddRetVal = RTE_E_OK;
  }
  else
  {


    *ErrorCode = 0x22;

    LddRetVal = E_NOT_OK;

    gEcuIsBusy = 0;

  }
  return LddRetVal;
}
FUNC(Std_ReturnType, RTE_CODE)AppDcm_ShortTermAdjustment_RPM(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlOptionRecord,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  if (1 == gEcuIsBusy)
  {
    gEcuIsBusy = 0;
    LddRetVal = E_NOT_OK;
    *ErrorCode = 0x22;
  }
  else
  {
    gRPM[0] = ControlOptionRecord[0];
    gRPM[1] = ControlOptionRecord[1];
    LddRetVal = RTE_E_OK;
  }
    return LddRetVal;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteData_RPM(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  gRPM[0] = Data[0];
  gRPM[1] = Data[1];

    return RTE_E_OK;
}


FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteData_BatVolt(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  gBatVolt[0] = Data[0];

    return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE)AppDcm_WriteData_ECT(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,

  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  gECT[0] = Data[0];

    return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE)ServiceRequestSupplierNotification_Confirmation(
  IN uint8 SID,
  IN uint8 ReqType,
  IN uint16 SourceAddress,
  IN Dcm_ConfirmationStatusType ConfirmationStatus)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  gSID = SID;
  gReqType = ReqType;
  gSourceAddress = SourceAddress;
  gConfirmationStatus = ConfirmationStatus;

  return RTE_E_OK;
}

FUNC(Std_ReturnType,RTE_CODE)ServiceRequestSupplierNotification_Indication(
  IN uint8 SID,
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData,
  IN uint16 DataSize,
  IN uint8 ReqType,
  IN uint16 SourceAddress,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal;

  gSID = SID;
  gDataSize = DataSize;
  gReqType = ReqType;
  gSourceAddress = SourceAddress;
  
  return RTE_E_OK;
}
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
