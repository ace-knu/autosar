/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: zbbswmap.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR INTEGRATION                                           **
**                                                                            **
**  PURPOSE   : Rom Test API Functionality                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By       Description                               **
********************************************************************************
** 1.0.0     10-Feb-2017   JS Park    RedMine #7473                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef _ZBBSWMAP_H
#define _ZBBSWMAP_H
#include "Platform_types.h"
#include "Fbl_Shared.h"

/* Following information have to be same with zbbswmap.h file in FBL */
#define NUMBER_OF_SW_MODULES  3U

/* Define the Main SW Module (with the Main Security Key) */
#define MAIN_SW_MODULE       E_ASW

/* Define the RAM,ROM Check Module */
#define CODE_CHECK_MODULE     0x02U
#define CHECK_SW_MODULE_NUM      2U

/* When projects do not use Low Power, erase or comment following line */
#define ROMTST_USE_LP

/* Following information have to be same with zbbswmap.h file in FBL */
/* SW module 0: Bootloader */
#define START_BOOT	 0x00000000UL
#define END_BOOT	 0x00007FFFUL
#define BOOT_IDENT	 (const T_SW_MODULE_ID * )0x00000008UL
#define BOOT_CRC	   (const T_BAIFT_CRC    * )0x00000014UL
 
/* SW module 1: RTSW */
#define START_ASW    0x00008000UL
#define END_ASW      0x0017FFFFUL
#define ASW_IDENT    (const T_SW_MODULE_ID * )0x00008010UL /* + 0  */ 
#define ASW_CRC      (const T_BAIFT_CRC     * )0x0000801CUL /* + 12 */
#define ASW_SK       (const uint32        * )0x000080C0UL /* + 176 */

/* SW module 2: RAM_ROM Check */
#define START_SWM2    0x00010000UL
#define END_SWM2      0x000103FFUL 
#define SWM2_IDENT    (const T_SW_MODULE_ID * )0x00010000UL /* + 0  */
#define SWM2_CRC      (const T_BAIFT_CRC     * )0x0001000CUL /* + 12 */
#define SWM2_SK       (const uint32        * )(0U) /* + 176 */
#define SWM2_ACCESS_TYPE     E_READ_ONLY

#endif /* _ZBBSWMAP_H */
