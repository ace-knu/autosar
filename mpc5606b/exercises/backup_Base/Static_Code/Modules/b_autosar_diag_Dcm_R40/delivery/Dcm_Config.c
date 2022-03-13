/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dem_Config.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.4     07-06-2017    Jin     Jung    #7008                              **
**                                                                            **
** 1.0.3     15-02-2017    Jin     Jung    #5460                              **
**                                                                            **
** 1.0.2     05-12-2016    Jin     Jung    #6846                              **
**                                                                            **
** 1.0.1     03-03-2016    Sungeol Baek    #3750, RTRT reflection             **
**                                                                            **
** 1.0.0     18-11-2013    Autron          Initial Version                    **
*******************************************************************************/

#include "Dcm.h"
#include "Dcm_Ram.h"
#include "Dcm_Types.h"
#include "Dcm_DspServices.h"
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#include "Dcm_Config.h"

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#ifdef DCM_NUMBER_OF_REQUEST_MANUFACTURER_INDICATION
/* Pre-compile option for Manufacturer Indication Support */
const uint8 Dcm_Number_Of_Request_Manufacturer_Indication = DCM_NUMBER_OF_REQUEST_MANUFACTURER_INDICATION;
#endif

#ifdef DCM_NUMBER_OF_REQUEST_SUPPLIER_INDICATION
/* Pre-compile option for Supplier Indication Support */
const uint8 Dcm_Number_Of_Request_Supplier_Indication = DCM_NUMBER_OF_REQUEST_SUPPLIER_INDICATION;
#endif

#ifdef DCM_TASK_TIME
/* Pre-compile option for Task Time */
const uint16 Dcm_Task_Time = DCM_TASK_TIME;
#endif

#ifdef DCM_PAGEDBUFFERTIMEOUT
/* Pre-compile option for Timeout for Paged Buffer */
const uint16 Dcm_PagedBufferTimeout = DCM_PAGEDBUFFERTIMEOUT;
#endif

#ifdef DCM_DIAG_RESP_MAX_NUM_RESPEND
/* Pre-compile option for Response Maximum Respend */
const uint8 Dcm_diag_Resp_Max_Num_Respend = DCM_DIAG_RESP_MAX_NUM_RESPEND;
#endif

#ifdef DCM_MAX_DID_TO_READ
/* Pre-compile option for Maximum Did to Read */
const uint16 Dcm_Max_DID_To_Read = DCM_MAX_DID_TO_READ;
#endif

#ifdef DCM_TOTAL_NUM_OF_PIDS
/* Pre-compile option for Total number of PIDs Configured */
const uint8 Dcm_Total_Num_Of_PIDs = DCM_TOTAL_NUM_OF_PIDS;
#endif

#ifdef DCM_TOTAL_NUM_OF_OBDMIDS
/* Pre-compile option for Total number of ObdMids Configured */
const uint8 Dcm_Total_Num_Of_OBDMIDs = DCM_TOTAL_NUM_OF_OBDMIDS;
#endif

#ifdef DCM_TOTAL_NUM_OF_TIDS
/* Pre-compile option for Total number of TIDs Configured */
const uint8 Dcm_Total_Num_Of_TIDs = DCM_TOTAL_NUM_OF_TIDS;
#endif

#ifdef DCM_TOTAL_NUM_OF_VIDS
/* Pre-compile option for Total number of VIDs Configured */
const uint8 Dcm_Total_Num_OF_VIDs = DCM_TOTAL_NUM_OF_VIDS;
#endif

#ifdef DCM_TOTAL_NUM_OF_DIDS
/* Pre-compile option for Total number of DIDs Configured */
const uint16 Dcm_Total_Num_Of_DIDs = DCM_TOTAL_NUM_OF_DIDS;
#endif

#ifdef DCM_NUM_OF_GAADATAINFOTYPECONFIG
/* Pre-compile option for Total number of Data Info type Configured */
const uint8 Dcm_Num_Of_Gaa_Data_InfoType_Config = DCM_NUM_OF_GAADATAINFOTYPECONFIG;
#endif

#ifdef DCM_NUM_OF_GAAROUTINECONTROLCONFIG
/* Pre-compile option for Total number of Routine Control Configured */
const uint8 Dcm_Num_Of_Gaa_Routine_Control_Config = DCM_NUM_OF_GAAROUTINECONTROLCONFIG;
#endif

