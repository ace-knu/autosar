/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : This file contains the type definitions and macro             **
**              definitions of DEM module                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
** 1.5.2    31-08-2017     EunKyung.Kim   Changes made As per Redmine #9647   **
**                                        #8142                               **
**                                                                            **
** 1.5.1    20-07-2017     EunKyung.Kim   Changes made As per Redmine #9294   **
**                                                                            **
** 1.5.0    31-05-2017     EunKyung.Kim   Changes made As per Redmine #8166   **
**                                                                            **
** 1.4.2    09-03-2017      YoungJin.Yun  Changes made As per Redmine #6202   **
**                                                                            **
** 1.4.1    06-02-2016      YoungJin.Yun  Changes made As per Redmine #7379   **
**                                                                            **
** 1.4.0    16-11-2016      YoungJin.Yun  Changes made As per Redmine #6549   **
**                                        #6188                               **
**                                                                            **
** 1.3.0    30-09-2016      YoungJin.Yun  Changes made As per Redmine #6097   **
**                                                                            **
** 1.2.0    30-08-2016      YoungJin.Yun  Changes made As per Redmine #5011   **
**                                                                            **
** 1.1.0    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.5    16-04-2015      Sungeol Baek  Changes made As per Reminde #2171   **
**                                                                            **
** 1.0.4    11-01-2014      YoungJin Yun  Changes made As per Redmine #366,   **
**                                        #368,#371,#372,#405,#366,#367,#368, ** 
**                                        #371,#372,#405,#369,#373,#374,#375, **
**                                        #376,#370,#377,#381,#382,#383,#384, **
**                                        #385,#386,#387,#388,#389,#390,#391, **
**                                        #397,#398,#399,#400,#378,#380,#401, **
**                                        #403,#404,#406,#409,#410,#411,#412  **
**                                        #367                                **
**                                                                            **
** 1.0.0    01-01-2013      Autron      Initial Version                       **
*******************************************************************************/


#ifndef DEM_TYPES_H
#define DEM_TYPES_H

/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Dem_Type.h"   /* Rte Header File for Dem Types */
#include "Std_Types.h"
#include "Dem_Cfg.h"
#include "Dcm.h"  /* DCM_RPT_FAILEDCONFIRMEDDTCINFO == STD_ON */

/*******************************************************************************
**                         Global Data Types                                  **
*******************************************************************************/
#ifndef DEM_INLINE
#ifndef INLINE
#define DEM_INLINE inline
#else 
#define DEM_INLINE inline
#endif
#endif

#ifdef DEM_DTC_KIND_ALL_DTCS
#define DEM_SWCGEN  
#endif

/* bit position for uint8 : Macros for filtering the events by the specificc condition */
#define DEM_EVPROCSTATE_INITMON_ONCLEARDTC                        (0U) /* (0x02U) */
#define DEM_EVPROCSTATE_DTC_SUPP                                  (1U) /* (0x04U) */
#define DEM_EVPROCSTATE_DTC_FILTER                                (2U) /* (0x08U) */
#define DEM_EVPROCSTATE_EVENT_STORED                              (3U) /* (0x10U) */
#define DEM_EVPROCSTATE_EVENT_LOCK                                (4U) /* (0x20U) */
#define DEM_EVPROCSTATE_EVENT_DEL                                 (5U) /* (0x40U) */
  /* DEM_J1939_SUPPORT */
#define DEM_EVPROCSTATE_J1939DTC_FILTER                           (6U) /* (0x80U) */
#define DEM_EVPROCSTATE_RESRVED                                   (7U) /* (0x01U) */

/* uint8 : Macros for filtering the event memory by the specificc condition */
#define DEM_EVMEM_STATUS_INIT                                     ((uint8) 0x00) /* status during dem init        */
#define DEM_EVMEM_STATUS_INVALID                                  ((uint8) 0x01) /* status during dem init        */
#define DEM_EVMEM_STATUS_DIRTY                                    ((uint8) 0x02) /* event memory entry is changed */
#define DEM_EVMEM_STATUS_QUEUED_NVM                               ((uint8) 0x04) /* state after NvM_ReadBlock or NvM_WriteBlock returns OK */  
#define DEM_EVMEM_STATUS_TRIGGER_NVM                              ((uint8) 0x08) /* immediate storage : puts job in the NvM's queue */
#define DEM_EVMEM_STATUS_FINISH_NVM                               ((uint8) 0x10) /* wait during NvM finishes jobs that write the data to the eeprom or the flash physically */
#define DEM_EVMEM_STATUS_DIRTY_NVM                                ((DEM_EVMEM_STATUS_DIRTY) | (DEM_EVMEM_STATUS_TRIGGER_NVM))
#define DEM_EVMEM_STATUS_DIRTY_NVM_QUEUED                         ((DEM_EVMEM_STATUS_DIRTY) | (DEM_EVMEM_STATUS_TRIGGER_NVM) | (DEM_EVMEM_STATUS_QUEUED_NVM))



#define DEM_BITMASK_RESET_PDTC                                    (DEM_UDS_STATUS_PDTC|DEM_UDS_STATUS_TNCTOC|DEM_UDS_STATUS_TFTOC)
#define DEM_BITMASK_RESET_TRIP                                    (DEM_UDS_STATUS_CDTC|DEM_UDS_STATUS_TNCTOC|DEM_UDS_STATUS_TFTOC)

#define DEM_STATUS_BIT_NORMAL                                     (1U)
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT                     (0U)
#define DEM_FDC_MASK                                              ((uint16)0x0C00)

#define DEM_DEBOUNCE_COUNTER_BASED                                (0x01U)
#define DEM_DEBOUNCE_TIME_BASED                                   (0x02U)
#define DEM_DEBOUNCE_MONITOR_BASED                                (0x03U)
#define DEM_DEBOUNCE_NO_DEBOUNCE_BASED                            (0x00U)

#define DEM_UNSET                                                 (0x03U) /* true(1) or false(0) or unset(3) */
#define DEM_TRUE                                                  (0x01U)
#define DEM_FALSE                                                 (0x00U)

#define DEM_MINUS_ONE                                             ((sint8)(-1))
#define DEM_ZERO                                                  (0x00U)
#define DEM_ONE                                                   (0x01U)
#define DEM_TWO                                                   (0x02U)
#define DEM_THREE                                                 (0x03U)
#define DEM_FOUR                                                  (0x04U)
#define DEM_FIVE                                                  (0x05U)
#define DEM_SIX                                                   (0x06U)
#define DEM_SEVEN                                                 (0x07U)
#define DEM_EIGHT                                                 (0x08U)
#define DEM_NINE                                                  (0x09U)
#define DEM_TEN                                                   (0x0AU)
#define DEM_ELEVEN                                                (0x0BU)
#define DEM_TWELVE                                                (0x0CU)
#define DEM_THIRTEEN                                              (0x0DU)
#define DEM_FOURTEEN                                              (0x0EU)
#define DEM_FIFTEEN                                               (0x0FU)
#define DEM_SIXTEEN                                               (0x10U)
#define DEM_TWENTY                                                (0x14U)
#define DEM_ONE_FOUR_FOUR                                         (0x90U)
#define DEM_EVCOMB_DISABLED                                       (0x00U)
#define DEM_EVCOMB_TYPE1                                          (0x01U)
#define DEM_EVCOMB_TYPE2                                          (0x02U)
#define DEM_FF_RECNUM_CONFIGURED                                  (0x01U)
#define DEM_FF_RECNUM_CALCULATED                                  (0x00U)
#define DEM_CLRRESP_NONVOLATILE_FINISH                            (0x00U)
#define DEM_CLRRESP_NONVOLATILE_TRIGGER                           (0x01U)
#define DEM_CLRRESP_VOLATILE                                      (0x02U)

/* start */
/* these are unused macros. we only use  TRIGGER_TESTFAILED  */
#define DEM_TRIGGER_EVENT_MEMORY_STORAGE                          0x00
#define DEM_TRIGGER_TESTFAILED                                    0x01
/* end */

