/**
*   @file    Fls_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver exported types.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Flash_Memory
*   Dependencies         : 
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fls_types_h_REF_1
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 reserved identifier
* This violation is due to the use of "_" which is required as per Autosar
*
*
* @section Fls_types_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
*
* @section Fls_types_h_REF_3
* Violates MISRA 2004 Required Rule 9.3, This violation is due to the support of DATA flash and DFO
* among various derivatives.
*
* @section Fls_types_h_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters. These Mcro  names are decided as per AUTOSAR guideline.
*
*/
#ifndef FLS_TYPES_H
#define FLS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DFLS02069 */
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Reg_eSys_FLASHC.h"
/* @implements     DFLS02068 */
#define FLS_TYPES_VENDOR_ID                    43
#define FLS_TYPES_MODULE_ID                    92
/*
* @violates @ref Fls_types_h_REF_4 Identifiers more than 31 characters.
*/
#define FLS_TYPES_AR_RELEASE_MAJOR_VERSION     4
/*
* @violates @ref Fls_types_h_REF_4 Identifiers more than 31 characters.
*/
#define FLS_TYPES_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Fls_types_h_REF_4 Identifiers more than 31 characters.
*/
#define FLS_TYPES_AR_RELEASE_REVISION_VERSION  3
#define FLS_TYPES_SW_MAJOR_VERSION             1
#define FLS_TYPES_SW_MINOR_VERSION             0
#define FLS_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module doesn't feel responsible (e.g. address does not belong to its current job)
*
*/
#define FLS_UNHANDLED       0U

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible, but wants to repeat the  causing instruction.
*                 Maybe: it still uses information in MCM or ECSM module, but they are outdated
*                (e.g. due to an erroneous DMA transfer in the meantime)
*
*/
#define FLS_HANDLED_RETRY   1U
/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible (usually it just would set some internal flag?)
*                 processing may continue, skipping the causing instruction
*
*/
#define FLS_HANDLED_SKIP    2U  /* module feels responsible (usually it just would set some
                                       internal flag?) processing may continue, skipping the
                                       causing instruction                                        */

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module  feels responsible, but the only reaction is to stop the system
*                 (e.g.: try to shut-down in a quite safe way)
*
*/
#define FLS_HANDLED_STOP    3U

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** 
    @brief Enumeration of physical flash sectors
    @implements DFLS03004
*/ 
typedef enum
{
    FLS_CODE_ARRAY_0_A_L00 = 0,
    FLS_CODE_ARRAY_0_A_L01,
    FLS_CODE_ARRAY_0_A_L02,
    FLS_CODE_ARRAY_0_A_L03,
    FLS_CODE_ARRAY_0_A_L04,
    FLS_CODE_ARRAY_0_A_L05,
    FLS_CODE_ARRAY_0_A_M00,
    FLS_CODE_ARRAY_0_A_M01,
    FLS_CODE_ARRAY_1_B_H00,
    FLS_CODE_ARRAY_1_B_H01,
    FLS_CODE_ARRAY_1_B_H02,
    FLS_CODE_ARRAY_1_B_H03,
    FLS_CODE_ARRAY_2_C_H04,
    FLS_CODE_ARRAY_2_C_H05,
    FLS_CODE_ARRAY_2_C_H06,
    FLS_CODE_ARRAY_2_C_H07,
    FLS_CODE_ARRAY_0_A_SHADOW,
    FLS_CODE_ARRAY_0_A_TEST,
    FLS_DATA_ARRAY_0_L00, /* @violates @ref Fls_types_h_REF_3 To support of DATA flash and DFO */
    FLS_DFO_ARRAY_0_L00 = FLS_DATA_ARRAY_0_L00,
    FLS_DATA_ARRAY_0_L01,
    FLS_DFO_ARRAY_0_L01 = FLS_DATA_ARRAY_0_L01,
    FLS_DATA_ARRAY_0_L02,
    FLS_DFO_ARRAY_0_L02 = FLS_DATA_ARRAY_0_L02,
    FLS_DATA_ARRAY_0_L03,
    FLS_DFO_ARRAY_0_L03 = FLS_DATA_ARRAY_0_L03,
    FLS_DATA_ARRAY_0_TEST,
    FLS_DFO_ARRAY_0_TEST = FLS_DATA_ARRAY_0_TEST
} Fls_LLD_PhysicalSectorType;

