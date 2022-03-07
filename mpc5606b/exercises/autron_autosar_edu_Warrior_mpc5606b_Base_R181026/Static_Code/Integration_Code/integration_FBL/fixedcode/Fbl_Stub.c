/*******************************************************************************
**  (C) 2012 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Fbl_Stub.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the API definitions for fbl,  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.0     03-June-2016  Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Use the FBL provided by AUTRON */
#include "Fbl_Stub.h"

/*******************************************************************************
** Function Name        : bcore_SetStartupCommand                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Service for DCM                                     **
**                                                                            **
** Sync/Async           : N/A                                                 **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : uint32                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
*******************************************************************************/
void bcore_SetStartupCommand(unsigned int ul_Value)
{
  STARTUP_COMMAND = ul_Value; /*lint !e923 Cast from int to pointer */
}

/*******************************************************************************
** Function Name        : bcore_GetStartupCommand                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Service for DCM                                     **
**                                                                            **
** Sync/Async           : N/A                                                 **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : uint32                                              **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
*******************************************************************************/
unsigned int bcore_GetStartupCommand(void)
{
  return STARTUP_COMMAND; /*lint !e923 Cast from int to pointer */
}

/*******************************************************************************
** Function Name        : bcore_GetProgConditions                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Service for DCM                                     **
**                                                                            **
** Sync/Async           : N/A                                                 **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : uint32 *                                            **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
*******************************************************************************/
uint32 * bcore_GetProgConditions(void)
{
  return PROG_CONDITIONS; /*lint !e923 Cast from int to pointer */
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