#define DEM_NO_EVENT                                              ((Dem_EventIdType)0x00U)
#define DEM_COUNTER_MAX                                           (0x7FU)
#define DEM_COUNTER_MIN                                           ((sint8)(-128))
#define DEM_OCC_MAX                                               (0xFFU)
#define DEM_IND_MAX                                               (0xFFU)
#define DEM_EXTERN_COUNTER_MAX                                    (0xFFU)
#define DEM_PROCESS_AGINGCTR_INTERN                               (0x01U)
#define DEM_PROCESS_AGINGCTR_EXTERN                               (0x02U)
#define DEM_UPDATE_RECORD_NO                                      (0x01U)
#define DEM_UPDATE_RECORD_YES                                     (0x02U)
#define DEM_SET_BYTE                                              (0x00U)
#define DEM_MASK3                                                 ((uint16)0xF000U)
#define DEM_THREE_ZERO_ZERO                                       ((uint16)0x0300U)
#define DEM_MASK1                                                 ((uint16)0x00F0U)
#define DEM_MAX_VALID_EXTENDED_RECORD_NUMBER                      ((uint8)0xEFU)
#define DEM_MAX_EXTENDED_RECORD_NUMBER                            (0xFFU)
#define DEM_EXTENDED_DATA_NUMBER_OBD                              (0xFEU)
#define DEM_MAX_RECORD                                            ((uint8)0xFFU)

#define DEM_BIT0_MASK1                                            ((uint8)0x01)
#define DEM_BIT1_MASK1                                            ((uint8)0x02)
#define DEM_BIT2_MASK1                                            ((uint8)0x04)
#define DEM_BIT3_MASK1                                            ((uint8)0x08)
#define DEM_BIT4_MASK1                                            ((uint8)0x10)
#define DEM_BIT5_MASK1                                            ((uint8)0x20)
#define DEM_BIT6_MASK1                                            ((uint8)0x40)
#define DEM_BIT7_MASK1                                            ((uint8)0x80)
#define DEM_BIT8_MASK1                                            ((uint16)0x100)
#define DEM_BIT9_MASK1                                            ((uint16)0x200)
#define DEM_BIT10_MASK1                                           ((uint16)0x400)
#define DEM_BIT11_MASK1                                           ((uint16)0x800)
#define DEM_BIT12_MASK1                                           ((uint16)0x1000)
#define DEM_BIT13_MASK1                                           ((uint16)0x2000)
#define DEM_BIT14_MASK1                                           ((uint16)0x4000)
#define DEM_BIT15_MASK1                                           ((uint16)0x8000)
#define DEM_BIT1_MASK1_BITWISE                                    (0x02U)
#define DEM_BIT0_MASK1_BITWISE                                    (0x01U)
#define DEM_BIT4_MASK1_BITWISE                                    (0x10U)
#define DEM_BIT0_MASK2                                            ((uint8)0xFE)
#define DEM_BIT1_MASK2                                            ((uint8)0xFD)
#define DEM_BIT2_MASK2                                            ((uint8)0xFB)
#define DEM_BIT3_MASK2                                            ((uint8)0xF7)
#define DEM_BIT4_MASK2                                            ((uint8)0xEF)
#define DEM_BIT5_MASK2                                            ((uint8)0xDF)
#define DEM_BIT6_MASK2                                            ((uint8)0xBF)
#define DEM_BIT7_MASK2                                            ((uint8)0x7F)

/* Pid Values */
#define DEM_PID_01                                                ((uint8)0x01)
#define DEM_PID_02                                                ((uint8)0x02)
#define DEM_PID_1C                                                ((uint8)0x1C)
#define DEM_PID_21                                                ((uint8)0x21)
#define DEM_PID_30                                                ((uint8)0x30)
#define DEM_PID_31                                                ((uint8)0x31)
#define DEM_PID_41                                                ((uint8)0x41)
#define DEM_PID_4D                                                ((uint8)0x4D)
#define DEM_PID_4E                                                ((uint8)0x4E)
#define DEM_PID_5F                                                ((uint8)0x5F)
#define DEM_PID_0D                                                ((uint8)0x0D)

#define DEM_INVALID                                               (0x00U)
#define DEM_INVALID_BLOCK                                         (0xFFFFU)
#define DEM_DTC_SEV_CHECK_AT_NEXT_HALT                            (0x40U)
#define DEM_DTC_SEV_IMMEDIATELY                                   (0x80U)
#define DEM_DTC_SEV_MAINTENANCE_ONLY                              (0x20U)
#define DEM_DTC_SEV_NO_SEVERITY                                   (0x00U)
#define DEM_DTC_SEV_MASK                                          ((uint8)DEM_DTC_SEV_CHECK_AT_NEXT_HALT |\
                                                                  (uint8)DEM_DTC_SEV_IMMEDIATELY |\
                                                                  (uint8)DEM_DTC_SEV_MAINTENANCE_ONLY |\
                                                                  (uint8)DEM_DTC_SEV_NO_SEVERITY)

#define DEM_EVENT_SIGNIFICANCE_FAULT                              (0x01U)
#define DEM_EVENT_SIGNIFICANCE_OCCURRENCE                         (0x00U)

#define DEM_TIMER_TYPE_FAILED                                     (0x00U)
#define DEM_TIMER_TYPE_PASSED                                     (0x01U)

#define DEM_NVM_READ_TIMEOUT                                      ((uint32)0x000FFFFF)
#define DEM_CONVERT_MIN_HR                                        (0.01667U) /* @IF_REQ : float ? */
#define DEM_MAXTIME_COUNT_IN_MIN_PID4E                            (0xFFFFU)

#define DEM_SIXTY_SEC                                             (0x3CU)
#define DEM_THOUSAND_SEC                                          (0x3E8U)
#define DEM_IndexOfFFRecords_MAX                                  (0xFFU)
#define DEM_FOURTY                                                (0x28U)
#define DEM_COUNTER_VALUE_MAX                                     (0xFFU)
#define DEM_MAX_VALID_RECORD_NUMBER                               (0xEFU)
#define DEM_MASK_UPPER_BYTE                                       ((uint16)0xFF00)
#define DEM_MASK_LOWER_BYTE                                       ((uint16)0x00FF)

#define DEM_MASK_LOWER_NIBBLE                                     (0x0FU)
#define DEM_MAXIMUM_DISTANCE_DTC_CLEAR_OBD                        (0xFFFFU)
#define DEM_MAXIMUM_DISTANCE_DTC_WITHMILON_OBD                    (0xFFFFU)

#define DEM_MASK                                                  ((uint8)0xEE)
#define DEM_MASK_BIT1_BIT5                                        ((uint8)0xDD)
#define DEM_MASK2                                                 ((uint8)0xBB)
#define DEM_MAX_WARM_UP_COUNT                                     ((uint8)0xFF)
#define DEM_MAX_0BD_VAL_ALLOWED                                   ((uint8)0xFF)

/* Bit Positions*/
#define BIT_POS_0                                                 (0U)
#define BIT_POS_1                                                 (1U)
#define BIT_POS_2                                                 (2U)
#define BIT_POS_3                                                 (3U)
#define BIT_POS_4                                                 (4U)
#define BIT_POS_5                                                 (5U)
#define BIT_POS_6                                                 (6U)
#define BIT_POS_7                                                 (7U)


#define DEM_BIT0_MASK                                             (0x01U)
#define DEM_BIT1_MASK                                             (0x02U)
#define DEM_BIT2_MASK                                             (0x04U)
#define DEM_BIT3_MASK                                             (0x08U)
#define DEM_BIT4_MASK                                             (0x10U)
#define DEM_BIT5_MASK                                             (0x20U)
#define DEM_BIT6_MASK                                             (0x40U)
#define DEM_BIT7_MASK                                             (0x80U)

/* Iumpr groups */
#define DEM_IUMPR_BOOSTPRS                                        (0x00U)
#define DEM_IUMPR_CAT1                                            (0x01U)
#define DEM_IUMPR_CAT2                                            (0x02U)
#define DEM_IUMPR_EGR                                             (0x03U)
#define DEM_IUMPR_EGSENSOR                                        (0x04U)
#define DEM_IUMPR_EVAP                                            (0x05U)
#define DEM_IUMPR_NMHCCAT                                         (0x06U)
#define DEM_IUMPR_NOXADSORB                                       (0x07U)
#define DEM_IUMPR_NOXCAT                                          (0x08U)
#define DEM_IUMPR_OXS1                                            (0x09U)
#define DEM_IUMPR_OXS2                                            (0x0AU)
#define DEM_IUMPR_PMFILTER                                        (0x0BU)
#define DEM_IUMPR_PRIVATE                                         (0x0CU)
#define DEM_IUMPR_SAIR                                            (0x0DU)
#define DEM_IUMPR_SECOXS1                                         (0x0EU)
#define DEM_IUMPR_SECOXS2                                         (0x0FU)

