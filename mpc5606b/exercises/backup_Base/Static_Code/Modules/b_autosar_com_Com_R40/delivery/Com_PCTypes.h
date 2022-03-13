/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of AUTOSAR Com Module Type Definitions and          **
**              declarations.                                                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.2     01-Sep-2017   Chan Kim    Internal Redmine #9784, #10060         **
** 2.2.1     24-Aug-2017   Chan Kim    Internal Redmine #9652                 **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7429, #7709, #7744,  **
**                                     #7878, #7820, #7525, #7705             **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6806, #6807          **
** 2.1.6     08-Nov-2016   Chan Kim    Internal Redmine #6557                 **
** 2.1.5     07-Oct-2016   Chan Kim    Internal Redmine #5909                 **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5687, #5813          **
** 2.1.3     12-Jul-2016   Chan Kim    Internal Redmine #5550                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #4806, #4757, #3959,  **
**                                     #4908                                  **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4109, #4158          **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.17    27-Feb-2015   Chan Kim    Internal Redmine #2275                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.15    09-Feb-2015   Chan Kim    Internal Redmine #2142                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463                 **
** 1.0.12    26-May-2014   Chan Kim    Internal Redmine #938, #901            **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #693, #730            **
** 1.0.10    03-Mar-2014   Chan Kim    Internal Redmine #647, #648            **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */

#ifndef COM_PCTYPES_H
#define COM_PCTYPES_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_PCTYPES_AR_RELEASE_MAJOR_VERSION  4
#define COM_PCTYPES_AR_RELEASE_MINOR_VERSION  0
#define COM_PCTYPES_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_PCTYPES_SW_MAJOR_VERSION  2
#define COM_PCTYPES_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Typedefinition of call-back function pointer */
typedef void (*pCallbackFunctPtr)(void);
/* Typedefinition of invalid function pointer */
typedef void (*pInvSigNotifCbkPtr)(void);
/* Typedefinition of invalid function pointer */
typedef boolean (*pInvalidFunctionPtr)
  (P2CONST(uint8, AUTOMATIC, COM_CONST)pSource,
   P2CONST(uint8, AUTOMATIC, COM_CONST)pTarget, PduLengthType LddSize);

typedef void (*pWrFunctionPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST)pSource,
  P2VAR(void, AUTOMATIC, COM_VAR)pTarget, PduLengthType LddSize);

typedef void (*pRdFunctionPtr)
  (P2CONST(uint8, AUTOMATIC, COM_CONST)pSource,
  P2VAR(uint8, AUTOMATIC, COM_VAR)pTarget, PduLengthType LddSize);

#if(COM_RX_COUNTER_NOTIFY == STD_ON)
/* Function pointer for Counter Error Notification */
typedef P2FUNC(void, COM_APPL_CODE, Com_RxCountNotify)(PduIdType ComPduId,
  uint8 ExpectedCounter, uint8 ReceivedCounter);
#endif

/* Transmission modes */
#define COM_TX_NONE_MODE                    ((uint8)0)
#define COM_TX_PERIODIC_MODE                ((uint8)1)
#define COM_TX_MIXED_MODE                   ((uint8)2)
#define COM_TX_MIXEDNTIMES_MODE             ((uint8)3)
#define COM_TX_DIRECTNTIMES_MODE            ((uint8)4)
#define COM_TX_DIRECT_MODE                  ((uint8)5)
#define COM_COUNTER_E_PENDING               ((uint8)1)
#define COM_COUNTER_TRIGTX                  ((uint8)2)

/* Endianess */
#define COM_BIGENDIAN                       (0)
#define COM_LITTLEENDIAN                    (1)

/* Data invalid action */
#define COM_INVALID_NONE                    ((uint8)0xFF)
#define COM_INVALID_PARAM                   ((uint8)0xFF)
#define COM_INVALID_RXID_PARAM              ((PduIdType)0xFFFF)
#define COM_INVALID_TXID_PARAM              ((PduIdType)0xFFFF)
#define COM_INVALID_SIGID_PARAM             ((Com_SignalIdType)0xFFFF)
#define COM_INVALID_SIGGRID_PARAM           ((Com_SignalGroupIdType)0xFFFF)
#define COM_INVALID_LENGTH_PARAM            ((PduLengthType)0xFFFF)
#define COM_INVALID_PACK_INDEX_PARAM        ((Com_TxPackCountType)0xFFFF)




/* Return value in case of gateway signal */
#define COM_GWTRANSMIT                      ((uint8)0x81)

/* Mask value for signals */
#define COM_SIG_SIZE_MASK_VALUE             ((uint8)0xF0)
#define COM_SIG_BYTE_MASK_VALUE             ((uint8)0x0F)

/* Size of signal */
#define COM_SIZE_8                          ((uint8)0x10)
#define COM_SIZE_16                         ((uint8)0x20)
#define COM_SIZE_24                         ((uint8)0x30)
#define COM_SIZE_32                         ((uint8)0x40)

#define COM_TYPE_8                          ((uint8)0x00)
#define COM_TYPE_16                         ((uint8)0x01)
#define COM_TYPE_24                         ((uint8)0x02)
#define COM_TYPE_32                         ((uint8)0x03)
#define COM_TYPE_40                         ((uint8)0x04)
#define COM_TYPE_48                         ((uint8)0x05)
#define COM_TYPE_56                         ((uint8)0x06)
#define COM_TYPE_64                         ((uint8)0x07)

#define COM_ZERO                            ((uint8)0)
#define COM_ONE                             ((uint8)1)
#define COM_TWO                             ((uint8)2)
#define COM_THREE                           ((uint8)3)
#define COM_FOUR                            ((uint8)4)
#define COM_FIVE                            ((uint8)5)
#define COM_EIGHT                           ((uint8)8)
#define COM_NINE                            ((uint8)9)
#define COM_SIXTEEN                         ((uint8)16)
#define COM_THIRTY_TWO                      ((uint8)32)

#define COM_MACRO_ZERO                      (0)

/* Mask values */
#define COM_SIGN_MASK                       ((uint8)0xff)
#define COM_SIGN_EXTENSION                  ((uint8)0xff)

#define COM_FALSE                           ((boolean)0)
#define COM_TRUE                            ((boolean)1)

#define COM_ENABLE                          ((boolean)0)
#define COM_DISABLE                         ((boolean)1)

#define COM_INVALID_TX_IPDU_ID              ((PduIdType)0xFFFF)

/* Tx I-PDU Status Bit */
#define COM_TX_TMS_STATUS_MASK              ((uint16)0x01)
#define COM_TX_PENDING_STATUS_MASK          ((uint16)0x02)
#define COM_TX_REQ_STATUS_MASK              ((uint16)0x04)
#define COM_TX_PT_STATUS_MASK               ((uint16)0x08)
#define COM_TX_RETRY_STATUS_MASK            ((uint16)0x10)
#define COM_TX_DM_STATUS_MASK               ((uint16)0x20)
#define COM_TX_DM_STATUS_MASK_NEG           ((uint16)0xDF)
#define COM_TX_REPT_STATUS_MASK             ((uint16)0x40)
#define COM_TX_CONFIRM_STATUS_MASK          ((uint16)0x80)
#define COM_TX_MAINFUNC_SEND_STATUS_MASK    ((uint16)0x100)
/* #2022 MDTForCyclicTransmission related compile error 
& incorrect operation is fixed(ref 4.2.1 Com Spec) */
#define COM_TX_REPT_COUNT_HANDLE_MASK       ((uint16)0x200)
#define COM_TX_REPT_CONFIRM_HANDLE_MASK     ((uint16)0x400)




/* Reset PT, Retry, DM, Rept and confirmation status mask */
#define COM_TX_RESET_STATUS_MASK            ((uint8)0x07)


  /*
  0x01: TMS
  0x02: IpduCallout
  0x04: TriggerIpduCallout
  0x08: Deadline Monitoring
  0x10: Minimum Delay Timer
  0x20: Signal Notification
  0x40: Immediate or Deferred
  0x80: Update bit
  */

/* Tx Ipdu Configuration Bits */
#define COM_TX_IPDU_TMS_CONFIG_MASK         ((uint8)0x01)
#define COM_TX_IPDU_API_SWITCH_CONFIG_MASK  ((uint8)0x01)
#define COM_TX_IPDU_PDUCALLOUT_CONFIG_MASK  ((uint8)0x02)
#define COM_TX_IPDU_TRIGCALLOUT_CONFIG_MASK ((uint8)0x04)
#define COM_TX_IPDU_DM_CONFIG_MASK          ((uint8)0x08)
#define COM_TX_IPDU_MDT_CONFIG_MASK         ((uint8)0x10)
#define COM_TX_IPDU_NOTIFY_CONFIG_MASK      ((uint8)0x20)
#define COM_TX_IPDU_DEFERRED_CONFIG_MASK    ((uint8)0x40)
#define COM_TX_IPDU_UB_CONFIG_MASK          ((uint8)0x80)
#define COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK  ((uint8)0x60)

#define COM_TX_IPDU_DM_MDT_CONFIG_MASK      (COM_TX_IPDU_DM_CONFIG_MASK | \
                                            COM_TX_IPDU_MDT_CONFIG_MASK)
/* Update bit configuration mask */
#define COM_TX_IPDU_UB_TRIGGER_CONFIG_MASK  ((uint8)0x02)
#define COM_TX_IPDU_UB_TRANSMIT_CONFIG_MASK ((uint8)0x00)
#define COM_TX_IPDU_UB_CONFIRM_CONFIG_MASK  ((uint8)0x01)

/* Rx Ipdu configuration */
#define COM_RX_IPDU_DEFERRED_CONFIG_MASK    ((uint8)0x01)
#define COM_RX_IPDU_NOTIF_CONFIG_MASK       ((uint8)0x02)
#define COM_RX_IPDU_GATEWAY_CONFIG_MASK     ((uint8)0x04)
#define COM_RX_IPDU_SIGNAL_CONFIG_MASK      ((uint8)0x08)
#define COM_RX_IPDU_SIGGRP_CONFIG_MASK      ((uint8)0x10)
#define COM_RX_IPDU_DM_CONFIG_MASK          ((uint8)0x20)
#define COM_RX_IPDU_SIGDM_CONFIG_MASK       ((uint8)0x80)
#define COM_RX_DM_CONFIG_MASK               ((uint8)0xa0)
#define COM_RX_ONEVERYN_CONFIG_MASK         ((uint8)0x40)

/* Tx Signal configuration */
#define COM_TX_SIG_TMS_STATUS_MASK          ((uint8)0x01)
#define COM_TX_SIG_TMS_CONFIG_MASK          ((uint8)0x02)
#define COM_TX_SIG_DM_CONFIG_MASK           ((uint8)0x80)
#define COM_TX_SIGNAL_UB_CONFIG_MASK        ((uint8)0x40)
#define COM_TX_SIG_TRIG_CONFIG_MASK         ((uint8)0x1F)
#define COM_TX_SIG_WOREPT_CONFIG_MASK       ((uint8)0x0C)
#define COM_TX_SIG_GW_CONFIG_MASK           ((uint8)0x20)
#define COM_TX_SIG_PROPERTY_CONFIG_MASK     ((uint8)0x1C)
/* Tx Signal Property Configuration + TMS configuration */
/* Bit position
   Prop. T R
   0 0 1 X X => 0x04 => Pending
   0 1 0 X X => 0x08 => Triggered
   0 1 1 X X => 0x0C => Triggered wo Rept
   1 1 0 X X => 0x18 => Triggered on change
   1 1 1 X X => 0x1C => Triggered on change wo Rept
*/
#define COM_TX_SIG_PENDING_PROPERTY         ((uint8)0x04)
#define COM_TX_SIG_TRIGGERED_ON_CHANGE      ((uint8)0x18)
#define COM_TX_SIGPROP_WOREPT_CONFIG_MASK   ((uint8)0x0C)
#define COM_TX_SIG_FILTER_CONFIG_MASK       ((uint8)0x02)


  /* Signal Configuration value. Depending upon the signal configuration value,
  generation tool should generate the value based on following formulae:
    0x01 : Notification
    0x02 : IdsM Report Support
    0x04 : Update bit
    0x08 : Update bit deadline monitoring system
    0x10 : Update bit deadline monitoring with timeout replacement
    0x20 : Filtering
    0x40 : Invalidation
    0x80 : Invalidation replacement with init value */

