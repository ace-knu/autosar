/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_ObdRam.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Defining Global Variables                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
********************************************************************************
** 1.0.0    18-11-2016      Autron      Initial Version                       **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_ObdRam.h" /* Dem global Ram variables header file for OBD */

#if (DEM_OBD_SUPPORT == STD_ON)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*************************************************************************
 * VAR INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * NO_INIT_UNSPECIFIED == SAVED_ZONE
 ************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
/* Permanent Event Memory variable */
VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_PermanentEventMemory
  [DEM_MAX_NUMBER_EVENT_ENTRY_PER];
#endif

#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


/*************************************************************************
 * VAR CLEARED_32
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* Used to Store the Mil on time */
VAR(uint32, DEM_VAR) Dem_GulTimeSinceMilOn;
/* Used to calculate time in sec */
VAR(uint32, DEM_VAR) Dem_GulDemTimeObdSecCount;
/* Used to calculate time in milli sec */
VAR(uint32, DEM_VAR) Dem_GulDemTimeObdmsCount;
/* Used to Store whether event is disabled or not for pid41e */
VAR(uint32, DEM_VAR) Dem_GulEventIdDisabled;
/* Used to Store time since clear dtc is called count in min */
VAR(uint32, DEM_VAR) Dem_GulDemClearTimeCount;

#define DEM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

/*************************************************************************
 * CLEARED_16
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Store the value of General Denominator*/
VAR(uint16, DEM_VAR) Dem_GusGeneralDenominator;
/* Store the value of ignition counter */
VAR(uint16, DEM_VAR) Dem_GusIgnitionCylCnt;
/* Pointer point the memory location in which Obd event is stored */
VAR(uint16, DEM_VAR) Dem_GusObdDtcFirstStored;
/* Pointer point the memory location in which Obd event is stored */
VAR(uint16, DEM_VAR) Dem_GusEventstoredinPermanent;
/* Store the value of General Denominator*/
VAR(uint16, DEM_VAR) Dem_GaaIumprDenominator[DEM_SIXTEEN];
/* Store the value of General Denominator*/
VAR(uint16, DEM_VAR) Dem_GaaIumprNumerator[DEM_SIXTEEN];
/* Used to Store the warm up cycle count */
VAR(uint16, DEM_VAR) Dem_GusWarmUpCycleCount;
#if (DEM_NUMBER_OF_RATIO_INFO > 0U)
/* Store the value of General Denominator*/
VAR(uint16, DEM_VAR) Dem_GusRatioIdDisable[DEM_NUMBER_OF_RATIO_INFO];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/*************************************************************************
 * CLEARED_8
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* Used to calculate Mil status of pid01 */
VAR(uint8, DEM_VAR) Dem_GucMilonFlag;

/* Used to calculate Warm up cycle count when Mil status is off */
VAR(uint8, DEM_VAR) Dem_GucWarmUpCycleCountMil;

#if (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
/* Permanent Event Memory variable */
VAR(uint8, DEM_VAR) Dem_PermanentEventMemoryState
  [DEM_MAX_NUMBER_EVENT_ENTRY_PER];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

/*****************************************************************************/
/* VAR CLEARED BOOLEAN                                                       */
/*****************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Current operation cycle Id Value */
VAR(boolean, DEM_VAR) Dem_ObdEventStored;
/* Used to calculate Mil status of pid01 */
VAR(boolean, DEM_VAR) Dem_GblMilStarted;
/* Used to Store the pto status */
VAR(boolean, DEM_VAR) Dem_GblPtoStatus;
/* Used to calculate time since clear dtc is called */
VAR(boolean, DEM_VAR) Dem_GblClearTimeStartObd;

#define DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*************************************************************************
 * CONST
 ************************************************************************/
 
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  

/*****************************************************************************/

#endif /* DEM_OBD_SUPPORT == STD_ON */
/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/
