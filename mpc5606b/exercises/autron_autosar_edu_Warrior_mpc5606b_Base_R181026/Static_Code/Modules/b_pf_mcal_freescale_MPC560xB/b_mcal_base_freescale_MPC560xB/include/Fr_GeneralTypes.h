/**
*   @file    Fr_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup [MODULE_SECTION]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : XPC560XB
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef FR_GENERAL_TYPES_H /* Multiple inclusion avoidance */
#define FR_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REF_1 
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Macro names are defined by AUTOSAR 
* Specification. 
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Macros which can be passed into Fr_ReadCCConfig as parameter Fr_ConfigParamIdx.
* @details        Each macro (index) uniquely identifies a configuration parameter which value can 
*                 be read out of the controllers configuration using Fr_ReadCCConfig.
*
* Covers FR657
* @implements DFR32010
*/

#define FR_CIDX_GDCYCLE                          0U    /* FrIfGdCycle */
#define FR_CIDX_PMICROPERCYCLE                   1U    /* FrPMicroPerCycle */
#define FR_CIDX_PDLISTENTIMEOUT                  2U    /* FrPdListenTimeout */
#define FR_CIDX_GMACROPERCYCLE                   3U    /* FrIfGMacroPerCycle */
#define FR_CIDX_GDMACROTICK                      4U    /* FrIfGdMacrotick */
#define FR_CIDX_GNUMBEROFMINISLOTS               5U    /* FrIfGNumberOfMinislots */
#define FR_CIDX_GNUMBEROFSTATICSLOTS             6U    /* FrIfGNumberOfStaticSlots */
#define FR_CIDX_GDNIT                            7U    /* FrIfGdNit */
#define FR_CIDX_GDSTATICSLOT                     8U    /* FrIfGdStaticSlot */
#define FR_CIDX_GDWAKEUPRXWINDOW                 9U    /* FrIfGdWakeupRxWindow */
#define FR_CIDX_PKEYSLOTID                      10U    /* FrPKeySlotId */
#define FR_CIDX_PLATESTTX                       11U    /* FrPLatestTx */
#define FR_CIDX_POFFSETCORRECTIONOUT            12U    /* FrPOffsetCorrectionOut */ 
#define FR_CIDX_POFFSETCORRECTIONSTART          13U    /* FrPOffsetCorrectionStart */
#define FR_CIDX_PRATECORRECTIONOUT              14U    /* FrPRateCorrectionOut */
#define FR_CIDX_PSECONDKEYSLOTID                15U    /* FrPSecondKeySlotId */
#define FR_CIDX_PDACCEPTEDSTARTUPRANGE          16U    /* FrPdAcceptedStartupRange */
#define FR_CIDX_GCOLDSTARTATTEMPTS              17U    /* FrIfGColdStartAttempts */
#define FR_CIDX_GCYCLECOUNTMAX                  18U    /* FrIfGCycleCountMax */
#define FR_CIDX_GLISTENNOISE                    19U    /* FrIfGListenNoise */
#define FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL    20U    /* FrIfGMaxWithoutClockCorrectFatal */
/* @violates @ref REF_1 */
#define FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE  21U    /* FrIfGMaxWithoutClockCorrectPassive */
#define FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH  22U    /* FrIfGNetworkManagementVectorLength */
#define FR_CIDX_GPAYLOADLENGTHSTATIC            23U    /* FrIfGPayloadLengthStatic */
#define FR_CIDX_GSYNCFRAMEIDCOUNTMAX            24U    /* FrIfGSyncFrameIDCountMax */
#define FR_CIDX_GDACTIONPOINTOFFSET             25U    /* FrIfGdActionPointOffset */
#define FR_CIDX_GDBIT                           26U    /* FrIfGdBit */
#define FR_CIDX_GDCASRXLOWMAX                   27U    /* FrIfGdCasRxLowMax */
#define FR_CIDX_GDDYNAMICSLOTIDLEPHASE          28U    /* FrIfGdDynamicSlotIdlePhase */
#define FR_CIDX_GDMINISLOTACTIONPOINTOFFSET     29U    /* FrIfGdMiniSlotActionPointOffset */
#define FR_CIDX_GDMINISLOT                      30U    /* FrIfGdMinislot */
#define FR_CIDX_GDSAMPLECLOCKPERIOD             31U    /* FrIfGdSampleClockPeriod */
#define FR_CIDX_GDSYMBOLWINDOW                  32U    /* FrIfGdSymbolWindow */
#define FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET 33U    /* FrIfGdSymbolWindowActionPointOffset */
#define FR_CIDX_GDTSSTRANSMITTER                34U    /* FrIfGdTssTransmitter */
#define FR_CIDX_GDWAKEUPRXIDLE                  35U    /* FrIfGdWakeupRxIdle */
#define FR_CIDX_GDWAKEUPRXLOW                   36U    /* FrIfGdWakeupRxLow */
#define FR_CIDX_GDWAKEUPTXACTIVE                37U    /* FrIfGdWakeupTxActive */
#define FR_CIDX_GDWAKEUPTXIDLE                  38U    /* FrIfGdWakeupTxIdle */
#define FR_CIDX_PALLOWPASSIVETOACTIVE           39U    /* FrPAllowPassiveToActive */
#define FR_CIDX_PCHANNELS                       40U    /* FrPChannels */
#define FR_CIDX_PCLUSTERDRIFTDAMPING            41U    /* FrPClusterDriftDamping */
#define FR_CIDX_PDECODINGCORRECTION             42U    /* rPDecodingCorrection */
#define FR_CIDX_PDELAYCOMPENSATIONA             43U    /* FrPDelayCompensationA */
#define FR_CIDX_PDELAYCOMPENSATIONB             44U    /* FrPDelayCompensationB */
#define FR_CIDX_PMACROINITIALOFFSETA            45U    /* FrPMacroInitialOffsetA */
#define FR_CIDX_PMACROINITIALOFFSETB            46U    /* FrPMacroInitialOffsetB */
#define FR_CIDX_PMICROINITIALOFFSETA            47U    /* FrPMicroInitialOffsetA */
#define FR_CIDX_PMICROINITIALOFFSETB            48U    /* FrPMicroInitialOffsetB */
#define FR_CIDX_PPAYLOADLENGTHDYNMAX            49U    /* FrPPayloadLengthDynMax */
#define FR_CIDX_PSAMPLESPERMICROTICK            50U    /* FrPSamplesPerMicrotick */
#define FR_CIDX_PWAKEUPCHANNEL                  51U    /* FrPWakeupChannel */
#define FR_CIDX_PWAKEUPPATTERN                  52U    /* FrPWakeupPattern */
#define FR_CIDX_PDMICROTICK                     53U    /* FrPdMicrotick */
#define FR_CIDX_GDIGNOREAFTERTX                 54U    /* FrIfGdIgnoreAfterTx */
#define FR_CIDX_PALLOWHALTDUETOCLOCK            55U    /* FrPAllowHaltDueToClock */
#define FR_CIDX_PEXTERNALSYNC                   56U    /* FrPExternalSync */
#define FR_CIDX_PFALLBACKINTERNAL               57U    /* FrPFallBackInternal */
#define FR_CIDX_PKEYSLOTONLYENABLED             58U    /* FrPKeySlotOnlyEnabled */
#define FR_CIDX_PKEYSLOTUSEDFORSTARTUP          59U    /* FrPKeySlotUsedForStartup */
#define FR_CIDX_PKEYSLOTUSEDFORSYNC             60U    /* FrPKeySlotUsedForSync */
#define FR_CIDX_PNMVECTOREARLYUPDATE            61U    /* FrPNmVectorEarlyUpdate */
#define FR_CIDX_PTWOKEYSLOTMODE                 62U    /* FrPTwoKeySlotMode */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @enum Fr_TxLPduStatusType
* @brief Transmit resource status is stored to variable of this type
* @implements DFR32005
*/
typedef enum
{
    FR_TRANSMITTED = 0U,  /* No LPdu transmission is pending, LSdu has been transmitted.*/
    FR_NOT_TRANSMITTED    /* An LPdu transmission is pending, LSdu has not been transmitted.*/
} Fr_TxLPduStatusType;