/* Rx Signal configuration */
#define COM_RX_SIGNAL_NOTIF_CONFIG_MASK        ((uint8)0x01)
#define COM_RX_SIGNAL_IDSM_MASK                ((uint8)0x02)
#define COM_RX_SIGNAL_UB_CONFIG_MASK           ((uint8)0x04)
#define COM_RX_SIGNAL_UBDM_CONFIG_MASK         ((uint8)0x08)
#define COM_RX_SIGNAL_UBDMREPLACE_CONFIG_MASK  ((uint8)0x10)
#define COM_RX_SIGNAL_FILTER_CONFIG_MASK       ((uint8)0x20)
#define COM_RX_SIGNAL_INVALID_CONFIG_MASK      ((uint8)0x40)
#define COM_RX_SIGNAL_INVREPLACE_CONFIG_MASK   ((uint8)0x80)
#define COM_RX_SIGNAL_REPLACE_CONFIG_MASK     \
                                ((uint8)(COM_RX_SIGNAL_INVREPLACE_CONFIG_MASK | \
                                        COM_RX_SIGNAL_UBDMREPLACE_CONFIG_MASK))

/*
    0x01: Notification
    0x02: Update Bit
    0x04: Update Bit with TimeOut
    0x08: Invalid Configuration
    0x10: Replace the value (Invalid Replacement )
    0x20: Replace the value (Timeout/Invalid Replacement)
*/
/* Rx Signal configuration */
#define COM_RX_SIGGRP_NOTIF_CONFIG_MASK        ((uint8)0x01)
#define COM_RX_SIGGRP_UB_CONFIG_MASK           ((uint8)0x02)
#define COM_RX_SIGGRP_UBDM_CONFIG_MASK         ((uint8)0x04)
#define COM_RX_SIGGRP_INVALID_CONFIG_MASK      ((uint8)0x08)
#define COM_RX_SIGGRP_INVREPLACE_CONFIG_MASK   ((uint8)0x10)
#define COM_RX_SIGGRP_REPLACE_CONFIG_MASK      ((uint8)0x20)

/* 2-bit mask used for Replication */
#define COM_REPLICATION_MASK      ((uint8)0x03)

/* Macros for TMS control */
#define COM_FALSE_MODE_INDICATION_MASK     ((uint8)0x10)
#define COM_MODE_TRANSMIT_MASK            ((uint8)0x11)

/* TP Macros */
#define COM_BUFFER_LOCKED      ((uint8)0x01)
#define COM_BUFFER_UNLOCKED    ((uint8)0x00)
/* #2142 : separate DYN PDU from TP */
#define COM_DYN_IPDU           ((uint8)0x01)
#define COM_NORMAL_IPDU        ((uint8)0x00)

#if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
/* Signal Type Macros */
#define COM_SIG_TYPE_BOOLEAN      ((uint8)0x00)
#define COM_SIG_TYPE_UINT8        ((uint8)0x01)
#define COM_SIG_TYPE_SINT8        ((uint8)0x02)
#define COM_SIG_TYPE_UINT16       ((uint8)0x03)
#define COM_SIG_TYPE_SINT16       ((uint8)0x04)
#define COM_SIG_TYPE_UINT32       ((uint8)0x05)
#define COM_SIG_TYPE_SINT32       ((uint8)0x06)
#define COM_SIG_TYPE_FLOAT32      ((uint8)0x07)
#define COM_SIG_TYPE_UINT8_N      ((uint8)0x08)
#define COM_SIG_TYPE_FLOAT64      ((uint8)0x09)
/* Add Dynamic Sig Type(#647) - 14.03.03 by Chan Kim START */
#define COM_SIG_TYPE_UINT8_DYN    ((uint8)0x0A)
/* Add Dynamic Sig Type(#647) - 14.03.03 by Chan Kim END */
#endif
/* Invalid DM timer */
#define COM_INVALID_DM_TIMER      ((uint16)0xffff)

#define COM_SIG_GW_STATUS_NORMAL  ((uint8)0x00)
#define COM_SIG_GW_STATUS_TOUT    ((uint8)0x01)

#define COM_SIG_GW_CALLOUT_ACT_NONE      ((uint8)0x00)
#define COM_SIG_GW_CALLOUT_ACT_ALWAYS    ((uint8)0x01)
#define COM_SIG_GW_CALLOUT_ACT_TOUTONLY  ((uint8)0x02)

#define COM_SIG_RANGECHECK_DEF_ID ((uint16)0xFFFF)

/*******************************************************************************
**                      Structure related to Endianess Conversion             **
*******************************************************************************/
#if(CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
/*  If the processor is Big Endian */
  #define COM_WORD_MS_BYTE_IDX (0)
  #define COM_WORD_LS_BYTE_IDX (1)
  #define COM_DWORD_MS_BYTE_IDX (0) 
  #define COM_DWORD_LS_BYTE_IDX (3)
  #define COM_DWORD_MS_WORD_IDX (0)    
  #define COM_DWORD_LS_WORD_IDX (1)  
#else
/* If the processor is Little Endian */
  #define COM_WORD_MS_BYTE_IDX (1)
  #define COM_WORD_LS_BYTE_IDX (0)
  #define COM_DWORD_MS_BYTE_IDX (3)    
  #define COM_DWORD_LS_BYTE_IDX (0)  
  #define COM_DWORD_MS_WORD_IDX (1)      
  #define COM_DWORD_LS_WORD_IDX (0)
#endif

/* polyspace:begin<MISRA-C:18.4:Not a defect:Justify with annotations> Union used for handling endian conversion */
/* Union for 16 bit CPU byte order */
typedef union
{
  struct
  {
    uint8 BO_Byte[2];
  }byte_val;
  uint16 whole_word;
}Com_MIWord_Access;

/* Union for 32 bit CPU byte order */
typedef union
{
  struct
  {
    uint8 BO_Byte[4];
  }byte_val;
  struct
  {
    uint16 BO_Word[2];
  }word_val;
  uint32 whole_dword;
}Com_MIdWord_Access;
/* polyspace:end<MISRA-C:18.4:Not a defect:Justify with annotations> Union used for handling endian conversion */

/******************************************************************************/

/*******************************************************************************
**                     Structure for Filters                                  **
*******************************************************************************/

/* Filter Algorithm - F_MaskedNewEqualsx,
                      F_MaskedNewDiffersX,
                      F_MaskedNewDiffersMaskedOld */
/* Structure for MaskedNew filter */
typedef struct STagCom_FilterMaskedNew
{
  /* Pointer to filter function pointer. Depending upon the signal type and
  filter types, generation tool should generate appropriate filter function */
  P2FUNC(boolean, COM_APPL_CODE,pFilterFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
  P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
  uint8 ActivateCode);
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter status. This parameter along with ucFltrStsMask is used
  to store the filter result. Generation tool should allocate one bit RAM area
  if the signal has been configured for the filter status indication
  otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pFilterStatus;
  /* Filter status mask. Generation tool should generate the value based on the
  RAM allocation of pFilterStatus in the structure */
  uint8 ucFltrStsMask;
  #endif
  /* Pointer to signal buffer. Generation tool should allocate the RAM area
  based on the type of the signal. This pointer is only applicable to
  F_MaskedNewDiffersMaskedOld. For other filters it should be NULL pointer */
  P2VAR(void, AUTOMATIC, COM_VAR) pSignalBuffer;
  /* Filter Mask value. Generation tool should generate filter mask value based
  on the configuration */
  uint32 ulFilterMask;
  /* Filter X value. Generation tool should generate filter X value based on
  the configuration */
  sint32 slX;
  /* [SWS_Com_00793] 4.1.1 store the last Rx DM timeout status */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pFilterActivated;  
}Com_FilterMaskedNew;

/* Filter Algorithm - F_NewIsWithin,
                      F_NewIsOutside */
/* Structure for NewIsInRange filter */
typedef struct STagCom_FilterNewIsInRange
{
  /* Pointer to filter function pointer */
  /* Depending upon the signal type and filter type, generation tool should
  generate appropriate filter function */
  P2FUNC(boolean, COM_APPL_CODE,pFilterFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
  P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
  uint8 ActivateCode);
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter status. This parameter along with ucFltrStsMask is used
  to store the filter result. Generation tool should allocate one bit RAM area
  if the signal has been configured for the filter status indication
  otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pFilterStatus;
  /* Filter status mask. Generation tool should generate the value based on the
  RAM allocation of pFilterStatus in the structure */
  uint8 ucFltrStsMask;
  #endif
  /* Minimum value of the filter. Generation tool should generate the minimum
  value based on the configuration */
  sint32 slMin;
  /* Maximum value of the filter. Generation should generate the maximum
  value based on the configuration */
  sint32 slMax;
}Com_FilterNewIsInRange;

/* shruti: Fixed the order. Order was wrong */
/* Filter Algorithm - F_OneEveryN */
/* Structure for OneEveryN filter */
typedef struct STagCom_FilterOneEveryN
{
  /* Pointer to filter function pointer */
  /* Depending upon the signal type and filter type, generation tool should
  generate appropriate filter function */
  P2FUNC(boolean, COM_APPL_CODE,pFilterFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
  P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
  uint8 ActivateCode);
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter status. This parameter along with ucFltrStsMask is used
  to store the filter result. Generation tool should allocate one bit RAM area
  if the signal has been configured for the filter status indication
  otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pFilterStatus;
  /* ddComPduId */
  PduIdType ddComPduId;
  /* Filter status mask. Generation tool should generate the value based on the
  RAM allocation of pFilterStatus in the structure */
  uint8 ucFltrStsMask;
  #endif
  /* Pointer to 16 bit counter. Generation tool should allocate 16 bit RAM
  area */
  P2VAR(uint16, AUTOMATIC, COM_VAR) pCounter;
  /* Offset value. Generation tool should generate offset value based on the
  configuration */
  uint16 usOffset;
  /* Period value. Generation tool should generate period value based on the
  configuration */
  uint16 usPeriod;
}Com_FilterOneEveryN;

/* Filter Algorithm - F_Never */
/* Structure for Never filter */
typedef struct STagCom_FilterNever
{
  /* Pointer to filter function pointer */
  P2FUNC(boolean, COM_APPL_CODE,pFilterFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
  P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
  uint8 ActivateCode);
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter status. This parameter along with ucFltrStsMask is used
  to store the filter result. Generation tool should allocate one bit RAM area
  if the signal has been configured for the filter status indication
  otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pFilterStatus;
  /* Filter status mask. Generation tool should generate the value based on the
  RAM allocation of pFilterStatus in the structure */
  uint8 ucFltrStsMask;
  #endif
}Com_FilterNever;

/******************************************************************************/

/*******************************************************************************
**   Structure for Notification/Notification Error Call-back functions        **
*******************************************************************************/

/* Structure for notification call-back function */
typedef struct STagCom_SigNotifCbk
{
  /* Pointer to notification call-back function. Generation tool should generate
  notification function based on the configuration */
  P2FUNC(void, COM_APPL_CODE,pSigNotifCbk)(void);
}Com_SigNotifCbk;

/* Structure for notification error call-back function */
typedef struct STagCom_SigErrorCbk
{
  /* Pointer to notification error function. Generation tool should generate
  notification error function based on the configuration */
  P2FUNC(void, COM_APPL_CODE,pSigErrorCbk)(void);
}Com_SigErrorCbk;

/******************************************************************************/

/*******************************************************************************
**   Structure for Tx Pack                                                    **
*******************************************************************************/
/* Shruti: 1) Name of ucSigTypeOrSize changed to ddSigTypeOrSize. Order corrected 
and type too
2) ucSignalType type corrected and name changed to ddSignalType. Order changed*/
/* Structure for Tx Pack */
typedef struct STagCom_TxPack
{
  /* Pointer to I-PDU buffer or signal buffer or shadow buffer or signal group
  buffer. This parameter along with ucSigTypeOrSize, ucNoOfShiftBit,
  ucWrStartMask and ucWrEndMask is used to pack the signal into I-PDU/signal
  buffer. Based on the configuration, generation tool should allocate the
  pointer to an I-PDU buffer or signal buffer or shadow buffer or signal group
  buffer */
  P2VAR(void, AUTOMATIC, COM_VAR) pWrBuffer;
  /* Signal type or size of the signal. Higher nibble represents the type of the
  signal and Lower nibble represents the size of the signal that is spread
  across I-PDU. Generation tool should generate the value based on the following
  formulae:
    0x11     8 bit signal pack into one byte      (COM_SIG_8_1)
    0x12     8 bit signal pack into two byte      (COM_SIG_8_2)
    0x22    16 bit signal pack into two byte      (COM_SIG_16_2)
    0x23    16 bit signal pack into three byte    (COM_SIG_16_3)
    0x33    24 bit signal pack into three byte    (COM_SIG_24_3)
    0x34    24 bit signal pack into four byte     (COM_SIG_24_4)
    0x44    24 bit signal pack into four byte     (COM_SIG_32_4)
    0x45    32 bit signal pack into five byte     (COM_SIG_32_5)
    0x0x    uint8[x] signal where x > 1           (COM_SIG_x) */
  PduLengthType ddSigTypeOrSize;

  /* Signal Type:
    08 Bit   : 0
    16 Bit   : 1
    24 Bit   : 2
    32 Bit   : 3
    uint8[x] : x */
  PduLengthType ddSignalType;

  /* Index of the array Com_GaaTxDynSigLength[]. If this instance of the pack
     struture is mapped to a dynamic signal, then Com_GaaTxDynSigLength[] shall
     hold the latest length of the dynamic signal. For non-dynamic signals,
     this parameter should be COM_INVALID_TXID_PARAM */
  /* #2142 : separate DYN PDU from TP */
  PduIdType ddTxIpduDynLegthRef;
  /* Index of the write function pointer array. Generation tool should allocate
  the array index based on the type of the signal and size of the network signal
  that is spread across an I-PDU. */
  uint8 ucWrFuncIndex;
  /* Number of shift bits. Generation tool should generate the value based on
  the offset position in an I-PDU */
  uint8 ucNoOfShiftBit;
  /* Write start mask. Generation tool should generate the value based on the
  start position of the signal in an I-PDU */
  uint8 ucWrStartMask;
  /* Write end mask. Generation tool should generate the value based on the end
  position of the signal in an I-PDU */
  uint8 ucWrEndMask;
}Com_TxPack;