#ifdef DCM_TOTAL_NUM_SEC_LEVEL
/* Pre-compile option for Total number of Security Levels Configured */
const uint8 Dcm_Total_Num_Sec_Level = DCM_TOTAL_NUM_SEC_LEVEL;
#endif

#ifdef DCM_NUM_PROTOCOL_CONFIGD
/* Pre-compile option for Total number of Protocols Configured */
const uint8 Dcm_Num_Protocol_Configd = DCM_NUM_PROTOCOL_CONFIGD;
#endif

#ifdef DCM_POWERDOWN_TIME
/* Pre-compile option for Power Down Time */
const uint8 Dcm_PowerDown_Time = DCM_POWERDOWN_TIME;
#endif

#ifdef DCM_TOTAL_NUM_OF_RIDS
/* Pre-compile option for Total number of DIDs Configured */
const uint16 Dcm_Total_Num_Of_RIDs = DCM_TOTAL_NUM_OF_RIDS;
#endif

#ifdef DCM_TOTAL_NUM_OF_DYM_DID
/* Pre-compile option for Dynamic Dids */
const uint16 Dcm_Total_Num_Of_Dym_DID = DCM_TOTAL_NUM_OF_DYM_DID;
#endif

#ifdef DCM_TOTAL_NUM_OF_STATIC_DID
/* Pre-compile option for Ststic Dids */
const uint16 Dcm_Total_Num_Of_Static_DID = DCM_TOTAL_NUM_OF_STATIC_DID;
#endif

#ifdef DCM_TOTAL_NUM_READ_MEMORY_CONFIGURED
/* Pre-compile option for Total number of Read Memory Configured */
const uint8 Dcm_Total_Num_Read_Memory_Configured = DCM_TOTAL_NUM_READ_MEMORY_CONFIGURED;
#endif

#ifdef DCM_TOTAL_NUM_WRITE_MEMORY_CONFIGURED
/* Pre-compile option for Total number of Write Memory Configured */
const uint8 Dcm_Total_Num_Write_Memory_Configured = DCM_TOTAL_NUM_WRITE_MEMORY_CONFIGURED;
#endif

#ifdef DCM_TOTAL_NUM_OF_RXPDUID
/* Pre-compile option for Total number of Rx Configured */
const PduIdType Dcm_Total_Num_Of_RxPduID = DCM_TOTAL_NUM_OF_RXPDUID;
#endif

#ifdef DCM_TOTAL_NUM_OF_ALL_CHANNEL
/* Pre-compile option for Total number ofAll ComM Configured */
const uint8 Dcm_Total_Num_Of_All_Channel = DCM_TOTAL_NUM_OF_ALL_CHANNEL;
#endif

#ifdef DCM_TOTAL_NUM_OF_SPECIFIC_CHANNEL
/* Pre-compile option for Total number of Specific ComM Configured */
const uint8 Dcm_Total_Num_Of_Specific_Channel = DCM_TOTAL_NUM_OF_SPECIFIC_CHANNEL;
#endif

#ifdef DCM_SEND_AT_LOW_RATE_TIMER
/* Pre-compile option for Periodic Transmission for slow rate (0x01) */
const uint16 Dcm_Send_At_Low_Rate_Timer = DCM_SEND_AT_LOW_RATE_TIMER;
#endif

#ifdef DCM_SEND_AT_MED_RATE_TIMER
/* Pre-compile option for Periodic Transmission for Medium rate (0x02) */
const uint16 Dcm_Send_At_Med_Rate_Timer = DCM_SEND_AT_MED_RATE_TIMER;
#endif

#ifdef DCM_SEND_AT_FAST_RATE_TIMER
/* Pre-compile option for Periodic Transmission for Fast rate (0x03) */
const uint16 Dcm_Send_At_Fast_Rate_Timer = DCM_SEND_AT_FAST_RATE_TIMER;
#endif

#ifdef DCM_DSP_MAX_PERIODIC_DID
/* Pre-compile option for Max Periodic DID to Read */
const uint16 Dcm_Dsp_Max_Periodic_DID = DCM_DSP_MAX_PERIODIC_DID;
#endif

