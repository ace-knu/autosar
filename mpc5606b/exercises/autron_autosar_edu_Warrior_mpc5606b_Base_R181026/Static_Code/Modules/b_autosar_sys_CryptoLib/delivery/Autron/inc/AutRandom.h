/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: AutRandom.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTRON Random algorithm                                       **
**                                                                            **
**  PURPOSE   : Header file to publish AUTRON crypto algorithm prototypes     **
**                - Autron Random                                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.2     10-Jan-2017   Sinil        Redmine #7156                         **
** 1.0.1     14-Jul-2016   Sinil        Redmine #5540                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef AUTRANDOM_H
#define AUTRANDOM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"                /* Standars types Header file */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** Length of random in byte. */
#define Aut_Random_LEN                                 4U

/** Hash context for Random */
typedef struct STag_AutRandomContext
{
  uint32 ulRandom;
} AutRandomContext;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* Function for generating Random */
extern boolean AutRandom_Generate(AutRandomContext* pRandomCtx, uint32 seedAddr);
#endif /* AUTRANDOM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