/* Structure for write function pointer */
typedef struct STagCom_SigWrFuncPtr
{
  /* Pointer to write function pointer. Generation tool should allocate the
  function based on the type of the signal and size of the network signal that
  is spread across an I-PDU */
  P2FUNC(void, COM_CODE, pWrFuncPtr)
  (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)LpTxPack,
  P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
}Com_SigWrFuncPtr;

/*******************************************************************************
**                        Structure related to  Rx                            **
*******************************************************************************/

/* Structure for write function pointer */
typedef struct STagCom_WrFuncPtr
{
  /* Pointer to write function pointer. Generation tool should allocate the
  function */
  P2FUNC(void, COM_CODE, pWrFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST)LpSource,
   P2VAR(void, AUTOMATIC, COM_VAR)LpDest,
   PduLengthType LddSize);
}Com_WrFuncPtr;

/* Structure for validate function pointer */
typedef struct STagCom_ValidateValue
{
  /* Pointer to validate function pointer. Generation tool should allocate the
  function */
  P2FUNC(boolean, COM_CODE, pValidateDataPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST)LpSource,
   P2VAR(void, AUTOMATIC, COM_VAR)LpDest,
   PduLengthType LddSize);
}Com_ValidateValue;

/* Structure for invalid function pointer */
typedef struct STagCom_InvalidFuncPtr
{
  /* Pointer to invalid function pointer. Generation tool should allocate the
  function */
  P2FUNC(boolean, COM_CODE, pInvalidFuncPtr)
  (P2CONST(void, AUTOMATIC, COM_CONST)LpSource,
  P2CONST(void, AUTOMATIC, COM_CONST)LpTarget,
  PduLengthType LddSize);
}Com_InvalidFuncPtr;

/* #7744 start */
#if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
   (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
/* Structure for Signal Replace */
typedef struct STagCom_SigReplace
{
  /* Pointer to Initialization value. Generation tool should allocate pointer
  to initialization value if the timeout replacement has been configured for the
  signal otherwise it should point to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pInitValue;
  /* Index of the pack structure array. This parameter is used to pack the
  initial value into I-PDU/signal buffer. Generation tool should generate the
  appropriate array index of the pack structure array if the signal has been
  configured for the timeout replacement otherwise it should have the value
  COM_INVALID_NONE */
  Com_TxPackCountType ddTxPackIndex;
  /* #7878 */
}Com_SigReplace;
#endif

#if((COM_RX_SIGGROUP_REPLACE == STD_ON) || \
   (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
/* Structure for Signal Replace */
typedef struct STagCom_SigGrpReplace
{
  /* Pointer to Initialization value. Generation tool should allocate pointer
  to initialization value if the timeout replacement has been configured for the
  signal otherwise it should point to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pInitValue;
  /* Index of the pack structure array. This parameter is used to pack the
  initial value into I-PDU/signal buffer. Generation tool should generate the
  appropriate array index of the pack structure array if the signal has been
  configured for the timeout replacement otherwise it should have the value
  COM_INVALID_NONE */
  Com_TxPackCountType ddTxPackIndex;
  /* #7878 */

  /* Index to reference SignalGroup which include this GroupSignal */
  Com_SignalGroupIdType ddSigGrpIndex;
}Com_SigGrpReplace;
#endif
/* #7744 end */
/* Structure for Rx deadline monitoring. Generation tool should place all RxDm
configured for an Ipdu sequentially (Ipdu first and followed by signals within
an Ipdu */
/* This structure should be generated for I-PDU as well as signal based
deadline monitoring.
  Generation tool should generate following structure based on following
  points:
   1) Signals within I-PDU does not have an update bit and deadline
      monitoring timer has been configured
   2) Signal with an update bit and deadline monitoring timer has been
      configured
*/

typedef struct STagCom_RxDm
{
  /* Added For getting related Rx PDU */
  PduIdType ddRxpduId;

  /* Deadline monitoring timeout. Generation tool should generate the time out
  value based on the configuration */
  uint16 usRxDmTimeout;
  /* Deadline monitoring first timeout. Generation tool should generate the
  first timeout value based on the configuration */
  uint16 usRxDmFirstTimeout;
  /* Index of the notification error call-back structure array. This parameter
  along with ucNoOfSigCallback is used to provide the notification error to the
  upper layer whenever deadline monitoring timer expires. Generation tool should
  generate the appropriate array index of the first notification error call-back
  function. If more than one notification error have been configured then
  notification error functions should be allocated consecutively in the
  "Com_SigErrorCbk" structure by the generation tool */
  Com_ErrCbkCountType ddSigErrCbkIndex;
  /* #7744 start */
  /* Number of error notification call-back functions */
  uint8 ucNoOfSigCallback;
  
  #if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
     (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))       
  /* Index of the Signal Replace structure array. This parameter is used to
  initialize I-PDU/Signal Buffer Buffer with the initial value if
  timeout occurs and notification error is configured with timeout
  replacement.  */
  uint8 ucSigReplaceIndex;
  /* Number of Signals configured for Replacement */
  uint8 ucNoOfSigReplace;  
  #endif

  #if((COM_RX_SIGGROUP_REPLACE == STD_ON) || \
     (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
  /* Index of the Signal Group Replace structure array. This parameter is used to
  initialize I-PDU/Signal Group Buffer with the initial value if
  timeout occurs and notification error is configured with timeout
  replacement.  */
  uint8 ucSigGrpReplaceIndex;
  /* Number of Signals Group configured for Replacement */
  uint8 ucNoOfSigGrpReplace;  
  #endif
  /* Count for which signal belongs to the same I-PDU */
  uint8 ucRxDmCount;
}Com_RxDm;
  /* #7744 end */
 #if (COM_RX_SIGNAL_INVALID == STD_ON)
/* Structure for Rx Invalid */
typedef struct STagCom_RxInvalid
{
  /* Pointer to invalid value. Generation tool should point to the invalid
  value */
  P2CONST(void, AUTOMATIC, COM_CONST) pInvalidValue;
  /* Pointer to initialization value. Generation tool should point to the
  initialization value if the invalid notification with replace value has been
  configured for the signal otherwise it should point to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST)pInitValue;
  
  /* #7820 */
  /* Index of the invalid function pointer array. Generation tool should
  generate the appropriate array index of the notification function array if the
  invalid notification function has been configured for the signal otherwise
  it should have the value COM_INVALID_NONE */
  Com_InvNotifCountType ddInvNotifCbkIndex;  
}Com_RxInvalid;
#endif

#if(COM_RX_SIGGROUP_INVALID == STD_ON)
/* Structure for Rx Signal In group Invalid */
typedef struct STagCom_RxSigInGrpInv
{
  /* Index of the RxUnpack structure array. This parameter is used to unpack
  the signal from an I-PDU. Generation tool should generate the appropriate
  array index of Rx Unpack structure for the signal */
  Com_RxUnPackCountType ddRxUnpackIndex;
  /* Pointer to invalid value. Generation tool should point to the invalid
  value that is configured for signal within signal group. If no invalid value
  has been configured, it should point to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST)pInvalidValue;
  
  /* #7820 */
}Com_RxSigInGrpInv;
#endif

/* Structure for Rx Unpack */
typedef struct STagCom_RxUnpack
{
  /* Pointer to I-PDU/shadow buffer. Generation tool should provide the pointer
  to the I-PDU/shadow buffer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pRdBuffer;
  /* Signal Type:
    08 Bit   : 0
    16 Bit   : 1
    24 Bit   : 2
    32 Bit   : 3
    uint8[x] : x */
  uint8 ucSignalType;
  /* Index of the read function pointer array. Depending upon the signal type
  and endianness, generation tool should generate the appropriate array index.
  */
  uint8 ucRdFuncIndex;
  /* Size of the signal. Generation tool should generate the value based on the
  size of the signal spread across an I-PDU */
  PduLengthType ddSignalSize;
  /* End mask value. Generation tool should generate the end mask value based
  on the size of the network signal */
  uint8 ucRdEndMask;
  /* Number of shift bits. Generation tool should generate the value based on
  the configuration */
  uint8 ucNoOfShiftBits;
  /* Sign mask value. Generation tool should generate the value based on the
  network signal size and type of the signal */
  uint8 ucRdSignMask;
  /* Index of the array Com_GaaRxDynSigLength[]. If this instance of the pack
     struture is mapped to a dynamic signal, then Com_GaaRxDynSigLength[] shall
     hold the latest length of the dynamic signal. For non-dynamic signals,
     this parameter should be COM_INVALID_RXID_PARAM */
  /* #2142 : separate DYN PDU from TP */
  PduIdType ddRxIpduDynLegthRef;
  #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
  /* Index of I-PDU byte in which the Signal start position. Generation tool
  should generate this parameter only in case of Rx counter */
  uint8 ucByteIndex;
  #endif
}Com_RxUnpack;

/* Structure for write function pointer */
typedef struct STagCom_SigRdFuncPtr
{
  /* Pointer to read function pointer. Depending upon the signal type and
  endianness, generation tool should generate the appropriate function. */
  P2FUNC(void, COM_CODE, pRdFuncPtr)
  (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)
  LpRxUnpack, P2VAR(void, AUTOMATIC, COM_VAR) LpSigDataPtr);
}Com_SigRdFuncPtr;

/* Structure for  Rx Signal. Generation tool should generate structure
consecutively for the signals within same I-PDU. Generation tool should first
generate the structure for  Rx signals for which update bit with
notification, update bit with deadline monitoring or filtering or invalidation
or any of the above combinations have been configured and then followed by other
signals within an I-PDU */
typedef struct STagCom_RxSignal
{
  #if((COM_RX_SIGNAL_UBDMREPLACE == STD_ON) || \
      (COM_RX_SIGNAL_FILTER == STD_ON) || \
      (COM_RX_SIGNAL_INVALID == STD_ON))
  /* Pointer to signal buffer. This parameter is used to store the signal value.
  Generation tool should allocate the RAM area for pSignalBuffer if the signal
  has been configured for filtering or invalidation or update bit with timeout
  replacement or any of the above combinations otherwise it should point to
  NULL pointer */
  P2VAR(void, AUTOMATIC, COM_VAR)pSignalBuffer;
  #endif
  #if(COM_RX_SIGNAL_UB == STD_ON)
  /* Pointer to an update bit position in an I-PDU. This parameter along with
  ucUbitMask is used to check whether the signal has update bit or not.
  Generation tool should generate the pointer which points to update bit
  position in an I-PDU if the signal has been configured for an update bit
  otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR)pUBit;
  #endif
  #if(COM_RX_SIGNAL_FILTER == STD_ON)
  /* Pointer to filter object. Depending upon the type of the filter,
  generation tool should generate the pointer to filter object if the signal has
  been configured for filtering */
  P2CONST(void, AUTOMATIC, COM_CONST) pFilter;
  #endif
  /* Index of the RxUnpack structure array. This parameter is used to unpack
  the signal from an I-PDU. Generation tool should generate the appropriate
  array index of Rx Unpack structure for the signal */
  Com_RxUnPackCountType ddRxUnpackIndex;
  /* Index of Rx Pdu to which signal belongs to */
  PduIdType ddRxpduId;
  #if(COM_RX_SIGNAL_NOTIFY == STD_ON)
  /* Index of the  notification function pointer array. This parameter is used
  to provide the notification to the upper layer immediately after the signal
  has been processed. Generation tool should generate the appropriate array
  index of the function array based on the configuration if the signal has been
  configured for the notification otherwise it should have the value
  COM_INVALID_NONE */
  Com_NotifCountType ddNotifCbkIndex;
  #endif
  #if(COM_RX_SIGNAL_UBDM == STD_ON)
  /* Index of the  deadline monitoring structurer array. Generation tool should
  generate the appropriate array index of the RxSigDm structure if the signal
  with an update bit is configured for deadline monitoring otherwise it should
  have the value COM_INVALID_NONE */
  uint8 ucRxUbDmIndex;
  #endif
  #if(COM_RX_SIGNAL_INVALID == STD_ON)
  /* Index of the invalid structure array. Generation tool should generate the
  appropriate array index of the invalid structure array if the signal has been
  configured to check the invalidation otherwise it should have the value
  COM_INVALID_NONE */
  uint8 ucInvIndex;
  #endif
  #if(COM_RX_SIGNAL_UB == STD_ON)
  /* Update bit mask. Generation tool should generate the mask based on the
  update bit position in an I-PDU */
  uint8 ucUbitMask;
  #endif
  /* Signal Configuration value. Depending upon the signal configuration value,
  generation tool should generate the value based on following formulae:
    0x01 : Notification
    0x02 : Reserved for future purpose
    0x04 : Update bit
    0x08 : Update bit deadline monitoring system
    0x10 : Update bit deadline monitoring with timeout replacement
    0x20 : Filtering
    0x40 : Invalidation
    0x80 : Invalidation replacement with init value */
  uint8 ucRxSigConfig;
  /* Signal end position */
  PduLengthType ddSignalEndByte;
}Com_RxSignal;

