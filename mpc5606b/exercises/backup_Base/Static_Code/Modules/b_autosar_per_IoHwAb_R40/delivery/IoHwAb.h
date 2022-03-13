/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb.h                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
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
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.5     16-SEP-2015   Jongyoung      1.MISRA-C Rule violation fix        **
** 1.0.4     05-Jun-2015   Jongyoung      1.IOHWAB_MCUSPECIFIC_SID newly add  **
** 1.0.3     26-Apr-2015   Jongyoung      1.Add TLE7240SL Demux functionality **
** 1.0.2     18-Aug-2014   Sinil          1. Add busy error Det code          **
**                                        2. Add service IDs for AnaIn        **
**                                        3. Update Det error codes           **
** 1.0.1     13-Jun-2014   Sinil          Add a service ID for L99MC6         **
** 1.0.0     07-Mar-2014   Sinil          Initial version                     **
*******************************************************************************/

#ifndef IOHWAB_H
#define IOHWAB_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "IoHwAb_Types.h"
#include "IoHwAb_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Instance identification */
#define IOHWAB_INSTANCE_ID                          ((uint8)0x00)

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* DET error is reported if an API is invoked with a null pointer parameter */
#define IOHWAB_E_DET_WRONG_STATE                    0x01
#define IOHWAB_E_DET_WRONG_SETTING                  0x02
#define IOHWAB_E_DET_WRONG_PARAM                    0x03
#define IOHWAB_E_DET_SETUP_FAIL                     0x04
#define IOHWAB_E_DET_PROC_FAIL                      0x05
#define IOHWAB_E_DET_BUSY                           0x06

/*******************************************************************************
**                      Service IDs                                           **
*******************************************************************************/
/* Service Id of IoHwAb_Init */
#define IOHWAB_INIT_SID                             0x01

/* Service Id of IoHwAb_GetVersionInfo */
#define IOHWAB_GETVERSIONINFO_SID                   0x10

/* Service Id of IoHwAb_AdcNotification */
#define IOHWAB_ADCNOTIFICATION_SID                  0x20

/* Service Id of IoHwAb_PwmNotification */
#define IOHWAB_PWMNOTIFICATION_SID                  0x30

/* Service Id of IoHwAb_IcuNotification */
#define IOHWAB_ICUNOTIFICATION_SID                  0x40

/* Service Id of IoHwAb_GptNotification */
#define IOHWAB_GPTNOTIFICATION_SID                  0x50

/* Service Id of IoHwAb_IOM_10ms */
#define IOHWAB_IOM_10MS_SID                         0xa0

#define IOHWAB_ANAIN_INIT_SID                       0xb0
#define IOHWAB_ANAINDIR_READ_DIRECT_SID             0xb1
#define IOHWAB_ANAIN_CONVERT_ALL_SID                0xb2
#define IOHWAB_ANAIN_READ_DIRECT_SID                0xb3

#define IOHWAB_DIGIN_MC33972_INIT_SID               0xc0
#define IOHWAB_DIGIN_MC33972_ACQ_SID                0xc1
#define IOHWAB_DIGIN_MC33972_L2H_SID                0xc2
#define IOHWAB_DIGIN_MC33972_H2L_SID                0xc3

#define IOHWAB_DIGOUT_L9826_SID                     0xd0
#define IOHWAB_DIGOUT_L99MC6_SID                    0xd1
#define IOHWAB_DIGOUT_TLE7240SL_SID                 0xd2

#define IOHWAB_VOLMON_SID                           0xe0

#define IOHWAB_MCUSPECIFIC_SID                      0xf0

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_Init(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_DeInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#if (IOHWAB_VERSION_INFO_API == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, IOHWAB_APPL_DATA) versioninfo);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IOHWAB_VERSION_INFO_API == STD_ON)*/

#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
typedef CoSvAb_FastTimerDelay IoHwAb_TimerDelay;
#endif
#if (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
typedef Gpt_ValueType IoHwAb_TimerDelay;
#endif

#endif /* IOHWAB_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

