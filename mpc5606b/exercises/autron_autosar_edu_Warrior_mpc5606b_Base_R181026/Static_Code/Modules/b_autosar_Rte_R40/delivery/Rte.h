/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  MODULE    : RTE                                                           **
**                                                                            **
**  TARGET    : N/R                                                           **
**                                                                            **
**  PURPOSE   : Static Header Files for Rte module                            **
**                                                                            **
**  PLATFORM DEPENDANT [YES/NO] : NO                                          **
**                                                                            **
**  TO BE CHANGED BY USER [YES/NO]: NO                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                   Description                   **
********************************************************************************
** 4.4.2     11-09-2017    KiYoung Yun  RTE Module Release Version 4.4.2      **
** 4.4.1     08-24-2017    KiYoung Yun  RTE Module Release Version 4.4.1      **
** 4.4.0     06-09-2017    Seongmin Kim RTE Module Release Version 4.4.0      **
** 4.3.3     02-10-2017    Daejun Park  RTE Module Release Version 4.3.3      **
** 4.3.2     11-30-2016    Daejun Park  RTE Module Release Version 4.3.2      **
** 4.3.1     10-20-2016    Daejun Park  RTE Module Release Version 4.3.1      **
** 4.3.0     08-19-2016    Seongmin Kim RTE Module Release Version 4.3.0      **
**                                      - Change made as per #3199            **
** 4.2.1     06-03-2016    Daejun Park  RTE Module Release Version 4.2.1      **
** 4.2.0     05-20-2016    Daejun Park  RTE Module Release Version 4.2.0      **
** 4.1.2     05-10-2016    JeongSu Lim  RTE Module Release Version 4.1.2      **
** 4.1.1     04-28-2016    JeongSu Lim  RTE Module Release Version 4.1.1      **
** 4.1.0     03-18-2016    JeongSu Lim  RTE Module Release Version 4.1.0      **
** 4.0.1     03-04-2016    JeongSu Lim  RTE Module Release Version 4.0.1      **
** 4.0.0     02-29-2016    JeongSu Lim  RTE Module Release Version 4.0.0      **
** 1.5.7     01-21-2016    JeongSu Lim  RTE Module Release Version 1.5.7      **
** 1.5.6     12-16-2015    JeongSu Lim  RTE Module Release Version 1.5.6      **
** 1.5.5     11-19-2015    JeongSu Lim  RTE Module Release Version 1.5.5      **
** 1.5.4     10-20-2015    JeongSu Lim  RTE Module Release Version 1.5.4      **
** 1.5.3     08-24-2015    JeongSu Lim  RTE Module Release Version 1.5.3      **
** 1.5.2     07-29-2015    JeongSu Lim  RTE Module Release Version 1.5.2      **
**                         Hoimin Kim   - Changes made as per Imp #2822       **
** 1.5.1     06-16-2015    Seongmin Kim RTE Module Release Version 1.5.1      **
**                                      - add RTE_UNUSED and RTE_UNUSED_PTR   **
** 1.5.0     05-07-2015    Seongmin Kim RTE Module Release Version 1.5.0      **
**                         DHLim                                              **
** 1.3.0     11-21-2014    DHLim        RTE Module Release Version 1.3.0      **
** 1.0.0     06-10-2014    DHLim        Initial version                       **
*******************************************************************************/

#ifndef RTE_H
#define RTE_H

/*******************************************************************************
** Include Section                                                            **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "string.h"
#include "Std_Types.h"
#include "Rte_Cfg.h"
#include "Rte_PBCfg.h"
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */

/*******************************************************************************
** Version Information                                                        **
*******************************************************************************/
#ifdef RTE_VENDOR_ID
  #if (RTE_VENDOR_ID != 76)
    #error "Rte.h : Mismatch in Rte Specification Vendor Id"
  #endif
#else
  #define RTE_VENDOR_ID 76
#endif

#ifdef RTE_MODULE_ID
  #if (RTE_MODULE_ID != 2)
    #error "Rte.h : Mismatch in Rte Specification Module Id"
#endif
#else
  #define RTE_MODULE_ID 2
#endif

#ifdef RTE_SW_MAJOR_VERSION
  #if (RTE_SW_MAJOR_VERSION != 4)
    #error "Rte.h : Mismatch in Rte Specification Major Version"
  #endif
#else
  #define RTE_SW_MAJOR_VERSION 4
#endif

#ifdef RTE_SW_MINOR_VERSION
  #if (RTE_SW_MINOR_VERSION != 4)
    #error "Rte.h : Mismatch in Rte Specification Minor Version"
  #endif