/* Structure for   Rx signal in group. Generation tool should generate
structure consecutively for the signals within signal group. Generation tool
should first generate  signal in group structure for the signals that
have been configured for invalidation and then followed by the other signals
within signal group */
typedef struct STagCom_RxSigInGrp
{
  /* #7744 */
  /* Index to reference SignalGroup which include this GroupSignal */
  Com_SignalGroupIdType ddSigGrpIndex;
  /* Index of the Rx unpack structure array. This parameter is used to unpack
  the signal value from the shadow buffer. Generation tool should generate the
  appropriate array index of the Rx unpack structure array.*/
  Com_RxUnPackCountType ddRxUnpackIndex;
  #if(COM_RX_SIGGROUP_INVALID == STD_ON)
  /* Index of the  invalid structure array. Generation tool should generate the
  appropriate array index of the invalid structure array if the signal has been
  configured to check the invalidation otherwise it should have the value
  COM_INVALID_NONE */
  uint8 ucSigInGrpInvIndex;
  #endif
}Com_RxSigInGrp;

#if(COM_RX_SIGGROUP_INVALID == STD_ON)
/* Structure for  Rx signal group configured for invalidation */
typedef struct STagCom_RxInvSigGroup
{
  /* Pointer to signal group initialization value. Generation tool should
  point to the default value if the signal group has been configured for
  invalidation check with replace value otherwise it should point to NULL
  pointer */
  P2CONST(void, AUTOMATIC, COM_CONST)pInitValue;
  /* Index of the  invalid notification function pointer array. Generation tool
  should generate the appropriate array index of the invalid function array
  if the signal has been configured for the notification otherwise it should
  have the value COM_INVALID_NONE */
  Com_InvNotifCountType ddInvNotifCbkIndex;
  /* Index of the   Rx signal in group array. Generation tool should
  generate the appropriate array index of the signal in group array  */
  Com_SignalIdType ddRxSigInGrpIndex;
  /* Number of signal groups which are configured for invalidation. 
  Generation tool should generate the value based on the number of signals 
  configured for invalidation within signal group */
  uint8 ucNoOfSignal;
}Com_RxInvSigGroup;
#endif

/* Structure for  Rx Signal Group. Generation tool should generate
structure consecutively for the signal groups within I-PDU. Generation tool
should first generate Rx signal group structure for the signal group that has
been configured for invalidation or update bit notification or update bit
deadline monitoring or any other combinations and then followed by other signal
groups in an I-PDU */
typedef struct STagCom_RxSigGroup
{
  /* Pointer to an I-PDU buffer. Generation tool should provide the pointer to
  the start position of an I-PDU */
  P2VAR(uint8, AUTOMATIC, COM_VAR)pIpduBuffer;
  /* Pointer to the pack structure. Generation tool should point to the pack
  structure if the signal group has been configured for invalidation with
  replace value or deadline monitoring with timeout replacement otherwise
  it should point to NULL pointer */
  /* UB + Invalid + Invalid Replace or
  UB + UBDM + Timeout Replace (Signal Buffer) or Invalid + Invalid Replace or
  DM + Timeout Replace (I-PDU Buffer) */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)pPackSigGrpBuffer;
  /* Pointer to the pack structure. Generation tool should point to the pack
  structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)pPackShadowBuffer;
  /* #7744 */
  /*pointer to the maksing data for packing signal group.*/
  P2CONST(void, AUTOMATIC, COM_CONST) pMaskingBuffer;
  
  #if(COM_RX_SIGGROUP_UB == STD_ON)
  /* Pointer to an update bit position in an I-PDU. This parameter along with
  ucUbitMask is used to check whether data of signal group has been updated.
  Generation tool should provide the pointer to an update bit position in an
  I-PDU if the signal group has been configured for the update bit otherwise it
  should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR)pUBit;
  #endif
  /* Index of Rx Pdu to which signal belongs to */
  PduIdType ddRxpduId;
  #if(COM_RX_SIGGROUP_NOTIFY == STD_ON)
  /* Index of the notification function pointer array. This parameter is used
  to provide the notification to the upper layer immediately after the signal
  has been processed. Generation tool should generate the appropriate array
  index of the function array based on the configuration if the signal has been
  configured for the notification otherwise it should have the value
  COM_INVALID_NONE */
  Com_NotifCountType ddNotifCbkIndex;
  #endif
  #if(COM_RX_SIGGROUP_UBDM == STD_ON)
  /* Index of the  deadline monitoring structurer array. Generation tool should
  generate the appropriate array index of the RxDm structure if the signal with
  an update bit has been configured for deadline monitoring otherwise it should
  have the value COM_INVALID_NONE */
  uint8 ucRxUbDmIndex;
  #endif
  #if(COM_RX_SIGGROUP_INVALID == STD_ON)
  /* Index of the  invalid structure array. Generation tool should generate the
  appropriate array index of the invalid structure array if one of the signal in
  the signal group has been configured to check the invalidation otherwise it
  should have the value COM_INVALID_NONE */
  uint8 ucInvIndex;
  #endif
  #if(COM_RX_SIGGROUP_UB == STD_ON)
  /* Update bit mask value. Generation tool should generate appropriate update
  bit mask value based on the update bit position in an I-PDU */
  uint8 ucUbitMask;
  #endif
  /* Signal end position */
  PduLengthType ddSignalEndByte;
  /* Signal group configuration. Generation tool should generate the value
  based on the signal group configuration as per the given formulae:
    0x01: Notification
    0x02: Update Bit
    0x04: Update Bit with TimeOut
    0x08: Invalid Configuration
    0x10: Replace the value (Invalid Replacement )
    0x20: Replace the value (Timeout/Invalid Replacement) */
  uint8 ucSigGroupConfig;
  /* #7744 */
  #if(COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON)
  /* SignalGroup Array access */
  boolean blArrayAccess;
  #endif   
}Com_RxSigGroup;

/* Callout function input value is changed in 4.1.1 com specification 
- Fixed by AUTRON START*/
/* Structure for Rx I-PDU Callout function Generation tool should allocate
structure for all Rx I-PDU callout functions consecutively */
typedef struct STagCom_TxIpduCallout
{
  P2FUNC(boolean, COM_APPL_CODE, pIpduCallout)
  	(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_VAR)PduInfoPtr);
}Com_TxIpduCallOut;

typedef struct STagCom_RxIpduCallout
{
  P2FUNC(boolean, COM_APPL_CODE, pIpduCallout)
  	(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPtr);
}Com_RxIpduCallOut;
/* Callout function input value is changed in 4.1.1 com specification 
- Fixed by AUTRON END*/


/* Structure for Rx Ipdu PduInfoPtr */
typedef struct STagCom_RxPduInfoType
{
  /* The start address of the  Rx IPDU is present here */
  P2VAR(uint8, AUTOMATIC, COM_VAR) SduDataPtr;
  /* Pointer to a RAM variable containing the length of this IPDU.
     Depending on the type of the particular IPDU (TP or NORMAL),
     Generation tool should reference Com_GaaRxSduLength
     shall be referenced here*/
  P2VAR(PduLengthType, AUTOMATIC, COM_VAR) SduLength;
}Com_RxPduInfoType;


#if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
typedef struct STag_Com_RxIpduCounter
{
  /* Index of the RxUnpack structure array. This parameter is used to unpack
  the counter value from an I-PDU. Generation tool should generate the
  appropriate array index of Rx Unpack structure for the Ipdu counter */
  Com_RxUnPackCountType ddRxUnpackIndex;
 /* Index to Ipdu Counter buffer (&Com_GaaRxIpduCountVal[]) */
  uint8 ucRxIpduCountData;
  #if(COM_RX_COUNTER_NOTIFY == STD_ON)
  /* Index to Error call back structure. Generation tool should generate
  index of Com_GaaRxCntNotify, If counter notification is not configured
  COM_INVALID_NONE should be generated */
  uint8 ucRxCntNotifIndx;
  #endif
  /* Threshold value of I-PDU counter algorithm */
  uint8 ucIPduCounterThreshold;
  /* Index of the Ipdu Counter status array(Com_GaaRamIpduCounterSts). This
  parameter is used to update the Ipdu Counter status. Generation tool should
  allocate one bit RAM area for each RxIpdu structure. RAM area for the I-PDU
  group should be allocated consecutively and start at byte boundary */
  uint8 ucIpduCnterStsIndex;
  /* Ipdu Counter status mask value. Generation tool should generate the
  appropriate mask value for "Com_GaaRamIpduCounterSts" parameter in the
  structure */
  uint8 ucIpduCounterEnMask;
  /* Mask with size of I-PDU counter. Generation tool should generate mask based
  on counter size */
  uint8 ucRxIpduCntWrpMask;
  /* No. of bits by which to shift to get the counter value */
  uint8 ucRxIpduCounterShiftBits;
}Com_RxIpduCounter;
#endif

/* Structure for I-PDU Replication */
#if(COM_RX_REPLICATION == STD_ON)
typedef struct STag_Com_RxIpduReplication
{
  /* Pointer to an I-PDU buffer. Generation tool should generate the index of
  the Ipdu counter structure array */
  P2VAR(void, AUTOMATIC, COM_VAR) pIpduBuffer;
  /* Replicated I-PDUs count. Generation tool should allocate RAM area
  based on the number of replicated I-PDUs. This is based on configuration
  parameter "ComIPduReplicationQuorum" */
  uint8 ucIpduRepliCount;
  /* Index of the Ipdu Replication status array(Com_GaaRamIpduRepliSts). This
  parameter is used to update the Ipdu Replication status. Generation tool
  should allocate one bit RAM area for each RxIpdu structure. RAM area for the
  I-PDU group should be allocated consecutively and start at byte boundary */
  uint8 ucIpduRepliStsIndex;
  /* Ipdu Replication status mask value. Generation tool should generate the
  appropriate mask value for "Com_GaaRamIpduRepliSts" parameter in the
  structure */
  uint8 ucIpduRepliEnMask;
  /* Index to RAM array holding the replication count value i.e.,
  Com_GaaRxRepliCount. Since the maximum value of vote is 3
  2 bits should be allocated to each Ipdu configured for
  replication */
  uint8 ucIpduRepliCountIndex;
  /* Number of bits to shift the counter by to get it to LSB */
  uint8 ucIpduRepliCountShift;
}Com_RxIpduReplication;
#endif

#if(COM_RX_TP_SUPPORT == STD_ON)
typedef struct STagCom_RxTPIpdu
{
  #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
    /* Pointer to the double I-PDU buffer reserved in case Ipdu counter is 
       enabled for a TP Ipdu. In all other cases this element
       should be generated as NULL_PTR. It is a pointer to
       Com_GaaRxPduInfoDoublePtr  */
  P2CONST(Com_RxPduInfoType, AUTOMATIC, COM_CONST)pDoubleIpduBuffer;
  #endif
  /* Maximum size of the TP Ipdu. In case of Dynamic Ipdu's,
    this parameter should give the maximum possible size of the Ipdu (in bytes)
    i.e., the maximum size of the dynamic signal should be considered.
    */
  PduLengthType ddRxTPMaxIpduSize;
  /* Reference to Com_GaaTPStatus */
  uint8 ucRxTPStatusRef;
  /* Mask to Com_GaaTPStatus */
  uint8 ucRxTPStatusMask;
  /* Reference to Com_GaaRxIpduTPLength */
  uint8 ucRxIpduTPLengthRef;
}Com_RxTPIpdu;
#endif