/*MAXIMUM GENERAL DENOMINATOR VALUE */
#define DEM_MAX_DENOMINATOR_NUMERATOR_VALUE                       (0xFFFFU)

/* Ratioid type */
#define DEM_RATIO_API                                             (0x01U)
#define DEM_RATIO_OBSERVER                                        (0x02U)

#define DEM_SET1_BYTE 0xff

typedef uint8 Dem_ReturnConditionOfDTCRecordUpdateType;
#define DEM_CONDITIONDTCRECUP_NO_DTC                              (0x00U)
#define DEM_CONDITIONDTCRECUP_DISABLED_DTC                        (0x01U)
#define DEM_CONDITIONDTCRECUP_NO_MATCHING_DTC                     (0x02U)

/*Operation cycle */
typedef uint8 Dem_OperationCycleKindType;
#define DEM_OPCYC_IGNITION                                        (0x00U)
#define DEM_OPCYC_OBD_DCY                                         (0x01U)
#define DEM_OPCYC_OTHER                                           (0x02U)
#define DEM_OPCYC_POWER                                           (0x03U)
#define DEM_OPCYC_TIME                                            (0x04U)
#define DEM_OPCYC_WARMUP                                          (0x05U)

#define DEM_FAILURE_CYCLE_EVENT                                   (0x00U)
#define DEM_FAILURE_CYCLE_INDICATOR                               (0x01U)

#define DEM_PROCESS_OCCCTR_TF                                     (0x00U)
#define DEM_PROCESS_OCCCTR_CDTC                                   (0x01U)

#define DEM_UNINIT                                                (0x00U)
#define DEM_PREINIT                                               (0x01U)
#define DEM_READNVDATA                                            (0x02U)
#define DEM_INIT                                                  (0x03U)
/* AUTRON Specific */
#define DEM_DEINIT                                                (0x04U)

/* Start: Do not modify */
#define DEM_BSWM_MODE_DEFAULT                                     (0x00U)
#define DEM_BSWM_MODE_READBLOCK_END                               (0x03U)
#define DEM_BSWM_MODE_WRITEBLOCK_END                              (0x04U)
/* End */


/* Type of the data element class */
#define DEM_DATA_ELEMENT_EXTERNAL                                 ((uint8)0x00)
#define DEM_DATA_ELEMENT_INTERNAL                                 ((uint8)0x01)
#define DEM_DATA_ELEMENT_AGINGCTR                                 ((uint8)0x02|DEM_DATA_ELEMENT_INTERNAL)
#define DEM_DATA_ELEMENT_OCCCTR                                   ((uint8)0x04|DEM_DATA_ELEMENT_INTERNAL)
#define DEM_DATA_ELEMENT_OVFLIND                                  ((uint8)0x08|DEM_DATA_ELEMENT_INTERNAL)
#define DEM_DATA_ELEMENT_SIGNIFICANCE                             ((uint8)0x10|DEM_DATA_ELEMENT_INTERNAL)

/* constant value to check whether data is stored in the NvRam */
#define DEM_NVM_FOOTPRINT                                         (0xABADBABEU)

/* value of event order for newest event */
#define DEM_NEWEST_EVENT                                          ((uint8)0xFF)

#define DEM_MAX_VALID_OBD_EXTENDED_RECORD_NUMBER                  (0xEFU)
#define DEM_MIN_VALID_OBD_EXTENDED_RECORD_NUMBER                  (0x90U)
#define DEM_MIN_VALID_EXTENDED_RECORD_NUMBER                      (0x01U)

#define DEM_OBD_RECORD_NUMBER                                     (0x0U)
#define DEM_DATAID_IGNORED                                        (0U)
#define DEM_ID_IGNORED                                            (0U)
#define DEM_RDFF_RECENT_FFRECNUM                                  (0xFFU) 

#define DEM_NO_DTC                                                (0U)

#define DEM_NO_IDX_U8                                             ((uint8)(0xFFU))
#define DEM_NO_IDX_U16                                            ((uint16)(0xFFFFU))
#define DEM_NO_IDX_U32                                            ((uint32)(0xFFFFFFFFU))

#define DEM_NO_EVENT_DATA                                         (DEM_NO_IDX_U16)
#define DEM_NO_EVENT_INDEX                                        (DEM_NO_IDX_U16)
#define DEM_NO_DTC_IDX                                            (DEM_NO_IDX_U16)
#define DEM_NO_EVENT_STATCBK_IDX                                  (DEM_NO_IDX_U16)
#define DEM_NO_EVENT_COND_IDX                                     (DEM_NO_IDX_U16)
#define DEM_NO_INDATT_IDX                                         (DEM_NO_IDX_U16)
#define DEM_NO_EVMEM_IDX                                          (DEM_NO_IDX_U8) 
#define DEM_NO_EVMEM_ENTRY                                        (DEM_NO_IDX_U8)

#define DEM_MAX_DTC_VALUE                                         (0x00FFFFFFU)
#define DEM_DATA_PADDING                                          ((uint8)(0xFF))

#define DEM_MAX_TIMESTAMP                                         (0xFFFFFFFFU)

/* return values of Dem_EvMem_ProcessEventRetention */
#define DEM_PROCESSEVENTRETENTION_OK                              (0x00)
#define DEM_PROCESSEVENTRETENTION_FAILED                          (0x01)
#define DEM_PROCESSEVENTRETENTION_FULL                            (0x02)


#if (DEM_OBD_SUPPORT == STD_ON)
#define DEM_SIZE_OF_OBD_FF                                        (DEM_MAX_NUMBER_OF_PID_DATAELEMENT + DEM_MAX_SIZE_OF_PID_DATAELEMENT)
/*
 #define DEM_SIZE_OF_EVENT_DATA                                    (DEM_SIZE_OF_FREEZEFRAME +DEM_SIZE_OF_EXTENDED_DATA+DEM_SIZE_OF_OBD_FF)
*/
#define DEM_SIZE_OF_PRESTORED_FF                                  (DEM_SIZE_OF_FF_ONE_RECORD + DEM_SIZE_OF_OBD_FF)
#else
/* 
#define DEM_SIZE_OF_EVENT_DATA                                    (DEM_SIZE_OF_FREEZEFRAME +DEM_SIZE_OF_EXTENDED_DATA) 
*/
#define DEM_SIZE_OF_PRESTORED_FF                                  (DEM_SIZE_OF_FF_ONE_RECORD)
#endif

/* Dem return types */
#ifndef DEM_E_NO_DTC_AVAILABLE
#define DEM_E_NO_DTC_AVAILABLE                                    (0x02)
#endif

#ifndef DEM_E_PENDING
#define DEM_E_PENDING                                             (0x10)
#endif

#define DEM_UDS_STATUS_UNSET                                      ((Dem_UdsStatusByteType)0U)


#define DEM_EVSTATUS_TESTED_PASSED_MASK                           ((DEM_UDS_STATUS_TFTOC) | (DEM_UDS_STATUS_TNCTOC))
#define DEM_EVSTATUS_TESTED_PASSED                                (0U)

#define DEM_JOB_UNDEF                                             ((uint8)0U)
#define DEM_JOB_TRIGGER                                           ((uint8)1U)
#define DEM_JOB_RUNNING                                           ((uint8)2U)
#define DEM_JOB_DONE                                              ((uint8)3U)
#define DEM_JOB_CANCEL                                            ((uint8)4U)

#define DEM_NVBLOCK_SUCCESS                                       ((uint8)0U)
#define DEM_NVBLOCK_INVALID                                       ((uint8)1U)
#define DEM_NVBLOCK_FAILED                                        ((uint8)2U)

#define DEM_GETEVID_FILTER_ED                                     (2U)
#define DEM_GETEVID_FILTER_FF                                     (1U)
#define DEM_GETEVID_FILTER_NONE                                   (0U)

/* Bit 0  : DEM_EVENT_KIND_BSW                      (0)
 *          DEM_EVENT_KIND_SWC                      (1)
 *
 * Bit 1-2: DEM_DEBOUNCE_COUNTER_BASED              (0x01U)
 *          DEM_DEBOUNCE_TIME_BASED                 (0x02U)
 *          DEM_DEBOUNCE_MONITOR_BASED              (0x03U)
 *          DEM_DEBOUNCE_NO_DEBOUNCE_BASED          (0x00U)
 *
 * Bit 3  : DEM_EVENT_SIGNIFICANCE_FAULT            (0x01U)
 *          DEM_EVENT_SIGNIFICANCE_OCCURRENCE       (0x00U)
 *
 * Bit 4  : AgingAllowed : TRUE/FALSE
 *
 * Bit 5  : Storage TestFailed : TRUE/FALSE
 *
 * Bit 6,7  : Clear WIR : TRUE/FALSE
 */