#else
  #define RTE_SW_MINOR_VERSION 4
#endif

#ifdef RTE_SW_PATCH_VERSION
  #if (RTE_SW_PATCH_VERSION != 2)
    #error "Rte.h : Mismatch in Rte Specification Patch Version"
  #endif
#else
  #define RTE_SW_PATCH_VERSION 2
#endif

#ifdef RTE_AR_RELEASE_MAJOR_VERSION
  #if (RTE_AR_RELEASE_MAJOR_VERSION != 4)
    #error "Rte.h : Mismatch in Rte Specification Release Major Version"
  #endif
#else
  #define RTE_AR_RELEASE_MAJOR_VERSION 4
#endif

#ifdef RTE_AR_RELEASE_MINOR_VERSION
  #if (RTE_AR_RELEASE_MINOR_VERSION != 0)
    #error "Rte.h : Mismatch in Rte Specification Release Minor Version"
  #endif
#else
  #define RTE_AR_RELEASE_MINOR_VERSION 0
#endif

#ifdef RTE_AR_RELEASE_REVISION_VERSION
  #if (RTE_AR_RELEASE_REVISION_VERSION != 3)
    #error "Rte.h : Mismatch in Rte Specification Release Revision Version"
  #endif
#else
  #define RTE_AR_RELEASE_REVISION_VERSION 3