/* Structure for Rx I-PDU. Generation tool should allocate structure for all Rx
 IPDU configured for Dm first and then followed by normal Ipdus */
typedef struct STagCom_RxIpdu
{
  #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
  /* Index to the relevant element of Com_GaaRxIpduCounter. If not configured
  COM_INVALID_RXID_PARAM should be present */
  PduIdType ddRxIpduCounter;
  #endif
  #if(COM_RX_SIGNAL == STD_ON)
  /* Index of the  Rx signal structure array. This parameter along with
  ucNoOfRxSignal is used to process Rx signals configured within an I-PDU.
  Generation tool should generate the index to the signal which is
  required to be processed. If no signals are configured for invalidation/
  filtering/UBDM/UB with notification, then the value should be
  COM_INVALID_SIGID_PARAM and "ucNoOfRxSignal" should be equal to zero */
  Com_SignalIdType ddRxSigIndex;
  #endif
  #if(COM_RX_SIGGROUP == STD_ON)
  /* Index of the  Rx signal group structure. This parameter along with
  ucNoOfRxSigGroup is used to process all Rx signal groups within an I-PDU.
  Generation tool should generate the index of the signal group which
  is required to be processed. If no signals within signal group have been
  configured for invalidation/UB with notification/UBDM with timeout replacement
  generation tool allocate the value COM_INVALID_SIGGRID_PARAM 
  and "ucNoOfRxSigGroup" should be equal to zero. */
  Com_SignalGroupIdType ddRxSigGrpIndex;
  #endif
  #if(COM_RX_IPDU_CALLOUT == STD_ON)
  /* Index of the I-PDU callout function pointer array. Generation tool should
  generate the appropriate array index of the function I-PDU callout function,
  if the I-PDU is configured for callout */
  PduIdType ddIpduCalloutIndex;
  #endif
  #if(COM_RX_IPDU_DM == STD_ON)
  /* Index of the  deadline monitoring structure array. Generation tool should
  generate the appropriate array index of the RxDm structure if the signal
  within I-PDU has been configured for I-PDU based deadline monitoring otherwise
  it should have the value COM_INVALID_RXID_PARAM */
  PduIdType ddRxIpduDmIndex;
  #endif
  #if(COM_RX_SIG_GATEWAY == STD_ON)
  uint8 ucRxGWStsIndex;
  #endif  
  #if(COM_RX_SIG_GATEWAY == STD_ON)
  /* Rx gateway status mask. Generation tool should generate the value based on
  RAM area allocated for pGWIpduSts parameter in the structure */
  uint8 ucRxGWStsMask;
  #endif
  #if(COM_RX_SIG_GATEWAY == STD_ON)  
  /* Index of Rx gateway information structure */  
  PduIdType ddRxGWIpduIndex;
  #endif  
  #if(COM_RX_SIGNAL == STD_ON)
  /* Number of Rx  signals. Generation tool should generate the value
  based on the signal configuration */
  uint8 ucNoOfRxSignal;
  #endif
  #if(COM_RX_SIGGROUP == STD_ON)
  /* Number of Rx  signal group. Generation tool should generate the
  value based on the configuration. */
  uint8 ucNoOfRxSigGroup;
  #endif
  /* uint8 -> PduLengthType for variable which has Pdu Length info 
  - Fixed by AUTRON START*/            
  /* Length of an Rx Ipdu */
  PduLengthType ddRxIpduLength;
  /* uint8 -> PduLengthType for variable which has Pdu Length info 
  - Fixed by AUTRON END*/          
  #if(COM_RX_REPLICATION == STD_ON)
  /* Index to Ipdu Replication structure. Generation tool should generate the
  value based on the configuration. If I-PDU counter is not configured
  generation tool should generate it as COM_INVALID_NONE */
  uint8 ucRxIpduRepliIndex;
  #endif
  #if(COM_RX_TP_SUPPORT == STD_ON)
  /* Index to struture of type Com_RxTPIpdu i.e variables of type
     Com_GaaRxTPIpdu. This should be valid only if the Ipdu is of type TP.
     For Normal Ipdu's this parameter should be generated as COM_INVALID_NONE.*/
  uint8 ucRxTPRef;
  #endif
  /* #2142 : separate DYN PDU from TP */
  /* Indicates the type of Ipdu 0x00 - Normal, 0x01 - Dynamic */
  uint8 ucIpduType;

  #if(COM_RX_DYN_SUPPORT == STD_ON)
  /* Sum of lengths of all the non Dynamic signals in the
     Ipdu. This parameter will provide  the number of bytes that are
     NOT occupied by the Dynamic signal. For non-dynamic signals,
     this parameter should be COM_INVALID_LENGTH_PARAM */
  PduLengthType ddRxNonDynLength;
  #endif

  #if(COM_RX_DYN_SUPPORT == STD_ON)
  /* Index of the array Com_GaaRxDynSigLength[]. If this instance of the pack
     struture is mapped to a dynamic signal, then Com_GaaRxDynSigLength[] shall
     hold the latest length of the dynamic signal. For non-dynamic signals,
     this parameter should be COM_INVALID_RXID_PARAM */
  PduIdType ddRxIpduDynLegthRef;
  #endif  
  
  /* Rx configuration
     0x01: Deferred
     0x02: Plain notification
     0x04: Gateway
     0x08: Signal
     0x10: Signal Group
     0X20: Deadline Monitoring
     0x40: Ipdu with one every N
  */
  uint8 ucRxConfig;
}Com_RxIpdu;

/* Structure for I-PDU group */
typedef struct STagCom_IpduGroup
{
  /* Index to Rx Ipdu */
  PduIdType ddRxIpduIndex;
  /* Index to Tx Ipdu */
  PduIdType ddTxIpduIndex;
  /* Number of Rx I-PDUs. Generation tool should generate the value based on
  the number of Rx I-PDUs within Rx I-PDU group */
  PduIdType ddNoOfRxIpdus;
  /* Number of Tx I-PDUs. Generation tool should generate the value based on
  the number of Tx I-PDUs within Tx I-PDU group */
  PduIdType ddNoOfTxIpdus;
  /* Number of Rx I-PDU group. Generation tool should generate the value based
  on the number of Rx I-PDU groups within an Rx I-PDU group */
  uint8 ucNoOfIpduGroups;
  /* Index to Ipdu Group Status Array */
  uint8 ucGroupIndex;
  /* Status Mask */
  uint8 ucStatusMask;
  /* Flag indicating if Rx DM is configured for any Ipdu in this group */
  boolean blRxDmEnabled;
}Com_IpduGroup;

/******************************************************************************/


/*******************************************************************************
**             Structure related to Mode Selection for Tx Ipdu                **
*******************************************************************************/

/*******************************************************************************
**               Structure related to Tx                             **
*******************************************************************************/
/* Structure for Tx deadline monitoring. */
typedef struct STagCom_TxIpduDm
{
  /* Deadline monitoring timeout. Generation tool should generate the value
  based on the configuration. Generation tool should generate to the least
  timeout value configured across all signals within an I-PDU */
  uint16 usDmTimeout;
  /* Index of the notification error call-back structure array. This parameter
  along with ucNoOfSigErrorCbk is used to generate the number of timeout
  notifications to the upper layer immediately after the transmission timeout
  error has been detected by the deadline monitoring mechanism. Generation tool
  should generate the appropriate array index of the signal notification error
  structure array */
  Com_ErrCbkCountType ddSigErrCbkIndex;
  /* Number of notification error call-back functions. Generation tool should
  generate the value based on the number of signals configured for deadline
  monitoring */
  uint8 ucNoOfSigErrorCbk;
  /* Index to Com Tx PDU */
  PduIdType ddComTxPduId;
  #if(COM_TX_CANCEL_SUPPORT == STD_ON)
  /* This boolean flag indicates if ComTxIPduCancelTransmitSupport is configured
  to true or not. It shall be generated as COM_TRUE in case the parameter
  is configured. Else, it shall be generated as COM_FALSE -- TBD. Is having
  it as boolean ok?*/
  boolean blCancelTxFlag;
  #endif
}Com_TxIpduDm;

/* Structure for Tx confirmation. Generation tool should generate the following
structure if the signals within Tx I-PDU has been configured for deadline
monitoring or transmit confirmation. Generation tool should generate the
structure consecutively within Tx I-PDU group */
typedef struct STagCom_TxIpduConfirm
{
  /* Index of the signal notification call-back structure array. This parameter
  along with "ucNoOfImmSigCallback" and "ucNoOfDefSigCallback" is used to
  generate the notifications to the upper layer immediately after the
  succcessful transmission of the I-PDUs containing signals. Generation tool
  should provide the index of the notification callback structure array if the
  signal within I-PDU has been configured for the notification otherwise it
  should have the value COM_INVALID_NONE */
  Com_NotifCountType ddSigNotifCbkIndex;
  /* Index of the notification error call-back structure array. This parameter
  along with ucNoOfSigErrorCbk is used to generate the number of timeout
  notifications to the upper layer immediately after the transmission timeout
  error has been detected by the deadline monitoring mechanism. Generation tool
  should generate the appropriate array index of the signal notification error
  structure array */
  Com_ErrCbkCountType ddSigErrCbkIndex;

  /* Number of immediate call-back functions. Generation tool should generate
  the value based on the I-PDU processing mode. For "Immediate mode", the value
  should be generated based on the signals which are configured for the
  notification otherwise the value should be zero */
  uint8 ucNoOfSigCallback;
  /* Number of error notification call-back functions. Generation tool should
  generate the value based on the number of signals configured for error
  notification */
  uint8 ucNoOfSigErrorCbk;
}Com_TxIpduConfirm;

/* Structure for Tx mode. Generation tool should generate the structure
consecutively for Tx I-PDUs */
typedef struct STagCom_TxMode
{
  /* Offset value. Generation tool should generate the value based on the
  configuration */
  uint16 usOffsetValue;
  /* Period value. Generation tool should generate the value based on the
  configuration */
  uint16 usPeriodicValue;
  #if(COM_TX_IPDU_REPETITION == STD_ON)
  /* Repetition timer value. Generation tool should generate the value based on
  the configuration */
  uint16 usReptTimerValue;
  /* Repetition counter value. Generation tool should generate the value based
  on the configuration */
  uint8 ucReptCount;
  #endif
  /* 0: None
     1: Periodic
     2: Mixed
     3: Mixed/Direct with n-times
     4: Direct
  */
  uint8 ucTxMode;
}Com_TxMode;

/*******************************************************************************
**             Structure related to Mode Selection for Tx Ipdu                **
*******************************************************************************/
#if(COM_TX_IPDU_TMS == STD_ON)
typedef struct STagCom_TxIpduModeSel
{
  /* Pointer to filter status. Generation tool should provide the pointer to
  first pTxFilterStatus byte if the signal within Tx I-PDU has been configured
  for the filter otherwise it should point to NULL pointer */
  uint8 ucFilterStatusIndex;
  /* Number of filter status Byte. Generation tool should generate the value
  based on the number of signals that has been configured for the filtering
  otherwise it should be zero */
  uint8 ucFilterStatusCount;
}Com_TxIpduModeSel;
#endif

#if((COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON))
/* Structure for Tx Update bit */
typedef struct STagCom_TxUpdateBit
{
  /* Pointer to an update bit. This parameter along with I-PDU size
  is used to clear the update bits in an I-PDU after being transmitted to the
  lower layer. Generation tool should generate the pointer to Tx I-PDU mask
  array if the signal within I-PDU has been configured for the update bit
  otherwise it should point to NULL pointer */
  P2CONST(uint8, AUTOMATIC, COM_CONST)pUbitsTxIpduMask;
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON START*/  
  /* Start byte position of an update bit in an I-PDU */
  uint16 ucStartPosition;
  /* End byte position of an update bit in an I-PDU */
  uint16 ucEndPosition;
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON END*/  
  /* Update bit configuration */
  uint8 ucUBConfig;
}Com_TxUpdateBit;
#endif