#define DEM_EVENTPARAM_EVENT_KIND_MASK                            (0x01U) /* 0000 0001 */
#define DEM_EVENTPARAM_DEBOUNCE_TYPE_MASK                         (0x06U) /* 0000 0110 */
#define DEM_EVENTPARAM_SIGNIFICANCE_MASK                          (0x08U) /* 0000 1000 */
#define DEM_EVENTPARAM_AGING_ALLOWED_MASK                         (0x10U) /* 0001 0000 */
#define DEM_EVENTPARAM_STORAGE_TF_MASK                            (0x20U) /* 0010 0000 */
#define DEM_EVENTPARAM_RESET_WIR_MASK                             (0xC0U) /* 1100 0000 */



#define DEM_EVENTPARAM_EVENT_KIND_POS                             (0U)
#define DEM_EVENTPARAM_DEBOUNCE_TYPE_POS                          (1U)
#define DEM_EVENTPARAM_SIGNIFICANCE_POS                           (3U)
#define DEM_EVENTPARAM_AGING_ALLOWED_POS                          (4U)
#define DEM_EVENTPARAM_STORAGE_TF_POS                             (5U)
#define DEM_EVENTPARAM_RESET_WIR_POS                              (6U)


#define DEM_GET_EVENTPARAM_EVENT_KIND(param)                      ((DemEventKindType)(((param) & DEM_EVENTPARAM_EVENT_KIND_MASK) >> DEM_EVENTPARAM_EVENT_KIND_POS))
#define DEM_GET_EVENTPARAM_DEBOUNCE_TYPE(param)                   ((uint8)(((param) & DEM_EVENTPARAM_DEBOUNCE_TYPE_MASK)         >> DEM_EVENTPARAM_DEBOUNCE_TYPE_POS))
#define DEM_GET_EVENTPARAM_SIGNIFICANCE(param)                    ((uint8)(((param) & DEM_EVENTPARAM_SIGNIFICANCE_MASK)          >> DEM_EVENTPARAM_SIGNIFICANCE_POS))
#define DEM_GET_EVENTPARAM_AGING_ALLOWED(param)                   ((boolean)(((param) & DEM_EVENTPARAM_AGING_ALLOWED_MASK)       >> DEM_EVENTPARAM_AGING_ALLOWED_POS))
#define DEM_GET_EVENTPARAM_STORAGE_TF(param)                      ((boolean)(((param) & DEM_EVENTPARAM_STORAGE_TF_MASK)          >> DEM_EVENTPARAM_STORAGE_TF_POS))
#define DEM_GET_EVENTPARAM_RESET_WIR(param)                       ((uint8)(((param) & DEM_EVENTPARAM_RESET_WIR_MASK)           >> DEM_EVENTPARAM_RESET_WIR_POS))

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Macros for Dem_ReturnReadEventDataType */
typedef uint8 Dem_ReturnReadEventDataType;
#define DEM_GET_READEVDATA_OK                                     ((uint8)0x00)
#define DEM_GET_READEVDATA_NOT_STORED                             ((uint8)0x01)
#define DEM_GET_READEVDATA_WRONG_DTC                              ((uint8)0x02) /* Not used */
#define DEM_GET_READEVDATA_WRONG_DTCORIGIN                        ((uint8)0x03) /* Not used */
#define DEM_GET_READEVDATA_WRONG_RECORDNUMBER                     ((uint8)0x04)
#define DEM_GET_READEVDATA_WRONG_BUFFERSIZE                       ((uint8)0x05)
  
/* Macros for Dem_ReturnGetVerifiedEventByDTCType */
typedef uint8 Dem_ReturnGetVerifiedEventByDTCType;
#define DEM_GET_EVENTBYDTC_OK                                     ((uint8)0x00)
#define DEM_GET_EVENTBYDTC_WRONG_DTC                              ((uint8)0x01)
#define DEM_GET_EVENTBYDTC_WRONG_DTCORIGIN                        ((uint8)0x02)

#if (DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH)
  /* [SWS_Dem_00572]
   * parameter DemClearDTCBehavior is set to DEM_CLRRESP_NONVOLATILE_FINISH,
   * the Dem module shall return DEM_CLEAR_OK after the volatile memory
   * and the non-volatile memory is cleared. */
#define DEM_EVMEM_STATUS_CLEARDTC                                 (DEM_EVMEM_STATUS_DIRTY|DEM_EVMEM_STATUS_TRIGGER_NVM|DEM_EVMEM_STATUS_FINISH_NVM) 
#elif (DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
  /* [SWS_Dem_00571] 
   * parameter DemClearDTCBehavior is setto DEM_CLRRESP_NONVOLATILE_TRIGGER, 
   * the Dem module shall return DEM_CLEAR_OK after the volatile memory is
   * cleared and clearing of the non-volatile memory is triggered. */       
#define DEM_EVMEM_STATUS_CLEARDTC                                 (DEM_EVMEM_STATUS_DIRTY|DEM_EVMEM_STATUS_TRIGGER_NVM)
#else
#define DEM_EVMEM_STATUS_CLEARDTC                                 (DEM_EVMEM_STATUS_DIRTY)
#endif

/* Macros for Dem_NvDataIdType  */
typedef uint8 Dem_NvDataIdType;
#define DEM_NVDATA_ALL_EVENT_STATUS_ID                            ((Dem_NvDataIdType) 0x00U)
#define DEM_NVDATA_GENERIC_NVRAM_DATA_ID                          ((Dem_NvDataIdType) 0x01U)
#define DEM_NVDATA_EVENT_MEMORY_ID                                ((Dem_NvDataIdType) 0x02U)


#define DEM_NVM_READ                                              (0x01)
#define DEM_NVM_WRITE                                             (0x00)  
  
#define DEM_DIRTY                                                 ((boolean)0x01)
#define DEM_CLEAR                                                 ((boolean)0x00)
  

 /* Macros for Dem_ClearDtcStateType */
#define DEM_CLEARDTC_STATE_READY                                  (0x01U)    
#define DEM_CLEARDTC_STATE_RUNNING                                (0x02U)
#define DEM_CLEARDTC_STATE_WAIT                                   (0x03U)
#define DEM_CLEARDTC_STATE_RESULT                                 (0x04U)
#define DEM_CLEARDTC_STATE_AFTER_CLEAROK                          (0x05U)
#define DEM_CLEARDTC_STATE_CLEAR_EVMEM                            (0x06U)
#define DEM_CLEARDTC_STATE_PREPARE_CLEARDTC                       (0x07U)

#define DEM_CLEARDTC_STATE_USER_IDLE                              (0x0U)
#define DEM_CLEARDTC_STATE_USER_CDD                               (0x1U)  
#define DEM_CLEARDTC_STATE_USER_DCM                               (0x2U)

/* Macros for debouncing event by time based */
#define DEM_EVENT_STATUS_UNDEFINED                                0x04
#define DCM_DBTIME_ACT_EVENT_QUALIFIED                            0x01
#define DCM_DBTIME_ACT_START_PASS_TIMER                           0x02
#define DCM_DBTIME_ACT_START_FAIL_TIMER                           0x03
#define DCM_DBTIME_ACT_NOP                                        0x04
#define DCM_DBTIME_ACT_CONTINOUS                                  0x05
/* Dcm uses it */
#define DEM_NO_FUNCTIONAL_UNIT                                    ((uint8)0x00)

/* Macros for Dem_TestResultType */
typedef uint8 Dem_TestResultType;
#define DEM_TEST_RESULT_PASSED_THIS_OPERATION                     0x01
#define DEM_TEST_RESULT_FAILED_THIS_OPERATION                     0x02
#define DEM_TEST_RESULT_FAILED                                    0x03
#define DEM_TEST_RESULT_PASSED                                    0x04
#define DEM_TEST_RESULT_INIT                                      0x05
#define DEM_TEST_RESULT_NO_RESULT                                 0x00

typedef uint32 Dem_DTCGroupType;
#define DEM_DTC_GROUP_EMISSION_REL_DTCS                           0x000000
#define DEM_DTC_GROUP_ALL_DTCS                                    ((uint32)0xFFFFFF)

