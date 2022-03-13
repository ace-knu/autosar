/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Config.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of variables of which value is set at link time     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
*******************************************************************************/
/*******************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.5.2    17-Apr-2017    Js.Lim    #8220                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 2.2.8    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.2.7    11-Mar-2016    Kt.Kim    #4386                                    **
** 2.2.6    25-Aug-2015    Kt.Kim    #2999                                    **
** 2.2.4    13-Apr-2013    Kt.Kim    #2254                                    **
** 2.1.0    29-May-2013    Kt.Kim    Library Support                           **
** 1.0.0    03-Jun-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_PCTypes.h"
#include "CanIf_Ram.h"

#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"          /* PduR Header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"           /* Callback CanTp Header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"           /* Callback CanNm  Header file */
#endif
#if (STD_ON == CANIF_OSEKNM_CALLBACK)
#include "OsekNm_Cbk.h"           /* Callback OsekNm  Header file */
#endif
#if (STD_ON == CANIF_RX_J1939TP_CALLBACK)
#include "J1939Tp_Cbk.h"         /* Callback J1939Tp Header file */
#endif
/* #5139 */
#if (STD_ON == CANIF_RX_J1939NM_CALLBACK)
#include "J1939Nm_Cbk.h"         /* Callback J1939Tp Header file */
#endif
#if (STD_ON == CANIF_RX_XCP_CALLBACK)
#include "Xcp_Cbk.h"             /* Callback XCP Header file */
#endif



#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace:begin<MISRA-C:11.1:Not a defect:Justify with annotations>
    No Impact of this rule violation  */ 
/* 8241 */
#if((STD_ON == CANIF_CANFD_SUPPORT) && (STD_ON == CANIF_CANFD_DISCRETE_DLC_SUPPORT))
CONST(uint8, CANIF_CONST) CanIf_GaaDiscreteDlctoDataLength[CANIF_SEVEN]=
                                                  {12U,16U,20U,24U,32U,48U,64U};
#endif
CONST(CanIf_RxCbkUser, CANIF_CONST) CanIf_GaaRxSingleCbkUser[] =
{
  {
#if (STD_ON == CANIF_RX_PDUR_CALLBACK) 
  #ifdef CANIF_PDUR_RXIND_MACRO
    &CANIF_PDUR_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  {
#if (STD_ON == CANIF_RX_CANTP_CALLBACK) 
  #ifdef CANIF_CANTP_RXIND_MACRO
    &CANIF_CANTP_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  {
#if (STD_ON == CANIF_RX_CANNM_CALLBACK) 
  #ifdef CANIF_CANNM_RXIND_MACRO
    &CANIF_CANNM_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  {
#if (STD_ON == CANIF_RX_CDD_CALLBACK) 
  #ifdef CANIF_CDD_RXIND_MACRO
    &CANIF_CDD_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR 
#endif
  },
  {
#if (STD_ON == CANIF_RX_J1939TP_CALLBACK) 
  #ifdef CANIF_J1939TP_RXIND_MACRO
    &CANIF_J1939TP_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  {
#if (STD_ON == CANIF_RX_XCP_CALLBACK) 
  #ifdef CANIF_XCP_RXIND_MACRO
    &CANIF_XCP_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  {
#if (STD_ON == CANIF_RX_OSEKNM_CALLBACK) 
  #ifdef CANIF_OSEKNM_RXIND_MACRO
    &CANIF_OSEKNM_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  },
  /* #5139 */
  {
#if (STD_ON == CANIF_RX_J1939NM_CALLBACK)
  #ifdef CANIF_J1939NM_RXIND_MACRO
    &CANIF_J1939NM_RXIND_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR  
#endif
  }  
};

CONST(CanIf_TxCbkUser, CANIF_CONST) CanIf_GaaTxSingleCbkUser[] =
{
  {
#if (STD_ON == CANIF_TX_PDUR_CALLBACK) 
  #ifdef CANIF_PDUR_TXCNFRM_MACRO
    &CANIF_PDUR_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR 
#endif
  },
  {
#if (STD_ON == CANIF_TX_CANTP_CALLBACK) 
  #ifdef CANIF_CANTP_TXCNFRM_MACRO
    &CANIF_CANTP_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_CANNM_CALLBACK) 
  #ifdef CANIF_CANNM_TXCNFRM_MACRO
    &CANIF_CANNM_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_CDD_CALLBACK) 
  #ifdef CANIF_CDD_TXCNFRM_MACRO
    &CANIF_CDD_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_J1939TP_CALLBACK) 
  #ifdef CANIF_J1939TP_TXCNFRM_MACRO
    &CANIF_J1939TP_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_XCP_CALLBACK) 
  #ifdef CANIF_XCP_TXCNFRM_MACRO
    &CANIF_XCP_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_OSEKNM_CALLBACK) 
  #ifdef CANIF_OSEKNM_TXCNFRM_MACRO
    &CANIF_OSEKNM_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  },
  {
#if (STD_ON == CANIF_TX_J1939NM_CALLBACK)
  #ifdef CANIF_J1939NM_TXCNFRM_MACRO
    &CANIF_J1939NM_TXCNFRM_MACRO
  #else
    NULL_PTR
  #endif
#else
    NULL_PTR
#endif
  }
};
/* polyspace:end<MISRA-C:11.1:Not a defect:Justify with annotations>
   No Impact of this rule violation                                           */
