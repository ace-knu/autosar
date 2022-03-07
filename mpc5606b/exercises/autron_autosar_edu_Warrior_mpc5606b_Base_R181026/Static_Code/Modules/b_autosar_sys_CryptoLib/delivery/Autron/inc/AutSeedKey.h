/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: AutSeedKey.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTRON SeedKey algorithm                                      **
**                                                                            **
**  PURPOSE   : Header file to publish AUTRON crypto algorithm prototypes     **
**                - Autron SeedKey                                            **
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
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef AUTSEEDKEY_H
#define AUTSEEDKEY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"                /* Standars types Header file */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** Length of one hash block in bytes. */
#define Aut_SeedKey_BLOCK_BYTES                         4U
/** Length of digest in byte. */
#define Aut_SeedKey_DIGEST_LEN                          4U

/** Hash context for SeedKey */
typedef struct STag_AutSeedKeyContext
{
  uint32 ulSeedKey;
} AutSeedKeyContext;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* Function for generating SeedKey */
extern boolean AutSeedKey_Generate(AutSeedKeyContext* pSeedKeyCtx,
  uint32 ulValue);
#endif /* AUTSEEDKEY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