#ifndef DEM_SWCGEN
typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                                     ((uint8)0x01)
#define DEM_DTC_KIND_EMISSION_REL_DTCS                            ((uint8)0x02)
#endif

#ifndef DEM_SWCGEN
typedef uint8 Dem_DTCOriginType;
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                             ((uint8)0x01)
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                              ((uint8)0x02)
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY                           ((uint8)0x03)
#define DEM_DTC_ORIGIN_SECONDARY_MEMORY                           ((uint8)0x04)
#endif
#define DEM_NO_DTC_ORIGIN                                         ((uint8)0x00)
#define DEM_NUM_OF_DTC_ORGINS                                     (4U)
#define DEM_MAX_OF_DTC_ORGIN                                      (5U)

#ifndef DEM_SWCGEN
typedef uint8 Dem_DTCRequestType;
#define DEM_FIRST_FAILED_DTC                                      ((uint8)0x01)
#define DEM_MOST_RECENT_FAILED_DTC                                ((uint8)0x02)
#define DEM_FIRST_DET_CONFIRMED_DTC                               ((uint8)0x03)
#define DEM_MOST_REC_DET_CONFIRMED_DTC                            ((uint8)0x04)
#endif
#define DEM_MAX_DTC_REQEST_TYPE                                   0x4

#ifndef DEM_SWCGEN
typedef uint8 Dem_DTCTranslationFormatType;
#define DEM_DTC_TRANSLATION_ISO15031_6                            0x00
#define DEM_DTC_TRANSLATION_ISO14229_1                            0x01
#define DEM_DTC_TRANSLATION_SAEJ1939_73                           0x02
#define DEM_DTC_TRANSLATION_ISO11992_4                            0x03
#define DEM_DTC_TRANSLATION_J2012DA_FORMAT_04                     0x04
#endif

#ifndef DEM_SWCGEN
typedef uint8 Dem_DTCSeverityType;
#define DEM_SEVERITY_NO_SEVERITY                                  ((uint8)0x00)
#define DEM_SEVERITY_MAINTENANCE_ONLY                             ((uint8)0x20)
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT                           ((uint8)0x40)
#define DEM_SEVERITY_CHECK_IMMEDIATELY                            ((uint8)0x80)
#endif

typedef uint8 Dem_FilterForFDCType;
#define DEM_FILTER_FOR_FDC_YES                                    0x00
#define DEM_FILTER_FOR_FDC_NO                                     0x01

typedef uint8 Dem_FilterWithSeverityType;
#define DEM_FILTER_WITH_SEVERITY_YES                              ((Dem_FilterWithSeverityType)0x00)
#define DEM_FILTER_WITH_SEVERITY_NO                               ((Dem_FilterWithSeverityType)0x01)

#ifndef DEM_SWCGEN
typedef uint8 Dem_ReturnSetFilterType;
#define DEM_FILTER_ACCEPTED                                       ((uint8)0x00)
#define DEM_WRONG_FILTER                                          ((uint8)0x01)

typedef uint8 Dem_ReturnGetStatusOfDTCType;
#define DEM_STATUS_OK                                             ((uint8)0x00)
#define DEM_STATUS_WRONG_DTC                                      ((uint8)0x01)
#define DEM_STATUS_WRONG_DTCORIGIN                                ((uint8)0x02)
#define DEM_STATUS_FAILED                                         ((uint8)0x03)
#define DEM_STATUS_PENDING                                        ((uint8)0x04)

typedef uint8 Dem_ReturnGetNextFilteredDTCType;
#define DEM_FILTERED_OK                                           ((uint8)0x00)
#define DEM_FILTERED_NO_MATCHING_DTC                              ((uint8)0x01)
#define DEM_FILTERED_PENDING                                      ((uint8)0x02)

typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
#define DEM_NUMBER_OK                                             ((uint8)0x00)
#define DEM_NUMBER_FAILED                                         ((uint8)0x01)
#define DEM_NUMBER_PENDING                                        ((uint8)0x02)

typedef uint8 Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                              ((uint8)0x00)
#define DEM_CLEAR_WRONG_DTC                                       ((uint8)0x01)
#define DEM_CLEAR_WRONG_DTCORIGIN                                 ((uint8)0x02)
#define DEM_CLEAR_FAILED                                          ((uint8)0x03)
#define DEM_CLEAR_PENDING                                         ((uint8)0x04)

typedef uint8 Dem_ReturnControlDTCSettingType;
#define DEM_CONTROL_DTC_SETTING_OK                                ((uint8)0x00)
#define DEM_CONTROL_DTC_SETTING_N_OK                              ((uint8)0x01)
#define DEM_CONTROL_DTC_WRONG_DTCGROUP                            ((uint8)0x02)

typedef uint8 Dem_ReturnDisableDTCRecordUpdateType;
#define DEM_DISABLE_DTCRECUP_OK                                   ((uint8)0x00)
#define DEM_DISABLE_DTCRECUP_WRONG_DTC                            ((uint8)0x01)
#define DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN                      ((uint8)0x02)
#define DEM_DISABLE_DTCRECUP_PENDING                              ((uint8)0x03)

typedef uint8 Dem_ReturnGetFreezeFrameDataByRecordType;
#define DEM_GET_FFBYRECORD_OK                                     ((uint8)0x00)
#define DEM_GET_FFBYRECORD_WRONG_RECORD                           ((uint8)0x01)
#define DEM_GET_FFBYRECORD_NO_DTC_FOR_RECORD                      ((uint8)0x02)

typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                                             ((uint8)0x00)
#define DEM_RECORD_WRONG_DTC                                      ((uint8)0x01)
#define DEM_RECORD_WRONG_DTCORIGIN                                ((uint8)0x02)
#define DEM_RECORD_WRONG_NUMBER                                   ((uint8)0x03)
#define DEM_RECORD_WRONG_BUFFERSIZE                               ((uint8)0x04)
#define DEM_RECORD_PENDING                                        ((uint8)0x05)

typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                                             ((uint8)0x00)
#define DEM_OCCURR_NOT_AVAILABLE                                  ((uint8)0x01)

typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
#define DEM_GET_FFDATABYDTC_OK                                    ((uint8)0x00)
#define DEM_GET_FFDATABYDTC_WRONG_DTC                             ((uint8)0x01)
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN                       ((uint8)0x02)
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER                    ((uint8)0x03)
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE                      ((uint8)0x04)
#define DEM_GET_FFDATABYDTC_PENDING                               ((uint8)0x05)

typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;
#define DEM_GET_SIZEOFEDRBYDTC_OK                                 ((uint8)0x00)
#define DEM_GET_SIZEOFEDRBYDTC_W_DTC                              ((uint8)0x01)
#define DEM_GET_SIZEOFEDRBYDTC_W_DTCOR                            ((uint8)0x02)
#define DEM_GET_SIZEOFEDRBYDTC_W_RNUM                             ((uint8)0x03)
#define DEM_GET_SIZEOFEDRBYDTC_PENDING                            ((uint8)0x04)

typedef uint8 Dem_ReturnGetSizeOfFreezeFrameByDTCType;
#define DEM_GET_SIZEOFFF_OK                                       ((uint8)0x00)
#define DEM_GET_SIZEOFFF_WRONG_DTC                                ((uint8)0x01)
#define DEM_GET_SIZEOFFF_WRONG_DTCOR                              ((uint8)0x02)
#define DEM_GET_SIZEOFFF_WRONG_RNUM                               ((uint8)0x03)
#define DEM_GET_SIZEOFFF_PENDING                                  ((uint8)0x04)

typedef uint8 Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                                  ((uint8)0x00)
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC                           ((uint8)0x01)
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY                          ((uint8)0x02)
#define DEM_GET_SEVERITYOFDTC_PENDING                             ((uint8)0x03)

typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;
#define DEM_GET_FUNCTIONALUNITOFDTC_OK                            ((uint8)0x00)
#define DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC                     ((uint8)0x01)
#endif

typedef uint8 DemEventKindType;
#define DEM_EVENT_KIND_BSW                                        ((uint8)0x00)
#define DEM_EVENT_KIND_SWC                                        ((uint8)0x01)
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> not defect */
#define DEM_WIR_RESET_ON_OPERATIONCYCLE_END                       ((uint8)0x01)
/* polyspace<MISRA-C:5.1:Not a defect:Justify with annotations> not defect */
#define DEM_WIR_RESET_ON_OPERATIONCYCLE_START                     ((uint8)0x02)

