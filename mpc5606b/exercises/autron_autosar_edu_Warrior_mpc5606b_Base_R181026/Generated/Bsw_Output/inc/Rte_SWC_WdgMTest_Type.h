
/*******************************************************************************
**  FILE-NAME: Rte_SWC_WdgMTest_Type.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR RTE GENERATION TOOL                                  **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 4.4.2                                                   **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\ECUCD_EcucValueCollection.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Com.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Det.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_EcuC.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Os.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Rte.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Adc.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_BswM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Can.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanIf.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanSM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_CanTp.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Com.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_ComM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Crc.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dcm.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dem.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Det.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Dio.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Fee.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_FiM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Fls.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Gpt.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Icu_43.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Mcu.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_MemIf.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_NvM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Os.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_PduR.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Port.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Pwm_43.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Spi.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\BswMd\Bswmd_Wdg_43.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Composition\EcuExtract.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DBImport\Project.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DataTypes\AUTOSAR_DataTypes.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\DataTypes\AUTOSAR_DataTypes_Etc.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_ComM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Dcm.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Dem.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_FiM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_Mode.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_App\App_WdgM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\MODE_PortInterfaces.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_Bsw_BswM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_ComM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_Det.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\System\Swcd_Bsw\Swcd_FiM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_EcuM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_IoHwAb.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_WdgIf.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\bswmd\Bswmd_WdgM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_Dcm.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_Dem.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_EcuM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_Bsw_NvM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_IoHwAb.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Generated\Bsw_Output\swcd\Swcd_WdgM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_swc_ErrorManagement\App_ErrM.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_sys_EcuM_R40\generator\EcuM_PortInterface.arxml
 *      E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Static_Code\Modules\b_autosar_sys_WdgM_R40\generator\Swcd_WdgM_Fixed.arxml

 * GENERATED ON:  This timestamp is removed.
*/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for verification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:begin<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/******************************************************************************/

/*******************************************************************************
**                         MULTIPLE INCLUSION PROTECTION                      **
*******************************************************************************/
#ifndef RTE_SWC_WDGMTEST_TYPE_H
#define RTE_SWC_WDGMTEST_TYPE_H

/*******************************************************************************
**                  Include Section                                           **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "Rte_Type.h"

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 extern "C"
 {
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#ifdef RTE_VENDOR_ID
  #if (RTE_VENDOR_ID != 76)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Vendor Id"
  #endif
#else
  #define RTE_VENDOR_ID 76
#endif

#ifdef RTE_MODULE_ID
  #if (RTE_MODULE_ID != 2)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Module Id"
  #endif
#else
  #define RTE_MODULE_ID 2
#endif

#ifdef RTE_SW_MAJOR_VERSION
  #if (RTE_SW_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Major Version"
  #endif
#else
  #define RTE_SW_MAJOR_VERSION 4
#endif

#ifdef RTE_SW_MINOR_VERSION
  #if (RTE_SW_MINOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Minor Version"
  #endif
#else
  #define RTE_SW_MINOR_VERSION 4
#endif

#ifdef RTE_SW_PATCH_VERSION
  #if (RTE_SW_PATCH_VERSION != 2)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Patch Version"
  #endif
#else
  #define RTE_SW_PATCH_VERSION 2
#endif

#ifdef RTE_AR_RELEASE_MAJOR_VERSION
  #if (RTE_AR_RELEASE_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Major Version"
  #endif
#else
  #define RTE_AR_RELEASE_MAJOR_VERSION 4
#endif

#ifdef RTE_AR_RELEASE_MINOR_VERSION
  #if (RTE_AR_RELEASE_MINOR_VERSION != 0)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Minor Version"
  #endif
#else
  #define RTE_AR_RELEASE_MINOR_VERSION 0
#endif

#ifdef RTE_AR_RELEASE_REVISION_VERSION
  #if (RTE_AR_RELEASE_REVISION_VERSION != 3)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Revision Version"
  #endif
#else
  #define RTE_AR_RELEASE_REVISION_VERSION 3
#endif

/*******************************************************************************
** Type Definitions for Modes                                                 **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
#ifndef RTE_MODETYPE_WdgM_Mode
#define RTE_MODETYPE_WdgM_Mode
typedef uint8 Rte_ModeType_WdgM_Mode;
#endif

/*
  polyspace:end<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
/*******************************************************************************
* Macros Used For Modes                                                       **
*******************************************************************************/
#ifndef RTE_TRANSITION_WdgM_Mode
#define RTE_TRANSITION_WdgM_Mode ((Rte_ModeType_WdgM_Mode)5U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
#define RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED ((Rte_ModeType_WdgM_Mode)4U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
#define RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED ((Rte_ModeType_WdgM_Mode)2U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
#define RTE_MODE_WdgM_Mode_SUPERVISION_FAILED ((Rte_ModeType_WdgM_Mode)1U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_OK
#define RTE_MODE_WdgM_Mode_SUPERVISION_OK ((Rte_ModeType_WdgM_Mode)0U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
#define RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED ((Rte_ModeType_WdgM_Mode)3U)
#endif