/**
* @enum Fr_RxLPduStatusType
*  @brief Transmit resource status is stored to variable of this type
*  @implements DFR32003
*/
typedef enum
{
    FR_RECEIVED = 0U,                /* LSdu has been received.*/
    FR_NOT_RECEIVED,                 /* LSdu has not been received.*/
    FR_RECEIVED_MORE_DATA_AVAILABLE  /* LSdu has been received. More instances of this LPdu are 
                                        available (FIFO usage ) */
} Fr_RxLPduStatusType;

/**
* @enum Fr_POCStateType
* @details Variables of this type are used to store the POC:state of the controller.
* @implements DFR32007
*/
typedef enum
{
    /* POC:Config - controller can be configured.  */
    FR_POCSTATE_CONFIG = 0U,
    /* POC:Default Config - controller is initialized and needs to be configured.*/
    FR_POCSTATE_DEFAULT_CONFIG,
    /* POC:Halt - controller is stopped.*/
    FR_POCSTATE_HALT,
    /* POC:Normal Active - controller is connected to the FlexRay cluster.*/
    FR_POCSTATE_NORMAL_ACTIVE,
    /* POC:Normal Passive - controller has problems with synchronization to the cluster.*/
    FR_POCSTATE_NORMAL_PASSIVE,
    /* POC:Ready - controller is configured and ready to communicate.*/
    FR_POCSTATE_READY,
    /* POC:Startup - controller is starting up the cluster or integrating to the cluster.*/
    FR_POCSTATE_STARTUP,
    /* POC:Wakeup - controller initiate Wakeup procedure.*/
    FR_POCSTATE_WAKEUP
} Fr_POCStateType;

/**
* @enum Fr_SlotModeType
* @brief This type is used to store the slot mode of the controller
*
* Covers FR506
* @implements DFR32008
*/
typedef enum
{
    FR_SLOTMODE_KEYSLOT = 0U,  /* FlexRay controller is transmitting only in single slot
                                 (key slot) */
    FR_SLOTMODE_ALL_PENDING,  /* After end of the cycle controller will change slot mode to
                                 <b>FR_SLOTMODE_ALL</b>*/
    FR_SLOTMODE_ALL           /* FlexRay controller transmits in all configured slots */
} Fr_SlotModeType;

