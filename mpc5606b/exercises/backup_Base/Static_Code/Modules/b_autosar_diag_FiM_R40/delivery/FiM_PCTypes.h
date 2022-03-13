/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : This file contains the structure definitions and macro        **
**              definitions of FiM module                                     **
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
** 1.0.1     26-Nov-2012   Udaykumar B   File name is updated                 **
**                                                                            **
** 1.0.0     01-Nov-2012   Autron        Initial version                      **
*******************************************************************************/
#ifndef FIM_PCTYPES_H
#define FIM_PCTYPES_H

/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM_Types.h"        /* FiM Types Definition Header File */
#include "Dem_Types.h"        /* Dem Types Header File */
#include "Dem.h"              /* Dem Header File */

/*******************************************************************************
**                      MACRO Definitions                                     **
*******************************************************************************/
/* Inhibition mask for Last Failed */
#define FIM_LAST_FAILED                            0x00

/* Inhibition mask for Not Tested*/
#define FIM_NOT_TESTED                             0x01

/* Inhibition mask for Tested */
#define FIM_TESTED                                 0x02

/* Inhibition mask for Tested & Failed */
#define FIM_TESTED_AND_FAILED                      0x03

#define FIM_ZERO                                   0x00
#define FIM_ONE                                    0x01
#define FIM_FOUR                                   0x04

#define FIM_TRUE                                   0x01
#define FIM_FALSE                                  0x00

#define FIM_NOT_INITIALIZED                        0x00
#define FIM_INITIALIZED                            0x01

/* Bit 0 of the status is set */
#define FIM_MASK_LAST_FAILED                       0x01
/* Bit 6 of the status is set */
#define FIM_MASK_NOT_TESTED                        0x40
/*
 * Bit 6 of the status is not set, mask is same that of FIM_MASK_NOT_TESTED
 * Only the expected value after masking (FIM_EXP_STS_TESTED) will differ.
 */
#define FIM_MASK_TESTED                            0x40

/* Bit 0 and Bit 6 are set */
#define FIM_MASK_TESTED_AND_FAILED                 0x41

/* Expected result is the expected result of (status & mask) for a given mask */

/* (Status)&(FIM_MASK_LAST_FAILED = 0000 0001b), expected 0000 0001b */
#define FIM_EXP_STS_LAST_FAILED                    0x01
/* (Status)&(FIM_MASK_NOT_TESTED = 0100 0000b), expected 0100 0000b */
#define FIM_EXP_STS_NOT_TESTED                     0x40
/* (Status)&(FIM_MASK_TESTED = 0100 0000b), expected 0000 0000b */
#define FIM_EXP_STS_TESTED                         0x00
/* (Status)&(FIM_MASK_TESTED_AND_FAILED = 0100 0001b), expected 0000 0001b */
#define FIM_EXP_STS_TESTED_AND_FAILED              0x01

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                     EventMask Configuration structure                      **
*******************************************************************************/
typedef struct STag_FiM_FunctionIdMask
{
  /* This parameter provides the index number of FID array */
  FiM_FidsSizeType ddFidIndex;

  /*
   * This structure element gives the mask of event and must be fetched from
   * FiMInhInhibitionMask parameter in inhibition configuration container
   */
  uint8 ucInhibitionMask;
}FiM_FunctionIdMask;

/*******************************************************************************
**                         Event Information structure                        **
*******************************************************************************/
typedef struct STag_FiM_EventInfo
{
  /*
   * This element gives the Eventid and is fetched from parameter
   * FiMInhEventRef in FiMInhChoiceDemRef choice container if it is configured
   * in FiMInhRefchoice container and from parameter FiMInputSumEventRef in
   * FiMEventSummary container if FiMInhChoiceSumRef choice container is
   * configured in FiMInhRefchoice container
   */
  Dem_EventIdType ddEventId;

  /*
   * This structure element contains the no of FIDs associated to the above
   * eventid. Generation tool shall generate this parameter based on the
   * FiMInhFunctionIdRef parameter from the FiMInhibitionconfiguration
   * container
   */
  FiM_FidsSizeType ddNumberOfFids;

  /*
   * This element contains the index of first Fid (to which this event belongs)
   * in the array FiM_GaaFunctionIdMask
   */
  FiM_EventFidLinkType ddFidArrayIndex;
}FiM_EventInfo;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FIM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(FiM_FunctionIdType, FIM_CONST)FiM_GaaFunctionId[];
#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define FIM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(FiM_EventInfo, FIM_CONST)FiM_GaaEventInfo[];
#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define FIM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(FiM_FunctionIdMask, FIM_CONST)FiM_GaaFunctionIdMask[];
#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

#endif /* FIM_PCTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