#ifdef DCM_DSP_MAX_PERIODIC_DID_SCHEDULED
/* Pre-compile option for Periodic Response Type */
const uint16 Dcm_Dsp_Max_Periodic_DID_Scheduled = DCM_DSP_MAX_PERIODIC_DID_SCHEDULED;
#endif

#ifdef DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG
/* Macro total number of Support Address configured */
const uint8 Dcm_Num_Of_Address_Length_Format_ID_Config = DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG;
#endif

#ifdef DCM_TOTAL_NUM_OF_CALLBACK_REQUEST
/* Pre-compile option for Total number of Callback request Configured */
const uint8 Dcm_Total_Num_Of_Callback_Request = DCM_TOTAL_NUM_OF_CALLBACK_REQUEST;
#endif

#ifdef DCM_NUM_OF_DIAGSESSIONCONFIG
/* Pre-compile option for Total number of Session level Configured */
const uint8 Dcm_Num_Of_Diag_Session_Config = DCM_NUM_OF_DIAGSESSIONCONFIG;
#endif

#ifdef DCM_NUM_OF_SECURITYLEVELCONFIG
/* Pre-compile option for Total number of Security level Configured */
const uint8 Dcm_Num_Of_Security_Level_Config = DCM_NUM_OF_SECURITYLEVELCONFIG;
#endif

#ifdef DCM_TOTAL_NUM_OF_OBD_DID
/* Macro total number of Support Address configured */
const uint16 Dcm_Total_Num_Of_OBD_DID = DCM_TOTAL_NUM_OF_OBD_DID;
#endif

#ifdef DCM_ROE_MAX_EVENT_LENGTH
/* Macro for Number of DcmDspDidRange configured */
const uint32 Dcm_ROE_Max_Event_Length = DCM_ROE_MAX_EVENT_LENGTH;
#endif

#ifdef DCM_ROE_MAX_NUMBER_OF_RETRY
/* Macro for Number of DcmDspDidRange configured */
const uint8 Dcm_ROE_Max_Number_Of_Retry = DCM_ROE_MAX_NUMBER_OF_RETRY;
#endif

#ifdef DCM_ROE_MAX_QUEUE_LENGTH
/* Macro for Number of DcmDspDidRange configured */
const uint8 Dcm_ROE_Max_Queue_Length = DCM_ROE_MAX_QUEUE_LENGTH;
#endif

#ifdef DCM_ROE_INTER_MESSAGE_TIME
/* Macro for Number of DcmDspDidRange configured */
const uint16 Dcm_ROE_Inter_Message_Time = DCM_ROE_INTER_MESSAGE_TIME;
#endif

#ifdef DCM_PID_AVL_CONFIG_LIST_FREEZE_FRAME
/* To indicate PID Config list */
const uint8 Dcm_PID_AVL_Config_List_FreezeFrame = DCM_PID_AVL_CONFIG_LIST_FREEZE_FRAME;
#endif

#ifdef DCM_PID_AVL_CONFIG_LIST
/* To indicate PID Config list */
const uint8 Dcm_PID_AVL_Config_List = DCM_PID_AVL_CONFIG_LIST;
#endif

#ifdef DCM_VID_AVL_CONFIG_LIST
/* To indicate VID Config list */
const uint8 Dcm_VID_AVL_Config_List = DCM_VID_AVL_CONFIG_LIST;
#endif

#ifdef DCM_TID_AVL_CONFIG_LIST
/* To indicate TID Config list */
const uint8 Dcm_TID_AVL_Config_List = DCM_TID_AVL_CONFIG_LIST;
#endif

#ifdef DCM_OBDMID_AVL_CONFIG_LIST
/* To indicate OBDMID Config list */
const uint8 DCM_OBDMID_AVL_Config_List = DCM_OBDMID_AVL_CONFIG_LIST;
#endif

#ifdef DCM_DSP_MAX_PERIODIC_DID_LEN
/* To indicate OBDMID Config list */
const uint8 Dcm_Dsp_Max_Periodic_Did_Len = DCM_DSP_MAX_PERIODIC_DID_LEN;
#endif


#ifdef DCM_MAX_NO_OF_PRECONFIGURED_DID
/* To indicate OBDMID Config list */
const uint8 Dcm_Max_No_Of_Preconfigured_Did = DCM_MAX_NO_OF_PRECONFIGURED_DID;
#endif


