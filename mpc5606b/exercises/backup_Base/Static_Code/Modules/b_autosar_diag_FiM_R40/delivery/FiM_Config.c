/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_Config.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : Configurable const variable definition                        **
**              of Function Inhibition Manager                                **
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
** 1.0.1     14-01-2016    YoungJin Yun  Modified function's location to      **
**                                       provide the lib and create the       **
**                                       wrapper functions                    **
**                                                                            **
** 1.0.0     01-01-2013   Autron        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM.h"         /* FiM Header File */
#include "FiM_Ram.h"     /* Ram header file */
#include "FiM_Config.h"     /* Ram header file */

#if (FIM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                     /* Det header file */
#endif

/*******************************************************************************
**                           Global Data                                      **
*******************************************************************************/
#define FIM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Total number of FIDs configured in FiM */
const FiM_FidsSizeType Fim_Total_Num_Of_Fids = (FiM_FidsSizeType)FIM_TOTAL_NUM_OF_FIDS;

/* Total number of DEM events referred in FIM */
const FiM_EventsSizeType Fim_Total_Num_Of_Dem_Events =  (FiM_EventsSizeType)FIM_TOTAL_NUM_OF_DEM_EVENTS;

/* The largest value of all the configured FIDs */
const FiM_FunctionIdType Fim_Largest_FID = (FiM_FunctionIdType)FIM_LARGEST_FID;

#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if(FIM_EN_EVENTID_BINARYSEARCH == STD_ON)
static FUNC(boolean, FIM_CODE)FiM_EventIdBinarySearch(
  Dem_EventIdType LddEventId,
  P2VAR(FiM_EventsSizeType, AUTOMATIC, FIM_VAR)LpEventIndex
  );
#endif
    
#if(FIM_EN_EVENTID_BINARYSEARCH == STD_OFF)
static FUNC(boolean, FIM_CODE)FiM_EventIdLinearSearch(
  Dem_EventIdType LddEventId,
  P2VAR(FiM_EventsSizeType, AUTOMATIC, FIM_VAR)LpEventIndex
  );
#endif
    
#if(FIM_FIDS_SEQUENTIAL == STD_OFF)
#if(FIM_EN_FID_BINARYSEARCH == STD_ON)
static FUNC(boolean, FIM_CODE)FiM_FidBinarySearch(
  FiM_FunctionIdType LddFid,
  P2VAR(FiM_FidsSizeType, AUTOMATIC, FIM_VAR)LddFidArrayIndex
  );
#endif
#endif
    
#if(FIM_FIDS_SEQUENTIAL == STD_OFF)
#if(FIM_EN_FID_BINARYSEARCH == STD_OFF)
static FUNC(boolean, FIM_CODE)FiM_FidLinearSearch(
  FiM_FunctionIdType LddFid,
  P2VAR(FiM_FidsSizeType, AUTOMATIC, FIM_VAR)LddFidArrayIndex
  );
#endif
#endif


