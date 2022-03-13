/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm                                              **
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
** 1.0.2     03-03-2016    Sungeol Baek   MISRA rule modification             **
**                                                                            **
** 1.0.1     16-04-2015    Sungeol Baek   #2171                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_H
#define DCM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Cfg.h"
#if(DCM_USE_ECU_SIGNAL_ENABLED == STD_ON)
#include "IoHwAb.h"
#endif
#include "Dcm_Cbk.h"
#include "Dcm_Types.h"    /* [Dcm055] */
#include "Rte_Dcm_Type.h" /* [Dcm055] */

#if(DCM_DLT_USE_FUNC == STD_ON)
#include "Dlt.h"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> Prototype of this function is made in other header file(Rte_*.h) which can not be included here because of Autosar Requiremtns */


#define DCM_INSTANCE_ID                                              ((uint8)0x00)

/* Service Id of Dcm_Init */
#define DCM_INIT_SID                                                 ((uint8)0x01)

/* Service Id of Dcm_GetVersionInfo */
#define DCM_GET_VERSION_INFO_SID                                     ((uint8)0x24)

/* Service Id of Dcm_DemTriggerOnDTCStatus */
#define DCM_DEM_TRIGGER_ONDTC_STATUS_SID                             ((uint8)0x2B)

/* Dcm_<ModeName>ModeEntry needs to be updated */
#define DCM_MODENAMEMODEENTRY_SID                                    ((uint8)0x2C)

/*******************************************************************************
**                     Functions provided to BSW modules and to SW-Cs         **
*******************************************************************************/

/* Service Id of Dcm_GetSecurityLevel */
#define DCM_GET_SECURITY_LEVEL_SID                                   ((uint8)0x0D)

/* Service Id of Dcm_GetSesCtrlType */
#define DCM_GET_SES_CTRL_TYPE_SID                                    ((uint8)0x06)

/* Service Id of Dcm_GetActiveProtocol */
#define DCM_GET_ACTIVE_PROTOCOL_SID                                  ((uint8)0x0F)

/* Service Id of Dcm_ResetToDefaultSession */
#define DCM_RESET_TO_DEFAULTSESSION_SID                              ((uint8)0x2A)

/* Service Id of Dcm_TriggerOnEvent */
#define DCM_TRIGGER_ON_EVENT_SID                                     ((uint8)0x2D)

/*******************************************************************************
**                     Callback Notifications                                 **
*******************************************************************************/

/* Service Id of Dcm_StartOfReception */
#define DCM_START_OF_RECEPTION_SID                                   ((uint8)0x00)

/* Service Id of Dcm_CopyRxData */
#define DCM_COPY_RXDATA_SID                                          ((uint8)0x02)

/* Service Id of Dcm_TpRxIndication */
#define DCM_RX_INDICATION_SID                                        ((uint8)0x03)

/* Service Id of Dcm_CopyTxData */
#define DCM_COPY_TXDATA_SID                                          ((uint8)0x04)

/* Service Id of Dcm_TpTxConfirmation */
#define DCM_TX_CONFIRMATION_SID                                      ((uint8)0x05)

/* Service Id of Dcm_ComM_NoComModeEntered */
#define DCM_COMM_NO_COM_MODE_ENTERED_SID                             ((uint8)0x21)

/* Service Id of Dcm_ComM_SilentComModeEntered */
#define DCM_COMM_SILENT_COM_MODE_ENTERED_SID                         ((uint8)0x22)

/* Service Id of Dcm_ComM_FullComModeEntered */
#define DCM_COMM_FULL_COM_MODE_ENTERED_SID                           ((uint8)0x23)

/* Added service id by youngjin.yun ,2014-12-13 */
#define DCM_SYNC_READ_DATA_SID                                       ((uint8)0x34)
#define DCM_SYNC_WRITE_DATA_SID                                      ((uint8)0x35)

#define DCM_READ_DATA_LENGTH_SID                                     ((uint8)0x36)
#define DCM_CONDITION_CHECK_READ_SID                                 ((uint8)0x37)

#define DCM_ASYNC_READ_DATA_SID                                      ((uint8)0x3B)
#define DCM_ASYNC_WRITE_DATA_SID                                     ((uint8)0x3E)

#define DCM_VARIANT_FUNC_SID                                         ((uint8)0x40)


/*******************************************************************************
**                     Callout Definitions                                    **
*******************************************************************************/

/* Service Id of Dcm_ReadMemory */
#define DCM_READ_MEMORY_SID                                          ((uint8)0x26)

/* Service Id of Dcm_WriteMemory */
#define DCM_WRITE_MEMORY_SID                                         ((uint8)0x27)

/* Dcm_<DiagnosticService> needs to be done */

/* Service Id of Dcm_Confirmation */
#define DCM_CONFIRMATION_SID                                         ((uint8)0x29)

/*******************************************************************************
**                     Scheduled Functions                                    **
*******************************************************************************/

/* Service Id of Dcm_MainFunction */
#define DCM_MAIN_FUNCTION_SID                                        ((uint8)0x25)

typedef struct STagDcm_ConfigType
{
  uint8 LucVar;
}Dcm_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(boolean, DCM_CODE) Dcm_DemGetInternalTroubleCodeServiceMode(void);

/*******************************************************************************
**                            Initialization                                  **
*******************************************************************************/
extern FUNC(void, DCM_CODE) Dcm_Init
(P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_APPL_CONST) ConfigPtr);


/*******************************************************************************
**                             Version handling                               **
*******************************************************************************/
#if(DCM_VERSION_INFO_API == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versioninfo);
#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_PERIODIC_DID_MainFunction (void);
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_ROE_MainFunction(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DemTriggerOnDTCStatus( \
                       uint32 DTC, uint8 DTCStatusOld, uint8 DTCStatusNew);
#endif

/*******************************************************************************
**                               DCM Serivces                                 **
*******************************************************************************/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel
    (P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType
    (P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetActiveProtocol
    (P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA)ActiveProtocol);

extern FUNC(Std_ReturnType, Dcm_CODE)Dcm_ResetToDefaultSession(void);

/*******************************************************************************
**                             Callout functions                              **
*******************************************************************************/

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/* polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> Prototype of this function is made in other header file(Rte_*.h) which can not be included here because of Autosar Requiremtns */

#endif /* DCM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
