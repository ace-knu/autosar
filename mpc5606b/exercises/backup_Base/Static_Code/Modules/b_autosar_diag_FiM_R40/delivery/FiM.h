/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service IDs     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 1.1.0     30-09-2016    Youngjin Yun  Redmine #3280                        **
**                                                                            **
** 1.0.0     01-Nov-2012   Autron        Initial version                      **
*******************************************************************************/
#ifndef FIM_H
#define FIM_H

/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM_Types.h"     /* FiM Types Definition Header File */
#include "Dem_Types.h"     /* Dem Types Definition Header File */
#include "FiM_Cfg.h"       /* FiM Cfg Definition Header File */
#include "FiM_Config.h"
#include "FiM_Version.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Service ID for FiM_Init */
#define FIM_INIT_SID                               0x00U
/* Service ID for FiM_GetFunctionPermission */
#define FIM_GETFUNCTIONPERMISSION_SID              0x01U
/* Service ID for FiM_DemTriggerOnEventStatus */
#define FIM_DEMTRIGGERONEVENTSTATUS_SID            0x02U
/* Service ID for FiM_DemInit */
#define FIM_DEMINIT_SID                            0x03U
/* Service ID for FiM_GetVersionInfo */
#define FIM_GETVERSIONINFO_SID                     0x04U
/* Service ID for FiM_MainFunction */
#define FIM_MAINFUNCTION_SID                       0x05U
/* FIM instance ID */
#define FIM_INSTANCE_ID                            0x00U

/* Standard Development error codes */
#define FIM_E_WRONG_PERMISSION_REQ                 0x01U
#define FIM_E_WRONG_TRIGGER_ON_EVENT               0x02U
#define FIM_E_FID_OUT_OF_RANGE                     0x03U
#define FIM_E_INVALID_POINTER                      0x05U
#define FIM_E_INVALID_EVENTSTATUSEXTENDEDTYPE      0x06U

/* Implementation specific Development error codes */
#define FIM_E_INIT_NOT_SUCCESS                     0xF0U
#define FIM_E_UNINIT                               0xF1U
#define FIM_E_INVALID_EVENTID                      0xF2U

/* Macro for Unused parameter */
#define FIM_UNUSED(x)       do{if((uint8)(x) != (uint8)DCM_ZERO) {}} while(0)
#define FIM_UNUSED_PTR(x)   do{if((x) != NULL_PTR) {}} while(0)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"
/* Extern for FiM_Init */
extern FUNC(void,FIM_CODE)FiM_Init
(
P2CONST(FiM_ConfigType,AUTOMATIC,FIM_APPL_CONST)FiMConfigPtr
);

/* Extern for FiM_DemTriggerOnEventStatus */
#if (FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
extern FUNC(void, FIM_CODE)FiM_DemTriggerOnEventStatus
(
Dem_EventIdType EventId,
Dem_EventStatusExtendedType EventStatusOld,
Dem_EventStatusExtendedType EventStatusNew
);
#endif

/* Extern for FiM_DemInit */
extern FUNC(void, FIM_CODE)FiM_DemInit(void);


#ifndef RTE_FIM_H
/* Extern for FiM_GetFunctionPermission */
extern FUNC(Std_ReturnType, FIM_CODE)FiM_GetFunctionPermission
(
FiM_FunctionIdType FID,
P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA)Permission
);

/* Extern for FiM_MainFunction */
extern FUNC(void, FIM_CODE)FiM_MainFunction(void);
#endif

#define FIM_STOP_SEC_CODE
#include "MemMap.h"

#define FIM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Extern for mask value for each type of MASK */
extern CONST(uint8, FIM_CONST)FiM_GaaMaskValues[];

/* Extern for expected result for each type of MASK */
extern CONST(uint8, FIM_CONST)FiM_GaaExpMaskedResult[];
#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */


#endif /* FIM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
