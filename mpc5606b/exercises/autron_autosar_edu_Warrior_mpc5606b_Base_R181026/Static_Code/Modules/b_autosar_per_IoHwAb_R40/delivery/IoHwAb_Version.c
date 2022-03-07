/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_Version.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : APIs implementation for IoHwAb module                         **
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
** 1.0.2     25-Mar-2015   Jongyoung  1.Manage the single module version      **
** 1.0.1     21-Mar-2014   Sinil      Task ID : 853                           **
**                                    Update Port and Dio version check       **
** 1.0.0     07-Mar-2014   Sinil      Initial version                         **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_Version.h"

#if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define IOHWAB_VERSION_C_AR_RELEASE_MAJOR_VERSION       4
#define IOHWAB_VERSION_C_AR_RELEASE_MINOR_VERSION       0
#define IOHWAB_VERSION_C_AR_RELEASE_REVISION_VERSION    3

/* FILE VERSION INFORMATION */
#define IOHWAB_VERSION_C_SW_MAJOR_VERSION               1
#define IOHWAB_VERSION_C_SW_MINOR_VERSION               1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (IOHWAB_AR_RELEASE_MAJOR_VERSION != \
  IOHWAB_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "IoHwAb_Version.c : Mismatch in Specification Major Version"
#endif

#if (IOHWAB_AR_RELEASE_MINOR_VERSION != \
  IOHWAB_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "IoHwAb_Version.c : Mismatch in Specification Minor Version"
#endif

#if (IOHWAB_AR_RELEASE_REVISION_VERSION != \
  IOHWAB_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "IoHwAb_Version.c : Mismatch in Specification Patch Version"
#endif

#if (IOHWAB_SW_MAJOR_VERSION != IOHWAB_VERSION_C_SW_MAJOR_VERSION)
  #error "IoHwAb_Version.c : Mismatch in Major Version"
#endif

#if (IOHWAB_SW_MINOR_VERSION != IOHWAB_VERSION_C_SW_MINOR_VERSION)
  #error "IoHwAb_Version.c : Mismatch in Minor Version"
#endif

#if ((IOHWAB_USE_DIG_DIR == STD_ON) || (IOHWAB_USE_DIG_IN == STD_ON) \
  || (IOHWAB_USE_DIG_OUT == STD_ON))
#if (PORT_AR_RELEASE_MAJOR_VERSION != IOHWAB_PORT_AR_RELEASE_MAJOR_VERSION)
  #error "Port.h : Mismatch in Specification Major Version"
#endif

#if (PORT_AR_RELEASE_MINOR_VERSION != IOHWAB_PORT_AR_RELEASE_MINOR_VERSION)
  #error "Port.h : Mismatch in Specification Minor Version"
#endif

#if (DIO_AR_RELEASE_MAJOR_VERSION != IOHWAB_DIO_AR_RELEASE_MAJOR_VERSION)
  #error "Dio.h : Mismatch in Specification Major Version"
#endif

#if (DIO_AR_RELEASE_MINOR_VERSION != IOHWAB_DIO_AR_RELEASE_MINOR_VERSION)
  #error "Dio.h : Mismatch in Specification Minor Version"
#endif
#endif /* ((IOHWAB_USE_DIG_DIR == STD_ON) || (IOHWAB_USE_DIG_IN == STD_ON) \
  || (IOHWAB_USE_DIG_OUT == STD_ON)) */

#if ((IOHWAB_USE_ANA_IN_DIR == STD_ON) || (IOHWAB_USE_ANA_IN == STD_ON))
#if (ADC_AR_RELEASE_MAJOR_VERSION != IOHWAB_ADC_AR_RELEASE_MAJOR_VERSION)
  #error "Adc.h : Mismatch in Specification Major Version"
#endif

#if (ADC_AR_RELEASE_MINOR_VERSION != IOHWAB_ADC_AR_RELEASE_MINOR_VERSION)
  #error "Adc.h : Mismatch in Specification Minor Version"
#endif
#endif /* ((IOHWAB_USE_ANA_IN_DIR == STD_ON) || (IOHWAB_USE_ANA_IN == STD_ON))*/

#if ((IOHWAB_USE_MC33972 == STD_ON) || (IOHWAB_USE_L9826 == STD_ON))
#if (SPI_AR_RELEASE_MAJOR_VERSION != IOHWAB_SPI_AR_RELEASE_MAJOR_VERSION)
  #error "Spi.h : Mismatch in Specification Major Version"
#endif

#if (SPI_AR_RELEASE_MINOR_VERSION != IOHWAB_SPI_AR_RELEASE_MINOR_VERSION)
  #error "Spi.h : Mismatch in Specification Minor Version"
#endif
#endif /* ((IOHWAB_USE_MC33972 == STD_ON) || (IOHWAB_USE_L9826 == STD_ON))*/

#if ((IOHWAB_USE_ICU == STD_ON) || (IOHWAB_MC33972_EXTINT == STD_ON))
#if (ICU_AR_RELEASE_MAJOR_VERSION != IOHWAB_ICU_AR_RELEASE_MAJOR_VERSION)
  #error "Icu.h : Mismatch in Specification Major Version"
#endif

#if (ICU_AR_RELEASE_MINOR_VERSION != IOHWAB_ICU_AR_RELEASE_MINOR_VERSION)
  #error "Icu.h : Mismatch in Specification Minor Version"
#endif
#endif /* ((IOHWAB_USE_ICU == STD_ON) || (IOHWAB_MC33972_EXTINT == STD_ON))*/

#if (IOHWAB_USE_GPT == STD_ON)
#if (GPT_AR_RELEASE_MAJOR_VERSION != IOHWAB_GPT_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt.h : Mismatch in Specification Major Version"
#endif

#if (GPT_AR_RELEASE_MINOR_VERSION != IOHWAB_GPT_AR_RELEASE_MINOR_VERSION)
  #error "Gpt.h : Mismatch in Specification Minor Version"
#endif
#endif /* (IOHWAB_USE_GPT == STD_ON) */

#if (IOHWAB_USE_PWM == STD_ON)
#if (PWM_AR_RELEASE_MAJOR_VERSION != IOHWAB_PWM_AR_RELEASE_MAJOR_VERSION)
  #error "Pwm.h : Mismatch in Specification Major Version"
#endif

#if (PWM_AR_RELEASE_MINOR_VERSION != IOHWAB_PWM_AR_RELEASE_MINOR_VERSION)
  #error "Pwm.h : Mismatch in Specification Minor Version"
#endif
#endif /* (IOHWAB_USE_PWM == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