#ifndef Dem_UdsStatusByteType
typedef uint8           Dem_UdsStatusByteType;
#endif
typedef Dem_EventIdType Dem_NumOfEventIdType;
typedef sint8           Dem_FaultDetectionCounterType;
typedef uint16          Dem_NumOfDebounceType;
/* types of the date element class */
typedef uint8           Dem_NumOfDataElementClassType;
typedef uint8           Dem_SizeOfDataElementClassType;
typedef CONSTP2CONST(Dem_NumOfDataElementClassType, AUTOMATIC,DEM_CONST) Dem_NumOfDataElementClassCPCType;
/* types of the freeze frame */
typedef uint16          Dem_SizeOfFreezeFrameClassType;
typedef uint8           Dem_NumOfFreezeFrameClassType;
/* types of the record number of the freeze frame */
typedef uint8           Dem_RecordNumberType;
typedef uint8           Dem_NumOfRecordNumberType;
/* types of the extended data */
typedef uint16          Dem_SizeOfExtendedDataClassType ;
typedef uint16          Dem_SizeOfExtendedDataRecordClassType ;
typedef uint16          Dem_NumOfExtendedDataRecordClassType ;
typedef uint8           Dem_NumOfExtendedDataClassType;
/* types of the extended data number of the extended data 
@IF_REQ : from  record number  to extended data number */
typedef uint8           Dem_ExtendedDataNumberType;
typedef uint8           Dem_NumOfExtendedDataNumberType;
/* types of the did*/
typedef uint16          Dem_DataIdentifierType;
typedef uint16          Dem_SizeOfDidClassType;
typedef uint8           Dem_NumOfDidClassType;
typedef Dem_EventIdType Dem_NumOfEventRelatedDataType;
typedef uint8           Dem_NumOfPrestoredFFType;
typedef uint8           Dem_NumOfEventMemoryEntryType;
typedef uint32          Dem_DTCType;
typedef uint16          Dem_NumOfDTCValueType;
typedef uint8           Dem_EventPriorityType;
typedef uint8           Dem_EventOccurrenceType;
/* For OBD */
/* types of the pid,
@IF_REQ :   to Dem_SizeOfPidRecordClassType,Dem_NumOfPidRecordClassType */
typedef uint16          Dem_SizeOfPidRecordType;
typedef uint16          Dem_NumOfPidRecordType;
/* @IF_REQ : to Dem_NumOfPidDataElementClassType,Dem_SizeOfPidDataElementClassType*/
typedef uint8           Dem_PidIdentifierType;
typedef uint16          Dem_NumOfPidDataElementType;
typedef uint8           Dem_SizeOfPidDataElementType;
/* types of the PID Class */
typedef uint8           Dem_NumOfPidClassType;
typedef uint16          Dem_SizeOfPidClassType;
typedef uint32          Dem_SizeOfOBDFreezeFrameDataType;
/* types of the Indicator */
typedef uint16          Dem_NumOfIndicatorAttributeType; 

typedef enum {
 DEM_FFFORMAT_TYPE_RAW = 1,
 DEM_FFFORMAT_TYPE_HDR_DID,
 DEM_FFFORMAT_TYPE_HDR_REC
} Dem_FFBufferFormatType;


typedef enum {
  DEM_DATA_OK = 0U,
  DEM_DATA_WRONG_DTC,/* DET */
  DEM_DATA_WRONG_SUPPRESSION,/* NO DET */
  DEM_DATA_WRONG_DTCORIGIN,
  DEM_DATA_WRONG_RECORDNUMBER,
  DEM_DATA_WRONG_BUFFERSIZE
} Dem_ReturnEventErrorType;


/* DET ERROR CODE */
#define DEM_E_PARAM_CONFIG                                        ((uint8)0x10)
#define DEM_E_PARAM_POINTER                                       ((uint8)0x11)
#define DEM_E_PARAM_DATA                                          ((uint8)0x12)
#define DEM_E_PARAM_LENGTH                                        ((uint8)0x13)
#define DEM_E_UNINIT                                              ((uint8)0x20)
#define DEM_E_NODATAAVAILABLE                                     ((uint8)0x21)
#define DEM_E_WRONG_CONDITION                                     ((uint8)0x22)
#define DEM_E_OPERATION_CYCLE_STARTED                             ((uint8)0x41)
#define DEM_E_UNEXPECTED_RESULT                                   ((uint8)0x91)
#define DEM_E_OUT_OF_BOUNDS                                       ((uint8)0x92)
#define DEM_E_BUFFER_LENGTH                                       ((uint8)0x93)
#define DEM_E_OUT_OF_RANGE                                        ((uint8)0x94)

/* Obd compliance */
#define DEM_OBDII_CALIFORNIAARB                                   ((uint8)0x01)
#define DEM_OBD_US_FEDERALEPA                                     ((uint8)0x02)
#define DEM_OBD_and_OBDII                                         ((uint8)0x03)
#define DEM_OBDI_CERTIFIEDTOCALIFORNIA                            ((uint8)0x04)
#define DEM_NOT_OBD_COMPLIANT                                     ((uint8)0x05)
#define DEM_EOBD                                                  ((uint8)0x06)
#define DEM_EOBD_and_OBDII                                        ((uint8)0x07)
#define DEM_EOBD_and_OBD                                          ((uint8)0x08)
#define DEM_EOBD_OBD_and_OBDII                                    ((uint8)0x09)
#define DEM_JOBD                                                  ((uint8)0x0A)
#define DEM_JOBD_and_OBDII                                        ((uint8)0x0B)
#define DEM_JOBD_and_EOBD                                         ((uint8)0x0C)
#define DEM_JOBD_EOBD_and_OBDII                                   ((uint8)0x0D)
#define DEM_EMD                                                   ((uint8)0x11)
#define DEM_EMDPLUS                                               ((uint8)0x12)
#define DEM_HD_OBD_C                                              ((uint8)0x13)
#define DEM_HD_OBD                                                ((uint8)0x14)
#define DEM_WWH_OBD                                               ((uint8)0x15)
#define DEM_HD_EOBD_I                                             ((uint8)0x17)
#define DEM_HD_EOBD_I_N                                           ((uint8)0x18)
#define DEM_HD_EOBD_II                                            ((uint8)0x19)
#define DEM_HD_EOBD_II_N                                          ((uint8)0x1A)
#define DEM_OBDBR_1                                               ((uint8)0x1C)
#define DEM_OBDBR_2                                               ((uint8)0x1D)

/* Readiness group */
#define DEM_OBD_RDY_MISF                                          ((uint8)0x01)
#define DEM_OBD_RDY_AC                                            ((uint8)0x02)
#define DEM_OBD_RDY_BOOSTPR                                       ((uint8)0x03)
#define DEM_OBD_RDY_CAT                                           ((uint8)0x04)
#define DEM_OBD_RDY_CMPRCMPT                                      ((uint8)0x05)
#define DEM_OBD_RDY_EGSENS                                        ((uint8)0x06)
#define DEM_OBD_RDY_ERG                                           ((uint8)0x07)
#define DEM_OBD_RDY_EVAP                                          ((uint8)0x08)
#define DEM_OBD_RDY_FLSYS                                         ((uint8)0x09)
#define DEM_OBD_RDY_HCCAT                                         ((uint8)0x0A)
#define DEM_OBD_RDY_HTCAT                                         ((uint8)0x0B)
#define DEM_OBD_RDY_NONE                                          ((uint8)0x0D)
#define DEM_OBD_RDY_NOXCAT                                        ((uint8)0x0E)
#define DEM_OBD_RDY_O2SENS                                        ((uint8)0x0F)
#define DEM_OBD_RDY_O2SENSHT                                      ((uint8)0x10)
#define DEM_OBD_RDY_PMFLT                                         ((uint8)0x11)
#define DEM_OBD_RDY_SECAIR                                        ((uint8)0x12)

#define DEM_CHK_UDSSTATUS_AVAIL(Bit)                              ((DEM_STATUS_AVAILABILITY_MASK & (Bit)) == (Bit))