/*******************************************************************************
** Type Definitions for Implementation Datatypes                              **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Range Types                                           **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Invalid Value Types                                   **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Enumeration constants                                 **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Number of type definitions for enumeration constants is depends on user configuration */
#ifndef WDGM_SE_INIT
#define WDGM_SE_INIT 300U
#endif /* WDGM_SE_INIT */

#ifndef WDGM_SE_WDGMTEST
#define WDGM_SE_WDGMTEST 400U
#endif /* WDGM_SE_WDGMTEST */

#ifndef WDGM_GLOBAL_STATUS_OK
#define WDGM_GLOBAL_STATUS_OK 0U
#endif /* WDGM_GLOBAL_STATUS_OK */

#ifndef WDGM_GLOBAL_STATUS_FAILED
#define WDGM_GLOBAL_STATUS_FAILED 1U
#endif /* WDGM_GLOBAL_STATUS_FAILED */

#ifndef WDGM_GLOBAL_STATUS_EXPIRED
#define WDGM_GLOBAL_STATUS_EXPIRED 2U
#endif /* WDGM_GLOBAL_STATUS_EXPIRED */

#ifndef WDGM_GLOBAL_STATUS_STOPPED
#define WDGM_GLOBAL_STATUS_STOPPED 3U
#endif /* WDGM_GLOBAL_STATUS_STOPPED */

#ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#define WDGM_GLOBAL_STATUS_DEACTIVATED 4U
#endif /* WDGM_GLOBAL_STATUS_DEACTIVATED */

#ifndef WDGM_WDGMMODE0
#define WDGM_WDGMMODE0 0U
#endif /* WDGM_WDGMMODE0 */

#ifndef WDGM_WDGMMODE1
#define WDGM_WDGMMODE1 1U
#endif /* WDGM_WDGMMODE1 */

#ifndef WDGM_SE_INIT_CP_INIT_AS0
#define WDGM_SE_INIT_CP_INIT_AS0 0U
#endif /* WDGM_SE_INIT_CP_INIT_AS0 */

#ifndef WDGM_SE_INIT_CP_INIT_ILS_0
#define WDGM_SE_INIT_CP_INIT_ILS_0 1U
#endif /* WDGM_SE_INIT_CP_INIT_ILS_0 */

#ifndef WDGM_SE_INIT_CP_INIT_ILS_1
#define WDGM_SE_INIT_CP_INIT_ILS_1 2U
#endif /* WDGM_SE_INIT_CP_INIT_ILS_1 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0 0U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0 1U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1 2U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1 */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Number of type definitions for enumeration constants is depends on user configuration */

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 }
#endif

#endif

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/*
  polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:end<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
