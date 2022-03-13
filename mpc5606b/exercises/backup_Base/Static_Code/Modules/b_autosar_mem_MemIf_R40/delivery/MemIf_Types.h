/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemIf_Types.h                                                 **
**                                                                            **
**  TARGET    : ALL                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Abstraction Interface Module                   **
**                                                                            **
**  PURPOSE   :  Provision of Type Definitions                                **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/
#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Type definition for MEMIF status types */
typedef enum
{
  MEMIF_UNINIT = 0,
  MEMIF_IDLE,
  MEMIF_BUSY,
  MEMIF_BUSY_INTERNAL
}MemIf_StatusType;

/* Type definition for MEMIF job result types */
typedef enum
{
  MEMIF_JOB_OK = 0,
  MEMIF_JOB_FAILED,
  MEMIF_JOB_PENDING,
  MEMIF_JOB_CANCELED,
  MEMIF_BLOCK_INCONSISTENT,
  MEMIF_BLOCK_INVALID
}MemIf_JobResultType;

/* Type definition for MEMIF mode types */
typedef enum
{
  MEMIF_MODE_SLOW = 0,
  MEMIF_MODE_FAST
}MemIf_ModeType;

#endif /* MEMIF_TYPES_H */
/*******************************************************************************
**                     End of File                                            **
*******************************************************************************/