/** 
    @brief Enumeration of physical flash sectors page size
*/ 
typedef enum
{
    FLS_PAGE_SIZE_04 = 0x4U,
    FLS_PAGE_SIZE_08 = 0x8U
} Fls_LLD_PageSizeType;

/** 
    @brief Enumeration of physical flash sectors program size
*/ 
typedef enum
{
    FLS_WRITE_WORD = 4U,
    FLS_WRITE_DOUBLE_WORD = 8U
} Fls_LLD_ProgSizeType;

/** 
    @brief Define pointer type of erase access code function
    @implements DFLS31301
*/
typedef P2FUNC( void, FLS_CODE, Fls_LLD_AcErasePtrType )  (P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) regBasePtr, P2FUNC(void, FLS_CODE, CallBack), P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) timerCounterAC);
  
/** 
    @brief Define pointer type of write access code function
    @implements DFLS31302
*/
typedef P2FUNC( void, FLS_CODE, Fls_LLD_AcWritePtrType )  (P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) regBasePtr, P2FUNC(void, FLS_CODE, CallBack), P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) timerCounterAC);




/**
* @brief          Fls Address Type.
* @details        Address offset from the configured flash base address to access a certain flash
*                 memory area.
* @implements     DFLS02001
*/
typedef uint32 Fls_AddressType;

/**
* @brief          Fls Length Type.
* @details        Number of bytes to read/write/erase/compare
* @implements     DFLS02002
*/
typedef uint32 Fls_LengthType;

/**
* @brief          Fls Sector Count Type
* @details        Number of configured sectors
* @implements     DFLS02003
*/
typedef uint32 Fls_SectorCountType;

/**
 * @brief Pointer type of Fls_AC_Callback function
*/
typedef P2FUNC( void, FLS_CODE, Fls_ACCallbackPtrType )  ( void );


/**
* @brief          Fls Job End Notification Pointer Type
* @details        Pointer type of Fls_JobEndNotification function
* @implements     DFLS02004
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobEndNotificationPtrType)(void);

/**
* @brief          Fls Job Error Notification Pointer Type
* @details        Pointer type of Fls_JobErrorNotification function
* @implements     DFLS02005
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobErrorNotificationPtrType)(void);


/**
* @brief          Return value of Fls handler function.
* @details        Fls_DsiHandler and Fls_MciHandler can return the following value:
*                 - FLS_UNHANDLED    Fls driver is not responsable for this situation
*                 - FLS_HANDLED_SKIP Fls driver is responsable for this exception and want to skip this job
*                 .
* @implements     DFLS02087
*/
typedef uint8_least Fls_CompHandlerReturnType;

typedef const uint8 * Fls_InstructionAddressType;
typedef const void * Fls_DataAddressType;

/**
* @brief          Detailed information on the exception.
* @details        The following information will be checked by the driver:
*                 - if there is a pending read, compare,
*                 - data_pt matches address currently accessed by pending flash read or flash compare job,
*                 - if the exception syndrome register indicates DSI or MCI reason,
*                 .
*
* @implements     DFLS02088
*/
typedef struct
{
    Fls_InstructionAddressType instruction_pt; /**< @brief pointer to the instruction that generated the ECC */
    Fls_DataAddressType        data_pt;        /**< @brief data address that caused the ECC error */
    uint32                     syndrome_u32;   /**< @brief details on the type of exception */
} Fls_ExceptionDetailsType;

typedef const Fls_ExceptionDetailsType *ExceptionDetailsPtrType;

/**
* @brief          Detailed information on Ecc Event.
* @details        The following information will be checked by the driver:
*                 - No Ivor exception has been triggered, and
*                 - EER bit set in MCR register indicates ECC Event in pending operation
*                 .
*
* @implements     DFLS02089
*/
typedef struct
{
    boolean     wasEccEvent;     /** @brief give information on Ecc event */
    uint32      eccEventAddr;    /** @brief data address that caused the ECC error */
} Fls_EccDetailsType;

typedef const Fls_EccDetailsType *EccDetailsPtrType;


#ifdef __cplusplus
}
#endif

#endif /* FLS_TYPES_H */

/** @}*/