/**
* @def FR_SLOTMODE_SINGLE
* @brief This macro is used for backward compatibility with Autosar 3.0 definition of Fr_SlotModeType
* Covers FR599
* @implements DFR32011
*/
#define FR_SLOTMODE_SINGLE FR_SLOTMODE_KEYSLOT

/**
* @enum Fr_ErrorModeType
* @brief Variables of this type are used for storage of FlexRay controller error mode.
* @implements DFR32009
*/
typedef enum
{
    FR_ERRORMODE_ACTIVE = 0U,  /* Controller is synchronized to FlexRay cluster.
                                  Synchronization has not been lost more than
                                  gMaxWithoutClockCorrectionPassive cycles.*/
    FR_ERRORMODE_PASSIVE,      /* Controller has lost synchronization for less than
                                  gMaxWithoutClockCorrectionFatal cycles.*/
    FR_ERRORMODE_COMM_HALT    /* FlexRay controller was stoped due to loss of synchronization.*/
} Fr_ErrorModeType;
/**
* @enum Fr_WakeupStatusType
* @details Variable of this type is used to query the FlexRay controller Wakeup status.
* @implements DFR32006
*/
typedef enum
{
    FR_WAKEUP_UNDEFINED = 0U,     /* Unknown state - the controller has not been in POC:Wakeup
                                     state since it was in POC:Default Config.*/
    FR_WAKEUP_RECEIVED_HEADER,    /* Frame header was received during initial listen phase.*/
    FR_WAKEUP_RECEIVED_WUP,       /* Valid WUP was received during initial listen phase.*/
    FR_WAKEUP_COLLISION_HEADER,   /* Collision with frame header during WUP transmission.*/
    FR_WAKEUP_COLLISION_WUP,      /* Collision with another wakeup during WUP transmission.*/
    FR_WAKEUP_COLLISION_UNKNOWN,  /* Unknown collision during WUP transmission.*/
    FR_WAKEUP_TRANSMITTED         /* WUP has been successfully transmitted.*/
} Fr_WakeupStatusType;

/**
*  @enum Fr_StartupStateType
*  @details Variable of this type is used to query the FlexRay controller Startup state.
*  @implements DFR32004
*/
typedef enum
{
    FR_STARTUP_UNDEFINED = 0U,                 /* Unknown state - controller has not been in the
                                                  POC:Startup state since POC:Default Config
                                                  state.*/
    FR_STARTUP_COLDSTART_LISTEN,               /* Controller listens before it initiates CAS
                                                  transmission.*/
    FR_STARTUP_INTEGRATION_COLDSTART_CHECK,    /* Node is synchronizing to leading coldstarter.*/
    FR_STARTUP_COLDSTART_JOIN,                 /* Controller has joined the leading coldstarter
                                                  in transmission of startup frames.*/
    FR_STARTUP_COLDSTART_COLLISION_RESOLUTION, /* Leading coldstarter transmits startup frames.*/
    FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,    /* Leading coldstarter checks if another node
                                                  transmits startup frames.*/
    FR_STARTUP_INTEGRATION_LISTEN,             /* Integrating node (non-coldstarter) listens.*/
    FR_STARTUP_INITIALIZE_SCHEDULE,            /* Schedule is being initialized.*/
    FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,  /* Controller looks for 4 pairs of startup frames
                                                  to integrate into cluster.*/
    FR_STARTUP_COLDSTART_GAP                   /* Pause between two attempts of coldstart.*/
} Fr_StartupStateType;

/**
* @enum Fr_ChannelType
*  @details This type is used to select the channel.
*  @implements DFR32001
*/
typedef enum
{
    FR_CHANNEL_A = 0U,  /* Channel A only */
    FR_CHANNEL_B,       /* Channel B only */
    FR_CHANNEL_AB       /* Both A and B channels */
} Fr_ChannelType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*  @struct Fr_POCStatusType
*  @brief Variables of this type are used to query the flexRay controller status.
*  @implements DFR32002
*/
typedef struct
{
    boolean ColdstartNoise;            /* TRUE means that noise detected on bus during startup.*/
    boolean CHIHaltRequest;            /* TRUE means that there is pending halt request.*/
    boolean Freeze;                    /* TRUE means that internal error causing transition to
                                          the POC:Halt state or FREEZE command occurred.*/
    Fr_SlotModeType SlotMode;          /* Contains FlexRay controller slot mode.*/
    Fr_WakeupStatusType WakeupStatus;  /* Contains FlexRay controller wakeup status.*/
    Fr_ErrorModeType ErrorMode;        /* Contains FlexRay controller error mode.*/
    Fr_StartupStateType StartupState;  /* Contains FlexRay controller startup state.*/
    Fr_POCStateType State;             /* Contains FlexRay controller POC state.*/
} Fr_POCStatusType;

#ifdef __cplusplus
}
#endif

#endif /* FR_GENERAL_TYPES_H */