/* Pre-compile option for Control DTC Enable */
#ifdef DCM_DSP_CONTROL_DTC_REENABLE_MODE_RULE
const Dcm_ModeType Dcm_Dsp_Control_Dtc_Reenable_Mode_Rule = DCM_DSP_CONTROL_DTC_REENABLE_MODE_RULE;
#endif
#ifdef DCM_DSP_COMM_CONTROL_REENABLE_MODE_RULE
/* Pre-compile option for Communication Control Enable */
const Dcm_ModeType Dcm_Dsp_Comm_Control_Reenable_Mode_Rule  = DCM_DSP_COMM_CONTROL_REENABLE_MODE_RULE;
#endif

#ifdef DCM_NO_OF_COMM_CHANNELS
const uint8 Dcm_No_Of_Comm_Channels = DCM_NO_OF_COMM_CHANNELS;
#endif

#ifdef DCM_NUM_OF_COMMCONTROLCONFIG
const uint8 Dcm_Num_Of_CommControlConfig = DCM_NUM_OF_COMMCONTROLCONFIG;
#endif
#ifdef DCM_NUM_OF_PDUIDTABLECONFIG
const PduIdType Dcm_Num_Of_PduidTableConfig = DCM_NUM_OF_PDUIDTABLECONFIG;
#endif


#ifdef DCM_NUM_OF_BUFFER_CONFIG
const uint8 Dcm_Num_Of_Buffer_Config = DCM_NUM_OF_BUFFER_CONFIG;
#endif

#ifdef DCM_NUM_OF_SIDCONFIG
const uint8 Dcm_Num_Of_SidConfig = DCM_NUM_OF_SIDCONFIG;
#endif

#ifdef DCM_NUM_OF_SUBSERVICEIDCONFIG
const uint8 Dcm_Num_Of_SubserviceIdConfig = DCM_NUM_OF_SUBSERVICEIDCONFIG;
#endif

#ifdef DCM_NUM_OF_GAASIGWRFUNCPTR
const uint8 Dcm_Num_Of_SigWrFuncPtr = DCM_NUM_OF_GAASIGWRFUNCPTR;
#endif

#ifdef DCM_NUM_OF_DIDPARACONFIG
const uint16 Dcm_Num_Of_DidParaConfig = DCM_NUM_OF_DIDPARACONFIG;
#endif

#ifdef DCM_NUM_OF_DCMDSPDIDRANGECONFIG
const uint16 Dcm_Num_Of_DcmDspDidRangeConfig = DCM_NUM_OF_DCMDSPDIDRANGECONFIG;
#endif

#ifdef DCM_NUM_OF_GAASIGRDFUNCPTR
const uint8 Dcm_Num_Of_SigRdFuncPtr = DCM_NUM_OF_GAASIGRDFUNCPTR;
#endif

#ifdef DCM_RESPOND_ALL_REQUEST
const boolean Dcm_Respond_All_Request = DCM_RESPOND_ALL_REQUEST;
#endif

