/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Provision of Dcm type definitions                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date         By                 Description                      **
********************************************************************************
** 1.0.10    05-06-2017   Jin     Jung       #8760                            **
**                                                                            **
** 1.0.9     30-05-2017   Jin     Jung       #8656                            **
**                                                                            **
** 1.0.8     28-03-2017   Jin     Jung       #7631                            **
**                                                                            **
** 1.0.7     15-02-2017   Jin     Jung       #5460                            **
**                                                                            **
** 1.0.6     16-11-2016   Jin     Jung       #6609                            **
**                                                                            **
** 1.0.5     30-06-2016   Jin     Jung       #5367                            **
**                                                                            **
** 1.0.4     10-08-2015   Youngjin Yun       #2977                            **
**                                                                            **
** 1.0.3     16-07-2015   Sungeol Baek       #2678                            **
**                                                                            **
** 1.0.2     04-03-2015   YoungJin Yun       #1689                            **
**                                                                            **
** 1.0.1     26-02-2015   YoungJin Yun       #1044                            **
**                                                                            **
** 1.0.0     09-01-2013   Autron             Initial Version                  **
*******************************************************************************/

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ComStack_Types.h"
#include "Rte_Dcm_Type.h"
#include "Dcm_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                Additional information on message request                   **
*******************************************************************************/

/*******************************************************************************
**                     Std_ReturnType                                         **
*******************************************************************************/
#ifndef DCM_E_PENDING
#define DCM_E_PENDING                                                     (0x0Au)
#endif

#ifndef DCM_E_FORCE_RCRRP
#define DCM_E_FORCE_RCRRP                                                 (0x0Cu)
#endif

#ifndef DCM_E_RESPONSEPENDING
#define DCM_E_RESPONSEPENDING                                             (120U)
#endif /*DCM_E_RESPONSEPENDING*/

/* Hyundai autron specific */
#define DCM_E_NO_DID                                                      (70u)

/*******************************************************************************
**                     DCM_STANDARD_SUPPORT Parameter                         **
*******************************************************************************/
#ifndef DCM_ISO14229_SUPPORT
#define DCM_ISO14229_SUPPORT                                              0x00u
#endif
#ifndef DCM_ES95486_SUPPORT
#define DCM_ES95486_SUPPORT                                               0x01u
#endif
#ifndef DCM_ES96590_SUPPORT
#define DCM_ES96590_SUPPORT                                               0x02u
#endif

#define DCM_BUFSZ_TESTERPRESENT                                           0x08U

#define DCM_ASYNC_DONE                                                    (DCM_FALSE)
#define DCM_SYNC_DONE                                                     (DCM_TRUE)

/*******************************************************************************
**                     Macros for ReadDataByIdentifier                        **
*******************************************************************************/
/* header size of DynamicallyDefinedDataIdentifier(defineByMemoryAddress) */
#define DCM_SIZEOF_DDID_ALF                                                   4u

#define DCM_SIZEOF_DATAID                                                     2u /* size of data identifier */
#define DCM_SIZEOF_PDATAID                                                    1u /* size of periodic data identifier */


/* ucSignalTypeorSize: This variable represents signal type or size of the signal. 
  Higher nibble represents the type of the signal and Lower nibble represents the 
  size of the signal that is spread across I-PDU. 
  0x11     8 bit signal pack into one byte       uint8
  0x12     8 bit signal pack into two byte       uint8
  0x22    16 bit signal pack into two byte       uint16
  0x23    16 bit signal pack into three byte     uint16
  0x44    32 bit signal pack into four byte      uint32
  0x45    32 bit signal pack into five byte      uint32
  0x50    greater than 32 (ext) Client Servicer
*/

#define   DCM_DATA_TYPE_CSIF_GT32                                          0x5u
#define   DCM_DATA_TYPE_32PACK_5B                                          0x4u
#define   DCM_DATA_TYPE_32PACK_4B                                          0x4u
#define   DCM_DATA_TYPE_16PACK_3B                                          0x2u
#define   DCM_DATA_TYPE_16PACK_2B                                          0x2u
#define   DCM_DATA_TYPE_8PACK_2B                                           0x1u

/* Macro for service Tester Present */
#define DCM_TP_ZEROSUBFUNCTION                                             0x80u
 

#define DCM_RDTCI_REPORT_DTCSNAPSHOTRECORD_BY_DTCNUMBER                    0x04u
#define DCM_RDTCI_REPORT_DTCEXTDATARECORD_BY_DTCNUMBER                     0x06u
#define DCM_RDTCI_REPORT_MIRRORMEMORY_DTCEXTDATARECORDBY_DTCNUMBER         0x10u
#define DCM_RDTCI_REPORT_NUMBEROFDTC_BY_SEVERITYMASKRECORD                 0x07u




/*******************************************************************************
**                     ReadITCInformation                                     **
*******************************************************************************/

#define DCM_ITC_STATUS_MASK                                                 0x08u

/*******************************************************************************
**                     Dcm_CommunicationModeType                              **
*******************************************************************************/

#ifdef DCM_ENABLE_RX_TX_NORM
#define DCM_SWCGEN  
#endif

#ifdef DCM_SWCGEN
/* Response pending Message */
#define DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING                     (0x78U)
#endif 

#ifndef DCM_SWCGEN
/* CommunicationModeType type definition */
typedef uint8 Dcm_CommunicationModeType;

