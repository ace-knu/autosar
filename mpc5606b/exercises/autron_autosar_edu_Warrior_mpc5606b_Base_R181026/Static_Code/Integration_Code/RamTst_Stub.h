/*******************************************************************************
**  (C) 2012 KPIT Cummins Infosystems Limited, Hyundai Motor Company,         **
**  Hyundai MOBIS Company and KEFICO Corporation                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cdd_RamTst.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Cdd_RamTst stub                                       **
**                                                                            **
**  PURPOSE   : Declaration of Cdd_RamTst stub functions                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                  Description                    **
********************************************************************************
** 1.0.0     15-Nov-2012   Shanthi Vishwanath  Initial version                **
*******************************************************************************/
#ifndef CDD_H
#define CDD_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                                Macros                                      **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CDD_AR_RELEASE_MAJOR_VERSION    0x04
#define CDD_AR_RELEASE_MINOR_VERSION    0x00
#define CDD_AR_RELEASE_REVISION_VERSION 0x03

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern uint8 GaaRamTstTestAdd[];

extern void RamTst_ErrorNotification(void);
extern void RamTst_TestCompletedNotification(void);
extern void TestCdd_DefaultBehavior(void);

#endif /* CDD_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