#ifdef DCM_NUM_OF_PROTOCOLCONFIG
const uint8 Dcm_Num_Of_ProtocolConfig = DCM_NUM_OF_PROTOCOLCONFIG;
#endif

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
** Function Name        : Dcm_DspInternal_ReadSigTypeEcuSignal                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used to read ecu signal            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LucDataType                                         **
**                                                                            **
** InOut parameter      : pData                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"    
#if (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE)
Dcm_CfgInternal_WriteSigTypeSenderReceiver(
  P2CONST(Dcm_DcmDspDataconfig, AUTOMATIC, DCM_APPL_CONST) aData,
  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) aInputBuffer,
  Dcm_NegativeResponseCodeType *anOutNegRespCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (
    (NULL_PTR != aData) && 
    (NULL_PTR != aInputBuffer) && 
    (NULL_PTR != anOutNegRespCode)
  )
  {

    *anOutNegRespCode = DCM_E_GENERALREJECT;  
    
    #if ((DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON))
     
    switch(aData->ucDcmDspDataType)
    {
      #if(DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON)
      case DCM_DSP_DATA_TYPE_UINT8:
        if (NULL_PTR != Dcm_GaaSigReadWriteUint8Func[aData->ucWriteFunctionIndex].pWriteDataUint8Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteUint8Func[aData->ucWriteFunctionIndex].pWriteDataUint8Func((uint8*)aInputBuffer);
        }
        break;
      #endif      
      
      #if(DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON)
      case DCM_DSP_DATA_TYPE_UINT16:
        if (NULL_PTR != Dcm_GaaSigReadWriteUint16Func[aData->ucWriteFunctionIndex].pWriteDataUint16Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteUint16Func[aData->ucWriteFunctionIndex].pWriteDataUint16Func((uint16*)aInputBuffer);
        }
        break;
      #endif        

      #if(DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON)      
      case DCM_DSP_DATA_TYPE_UINT32:      
        if (NULL_PTR != Dcm_GaaSigReadWriteUint32Func[aData->ucWriteFunctionIndex].pWriteDataUint32Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteUint32Func[aData->ucWriteFunctionIndex].pWriteDataUint32Func((uint32*)aInputBuffer);
        }
        break;
      #endif        

      #if(DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON)
      case DCM_DSP_DATA_TYPE_SINT8:        
        if (NULL_PTR != Dcm_GaaSigReadWriteSint8Func[aData->ucWriteFunctionIndex].pWriteDataSint8Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteSint8Func[aData->ucWriteFunctionIndex].pWriteDataSint8Func((sint8*)aInputBuffer);
        }
        break;
      #endif        

      #if(DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON)
      case DCM_DSP_DATA_TYPE_SINT16:        
        if (NULL_PTR != Dcm_GaaSigReadWriteSint16Func[aData->ucWriteFunctionIndex].pWriteDataSint16Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteSint16Func[aData->ucWriteFunctionIndex].pWriteDataSint16Func((sint16*)aInputBuffer);
        }
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON)
      case DCM_DSP_DATA_TYPE_SINT32:        
        if (NULL_PTR != Dcm_GaaSigReadWriteSint32Func[aData->ucWriteFunctionIndex].pWriteDataSint32Func)
        {
          retVal = 
            Dcm_GaaSigReadWriteSint32Func[aData->ucWriteFunctionIndex].pWriteDataSint32Func((sint32*)aInputBuffer);
        }
        break;
      #endif        
        
      default:
        retVal = E_NOT_OK;      
        break;
    }
    if (E_OK == retVal)
    {
      *anOutNegRespCode = DCM_E_POSITIVERESPONSE;       
    }    
    #endif

  }

  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CfgInternal_ReadSigTypeEcuSignal                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used to read ecu signal            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LucDataType                                         **