/* Enable the Rx and Tx for normal communication */
#define DCM_ENABLE_RX_TX_NORM                    ((Dcm_CommunicationModeType)0x00)

/* Enable the Rx and disable the Tx for normal communication */
#define DCM_ENABLE_RX_DISABLE_TX_NORM            ((Dcm_CommunicationModeType)0x01)

/* Disable the Rx and enable the Tx for normal communication */
#define DCM_DISABLE_RX_ENABLE_TX_NORM            ((Dcm_CommunicationModeType)0x02)

/* Disable Rx and Tx for normal communication */
#define DCM_DISABLE_RX_TX_NORMAL                 ((Dcm_CommunicationModeType)0x03)
#define DCM_DISABLE_RX_TX_NORM                   ((Dcm_CommunicationModeType)0x03)

/* Enable the Rx and Tx for network management communication */
#define DCM_ENABLE_RX_TX_NM                      ((Dcm_CommunicationModeType)0x04)

/* Enable Rx and disable the Tx for network management communication */
#define DCM_ENABLE_RX_DISABLE_TX_NM              ((Dcm_CommunicationModeType)0x05)

/* Disable the Rx and enable the Tx for network management communication */
#define DCM_DISABLE_RX_ENABLE_TX_NM              ((Dcm_CommunicationModeType)0x06)

/* Disable Rx and Tx for network management communication */
#define DCM_DISABLE_RX_TX_NM                     ((Dcm_CommunicationModeType)0x07)

/* Enable Rx and Tx for normal and network management communication */
#define DCM_ENABLE_RX_TX_NORM_NM                 ((Dcm_CommunicationModeType)0x08)

/* Enable the Rx and disable the Tx for normal and network
 *  management communication
 */
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM         ((Dcm_CommunicationModeType)0x09)

/* Disable the Rx and enable the Tx for normal
 * and network management communication
 */
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM         ((Dcm_CommunicationModeType)0x0A)

/* Disable Rx and Tx for normal and network management communication */
#define DCM_DISABLE_RX_TX_NORM_NM                ((Dcm_CommunicationModeType)0x0B)
#endif

#define DCM_COMMUNICATIONMODETYPE_UNDEFINED                                 0xFFu


/*******************************************************************************
**                CommunicationControlService  for ES95486                    **
*******************************************************************************/
#define DCM_CC_ENABLE_RX_AND_TX                                     ((uint8)0x00u)
#define DCM_CC_DIABLE_NM_TRANS                                      ((uint8)0x01u)
#define DCM_CC_DIABLE_NM_TRANS_NORESP                               ((uint8)0x02u)
#define DCM_CC_DISABLE_RX_AND_TX                                    ((uint8)0x03u)

/* CommnuicationType */
#define DCM_COMM_TYPE_NORMAL                                        ((uint8)0x01u)
#define DCM_COMM_TYPE_NM                                            ((uint8)0x02u)
#define DCM_COMM_TYPE_NM_AND_NORMAL                                 ((uint8)0x03u)


typedef uint8 Dcm_ModeType;


/*******************************************************************************
**                ClearDiagnosticInformation                                  **
*******************************************************************************/

#define DCM_DTCGROUP_ALL_GROUPS     0xFFFFFFu
#define DCM_DTCGROUP_CHASSIS_GROUP  0x4000FFu


/*******************************************************************************
**                Dcm_ReturnReadMemoryType                                    **
*******************************************************************************/

#ifndef DCM_SWCGEN
/* Return values of Callout Dcm_ReadMemory */
typedef uint8 Dcm_ReturnReadMemoryType;

/* Reading has been done */
#define DCM_READ_OK                               ((Dcm_ReturnReadMemoryType)0x00)

/* Reading is pending, another call is request to finalize the reading */
#define DCM_READ_PENDING                          ((Dcm_ReturnReadMemoryType)0x01)

/* Reading has failed */
#define DCM_READ_FAILED                           ((Dcm_ReturnReadMemoryType)0x02)

#define DCM_READ_FORCE_RCRRP                      ((Dcm_ReturnReadMemoryType)0x03)

/*******************************************************************************
**                Dcm_ReturnWriteMemoryType                                   **
*******************************************************************************/

/* Return type of callout Dcm_WriteMemory */
typedef uint8 Dcm_ReturnWriteMemoryType;

/* Writing has been done */
#define DCM_WRITE_OK                             ((Dcm_ReturnWriteMemoryType)0x00)

/* Writing is pending, another called is requested */
#define DCM_WRITE_PENDING                        ((Dcm_ReturnWriteMemoryType)0x01)

/* The writing has failed */
#define DCM_WRITE_FAILED                         ((Dcm_ReturnWriteMemoryType)0x02)

#define DCM_WRITE_FORCE_RCRRP                    ((Dcm_ReturnWriteMemoryType)0x03)

/*******************************************************************************
**                Dcm_EcuStartModeType                                        **
*******************************************************************************/

/* Allows the DCM to know if a diagnostic response shall be sent in the case
 * of a jump from bootloader
 */
typedef uint8 Dcm_EcuStartModeType;

/* The ECU starts normally */
#define DCM_COLD_START                                ((Dcm_EcuStartModeType)0x00)

/* The ECU starts from a bootloader jump */
#define DCM_WARM_START                                ((Dcm_EcuStartModeType)0x01)

/*******************************************************************************
**                      Dcm_StatusType                                        **
*******************************************************************************/
/* Base item type to transport status information */
typedef uint8 Dcm_StatusType;

