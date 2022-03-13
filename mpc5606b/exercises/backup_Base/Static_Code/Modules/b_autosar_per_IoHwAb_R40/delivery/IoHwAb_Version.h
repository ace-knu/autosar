/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_Version.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for IoHwAb_Version                                   **
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
** 1.0.3     05-Dec-2016   Jongyoung      #6845                               **

*******************************************************************************/

#ifndef IOHWAB_VERSION_H
#define IOHWAB_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_Cfg.h"

#if (defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX ))
#include "Dio_Version.h"
#include "Port_Version.h"
#include "Icu_Version.h"
#include "Gpt_Version.h"
#include "Pwm_Version.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define IOHWAB_VERSION_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_VERSION_AR_RELEASE_MINOR_VERSION     0u
#define IOHWAB_VERSION_AR_RELEASE_REVISION_VERSION  3u

/* Software Version Information */
#define IOHWAB_VERSION_SW_MAJOR_VERSION             1u
#define IOHWAB_VERSION_SW_MINOR_VERSION             1u
#define IOHWAB_VERSION_SW_PATCH_VERSION             0u

/* Included Files AUTOSAR Specification Version */

#define IOHWAB_ADC_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_ADC_AR_RELEASE_MINOR_VERSION     0u

#define IOHWAB_SPI_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_SPI_AR_RELEASE_MINOR_VERSION     0u

#define IOHWAB_DIO_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_DIO_AR_RELEASE_MINOR_VERSION     0u

#define IOHWAB_PWM_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_PWM_AR_RELEASE_MINOR_VERSION     0u

#define IOHWAB_PORT_AR_RELEASE_MAJOR_VERSION    4u
#define IOHWAB_PORT_AR_RELEASE_MINOR_VERSION    0u

#define IOHWAB_ICU_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_ICU_AR_RELEASE_MINOR_VERSION     0u

#define IOHWAB_GPT_AR_RELEASE_MAJOR_VERSION     4u
#define IOHWAB_GPT_AR_RELEASE_MINOR_VERSION     0u

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* IOHWAB_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