#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
/* Structure for Tx I-PDU Counter */
typedef struct STag_Com_TxIpduCounter
{
  /* Index of the Tx Pack structure. This parameter is used to pack the counter
  value into I-PDU buffer. Generation tool should generate the index of the
  Tx pack structure array */
  Com_TxPackCountType ddTxPackIndex;
  /* Index to Ipdu Counter buffer (&Com_GaaTxIpduCountVal[]) */
  uint8 ucTxIpduCountData;
  /* Mask with size of I-PDU counter. Generation tool should generate mask based
  on counter size and position in the byte in which it is present. This
  together with ucTxIpduCountData will be used to decide the position of
  the counter bits during runtime */
  uint8 ucTxIpduCntWrpMask;
  /* No. of bits by which to shift to get the counter value */
  uint8 ucTxIpduCounterShiftBits;
}Com_TxIpduCounter;
#endif

#if(COM_TX_TP_SUPPORT == STD_ON)
typedef struct STagCom_TxTPIpdu
{
  /* Reference to Com_GaaTxIpduTPLength */
  uint8 ucTxIpduTPLengthRef;
  /* Reference to Com_GaaTPStatus. For a non-TP Ipdu, this should be
     COM_INVALID_NONE */
  uint8 ucTxTPStatusRef;
  /* Mask to Com_GaaTPStatus. For a non-TP Ipdu, this should be
     COM_INVALID_NONE */
  uint8 ucTxTPStatusMask;
}Com_TxTPIpdu;
#endif

/* Structure for Tx I-PDU. Generation tool should place the Tx I-PDU structure
consecutively for the Tx I-PDU group */
typedef struct STagCom_TxIpdu
{
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to TxIpdu Mode Selection. Generation tool should provide the
  pointer to TxIpdu Mode Selection Configuration otherwise it should point
  to NULL pointer */
  P2CONST(Com_TxIpduModeSel, AUTOMATIC, COM_CONST) pTxModeSelect;
  #endif
  #if((COM_TX_SIGNAL_NOTIFY == STD_ON) || (COM_TX_IPDU_DM == STD_ON))
  /* Index to Tx confirmation structure. Generation tool should generate the
  pointer to the Tx confirmation structure if the signal within Tx I-PDU has
  been configured for the notification or deadline monitoring */
  PduIdType ddTxPduConfirmIndex;
  #endif

  #if((COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON))
  /* Pointer to update bit structure */
  PduIdType ddTxIpduUbIndex;
  #endif

  /* Index of the periodic timer array. Generation tool should allocate 16 bit
  RAM area if one of the transmission mode has been configured as "periodic"
  otherwise it should have the value COM_INVALID_TXID_PARAM */
  PduIdType ddTxPeriodicTimerIndex;

  /* Index to true transmission mode */
  PduIdType ddTrueTxModeIndex;

  /* TxPduId value. Generation tool should generate the short name based on the
  Pdu Router configuration */
  PduIdType ddTxIpduId;

  #if(COM_TX_IPDU_MINDELAY == STD_ON)
  /* Index of the Minimum Delay Timer array. Generation tool should provide the
  index of the Minnimum Delay Timer configuration array otherwise it should have
  the value COM_INVALID_TXID_PARAM */
  PduIdType ddTxMDTimerIndex;
  #endif
  #if(COM_TX_IPDU_REPETITION == STD_ON)
  /* Index of the repetition Structure array. Generation tool should
  generate the appropriate index of the repetition timer structure array
  if Ipdu repetition is configured */
  PduIdType ddTxReptIndex;
  #endif

  #if(COM_TX_IPDU_DM == STD_ON)
  /* Index of the  deadline monitoring structurer array. Generation tool should
  generate the appropriate array index of the I-PDU based deadline monitoring
  structure if deadline monitoring has been configured otherwise it should have
  the value COM_INVALID_TXID_PARAM */
  PduIdType ddTxIpduDmIndex;
  #endif

  #if(COM_TX_IPDU_CALLOUT == STD_ON)
  /* Index of  to I-PDU callout function pointer array. Generation tool should
  provide the appropriate index of the I-PDU callout function array, if the
  I-PDU is configured for callout */
  PduIdType ddIpduCalloutIndex;
  #endif

  #if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
  /* Index of  to I-PDU callout function pointer array. Generation tool should
  provide the appropriate index of the I-PDU callout function array, if the
  I-PDU is configured for callout */
  PduIdType ddIpduTriggerCalloutIndex;
  #endif

  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
  /* Index to the relevant element of Com_GaaTxIpduCounter. If not configured
  COM_INVALID_NONE should be present */
  PduIdType ddTxIpduCounter;
  #endif

  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Index to struture of type Com_TxTPIpdu i.e variables of type
     Com_GaaTxTPIpdu. This should be valid only if the Ipdu is of type TP.
     For Normal Ipdu's this parameter should be generated as COM_INVALID_NONE.*/
  uint8 ucTxTPRef;
  #endif

  /* #2142 : separate DYN PDU from TP */
  /* Indicates the type of Ipdu 0x00- NORMAL, 0x01 - DYNAMIC */
  uint8 ucIpduType;

  #if(COM_TX_DYN_SUPPORT == STD_ON)
  /* Sum of lengths of all the non Dynamic signals in the
     Ipdu. This parameter will provide  the number of bytes that are
     NOT occupied by the Dynamic signal. Should be generated even for 
     non dynamic signals */
  PduLengthType ddTxNonDynLength;
  #endif
  
  #if(COM_TX_DYN_SUPPORT == STD_ON)
  /* Index of the array Com_GaaTxDynSigLength[]. If this instance of the pack
     struture is mapped to a dynamic signal, then Com_GaaTxDynSigLength[] shall
     hold the latest length of the dynamic signal. For non-dynamic signals,
     this parameter should be COM_INVALID_TXID_PARAM */
  PduIdType ddTxIpduDynLegthRef;
  #endif  

  /*
  0x0001: TMS
  0x0002: IpduCallout
  0x0004: TriggerIpduCallout
  0x0008: Deadline Monitoring
  0x0010: Minimum Delay Timer
  0x0020: Signal Notification
  0x0040: Immediate or Deferred
  0x0080: Update bit
  */
  uint8 ucTxConfig;
  #if(COM_API_MODE_SWITCH_ENABLED == STD_ON)
  /*
  0x0001: For API Com_SwitchIpduTxMode i.e., TRUE and 
          FALSE modes are configured but filters are not present
  NOTE:   The remaining bits are reserved for future use
  */
  uint8 ucTxConfigExtn;
  #endif
}Com_TxIpdu;

/* Structure for Tx signal. Generation tool should generate all the Tx
signals consecutively which are routed through a Rx signal */
typedef struct STagCom_TxSignal
{
  #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
  /* Pointer to invalid data. This parameter is used to hold the previous Tx
  data of the signal. Generation tool should provide pointer to the signal
  buffer for the signal if signal has been configured for Trigger on change
  otherwise it should point to NULL pointer */
  P2VAR(void, AUTOMATIC, COM_VAR)pSignalBuffer;
  #endif

  #if(COM_TX_SIGNAL_INVALID == STD_ON)
  /* Pointer to invalid data. This parameter is used to provide invalid value
  of the signal whenever Com_InvalidateSignal() is invoked by the upper layer.
  Generation tool should provide pointer to the Invalid data for the signal if
  signal has been configured for invalidation otherwise it should point to NULL
  pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pInvalidData;
  #endif
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter object. Depending upon the type of the filter, generation
  tool should provide the pointer to appropriate filter structure. If signal
  has not been configured for the filtering, generation tool should provide
  pointer to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pFilter;
  #endif
  #if(COM_TX_SIGNAL_UB == STD_ON)
  /* Pointer to update bit. This parameter along with ucUbitMask is used to set
  the update bit in the I-PDU. Generation tool should provide the pointer to
  update bit position in an I-PDU, if the signal has been configured for an
  update bit otherwise it should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pUbit;
  #endif
  /* Index of the Tx I-PDU structure. Generation tool should generate the
  index of the Tx I-PDU structure array */
  PduIdType ddTxIpduIndex;
  /* Index of the Tx Pack structure. This parameter is used to pack the signal
  data into I-PDU buffer. Generation tool should generate the index of the
 Tx pack structure array */
  Com_TxPackCountType ddTxPackIndex;
  /* Signal configuration. Generation tool should generate the value based
  on following formulae depending upon signal configuration:
    7: Signal configured for deadline monitoring
    6: Signal configured for update bit
    5: Gateway Signal
    2-4: Signal transfer property
      001: Pending
      010: Triggered
      011: Triggered wo repetition
      111: Triggered on Change wo Repetition
      110: Triggered on Change
    1: Signal configured for TMS
    0: TMS Selection - reserved for intexternal use default value should be 0
  */
  uint8 ucTxSigConfig;

  #if(COM_TX_SIGNAL_UB == STD_ON)
  /* Update bit mask. Generation tool should generate the value based on update
  bit position in an I-PDU */
  uint8 ucUbitMask;
  #endif
  #if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON START*/  
  /* Signal BitSize */
  uint16 usBitSize;
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON END*/    

  /* Signal Type */
  uint8 ucType;  
  #endif  
}Com_TxSignal;


/* Structure for Tx signal in group. Generation tool should generate
all the Tx signals in group consecutively which are routed through Rx signals in
group */
typedef struct STagCom_TxSigInGrp
{
  /* #7705 */
  #if((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON))
  /* Pointer to invalid data. This parameter is used to hold the previous Tx
  data of the signal. Generation tool should provide pointer to the signal
  buffer for the signal if signal has been configured for Trigger on change
  otherwise it should point to NULL pointer */
  P2VAR(void, AUTOMATIC, COM_VAR)pSignalBuffer;
  #endif
  
  /* Index to reference SignalGroup which include this GroupSignal */
  Com_SignalGroupIdType ddSigGrpIndex;
  
  #if(COM_TX_SIGINGROUP_INVALID == STD_ON)
  /* Pointer to invalid data. This parameter is used to provide invalid value of
  the signal whenever Com_InvalidateSignal() is invoked by the upper layer.
  Generation tool should provide pointer to the invalid data for the signal if
  signal has been configured for invalidation otherwise it should point to
  NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pInvalidData;
  #endif
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter object. Depending upon the type of the filter, generation
  tool should provide the pointer to appropriate filter structure. If signal
  has not been configured for the filtering, generation tool should provide
  pointer to NULL pointer */
  P2CONST(void, AUTOMATIC, COM_CONST) pFilter;
  #endif
  /*  Index of the Tx Pack structure. This parameter is used to pack the signal
      data into I-PDU buffer. Generation tool should generate the index of the
      Tx pack structure array */
  Com_TxPackCountType ddTxPackIndex;
  #if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON START*/  
  /* Signal BitSize */
  uint16 usBitSize;
  /* uint8 -> uint16 for supporting huge data - Fixed by AUTRON END*/    

  /* Signal Type */
  uint8 ucType;  
  #endif
  /* #7705 */
  #if((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON))
  /*
    2-4: Signal transfer property
    001: Pending
    110: Triggered on Change
  */
  uint8 ucTxSigConfig;
  #endif
}Com_TxSigInGrp;

typedef struct STagCom_TxGroupSignal
{
  Com_SignalIdType ddSignalId;
}Com_TxGroupSignal;


typedef struct STagCom_TxSigGrpModeSel
{
  /* Pointer to filter status. Generation tool should provide the pointer to
  first pTxFilterStatus byte if the signal within Signa Group has been
  configured for the filter */
  uint8 ucFilterStatusIndex;
  /* Number of filter status Byte. Generation tool should generate the value
  based on the number of signals that has been configured for the filtering
  otherwise it should be zero */
  uint8 ucNoOfFilterStsByte;
  /* Pointer to filter status index to Ipdu. Generation tool should provide the
  index if the signal within Tx I-PDU has been configured for the filter  */
  uint8 ucIpduFilterStsIndex;
  /* Mask to filter status index to Tx Ipdu */
  uint8 ucFilterStatusMask;

}Com_TxSigGrpModeSel;