/* This value is representing a successful operation */
#define DCM_E_OK                                                     ((uint8)0x00)

/* When comparison fails this definition is used */
#define DCM_E_COMPARE_KEY_FAILED                                     ((uint8)0x01)

/*
 * New timing parameters are not ok, since requested values are not within
 * the defined limits.
 */
#define DCM_E_TI_PREPARE_LIMITS                                      ((uint8)0x02)

/* New timing parameter are not ok, since requested values are not consistent */
#define DCM_E_TI_PREPARE_INCONSTENT                                  ((uint8)0x03)

/* Application does not allow start of requested session */
#define DCM_E_SESSION_NOT_ALLOWED                                    ((uint8)0x04)

/* Application does not allow start of requested protocol */
#define DCM_E_PROTOCOL_NOT_ALLOWED                                   ((uint8)0x05)

/* ResponseOnOneEvent request is not accepted by DCM */
#define DCM_E_ROE_NOT_ACCEPTED                                       ((uint8)0x06)

/* Periodic transmission request is not accepted by DCM */
#define DCM_E_PERIODICID_NOT_ACCEPTED                                ((uint8)0x07)

/* Application rejects diagnostic request */
#define DCM_E_REQUEST_NOT_ACCEPTED                                   ((uint8)0x08)

/*
 * Diagnostic request is not allowed by application because of not fitting
 * environmental conditions
 */
#define DCM_E_REQUEST_ENV_NOK                                       ((uint8)0x09)
#endif

/* #5246, #5367, #6609 : if macro is not defined in Std_Type.h */
#ifndef E_REQUEST_NOT_ACCEPTED
#define E_REQUEST_NOT_ACCEPTED                                       ((uint8)0x08)
#endif

/* Macro to get PID */
#define DCM_GET_PID                                                 ((uint8)0x00)

/* Macro to get TID */
#define DCM_GET_TID                                                 ((uint8)0x02)

/* Macro to get OBDMID */
#define DCM_GET_OBDMID                                              ((uint8)0x01)

/* Macro to get InfoType */
#define DCM_GET_VID                                                 ((uint8)0x03)

/* Macro to other PID  */
#define DCM_OTHER_PID                                               ((uint8)0x04)

/* Macro to TWO PID  */
#define DCM_TWO_PID                                                 ((uint8)0x08)

/* Macro to identify DID  */
#define DCM_GET_DID                                                 ((uint16)0x00)

/* Macro to identify RID  */
#define DCM_GET_RID                                                 ((uint16)0x01)

/* DTC Translation type */
#define DCM_FORMAT_IDENTIFIER_15031_6                               ((uint8)0x00)
#define DCM_FORMAT_IDENTIFIER_14229_1                               ((uint8)0x01)

/* Value of Status Mask All */
#define DCM_STATUS_MASK_ALL                                         ((uint8)0x00)

/* Value of service id of OBD */
#define DCM_OBD_NO_SID                                              ((uint8)0xFF)

/* Value of DTC All */
#define DCM_DTC_ALL                                         ((uint32)0x00000000UL)

/* Numerical macros */
#define DCM_ZERO                                                     0x00u
#define DCM_ONE                                                      ((uint8)0x01)
#define DCM_TWO                                                      ((uint8)0x02)
#define DCM_THREE                                                    ((uint8)0x03)
#define DCM_FOUR                                                     ((uint8)0x04)
#define DCM_FIVE                                                     ((uint8)0x05)
#define DCM_SIX                                                      ((uint8)0x06)
#define DCM_SEVEN                                                    ((uint8)0x07)
#define DCM_EIGHT                                                    ((uint8)0x08)
#define DCM_NINE                                                     ((uint8)0x09)
#define DCM_TEN                                                      ((uint8)0x0A)
#define DCM_ELEVEN                                                   ((uint8)0x0B)
#define DCM_TEWELVE                                                  ((uint8)0x0C)
#define DCM_THIRTEEN                                                 ((uint8)0x0D)
#define DCM_FOURTEEN                                                 ((uint8)0x0E)
#define DCM_FIFTEEN                                                  ((uint8)0x0F)
#define DCM_THIRTY_TWO                                               ((uint8)0x20)
#define DCM_SIXTY_FOUR                                               ((uint8)0x40)
#define DCM_NINTY_SIX                                                ((uint8)0x60)
#define DCM_ONE_TWO_EIGHT                                            ((uint8)0x80)
#define DCM_ONE_SIXTY                                                ((uint8)0xA0)
#define DCM_ONE_NINE_TWO                                             ((uint8)0xC0)
#define DCM_TWO_TWO_FOUR                                             ((uint8)0xE0)
#define DCM_SIXTEEN                                                  ((uint8)0x10)
#define DCM_TWENTY                                                   ((uint8)0x14)
#define DCM_NINETEEN                                                 ((uint8)0x13)
#define DCM_TWENTYONE                                                ((uint8)0x15)
#define DCM_SEVENTEEN                                                ((uint8)0x11)
#define DCM_EIGHTTEEN                                                ((uint8)0x12)
#define DCM_MAXVALUE                                                 ((uint8)0xFF)
#define DCM_TWENTYFOUR                                               ((uint8)0x18)
#define DCM_ONE_UINT32                                              ((uint32)0x01)
#define DCM_THREE_UINT16                                            ((uint16)0x03)

#define DCM_PERIODICRESPONSE_ID                                      ((uint8)0x6A)

