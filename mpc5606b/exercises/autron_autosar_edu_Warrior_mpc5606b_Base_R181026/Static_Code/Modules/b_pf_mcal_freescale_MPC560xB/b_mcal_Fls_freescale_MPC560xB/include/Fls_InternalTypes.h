/**
*   @file    Fls_InternalTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver private types.
*
*   @addtogroup [FLS]
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

#ifndef FLS_INTERNALTYPES_H
#define FLS_INTERNALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Type of job currently executed by Fls_MainFunction.
*
* @implements     DFLS02021
*/

typedef enum
{
    /**
    * @brief erase one or more complete flash sectors
    */
    FLS_JOB_ERASE = 0,    
    /**
    * @brief write one or more complete flash pages 
    */
    FLS_JOB_WRITE,        
    /**
    * @brief read one or more bytes from flash memory 
    */
    FLS_JOB_READ,     
    /**
    * @brief compare data buffer with content of flash memory
    */
    FLS_JOB_COMPARE      
} Fls_JobType;

/**
* @brief          Result of low-level flash operation.
*
* @implements     DFLS03001
*/
typedef enum {
    FLS_LLD_E_OK = 0,                /**< @brief operation succeeded */
    FLS_LLD_E_FAILED,                /**< @brief operation failed due to hardware error */
    FLS_LLD_E_BLOCK_INCONSISTENT,    /**< @brief data buffer doesn't match with content of flash memory */
    FLS_LLD_E_PENDING                /**< @brief operation is pending */
} Fls_LLD_ReturnType;

/**
* @brief          Type of job currently executed by Fls_LLD_MainFunction.
*
* @implements     DFLS03005
*/
typedef enum
{
    /**
    * @brief no job executed by Fls_LLD_MainFunction 
    */    
    FLS_LLD_JOB_NONE = 0, 
    /**
    * @brief erase one flash sector 
    */    
    FLS_LLD_JOB_ERASE, 
    /**
    * @brief complete erase and start an interleaved erase flash sector 
    */
    FLS_LLD_JOB_ERASE_TEMP,
    /**
    * @brief write one or more complete flash pages 
    */
    FLS_LLD_JOB_WRITE, 
    /**
    * @brief erase blank check of flash sector
    */    
    FLS_LLD_JOB_ERASE_BLANK_CHECK 
    
} Fls_LLD_JobType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Logical sector index.
*
* @implements     DFLS02022
*/
typedef uint32 Fls_SectorIndexType;


/** 
    @brief FLASH physical sector description
    @implements DFLS03017
*/
typedef struct
{
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) sectorStartAddressPtr; /**< @brief FLASH physical sector start address */
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) memArrayRegBasePtr; /**< @brief memory array control/configuration register base address */
    uint32 addrSpaceBloSelValue; /**< @brief address space block select value */
    uint32 addrSpaceBloLockValue; /**< @brief address space block lock value */
    uint8 sectorBloSelRegOffset; /**< @brief block select register offset */
    uint8 addrSpaceBloPrimLockRegOffset; /**< @brief address space block primary lock register offset */
    uint8 addrSpaceBloSecoLockRegOffset; /**< @brief address space block secondary lock register offset */
    uint8 platformFlashConfRegOffset; /**< @brief PFC configuration register offset */
    uint32 platformFlashConfInvalValue; /**< @brief PFC configuration register line/page buffer invalidation value */
    boolean interleavedBlo; /**< @brief block that consists of two FLASH physical sectors */
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) memArrayB1RegBasePtr; /**< @brief memory array control/configuration register base address Bank1 */
    uint32 interleavedSize; /**< @brief interleaved size for each Bank */
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) sectorStartB1AddressPtr; /**< @brief FLASH physical sector start address Bank1 */    
} Fls_LLD_SectorInfoType;

/** 
    @brief FLASH array description
    @implements DFLS03018
*/
typedef struct
{
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) memArrayRegBasePtr; /**< @brief memory array control/configuration register base address */
    boolean programSuspPossible; /**< @brief is Program suspend operation possible within FLASH array */
    boolean eraseSuspPossible; /**< @brief is Erase suspend operation possible within FLASH array */
} Fls_LLD_ArrayInfoType;


#ifdef __cplusplus
}
#endif

#endif /* FLS_INTERNALTYPES_H */

/** @}*/