/* Structure for Tx signal group. Generation tool should generate
all the Tx signal groups consecutively which are routed through a Rx signal
group */
typedef struct STagCom_TxSigGrp
{
  /* Pointer to shadow buffer. This parameter is used to copy the shadow buffer
  data to I-PDU buffer. Generation tool should provide the pointer to first
  byte of the shadow buffer */
  P2CONST(void, AUTOMATIC, COM_CONST) pShadowBuffer;
  
  /* #7429 */
  /* Pointer to the maksing data for packing signal group */
  P2CONST(void, AUTOMATIC, COM_CONST) pMaskingBuffer;
  
  #if(COM_TX_SIGGROUP_UB == STD_ON)
  /* Pointer to update bit. This parameter along with ucUbitMask is used to set
  the update bit in the I-PDU. Generation tool should provide the pointer to an
  I-PDU buffer if the signal has been configured for an update bit otherwise it
  should point to NULL pointer */
  P2VAR(uint8, AUTOMATIC, COM_VAR) pUbit;
  #endif
  /* Index of the Tx Pack structure. This parameter is used to pack the signal
  group data into I-PDU buffer. Generation tool should generate the index of the
  Tx pack structure array */
  Com_TxPackCountType ddTxSigGrpPackIndex;
  #if(COM_TX_SIGINGROUP_INVALID == STD_ON)
  /* Index of the  group signals array. Generation Tool should generate
  all Tx signal in group consecutively. If signal group is not configured for
  invalidation, generation tool should generate the value 
  COM_INVALID_SIGID_PARAM otherwise it should generate the index of the group 
  signal array for which invalidation is configured */
  Com_SignalIdType ddTxGrpSigIndex;
  #endif
  /* Index of the Tx I-PDU structure. Generation tool should generate the
  index of the Tx I-PDU structure array */
  PduIdType ddTxIpduIndex;
  #if(COM_TX_SIGGROUP_TMS == STD_ON)
  /* Index to TxSigGrpModeSel structure */
  uint8 ucTxSigGrpModeSelIndex;
  #endif
  /* Signal group configuration. Generation tool should generate the value based
  on following formula depending upon signal group configuration:
    7: Signal configured for deadline monitoring
    6: Signal configured for update bit
    5: Gateway Signal
    2-4: Signal transfer property
      001: Pending
      010: Triggered
      011: Triggered wo repetition
      111: Triggered on Change wo Repetition
      110: Triggered on Change
    1: Signal configured for TMS
    0: TMS Selection - reserved for intexternal use default value should be 0
  */
  uint8 ucTxSigGrpConfig;
  #if(COM_TX_SIGGROUP_UB == STD_ON)
  /* Update bit mask. Generation tool should generate the value based on update
  bit position in an I-PDU */
  uint8 ucUbitMask;
  #endif
  #if(COM_TX_SIGINGROUP_INVALID == STD_ON)
  /* Group Signal Count */
  uint8 ucGroupSignalCount;
  #endif
  /* #7705 */
  /* Pointer to reference On Change Status memory for handling Sub configuration of Group Signal */
  #if((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON))
  P2VAR(uint8, AUTOMATIC, COM_VAR)pOnChangeStatus;
  #endif
  /* #7525 */
  #if(COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON)
  /* SignalGroup Array access */
  boolean blArrayAccess;
  #endif    
}Com_TxSigGrp;

/*******************************************************************************
**               Structure related to Gateway                                 **
*******************************************************************************/

/* Structure for  gateway signal */
typedef struct STagCom_RxGWSignal
{
  #if(COM_RX_SIGNAL_UB == STD_ON)
  /* Pointer to an update bit at Rx side. This parameter along with ucUbitMask
  is used to check the status of update bit before gatewaying the signal. If the
  Rx signal does not have any update bit, generation tool should generate the
  NULL pointer */
  P2CONST(uint8, AUTOMATIC, COM_CONST) pUBit;
  #endif
  /* Index of the Tx signal array. Generation tool should point to
  corresponding transmit signal. In case of an I-PDU containing signals to be
  routed completely via a transmit I-PDU by retention the signal order and the
  signal endianness, generation tool should point to the Tx signal structure
  which contains the pack information for an I-PDU and the signal transfer
  property. In case when I-PDU is completely routed and if the signal within an
  I-PDU does have different transfer property, it should point to
  "COM_TRIGGERED" */
  Com_SignalIdType ddTxSigIndex;
  /* Index of the Rx unpack structure array. Generation tool should point to the
  same unpack structure at Rx side if network byte ordering and CPU byte
  ordering are same or signal has been configured for filtering. In case of an
  I-PDU containing signals to be routed completely via a transmit I-PDU by
  retention the signal order and the signal endianness, generation tool should
  point to the unpack structure which contains the pointer to an I-PDU buffer,
  start mask of an I-PDU, end mask of an I-PDU and I-PDU size count */
  Com_RxUnPackCountType ddRxUnpackIndex;
  #if(COM_RX_SIGNAL_UB == STD_ON)
  /* Update bit mask */
  uint8 ucUbitMask;
  #endif
  /* Number of routed signals */
  uint8 ucNoOfRouteSignal;
  /* Signal Gateway action when timeout is occurred*/
  boolean blDMTrigger;
}Com_RxGWSignal;

/* Structure for  gateway Rx signal in group. Generation tool should
generate the structure consecutively for signals within signal group configured
for gateway */
typedef struct STagCom_RxGWSigInGrp
{
  /* Index of the Rx unpack structure array. Generation tool should point to the
  same unpack structure at Rx side if network byte ordering and CPU byte
  ordering are same or signal has been configured for filtering. In case of an
  I-PDU containing signals to be routed completely via a transmit I-PDU by
  retention the signal order and the signal endianness, generation tool should
  point to the unpack structure which contains the pointer to an I-PDU buffer,
  start mask of an I-PDU, end mask of an I-PDU and I-PDU size count */
  Com_RxUnPackCountType ddRxUnpackIndex;
  /* Index to Tx signal in group. This parameter along with
  ucNoOfRouteSigInGrp is used to route Rx signal in group to configured Tx
  signal in group. Generation tool should allocate Tx signal in group structure
  consecutively for signal in group which are routed through a Rx signal in
  group. Generation tool should point to index of transmit signal in group */
  Com_SignalIdType ddTxSigIndex;
  /* Number of signals in group to be routed */
  uint8 ucNoOfRouteSigInGrp;
}Com_RxGWSigInGrp;

/* Structure for  gateway Rx signal group. */
typedef struct STagCom_RxGWSigGroup
{
  /* Pointer to Rx update bit position in an I-PDU. This parameter along with
  ucRxUbitMask is used to check the update bit status in an I-PDU */
  /* Insert update bit configuration featuring by AUTRON #938 */
  #if(COM_RX_SIGGROUP_UB == STD_ON)
  P2CONST(uint8, AUTOMATIC, COM_CONST) pRxUBit;
  #endif  
  /* Index of the Rx  gateway signal in group array. This parameter
  along with ucNoOfSigInGrp is used to process all Rx signals within group and
  pack the data into shadow buffer to corresponding transmit signal in signal
  group */
  Com_SignalIdType ddRxSigInGrpIndex;
  /* Index of the Tx signal group array. This parameter is used to copy
  the data from the shadow buffer to I-PDU buffer and trigger an I-PDU to the
  lower layer if signal group property is configured as "Triggered" */
  Com_SignalGroupIdType ddTxSigGrpIndex;
  /* Number of signals in group */
  uint8 ucNoOfSigInGrp;
  /* Update bit mask value. Depending upon the update bit position in an I-PDU,
  generation tool should generate the mask value */
  /* Insert update bit configuration featuring by AUTRON #938 */
  #if(COM_RX_SIGGROUP_UB == STD_ON)  
  uint8 ucRxUbitMask;
  #endif
  /* Number of Tx signal groups routed by Rx signal groups */
  uint8 ucNoOfRouteSigGroup;
  /* Signal Gateway action when timeout is occurred*/
  boolean blDMTrigger;
}Com_RxGWSigGroup;

/* Structure for Rx I-PDU configured for gateway */
typedef struct STagCom_RxGWIpdu
{
  /* Index of the Rx  gateway signal array. This parameter along with
  ucNoOfRxGWSignal is used to process all  Rx signals within an I-PDU
  configured for gateway */
  Com_SignalIdType ddGWRxSigIndex;
  /* Index of the Rx  gateway signal group array. This parameter along
  with ucNoOfRxGWSigGroup is used to process all  Rx signal groups
  within an I-PDU configured for gateway */
  Com_SignalGroupIdType ddGWRxSigGrpIndex;
  /* Number of Rx gatewayed signal. Generation tool should generate the value
  based on the number of signals in an I-PDU configured for gateway */
  uint8 ucNoOfRxGWSignal;
  /* Number of Rx gatewayed signal groups. Generation tool should generate the
  value based on the number of signal groups in an I-PDU configured for
  gateway */
  uint8 ucNoOfRxGWSigGroup;
}Com_RxGWIpdu;

/* Structure for gateway callout definition */
#if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)  
typedef boolean (*pGWSigCalloutFunctionPtr)
  (P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr,
   uint8 SigGWStatus);
#endif

/* Structure for Tx Signal configured for gateway callout */
typedef struct STagCom_TxGWSignal
{
  /*Index of the Tx signal array*/
  Com_SignalIdType ddGWTxSigIndex;
  #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON) 
  /*Signal gateway callout's configured action*/   
  uint8 ucGWCalloutAction;
  #endif

  #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)  
  /*Signal gateway callout's configured function pointer*/     
  pGWSigCalloutFunctionPtr ddGWCalloutFunctionPtr;  
  #endif
}Com_TxGWSignal;