#endif

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
extern "C" 
{
#endif

/*******************************************************************************
** Standard ReturnType Macros
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> AUTOSAR Standard rte_sws_7404 */
#define Rte_IsInfrastructureError(status) (((status) & 128U) != 0)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> AUTOSAR Standard rte_sws_7405 */
#define Rte_HasOverlayedError(status) (((status) & 64U) != 0)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> AUTOSAR Standard rte_sws_7406 */
#define Rte_ApplicationError(status) ((status) & 63U) 

/*******************************************************************************
** Type Definitions for AUTOSAR Error Types                                   **
*******************************************************************************/
#define RTE_TRUE                                      0x01U
#define RTE_ONE                                       0x01U
#define RTE_FALSE                                     0x00U
#define RTE_ZERO                                      0x00U

#define IN 
#define INOUT 
#define OUT

#define RTE_E_OK                                      0x00U
#define RTE_E_INVALID                                 0x01U
#define RTE_E_COMMS_ERROR                             0x80U
#define RTE_E_MAX_AGE_EXCEEDED                        0x40U
#define RTE_E_LOST_DATA                               0x40U
#define RTE_E_TRANSMIT_ACK                            0x84U
#define RTE_E_NO_DATA                                 0x83U
#define RTE_E_LIMIT                                   0x82U
#define RTE_E_TIMEOUT                                 0x81U
#define RTE_E_NORESULT                                0x00U
#define RTE_E_NOFEEDBACK                              0xFFU
#define RTE_E_COM_STOPPED                             0x80U
#define RTE_E_UNCONNECTED                             0x86U
#define RTE_E_NEVER_RECEIVED                          0x85U
#define RTE_E_IN_EXCLUSIVE_AREA                       0x87U
#define RTE_E_OUT_OF_RANGE                            0x89U
#define RTE_E_SEG_FAULT                               0x88U


#define SCHM_E_OK                                     0x00U
#define SCHM_E_LIMIT                                  0x82U
#define SCHM_E_NO_DATA                                0x83U
#define SCHM_E_TRANSMIT_ACK                           0x84U
#define SCHM_E_IN_EXCLUSIVE_AREA                      0x87U
#define SCHM_E_TIMEOUT                                0x81U

#define RTE_E_DET_ILLEGAL_SIGNAL_ID                   0x01U
#define RTE_E_DET_ILLEGAL_VARIANT_CRITERION_VALUE     0x02U
#define RTE_E_DET_ILLEGAL_INVOCATION                  0x03U
#define RTE_E_DET_WAIT_IN_EXCLUSIVE_AREA              0x04U
#define RTE_E_DET_ILLEGAL_NESTED_EXCLUSIVE_AREA       0x05U
#define RTE_E_DET_SEG_FAULT                           0x06U
#define RTE_E_DET_UNINIT                              0x07U
#define RTE_E_DET_ILLEGAL_APPLICATION_ERROR_VALUE     0x08U
#define RTE_SERVICEID_SCHM_INIT                       0x00U

#define RTE_INSTANCE_ID                               0x00U
#define SCHM_MODULE_ID                                0x82U
#define SCHM_INSTANCE_ID                              0x00U

#define RTE_PORTS_SID                                 0x10U
#define RTE_NPORTS_SID                                0x11U
#define RTE_PORT_SID                                  0x12U
#define RTE_SEND_SID                                  0x13U
#define RTE_WRITE_SID                                 0x14U
#define RTE_SWITCH_SID                                0x15U
#define RTE_INVALIDATE_SID                            0x16U
#define RTE_FEEDBACK_SID                              0x17U
#define RTE_SWITCHACK_SID                             0x18U
#define RTE_READ_SID                                  0x19U
#define RTE_DREAD_SID                                 0x1AU
#define RTE_RECEIVE_SID                               0x1BU
#define RTE_CALL_SID                                  0x1CU
#define RTE_RESULT_SID                                0x1DU
#define RTE_PIM_SID                                   0x1EU
#define RTE_CDATA_SID                                 0x1FU
#define RTE_PRM_SID                                   0x20U
#define RTE_IREAD_SID                                 0x21U
#define RTE_IWRITE_SID                                0x22U
#define RTE_IWRITEREF_SID                             0x23U
#define RTE_IINVALIDATE_SID                           0x24U
#define RTE_ISTATUS_SID                               0x25U
#define RTE_IRVIREAD_SID                              0x26U
#define RTE_IRVIWRITE_SID                             0x27U
#define RTE_IRVREAD_SID                               0x28U
#define RTE_IRVWRITE_SID                              0x29U
#define RTE_ENTER_SID                                 0x2AU
#define RTE_EXIT_SID                                  0x2BU
#define RTE_MODE_SID                                  0x2CU
#define RTE_TRIGGER_SID                               0x2DU
#define RTE_IRTRIGGER_SID                             0x2EU
#define RTE_IFEEDBACK_SID                             0x2FU
#define RTE_ISUPDATED_SID                             0x30U
#define RTE_START_SID                                 0x70U
#define RTE_STOP_SID                                  0x71U
#define RTE_PARTITIONTERMINATED_SID                   0x72U
#define RTE_PARTITIONRESTARTING_SID                   0x73U
#define RTE_RESTARTPARTITION_SID                      0x74U
#define RTE_COMCBK_SID                                0x95U

#define SCHM_INIT_SID                                 0x00U
#define SCHM_DEINIT_SID                               0x01U
#define SCHM_GETVERSIONINFO_SID                       0x02U
#define SCHM_ENTER_SID                                0x03U
#define SCHM_EXIT_SID                                 0x04U
#define SCHM_ACTMAINFUNCTION_SID                      0x05U
#define SCHM_SWITCH_SID                               0x06U
#define SCHM_MODE_SID                                 0x07U
#define SCHM_SWITCHACK_SID                            0x08U
#define SCHM_TRIGGER_SID                              0x09U

#define E2EPW_ZERO                                    0x00U
#define E2EPW_SHIFT_BY_ONE_BYTE                       0x08U
#define E2EPW_SHIFT_BY_TWO_BYTES                      0x10U
#define E2EPW_SHIFT_BY_THREE_BYTES                    0x18U

#define E2EPW_STATUS_OK                               0x00U
#define E2EPW_STATUS_NONEWDATA                        0x01U
#define E2EPW_STATUS_WRONGCRC                         0x02U
#define E2EPW_STATUS_INITAL                           0x04U
#define E2EPW_STATUS_REPEATED                         0x08U
#define E2EPW_STATUS_OK_LEGACY                        0x10U
#define E2EPW_STATUS_OKSOMELOST                       0x20U
#define E2EPW_STATUS_WRONGSEQUENCE                    0x40U

#define E2EPW_E_DESERIALIZATION                       0x03U
#define E2EPW_E_REDUNDANCY                            0x05U

#ifdef _STRING_H
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in Rte has already been verified and no impact of this rule violation  */
#define Rte_Memcpy(Dst, Src, Size)  (memcpy((Dst),(Src),(Size)))
#else
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in Rte has already been verified and no impact of this rule violation  */
#define Rte_Memcpy(Dst, Src, Size)  (memcpy((Dst),(Src),(Size)))
#endif

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in Rte has already been verified and no impact of this rule violation  */
#define RTE_UNUSED(x)                                 do { \
                                                        if((uint32)(x) != (uint32)RTE_ZERO) {} \
                                                      } while(0)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in Rte has already been verified and no impact of this rule violation  */
#define RTE_UNUSED_PTR(x)                             do { \
                                                        if((x) != NULL_PTR) {} \
                                                      } while(0)

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
} /* extern "C" */
#endif 

#endif 
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