#define DCM_ROUTINE_START_MASK                                       ((uint8)0xF0)
#define DCM_ROUTINE_STOP_MASK                                        ((uint8)0xFF)

#define DCM_AND                                                      ((uint8)0x00)
#define DCM_OR                                                       ((uint8)0x01)
#define DCM_EQUALS                                                   ((uint8)0x00)
#define DCM_UNEQUAL                                                  ((uint8)0x01)

#define DCM_SIG_SIZE_MASK_VALUE                                      ((uint8)0xF0)
#define DCM_SIG_BYTE_MASK_VALUE                                      ((uint8)0x0F)
#define DCM_SINT16_SIZE_MASK_VALUE                                   ((uint16)0xFF00)

/* Added by youngjin.yun, 2015-01-05*/
#define DCM_U16_LSB_MASK                                             ((uint16)0x00FF)
#define DCM_U16_MSB_MASK                                             ((uint16)0xFF00)

/* Added by youngjin.yun, 2015-01-05*/
#define DCM_U8_HLSB_MASK                                             ((uint16)0x00FF)
#define DCM_U8_MSB_MASK                                              ((uint16)0xFF00)

#define DCM_HI_NIBBLE(b, type)                                       ((type)(( ((type)(b)) >> 4U) & (type)0x0FU))
#define DCM_LO_NIBBLE(b, type)                                       ((type)(  ((type)(b)) & (type)0x0FU))

#define DCM_U16_HI_BYTE(b)                                           ((uint8)(((b) >> 8U) & 0xFFU))
#define DCM_U16_LO_BYTE(b)                                           ((uint8)((b) & 0xFFU))

#define DCM_8B_ALIGN(b)                                              (((b) + 7)/8)

#define DCM_DTC_SEV_MASK                                             0xE0

/* ES95476
F200-F2FF  Reserved : Periodic Data Identifier, Dynamically Defined Data Identifier
F300-F3FF  Reserved : Dynamically Defined Data Identifier
 */
#define DCM_DYNAMICID_LOWER_RANGE                                 ((uint16)0xF200)
#define DCM_DYNAMICID_UPPER_RANGE                                 ((uint16)0xF3FF)


#define DCM_READDATABYID_F186                                     ((uint16)0xF186)

#define DCM_OBDDID_LOWER_RANGE                                    ((uint16)0xF400)
#define DCM_OBDDID_RANGE_F4FF                                     ((uint16)0xF4FF)
#define DCM_OBDDID_RANGE_F600                                     ((uint16)0xF600)
#define DCM_OBDDID_RANGE_F6FF                                     ((uint16)0xF6FF)
#define DCM_OBDDID_RANGE_F800                                     ((uint16)0xF800)
#define DCM_OBDDID_UPPER_RANGE                                    ((uint16)0xF8FF)

#define DCM_DID_RANGE_F1FF                                        ((uint16)0xF1FF)
#define DCM_DID_RANGE_FEFF                                        ((uint16)0xFEFF)

#define DCM_TYPE_8                                                      ((uint8)0)
#define DCM_TYPE_16                                                     ((uint8)1)

#define DCM_SIZE_8                                                   ((uint8)0x10)
#define DCM_SIZE_16                                                  ((uint8)0x20)

#define DCM_DEMPID1                                                  ((uint8)0x01)
#define DCM_DEMPID1C                                                 ((uint8)0x1C)
#define DCM_DEMPID21                                                 ((uint8)0x21)
#define DCM_DEMPID30                                                 ((uint8)0x30)
#define DCM_DEMPID31                                                 ((uint8)0x31)
#define DCM_DEMPID41                                                 ((uint8)0x41)
#define DCM_DEMPID4D                                                 ((uint8)0x4D)
#define DCM_DEMPID4E                                                 ((uint8)0x4E)

/* Macro value for service Read and Write  */
typedef uint8 Dcm_DidType;
#define DCM_DYN_ID                                                   ((uint8)0x00) 
#define DCM_OBD_ID                                                   ((uint8)0x01)  
#define DCM_NONOBD_ID                                                ((uint8)0x02)
#define DCM_DIDTYPE_DIDRANGE                                         ((uint8)0x03)
#define DCM_DIDTYPE_SESSION                                          ((uint8)0x04)
#define DCM_DIDTYPE_NO_TYPE                                          ((uint8)0x05)


#define DCM_SESSION_JUMPTOBOOTLOADER                                  0x01u
#define DCM_SESSION_JUMPTOSYSSUPPLIERBOOTLOADER                       0x02u


/*
DCM_INITIAL 0x00 
Indicates the initial call to the operation 

DCM_PENDING 0x01 
Indicates that a pending return has been done on 
the previous call of the operation 

DCM_CANCEL 0x02 
Indicates that the DCM requests to cancel the 
pending operation 

DCM_FORCE_RCRRP_OK 0x03 
Confirm a response pending transmission 
*/
/* Macro value for DID read / write operations status  */
#define DCM_OPSTATUS_INITIAL                                          (DCM_ZERO)
#define DCM_OPSTATUS_COMPLETE                                         (DCM_ONE)
#define DCM_OPSTATUS_PENDING                                          (DCM_TWO)





/* Enable the Rapid power shutdown */
#define DCM_ENABLE_RAPID_POWER_SHUTDOWN_RESET                        ((uint8)0x04)