/*******************************************************************************
** Function Name        : FiM_EventIdSearch                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaEventInfo for a requested event.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddEventId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpEventIndex                                        **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"
FUNC(boolean, FIM_CODE)FiM_EventIdSearch(
  Dem_EventIdType LddEventId,
  P2VAR(FiM_EventsSizeType, AUTOMATIC, FIM_VAR)LpEventIndex
)
{
  boolean LblEventExists;

  #if(FIM_EN_EVENTID_BINARYSEARCH == STD_ON)
  /* Check whether EventId is in the configured range - use binary search */
  LblEventExists = FiM_EventIdBinarySearch(LddEventId, LpEventIndex);
  #else
  LblEventExists = FiM_EventIdLinearSearch(LddEventId, LpEventIndex);
  #endif

  return LblEventExists;
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : FiM_FidSearch                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaFunctionId for a requested Fid.              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddFid                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LddFidArrayIndex                                    **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"
FUNC(boolean, FIM_CODE) FiM_FidSearch(FiM_FunctionIdType LddFid,
  P2VAR(FiM_FidsSizeType, AUTOMATIC, FIM_VAR)LddFidArrayIndex)
{
  boolean foundFid = FIM_FALSE;

  /* Check if FID is within the configured range */
  #if(FIM_FIDS_SEQUENTIAL == STD_ON)
  *LddFidArrayIndex = (FiM_FidsSizeType)LddFid;
  if(LddFid > Fim_Largest_FID)
  {
    #if(FIM_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET indicating FID out of range Pointer */
    (void)Det_ReportError(FIM_MODULE_ID, FIM_INSTANCE_ID,
      FIM_GETFUNCTIONPERMISSION_SID, FIM_E_FID_OUT_OF_RANGE);
    #endif
  }
  else
  {
    foundFid = FIM_TRUE;
  }
  #else

  #if(FIM_EN_FID_BINARYSEARCH == STD_ON)
  foundFid = FiM_FidBinarySearch(LddFid, LddFidArrayIndex);
  #else
  foundFid = FiM_FidLinearSearch(LddFid, LddFidArrayIndex);
  #endif

  if(FIM_FALSE == foundFid)
  {
    #if(FIM_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET indicating FID out of range Pointer */
    (void)Det_ReportError(FIM_MODULE_ID, FIM_INSTANCE_ID,
      FIM_GETFUNCTIONPERMISSION_SID, FIM_E_FID_OUT_OF_RANGE);
    #endif
  }
  #endif  

  return foundFid;
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"

  


/*******************************************************************************
** Function Name        : FiM_EventIdBinarySearch                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaEventInfo for a requested event.             **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddEventId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpEventIndex                                        **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        FiM_GaaEventInfo                                    **
**                                                                            **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
#if(FIM_EN_EVENTID_BINARYSEARCH == STD_ON)
#define FIM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean, FIM_CODE)FiM_EventIdBinarySearch(
  Dem_EventIdType LddEventId, P2VAR(FiM_EventsSizeType, AUTOMATIC,
  FIM_VAR)LpEventIndex)
{
  Dem_EventIdType LddCurrEventId;
  FiM_EventsSizeType LddHigh;
  FiM_EventsSizeType LddLow;
  FiM_EventsSizeType LddMiddle;
  boolean LblReturn;

  /* Initialize LddHigh variable with number of Events */
  LddHigh = Fim_Total_Num_Of_Dem_Events - FIM_ONE;
  /* Initialize LddLow variable with one */
  LddLow = FIM_ONE;
  /* Initialize return value with false */
  LblReturn = FIM_FALSE;
  /* Get the lower limit of EventId */
  LddCurrEventId = FiM_GaaEventInfo[FIM_ZERO].ddEventId;

  /* Check whether search EventId is in range */
  if((LddEventId >= LddCurrEventId) &&
  (LddEventId <= FiM_GaaEventInfo[LddHigh].ddEventId))
  {
    /* Check whether requested Event is not the first element of the list */
    if(LddEventId != LddCurrEventId)
    {
      do
      {
        /* Get the middle index number */
        LddMiddle = (LddHigh + LddLow) >> FIM_ONE;

        /* Get the EventId of the middle */
        LddCurrEventId = FiM_GaaEventInfo[LddMiddle].ddEventId;

        /* Compare the current EventId with the requested one */
        if(LddCurrEventId == LddEventId)
        {
          /* Update the identified Event Index number in out variable */
          *LpEventIndex = LddMiddle;
          /* Update the return variable to true */
            LblReturn = FIM_TRUE;
          /* Set LddHigh to zero to break the loop */
          LddHigh = FIM_ZERO;
        }
        else
        {
          /* Check if the requested EventId smaller than the current EventId */
          if(LddEventId < LddCurrEventId)
          {
            if(LddMiddle > FIM_ZERO)
            {
              /*The requested EventId is smaller than current, update LddHigh*/
              LddHigh = LddMiddle - FIM_ONE;
            }
            else
            {
              LddHigh = FIM_ZERO;
            }
          }
          else
          {
            /* The requested EventId is greater than current, update LddLow */
            LddLow = LddMiddle + FIM_ONE;
          }
        } /* end if(LddCurrEventId == LddEventId) */
      }while(LddLow <= LddHigh);

    } /* if(LddEventId != LddCurrEventId) */
    else
    {
      /* Update the return pointer with the first element of event */
      *LpEventIndex = FIM_ZERO;
      /* Update the return variable to true */
      LblReturn = FIM_TRUE;
    }
  } /* if((LddEventId >= LddCurrEventId) && ... */
  return (LblReturn);
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : FiM_EventIdLinearSearch                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaEventInfo for a requested event.             **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Input Parameters     : LddEventId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpEventIndex                                        **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        FiM_GaaEventInfo                                    **
**                                                                            **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
#if(FIM_EN_EVENTID_BINARYSEARCH == STD_OFF)
#define FIM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean, FIM_CODE)FiM_EventIdLinearSearch(
  Dem_EventIdType LddEventId, P2VAR(FiM_EventsSizeType, AUTOMATIC,
  FIM_VAR)LpEventIndex)
{
  boolean LblSearchResult;
  /* variable to break the FOR loop */
  FiM_EventsSizeType LddIndex;

  /* Set the search result flag to FIM_FALSE */
  LblSearchResult = FIM_FALSE;

  /* Check for LddEventId by linear search */
  for(LddIndex = FIM_ZERO; ((LddIndex < Fim_Total_Num_Of_Dem_Events) &&
    (LblSearchResult == FIM_FALSE)); LddIndex++)
  {
    /* Is EventId matches with requested EventId */
    if(FiM_GaaEventInfo[LddIndex].ddEventId == LddEventId)
    {
      /* Set search result flag to TRUE */
      LblSearchResult = FIM_TRUE;
    }
  }
  /* Decrement the index to get the correct index since it would be
     incremented one extra time when the control comes out of FOR loop */
  LddIndex--;
  /* Update index for Request Array Index */
  *LpEventIndex = LddIndex;
  /* Return FIM_TRUE if found else FIM_FALSE */
  return(LblSearchResult);
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : FiM_FidBinarySearch                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaFunctionId for a requested Fid.              **
**                        This service is used only incase if the FIDs are    **
**                        not sequential.                                     **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddFid                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LddFidArrayIndex                                    **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        FiM_GaaFunctionId                                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
#if(FIM_FIDS_SEQUENTIAL == STD_OFF)
#if(FIM_EN_FID_BINARYSEARCH == STD_ON)
#define FIM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean, FIM_CODE) FiM_FidBinarySearch(FiM_FunctionIdType LddFid,
  P2VAR(FiM_FidsSizeType, AUTOMATIC, FIM_VAR)LddFidArrayIndex)
{
  FiM_FunctionIdType LddCurrFid;
  FiM_FidsSizeType LddHigh;
  FiM_FidsSizeType LddLow;
  FiM_FidsSizeType LddMiddle;
  boolean LblReturn;

  LblReturn = FIM_FALSE;

  /* Initialize LddHigh variable with number of FIDs */
  LddHigh = Fim_Total_Num_Of_Fids - FIM_ONE;
  /* Initialize LddLow variable with one */
  LddLow = FIM_ONE;

  /* Get the lower limit of Fid */
  LddCurrFid = FiM_GaaFunctionId[FIM_ZERO];

  /* Check whether search Fid is in range */
  if((LddFid >= LddCurrFid) && (LddFid <= FiM_GaaFunctionId[LddHigh]))
  {
    /* Check whether requested Fid is not the first element of the list */
    if(LddFid != LddCurrFid)
    {
      do
      {
        /* Get the middle index number */
        LddMiddle = (LddHigh + LddLow) >> FIM_ONE;

        /* Get the Fid of the middle */
        LddCurrFid = FiM_GaaFunctionId[LddMiddle];

        /* Compare the current Fid with the requested one */
        if(LddCurrFid == LddFid)
        {
          /* Update the identified Fid Index number in out variable */
          *LddFidArrayIndex = LddMiddle;
          /* Set LddHigh to zero to break the loop */
          LddHigh = FIM_ZERO;

          LblReturn = FIM_TRUE;
        }
        else
        {
          /* Check if the requested Fid smaller than the current Fid */
          if(LddFid < LddCurrFid)
          {
            if(LddMiddle > FIM_ZERO)
            {
              /* The requested Fid is smaller than current, update LddHigh */
              LddHigh = LddMiddle - FIM_ONE;
            }
            else
            {
              LddHigh = FIM_ZERO;
            }
          }
          else
          {
            /* The requested Fid is greater than current, update LddLow */
            LddLow = LddMiddle + FIM_ONE;
          }
        } /* end if(LddCurrFid == LddFid) */
      }while(LddLow <= LddHigh);

    } /* if(LddFid != LddCurrFid) */
    else
    {
      /* Update the return pointer with the first element of Fid */
      *LddFidArrayIndex = FIM_ZERO;

      LblReturn = FIM_TRUE;
    }
  } /* if((LddFid >= LddCurrFid) && ... */
  return(LblReturn);
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : FiM_FidLinearSearch                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service identifies array index of              **
**                        FiM_GaaFunctionId for a requested Fid.              **
**                        This service is used only incase if the FIDs are    **
**                        not sequential.                                     **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddFid                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LddFidArrayIndex                                    **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        FiM_GaaFunctionId                                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
#if(FIM_FIDS_SEQUENTIAL == STD_OFF)
#if(FIM_EN_FID_BINARYSEARCH == STD_OFF)
#define FIM_START_SEC_CODE
#include "MemMap.h"
static FUNC(boolean, FIM_CODE) FiM_FidLinearSearch(FiM_FunctionIdType LddFid,
  P2VAR(FiM_FidsSizeType, AUTOMATIC, FIM_VAR)LddFidArrayIndex)
{
  boolean LblSearchResult;
  /* variable to break the FOR loop */
  FiM_FidsSizeType LddIndex;
  /* Set the search result flag to FIM_FALSE */
  LblSearchResult = FIM_FALSE;
  /* Check for LddFid by linear search */
  for(LddIndex = FIM_ZERO; ((LddIndex < Fim_Total_Num_Of_Fids) &&
    (LblSearchResult == FIM_FALSE)); LddIndex++)
  {
    /* Is FiD matches with requested FiD */
    if(FiM_GaaFunctionId[LddIndex] == LddFid)
    {
      /* Set search result flag to TRUE */
      LblSearchResult = FIM_TRUE;
    }
  }
  /* Decrement the index to get the correct index since it would be
     incremented one extra time when the control comes out of FOR loop */
  LddIndex--;
  /* Update index for Request Array Index */
  *LddFidArrayIndex = LddIndex;
  /* Return FIM_TRUE if found else FIM_FALSE */
  return(LblSearchResult);
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