/* NvRamBlockAccessOptimizationSupport == false  */
#if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_OFF)
  /*****************************************************
   *         ONE NV BLOCK FOR ALL EVENT STATUS         *
   *****************************************************/
   
  /* bit 0 : TestFailed */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TF) && ((DEM_NUM_OF_TESTFAILED_BIT_STORAGE > 0U) || (DEM_STATUS_BIT_STORAGE_TESTFAILED == STD_ON)))
  #define DEM_UDS_STATUS_TF_ALLEVENTSTATUS                        (DEM_UDS_STATUS_TF)
  #else
  #define DEM_UDS_STATUS_TF_ALLEVENTSTATUS                        (0)
  #endif
  
  /* bit 1 : TestFailedThisOperationCycle */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
  #define DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS                     (DEM_UDS_STATUS_TFTOC)
  #else
  #define DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS                     (0)
  #endif

  /* bit 2 : PendingDTC */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC))
  #define DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS                      (DEM_UDS_STATUS_PDTC)
  #else
  #define DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS                      (0)
  #endif

  /* bit 3 : ConfirmedDTC : It is calculable based on the failure counter of stored event entry */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_CDTC))
  #define DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS                      (DEM_UDS_STATUS_CDTC)
  #else
  #define DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS                      (0)
  #endif

  /* bit 4 : TestNotCompletedSinceLastClear */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TNCSLC))
  #define DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS                    (DEM_UDS_STATUS_TNCSLC)
  #else
  #define DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS                    (0)
  #endif
  
  /* bit 5 : TestFailedSinceLastClear */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TFSLC))
  #define DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS                     (DEM_UDS_STATUS_TFSLC)
  #else
  #define DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS                     (0)
  #endif

  /* bit 6 : TestNotCompletedThisOperationCycle */  
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
  #define DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS                    (DEM_UDS_STATUS_TNCTOC)
  #else
  #define DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS                    (0)
  #endif

  /* bit 7 : WarningIndicatorRequested */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_WIR))
  #define DEM_UDS_STATUS_WIR_ALLEVENTSTATUS                       (DEM_UDS_STATUS_WIR)
  #else
  #define DEM_UDS_STATUS_WIR_ALLEVENTSTATUS                       (0)
  #endif  

/* NvRamBlockAccessOptimizationSupport == true  */    
#else

  #if (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON)
    /*****************************************************
     *         ONE NV BLOCK FOR ALL EVENT STATUS         *
     *****************************************************/
    /* bit 0 : TestFailed , displaceed */
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TF) && ((DEM_NUM_OF_TESTFAILED_BIT_STORAGE > 0U) ||(DEM_STATUS_BIT_STORAGE_TESTFAILED == STD_ON)))
    #define DEM_UDS_STATUS_TF_ALLEVENTSTATUS                        (DEM_UDS_STATUS_TF)
    #else
    #define DEM_UDS_STATUS_TF_ALLEVENTSTATUS                        (0)
    #endif
    
    /* bit 1 : TestFailedThisOperationCycle */
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
    #define DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS                     (DEM_UDS_STATUS_TFTOC)
    #else
    #define DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS                     (0)
    #endif

    /* bit 2 : PendingDTC TF may be not cleared when event is aged */
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC))
    #define DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS                      (DEM_UDS_STATUS_PDTC)
    #else
    #define DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS                      (0)
    #endif

    /* bit 3 : ConfirmedDTC, It is stored in only the event memory entry */
    #define DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS                      (0)

    /* bit 4 : TestNotCompletedSinceLastClear */
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TNCSLC))
    #define DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS                    (DEM_UDS_STATUS_TNCSLC)
    #else
    #define DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS                    (0)
    #endif
    
    /* bit 5 : TestFailedSinceLastClear */
    #if ((DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TFSLC)) && (DEM_STATUS_BIT_HANDLING_TFSLC == DEM_STATUS_BIT_NORMAL))
    #define DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS                     (DEM_UDS_STATUS_TFSLC)
    #else
    #define DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS                     (0)
    #endif

    /* bit 6 : TestNotCompletedThisOperationCycle */  
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
    #define DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS                    (DEM_UDS_STATUS_TNCTOC)
    #else
    #define DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS                    (0)
    #endif

    /* bit 7 : WarningIndicatorRequested */
    #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_WIR) && (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON))
    #define DEM_UDS_STATUS_WIR_ALLEVENTSTATUS                       (DEM_UDS_STATUS_WIR)
    #else
    #define DEM_UDS_STATUS_WIR_ALLEVENTSTATUS                       (0)
    #endif
    
  #else  /* if displacement is off */
    /* bit 0 : TestFailed , displaceed */    
    #define DEM_UDS_STATUS_TF_ALLEVENTSTATUS                        (0)  
    /* bit 1 : TestFailedThisOperationCycle */
    #define DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS                     (0)
    /* bit 2 : PendingDTC TF may be not cleared when event is aged */
    #define DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS                      (0)
    /* bit 3 : ConfirmedDTC, It is stored in only the event memory entry */
    #define DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS                      (0)
    /* bit 4 : TestNotCompletedSinceLastClear */
    #define DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS                    (0)
    /* bit 5 : TestFailedSinceLastClear */
    #define DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS                     (0)
    /* bit 6 : TestNotCompletedThisOperationCycle */  
    #define DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS                    (0)
    /* bit 7 : WarningIndicatorRequested */
    #define DEM_UDS_STATUS_WIR_ALLEVENTSTATUS                       (0)
    
  #endif /* (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON) */

  #define DEM_UDS_STATUS_TRIGGER_ALLEVENTSTATUS                     ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TF_ALLEVENTSTATUS | \
                                                                    (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS | \
																	(Dem_UdsStatusByteType)DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS | \
                                                                    (Dem_UdsStatusByteType)DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS | \
                                                                    (Dem_UdsStatusByteType)DEM_UDS_STATUS_WIR_ALLEVENTSTATUS)


  /*****************************************************
   *                EVENT MEMORY ENTRY                 *
   *****************************************************/

  /* bit 0 : TestFailed */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TF) && ((DEM_NUM_OF_TESTFAILED_BIT_STORAGE > 0U) || (DEM_STATUS_BIT_STORAGE_TESTFAILED == STD_ON)))
  #define DEM_UDS_STATUS_TF_EVMEM                                 (DEM_UDS_STATUS_TF)
  #else
  #define DEM_UDS_STATUS_TF_EVMEM                                 (0)
  #endif
  
  /* bit 1 : TestFailedThisOperationCycle */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
  #define DEM_UDS_STATUS_TFTOC_EVMEM                              (DEM_UDS_STATUS_TFTOC)
  #else
  #define DEM_UDS_STATUS_TFTOC_EVMEM                              (0)
  #endif

  /* bit 2 : PendingDTC */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC))
  #define DEM_UDS_STATUS_PDTC_EVMEM                               (DEM_UDS_STATUS_PDTC)
  #else
  #define DEM_UDS_STATUS_PDTC_EVMEM                               (0)
  #endif
  
  /* bit 3 : ConfirmedDTC : It is calculable based on the failure counter of stored event entry */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_CDTC))
  #define DEM_UDS_STATUS_CDTC_EVMEM                               (DEM_UDS_STATUS_CDTC)
  #else
  #define DEM_UDS_STATUS_CDTC_EVMEM                               (0)
  #endif

  /* bit 4 : TestNotCompletedSinceLastClear */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TNCSLC))
  #define DEM_UDS_STATUS_TNCSLC_EVMEM                             (DEM_UDS_STATUS_TNCSLC)
  #else
  #define DEM_UDS_STATUS_TNCSLC_EVMEM                             (0)
  #endif
  
  /* bit 5 : TestFailedSinceLastClear */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_TFSLC))
  #define DEM_UDS_STATUS_TFSLC_EVMEM                              (DEM_UDS_STATUS_TFSLC)
  #else
  #define DEM_UDS_STATUS_TFSLC_EVMEM                              (0)
  #endif

  /* bit 6 : TestNotCompletedThisOperationCycle */  
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_PDTC) || (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON))  
  #define DEM_UDS_STATUS_TNCTOC_EVMEM                             (DEM_UDS_STATUS_TNCTOC)
  #else
  #define DEM_UDS_STATUS_TNCTOC_EVMEM                             (0)
  #endif

  /* bit 7 : WarningIndicatorRequested */
  #if (DEM_CHK_UDSSTATUS_AVAIL(DEM_UDS_STATUS_WIR))
  #define DEM_UDS_STATUS_WIR_EVMEM                                (DEM_UDS_STATUS_WIR)
  #else
  #define DEM_UDS_STATUS_WIR_EVMEM                                (0)
  #endif 

  #define DEM_UDS_STATUS_MASK_EVMEM                               (((Dem_UdsStatusByteType)DEM_UDS_STATUS_TF_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TFTOC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_CDTC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TNCSLC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TFSLC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TNCTOC_EVMEM) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_WIR_EVMEM))