/* Disable the Rapid power shutdown */
#define DCM_DISABLE_RAPID_POWER_SHUTDOWN_RESET                       ((uint8)0x05)


/* DcmEcuReset type definition */
typedef uint8 DcmEcuResetType;

#define NONE                                               ((DcmEcuResetType)0x00)
#define HARD                                               ((DcmEcuResetType)0x01)
#define KEYONOFF                                           ((DcmEcuResetType)0x02)
#define SOFT                                               ((DcmEcuResetType)0x03)
#define JUMPTOBOOTLOADER                                   ((DcmEcuResetType)0x04)
#define JUMPTOSYSSUPPLIERBOOTLOADER                        ((DcmEcuResetType)0x05)
#define EXECUTE                                            ((DcmEcuResetType)0x06)

/* DcmEcuReset type definition */
typedef uint8 DcmModeRapidPowerShutDownType;

#define ENABLE_RAPIDPOWERSHUTDOWN            ((DcmModeRapidPowerShutDownType)0x00)
#define DISABLE_RAPIDPOWERSHUTDOWN           ((DcmModeRapidPowerShutDownType)0x01)

#define ENABLEDTCSETTING                                             ((uint8)0x01)
#define DISABLEDTCSETTING                                            ((uint8)0x02)

/* Following macro IO control */
#define DCM_CTRL_RET_CTRL_ECU                                        (DCM_ZERO)
#define DCM_CTRL_RST_TO_DFLT                                         (DCM_ONE)
#define DCM_CTRL_FRZ_CUR_STATE                                       (DCM_TWO)
#define DCM_CTRL_SHRT_TRM_ADJ                                        (DCM_THREE)

/* Following macro Routine control */
#define DCM_ROUTINE_CTRL_START                                       (DCM_ONE)
#define DCM_ROUTINE_CTRL_STOP                                        (DCM_TWO)
#define DCM_ROUTINE_CTRL_REQUEST_RESULT                              (DCM_THREE)


/* Following macro specifies the different functions in the OBD service 01 */
/* ID related to Availability list */
#define DCM_AVAIL_ID                                                 (DCM_ZERO)

/* ID related to Dem */
#define DCM_DEM_PID                                                  (DCM_ONE)

/* ID related to R-Port */
#define DCM_R_PORT_PID                                               (DCM_TWO)

/* Search macros */
#define DCM_NOT_CONFIG_ID                                            (DCM_FIVE)

/* Boolean macros */
#define DCM_FALSE                                                    (DCM_ZERO)
#define DCM_TRUE                                                     (DCM_ONE)
#define DCM_UNINITIALISED                                            (DCM_FALSE)
#define DCM_INITIALISED                                              (DCM_TRUE)

/*  Macro ID For response */
#define DCM_RESPONSE_ID                                              ((uint8)0x40)
#define DCM_SID_MASK                                                 ((uint8)0xBF) /* (~DCM_RESPONSE_ID) */



/* Macros for Timer Indexes */
#define DCM_MAX_TIMERS                                               ((uint8)9)
#define DCM_P2SERVERMIN_TIMER                                        ((uint8)0)
#define DCM_P2SERVERMAX_TIMER                                        ((uint8)1)
#define DCM_S3SERVER_TIMER                                           ((uint8)2)
#define DCM_PAGED_BUFFER_TIMER                                       ((uint8)3)
#define DCM_PROTOCOL_PREEMPT_TIMER                                   ((uint8)4)
#define DCM_SECURITY_TIMER                                           ((uint8)5)
#define DCM_ROE_INTERMESSAGE_TIMER                                   ((uint8)6)

/* Macros for Read DTC service */
#define DCM_REP_NUMOFDTC_BY_STATUSMASK                               ((uint8)0x01)
#define DCM_REP_NUMOFDTC_BY_SEVERITYMASK                             ((uint8)0x07)
#define DCM_REP_NUMOFMMDTC_BY_STATUSMASK                             ((uint8)0x11)
#define DCM_REP_NUMOFEMIOBDDTC_BY_STATUSMASK                         ((uint8)0x12)

#define DCM_RD_ALL_SUPPORTED_DTC                                     ((uint8)0x0A)
#define DCM_RD_MIRROR_MEM_BYDTCMASK                                  ((uint8)0x0F)
#define DCM_DSP_EMI_OBD_DTC_SUBFCT                                   ((uint8)0x13)
#define DCM_DSP_PERMNT_STATUS_SUBFCT                                 ((uint8)0x15)
#define DCM_DSP_MAX_SUBFCT                                           ((uint8)0x16)
#define DCM_DSP_ORG_MASK                                             ((uint8)0x10)
#define DCM_RD_SSRECBYREC_FCTMASK                                    ((uint8)0x05)
#define DCM_DSP_FFSIZE_FCTMASK                                       ((uint8)0x06)
#define DCM_FAILED_CONFMD_IDX                                        ((uint8)0x0B)
#define DCM_RD_SSRECBYDTC_FCTMASK                                    ((uint8)0x04)
#define DCM_RD_SUPPORTED_DTC_FCTMASK                                 ((uint8)0x02)

/* General Macros*/
#define DCM_MAX_RECDDATA_SIZE                                        ((uint8)0xFF)
#define DCM_MAX_EXTND_RECORDS                                        ((uint8)0xFF)
#define DCM_SUBFUNCTION_MASK                                         ((uint8)0x7F)
#define DCM_SUPRESSBIT_MASK                                          ((uint8)0x80)
#define DCM_MAX_RECORDS                                              ((uint8)0xFE)
#define DCM_START_MAX_RECORDS                                        ((uint8)0x90)
#define DCM_MOD_VALUE                                                ((uint8)0x22)
#define DCM_RD_DTCSVTY_FCTMASK                                       ((uint8)0x08)

