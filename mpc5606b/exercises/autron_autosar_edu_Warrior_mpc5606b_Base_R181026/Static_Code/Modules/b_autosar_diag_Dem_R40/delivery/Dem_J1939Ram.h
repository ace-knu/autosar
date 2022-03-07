/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_J1939Ram.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Config.c                                     **
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
** 1.1.0    16-11-2016    YJ.Yun      Changes made As per Redmine #6188       **
**                                                                            **
** 1.0.0     08-06-2016   YJ.Yun      Initial Version                         **
*******************************************************************************/

#ifndef DEM_J1939RAM_H
#define DEM_J1939RAM_H
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

#include "Dem.h" 
#include "Rte_Dem.h"

#if (DEM_J1939_SUPPORT == STD_ON)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_PriEvMemChronoOrder[];
extern VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_PriEvMemChronoOrderNextLoc;

#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#endif


/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */


#endif