CONST(CanIf_Precompile_Options, CANIF_CONST) CanIf_GddPrecompOpt = 
{
  CANIF_RX_MULTIPLE_CALLBACK,
  CANIF_TX_MULTIPLE_CALLBACK,
  CANIF_BASIC_CAN_TXPDU,
  CANIF_RX_BASIC_CAN_SUPPORT,
  CANIF_TX_BUFFERING,
  CANIF_NO_OF_TXQUEUE,
  CANIF_NO_OF_TXBUFFER,
  CANIF_NO_OF_RXLPDU,
  CANIF_NO_OF_TXLPDU,
  CANIF_NO_OF_BASIC_TXLPDU
};
#if (STD_ON == CANIF_RX_MULTIPLE_CALLBACK)
CONSTP2CONST(CanIf_RxCbkUser, AUTOMATIC, CANIF_CONST) CanIf_GpRxMulCbkUser = &CanIf_GaaRxCbkUser[0];
#else
CONSTP2CONST(CanIf_RxCbkUser, AUTOMATIC, CANIF_CONST) CanIf_GpRxMulCbkUser = NULL_PTR;
#endif

#if (STD_ON == CANIF_TX_MULTIPLE_CALLBACK)
CONSTP2CONST(CanIf_TxCbkUser, AUTOMATIC, CANIF_CONST) CanIf_GpTxMulCbkUser = &CanIf_GaaTxCbkUser[0];
#else
CONSTP2CONST(CanIf_TxCbkUser, AUTOMATIC, CANIF_CONST) CanIf_GpTxMulCbkUser = NULL_PTR;
#endif

#if ((STD_ON == CANIF_BASIC_CAN_TXPDU) || (STD_ON == CANIF_TX_QUEUE))
CONST(CanIf_TxBufferPtrsType, CANIF_CONST) CanIf_GddTxBuffCon = 
{
  &CanIf_GaaTxBuffer[0],
  &CanIf_GaaTxQueue[0],
  &CanIf_GaaTxPduToQueueMapping[0],
  &CanIf_GaaTxBasicPduIndexMapping[0]
};
#else
CONST(CanIf_TxBufferPtrsType, CANIF_CONST) CanIf_GddTxBuffCon = 
{
  NULL_PTR,
  NULL_PTR,
  NULL_PTR,
  NULL_PTR,  
};
#endif
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#define CANIF_START_SEC_CONST_8
#include "MemMap.h"
CONST(uint8, CANIF_CONST) CanIf_No_Of_Transceiver = CANIF_NO_OF_TRANSCEIVER;
#define CANIF_STOP_SEC_CONST_8
#include "MemMap.h"