#define DCM_DTRSTATUS_VISIBLE                                        ((uint8)0x00)

/* DSL Macros */
#define DCM_HBYTE_PERIODICID                                         ((uint8)0xF2)

/* DSP Macros*/
#define DCM_BIT6_AND_MASK                                            ((uint8)0xBF)
#define DCM_BIT0_AND_MASK                                            ((uint8)0x01)

#define DCM_DIAG_SESSION                                             ((uint8)0x50)
#define DCM_READDTC_SERVICE                                          ((uint8)0x59)
#define DCM_ECU_SERVICE                                              ((uint8)0x51)
#define DCM_COMMUNICATION_SERVICE                                    ((uint8)0x68)
#define DCM_ENABLE_NORMAL_MESG_TRANSMISSION_SERVICE                  ((uint8)0x69)
#define DCM_STOP_DIAGNOSTIC_SESSION                                  ((uint8)0x60)
#define DCM_LINKCONTROL_SERVICE                                      ((uint8)0xC7)
#define DCM_CONTROLDTC_SETTING                                       ((uint8)0xC5)

/* Internal DTC Diagnostic Service support */
#define DCM_READ_ITC_SERVICE                                         ((uint8)0xBA)
#define DCM_CLEAR_ITC_SERVICE                                        ((uint8)0xBB)

#define DCM_SERVICE_NOT_CONFIGURED                                   ((uint8)0xFF)
#define DCM_ADDR_FUNCTIONAL                                          ((uint8)0x01)
#define DCM_ADDR_PHYSICAL                                            ((uint8)0x00)
#define DCM_NEGATIVE_RESPONSE_SID                                    ((uint8)0x7F)

#define DCM_FULL_COMMUNICATION                                       ((uint8)0x00)
#define DCM_SILENT_COMMUNICATION                                     ((uint8)0x01)
#define DCM_NO_COMMUNICATION                                         ((uint8)0x02)

#define Dcm_DspStartProtocol() \
 do {\
  Dcm_GucFailedSecurityAccessCount = DCM_ZERO;\
  Dcm_DspSerPgStatus.ucDemDisableInvoked = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucLastPage = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucUpdatePageStarted = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucPagingStarted = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucFirstPage = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucPagingInMid = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucMultipleRecd = DCM_FALSE;\
  Dcm_DspSerPgStatus.ucSecSeedReq = DCM_FALSE;\
} while(0)



/*Macros for DcmDspDataUsePort*/
#define DCM_USEBLOCKID                                               ((uint8)0x00)
#define DCM_USEECUSIGNAL                                             ((uint8)0x01)
#define DCM_USE_DATA_ASYNCH_CLIENT_SERVER                            ((uint8)0x02)
#define DCM_USE_DATA_SYNCH_CLIENT_SERVER                             ((uint8)0x03)
#define DCM_USE_DATA_SENDER_RECEIVER                                 ((uint8)0x04)
#define DCM_USE_DATA_SYNCH_FNC                                       ((uint8)0x05)
#define DCM_USE_DATA_ASYNCH_FNC                                      ((uint8)0x06)
/* Macros for DcmDspDataUsePort in PID Configuration */
#define DCM_OBD_SENDER_RECEIVER                                      ((uint8)0x02)
#define DCM_OBD_SYNCH_CLIENT_SERVER                                  ((uint8)0x01)
#define DCM_OBD_SYNCHCLIENT_FNC                                      ((uint8)0x00)

#define DCM_NO_BOOT                                                  ((uint8)0x00)
#define DCM_OEM_BOOT                                                 ((uint8)0x01)
#define DCM_SYS_BOOT                                                 ((uint8)0x02)

/*Macros for DcmDspDataType*/
#define DCM_DSP_DATA_TYPE_BOOLEAN                                                      ((uint8)0x00)
#define DCM_DSP_DATA_TYPE_SINT16                                                       ((uint8)0x01)
#define DCM_DSP_DATA_TYPE_SINT32                                                       ((uint8)0x02)
#define DCM_DSP_DATA_TYPE_SINT8                                                        ((uint8)0x03)
#define DCM_DSP_DATA_TYPE_UINT16                                                       ((uint8)0x04)
#define DCM_DSP_DATA_TYPE_UINT32                                                       ((uint8)0x05)
#define DCM_DSP_DATA_TYPE_UINT8                                                        ((uint8)0x06)

#define DCM_PERODIC_SLOWRATE_TM                                             0x01u
#define DCM_PERODIC_MEDIUMRATE_TM                                           0x02u
#define DCM_PERODIC_FASTRATE_TM                                             0x03u
#define DCM_PERODIC_STOP_TM                                                 0x04u

/* Following macro Read Data by Periodic ID */
#define DCM_STOP_SENDING                                                    0x04u
#define DCM_PERIODIC_ID_F200                                                ((uint16)0xF200u)
#define DCM_PER_DATA_IDLE                                                   0x00u
#define DCM_PER_DATA_READY                                                  0x01u
#define DCM_PER_DATA_BUSY                                                   0x02u

