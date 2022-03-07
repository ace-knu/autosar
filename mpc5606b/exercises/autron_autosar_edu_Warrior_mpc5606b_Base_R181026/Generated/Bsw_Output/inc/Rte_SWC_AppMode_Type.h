
/*******************************************************************************
**  FILE-NAME: Rte_SWC_AppMode_Type.h                                                     **
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
#ifndef RTE_SWC_APPMODE_TYPE_H
#define RTE_SWC_APPMODE_TYPE_H

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
#ifndef RTE_MODETYPE_MDG_CanSMBORState
#define RTE_MODETYPE_MDG_CanSMBORState
typedef uint8 Rte_ModeType_MDG_CanSMBORState;
#endif

#ifndef RTE_MODETYPE_MDG_ComMMode
#define RTE_MODETYPE_MDG_ComMMode
typedef uint8 Rte_ModeType_MDG_ComMMode;
#endif

#ifndef RTE_MODETYPE_EcuMode
#define RTE_MODETYPE_EcuMode
typedef EcuM_StateType Rte_ModeType_EcuMode;
#endif

#ifndef RTE_MODETYPE_MDG_InitState
#define RTE_MODETYPE_MDG_InitState
typedef uint8 Rte_ModeType_MDG_InitState;
#endif

#ifndef RTE_MODETYPE_MDG_PduGroup
#define RTE_MODETYPE_MDG_PduGroup
typedef uint8 Rte_ModeType_MDG_PduGroup;
#endif

#ifndef RTE_MODETYPE_MDG_WakeupEvent
#define RTE_MODETYPE_MDG_WakeupEvent
typedef uint8 Rte_ModeType_MDG_WakeupEvent;
#endif

/*
  polyspace:end<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
/*******************************************************************************
* Macros Used For Modes                                                       **
*******************************************************************************/
#ifndef RTE_TRANSITION_MDG_CanSMBORState
#define RTE_TRANSITION_MDG_CanSMBORState ((Rte_ModeType_MDG_CanSMBORState)255U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_COMPLETE
#define RTE_MODE_MDG_CanSMBORState_COMPLETE ((Rte_ModeType_MDG_CanSMBORState)0U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_START
#define RTE_MODE_MDG_CanSMBORState_START ((Rte_ModeType_MDG_CanSMBORState)1U)
#endif

#ifndef RTE_TRANSITION_MDG_ComMMode
#define RTE_TRANSITION_MDG_ComMMode ((Rte_ModeType_MDG_ComMMode)255U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_FULL_COM
#define RTE_MODE_MDG_ComMMode_FULL_COM ((Rte_ModeType_MDG_ComMMode)2U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_NO_COM
#define RTE_MODE_MDG_ComMMode_NO_COM ((Rte_ModeType_MDG_ComMMode)0U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_SILENT_COM
#define RTE_MODE_MDG_ComMMode_SILENT_COM ((Rte_ModeType_MDG_ComMMode)1U)
#endif