**                                                                            **
** InOut parameter      : pData                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) : Dcm_GaaEcuSignalUint16Func     **
**                                                                            **
*******************************************************************************/
#if ((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
     (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
FUNC(Std_ReturnType, DCM_CODE)
Dcm_CfgInternal_ReadSigTypeEcuSignal(
  P2CONST(Dcm_DcmDspDataconfig, AUTOMATIC, DCM_APPL_CONST) aData,
  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) aOutputBuffer)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((NULL_PTR != aData) && (NULL_PTR != aOutputBuffer))
  {
    #if ((DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON) ||\
    (DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)      ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON))
    
    switch(aData->ucDcmDspDataType)
    {
      #if(DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON)
      case DCM_DSP_DATA_TYPE_UINT8:
        if (NULL_PTR != Dcm_GaaEcuSignalUint8Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint8)
        {
          Dcm_GaaEcuSignalUint8Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint8((uint8*)aOutputBuffer);
          retVal = E_OK;
        }
        break;
      #endif
      
      #if(DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT16:    
        if (NULL_PTR != Dcm_GaaEcuSignalUint16Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint16)
        {
          Dcm_GaaEcuSignalUint16Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint16((uint16*)aOutputBuffer);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT32:
        if (NULL_PTR != Dcm_GaaEcuSignalUint32Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint32)      
        {
          Dcm_GaaEcuSignalUint32Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalUint32((uint32*)aOutputBuffer);
          retVal = E_OK;  
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT8:
        if (NULL_PTR != Dcm_GaaEcuSignalSint8Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint8)      
        {
          Dcm_GaaEcuSignalSint8Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint8((sint8*)aOutputBuffer);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT16:    
        if (NULL_PTR != Dcm_GaaEcuSignalSint16Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint16)      
        {
          Dcm_GaaEcuSignalSint16Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint16((sint16*)aOutputBuffer);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT32:    
        if (NULL_PTR != Dcm_GaaEcuSignalSint32Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint32)      
        {
          Dcm_GaaEcuSignalSint32Func[aData->ucEcuSignalFunctionIndex].pDataReadEcuSignalSint32((sint32*)aOutputBuffer);        
          retVal = E_OK;
        }
        break;
      #endif
      
      default:  
        retVal = E_NOT_OK;      
        break;
    }
    #endif
  }

  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CfgInternal_IOControlSigTypeEcuSignal           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used to read ecu signal            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LucDataType                                         **
**                                                                            **
** InOut parameter      : pData                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) : Dcm_GaaEcuSignalUint16Func     **
**                                                                            **
*******************************************************************************/
#if (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE)
Dcm_CfgInternal_IOControlSigTypeEcuSignal(
  P2CONST(Dcm_DcmDspDataconfig, AUTOMATIC, DCM_APPL_CONST) aCfgData,
  uint8 anAction,
  P2CONST(void, AUTOMATIC, DCM_APPL_DATA) anInputBuffer,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA)  aNegResponceCode)  
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((NULL_PTR != aCfgData) && (NULL_PTR != aNegResponceCode))
  {
    *aNegResponceCode = DCM_E_GENERALREJECT;

    #if ((DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON) ||\
    (DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)      ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)     ||\
    (DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON))

    /*Invoke the Api IoHwAb_Dcm_<symbolic name of ECU signal
     * (parameter DcmDspDataEcuSignal)>() with
     * InputOutputControlParameter for the action parameter
     */        
    switch(aCfgData->ucDcmDspDataType)
    {
      #if(DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON)
      case DCM_DSP_DATA_TYPE_UINT8:        
        if (NULL_PTR != Dcm_GaaEcuSignalUint8Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint8Fnc)
        {
          uint8 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(uint8 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (uint8 *)anInputBuffer;
            inputVal = *inputValPtr;
          }
          
          Dcm_GaaEcuSignalUint8Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint8Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif
        
      #if(DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT16:
        if (NULL_PTR != Dcm_GaaEcuSignalUint16Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint16Fnc)
        {
          uint16 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(uint16 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (uint16 *)anInputBuffer;
            inputVal = *inputValPtr;
          }
          Dcm_GaaEcuSignalUint16Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint16Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT32:
        if (NULL_PTR != Dcm_GaaEcuSignalUint32Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint32Fnc)
        {
          uint32 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(uint32 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (uint32 *)anInputBuffer;
            inputVal = *inputValPtr;
          }
          Dcm_GaaEcuSignalUint32Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalUint32Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT8:
        if (NULL_PTR !=  Dcm_GaaEcuSignalSint8Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint8Fnc)
        {
          sint8 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(sint8 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (sint8 *)anInputBuffer;
            inputVal = *inputValPtr;
          }
          Dcm_GaaEcuSignalSint8Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint8Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif
        
      #if(DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)
      case DCM_DSP_DATA_TYPE_SINT16:
        if (NULL_PTR != Dcm_GaaEcuSignalSint16Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint16Fnc)
        {
          sint16 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(sint16 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (sint16 *)anInputBuffer;
            inputVal = *inputValPtr;

          }        
          Dcm_GaaEcuSignalSint16Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint16Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif

      #if(DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT32:
        if (NULL_PTR != Dcm_GaaEcuSignalSint32Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint32Fnc)
        {
          sint32 inputVal = 0;
          if (NULL_PTR != anInputBuffer)
          {
            P2CONST(sint32 , AUTOMATIC, DCM_APPL_DATA) inputValPtr = (sint32 *)anInputBuffer;
            inputVal = *inputValPtr;
          }
          Dcm_GaaEcuSignalSint32Func[aCfgData->ucEcuSignalFunctionIndex].pDataControlEcuSignalSint32Fnc(anAction, inputVal);
          retVal = E_OK;
        }
        break;
      #endif
        
      default:
        retVal = E_NOT_OK;
        break;      
    }
    
    if (E_OK == retVal)
    {
      *aNegResponceCode = DCM_E_POSITIVERESPONSE;
    }
    
    #endif
  }


  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CfgInternal_ReadDataSenderReceiverType          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used to read data element with     **
**                        Sender Receiver Interface                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LucDataType                                         **
**                                                                            **
** InOut parameter      : pData                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
*******************************************************************************/
#if ((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
     (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)) 
FUNC(Std_ReturnType, DCM_CODE)
Dcm_CfgInternal_ReadSigTypeSenderReceiver(
  P2CONST(Dcm_DcmDspDataconfig, AUTOMATIC, DCM_APPL_CONST) aCfgData,
  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) anOutputBuffer)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((NULL_PTR != aCfgData) && (NULL_PTR != anOutputBuffer))
  {
    #if ((DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON) ||\
      (DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON))

    switch(aCfgData->ucDcmDspDataType)
    {
      #if(DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON)
      case DCM_DSP_DATA_TYPE_UINT8:
        if (NULL_PTR != Dcm_GaaSigReadWriteUint8Func[aCfgData->ucReadFunctionIndex].pReadDataUint8Func)
        {
          retVal = Dcm_GaaSigReadWriteUint8Func[aCfgData->ucReadFunctionIndex].pReadDataUint8Func((uint8*)anOutputBuffer);
        }
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT16:
        if (NULL_PTR != Dcm_GaaSigReadWriteUint16Func[aCfgData->ucReadFunctionIndex].pReadDataUint16Func)
        {
          retVal = Dcm_GaaSigReadWriteUint16Func[aCfgData->ucReadFunctionIndex].pReadDataUint16Func((uint16*)anOutputBuffer);
        }
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_UINT32:
        if (NULL_PTR != Dcm_GaaSigReadWriteUint32Func[aCfgData->ucReadFunctionIndex].pReadDataUint32Func)
        {
          retVal = Dcm_GaaSigReadWriteUint32Func[aCfgData->ucReadFunctionIndex].pReadDataUint32Func((uint32*)anOutputBuffer);
        }
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT8:
        if (NULL_PTR != Dcm_GaaSigReadWriteSint8Func[aCfgData->ucReadFunctionIndex].pReadDataSint8Func)
        {
          retVal = Dcm_GaaSigReadWriteSint8Func[aCfgData->ucReadFunctionIndex].pReadDataSint8Func((sint8*)anOutputBuffer);  
        }
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT16:
        if (NULL_PTR != Dcm_GaaSigReadWriteSint16Func[aCfgData->ucReadFunctionIndex].pReadDataSint16Func)
        {
          retVal = Dcm_GaaSigReadWriteSint16Func[aCfgData->ucReadFunctionIndex].pReadDataSint16Func((sint16*)anOutputBuffer);
        }  
        break;
      #endif

      #if(DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON)        
      case DCM_DSP_DATA_TYPE_SINT32:
        if (NULL_PTR != Dcm_GaaSigReadWriteSint32Func[aCfgData->ucReadFunctionIndex].pReadDataSint32Func)
        {
          retVal = Dcm_GaaSigReadWriteSint32Func[aCfgData->ucReadFunctionIndex].pReadDataSint32Func((sint32*)anOutputBuffer);
        }
        break;
      #endif
      
      default:
        retVal = E_NOT_OK;      
        break;
    }
    #endif
  }

  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CfgInternal_GetDIDRangeConfig                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used to read DidRange informations **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LusDIDIndex                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_DIDRangeConfig                                  **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) : Dcm_Num_Of_DcmDspDidRangeConfig**
**                                                                            **
*******************************************************************************/
#if(DCM_DIDSERVICE_SUPPORT_ENABLE == STD_ON)
FUNC(P2VAR(Dcm_DIDRangeConfig, AUTOMATIC, DCM_APPL_DATA), DCM_CODE)
  Dcm_CfgInternal_GetDIDRangeConfig(uint16 LusDIDIndex)
{
  P2VAR(Dcm_DIDRangeConfig, AUTOMATIC, DCM_APPL_DATA)pDIDRangeConfig = NULL_PTR;

  #if (DCM_NUM_OF_DCMDSPDIDRANGECONFIG != DCM_ZERO)
  if(LusDIDIndex < Dcm_Num_Of_DcmDspDidRangeConfig)
  {
    pDIDRangeConfig = &Dcm_GaaDcmDspDIDRangeConfig[LusDIDIndex];
  }
  #else
  DCM_UNUSED(LusDIDIndex);
  #endif

  return pDIDRangeConfig;
}
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