typedef signed int Com_PtrType;

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if(COM_TX_IPDU_MDT_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_16
#include "MemMap.h"
/* Global array for allocating RAM area of Tx Update bit masks */
extern CONST(uint16, COM_CONST) Com_GaaTxMDTimeout[COM_TX_IPDU_MDT_COUNT];
#define COM_STOP_SEC_CONST_16
#include "MemMap.h"
#endif

#if(COM_NO_OF_FILTER_ONEVERYN > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for FilterOneEveryN structure */
extern CONST(Com_FilterOneEveryN, COM_CONST)
Com_GaaFilterOneEveryN[COM_NO_OF_FILTER_ONEVERYN];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for InvalidFuncPtr structure */
extern CONST(Com_InvalidFuncPtr, COM_CONST) Com_GaaInvalidFuncPtr[COM_NINE];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Validate old data in case if signal /signal group transfer
property is configued as COM_TRIGGERED_ON_CHANGE */
extern CONST(Com_ValidateValue, COM_CONST) Com_GaaValidateValue[COM_FIVE];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(COM_WR_FUNC_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for WrFuncPtr structure */
extern CONST(Com_WrFuncPtr, COM_CONST) Com_GaaWrFuncPtr[COM_WR_FUNC_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif


#if(COM_SIG_WR_FUNC_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for SigWrFuncPtr structure */
extern CONST(Com_SigWrFuncPtr, COM_CONST)
Com_GaaSigWrFuncPtr[COM_SIG_WR_FUNC_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_SIG_RD_FUNC_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for SigRdFuncPtr structure */
extern CONST(Com_SigRdFuncPtr, COM_CONST)
Com_GaaSigRdFuncPtr[COM_SIG_RD_FUNC_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_CALLOUT_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Rx IpduCallout structure */
extern CONST(Com_RxIpduCallOut, COM_CONST)
Com_GaaRxIpduCallOut[COM_RX_IPDU_CALLOUT_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_CALLOUT_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Tx IpduCallout structure */
extern CONST(Com_TxIpduCallOut, COM_CONST)
Com_GaaTxIpduCallOut[COM_TX_IPDU_CALLOUT_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_SIG_NOTIF_CBK_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for SigNotifCbk structure */
extern CONST(Com_SigNotifCbk, COM_CONST)
Com_GaaSigNotifCbk[COM_SIG_NOTIF_CBK_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_INVALIDNOTIFY == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for InvalidSigNotifCbk structure */
extern CONST(pInvSigNotifCbkPtr, COM_CONST)
Com_GaaInvNotifCbk[COM_INV_NOTIF_CBK_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_SIG_ERROR_CBK_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for SigErrorCbk structure */
extern CONST(Com_SigErrorCbk, COM_CONST)
Com_GaaSigErrorCbk[COM_SIG_ERROR_CBK_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_IPDUGROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxIpduGroup structure */
extern CONST(Com_IpduGroup, COM_CONST)Com_GaaIpduGroup[COM_IPDUGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxIpdu structure */
extern CONST(Com_TxIpdu, COM_CONST)Com_GaaTxIpdu[COM_TX_IPDU_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_DM_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxIpduDm structure */
extern CONST(Com_TxIpduDm, COM_CONST)Com_GaaTxIpduDm[COM_TX_IPDU_DM_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_CONFIRM > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxIpduCnfrm structure */
extern CONST(Com_TxIpduConfirm, COM_CONST)
Com_GaaTxIpduConfirm[COM_TX_IPDU_CONFIRM];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_MODE_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxMode structure */
extern CONST(Com_TxMode, COM_CONST)Com_GaaTxMode[COM_TX_MODE_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_SIGNAL_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxSignal structure */
extern CONST(Com_TxSignal, COM_CONST) Com_GaaTxSignal[COM_TX_SIGNAL_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxSigInGrp structure */
extern CONST(Com_TxSigInGrp, COM_CONST)
Com_GaaTxSigInGrp[COM_TX_SIGINGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_SIGGROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxSigSignal structure */
extern CONST(Com_TxSigGrp, COM_CONST) Com_GaaTxSigGroup[COM_TX_SIGGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_SIGINGROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxGroupSignal structure */
extern CONST(Com_TxGroupSignal, COM_CONST) 
Com_GaaTxGroupSignal[COM_TX_SIGINGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* Array size calculation error - Fixed by AUTRON START*/  
#if(COM_PACK_FUNC_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxPack structure */
extern CONST(Com_TxPack, COM_CONST) Com_GaaTxPack[COM_PACK_FUNC_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
/* Array size calculation error - Fixed by AUTRON END*/  
  
#if(COM_RX_IPDU_GROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxIpduGroup structure */
extern CONST(PduIdType, COM_CONST)Com_GaaRxIpduGroup[COM_RX_IPDU_GROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_GROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for TxIpduGroup structure */
extern CONST(PduIdType, COM_CONST)Com_GaaTxIpduGroup[COM_TX_IPDU_GROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxIpdu structure */
extern CONST(Com_RxIpdu, COM_CONST)Com_GaaRxIpdu[COM_RX_IPDU_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_DM_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxDm structure */
extern CONST(Com_RxDm, COM_CONST)Com_GaaRxDm[COM_RX_IPDU_DM_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* Global array for RxInvalid structure */
#if(COM_RX_SIGNAL_INVALID == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Com_RxInvalid, COM_CONST) Com_GaaRxInvalid[COM_RX_INV_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* Global array for RxSigInGrpInv structure */
#if(COM_RX_SIGGROUP_INVALID == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Com_RxSigInGrpInv, COM_CONST) 
Com_GaaRxSigInGrpInv[COM_RX_SIG_INGRP_INV_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_SIGNAL_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxSignal structure */
extern CONST(Com_RxSignal, COM_CONST) Com_GaaRxSignal[COM_RX_SIGNAL_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_SIGGROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxSigGroup structure */
extern CONST(Com_RxSigGroup, COM_CONST)
Com_GaaRxSigGroup[COM_RX_SIGGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_SIGINGROUP_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxSigInGrp structure */
extern CONST(Com_RxSigInGrp, COM_CONST)
Com_GaaRxSigInGrp[COM_RX_SIGINGROUP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxInvSigGroup structure */
#if(COM_RX_SIGGROUP_INVALID == STD_ON)
extern CONST(Com_RxInvSigGroup, COM_CONST)
Com_GaaRxInvSigGroup[COM_RX_SIG_GRP_INV_COUNT];
#endif
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array size calculation error - Fixed by AUTRON START*/  
#if(COM_UNPACK_FUNC_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxUnpack structure */
extern CONST(Com_RxUnpack, COM_CONST) Com_GaaRxUnpack[COM_UNPACK_FUNC_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
/* Array size calculation error - Fixed by AUTRON END*/  

#if((COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON))
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Tx Update Bitstructure */
extern CONST(Com_TxUpdateBit, COM_CONST)
Com_GaaTxUpdateBit[COM_TX_UPDATEBIT_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_SIGGRP_MODE_SEL_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for RxUnpack structure */
extern CONST(Com_TxSigGrpModeSel, COM_CONST)
Com_GaaTxSigGrpModeSel[COM_TX_SIGGRP_MODE_SEL_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_GW_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for GWRxIpdu structure */
extern CONST(Com_RxGWIpdu, COM_CONST) Com_GaaRxGWIpdu[COM_RX_GW_COUNT];
/* Global array for GWRxSignal structure */
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_SIG_GATEWAY == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Com_TxGWSignal, COM_CONST) Com_GaaTxGWSignal[COM_TX_SIG_GW_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif


#if(COM_RX_SIGNAL_GW == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Com_RxGWSignal, COM_CONST) Com_GaaRxGWSignal[COM_RX_SIG_GW_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_SIGGROUP_GW == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for GWRxSigGroup structure */
extern CONST(Com_RxGWSigGroup, COM_CONST)
Com_GaaRxGWSigGroup[COM_RX_SIG_GRP_GW_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif


#if(COM_RX_SIG_INGRP_GW_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for GWRxSigInGrp structure */
extern CONST(Com_RxGWSigInGrp, COM_CONST)
Com_GaaRxGWSigInGrp[COM_RX_SIG_INGRP_GW_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* #7744 start */
#if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
   (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
#if(COM_SIG_REPLACE_COUNT > COM_MACRO_ZERO)   
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Signal Replace structure */
extern CONST(Com_SigReplace, COM_CONST)
Com_GaaSigReplace[COM_SIG_REPLACE_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif

#if((COM_RX_SIGGROUP_REPLACE == STD_ON) || \
   (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
#if(COM_SIGGRP_REPLACE_COUNT > COM_MACRO_ZERO)      
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Signal Replace structure */
extern CONST(Com_SigGrpReplace, COM_CONST)
Com_GaaSigGrpReplace[COM_SIGGRP_REPLACE_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif
/* #7744 end */

#if(COM_RX_IPDU_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  Memory allocated to different Pdu's */
extern CONST(Com_RxPduInfoType, COM_CONST)
Com_GaaRxPduInfoPtr[COM_RX_IPDU_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Tx IPDU structure allocating memory to IPDU's.
   Calculation of Ipdu length in case of dynamic Ipdu:
   The length of the Ipdu must be generated according to the initial
   values of the dynamic signal present. The length of the Ipdu will be the
   minimum length that can accomodate the uint8_DYN signal.
   For e.g.: Suppose an IPDU has allocated a maximum size of 4 bytes to the DYN
   signal. There are 3 other signals in the Ipdu occupying a total of 4 bytes.
   Hence, the maximum size of the Ipdu is 8 bytes. However suppose that the
   initial value of the uint8_DYN signal is 96, 52, 12. Then the size generated
   here should be 7 bytes */
extern VAR(PduInfoType, COM_VAR) Com_GaaTxPduInfoPtr[COM_TX_IPDU_COUNT];
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_GWSTATUS_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of 8 bits for Rx GW I-PDU status */
extern VAR(uint8, COM_VAR)
Com_GaaRxGWIpduStatus[COM_RX_IPDU_GWSTATUS_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_REPT_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of Tx Rept Timer */
extern VAR(uint8, COM_VAR)  Com_GaaTxReptCount[COM_TX_REPT_COUNT];

/* Global array for allocating RAM area of Tx Rept Sub Timer */
extern VAR(uint8, COM_VAR)  Com_GaaTxReptSubCount[COM_TX_REPT_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_FILTER_STATUS_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global array for Filter Status */
extern VAR(uint8, COM_VAR)  Com_GaaFilterStatus[COM_FILTER_STATUS_COUNT];
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_PERIOD_TIMER_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of 16 bits for timer */
extern VAR(uint16, COM_VAR)  Com_GaaTxPeriodicTimer[COM_TX_PERIOD_TIMER_COUNT];
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_DM_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of Rx Dm Timer */
extern VAR(uint16, COM_VAR)  Com_GaaRxDMTimer[COM_RX_IPDU_DM_COUNT];
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_DM_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of Tx Dm Timer */
extern VAR(uint16, COM_VAR)  Com_GaaTxDMTimer[COM_TX_IPDU_DM_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_REPT_TIMER_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of Tx Rept Timer */
extern VAR(uint16, COM_VAR)  
Com_GaaTxReptTimer[COM_TX_REPT_TIMER_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_MDT_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for allocating RAM area of Tx Minimum Delay Timer */
extern VAR(uint16, COM_VAR)  Com_GaaTxMDTimer[COM_TX_IPDU_MDT_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Tx Ipdu Counter */
extern CONST(Com_TxIpduCounter, COM_CONST)
Com_GaaTxIpduCounter[COM_TX_IPDU_COUNTER_SIZE];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Rx Ipdu Counter */
extern CONST(Com_RxIpduCounter, COM_CONST)
Com_GaaRxIpduCounter[COM_RX_IPDU_COUNTER_SIZE];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global Array for Tx I-PDU counter to maintain I-PDU count */
extern VAR(uint8, COM_VAR) Com_GaaTxIpduCountVal[COM_TX_IPDU_COUNTER_VAL_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global Array for Rx I-PDU counter to maintain I-PDU count */
extern VAR(uint8, COM_VAR)
Com_GaaRxIpduCountVal[COM_RX_IPDU_COUNTER_VAL_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for maintaining Ipdu Counter status. Indicates whether the Ipdu
counter is started/Enabled or not */
extern VAR(uint8, COM_VAR)
Com_GaaRamIpduCounterSts[COM_RAM_IPDU_COUNTER_STS_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_COUNTER_NOTIFY == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array counter error notification */
extern CONST(Com_RxCountNotify, COM_CONST)
Com_GaaRxCntNotify[COM_RX_COUNTER_NOTIF_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_REPLICATION == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Rx Replication */
extern CONST(Com_RxIpduReplication, COM_CONST)
Com_GaaRxIpduReplication[COM_RX_REPLI_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Tx TP Ipdu's. Instances of these will contain details
   about relevant TP (and dynamic) Ipdu's */
extern CONST(Com_TxTPIpdu, COM_CONST) Com_GaaTxTPIpdu[COM_TX_TP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for Rx TP Ipdu's. Instances of these will contain details
   about relevant TP (and dynamic) Ipdu's */
extern CONST(Com_RxTPIpdu, COM_CONST) Com_GaaRxTPIpdu[COM_RX_TP_COUNT];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_REPLICATION == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for maintaining Ipdu Replication status. Indicates whether the
Ipdu Replication is enabled is Enabled or not */
/* Change the declaration size as empty(#648) - 14.03.03 by Chan Kim START */
extern VAR(uint8, COM_VAR) Com_GaaRamIpduRepliSts[];
/* Change the declaration size as empty(#648) - 14.03.03 by Chan Kim END */
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_REPLICATION == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for maintaining Ipdu Replication count. Indicates the
number of Ipdus needed for Quorum voting to be complete */
/* Change the declaration size as empty(#648) - 14.03.03 by Chan Kim START */
extern VAR(uint8, COM_VAR) Com_GaaRxRepliCount[];
/* Change the declaration size as empty(#648) - 14.03.03 by Chan Kim END */
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_TX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds the status of TP buffers. Generation tool should allocate
   1 bit per TP Ipdu and provide a mask and reference to that variable in
   Com_RxIpdu structure */
extern VAR(uint8, COM_VAR) Com_GaaTxTPStatus[COM_TX_TP_STATUS_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds the status of TP buffers. Generation tool should allocate
   1 bit per TP Ipdu and provide a mask and reference to that variable in
   Com_RxIpdu structure */
extern VAR(uint8, COM_VAR) Com_GaaRxTPStatus[COM_RX_TP_STATUS_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif


/* uint16 -> PduLengthType for variable which has Pdu Length info 
& Memory arragement - Fixed by AUTRON START*/  
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds the run time changing length of Tx Dynamic signal.Generation
   tool should allocate element of this array per Tx DYN signal. The size of the
   array should be equal to the number of signals configured as uint8_DYN */
extern VAR(PduLengthType, COM_VAR) Com_GaaTxDynSigLength[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds the run time changing length of Rx Dynamic signal.
   Generation tool should allocate element of this array per Rx DYN signal. The
   size of the array should be equal to the number of signals configured as
   uint8_DYN */
extern VAR(PduLengthType, COM_VAR) Com_GaaRxDynSigLength[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if(COM_TX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds, in bytes the part of Tx TP Ipdu that has been copied to 
  PduR buffers so far in  previous calls to Com_CopyTxData. */
extern VAR(PduLengthType, COM_VAR) 
Com_GaaTxIpduTPLength[COM_TX_IPDU_TP_LEN_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* This array holds, in bytes the part of Rx TP Ipdu that has been copied from
   PduR buffers so far in  previous calls to Com_CopyRxData. */
extern VAR(PduLengthType, COM_VAR) 
Com_GaaRxIpduTPLength[COM_RX_IPDU_TP_LEN_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* This global array holds the memory size of signal based on its type */
extern CONST(uint8, COM_CONST)
Com_GaaSigMemSize[COM_FIVE];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* uint16 -> PduLengthType for variable which has Pdu Length info 
& Memory arragement - Fixed by AUTRON END*/  

/* #7429, #7744 */
#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* This global array holds the masking value in memory area occupied by Signal Group */
extern CONST(uint8, COM_CONST) Com_GaaSigGroupMaskInfo[];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* #7705 */
#if(COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON)
#define COM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* This global array holds the status of Signal Group which configured as OnChange attribute with sub transfer property of Group Signal */
extern VAR(uint8, COM_VAR) Com_GaaSigGroupChangedStatus[];
#define COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* COM_PCTYPES_H */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