#ifndef RTE_TRANSITION_EcuMode
#define RTE_TRANSITION_EcuMode ((Rte_ModeType_EcuMode)0U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_APP_POST_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_APP_POST_RUN ((Rte_ModeType_EcuMode)51U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_APP_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_APP_RUN ((Rte_ModeType_EcuMode)50U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_OFF
#define RTE_MODE_EcuMode_ECUM_STATE_OFF ((Rte_ModeType_EcuMode)128U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_PREP_SHUTDOWN
#define RTE_MODE_EcuMode_ECUM_STATE_PREP_SHUTDOWN ((Rte_ModeType_EcuMode)68U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_RESET
#define RTE_MODE_EcuMode_ECUM_STATE_RESET ((Rte_ModeType_EcuMode)144U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_RUN ((Rte_ModeType_EcuMode)48U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_SHUTDOWN
#define RTE_MODE_EcuMode_ECUM_STATE_SHUTDOWN ((Rte_ModeType_EcuMode)64U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_SLEEP
#define RTE_MODE_EcuMode_ECUM_STATE_SLEEP ((Rte_ModeType_EcuMode)80U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_ONE
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_ONE ((Rte_ModeType_EcuMode)17U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_THREE
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_THREE ((Rte_ModeType_EcuMode)19U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_TWO
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_TWO ((Rte_ModeType_EcuMode)18U)
#endif

#ifndef RTE_TRANSITION_MDG_InitState
#define RTE_TRANSITION_MDG_InitState ((Rte_ModeType_MDG_InitState)255U)
#endif

#ifndef RTE_MODE_MDG_InitState_COMPLETE
#define RTE_MODE_MDG_InitState_COMPLETE ((Rte_ModeType_MDG_InitState)1U)
#endif

#ifndef RTE_MODE_MDG_InitState_START
#define RTE_MODE_MDG_InitState_START ((Rte_ModeType_MDG_InitState)0U)
#endif

#ifndef RTE_TRANSITION_MDG_PduGroup
#define RTE_TRANSITION_MDG_PduGroup ((Rte_ModeType_MDG_PduGroup)255U)
#endif

#ifndef RTE_MODE_MDG_PduGroup_START
#define RTE_MODE_MDG_PduGroup_START ((Rte_ModeType_MDG_PduGroup)1U)
#endif

#ifndef RTE_MODE_MDG_PduGroup_STOP
#define RTE_MODE_MDG_PduGroup_STOP ((Rte_ModeType_MDG_PduGroup)0U)
#endif

#ifndef RTE_TRANSITION_MDG_WakeupEvent
#define RTE_TRANSITION_MDG_WakeupEvent ((Rte_ModeType_MDG_WakeupEvent)255U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_CAN1RX
#define RTE_MODE_MDG_WakeupEvent_CAN1RX ((Rte_ModeType_MDG_WakeupEvent)6U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_CAN1RX_POLL
#define RTE_MODE_MDG_WakeupEvent_CAN1RX_POLL ((Rte_ModeType_MDG_WakeupEvent)7U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_EXTERNAL_WDG
#define RTE_MODE_MDG_WakeupEvent_EXTERNAL_WDG ((Rte_ModeType_MDG_WakeupEvent)4U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_GPT
#define RTE_MODE_MDG_WakeupEvent_GPT ((Rte_ModeType_MDG_WakeupEvent)5U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INITIAL_MODE
#define RTE_MODE_MDG_WakeupEvent_INITIAL_MODE ((Rte_ModeType_MDG_WakeupEvent)32U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INTERNAL_RESET
#define RTE_MODE_MDG_WakeupEvent_INTERNAL_RESET ((Rte_ModeType_MDG_WakeupEvent)2U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INTERNAL_WDG
#define RTE_MODE_MDG_WakeupEvent_INTERNAL_WDG ((Rte_ModeType_MDG_WakeupEvent)3U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_POWER
#define RTE_MODE_MDG_WakeupEvent_POWER ((Rte_ModeType_MDG_WakeupEvent)0U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_RESET
#define RTE_MODE_MDG_WakeupEvent_RESET ((Rte_ModeType_MDG_WakeupEvent)1U)
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
#ifndef COMM_MODE_NO_COM
#define COMM_MODE_NO_COM 0U
#endif /* COMM_MODE_NO_COM */

#ifndef COMM_MODE_FULL_COM
#define COMM_MODE_FULL_COM 2U
#endif /* COMM_MODE_FULL_COM */

#ifndef APP_MODE_ACTIVE
#define APP_MODE_ACTIVE 0U
#endif /* APP_MODE_ACTIVE */

#ifndef APP_MODE_INACTIVE_OFF
#define APP_MODE_INACTIVE_OFF 1U
#endif /* APP_MODE_INACTIVE_OFF */

#ifndef APP_MODE_INACTIVE_RESET
#define APP_MODE_INACTIVE_RESET 2U
#endif /* APP_MODE_INACTIVE_RESET */

#ifndef APP_MODE_INACTIVE_SLEEP
#define APP_MODE_INACTIVE_SLEEP 3U
#endif /* APP_MODE_INACTIVE_SLEEP */

#ifndef MODE_READY
#define MODE_READY 0U
#endif /* MODE_READY */

#ifndef MODE_A
#define MODE_A 1U
#endif /* MODE_A */

#ifndef MODE_B
#define MODE_B 2U
#endif /* MODE_B */

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

