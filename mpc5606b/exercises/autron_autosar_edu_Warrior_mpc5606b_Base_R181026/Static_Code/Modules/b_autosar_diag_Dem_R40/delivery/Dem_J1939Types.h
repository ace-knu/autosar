/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_J1939Types.h                                              **
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
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.1    20-07-2017    EunKyung.Kim   Changes made As per Redmine #9294    **
**                                                                            **
** 1.0.0    10-06-2016    youngjin.yun   Initial Version                      **
*******************************************************************************/

#ifndef DEM_J1939TYPES_H
#define DEM_J1939TYPES_H

/* 
   polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is AUTOSAR standard
   polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect
   polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect
   polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> Not a defect 
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Dem_Type.h"   /* Rte Header File for Dem Types */
#include "Std_Types.h"
#include "Dem_Cfg.h"
#include "Dem_Types.h"


#if (DEM_J1939_SUPPORT == STD_ON)


/*******************************************************************************
**                         Global Data Types                                  **
*******************************************************************************/
  /*For J1939 */
typedef uint8 Dem_ReturnGetNextFilteredElementType;
/*#define DEM_FILTERED_OK                                         ((uint8)0x00) */
#define DEM_FILTERED_NO_MATCHING_ELEMENT                          ((uint8)0x01) 
/* #define DEM_FILTERED_PENDING                                   ((uint8)0x02) */
#define DEM_FILTERED_BUFFER_TOO_SMALL                             ((uint8)0x03)

typedef uint8 Dem_J1939DcmDTCStatusFilterType;
#define DEM_J1939DTC_ACTIVE                                       0 
#define DEM_J1939DTC_PREVIOUSLY_ACTIVE                            1 
#define DEM_J1939DTC_PENDING                                      2
#define DEM_J1939DTC_PERMANENT                                    3
#define DEM_J1939DTC_CURRENTLY_ACTIVE                             4

typedef uint16  Dem_J1939DcmLampStatusType;

#define DEM_J1939LAMP_SLOW_FLASH                                  0x00
#define DEM_J1939LAMP_FAST_FLASH                                  0x01
#define DEM_J1939LAMP_DO_NOT_FLASH                                0x03
#define DEM_J1939LAMP_ON                                          0x01
#define DEM_J1939LAMP_OFF                                         0x00
#define DEM_J1939LAMP_NOT_AVAILABLE                               0xFFFFU

typedef uint8  Dem_J1939DcmSetClearFilterType; 
#define DEM_J1939DTC_CLEAR_ALL                                    0 /* active DTCs */
#define DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE                      1 /* previously active DTCs */

typedef uint8  Dem_J1939DcmSetFreezeFrameFilterType; 
#define DEM_J1939DCM_FREEZEFRAME                                  0 /* FreezeFrame (DM04) */
#define DEM_J1939DCM_EXPANDED_FREEZEFRAME                         1 /* ExpandedFreezeFrame(DM25) */
#define DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME                 2 /* SPNs in Expanded-FreezeFrame (DM24) */


#define DEM_J1939DCM_FILTEREDDTC_BY_CHRONOLOGICAL_ORDER           (0)
#define DEM_J1939DCM_FILTEREDDTC_BY_EVENTIDD                      (1)


/* Not supported yet */
#define DEM_J1939DCMGETNUMBEROFFILTEREDDTC_USED                   (STD_OFF)


/*******************************************************************************
 **                 Structure for combined DTC                                 **
 *******************************************************************************/
typedef struct STag_Dem_J1939LampType
{
  uint16 RedStopLampId;
  uint16 WarningLampId;
  uint16 ProtectLampId;
} Dem_J1939LampType;


typedef struct STag_Dcm_J1939DTCFilterStateType {
  Dem_DTCSeverityType j1939_DTCKind;               
  Dem_J1939DcmDTCStatusFilterType j1939_DTCStatusFilter;
  boolean j1939_JobAction;
  uint16  j1939_NumOfFilteredDTC;
  uint8 FilteringType;
} Dem_J1939DTCFilterStateType;

#endif

/* 
   polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is AUTOSAR standard
   polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect
   polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect
   polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> Not a defect 
*/


#endif
/* _DEM_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