#endif

#if ((DEM_EVENT_DISPLACEMENT_SUPPORT == STD_OFF) && (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON))
#define DEM_UDS_STATUS_IN_EVENT_NVBLOCK                           (STD_OFF)
#else
/* if event displacement is supported or nvblock access optimization is supported , EventStatus Array is assigned 
 to EventStatusNvBlock */
#define DEM_UDS_STATUS_IN_EVENT_NVBLOCK                           (STD_ON)
#endif


#define DEM_UDS_STATUS_MASK_ALLEVENTSTATUS                        (((Dem_UdsStatusByteType)DEM_UDS_STATUS_TF_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS) |\
                                                                  ((Dem_UdsStatusByteType)DEM_UDS_STATUS_WIR_ALLEVENTSTATUS))

/* identify whether debounce algorithm is used */
#if((DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON) || \
    (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON) || \
    (DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL > 0u))
#define DEM_DEBOUNCE_SUPPORT                                      (STD_ON)
#else
#define DEM_DEBOUNCE_SUPPORT                                      (STD_FF)
#endif

/* identify whether reportFirstConfirmedDTC,reportFirstTestFailedDTC,
 * reportMostRecentTestFailedDTC ,reportMostRecentConfirmedDTC are used */
#ifdef DCM_RPT_FAILEDCONFIRMEDDTCINFO

#if (DCM_RPT_FAILEDCONFIRMEDDTCINFO == STD_ON)
#define  DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED                  STD_ON
#else 
#define  DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED                  STD_OFF
#endif

#else
#define  DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED                  STD_OFF

#endif


/* Dem uses time stamp in the event memory according to the configurations */
#if ((DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON) ||\
      (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON) ||\
      (DEM_J1939_SUPPORT == STD_ON))
#define DEM_EVMEM_TIMESTAMP_USED                                  (STD_ON)      
#define DEM_EVMEM_SET_MAX_TIMESTAMP(GetTimeStampFunc, DTCOrigin) \
do {\
  uint32 timeStamp = (GetTimeStampFunc);\
  if (Dem_MaxTimeStamp[(DTCOrigin)] < timeStamp)\
  {\
    Dem_MaxTimeStamp[(DTCOrigin)] = timeStamp;\
  }\
} while(0)

#else
#define DEM_EVMEM_TIMESTAMP_USED                                  (STD_OFF)
#define DEM_EVMEM_SET_MAX_TIMESTAMP(GetTimeStampFunc, DTCOrigin)  do {} while(0)

#endif

/* identify whether all NvM Blocks are configured */
#if (\
  ((DEM_NUM_OF_PRIMARY_EVENTMEMORY_NVBLOCKID > 0U) || (DEM_NUM_OF_SECONDARY_EVENTMEMORY_NVBLOCKID > 0U)) &&\
  (DEM_NVM_BLK_ID_EVENT_STATUS > 0U) &&\
  (DEM_NVM_BLK_ID_NON_VOLATILE_DATA)\
)
#define DEM_NV_BLOCKS_USED                                       (STD_ON)                                          
#else
#define DEM_NV_BLOCKS_USED                                       (STD_OFF)
#endif



/*****************************************************************************
 *                        MACRO FUNCTIONS                                    *
 *****************************************************************************/
#define COUNTOF(_Array)                                           (sizeof(_Array) / sizeof((_Array)[0]))

#define DEM_IS_BIT_SET_UDSSTATUSBYTE(EventId, Mask)               ((Dem_AllEventStatusByte[(EventId)] & (Dem_UdsStatusByteType)(Mask)) != (Dem_UdsStatusByteType)0U)
#define DEM_IS_BIT_UNSET_UDSSTATUSBYTE(EventId, Mask)             ((Dem_AllEventStatusByte[(EventId)] & (Dem_UdsStatusByteType)(Mask)) == (Dem_UdsStatusByteType)0U)
#define DEM_SET_UDSSTATUSBYTE(EventId, Mask)                      do{(Dem_AllEventStatusByte[(EventId)] |= (Dem_UdsStatusByteType)(Mask));} while(0)
#define DEM_CLR_UDSSTATUSBYTE(EventId, Mask)                      do{(Dem_AllEventStatusByte[(EventId)] &= (Dem_UdsStatusByteType)(~(Dem_UdsStatusByteType)(Mask)));} while(0)
#define DEM_RST_UDSSTATUSBYTE(EventId, Mask)                      do{(Dem_AllEventStatusByte[(EventId)] = (Dem_UdsStatusByteType)(Mask));} while(0)

#define DEM_SET_EVENTSTATUSBYTE(UdsStatusByte, Mask)                      do{((UdsStatusByte) |= (Dem_UdsStatusByteType)(Mask));} while(0)
#define DEM_CLR_EVENTSTATUSBYTE(UdsStatusByte, Mask)                      do{((UdsStatusByte) &= (Dem_UdsStatusByteType)(~(Dem_UdsStatusByteType)(Mask)));} while(0)

#define DEM_IS_AGING_SUPPORTED(event ,OperationCycleId) \
 ((DEM_TRUE==(event)->blAgingAllowed) && \
  ((event)->e_AgingCycleId == (OperationCycleId)))

#if (DEM_DEV_ERROR_DETECT == STD_ON)
#define DEM_REPORT_ERROR(sid, type)                               do{(void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,(sid),(type));} while(0)
#else
#define DEM_REPORT_ERROR(sid, type)                               do{}while(0)
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
#define DEM_IF_DTC_ORIGIN_SECONDARY_MEMORY(DTCOrigin)             (DEM_DTC_ORIGIN_SECONDARY_MEMORY == (DTCOrigin))
#else
#define DEM_IF_DTC_ORIGIN_SECONDARY_MEMORY(DTCOrigin)             (0U)
#endif
#define DEM_IF_DTCORIGIN_IS_VALID(DTCOrigin)                      ((DEM_DTC_ORIGIN_PRIMARY_MEMORY == (DTCOrigin)) || DEM_IF_DTC_ORIGIN_SECONDARY_MEMORY(DTCOrigin))

/* comp.lang.c FAQ list Question 20.8  
#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)
 */
#define DEM_BYTE_BITS                                             (8U)
#define DEM_BITARRAY_BITMASK(b)                                   ((uint8)(1U << ((b) % DEM_BYTE_BITS)))
#define DEM_BITARRAY_BITSLOT(b)                                   ((b) / DEM_BYTE_BITS)
#define DEM_BITARRAY_BITSET(a, b)                                 ((a)[DEM_BITARRAY_BITSLOT(b)] |= DEM_BITARRAY_BITMASK(b))
#define DEM_BITARRAY_BITCLEAR(a, b)                               ((a)[DEM_BITARRAY_BITSLOT(b)] &= ((uint8)~DEM_BITARRAY_BITMASK(b)))
#define DEM_BITARRAY_BITTEST_ISBITSET(a, b)                       ((a)[DEM_BITARRAY_BITSLOT(b)] & DEM_BITARRAY_BITMASK(b))
#define DEM_BITARRAY_BITNSLOTS(nb)                                (((nb) + (DEM_BYTE_BITS - 1U)) / DEM_BYTE_BITS)

#define DEM_UDSSTATUS_SYNC_NV(Dest, EvPos, udsStatusByte, StatusMask) \
do {\
  if (0U == ((udsStatusByte) & (StatusMask))) {\
    DEM_BITARRAY_BITCLEAR((Dest), (EvPos));\
  }\
  else {\
    DEM_BITARRAY_BITSET((Dest), (EvPos));\
  }\
}\
while(0)

#define DEM_UDSSTATUS_GET_NV(Dest, EvId, NumOfShift, Src) \
do {\
  if (0U != DEM_BITARRAY_BITTEST_ISBITSET((Src), (EvId))) {\
    (Dest) |= (uint8)(1U << (NumOfShift));\
  }\
  else {\
    (Dest) &= (uint8)(~((uint8)(1U << (NumOfShift))));\
  }\
}\
while(0)


/* Direction for Couneter based debouncing */

#define DEM_CTRDEB_DIRECTION_UNDEF                              (0x0U)
#define DEM_CTRDEB_DIRECTION_UP                                 (0x1U)
#define DEM_CTRDEB_DIRECTION_DOWN                               (0x2U)



/* #define DEM_STATIC_ASSERT(expr, msg) extern char compiler_assert_ ## msg [(expr) ? (+1) : (-1)] */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

#endif
/* _DEM_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
