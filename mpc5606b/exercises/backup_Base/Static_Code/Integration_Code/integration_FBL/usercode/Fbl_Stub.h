/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Fbl_Stub.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTRON FBL                                            **
**                                                                            **
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
** 1.0.0     29-Apr-2016  Jinseok Park    Initial version                     **
*******************************************************************************/
#ifndef FBL_STUB_H
#define FBL_STUB_H

#include "Std_Types.h"
#include "HwResource.h"

#define USE_RANDOM_SEED_KEY

#if (HWRESOURCE_MCU(HWRESOURCE_MPC5607B))
  #define BOOT_DEVICE_RAMSIZE  (96*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5606B))
  #define BOOT_DEVICE_RAMSIZE  (80*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5605B))
  #define BOOT_DEVICE_RAMSIZE  (64*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5604C))
  #define BOOT_DEVICE_RAMSIZE  (48*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5603C))
  #define BOOT_DEVICE_RAMSIZE  (40*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5604B) || HWRESOURCE_MCU(HWRESOURCE_MPC5602C))
  #define BOOT_DEVICE_RAMSIZE  (32*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5603B))
  #define BOOT_DEVICE_RAMSIZE  (28*1024UL)
#elif(HWRESOURCE_MCU(HWRESOURCE_MPC5602B))
  #define BOOT_DEVICE_RAMSIZE  (24*1024UL)
#else
 #error "Undefined MCU Name"
#endif

/* MPC560xb */
#define STARTUP_COMMAND *((uint32*)(0x40000000UL + BOOT_DEVICE_RAMSIZE - 4UL))
#define PROG_CONDITIONS ((uint32*)(0x40000000UL + BOOT_DEVICE_RAMSIZE - 16UL))


/* Valid values for the Startup Command */
#define RESTART_BOOT_EOL     0xA4420810UL
#define RESTART_BOOT_DIAG    0xA5430911UL
#define RESTART_ASW_MEMCHECK 0xA7863229UL

//extern void bcore_SetStartupCommand(uint32 ul_Value);
extern void bcore_SetStartupCommand(unsigned int ul_Value);
//extern uint32 bcore_GetStartupCommand(void);
extern unsigned int bcore_GetStartupCommand(void);
extern uint32 * bcore_GetProgConditions(void);

#endif