/* Following macros for Read Data By Periodic ID */
#define DCM_PERIODIC_SLOW_TIMER                                         ((uint8)6)
#define DCM_PERIODIC_MEDIUM_TIMER                                       ((uint8)7)
#define DCM_PERIODIC_FAST_TIMER                                         ((uint8)8)

#define DCM_RECEPTION_ONGOING                                           ((uint8)1)
#define DCM_RECEPTION_COMPLETED                                         ((uint8)2)
#define DCM_RECEPTION_IDLE                                              ((uint8)3)
#define DCM_RECEPTION_CANCELLED                                         ((uint8)4)

#define USE_SYNCH_CLIENT_SERVER                                         ((uint8)1)
#define USE_SYNCH_FNC                                                   ((uint8)2)
#define USE_ASYNCH_CLIENT_SERVER                                        ((uint8)3)
#define USE_ASYNCH_FNC                                                  ((uint8)4)

/*******************************************************************************
** Related to protocol timing Values                                          **
*******************************************************************************/
/*Value for P2Server min */
#define DCM_TIMSTR_P2_SERVER_MIN                                  ((uint16)0x0000)

/* Value for P2*Server min */
#define DCM_TIMSTR_P2_STAR_SERVER_MIN                             ((uint16)0x0000)

/* Value for S3 Server */
#define DCM_TIMSTR_S3_SERVER                                      ((uint16)0x1388)



/*******************************************************************************
**                     Diagnostic Service Ids                                 **
*******************************************************************************/

#define DCM_DIAGNOSTICSESSIONCONTROL                                 ((uint8)0x10)
#define DCM_ECURESET                                                 ((uint8)0x11)
#define DCM_CLEARDIAGNOSTICINFORMATION                               ((uint8)0x14)
#define DCM_READDTCINFORMATION                                       ((uint8)0x19)
#define DCM_READDATABYIDENTIFIER                                     ((uint8)0x22)
#define DCM_STOPDIAGNOSTICSESSION                                    ((uint8)0x20)
#define DCM_READMEMORYBYADDRESS                                      ((uint8)0x23)
#define DCM_READSCALINGDATABYIDENTIFIER                              ((uint8)0x24)
#define DCM_SECURITYACCESS                                           ((uint8)0x27)
#define DCM_COMMUNICATIONCONTROL                                     ((uint8)0x28)
#define DCM_ENABLENORMALMESSAGETRANSMISSION                          ((uint8)0x29)
#define DCM_READDATABYPERIODICIDENTIFIER                             ((uint8)0x2A)
#define DCM_DYNAMICALLYDEFINEDATAIDENTIFIER                          ((uint8)0x2C)
#define DCM_WRITEDATABYIDENTIFIER                                    ((uint8)0x2E)
#define DCM_INPUTOUTPUTCONTROLBYIDENTIFIER                           ((uint8)0x2F)
#define DCM_ROUTINECONTROL                                           ((uint8)0x31)
#define DCM_REQUESTDOWNLOAD                                          ((uint8)0x34)
#define DCM_REQUESTUPLOAD                                            ((uint8)0x35)
#define DCM_TRANSFERDATA                                             ((uint8)0x36)
#define DCM_REQUESTTRANSFEREXIT                                      ((uint8)0x37)
#define DCM_WRITEMEMORYBYADDRESS                                     ((uint8)0x3D)
#define DCM_TESTERPRESENT                                            ((uint8)0x3E)
#define DCM_ACCESSTIMINGPARAMETER                                    ((uint8)0x83)
#define DCM_SECUREDDATATRANSMISSION                                  ((uint8)0x84)
#define DCM_CONTROLDTCSETTING                                        ((uint8)0x85)
#define DCM_RESPONSEONEVENT                                          ((uint8)0x86)
#define DCM_LINKCONTROL                                              ((uint8)0x87)

/*******************************************************************************
**                     OBD        Service Ids                                 **
*******************************************************************************/

#define DCM_OBD_REQ_CURRENTPOWERTRAINDIAGDATA                        ((uint8)0x01)
#define DCM_OBD_REQ_POWERTRAIN_FREEZEFRAME_DATA                      ((uint8)0x02)
#define DCM_OBD_GETDTC_03                                            ((uint8)0x03)
#define DCM_OBD_CLRRST_EMISSION_DIAGINFO                             ((uint8)0x04)
#define DCM_OBD_REQ_ONBOAD_MONITOR_RESULT                            ((uint8)0x06)
#define DCM_OBD_GETDTC_07                                            ((uint8)0x07)
#define DCM_OBD_REQ_CTLR_ONBOAD_SYSTEM                               ((uint8)0x08)
#define DCM_OBD_REQ_VEHICLEINFO                                      ((uint8)0x09)
#define DCM_OBD_GETDTC_0A                                            ((uint8)0x0A)

/*******************************************************************************
**                      SUB FUNCTION                                          **
*******************************************************************************/






/*******************************************************************************
**                      DET ERROR CODES                                       **
*******************************************************************************/

/* Timeout is reported using following error code */
#define DCM_E_INTERFACE_TIMEOUT                                      ((uint8)0x01)

/* Return-value out of range is reported using following error code */
#define DCM_E_INTERFACE_RETURN_VALUE                                 ((uint8)0x02)

/* Buffer Overflow is reported using following error code */
#define DCM_E_INTERFACE_BUFFER_OVERFLOW                              ((uint8)0x03)

/* Protocol mismatch is reported using following error code */
#define DCM_E_INTERFACE_PROTOCOL_MISMATCH                            ((uint8)0x04)

/* Dcm not initialized is reported using following error code */
#define DCM_E_UNINIT                                                 ((uint8)0x05)

/*
 * Dcm API function with invalid input parameter is reported using following
 * error code
 */
#define DCM_E_PARAM                                                  ((uint8)0x06)
/*
 * Dcm API function with invalid pointer parameter is reported using following
 * error code
 */
#define DCM_E_PARAM_POINTER                                          ((uint8)0x07)

/* Macro for Unused parameter */
#define DCM_UNUSED(x)       do{if((uint8)(x) != (uint8)DCM_ZERO) {}} while(0)
#define DCM_UNUSED_PTR(x)   do{if((x) != NULL_PTR) {}} while(0)



/*******************************************************************************
**                      Response On Event                                     **
*******************************************************************************/
/* Activate External ROE Event */


#define DCM_IDLE                            0x00u
#define DCM_ROEONGOING                      0x01u
#define DCM_ROEPENDING                      0x02u

#define DCM_ROE_SUBFUNCTION_MASK            0x3Fu
#define DCM_ROE_STORE_BIT_MASK              0x40u

/* sub-function (eventType) bit5-0 definition */
#define DCM_STOP_ROE                        0x00u
#define DCM_ON_DTC_STATUS_CHANGE            0x01u
#define DCM_ON_TIME_INTERRUPT               0x02u
#define DCM_ON_CHANGE_OF_DID                0x03u
#define DCM_ON_DTC_STATUS_CHANGE_STOREBIT   0x41u
#define DCM_ON_TIME_INTERRUPT_STOREBIT      0x42u
#define DCM_ON_CHANGE_OF_DID_STOREBIT       0x43u
#define DCM_REPORT_ACTIVATED_EVENTS         0x04u
#define DCM_START_ROE                       0x05u
#define DCM_CLEAR_ROE                       0x06u


/* the max buffer size to store servieToRespondTo */
#define DCM_ROE_STRT_SIZE                   0x10u

#define DCM_ROE_MAX_REQ_DATA_LEN            0x10u

/* Length of Request Message Parameters */
#define DCM_ROE_MIN_ROE_REQ_MSG_LEN         0x01u

/* minimum length of STRTR(serviceToRespondToRecord) request message
   ReadDataByIdentifier = 3-byte
   ReadDTCInformation : 2-byte
   RoutineControl : 4-byte
   InputOutputControlByIdentifier : 3-byte   */
#define DCM_ROE_MIN_STRTR_REQ_MSG_LEN      0x02u

/* Length of eventTypeRecord when the sub-function is
  stopResponseOnEvent (0x00) */
#define DCM_ROE_ETR_LEN_STPROE             0x00u
/* Length of eventTypeRecord when the sub-function is
  onDTCStatusChange (0x01) */
#define DCM_ROE_ETR_LEN_ONDTCS             0x01u
/* Length of eventTypeRecord when the sub-function is onTimeInterrupt (0x02) */
#define DCM_ROE_ETR_LEN_OTI                0x01u
/* Length of eventTypeRecord when the sub-function is
  onChangeOfDataIdentifier (0x03) */
#define DCM_ROE_ETR_LEN_OCODID             0x02u
/* Length of eventTypeRecord when the sub-function is
  reportActivatedEvents (0x04) */
#define DCM_ROE_ETR_LEN_RAE                0x00u
/* Length of eventTypeRecord when the sub-function is
  startResponseOnEvent (0x05) */
#define DCM_ROE_ETR_LEN_STRTROE            0x00u
/* Length of eventTypeRecord when the sub-function is
  clearResponseOnEvent (0x06) */
#define DCM_ROE_ETR_LEN_CLRROE             0x00u

/* Value of vehicle manufacturer specific eventWindowTime */
#define DCM_ROE_SPECIFIC_WINDOW_TIME       0x02u


#define DCM_ROE_QUEUE_WRITE                (DCM_ZERO)
#define DCM_ROE_QUEUE_READ                 (DCM_ONE)


#ifndef DCM_SWCGEN
/*******************************************************************************
**                Dcm_ProgConditionsType                                      **
*******************************************************************************/

typedef struct STagDcm_ProgConditionsType
{
  /* Tester source address configured per protocol */
  uint16 TesterSourceAddr;
  /* Id of the protocol on which the request has been received */
  uint8 ProtocolId;
  /* Service identifier of the received request */
  uint8 Sid;
  /* Identifier of the received subfunction */
  uint8 SubFncId;
  /* Set to true in order to request reprogramming of the ECU */
  boolean ReprogramingRequest;
  /* Indicate whether the application has been updated or not */
  boolean ApplUpdated;
  /* Set to true in case the flashloader or application shall send a response */
  boolean ResponseRequired;
  /* Indication current security level */
  uint8 SecLvInfo;
}Dcm_ProgConditionsType;
#endif


#define DEM_SESCTRL_ITC_TYPE    0x01u /* currently, just true or false */


#ifndef DCM_INLINE

#ifndef INLINE
#define DCM_INLINE inline
#else 
#define DCM_INLINE INLINE
#endif

#endif

/* CSAC Algorithm */
#ifdef DcmConf_DcmDspSecurityRow_L21
#define DCM_CSAC_CONFIGURED (STD_ON)
#else
#define DCM_CSAC_CONFIGURED (STD_OFF)
#endif
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

#endif /* DCM_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
