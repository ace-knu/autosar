/**
*   @file    Fee.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Source Code.
*   @details Flash EEPROM emulation driver source code.
*
*   @addtogroup FEE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : none
*   Dependencies         : Fls
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF7_ASR_REL_4_0_REV_0003_20150304
*
*   (c) Copyright 2006-2015 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* This violation is due to use of macros FEE_SERIALIZE and FEE_DESERIALIZE 
* as functions.
*
* @section Fee_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*
* @section Fee_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar 
* requirement MEMMAP003.
*
* @section Fee_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* This violation is not applicable because all data are present in flash memory.
*
* @section Fee_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer. 
* This violation is due to casting the unsigned char pointer to unsigned long 
* pointer and access these addresses for updating contents of that address.
*
* @section Fee_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,  Array indexing shall be the only 
* allowed form of pointer arithmetic.
* This violation is due to the use of pointer arithmatic, which is used for the 
* speed optimization, the indexing of the pointer is taken care and hence the 
* unintended memory location will not be accessed.
*
* @section Fee_c_REF_7
* Violates MISRA 2004 Required Rule 11.5, attempt to cast away const/volatile 
* from a pointer or reference.
* A cast shall not be performed that removes any const or volatile qualification 
* from the type addressed by a pointer.
*
* @section Fee_c_REF_8
* Violates MISRA 2004 Advisory Rule 12.6, boolean expression required for logical operators.
* Booleans operands are not used for logical operators '&&', '||' and '!'
*
* @section Fee_c_REF_9
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_c_REF_10
* Violates MISRA 2004 Required Rule 9.1, All automatic variables shall have been assigned a value
* before being used.
* Automatic value wasn't assigned a value before being used.
*
* @section Fee_c_REF_11
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Fee_c_REF_12
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro
*
* @section Fee_c_REF_13
* Violates MISRA 2004 Required Rule 19.10, unparenthesized macro parameter in definition of macro
*
* @section Fee_c_REF_14
* Violates MISRA 2004 Required Rule 14.10, else-branch must have a comment or action
*
* @section Fee_c_REF_15
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fee.h"
#include "Fee_InternalTypes.h"
#include "Fee_Cbk.h"
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_C                      43U
#define FEE_AR_RELEASE_MAJOR_VERSION_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_C       0
/* @violates @ref Fee_c_REF_9 Identifier clash */
/* @violates @ref Fee_c_REF_11 Identifier exceeds 31 characters */
#define FEE_AR_RELEASE_REVISION_VERSION_C    3
#define FEE_SW_MAJOR_VERSION_C               1
#define FEE_SW_MINOR_VERSION_C               0
#define FEE_SW_PATCH_VERSION_C               1
  
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_VENDOR_ID)
    #error "Fee.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Fee.c and Fee.h are different"
#endif
/* Check if source file and Fee header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
         (FEE_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fee.c and Fee.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (FEE_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fee.c and Det.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/**
* @brief          Serialize scalar parameter into the buffer
* 
* @param[in]      paramVal serialized parameter
* @param[in]      paramType type of serialized parameter
* @param[in,out]  serialPtr pointer to target buffer
* 
* @pre            serialPtr must be valid pointer
* @post           increments the serialPtr by sizeof(paramType)
*
* @violates @ref Fee_c_REF_1 Function-like macro defined
*/
/* @violates @ref Fee_c_REF_12 Disallowed definition for macro */
/* @violates @ref Fee_c_REF_13 unparenthesized macro parameter in definition of macro */
#define FEE_SERIALIZE( paramVal, paramType, serialPtr ) \
    *((paramType*)(serialPtr)) = (paramVal); \
    (serialPtr) += sizeof(paramType);
    
/**
* @brief          Deserialize scalar parameter from the buffer
* 
* @param[in,out]  deserialPtr pointer to source buffer    
* @param[out]     paramVal deserialized parameter
* @param[in]      paramType type of serialized parameter
* 
* @pre            deserialPtr must be valid pointer
* @post           increments the deserialPtr by sizeof(paramType)
*
* @violates @ref Fee_c_REF_1 Function-like macro defined
*/
/* @violates @ref Fee_c_REF_12 Disallowed definition for macro */
/* @violates @ref Fee_c_REF_13 unparenthesized macro parameter in definition of macro */
#define FEE_DESERIALIZE( deserialPtr, paramVal, paramType ) \
    (paramVal) = *((paramType*)(deserialPtr)); \
    (deserialPtr) += sizeof(paramType);
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define FEE_START_SEC_VAR_INIT_8
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/** 
* @brief        Pointer to user data buffer. Used by the read and write Fee jobs
* @implements   DFEE03027
*/
STATIC P2VAR( uint8, FEE_VAR, FEE_APPL_DATA ) Fee_JobDataDestPtr = NULL_PTR;
/**
* @brief        Internal cluster group iterator. Used by the scan and swap jobs 
*               Warning: do not use it outside scan and swap functions 
*                        (because it will be Out of Range)   
* @implements   DFEE03033
*/
STATIC VAR(uint8, FEE_VAR) Fee_JobIntClrGrpIt = (uint8)0;
/**
* @brief        Internal cluster iterator. Used by the scan and swap jobs 
* @implements   DFEE03034
*/
STATIC VAR(uint8, FEE_VAR) Fee_JobIntClrIt = (uint8)0;
/**
* @brief        Data buffer used by all jobs to store immediate data
* @implements   DFEE03041
*/
STATIC VAR(uint8, FEE_VAR) Fee_DataBuffer[FEE_DATA_BUFFER_SIZE] = {(uint8)0};
#define FEE_STOP_SEC_VAR_INIT_8
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

#define FEE_START_SEC_VAR_INIT_16
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/**
* @brief        Fee block index. Used by all Fee jobs
* @implements   DFEE03028
*/
STATIC VAR(uint16, FEE_VAR) Fee_JobBlockIndex = 0U;
/**
* @brief        Internal block iterator. Used by the swap job
* @implements   DFEE03035
*/
STATIC VAR(uint16, FEE_VAR) Fee_JobIntBlockIt = 0U;
#define FEE_STOP_SEC_VAR_INIT_16
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/* @violates @ref Fee_c_REF_11 Identifier exceeds 31 characters */
#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/**
* @brief        Fee block offset. Used by the read Fee job
* @implements   DFEE03029
*/
STATIC VAR(Fls_LengthType, FEE_VAR) Fee_JobBlockOffset = 0UL;
/**
* @brief        Number of bytes to read. Used by the read Fee job
* @implements   DFEE03030
*/              
STATIC VAR(Fls_LengthType, FEE_VAR) Fee_JobBlockLength = 0UL;
/**
* @brief        Internal flash helper address iterator. Used by the scan and 
*               swap jobs
* @implements   DFEE03036
*/
STATIC VAR(Fls_AddressType, FEE_VAR) Fee_JobIntAddrIt = 0UL;
/**
* @brief        Internal address of current block header. Used by the swap job
* @implements   DFEE03037
*/
STATIC VAR(Fls_AddressType, FEE_VAR) Fee_JobIntHdrAddr = 0UL;
/**
* @brief        Internal address of current data block. Used by the swap job.
* @implements   DFEE03038
*/
STATIC VAR(Fls_AddressType, FEE_VAR) Fee_JobIntDataAddr = 0UL;
/** 
* @brief        Internal state of Fee module
* @implements   DFEE03025
*/
STATIC VAR(MemIf_StatusType, FEE_VAR) Fee_ModuleStatus = MEMIF_UNINIT;
/** 
* @brief        Result of last Fee module job
* @implements   DFEE03026
*/
STATIC VAR(MemIf_JobResultType, FEE_VAR) Fee_JobResult = MEMIF_JOB_OK;
/**
* @brief        Currently executed job (including internal one)
* @implements   DFEE03031
*/
STATIC VAR(Fee_JobType, FEE_VAR) Fee_Job = FEE_JOB_DONE;
/**
* @brief        Fee job which started internal management job(s) such as swap...
* @implements   DFEE03032
*/
STATIC VAR(Fee_JobType, FEE_VAR) Fee_JobIntOriginalJob = FEE_JOB_DONE;
/* @violates @ref Fee_c_REF_11 Identifier exceeds 31 characters */
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/* @violates @ref Fee_c_REF_11 Identifier exceeds 31 characters */
#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"
/**
* @brief        Run-time information of all configured Fee blocks. Contains
*               status, and data information. Used by all jobs
* @implements   DFEE03039
*/
STATIC VAR(Fee_BlockInfoType, FEE_VAR) Fee_BlockInfo[FEE_NUMBER_OF_BLOCKS];
/**
* @brief        Run-time information of all configured cluster groups
* @implements   DFEE03040
*/
STATIC VAR(Fee_ClusterGroupInfoType, FEE_VAR) Fee_ClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS];
/* @violates @ref Fee_c_REF_11 Identifier exceeds 31 characters */
#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

STATIC FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr( 
    CONST( uint16, AUTOMATIC ) BlockNumber, 
    CONST( uint16, AUTOMATIC ) Length,
    CONST( Fls_AddressType, AUTOMATIC) TargetAddress,    
    CONST( boolean, AUTOMATIC ) ImmediateBlock, 
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) BlockHdrPtr );

STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck(
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetPtr,
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetEndPtr );
    
STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag(
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) TargetPtr,
    VAR( uint8, AUTOMATIC ) FlagPattern, 
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) FlagValue );
    
STATIC FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr(
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) BlockNumber,
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) Length,
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) TargetAddress,
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) ImmediateBlock,
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) BlockHdrPtr );
    
STATIC FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr(
    CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) ClrID,
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) StartAddress,
    CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) ClusteSize,
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) ClrHdrPtr );
    
STATIC FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr(
    CONST( uint32, AUTOMATIC ) ClrID,
    CONST( Fls_AddressType, AUTOMATIC) StartAddress,
    CONST( Fls_LengthType, AUTOMATIC) ClusteSize,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) ClrHdrPtr );
    
STATIC FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex(
    CONST( uint16, AUTOMATIC ) BlockNumber );
    
STATIC FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize( 
    VAR( uint16, AUTOMATIC ) BlockSize );
    
STATIC FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer(
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) SourcePtr,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) TargetPtr,    
    CONST( uint16, AUTOMATIC ) Length );
    
STATIC FUNC( void, FEE_CODE ) Fee_SerializeFlag(
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) TargetPtr,
    CONST( uint8, AUTOMATIC ) FlagPattern );
    
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse(
    CONST( boolean, AUTOMATIC ) bufferValid );
    
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse( 
   CONST( boolean, AUTOMATIC) bufferValid );
    
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead( 
   CONST( boolean, AUTOMATIC) bufferValid );
    
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite( 
    CONST( boolean, AUTOMATIC ) bufferValid );
    
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void );

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

/** 
* @brief        Serialize Fee block parameters into a write buffer
* 
* @param[in]    BlockNumber      Fee block number
* @param[in]    Length           Size of Fee block in bytes
* @param[in]    TargetAddress    Logical address of Fee block in Fls adress 
*                                space
* @param[in]    ImmediateBlock   Type of Fee block. Set to TRUE for immediate 
*                                block
* @param[out]   BlockHdrPtr      Pointer to serialization buffer
*     
* @pre          BlockHdrPtr must be valid pointer
*     
* @implements   DFEE03079
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr( 
    CONST( uint16, AUTOMATIC ) BlockNumber, 
    CONST( uint16, AUTOMATIC ) Length,
    CONST( Fls_AddressType, AUTOMATIC) TargetAddress,    
    CONST( boolean, AUTOMATIC ) ImmediateBlock, 
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) BlockHdrPtr )
{
    VAR( uint32, AUTOMATIC ) checkSum = 0UL;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) targetEndPtr = NULL_PTR;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    targetEndPtr = BlockHdrPtr + FEE_BLOCK_OVERHEAD;
        
    /* Calculate the block header checksum */
    checkSum = (uint32) BlockNumber + (uint32) Length + TargetAddress;

    /* Use MSB of the checksum for the immediate block flag so 
        the checksum is 31-bit */    
    if( ImmediateBlock )
    {
        checkSum += 1U;
        checkSum |= 0x80000000U;
    }
    else
    {
        checkSum &= 0x7fffffffU;
    }
    
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( BlockNumber, uint16, BlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( Length, uint16, BlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( TargetAddress, Fls_AddressType, BlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( checkSum, uint32, BlockHdrPtr )
    
    /* Fill rest of the header with the erase pattern */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( ; BlockHdrPtr != targetEndPtr; BlockHdrPtr++ )
    { 
        *BlockHdrPtr = FEE_ERASED_VALUE;
    }
}

/** 
* @brief          Check whether specified data buffer contains only 
*                 the FEE_ERASED_VALUE value
* 
* @param[in]      targetPtr      pointer to start of the checked buffer
* @param[in]      targetEndPtr   pointer to end + 1 of the checked buffer
* 
* @return         Std_ReturnType
* @retval         E_OK           The buffer contains only erased value
* @retval         E_NOT_OK       The buffer doesn't contain only erased value
* 
* @pre            targetPtr and targetEndPtr pointers must be valid
* 
* @implements     DFEE03043
*/
STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck(
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetPtr,
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetEndPtr )
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( ; targetPtr != targetEndPtr; targetPtr++ )
    { 
        if( FEE_ERASED_VALUE == *targetPtr )
        {
            /* Pattern match */
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    
    return( RetVal );
}

/** 
* @brief        Deserialize the valid or invalid flag from a read buffer
* 
* @param[in]    TargetPtr        Pointer to the read buffer
* @param[in]    FlagPattern      FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* @param[out]   FlagValue        TRUE if flag of above type is set
* 
* @return       Std_ReturnType
* @retval       E_OK             The flag is set or cleared and rest of the read buffer 
*                               (FEE_VIRTUAL_PAGE_SIZE - 1) contains FEE_ERASED_VALUE
* @retval       E_NOT_OK         Buffer doesn't contain valid flag data. It's garbled...
* 
* @pre          TargetPtr and FlagValue pointers must be valid
* 
* @implements   DFEE03047
*/
STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag(
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) TargetPtr,
    VAR( uint8, AUTOMATIC ) FlagPattern, 
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) FlagValue )
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;

    if(( *TargetPtr == FlagPattern ) || ( FEE_ERASED_VALUE == *TargetPtr ))
    {
        /* The bytePattern can be either present or not */
        if( *TargetPtr == FlagPattern )
        {
            *FlagValue = (boolean) TRUE;
        }
        else
        {
            *FlagValue = (boolean) FALSE;
        }
        
        /* Check rest of the FEE_VIRTUAL_PAGE_SIZE */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        RetVal = Fee_BlankCheck(TargetPtr + 1, TargetPtr + FEE_VIRTUAL_PAGE_SIZE );
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return( RetVal );
}

/** 
* @brief        Deserialize Fee block header parameters from read buffer
* 
* @param[out]   BlockNumber              Fee block number
* @param[out]   Length                   Size of Fee block in bytes
* @param[out]   Length                   Size of Fee block in bytes    
* @param[out]   TargetAddress            Logical address of Fee block in Fls adress space
* @param[out]   ImmediateBlock           Type of Fee block. Set to TRUE for immediate block
* @param[in]    BlockHdrPtr              Pointer to read buffer
* 
* @return       Fee_BlockStatusType
* @retval       FEE_BLOCK_VALID          Fee block is valid
* @retval       FEE_BLOCK_INVALID        Fee block is invalid (has been invalidated)
* @retval       FEE_BLOCK_INCONSISTENT   Fee block is inconsistent, it may contain corrupted data...
* @retval       FEE_BLOCK_HEADER_INVALID Fee block header is invalid (garbled)
* @retval       FEE_BLOCK_HEADER_BLANK   Fee block header is filled with FEE_ERASED_VALUE
* 
* @pre          BlockHdrPtr              pointer must be valid
* 
* @implements   DFEE03045
*/
STATIC FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr(
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) BlockNumber,
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) Length,
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) TargetAddress,
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) ImmediateBlock,
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) BlockHdrPtr )
{
    VAR( Fee_BlockStatusType, AUTOMATIC ) RetVal = FEE_BLOCK_HEADER_INVALID;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    if( Fee_BlankCheck( BlockHdrPtr, BlockHdrPtr + FEE_BLOCK_OVERHEAD ) == (Std_ReturnType)E_OK )
    {
        RetVal = FEE_BLOCK_HEADER_BLANK;    
    }
    else
    {
        VAR( uint32, AUTOMATIC ) readCheckSum;
        VAR( uint32, AUTOMATIC ) calcCheckSum;
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetEndPtr; 
        VAR( boolean, AUTOMATIC ) flagValid;
        VAR( boolean, AUTOMATIC ) flagInvalid;        

        /* Check 1st part of the header */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        targetEndPtr = ( BlockHdrPtr + FEE_BLOCK_OVERHEAD ) - ( 2U * FEE_VIRTUAL_PAGE_SIZE );
        
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
        FEE_DESERIALIZE( BlockHdrPtr, *BlockNumber, uint16 )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
        FEE_DESERIALIZE( BlockHdrPtr, *Length, uint16 )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
        FEE_DESERIALIZE( BlockHdrPtr, *TargetAddress, Fls_AddressType )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
        FEE_DESERIALIZE( BlockHdrPtr, readCheckSum, uint32 )

        /* Use MSB of checksum for immediate block flag so 
            the checksum is 31-bit long */            
        calcCheckSum = *Length + *TargetAddress + *BlockNumber;

        if( 0U == (readCheckSum & 0x80000000U)  )
        {
            *ImmediateBlock = (boolean) FALSE;
        }
        else
        {
            *ImmediateBlock = (boolean) TRUE;
            calcCheckSum += 1U;
        }

        /* Ignore MSB since it's used for ImmediateBlock flag */
        if( (readCheckSum & 0x7fffffffU) != (calcCheckSum & 0x7fffffffU) )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }    
        else if( (Std_ReturnType)E_OK != Fee_BlankCheck( BlockHdrPtr, targetEndPtr )  )
        {
            /* FEE_BLOCK_HEADER_INVALID */    
        }
        else if( (Std_ReturnType)E_OK != \
        /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
        Fee_DeserializeFlag( targetEndPtr, FEE_VALIDATED_VALUE, &flagValid )  )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        else if( (Std_ReturnType)E_OK != Fee_DeserializeFlag( targetEndPtr + FEE_VIRTUAL_PAGE_SIZE, 
        /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
                                         FEE_INVALIDATED_VALUE, &flagInvalid )  )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        else
        {
            /* Block header is valid */
            /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
            if(( !flagValid ) && ( !flagInvalid ))
            {
                RetVal = FEE_BLOCK_INCONSISTENT;
            }
            /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */           
            else if(( flagValid ) && ( !flagInvalid ))
            {
                RetVal = FEE_BLOCK_VALID;
            }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */           
            else if(( flagValid ) && ( flagInvalid ))
            {
                RetVal = FEE_BLOCK_INVALIDATED;
            }
#endif
            else
            {
                RetVal = FEE_BLOCK_INVALID;
            }
        }
    }
    
    return( RetVal );
}

/** 
* @brief        Deserialize Fee cluster header parameters from read buffer
* 
* @param[out]   ClrID                      32-bit cluster ID
* @param[out]   StartAddress               Logical address of Fee cluster in Fls address space
* @param[out]   ClusteSize                 Size of Fee cluster in bytes
* @param[in]    ClrHdrPtr                  Pointer to read buffer
* 
* @return       Fee_ClusterStatusType
* @retval       FEE_CLUSTER_VALID          Fee cluster is valid
* @retval       FEE_CLUSTER_INVALID        Fee cluster has been invalidated
* @retval       FEE_CLUSTER_INCONSISTENT   Fee cluster is inconsistent, it may 
*                                          contain corrupted data
* @retval       FEE_CLUSTER_HEADER_INVALID Fee cluster header is invalid (garbled)
* 
* @pre          ClrHdrPtr pointer must be valid
* 
* @implements   DFEE03046
*/
STATIC FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr(
    CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) ClrID,
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) StartAddress,
    CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) ClusteSize,
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) ClrHdrPtr )
{
    VAR( Fee_ClusterStatusType, AUTOMATIC ) RetVal = FEE_CLUSTER_HEADER_INVALID;
    VAR( uint32, AUTOMATIC ) checkSum = 0UL;
    VAR( boolean, AUTOMATIC ) flagValid = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) flagInvalid = (boolean)FALSE;
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) targetEndPtr = NULL_PTR; 
    
    /* Check 1st part of the header */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    targetEndPtr = ( ClrHdrPtr + FEE_CLUSTER_OVERHEAD ) - ( 2U * FEE_VIRTUAL_PAGE_SIZE );
    
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
    FEE_DESERIALIZE( ClrHdrPtr, *ClrID, uint32 )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
    FEE_DESERIALIZE( ClrHdrPtr, *StartAddress, Fls_AddressType )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
    FEE_DESERIALIZE( ClrHdrPtr, *ClusteSize, Fls_LengthType )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer or reference. */
    FEE_DESERIALIZE( ClrHdrPtr, checkSum, uint32 )

    if(( *ClrID + *StartAddress + *ClusteSize ) != checkSum )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if( (Std_ReturnType)E_OK != Fee_DeserializeFlag( targetEndPtr, FEE_VALIDATED_VALUE,
    /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
                                                         &flagValid ) )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    else if( (Std_ReturnType)E_OK != Fee_DeserializeFlag( targetEndPtr + FEE_VIRTUAL_PAGE_SIZE, 
    /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
                                      FEE_INVALIDATED_VALUE, &flagInvalid ) )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }    
    else
    {
        /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
        if(( !flagValid ) && ( !flagInvalid ))
        {
            RetVal = FEE_CLUSTER_INCONSISTENT;
        }
        /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
        if(( flagValid ) && ( !flagInvalid ))
        {
            RetVal = FEE_CLUSTER_VALID;
        }
        else
        {
            RetVal = FEE_CLUSTER_INVALID;
        }
    }

    return( RetVal );
}

/** 
* @brief        Serialize        Fee cluster header parameters to write buffer
* 
* @param[in]    ClrID            32-bit cluster ID
* @param[in]    StartAddress     Logical address of Fee cluster in Fls address space
* @param[in]    ClusteSize       Size of Fee cluster in bytes
* @param[out]   ClrHdrPtr        Pointer to write buffer
* 
* @pre          ClrHdrPtr        pointer must be valid
* 
* @implements   DFEE03080
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr(
    CONST( uint32, AUTOMATIC ) ClrID,
    CONST( Fls_AddressType, AUTOMATIC) StartAddress,
    CONST( Fls_LengthType, AUTOMATIC) ClusteSize,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) ClrHdrPtr )
{
    VAR( uint32, AUTOMATIC ) checkSum = 0UL;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) targetEndPtr = NULL_PTR; 
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    targetEndPtr = ClrHdrPtr + FEE_CLUSTER_OVERHEAD;
    
    /* Calculate the cluster header checksum */
    checkSum = ClrID + StartAddress + ClusteSize;
     
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */     
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( ClrID, uint32, ClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( StartAddress, Fls_AddressType, ClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( ClusteSize, Fls_LengthType, ClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( checkSum, uint32, ClrHdrPtr )
    
    /* Fill rest of the header with the erase pattern */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( ; ClrHdrPtr != targetEndPtr; ClrHdrPtr++ )
    { 
        *ClrHdrPtr = FEE_ERASED_VALUE;
    }    
}

/** 
* @brief        Searches ordered list of Fee blocks and returns index of block 
*               with matching BlockNumber
* 
* @param[in]    BlockNumber              Fee block number (FeeBlockNumber)
* 
* @return       uint16
* @retval       Fee block index
* @retval       0xffff if BlockNumber is invalid 
* 
* @implements   DFEE03048
*/
STATIC FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex(
    CONST( uint16, AUTOMATIC ) BlockNumber )
{
    VAR( sint32, AUTOMATIC ) low = 0L;
    VAR( sint32, AUTOMATIC ) high = (sint32)FEE_NUMBER_OF_BLOCKS - 1;
    VAR( uint16, AUTOMATIC ) RetVal = 0xffffU;

    while( low <= high )
    { 
        VAR( sint32, AUTOMATIC ) middle = low + (( high - low ) / 2);
        if( BlockNumber < Fee_BlockConfig[middle].blockNumber )
        {
            high = middle - 1;
        }
        else if( BlockNumber > Fee_BlockConfig[middle].blockNumber )
        {
            low = middle + 1;
        }
        else
        {
            RetVal = (uint16)middle;
            break;
        }
    }
    
    return( RetVal );
}

/** 
* @brief        Adjusts passed size so it's integer multiple of pre-configured +
*               FEE_VIRTUAL_PAGE_SIZE
* 
* @param[in]    blockSize        Fee block size (FeeBlockSize)
* 
* @return       uint16
* @retval       Adjusted         Fee block size to integer multiple    of FEE_VIRTUAL_PAGE_SIZE
* 
* @implements   DFEE03042
*/
STATIC FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize( 
    VAR( uint16, AUTOMATIC ) BlockSize )
{
    /* Check whether the block size is integer multiple 
        of FEE_VIRTUAL_PAGE_SIZE */
    if( 0U == ( BlockSize % FEE_VIRTUAL_PAGE_SIZE ) )
    {
        /* block size is integer multiple of FEE_VIRTUAL_PAGE_SIZE */
    }
    else
    {
        BlockSize = (( BlockSize / FEE_VIRTUAL_PAGE_SIZE ) + 1U ) 
            * FEE_VIRTUAL_PAGE_SIZE;
    }
    
    return( (uint16)BlockSize );
}

/** 
* @brief        Copy data from user to internal write buffer and fills
*               rest of the write buffer with FEE_ERASED_VALUE
* 
* @param[in]    sourcePtr        Pointer to user data buffer
* @param[out]   targetPtr        Pointer to internal write buffer
* @param[in]    length           Number of bytes to copy 
* 
* @pre          sourcePtr and targetPtr must be valid pointers
* @pre          length must be <= FEE_VIRTUAL_PAGE_SIZE
* 
* @implements   DFEE03044
*/
STATIC FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer(
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) SourcePtr,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) TargetPtr,    
    CONST( uint16, AUTOMATIC ) Length )
{
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) targetEndPtr = TargetPtr + Length;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pageEndPtr = TargetPtr + FEE_VIRTUAL_PAGE_SIZE;
    
    /* Copy data to page buffer */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( ; TargetPtr != targetEndPtr; TargetPtr++ )
    { 
        *TargetPtr = *SourcePtr;
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        SourcePtr++;
    }
    
    /* Fill rest of the page buffer with FEE_ERASED_VALUE */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( ; TargetPtr != pageEndPtr; TargetPtr++ )
    { 
        *TargetPtr = FEE_ERASED_VALUE;
    }    
}

/** 
* @brief        Serialize validation or invalidation flag to write buffer
* 
* @param[out]   targetPtr        Pointer to write buffer
* @param[in]    FlagPattern      FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* 
* @pre          TargetPtr        must be valid pointer
* 
* @implements   DFEE03081
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeFlag(
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) TargetPtr,
    CONST( uint8, AUTOMATIC ) FlagPattern )
{
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) targetEndPtr = TargetPtr + FEE_VIRTUAL_PAGE_SIZE;

    *TargetPtr = FlagPattern;
        
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    for( TargetPtr++ ; TargetPtr != targetEndPtr; TargetPtr++ )
    { 
        *TargetPtr = FEE_ERASED_VALUE;
    }
}

/** 
* @brief        Validate current Fee cluster in current Fee cluster group by 
*               writing FEE_VALIDATED_VALUE into flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write 
*                                        job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current cluster group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
* 
* @implements   DFEE03065
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void )
{
    /* @implements         DFEE38001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    /* @implements         DFEE38002 */
    VAR( Fls_AddressType, AUTOMATIC ) startAddr = 0UL;

    /* Get start address of swap cluster */
    /* @implements         DFEE38003 */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    startAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    
    /* Serialize validation pattern to write buffer */
    /* @implements         DFEE38004 */
    Fee_SerializeFlag( Fee_DataBuffer, FEE_VALIDATED_VALUE );
    
    /* Write validation pattern to flash */
    /* @implements         DFEE38005 */
    if( (Std_ReturnType)E_OK == Fls_Write(( startAddr + FEE_CLUSTER_OVERHEAD ) - \
                   ( 2U * FEE_VIRTUAL_PAGE_SIZE ), Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) )
    {
        /* Fls write job has been accepted */
        /* @implements         DFEE38006 */
        RetVal = MEMIF_JOB_PENDING;    
    }
    else
    {
        /* Fls write job hasn't been accepted */
        /* @implements         DFEE38007 */
        RetVal = MEMIF_JOB_FAILED;
    }
    
    /* Schedule subsequent Fee job */
    /* @implements         DFEE38008 */
    Fee_Job = FEE_JOB_INT_SWAP_CLR_VLD_DONE;
    
    return( RetVal );
}

/** 
* @brief        Copy next block from source to target cluster
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the write job
* 
* @pre          Fee_JobIntBlockIt        must contain index of currently swaped 
*                                        Fee block
* @pre          Fee_JobBlockIndex        must contain index of Fee block which 
*                                        caused the swap
* @pre          Fee_JobIntClrGrpIt       must contain index of current cluster 
*                                        group
* @pre          Fee_JobIntHdrAddr        must contain valid address of Fee block 
*                                        header in target cluster
*               
* @post         Fee_JobIntHdrAddr is advanced on to next Fee block
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ, FEE_JOB_INT_SWAP_BLOCK, 
* or            FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*     
* @implements   DFEE03061
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void )
{
    /* @implements         DFEE37001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    
    /* Find first valid or inconsistent block in same cluster group */
    /* @implements         DFEE37002 */
    for( ; Fee_JobIntBlockIt < FEE_NUMBER_OF_BLOCKS; Fee_JobIntBlockIt++ )
    {
        /* @implements         DFEE37003 */
        if(
            ( Fee_BlockConfig[Fee_JobIntBlockIt].clrGrp == Fee_JobIntClrGrpIt ) &&
            ( ( FEE_BLOCK_VALID ==  Fee_BlockInfo[Fee_JobIntBlockIt].blockStatus ) ||
            ( FEE_BLOCK_INCONSISTENT == Fee_BlockInfo[Fee_JobIntBlockIt].blockStatus )))
        {
            break;
        }
        else
        {
            /* No match. Try next one... */
        }
    }

    /* @implements         DFEE37004 */
    if( FEE_NUMBER_OF_BLOCKS == Fee_JobIntBlockIt )
    {
        /* No more matching blocks. Validate the cluster */
        /* @implements         DFEE37005 */
        RetVal = Fee_JobIntSwapClrVld();
    }
    else
    {
        /* @implements         DFEE37006 */
        VAR( Fls_AddressType, AUTOMATIC ) dataAddr = 0UL;
        /* @implements         DFEE37007 */
        VAR( uint16, AUTOMATIC ) blockSize = 0U;
        /* @implements         DFEE37008 */
        VAR( uint16, AUTOMATIC ) alignedBlockSize = 0U;
    
        /* Size of swapped block */
        /* @implements         DFEE37009 */
        blockSize = Fee_BlockConfig[Fee_JobIntBlockIt].blockSize;
        /* Align Fee block size to the virtual page boundary */
        /* @implements         DFEE37011 */
        alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );
    
        /* Calculate data address */
        /* @implements         DFEE37012 */
        dataAddr = Fee_JobIntDataAddr - alignedBlockSize;

        /* Update the block address info */
        /* @implements         DFEE37013 */
        Fee_JobIntDataAddr = dataAddr;

        /* Initialize the data transfer iterator */
        /* @implements         DFEE37014 */
        Fee_JobIntAddrIt = dataAddr;
            
        /* Serialize block header to the write buffer */
        /* @implements         DFEE37016 */
        Fee_SerializeBlockHdr( Fee_BlockConfig[Fee_JobIntBlockIt].blockNumber, 
            blockSize, dataAddr, 
            Fee_BlockConfig[Fee_JobIntBlockIt].immediateData, Fee_DataBuffer );
        
        /* @implements         DFEE37017 */
        if( FEE_BLOCK_VALID == Fee_BlockInfo[Fee_JobIntBlockIt].blockStatus )
        {
            /* Read block data */
            /* @implements         DFEE37018 */
            Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
        }
        else
        {
            /* Nothing to read. Move on to next block */
            /* @implements         DFEE37019 */
            Fee_JobIntBlockIt++;
            /* @implements         DFEE37020 */
            Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
        }
        
        /* Write header to flash */
        /* @implements         DFEE37021 */
        if( (Std_ReturnType)E_OK != Fls_Write( Fee_JobIntHdrAddr, Fee_DataBuffer, \
                   FEE_BLOCK_OVERHEAD - ( 2U * FEE_VIRTUAL_PAGE_SIZE )) )
        {
            /* Fls write job hasn't been accepted */
            /* @implements         DFEE37022 */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls write job has been accepted */
            /* @implements         DFEE37023 */
            RetVal = MEMIF_JOB_PENDING;    
        }
        
        /* Move on to next block header */
        /* @implements         DFEE37024 */
        Fee_JobIntHdrAddr += FEE_BLOCK_OVERHEAD;
    }
    
    return( RetVal );
}

/** 
* @brief        Format current Fee cluster in current Fee cluster group by 
*               writing cluster header into flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write 
*                                        job
* 
* @pre          Fee_JobIntClrGrpIt       must contain index of current cluster 
*                                        group
* @pre          Fee_JobIntClrIt          must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
* 
* @implements   DFEE03064
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void )
{
    /* @implements         DFEE36001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    /* @implements         DFEE36002 */
    VAR( Fls_AddressType, AUTOMATIC ) startAddr = 0UL;
    /* @implements         DFEE36003 */
    VAR( Fls_LengthType, AUTOMATIC ) length = 0UL;
    /* @implements         DFEE36004 */
    VAR( uint32, AUTOMATIC ) actClrID = 0UL;
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @implements         DFEE36005 */
    startAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @implements         DFEE36006 */
    length = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].length;
    /* @implements         DFEE36007 */
    actClrID = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID;
    
    /* Build cluster header with new actClrID + 1 */
    /* @implements         DFEE36008 */
    Fee_SerializeClusterHdr( actClrID + 1U, startAddr, length, 
        Fee_DataBuffer );
    
    /* Write the cluster header to flash */
    /* @implements         DFEE36009 */
    if( (Std_ReturnType)E_OK == Fls_Write( startAddr, Fee_DataBuffer, 
                 FEE_CLUSTER_OVERHEAD - ( 2U * FEE_VIRTUAL_PAGE_SIZE )) )
    {
        /* Fls read job has been accepted */
        /* @implements         DFEE36010 */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        /* @implements         DFEE36011 */
        RetVal = MEMIF_JOB_FAILED;
    }    
    
    /* Schedule cluster format done job */
    /* @implements         DFEE36012 */
    Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
    
    return( RetVal );
}

/** 
* @brief        Erase current Fee cluster in current Fee cluster group by erasing flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
* 
* @pre          Fee_JobIntClrGrpIt       must contain index of current cluster group
* @pre          Fee_JobIntClrIt          must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_FMT subsequent job
* 
* @implements   DFEE03063
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void )
{
    /* @implements         DFEE35001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    /* @implements         DFEE35002 */
    VAR( Fls_AddressType, AUTOMATIC ) startAddr = 0UL;
    /* @implements         DFEE35003 */    
    VAR( Fls_LengthType, AUTOMATIC ) length = 0UL;
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @implements         DFEE35004 */
    startAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    /* @implements         DFEE35005 */
    length = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].length;
    
    /* Erase cluster */
    /* @implements         DFEE35006 */
    if( (Std_ReturnType)E_OK == Fls_Erase( startAddr, length ) )
    {
        /* Fls read job has been accepted */
        /* @implements         DFEE35007 */
        RetVal = MEMIF_JOB_PENDING;    
    } 
    else
    {
        /* Fls read job hasn't been accepted */
        /* @implements         DFEE35008 */
        RetVal = MEMIF_JOB_FAILED;        
    }

    /* Schedule cluster format job */
    /* @implements         DFEE35009 */
    Fee_Job = FEE_JOB_INT_SWAP_CLR_FMT;
    
    return( RetVal );
}

/** 
* @brief        Initialize the cluster swap internal operation on 
*               current cluster group
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
* 
* @pre          Fee_JobIntClrGrpIt       must contain index of current cluster group
* @pre          Fee_Job                  must contain type of Fee job which caused the cluster swap
* 
* @post         Fee module status is set to MEMIF_BUSY_INTERNAL
* @post         Fee_Job is stored in Fee_JobIntOriginalJob so it can be rescheduled 
*               once the swap operation is finished
* @post         Fee internal block iterator Fee_JobIntBlockIt is set to zero
* @post         Fee internal cluster iterator Fee_JobIntClrIt is set to 
*               the target cluster
* @post         Fee_JobIntHdrAddr and Fee_JobIntDataAddr addresses are initialized to 
*               point to the target cluster
* @post         Schedule erase of the target cluster
* 
* @implements   DFEE03060
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void )
{
    /* @implements         DFEE34001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    
    /* Store type of original job so Fee can re-schedule
        this job once the swap is complete */
    /* @implements         DFEE34002 */
    Fee_JobIntOriginalJob = Fee_Job;
    
    /* Reset the block iterator */
    /* @implements         DFEE34003 */
    Fee_JobIntBlockIt = 0U;
    
    /* Get cluster index the block belongs to */
    /* @implements         DFEE34004 */
    Fee_JobIntClrIt = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClr;
    
    /* Calculate index of cluster to swap to */
    /* @implements         DFEE34005 */
    Fee_JobIntClrIt++;
    
    if( Fee_JobIntClrIt == Fee_ClrGrps[Fee_JobIntClrGrpIt].clrCount )
    {
        /* Cluster roll over */
        /* @implements         DFEE34006 */
        Fee_JobIntClrIt = 0U;
    }
    else
    {
    /* @violates @ref Fee_c_REF_14 else-branch must have a comment or action*/
    }

    /* Calculate header and data address iterators */
    /* @implements         DFEE34007 */
    Fee_JobIntHdrAddr =
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    
    /* @implements         DFEE34008 */
    Fee_JobIntDataAddr = Fee_JobIntHdrAddr + 
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
           allowed form of pointer arithmetic. */
        Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].length;

    /* Move on to the first block header */
    /* @implements         DFEE34009 */
    Fee_JobIntHdrAddr += FEE_CLUSTER_OVERHEAD;
        
    /* Erase the swap cluster */
    /* @implements         DFEE34010 */
    RetVal = Fee_JobIntSwapClrErase();

    return( RetVal );
}

/** 
* @brief        Read the Fee block header into internal buffer
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the read job
* 
* @pre          Fee_JobIntAddrIt must contain valid logical address of 
*               Fee block header to read
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
* 
* @implements   DFEE03053
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;

    /* Read the block header */
    if( (Std_ReturnType)E_OK != Fls_Read( Fee_JobIntAddrIt, Fee_DataBuffer, FEE_BLOCK_OVERHEAD ) )
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    
    Fee_Job    = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;

    return( RetVal );
}

/** 
* @brief        Erase first Fee cluster in current cluster group
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase 
*                                        job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster 
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT subsequent job
* 
* @implements   DFEE03055
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) startAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) length = 0UL;    
    
    /* Get address and size of first cluster in the current cluster group */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    startAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    length = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].length;
    
    if( (Std_ReturnType)E_OK == Fls_Erase( startAddr, length ) )
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;    
    } 
    else
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;        
    }

    /* Schedule cluster format job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT;
    
    return( RetVal );
}

/** 
* @brief        Scan active cluster of current cluster group or erase and format 
*               first cluster if an active cluster can't be found
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @post         Initialize the Fee_JobIntAddrIt iterator to address of 
*               the first Fee block header to scan
* @post         Initialize the hdrAddrIt and dataAddrIt iterators to addresses of
*               the first Fee block header and data block
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*     
* @implements   DFEE03054
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;

    if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_JobIntClrGrpIt )
    {
        /* Nor more cluster groups to scan */
        Fee_Job = FEE_JOB_DONE;
    }
    else
    {
        if( 0U == Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID )
        {
            /* No active cluster found in current group so erase and format
                the first one... */
            RetVal = Fee_JobIntScanClrErase();
        }
        else
        {
            /* Active cluster found */
            VAR( uint8, AUTOMATIC ) clrIndex = (uint8)0;
            VAR( Fls_AddressType , AUTOMATIC ) clrStartAddr = 0UL;
            VAR( Fls_LengthType , AUTOMATIC ) clrLength = 0UL;
            
            /* Get index of active cluster */
            clrIndex = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClr;
            
            /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
               allowed form of pointer arithmetic. */
            clrStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[clrIndex].startAddr;

            /* Calculate logical address of first block header in active cluster */
            Fee_JobIntAddrIt = FEE_CLUSTER_OVERHEAD + clrStartAddr;
        
            /* Initialize the block header pointer */
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt = Fee_JobIntAddrIt;
            
            /* Initialize the block data pointer */
            /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
               allowed form of pointer arithmetic. */
            clrLength = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[clrIndex].length;
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = clrStartAddr + clrLength;
    
            /* Active cluster found so read the first block header */
            RetVal = Fee_JobIntScanBlockHdrRead();
        }
    }    
    
    return( RetVal );
}

/** 
* @brief        Format first Fee cluster in current Fee cluster group by writing
*               cluster header into flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase 
*                                        job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster 
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT_DONE subsequent job
* 
* @implements   DFEE03056
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void ) 
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) startAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) length = 0UL;
    
    /* Get address and size of first cluster in the current cluster group */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    startAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    length = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].length;
    
    /* Build cluster header with clusterID = 1 */
    Fee_SerializeClusterHdr( 1U, startAddr, length, Fee_DataBuffer );
    
    /* Make the cluster valid right away as it's empty anyway... */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    Fee_SerializeFlag(( Fee_DataBuffer + FEE_CLUSTER_OVERHEAD ) - (2U * FEE_VIRTUAL_PAGE_SIZE), FEE_VALIDATED_VALUE );
    
    /* Write the cluster header to flash */
    if( (Std_ReturnType)E_OK == Fls_Write( startAddr, Fee_DataBuffer, 
                                FEE_CLUSTER_OVERHEAD - FEE_VIRTUAL_PAGE_SIZE ) )
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;    
    }
    else
    {
        /* Fls write job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }    

    /* Schedule cluster format done job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT_DONE;
    
    return( RetVal );
}

/** 
* @brief        Finalize format of first Fee cluster in current Fee cluster group
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or 
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase 
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster 
*               group
* @post         Assign index (actClr) and ID (actClrID) of active cluster in 
*               current cluster group
* @post         Initialize the hdrAddrIt and dataAddrIt iterators to addresses 
*               of
*               the first Fee block header and data block
* @post         Advance the Fee_JobIntClrGrpIt iterator to next cluster group
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT, 
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*     
* @implements   DFEE03057
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void ) 
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType , AUTOMATIC ) clrStartAddr = 0UL;
    VAR( Fls_LengthType , AUTOMATIC ) clrLength = 0UL;
    
    /* Assign Index and ID of active cluster */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClr = 0U;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID = 1U;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic. */
    clrStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
       allowed form of pointer arithmetic */
    clrLength = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[0].length;
    
    /* Initialize the block header pointer */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt = 
        clrStartAddr + FEE_CLUSTER_OVERHEAD;
    
    /* Initialize the block data pointer */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = clrStartAddr + clrLength;
    
    /* Move on to next cluster group */
    Fee_JobIntClrGrpIt++;
    
    /* Scan next cluster group if any */
    RetVal = Fee_JobIntScanClr();
    
    return( RetVal );
}

/** 
* @brief        Parse Fee block header
* 
* @param[in]    bufferValid FALSE if previous Fls read job has failed
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or 
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase  
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
* 
* @pre          Fee_JobIntClrGrpIt       must contain index of current Fee 
*                                        cluster group
* 
* @post         Initialize internal recovery swap operation in case of bogus 
*               Fee block header or failure of previous read job (perhaps ECC failure..)
* @post         Advance the Fee_JobIntClrGrpIt iterator to next cluster group in 
*               case of blank Fee block header (end of header list)
* @post         Update the blockStatus, dataAddr, and invalidAddr block 
*               information and the hdrAddrIt and dataAddrIt iterators in case of valid 
*               Fee block header
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job in case 
*               of valid Fee block header
*               
*     
* @implements   DFEE03052
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse(
    CONST( boolean, AUTOMATIC ) bufferValid )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
    VAR( Fee_BlockStatusType, AUTOMATIC ) blockStatus;
    VAR( uint16, AUTOMATIC ) blockNumber = 0U;
    VAR( uint16, AUTOMATIC ) blockSize = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) dataAddr = 0UL;
    VAR( boolean, AUTOMATIC ) immediateData = (boolean)FALSE;
    /**
    * @brief        Internal variable used to trigger a cluster swap. Used by the swap job.
    * @implements   DFEE03082
    */
    STATIC VAR( boolean, AUTOMATIC) Fee_SwapToBePerformed = (boolean)FALSE;

    /* Deserialize block header from read buffer */
    blockStatus = Fee_DeserializeBlockHdr( 
        /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
        &blockNumber, &blockSize, &dataAddr, &immediateData, Fee_DataBuffer);

    /* Clear swap variable except for last header */
    if( FEE_BLOCK_HEADER_BLANK  != blockStatus )
    {
        Fee_SwapToBePerformed = (boolean)FALSE;
    }

    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    if(( FEE_BLOCK_HEADER_INVALID  == blockStatus ) || ( !bufferValid ))
    {
        /* Invalidate the block index so Fee won't skip
            the Fee_JobBlockIndex block */
        Fee_JobBlockIndex = 0xffffU;
        
        /* Move on to next block header */
        Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;
        
        /* Update the block header pointer */
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt = Fee_JobIntAddrIt;
    
        /* Update the block data pointer, starting from hdr pointer plus to 2U * FEE_BLOCK_OVERHEAD */
        Fee_SwapToBePerformed = (boolean)TRUE; /* Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = Fee_JobIntAddrIt + (2U * FEE_BLOCK_OVERHEAD ); */
        
        /* Read next header */
        RetVal = Fee_JobIntScanBlockHdrRead();

    } 
    else if( FEE_BLOCK_HEADER_BLANK  == blockStatus )
    {
        /* If SwapToBePerformed is set, it means that last header is corrupted and 
           ONLY now the dataAddrIt variable will be updated to cause swap. */
        if(Fee_SwapToBePerformed == (boolean)TRUE)
        {
           Fee_SwapToBePerformed = (boolean)FALSE;
           Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = Fee_JobIntAddrIt + (2U * FEE_BLOCK_OVERHEAD );
        }
        
        /* End of header list so move on to next cluster group */
        Fee_JobIntClrGrpIt++;
        
        RetVal = Fee_JobIntScanClr();
    }
    else
    {
        /* Look for found block in the block configuration */
        VAR( uint32, AUTOMATIC ) blockIndex = Fee_GetBlockIndex( blockNumber );
        
        if( 0xffffU != blockIndex )
        {
            VAR( uint16, AUTOMATIC ) alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );
            /* Check whether found block belongs to current cluster group,
                and its size and type match the configuration and
                data address is consistent */
            if(( Fee_BlockConfig[blockIndex].clrGrp == Fee_JobIntClrGrpIt ) &&
                ( Fee_BlockConfig[blockIndex].blockSize == blockSize ) &&
                ( Fee_BlockConfig[blockIndex].immediateData == immediateData ) &&
                ( dataAddr <= (Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt-alignedBlockSize) ) &&
                ( dataAddr >= (Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt + (2U * FEE_BLOCK_OVERHEAD)) )
              )
            {
                /* Update block run-time information */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                /* Update block run-time information when:
                  - new valid block is found
                  - block was invalidated 
                     - block contains immediate data
                     (basically just ignore INCONSISTENT non-immediate blocks)
                 */
                if ((FEE_BLOCK_INCONSISTENT != blockStatus) ||
                    (immediateData == (boolean)TRUE))
                {
                     /* Mark invalidated blocks as invalid */
                    if (FEE_BLOCK_INVALIDATED == blockStatus)
                    {
                         blockStatus = FEE_BLOCK_INVALID;
                    }
#endif
                    Fee_BlockInfo[blockIndex].blockStatus = blockStatus;
                     /* Update the block data pointer */
                    Fee_BlockInfo[blockIndex].dataAddr = dataAddr;
                    Fee_BlockInfo[blockIndex].invalidAddr = ( Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD ) \
                                                                  - FEE_VIRTUAL_PAGE_SIZE;
                       
                    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = dataAddr;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                }
                else
                {
                    /* header is valid but data is corrupted, in this case it is important to update 
                       dataAddrIt to avoid corrupted space, cluster swap is not needed */
                    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = dataAddr;
                }
#endif
            }
            else
            {
                /* Block header doesn't match Fee config... next write cluster swap occurs */
                Fee_SwapToBePerformed = (boolean)TRUE;
            }
        }
        else
        {
            /* Invalid block number (removed from Fee config...) next write cluster swap occurs */
            Fee_SwapToBePerformed = (boolean)TRUE;
        }

        /* Move on to next block header */
        Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;
        
        /* Update the block header pointer */
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt = Fee_JobIntAddrIt;
            
        /* Read next header */
        RetVal = Fee_JobIntScanBlockHdrRead();
    }
    
    return( RetVal );
}

/** 
* @brief        Read Fee cluster header
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_JobIntClrIt must contain index of current Fee cluster
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
* 
* @implements   DFEE03059
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) readAddress = 0UL;
    
    /* Get address of current cluster */
   /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
      allowed form of pointer arithmetic */   
    readAddress = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    
    if( (Std_ReturnType)E_OK != Fls_Read( readAddress, Fee_DataBuffer, FEE_CLUSTER_OVERHEAD ) )
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
        
    /* Schedule cluster scan job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;
    
    return( RetVal );        
}

/** 
* @brief        Initialize the cluster scan job
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* 
* @post         Reset the Fee_JobIntClrGrpIt and Fee_JobIntClrIt iterators
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
* 
* @implements   DFEE03051
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;

    /* Reset iterators to first cluster of first cluster group */
    Fee_JobIntClrGrpIt = 0U;
    Fee_JobIntClrIt = 0U;

    /* Schedule reading of first cluster header */
    RetVal = Fee_JobIntScanClrHdrRead();
    
    return( RetVal );
}

/** 
* @brief        Parse Fee cluster header
* 
* @param[in]    bufferValid FALSE if previous Fls read job has failed
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Update the Fee_JobIntClrIt and/or Fee_JobIntClrGrpIt iterators to move
*               into next cluster and/or cluster group and read next cluster header if
*               there is any
* @post         Scan first active cluster if Fee is done with reading the cluster headers
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT, 
*               FEE_JOB_INT_SCAN_CLR_PARSE, FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent jobs
*     
* @implements   DFEE03058
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse( 
   CONST( boolean, AUTOMATIC) bufferValid ) 
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( Fee_ClusterStatusType, AUTOMATIC ) clrStatus = FEE_CLUSTER_VALID;
    VAR( uint32, AUTOMATIC ) clrID = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) clrStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) clrSize = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) cfgStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) cfgClrSize = 0UL;    
    
    /* Get configured cluster start address and size */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the 
       only allowed form of pointer arithmetic */
    cfgStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the 
       only allowed form of pointer arithmetic */
    cfgClrSize = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].length;

    /* Deserialize cluster parameters from the read buffer */
    /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
    clrStatus = Fee_DeserializeClusterHdr( &clrID, &clrStartAddr, &clrSize, Fee_DataBuffer );

    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    if(( bufferValid ) && ( FEE_CLUSTER_VALID == clrStatus ) && 
        ( clrStartAddr == cfgStartAddr ) && ( clrSize == cfgClrSize ) && 
        ( clrID > Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID ))
    {
        /* Found valid and active cluster */
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClr = Fee_JobIntClrIt;
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID = clrID;
    }
    else
    {
        /* Invalid, inconsistent, or cluster with low ID */
    }
    
    /* Move on to next cluster */
    Fee_JobIntClrIt++;
    
    if( Fee_JobIntClrIt == Fee_ClrGrps[Fee_JobIntClrGrpIt].clrCount )
    {
        /* Move on to next cluster group */
        Fee_JobIntClrGrpIt++;
        Fee_JobIntClrIt = 0U;
    }
    else
    {
        /* next cluster in current cluster group */
    }

    if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_JobIntClrGrpIt )
    {
        Fee_JobIntClrGrpIt = 0U;
        
        /* Done reading all cluster headers. Now scan active clusters */
        RetVal = Fee_JobIntScanClr();
    }
    else
    {
        /* Read next cluster header */
        RetVal = Fee_JobIntScanClrHdrRead();
    }
    
    return( RetVal );        
}

/** 
* @brief        Read Fee block
*               
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* @retval       MEMIF_BLOCK_INVALID      Requested Fee block is invalid
* @retval       MEMIF_BLOCK_INCONSISTENT Requested Fee block is inconsistent
* 
* @pre          Fee_JobBlockIndex must contain index of requested Fee block
* @pre          Fee_JobBlockOffset must contain offset in requested Fee block
* @pre          Fee_JobBlockLength must contain number of bytes to read from requested Fee block   
* @post         Schedule the FEE_JOB_DONE    subsequent job
* 
* @implements   DFEE03071
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void )
{
    /* @implements         DFEE39001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
    /* @implements         DFEE39002 */
    VAR( Fee_BlockStatusType, AUTOMATIC ) blockStatus = FEE_BLOCK_VALID;
    /* @implements         DFEE39003 */
    VAR( Fls_AddressType, AUTOMATIC ) blockAddress = 0UL;

    /* @implements         DFEE39004 */
    blockStatus = Fee_BlockInfo[Fee_JobBlockIndex].blockStatus;
    /* @implements         DFEE39005 */
    blockAddress = Fee_BlockInfo[Fee_JobBlockIndex].dataAddr;
    
    /* @implements         DFEE39006 */
    if( FEE_BLOCK_VALID == blockStatus )
    {
        /* @implements         DFEE39007 */
        if( (Std_ReturnType)E_OK != Fls_Read( blockAddress + Fee_JobBlockOffset, Fee_JobDataDestPtr,
                                              Fee_JobBlockLength ) )
        {
            /* Fls read job hasn't been accepted */
            /* @implements         DFEE39008 */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            /* @implements         DFEE39009 */
            RetVal = MEMIF_JOB_PENDING;
        }
    }
    /* @implements         DFEE39010 */
    else if( FEE_BLOCK_INVALID == blockStatus )
    {
        /* @implements         DFEE39011 */
        RetVal = MEMIF_BLOCK_INVALID;
    }
    /* @implements         DFEE39012 */
    else if( FEE_BLOCK_INCONSISTENT == blockStatus )
    {
        /* @implements         DFEE39013 */
        if ( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
        {
            /* @implements         DFEE39014 */
            RetVal = MEMIF_BLOCK_INVALID;
        }
        else
        {
            /* @implements         DFEE39015 */
            RetVal = MEMIF_BLOCK_INCONSISTENT;
        }
    }
    else
    {
        /* Something is wrong... MEMIF_JOB_FAILED */
    }

    /* There is no consecutive job to schedule */
    /* @implements         DFEE39016 */
    Fee_Job = FEE_JOB_DONE;
    
    return( RetVal );
}

/** 
* @brief        Validate Fee block
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* 
* @pre          Fee_JobIntHdrAddr must contain address of Fee block header to 
*               validate
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
* 
* @implements   DFEE03062
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void ) 
{ 
    /* @implements         DFEE33001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
     
    /* Serialize validation pattern to buffer */
    /* @implements         DFEE33002 */
    Fee_SerializeFlag( Fee_DataBuffer, FEE_VALIDATED_VALUE );
    
    /* Write header to flash */
    /* @implements         DFEE33003 */
    if( (Std_ReturnType)E_OK != Fls_Write( Fee_JobIntHdrAddr - ( 2U * FEE_VIRTUAL_PAGE_SIZE ), 
                                           Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) )
    {
        /* Fls read job hasn't been accepted */
        /* @implements         DFEE33004 */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        /* @implements         DFEE33005 */
        RetVal = MEMIF_JOB_PENDING;
    }
    
    /* Finalize the write operation */
    /* @implements         DFEE33006 */
    Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
    
    return( RetVal );
}

/** 
* @brief        Read data from source cluster to internal Fee buffer
* 
* @param[in]    bufferValid FALSE if previous Fls read job has failed
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* 
* @pre          Fee_JobIntBlockIt must contain index of currently swaped 
*               Fee block
* @pre          Fee_JobIntDataAddr must contain start address of Fee data block
*               in the target cluster
* @pre          Fee_JobIntAddrIt must contain current address of Fee data block
*               in the target cluster
* @post         Move on to next block Fee block if bufferValid == FALSE
* @post         Validates the Fee block if there is no more data to read
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_WRITE subsequent job
* 
* @implements   DFEE03067
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead( 
   CONST( boolean, AUTOMATIC) bufferValid )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
    VAR( Fls_AddressType, AUTOMATIC ) readAddr = 0UL;
    VAR( uint16, AUTOMATIC ) alignedBlockSize = 0U;    
    VAR( uint16, AUTOMATIC ) blockSize = 0U;

    /* Get size of swaped block */
    /* @implements         DFEE32001 */
    blockSize = Fee_BlockConfig[Fee_JobIntBlockIt].blockSize;
    
    /* Get size of swaped block aligned to virtual page boundary */
    /* @implements         DFEE32002 */
    alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );
    
    /* Calculate remaining number of bytes to read */
    /* @implements         DFEE32003 */
    Fee_JobBlockLength = ( Fee_JobIntDataAddr + alignedBlockSize ) - Fee_JobIntAddrIt;
    
    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    /* @implements         DFEE32004 */
    if( !bufferValid )
    {
        /* There was error while reading the source cluster.
            Change the block status to FEE_BLOCK_INCONSISTENT, 
            leave the block (in flash) INCONSITENT and move on to next block */
        /* @implements         DFEE32005 */
        Fee_BlockInfo[Fee_JobIntBlockIt].blockStatus = FEE_BLOCK_INCONSISTENT;
        
        /* @implements         DFEE32006 */
        Fee_JobIntBlockIt++;

        /* @implements         DFEE32007 */
        RetVal = Fee_JobIntSwapBlock();
    }
    /* @implements         DFEE32008 */
    else if( 0U == Fee_JobBlockLength )
    {
        /* No more bytes to copy. Validate the block and 
            move on to next block... */
        /* @implements         DFEE32009 */
        Fee_JobIntBlockIt++;
        
        /* @implements         DFEE32010 */
        RetVal = Fee_JobIntSwapBlockVld();
    }
    else
    {
        /* @implements         DFEE32011 */
        if( Fee_JobBlockLength > FEE_DATA_BUFFER_SIZE )
        {
            /* @implements         DFEE32012 */
            Fee_JobBlockLength = FEE_DATA_BUFFER_SIZE;
        }
        else
        {
            /* Block data fits into the buffer */
        }
    
        /* Calculate source address */
        /* @implements         DFEE32013 */
        readAddr = ( Fee_BlockInfo[Fee_JobIntBlockIt].dataAddr + 
            Fee_JobIntAddrIt ) - Fee_JobIntDataAddr;
        
        /* Read the block data */
        /* @implements         DFEE32014 */
        if( (Std_ReturnType)E_OK != Fls_Read( readAddr, Fee_DataBuffer, Fee_JobBlockLength ) )
        {
            /* Fls read job hasn't been accepted */
            /* @implements         DFEE32015 */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            /* @implements         DFEE32016 */
            RetVal = MEMIF_JOB_PENDING;
        }    

        /* @implements         DFEE32017 */
        Fee_Job = FEE_JOB_INT_SWAP_DATA_WRITE;
    }

    return( RetVal );
}

/** 
* @brief        Write data from internal Fee buffer to target cluster
* 
* @param[in]    bufferValid FALSE if previous Fls read job has failed
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING         Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED          Underlying Fls didn't accept write job
* 
* @pre          Fee_JobBlockLength        must contain size of data block being 
*                                         transfered(up to FEE_DATA_BUFFER_SIZE)
* @pre          Fee_JobIntAddrIt          must contain current address of Fee 
*                                         data block in the target cluster        
* @post         Update the Fee_JobIntAddrIt data iterator for next data
*               transfer if any
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ subsequent job
* 
* @implements   DFEE03068
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite( 
    CONST( boolean, AUTOMATIC ) bufferValid )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;

    /* @implements         DFEE31001 */
    if( bufferValid ) 
    {    
        /* @implements         DFEE31002 */
        if( (Std_ReturnType)E_OK == Fls_Write( Fee_JobIntAddrIt, Fee_DataBuffer, \
                                                           Fee_JobBlockLength ))
        {
            /* Fls read job has been accepted */
            /* @implements         DFEE31003 */
            RetVal = MEMIF_JOB_PENDING;    
        }
        else
        {
            /* Fls write job hasn't been accepted */
            /* @implements         DFEE31004 */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* @implements         DFEE31005 */
        Fee_JobIntAddrIt += Fee_JobBlockLength;
        
        /* @implements         DFEE31006 */
        Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
    }
    else
    {
        /* @implements         DFEE31007 */
        RetVal = Fee_JobIntSwapDataRead( (boolean) FALSE );
    }
    
    return( RetVal );
}

/** 
* @brief        Finalize cluster validation
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
* 
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster 
*               group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Update the dataAddr and invalidAddr Fee_BlockConfig variables of
*               all affected (swaped) Fee blocks
* @post         Update actClr, actClrID, hdrAddrIt, dataAddrIt Fee_ClrGrpInfo 
*               variables of current cluster group
* @post         Change Fee module status from MEMIF_BUSYINTERNAL to MEMIF_BUSY
* @post         Re-schedule the Fee_JobIntOriginalJob subsequent job
* 
* @implements   DFEE03066
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) blockIt = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) hdrAddrIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) dataAddrIt = 0UL;
    VAR( uint16, AUTOMATIC ) blockSize;        
    VAR( uint16, AUTOMATIC ) alignedBlockSize;  
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the 
       only allowed form of pointer arithmetic */
    /* @implements         DFEE30001 */
    hdrAddrIt = Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the 
       only allowed form of pointer arithmetic */
    /* @implements         DFEE30002 */
    dataAddrIt = hdrAddrIt + Fee_ClrGrps[Fee_JobIntClrGrpIt].clrPtr[Fee_JobIntClrIt].length;
    
    /* Move on to the first block header */
    /* @implements         DFEE30003 */
    hdrAddrIt += FEE_CLUSTER_OVERHEAD;
    
    /* Sync block info */
    /* @implements         DFEE30004 */
    for( blockIt = 0U; blockIt < FEE_NUMBER_OF_BLOCKS; blockIt++ )
    {
        /* @implements         DFEE30005 */
        if(
            ( Fee_BlockConfig[blockIt].clrGrp == Fee_JobIntClrGrpIt ) &&
            (( FEE_BLOCK_VALID == Fee_BlockInfo[blockIt].blockStatus ) ||
            ( FEE_BLOCK_INCONSISTENT == Fee_BlockInfo[blockIt].blockStatus )))
        {    
            /* Sync invalidAddr */
            /* @implements         DFEE30006 */
            Fee_BlockInfo[blockIt].invalidAddr = ( hdrAddrIt + 
                FEE_BLOCK_OVERHEAD ) - FEE_VIRTUAL_PAGE_SIZE;
            
            /* @implements         DFEE30007 */
            hdrAddrIt += FEE_BLOCK_OVERHEAD;
            /* Size of swapped block */
            /* @implements         DFEE30009 */
            blockSize = Fee_BlockConfig[blockIt].blockSize;
                
            /* Align Fee block size to the virtual page boundary */
            /* @implements         DFEE30010 */
            alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );
            
            /* Update the block address info */
            /* @implements         DFEE30011 */
            dataAddrIt -= alignedBlockSize;

            /* @implements         DFEE30012 */
            Fee_BlockInfo[blockIt].dataAddr = dataAddrIt;
        }
        else
        {
            /* No matching block */
        }
    }
    
    /* Switch to the new cluster */
    /* @implements         DFEE30014 */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClr = Fee_JobIntClrIt;
    /* @implements         DFEE30015 */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].actClrID++;
    /* @implements         DFEE30016 */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].hdrAddrIt = hdrAddrIt;
    /* @implements         DFEE30017 */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].dataAddrIt = dataAddrIt;

    /* Internal job has finished so transition
        from MEMIF_BUSYINTERNAL to MEMIF_BUSY */
    /* @implements         DFEE30020 */
    Fee_ModuleStatus = MEMIF_BUSY;

    /* And now cross fingers and re-schedule original job ... */
    /* @implements         DFEE30021 */
    Fee_Job = Fee_JobIntOriginalJob;
    
    /* @implements         DFEE30022 */
    RetVal = Fee_JobSchedule();
    
    return( RetVal );
}

/** 
* @brief        Write Fee block header to flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @post         Update the dataAddr and invalidAddr Fee_BlockConfig variables of
*               written Fee block
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
*     
* @implements   DFEE03076
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
    VAR( uint16, AUTOMATIC ) blockSize = 0U;
    VAR( uint16, AUTOMATIC ) alignedBlockSize =0U;
    VAR( Fls_LengthType, AUTOMATIC ) availClrSpace = 0UL;
    VAR( uint8, AUTOMATIC ) clrGrpIndex = (uint8)0;
    
    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE29001 */
    clrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;

    /* Calculate available space in active cluster */
    /* @implements         DFEE29002 */
    availClrSpace = Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt - 
        Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt;
    
    /* Get size of Fee block */
    /* @implements         DFEE29003 */
    blockSize = Fee_BlockConfig[Fee_JobBlockIndex].blockSize;
    
    /* Align Fee block size to the virtual page boundary */
    /* @implements         DFEE29004 */
    alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );

    /* Mark the block as invalid until the block header is written 
    Fee_BlockInfo[Fee_JobBlockIndex].blockStatus = FEE_BLOCK_INVALID;*/
    
    /* One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
       between header block space and data block space */
    /* @implements         DFEE29005 */
    if(((uint32) alignedBlockSize + (2U * FEE_BLOCK_OVERHEAD )) > availClrSpace )
    {
        /* The block won't fit into current cluster. Init swap sequence... */
        
        /* Get cluster group index the block belongs to */
        /* @implements         DFEE29006 */
        Fee_JobIntClrGrpIt = clrGrpIndex;
        
        /* @implements         DFEE29007 */
        RetVal = Fee_JobIntSwap();
    } 
    else
    {
        VAR( Fls_AddressType, AUTOMATIC ) dataAddr;
        VAR( Fls_AddressType, AUTOMATIC ) hdrAddr;

        /* Calculate data and header addresses */
        /* @implements         DFEE29008 */
        dataAddr = Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt - alignedBlockSize;
        /* @implements         DFEE29009 */
        hdrAddr = Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt;

        /* Serialize block header to the write buffer */
        /* @implements         DFEE29010 */
        Fee_SerializeBlockHdr(  Fee_BlockConfig[Fee_JobBlockIndex].blockNumber,
                                blockSize, dataAddr, 
                                Fee_BlockConfig[Fee_JobBlockIndex].immediateData, 
                                Fee_DataBuffer );
        

        /* Write header to flash */
        /* @implements         DFEE29011 */
        if( (Std_ReturnType)E_OK != Fls_Write( hdrAddr, Fee_DataBuffer, FEE_BLOCK_OVERHEAD - \
                                     ( 2U * FEE_VIRTUAL_PAGE_SIZE )) )
        {
            /* Fls read job hasn't been accepted */
            /* @implements         DFEE29012 */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            /* @implements         DFEE29013 */
            RetVal = MEMIF_JOB_PENDING;    
        }
    }

    return( RetVal );
}

/** 
* @brief        Write Fee block data to flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* 
* @pre          Fee_JobBlockIndex        must contain index of Fee block to  
*                                        write to
* @pre          Fee_JobDataDestPtr       must contain valid pointer to user 
*                                        buffer
* @post         Update hdrAddrIt, dataAddrIt Fee_ClrGrpInfo variables of current 
*               cluster group if immediateData == FALSE only
* @post         Changes blockStatus to FEE_BLOCK_INCONSISTENT
* @post         Schedule either FEE_JOB_WRITE_VALIDATE or 
*               FEE_JOB_WRITE_UNALIGNED_DATA subsequent job
*     
* @implements   DFEE03074
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void )
{
    VAR( Fls_AddressType, AUTOMATIC ) dataAddr;
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) blockSize = 0U;
    VAR( uint16, AUTOMATIC ) alignedBlockSize = 0U;    
    VAR( Fls_LengthType, AUTOMATIC ) writeLength = 0UL;    
    VAR( uint16, AUTOMATIC ) clrGrp =0U;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) writeDataPtr = 0;    

/* @implements         DFEE28001 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    /* @implements         DFEE28002 */
    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    if( !Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
        /* @implements         DFEE28003 */
        VAR( Fls_AddressType, AUTOMATIC ) hdrAddr;
        /* @implements         DFEE28004 */
        VAR( uint8, AUTOMATIC ) clrGrpIndex = (uint8)0;

        /* Index of cluster group the Fee block belongs to */
        /* @implements         DFEE28005 */
        clrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;

        /* Get size of Fee block */
        /* @implements         DFEE28006 */
        blockSize = Fee_BlockConfig[Fee_JobBlockIndex].blockSize;

        /* Align Fee block size to the virtual page boundary */
        /* @implements         DFEE28007 */
        alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );

        /* Calculate data and header addresses */
        /* @implements         DFEE28008 */
        dataAddr = Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt - alignedBlockSize;
        /* @implements         DFEE28009 */
        hdrAddr = Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt;

        /* @implements         DFEE28010 */
        Fee_BlockInfo[Fee_JobBlockIndex].dataAddr = dataAddr;
        /* @implements         DFEE28011 */
        Fee_BlockInfo[Fee_JobBlockIndex].invalidAddr = ( hdrAddr + FEE_BLOCK_OVERHEAD ) - FEE_VIRTUAL_PAGE_SIZE;
    }
    /* Mark the block as inconsistent since the block header has been written */
    /* @implements         DFEE28012 */
    Fee_BlockInfo[Fee_JobBlockIndex].blockStatus = FEE_BLOCK_INCONSISTENT;
#endif
    
    /* Get size of Fee block */
    /* @implements         DFEE28013 */
    blockSize = Fee_BlockConfig[Fee_JobBlockIndex].blockSize;

    /* Align Fee block size to the virtual page boundary */
    /* @implements         DFEE28014 */
    alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );

    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE28015 */
    clrGrp = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;

    /* @implements         DFEE28016 */
    if( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
        /* Don't update header and data pointes as it's immediate write */
    }
    else
    {
        /* Header has been written so update both header and data addresses */
        /* @implements         DFEE28017 */
        Fee_ClrGrpInfo[clrGrp].hdrAddrIt += FEE_BLOCK_OVERHEAD;
        /* @implements         DFEE28018 */
        Fee_ClrGrpInfo[clrGrp].dataAddrIt -= alignedBlockSize;
    }
    
    /* @implements         DFEE28019 */
    if( blockSize < FEE_VIRTUAL_PAGE_SIZE )
    {
        /* Go through buffer... */
        /* @implements         DFEE28020 */
        Fee_CopyDataToPageBuffer( Fee_JobDataDestPtr, Fee_DataBuffer, blockSize );
        /* @implements         DFEE28021 */
        writeDataPtr = Fee_DataBuffer;
        /* @implements         DFEE28022 */
        writeLength = FEE_VIRTUAL_PAGE_SIZE;
        
        /* Schedule write of validation pattern */
        /* @implements         DFEE28023 */
        Fee_Job = FEE_JOB_WRITE_VALIDATE;
    }
    else
    {
        /* @implements         DFEE28024 */
        writeDataPtr = Fee_JobDataDestPtr;
        
        /* @implements         DFEE28025 */
        if( alignedBlockSize == blockSize )
        {
            /* @implements         DFEE28026 */
            writeLength = blockSize;
            
            /* Schedule write of validation pattern */
            /* @implements         DFEE28027 */
            Fee_Job = FEE_JOB_WRITE_VALIDATE;
        }
        else
        {
            /* @implements         DFEE28028 */
            writeLength = (uint32) alignedBlockSize - FEE_VIRTUAL_PAGE_SIZE;
            
            /* Schedule write of unaligned data */
            /* @implements         DFEE28029 */
            Fee_Job = FEE_JOB_WRITE_UNALIGNED_DATA;            
        }
    }

/* @implements         DFEE28030 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE28031 */
    if( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
#endif
        /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
        /* @implements         DFEE28032 */
        dataAddr = Fee_BlockInfo[Fee_JobBlockIndex].dataAddr;

/* @implements         DFEE28033 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    }
    else
    {
        /* Use ClrGrp info */
        /* @implements         DFEE28034 */
        dataAddr = Fee_ClrGrpInfo[clrGrp].dataAddrIt;
    }
#endif

    /* @implements         DFEE28035 */
    if( (Std_ReturnType)E_OK == Fls_Write( dataAddr, writeDataPtr, writeLength ) )
    {
        /* Fls read job has been accepted */
        /* @implements         DFEE28036 */
        RetVal = MEMIF_JOB_PENDING;    
    }
    else
    {
        /* Fls write job hasn't been accepted */
        /* @implements         DFEE28037 */
        RetVal = MEMIF_JOB_FAILED;
    }
    
    return( RetVal );
}

/** 
* @brief        Write Fee block to flash
*               
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @pre          Fee_JobDataDestPtr must contain valid pointer to user buffer
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_WRITE_DATA subsequent job
* 
* @implements   DFEE03073
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void )
{
    /* @implements         DFEE27001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
    
    /* @implements         DFEE27002 */
    if( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
        /* @implements         DFEE27003 */
        if( FEE_BLOCK_INCONSISTENT == Fee_BlockInfo[Fee_JobBlockIndex].blockStatus )
        {
            /* The immediate block is ready to be written */
            /* @implements         DFEE27004 */
            RetVal = Fee_JobWriteData();
        }
        else
        {
            /* The immediate block is not pre-erased and ready to be written */
            /* @implements         DFEE27005 */
            RetVal = MEMIF_JOB_FAILED;
        }
    }
    else
    {
        /* Write block header */
        /* @implements         DFEE27006 */
        RetVal = Fee_JobWriteHdr();
        
        /* Schedule next job */
        /* @implements         DFEE27007 */
        if( FEE_JOB_INT_SWAP_CLR_FMT == Fee_Job )
        {        
            /* Block din't fit into the cluster.
               Cluster swap has been enforced... */
        }
        else
        {
            /* @implements         DFEE27008 */
            Fee_Job = FEE_JOB_WRITE_DATA;        
        }
    }
    
    return( RetVal );
}

/** 
* @brief        Write unaligned rest of Fee block data to flash
*               
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*               
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @pre          Fee_JobDataDestPtr must contain valid pointer to user buffer
* @post         Schedule FEE_JOB_WRITE_VALIDATE subsequent job
* 
* @implements   DFEE03077
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void )
{
    /* @implements         DFEE26001 */
    VAR( Fls_AddressType, AUTOMATIC ) dataAddr;
    /* @implements         DFEE26002 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    /* @implements         DFEE26003 */
    VAR( uint16, AUTOMATIC ) writeOffset = 0U;
    /* @implements         DFEE26004 */
    VAR( uint16, AUTOMATIC ) writeLength = 0U;
    /* @implements         DFEE26005 */
    VAR( uint16, AUTOMATIC ) blockSize = 0U;
/* @implements         DFEE26006 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE26007 */
    VAR( uint16, AUTOMATIC ) clrGrp =0U;

    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE26008 */
    clrGrp = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;
#endif
    /* Get size of Fee block */
    /* @implements         DFEE26009 */
    blockSize = Fee_BlockConfig[Fee_JobBlockIndex].blockSize;

    /* Calculate number of bytes already written */
    /* @implements         DFEE26010 */
    writeOffset = (blockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;
    
    /* Calculate length remaining data to write */
    /* @implements         DFEE26011 */
    writeLength = blockSize % FEE_VIRTUAL_PAGE_SIZE;
    
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the 
       only allowed form of pointer arithmetic */
    /* @implements         DFEE26012 */
    Fee_CopyDataToPageBuffer( Fee_JobDataDestPtr + writeOffset, Fee_DataBuffer,
        writeLength );

/* @implements         DFEE26013 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE26014 */
    if( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
#endif
        /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
        /* @implements         DFEE26015 */
        dataAddr = Fee_BlockInfo[Fee_JobBlockIndex].dataAddr;
/* @implements         DFEE26016 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    }
    else
    {
        /* Use ClrGrp info */
        /* @implements         DFEE26017 */
        dataAddr = Fee_ClrGrpInfo[clrGrp].dataAddrIt;
    }
#endif

    /* @implements         DFEE26018 */
    if( (Std_ReturnType)E_OK == Fls_Write( dataAddr + writeOffset,
                                Fee_DataBuffer,    FEE_VIRTUAL_PAGE_SIZE ) )
    {
        /* Fls write job has been accepted */
        /* @implements         DFEE26019 */
        RetVal = MEMIF_JOB_PENDING;    
    }
    else
    {
        /* Fls write job hasn't been accepted */
        /* @implements         DFEE26020 */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule write of validation pattern */
    /* @implements         DFEE26021 */
    Fee_Job = FEE_JOB_WRITE_VALIDATE;
    
    return( RetVal );
}

/**
* @brief        Validate Fee block by writing validation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to validate
* @post         Schedule FEE_JOB_WRITE_DONE subsequent job
* 
* @implements   DFEE03078
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void )
{
    /* @implements         DFEE25001 */
    VAR( Fls_AddressType, AUTOMATIC ) hdrAddr;
    /* @implements         DFEE25002 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
/* @implements         DFEE25003 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE25004 */
    VAR( uint8, AUTOMATIC ) clrGrpIndex = (uint8)0;
    
    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE25005 */
    clrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;
#endif       
    /* Serialize validation pattern to buffer */
    /* @implements         DFEE25006 */
    Fee_SerializeFlag( Fee_DataBuffer, FEE_VALIDATED_VALUE );

/* @implements         DFEE25007 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE25008 */
    if( Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
#endif
        /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
        /* @implements         DFEE25009 */
        hdrAddr = (Fee_BlockInfo[Fee_JobBlockIndex].invalidAddr - FEE_VIRTUAL_PAGE_SIZE);
/* @implements         DFEE25010 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    }
    else
    {
        /* Use ClrGrp info */
        /* @implements         DFEE25011 */
        hdrAddr = Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt - (2U *  FEE_VIRTUAL_PAGE_SIZE);
    }
#endif
    
    /* Write validation pattern to flash */
    /* @implements         DFEE25012 */
    if( (Std_ReturnType)E_OK == Fls_Write( hdrAddr, Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE) )
    {
        /* Fls read job has been accepted */
        /* @implements         DFEE25013 */
        RetVal = MEMIF_JOB_PENDING;    
    }
    else
    {
        /* Fls write job hasn't been accepted */
        /* @implements         DFEE25014 */
        RetVal = MEMIF_JOB_FAILED;
    }
    
    /* Finalize the write operation */
    /* @implements         DFEE25015 */
    Fee_Job = FEE_JOB_WRITE_DONE;
    
    return( RetVal );
}

/**
* @brief        Finalize validation of Fee block
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_VALID
* @post         Schedule FEE_JOB_DONE subsequent job
* 
* @implements   DFEE03075
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void )
{
/* @implements         DFEE23001 */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* @implements         DFEE23002 */
    VAR( Fls_AddressType, AUTOMATIC ) dataAddr;
    /* @implements         DFEE23003 */
    VAR( Fls_AddressType, AUTOMATIC ) hdrAddr;
    /* @implements         DFEE23004 */
    VAR( uint8, AUTOMATIC ) clrGrpIndex = (uint8)0;
    
    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE23005 */
    clrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;
    
    /* Calculate data and header addresses */
    /* @implements         DFEE23006 */
    dataAddr = Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt;
    /* @implements         DFEE23007 */
    hdrAddr = Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt;

    /* @implements         DFEE23008 */
    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    if( !Fee_BlockConfig[Fee_JobBlockIndex].immediateData )
    {
    /* Update the block address info */
    /* @implements         DFEE23009 */
    Fee_BlockInfo[Fee_JobBlockIndex].dataAddr = dataAddr;
    /* @implements         DFEE23010 */
    Fee_BlockInfo[Fee_JobBlockIndex].invalidAddr = ( hdrAddr - FEE_VIRTUAL_PAGE_SIZE);
    }
#endif

    /* Mark the Fee block as valid */
    /* @implements         DFEE23011 */
    Fee_BlockInfo[Fee_JobBlockIndex].blockStatus = FEE_BLOCK_VALID;

    /* No more Fls jobs to schedule */
    /* @implements         DFEE23012 */
    Fee_Job = FEE_JOB_DONE;
    
    return( MEMIF_JOB_OK );
}

/**
* @brief        Invalidate Fee block by writing the invalidation flag to flash
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* @retval       MEMIF_JOB_OK             The Fee block is already invalid
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to invalidate
* @post         Schedule FEE_JOB_DONE or FEE_JOB_INVAL_BLOCK_DONE subsequent 
*               jobs
* 
* @implements   DFEE03069
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void )
{
    /* @implements         DFEE22001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    
    /* @implements         DFEE22002 */
    if( FEE_BLOCK_INVALID == Fee_BlockInfo[Fee_JobBlockIndex].blockStatus ) 
    {
        /* No more subsequent Fls jobs to schedule */
        /* @implements         DFEE22003 */
        Fee_Job = FEE_JOB_DONE;
        
        /* Fee job completed */
        /* @implements         DFEE22004 */
        RetVal = MEMIF_JOB_OK;        
    }
    else
    {
        /* Serialize invalidation pattern to buffer */
        /* @implements         DFEE22005 */
        Fee_SerializeFlag( Fee_DataBuffer, FEE_INVALIDATED_VALUE );
        
        /* Write invalidation pattern to flash */
        /* @implements         DFEE22006 */
        if( (Std_ReturnType)E_OK == Fls_Write( Fee_BlockInfo[Fee_JobBlockIndex].invalidAddr, \
            Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) )
        {
            /* Fls read job has been accepted */
            /* @implements         DFEE22007 */
            RetVal = MEMIF_JOB_PENDING;    
        }
        else
        {
            /* Fls write job hasn't been accepted */
            /* @implements         DFEE22008 */
            RetVal = MEMIF_JOB_FAILED;
        }
        
        /* Finalize the invalidation operation */
        /* @implements         DFEE22009 */
        Fee_Job = FEE_JOB_INVAL_BLOCK_DONE;
    }
    
    return( RetVal );
}

/**
* @brief        Finalize invalidation of Fee block
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
* 
* @pre          Fee_JobBlockIndex        must contain index of Fee block to 
*                                        write to
* @post         change Fee block status to FEE_BLOCK_INVALID
* @post         Schedule FEE_JOB_DONE subsequent job
* 
* @implements   DFEE03070
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void )
{
    /* Mark the Fee block as in valid */
    /* @implements         DFEE21001 */
    Fee_BlockInfo[Fee_JobBlockIndex].blockStatus = FEE_BLOCK_INVALID;

    /* No more subsequent Fls jobs to schedule */
    /* @implements         DFEE21002 */
    Fee_Job = FEE_JOB_DONE;
    
    /* Fee job completed */
    return( MEMIF_JOB_OK );
}

/**
* @brief        Erase (pre-allocate) immediate Fee block
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to 
*               pre-allocated
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster    
* @post         Schedule FEE_JOB_ERASE_IMMEDIATE_DONE subsequent jobs
* 
* @implements   DFEE03049
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void )
{
    /* @implements         DFEE20001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;
    
    /* Write block header */
    /* @implements         DFEE20002 */
    RetVal = Fee_JobWriteHdr();
        
    /* Schedule next job */
    /* @implements         DFEE20003 */
    if( FEE_JOB_INT_SWAP_CLR_FMT == Fee_Job )
    {
        /* Block din't fit into the cluster.
           Cluster swap has been enforced... */
    }
    else
    {
        /* @implements         DFEE20004 */
        Fee_Job = FEE_JOB_ERASE_IMMEDIATE_DONE;
    }

    return( RetVal );
}

/**
* @brief        Finalize erase (pre-allocation) of Fee block
* 
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
* 
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_INCONSISTENT
* @post         Schedule FEE_JOB_DONE subsequent job
* 
* @implements   DFEE03050
* 
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void )
{
    /* @implements         DFEE24001 */
    VAR( uint16, AUTOMATIC ) blockSize = 0U;
    /* @implements         DFEE24002 */
    VAR( uint16, AUTOMATIC ) alignedBlockSize = 0U;
    /* @implements         DFEE24003 */
    VAR( uint16, AUTOMATIC ) clrGrp = 0U;

    /* Mark the Fee immediate block as inconsistent 
        so it can be written later on */
    /* @implements         DFEE24008 */
    Fee_BlockInfo[Fee_JobBlockIndex].blockStatus = FEE_BLOCK_INCONSISTENT;

    /* Get size of Fee block */
    /* @implements         DFEE24009 */
    blockSize = Fee_BlockConfig[Fee_JobBlockIndex].blockSize;

    /* Align Fee block size to the virtual page boundary */
    /* @implements         DFEE24010 */
    alignedBlockSize = Fee_AlignToVirtualPageSize( blockSize );

    /* Index of cluster group the Fee block belongs to */
    /* @implements         DFEE24011 */
    clrGrp = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;

    /* Header has been written so update both header and data addresses */
    /* @implements         DFEE24018 */
    Fee_ClrGrpInfo[clrGrp].hdrAddrIt += FEE_BLOCK_OVERHEAD;
    /* @implements         DFEE24019 */
    Fee_ClrGrpInfo[clrGrp].dataAddrIt -= alignedBlockSize;

/* @implements         DFEE24020 */
    /* As Fee immediate block is inconsistent 
       it is not possible to get previous data, so update Block info */
    /* @implements         DFEE24021 */
    Fee_BlockInfo[Fee_JobBlockIndex].invalidAddr = (Fee_ClrGrpInfo[clrGrp].hdrAddrIt - FEE_VIRTUAL_PAGE_SIZE);
    /* @implements         DFEE24022 */
    Fee_BlockInfo[Fee_JobBlockIndex].dataAddr = Fee_ClrGrpInfo[clrGrp].dataAddrIt;

    /* No more subsequent Fls jobs to schedule */
    /* @implements         DFEE24023 */
    Fee_Job = FEE_JOB_DONE;
    
    /* Fee job completed */
    return( MEMIF_JOB_OK );
}

/**
* @brief        Schedule subsequent jobs
*
* @return       MemIf_JobResultType
*
* @pre          Fee_Job must contain type of job to schedule
* 
* @implements   DFEE03072
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void )
{
    /* @implements         DFEE19001 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_FAILED;
        
    switch( Fee_Job )
    {
        /* Fee_Read() related jobs */
        /* @implements         DFEE19002, DFEE19032 */
        case FEE_JOB_READ:
            RetVal = Fee_JobRead();
            break;
    
        /* Fee_Write() related jobs */
        /* @implements         DFEE19003, DFEE19033 */
        case FEE_JOB_WRITE:
            RetVal = Fee_JobWrite();
            break;

        /* @implements         DFEE19004, DFEE19034 */
        case FEE_JOB_WRITE_DATA:
            RetVal = Fee_JobWriteData();
            break;
        
        /* @implements         DFEE19005, DFEE19035 */
        case FEE_JOB_WRITE_UNALIGNED_DATA:
            RetVal = Fee_JobWriteUnalignedData();
            break;
        
        /* @implements         DFEE19006, DFEE19036 */
        case FEE_JOB_WRITE_VALIDATE:
            RetVal = Fee_JobWriteValidate();
            break;
        
        /* @implements         DFEE19007, DFEE19037 */
        case FEE_JOB_WRITE_DONE:
            RetVal = Fee_JobWriteDone();
            break;

        /* Fee_InvalidateBlock() related jobs */
        /* @implements         DFEE19008, DFEE19038 */
        case FEE_JOB_INVAL_BLOCK:
            RetVal = Fee_JobInvalBlock();
            break;
        
        /* @implements         DFEE19009, DFEE19039 */
        case FEE_JOB_INVAL_BLOCK_DONE:
            RetVal = Fee_JobInvalBlockDone();
            break;
    
        /* Fee_EraseImmediateBlock() related jobs */
        /* @implements         DFEE19010, DFEE19040 */
        case FEE_JOB_ERASE_IMMEDIATE:
            RetVal = Fee_JobEraseImmediate();
            break;
            
        /* @implements         DFEE19011, DFEE19041 */
        case FEE_JOB_ERASE_IMMEDIATE_DONE:
            RetVal = Fee_JobEraseImmediateDone();
            break;
        
        /* Fee_Init() related jobs */
        /* @implements         DFEE19012, DFEE19042 */
        case FEE_JOB_INT_SCAN:
            RetVal = Fee_JobIntScan();
            break;

        /* @implements         DFEE19014, DFEE19044 */
        case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            RetVal = Fee_JobIntScanClrHdrParse((boolean) TRUE );
            break;
        
        /* @implements         DFEE19015, DFEE19045 */
        case FEE_JOB_INT_SCAN_CLR_FMT:
            RetVal = Fee_JobIntScanClrFmt();
            break;
        
        /* @implements         DFEE19016, DFEE19046 */
        case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            RetVal = Fee_JobIntScanClrFmtDone();
            break;

        /* @implements         DFEE19017, DFEE19047 */
        case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            RetVal = Fee_JobIntScanBlockHdrParse((boolean) TRUE );
            break;

        /* Swap related jobs */
        /* @implements         DFEE19018, DFEE19048 */
        case FEE_JOB_INT_SWAP_CLR_FMT:
            RetVal = Fee_JobIntSwapClrFmt();
            break;

        /* @implements         DFEE19019, DFEE19049 */
        case FEE_JOB_INT_SWAP_BLOCK:
            RetVal = Fee_JobIntSwapBlock();
            break;

        /* @implements         DFEE19020, DFEE19050 */
        case FEE_JOB_INT_SWAP_DATA_READ:
            RetVal = Fee_JobIntSwapDataRead((boolean) TRUE );
            break;        

        /* @implements         DFEE19021, DFEE19051 */
        case FEE_JOB_INT_SWAP_DATA_WRITE:
            RetVal = Fee_JobIntSwapDataWrite((boolean) TRUE );
            break;

        /* @implements         DFEE19022, DFEE19052 */
        case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            RetVal = Fee_JobIntSwapClrVldDone();
            break;

        /* if the job is finished switch case will break */
        /* @implements         DFEE19023 */
        case FEE_JOB_DONE:
            /* Do nothing */
            break;

        /* @implements         DFEE19024, DFEE19054 */
        default:
            Cer_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_JOBSCHEDULE_ID, FEE_E_JOB_UNKNOW);
            /* No return from this function call, a call to Cer_ReporError()
               function causes an infinite loop from which it is impossible to escape.
            */
            /* Break not required here and avoids a compiler warning "statement never reached" */
    }
    
    return( RetVal );
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if !defined(__DOXYGEN__)

/* Job end notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_END_NOTIFICATION_DECL

/* Job error notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_ERROR_NOTIFICATION_DECL

#endif

/**
* @brief        Service to initialize the FEE module.
* @details      The function Fee_Init shall initialize the Flash EEPROM 
*               Emulation module.  
*       
* @pre          The FEE module'  s environment shall not call the function  
*               Fee_Init shall during a running operation of the FEE module.
* @note         The function Autosar Service ID[hex]: 0x00.   
* @note         Synchronous
* @note         Non Reentrant
*               
* @api          
*               
* @implements   DFEE03008
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_Init( void )
{ 
/* @implements         DFEE06001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements         DFEE06002, DFEE06009 */
    if( MEMIF_BUSY == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID, FEE_E_BUSY );
    }
    /* @implements         DFEE06003, DFEE06010 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID, FEE_E_BUSY_INTERNAL );
    }    
    else
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */    
    {
        VAR( uint32, AUTOMATIC ) InvalIndex;

        /* Invalidate all blocks */
        /* @implements         DFEE06004, DFEE06011 */
        for( InvalIndex = 0U; InvalIndex < FEE_NUMBER_OF_BLOCKS; InvalIndex++ )
        {
            Fee_BlockInfo[InvalIndex].blockStatus = FEE_BLOCK_INVALID;
        }
        
        /* Invalidate all cluster groups */
        /* @implements         DFEE06005, DFEE06012 */
        for( InvalIndex = 0U; InvalIndex < FEE_NUMBER_OF_CLUSTER_GROUPS; InvalIndex++ )
        {
            Fee_ClrGrpInfo[InvalIndex].actClrID = 0U;
        }
    
        /* Schedule init job */
        /* @implements         DFEE06006 */
        Fee_Job = FEE_JOB_INT_SCAN;

        /* @implements         DFEE06007 */
        Fee_ModuleStatus = MEMIF_BUSY_INTERNAL;
        
        /* @implements         DFEE06008 */
        Fee_JobResult = MEMIF_JOB_PENDING;
    }
}

#if(( FEE_SETMODE_API_SUPPORTED == STD_ON ) || defined(__DOXYGEN__))
/** 
* @brief        Set the Fee module' s operation mode to the given Mode.
* @details      Call the Fls_SetMode function of the underlying flash driver.
*
* @param[in]    Mode (Either MEMIF_MODE_FAST or MEMIF_MODE_SLOW)
*               
* @pre          The module must be initialized and not busy.
*
* @api 
*
* @implements   DFEE03009
*
* @note         The function Autosar Service ID[hex]: 0x01.   
* @note         Synchronous
* @note         Non Reentrant
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_SetMode(
    VAR( MemIf_ModeType, AUTOMATIC) Mode )
{

/* @implements         DFEE08001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements         DFEE08002, DFEE08006 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_UNINIT );
    }
    /* @implements         DFEE08003, DFEE08007 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_BUSY );
    }
    /* @implements         DFEE08004, DFEE08008 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_BUSY_INTERNAL );
    }
    else
    /* @implements         DFEE08005, DFEE08009, DFEE08010 */
#else
        if( MEMIF_IDLE == Fee_ModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */   
        {
            Fls_SetMode( Mode );
        }
}
#endif /* ( FEE_SETMODE_API_SUPPORTED == STD_ON ) || defined(__DOXYGEN__) */ 

/** 
* @brief        Service to initiate a read job.
* @details      The function Fee_Read shall take the block start address and 
*               offset and calculate the corresponding memory read address.  
*
* @param[in]    BlockNumber      Number of logical block, also denoting 
*                                start address of that block in flash memory.
* @param[in]    BlockOffset      Read address offset inside the block.
* @param[out]   DataBufferPtr    Pointer to data buffer.
* @param[in]    Length           Number of bytes to read.
*
* @pre          The module must be initialized, not busy, BlockNumber must be 
*               valid, Length != 0, DataBufferPtr != NULL_PTR, BlockOffset and 
*               (BlockOffset + Length - 1) must be in range.  
* @post         changes Fee_ModuleStatus module status and Fee_JobBlockOffset, 
*               Fee_JobBlockLength, Fee_JobBlockIndex, Fee_JobDataDestPtr, 
*               Fee_Job, Fee_JobResult job control internal variables.
*
* @return       Std_ReturnType   
* @retval       E_OK             The read job was accepted by the 
*                                underlying memory driver.
* @retval       E_NOT_OK         The read job has not been accepted 
*                                by the underlying memory driver.
*
* @api 
*      
* @implements   DFEE03010
*
* @note         The function Autosar Service ID[hex]: 0x02.
* @note         Asynchronous.
* @note         Non Reentrant. 
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_Read(
    VAR( uint16, AUTOMATIC ) BlockNumber,
    VAR( uint16, AUTOMATIC ) BlockOffset,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr,
    VAR( uint16, AUTOMATIC ) Length )
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) blockIndex = Fee_GetBlockIndex( BlockNumber );

    /* @implements            DFEE07001, DFEE07002, DFEE07016 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE07006, DFEE07020 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE07007, DFEE07021 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_BUSY_INTERNAL );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* @implements            DFEE07023 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements            DFEE07003, DFEE07017 */
    else if( 0xffffU == blockIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_NO );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE07004, DFEE07018 */
    else if( BlockOffset >= Fee_BlockConfig[blockIndex].blockSize )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_OFS );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE07005, DFEE07019 */
    else if(( 0U == Length ) || ((BlockOffset + Length) > Fee_BlockConfig[blockIndex].blockSize ))
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_LEN );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE07008, DFEE07022 */
    else if( NULL_PTR == DataBufferPtr )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_DATA_PTR );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {

        /* Configure the read job */
        /* @implements            DFEE07009 */
        Fee_JobBlockIndex = blockIndex;        
        
        /* @implements            DFEE07010 */
        Fee_JobBlockOffset = BlockOffset;
        
        /* @implements            DFEE07011 */
        Fee_JobBlockLength = Length;
        
        /* @implements            DFEE07012 */
        Fee_JobDataDestPtr = DataBufferPtr;
        
        /* @implements            DFEE07013 */
        Fee_Job = FEE_JOB_READ;

        /* @implements            DFEE07014 */
        Fee_ModuleStatus = MEMIF_BUSY;
        
        /* Execute the read job */
        /* @implements            DFEE07015 */
        Fee_JobResult = MEMIF_JOB_PENDING;
    }

    return( RetVal );
}

/** 
* @brief        Service to initiate a write job.
* @details      The function Fee_Write shall take the block start address and 
*               calculate the corresponding memory write address. The block 
*               address offset shall be fixed to zero.
*               The function Fee_Write shall copy the given / computed 
*               parameters to module internal variables, initiate a write job, 
*               set the FEE module status to MEMIF_BUSY, set the job result to 
*               MEMIF_JOB_PENDING and return with E_OK.The FEE module shall 
*               execute the write job of the function Fee_Write
*               asynchronously within the FEE module' s main function. 
*               
* @param[in]    BlockNumber      Number of logical block, also denoting 
*                                start address of that block in emulated 
*                                EEPROM.
* @param[out]   DataBufferPtr    Pointer to data buffer.
*               
* @return       Std_ReturnType
* @retval       E_OK             The write job was accepted by the 
*                                underlying memory driver.
* @retval       E_NOT_OK         The write job has not been accepted by 
*                                the underlying memory driver. 
*
* @pre          The module must be initialized, not busy, BlockNumber must be 
*               valid, and DataBufferPtr != NULL_PTR.  
*               Before call the function "Fee_Write" for immediate date must be 
*               called the function "Fee_EraseImmediateBlock".
* @post         changes Fee_ModuleStatus module status and Fee_JobBlockIndex,
*               Fee_JobDataDestPtr, Fee_Job, Fee_JobResult job control internal 
*               variables.
* @note         The function Autosar Service ID[hex]: 0x03.   
* @note         Asynchronous.
* @note         Non Reentrant.  
*
* @api 
*     
* @implements   DFEE03011
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_Write(
    VAR( uint16, AUTOMATIC ) BlockNumber,
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr) 
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) blockIndex = Fee_GetBlockIndex( BlockNumber );


    /* @implements            DFEE09002, DFEE09012 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
    /* @implements            DFEE09001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE09004, DFEE09014 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements            DFEE09003, DFEE09013 */
    else if( 0xffffU == blockIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE09005, DFEE09015 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_BUSY_INTERNAL );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE09006, DFEE09016 */
    else if( NULL_PTR == DataBufferPtr )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_DATA_PTR );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
    
        /* Configure the write job */
        /* @implements            DFEE09007 */
        Fee_JobBlockIndex = blockIndex;
        
        /* @implements            DFEE09008 */
        Fee_JobDataDestPtr = DataBufferPtr;
        
        /* @implements            DFEE09009 */
        Fee_Job = FEE_JOB_WRITE;
        
        /* @implements            DFEE09010 */
        Fee_ModuleStatus = MEMIF_BUSY;
        
        /* Execute the write job */
        /* @implements            DFEE09011 */
        Fee_JobResult = MEMIF_JOB_PENDING;

    }

    return( RetVal );
}

/** 
* @brief        Service to call the cancel function of the underlying flash 
*               driver.
* @details      The function Fee_Cancel and the cancel function of the 
*               underlying flash driver are asynchronous w.r.t. an ongoing 
*               read, erase or write job in the flash memory.  
*    
* @pre          The module must be initialized.
* @post         Changes Fee_ModuleStatus module status and job result 
*               Fee_JobResult internal variables.
* @note         The function Autosar Service ID[hex]: 0x04.   
* @note         Asynchronous.
* @note         Non Reentrant.  
*
* @api  
*  
* @implements   DFEE03012
*
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_Cancel( void )
{

/* If FEE_CANCEL_API == STD_OFF Fee_Cancel set only a Det Error Notification
   Note: this is to avoid robustness issues (in term of internal variables) */
#if( FEE_CANCEL_API == STD_OFF )
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_CANCEL_API );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#else

/* @implements         DFEE10001, DFEE10007, DFEE10008 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_UNINIT );
    }
    else
    {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* @implements         DFEE10002 */
        if( MEMIF_JOB_PENDING == Fee_JobResult )
        {
            /* Cancel ongoing Fls job if any */
            /* @implements         DFEE10009 */
            if( MEMIF_BUSY == Fee_ModuleStatus )
            {
                /* @implements         DFEE10003, DFEE10004, DFEE10005, DFEE10006 */
                Fee_JobResult = MEMIF_JOB_CANCELED;
                Fee_Job       = FEE_JOB_DONE;
                Fls_Cancel();
                Fee_ModuleStatus = MEMIF_IDLE;

                /* No notifications from internal jobs */
            }
            else
            {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
                /* @implements         DFEE10011 */
                Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_INVALID_CANCEL );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
                /* Call job error notification function */
                /* @implements         DFEE10010 */
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
        }
        else
        {
            /* Leave the job result unchanged */
        }
        
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#endif    /* FLS_CANCEL_API == STD_ON */
}

/** 
* @brief        Return the Fee module state.
* @details      Return the Fee module state synchronously.
*
* @note         The function Autosar Service ID[hex]: 0x05.   
* @note         Synchronous
* @note         Non Reentrant  
*               
* @return       Fee_ModuleStatus
* @retval       MEMIF_UNINIT             Module has not been initialized (yet).
* @retval       MEMIF_IDLE               Module is currently idle.
* @retval       MEMIF_BUSY               Module is currently busy.
* @retval       MEMIF_BUSY_INTERNAL      Module is busy with internal management
*                                        operations.
*               
* @api          
*               
* @implements   DFEE03013
*
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void ) 
{
    /* @implements         DFEE11001 */
    return( Fee_ModuleStatus );
}

/** 
* @brief        Return the result of the last job.
* @details      Return the result of the last job synchronously.
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK              The job has been finished successfully.
* @retval       MEMIF_JOB_FAILED          The job has not been finished 
*                                         successfully.
* @retval       MEMIF_JOB_PENDING         The job has not yet been finished.
* @retval       MEMIF_JOB_CANCELED        The job has been canceled.
* @retval       MEMIF_BLOCK_INCONSISTENT  The requested block is inconsistent, 
*                                         it may contain corrupted data.
* @retval       MEMIF_BLOCK_INVALID       The requested block has been invalidated, 
*                                         the requested read operation can not be performed.
*
* @api  
*  
* @implements   DFEE03014
*               
* @note         The function Autosar Service ID[hex]: 0x06.   
* @note         Synchronous.
* @note         Non Reentrant.   
*               
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void )
{
    /* @implements         DFEE12005 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = Fee_JobResult;
    /* @implements         DFEE12006 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements         DFEE12002, DFEE12003, DFEE12004  */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETJOBRESULT_ID, FEE_E_UNINIT );
        RetVal = MEMIF_JOB_FAILED;
    }    
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    /* @implements         DFEE12001 */
    return( RetVal );
}

/** 
* @brief        Service to invalidate a logical block.
*  
* @param[in]    BlockNumber      Number of logical block, also denoting  
*                                start address of that block in flash memory 
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying 
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the 
*                                underlying memory driver.
*  
* @pre          The module must be initialized, not busy, and BlockNumber must be 
*               valid
*               
* @post         changes Fee_ModuleStatus module status and Fee_JobBlockIndex, 
*               Fee_Job, and Fee_JobResult job control internal variables.
*               EEPROM.
*
* @api  
*
* @implements   DFEE03015
* 
* @note         The function Autosar Service ID[hex]: 0x07.   
* @note         Asynchronous.
* @note         Non Reentrant.  
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock(
    VAR( uint16, AUTOMATIC ) BlockNumber )
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR( uint16, AUTOMATIC ) blockIndex = Fee_GetBlockIndex( BlockNumber );

/* @implements         DFEE13001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements         DFEE13002, DFEE13010 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_UNINIT );
    }
    /* @implements         DFEE13003, DFEE13011 */
    else if( 0xffffU == blockIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, \
                                                 FEE_E_INVALID_BLOCK_NO );
    }
    /* @implements         DFEE13004, DFEE13012 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY );
    }
    /* @implements         DFEE13005, DFEE13013 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, \
                                                 FEE_E_BUSY_INTERNAL );
    }    
    else
#else
        /* @implements         DFEE13014 */
        if( MEMIF_IDLE == Fee_ModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */   
        {

            /* Configure the invalidate block job */
            /* @implements         DFEE13006 */
            Fee_JobBlockIndex = blockIndex;
        
            /* @implements         DFEE13007 */
            Fee_Job = FEE_JOB_INVAL_BLOCK;
            
            /* @implements         DFEE13008 */
            Fee_ModuleStatus = MEMIF_BUSY;
            
            /* Execute the invalidate block job */
            /* @implements         DFEE13009 */
            Fee_JobResult = MEMIF_JOB_PENDING;
        
            RetVal = (Std_ReturnType)E_OK;
        }


    return( RetVal );
}
/* @implements            DFEE14001 */
#if(( FEE_VERSION_INFO_API == STD_ON ) || defined(__DOXYGEN__))
/** 
* @brief        Return the version information of the Fee module.
* @details      The version information includes: Module Id, Vendor Id,
*               Vendor specific version numbers.
*
* @param[out]   VersionInfoPtr   Pointer to where to store the version
*                                information of this module .
*
* @pre          VersionInfoPtr must not be NULL_PTR.
*
* @api  
*  
* @implements   DFEE03016
* 
* @note         The function Autosar Service ID[hex]: 0x08.
* @note         Synchronous.
* @note         Non Reentrant.
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_GetVersionInfo(
    P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) VersionInfoPtr )
{
/* @implements            DFEE14002, DFEE14004, DFEE14005 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == VersionInfoPtr )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETVERSIONINFO_ID, \
                         FEE_E_INVALID_DATA_PTR );
    }
    else
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        /* @implements            DFEE14003 */
        VersionInfoPtr->moduleID = FEE_MODULE_ID;
        VersionInfoPtr->vendorID = FEE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)FEE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FEE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FEE_SW_PATCH_VERSION;
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FEE_VERSION_INFO_API == STD_ON */

/** 
* @brief        Service to erase a logical block.
* @details      The function Fee_EraseImmediateBlock shall take the block number
*               and calculate the corresponding memory block address.
*               The function Fee_EraseImmediateBlock shall ensure that the FEE
*               module can write immediate data. Whether this involves  
*               physically erasing a memory area and therefore calling the erase 
*               function of the underlying driver depends on the implementation.
*               If development error detection for the FEE module is enabled, 
*               the function Fee_EraseImmediateBlock shall check whether the 
*               addressed logical block is configured as containing immediate 
*               data (configuration parameter FeeImmediateData == TRUE). 
*               If not, the function Fee_EraseImmediateBlock 
*               shall report the error code FEE_E_INVALID_BLOCK_NO.
*
* @param[in]    BlockNumber      Number of logical block, also denoting.
*                          
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying 
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the underlying
*                                memory driver.
*                                start address of that block in emulated EEPROM.
*                 
* @pre          The module must be initialized, not busy, BlockNumber must be  
*               valid, and type of Fee block must be immediate.
* @post         changes Fee_ModuleStatus module status and Fee_JobBlockIndex, 
*               Fee_Job, and Fee_JobResult job control internal variables.
*    
* @api  
*       
* @implements   DFEE03017
*
* @note         The function Autosar Service ID[hex]: 0x09.   
* @note         Asynchronous.
* @note         Non Reentrant.  
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock(
    VAR( uint16, AUTOMATIC ) BlockNumber )
{
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) blockIndex = Fee_GetBlockIndex( BlockNumber );
 
/* @implements         DFEE15001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements         DFEE15002, DFEE15011 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements         DFEE15003, DFEE15012 */
    else if( 0xffffU == blockIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, \
                                                 FEE_E_INVALID_BLOCK_NO );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements         DFEE15004, DFEE15013 */
    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    else if( !Fee_BlockConfig[blockIndex].immediateData )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, \
                                                 FEE_E_INVALID_BLOCK_NO );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    /* @implements         DFEE15005, DFEE15014 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, \
                                                               FEE_E_BUSY );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements         DFEE15006, DFEE15015 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, \
                                                 FEE_E_BUSY_INTERNAL );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    else
    {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* Configure the erase immediate block job */
        /* @implements         DFEE15007 */
        Fee_JobBlockIndex = blockIndex;
        
        /* @implements         DFEE15008 */
        Fee_Job = FEE_JOB_ERASE_IMMEDIATE;
        
        /* @implements         DFEE15009 */
        Fee_ModuleStatus = MEMIF_BUSY;
        
        /* Execute the erase immediate block job */
        /* @implements         DFEE15010 */
        Fee_JobResult = MEMIF_JOB_PENDING;
#if( FEE_DEV_ERROR_DETECT == STD_ON )        
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return( RetVal );
}

/** 
* @brief        Service to report the FEE module the successful end of 
*               an asynchronous operation.
* @details      The underlying flash driver shall call the function 
*               Fee_JobEndNotification to report the successful end of 
*               an asynchronous operation.
*               
* @pre          The module must be initialized.
* @post         Changes Fee_ModuleStatus module status and Fee_JobResult  
*               internal variables.
*               
* @api          
*               
* @implements   DFEE03006
*
* @note         The function Autosar Service ID[hex]: 0x10.   
* @note         Synchronous.
* @note         Non Reentrant
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_JobEndNotification( void )
{
    /* @implements         DFEE16001 */
    if( FEE_JOB_DONE == Fee_Job )
    {
        /* Last schedule Fls job finished */
        /* @implements         DFEE16002 */
        Fee_JobResult = Fls_GetJobResult();
        
        /* @implements    DFEE16003, DFEE16009, DFEE16012 */
        if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
        {
            /* no notifications from internal jobs */
            Fee_ModuleStatus = MEMIF_IDLE;
        }
        else
        {
            Fee_ModuleStatus = MEMIF_IDLE;
            
            /* Call job end notification function */
            FEE_NVM_JOB_END_NOTIFICATION
        }
    }
    else
    {
        /* @implements         DFEE16004 */
        Fee_JobResult = Fee_JobSchedule();

        /* @implements         DFEE16006 */
        if( MEMIF_JOB_OK == Fee_JobResult )
        {
            /* @implements         DFEE16007, DFEE16010, DFEE16013 */
            if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
            {
                /* no notifications from internal jobs */
                Fee_ModuleStatus = MEMIF_IDLE;
            }
            else
            {
                Fee_ModuleStatus = MEMIF_IDLE;

                /* Call job end notification function */
                FEE_NVM_JOB_END_NOTIFICATION
            }
        }
        /* @implements         DFEE16005 */
        else if( MEMIF_JOB_PENDING == Fee_JobResult )
        {
            /* Nothing to do (ongoing Fls job) */
        }
        else
        {
            /* @implements         DFEE16008, DFEE16011, DFEE16014 */
            if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
            {
                /* no notifications from internal jobs */
                Fee_ModuleStatus = MEMIF_IDLE;
            }
            else
            {
                Fee_ModuleStatus = MEMIF_IDLE;
                
                /* Call job error notification function */
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
        }
    }
}

/** 
* @brief        Service to report the FEE module the failure of 
*               an asynchronous operation.
* @details      The underlying flash driver shall call the function 
*               Fee_JobErrorNotification to report the failure of 
*               an asynchronous operation.    
*                  
* @pre          The module must be initialized.
* @post         Changes Fee_ModuleStatus module status and Fee_JobResult 
*               internal variables.
*            
* @api          
*               
* @implements   DFEE03007
*               
* @note         The function Autosar Service ID[hex]: 0x11.   
* @note         Synchronous.
* @note         Non Reentrant.
*            
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void )
{
   VAR( boolean, AUTOMATIC ) callNotif= (boolean)FALSE; 

 /* @implements         DFEE17001 */
    if( MEMIF_JOB_CANCELED == Fee_JobResult )
    {
        /* Fls job has been canceled. Do nothing in this callback.
           The NvM_JobErrorNotification() callback will be called from 
           the Fee_Cancel()function which called the Fls_Cancel() function */
    }
    else
    {
        switch( Fee_Job )
        {
            /* Error while reading block header. Treat block header as 
                invalid and    stop reading further block headers */
            /* @implements         DFEE17002, DFEE17011 */
            case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
                Fee_JobResult = Fee_JobIntScanBlockHdrParse((boolean) FALSE );
                break;

            /* Error while reading cluster header. Treat cluster as 
                invalid and    move on to next cluster */
            /* @implements         DFEE17003, DFEE17012 */
            case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
                Fee_JobResult = Fee_JobIntScanClrHdrParse((boolean) FALSE );
                break;
                
            /* Error while reading data from source cluster.
                Leave block as INCONSISTENT and move on to next block */
            /* @implements         DFEE17004, DFEE17013 */
            case FEE_JOB_INT_SWAP_DATA_WRITE:
                Fee_JobResult = Fee_JobIntSwapDataWrite((boolean) FALSE );
                break;            
            /* for all the following cases based on the Fee module status error notification will
               be called */
            case FEE_JOB_WRITE:
            case FEE_JOB_WRITE_DATA:
            case FEE_JOB_WRITE_UNALIGNED_DATA:
            case FEE_JOB_ERASE_IMMEDIATE:
            case FEE_JOB_ERASE_IMMEDIATE_DONE:
            case FEE_JOB_WRITE_VALIDATE:
            case FEE_JOB_WRITE_DONE:
                {
                    VAR( uint8, AUTOMATIC ) clrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].clrGrp;
                    /* Something wrong in FlashMemory (cluster swap occurs to next write) */
                    Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt = Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt + (2U * FEE_BLOCK_OVERHEAD );
                }
                callNotif= (boolean)TRUE;
                break;
            case FEE_JOB_READ:
            case FEE_JOB_INVAL_BLOCK:
            case FEE_JOB_INVAL_BLOCK_DONE:
            case FEE_JOB_INT_SCAN:
            case FEE_JOB_INT_SCAN_CLR:
            case FEE_JOB_INT_SCAN_CLR_FMT:
            case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            case FEE_JOB_INT_SWAP_BLOCK:
            case FEE_JOB_INT_SWAP_CLR_FMT:
            case FEE_JOB_INT_SWAP_DATA_READ:
            case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            case FEE_JOB_DONE:
            /* @implements         DFEE17005 */
            default:
                callNotif= (boolean)TRUE;
                break;
        }
        
        if (callNotif == (boolean)TRUE)
        {
            /* @implements         DFEE17006 */
            Fee_JobResult = Fls_GetJobResult();
    
            /* @implements         DFEE17007 */
            if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
            {
                /* No notifications from internal jobs */
                /* @implements         DFEE17008 */
                Fee_ModuleStatus = MEMIF_IDLE;
            }
            else
            {
                /* @implements         DFEE17009 */
                Fee_ModuleStatus = MEMIF_IDLE;
                
                /* Call job error notification function */
                /* @implements         DFEE17010 */
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
        }
    }
}

/** 
* @brief        Service to handle the requested read / write / erase jobs 
*               respectively the internal management operations.
* @details      The function shall asynchronously handle the requested 
*               read / write / erase jobs respectively the internal management operations. 
*               The function shall check, whether 
*               the block requested for reading has been invalidated by the 
*               upper layer module. 
*               If so, the function shall set the job result to 
*               MEMIF_BLOCK_INVALID and call the error notification routine 
*               of the upper layer if configured.
*               The function shall check the consistency of the logical block 
*               being read before notifying the caller. If an inconsistency 
*               of the read data is detected, the function 
*               shall set the job result to MEMIF_BLOCK_INCONSISTENT and call 
*               the error notification routine of the upper layer.  
* @pre          The module must be initialized.
* @note         The function Autosar Service ID[hex]: 0x12.
*
* @api  
*    
* @implements   DFEE03018
*
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_MainFunction( void )
{
/* @implements         DFEE18001, DFEE18008, DFEE18009 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_MAINFUNCTION_ID, 
            FEE_E_UNINIT );
    }
    else
    { 
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* @implements         DFEE18002 */
        if( MEMIF_JOB_PENDING == Fee_JobResult )
        {
        
            /* @implements         DFEE18003 */
            switch( Fee_Job )
            {
                /* for all the following jobs subsequent jobs will be called in Fee job schedule
                   function based on Job */
                case FEE_JOB_INT_SCAN:
                case FEE_JOB_READ:
                case FEE_JOB_WRITE:
                case FEE_JOB_INVAL_BLOCK:
                case FEE_JOB_ERASE_IMMEDIATE:
                    /* @implements  DFEE18010 */
                    Fee_JobResult = Fee_JobSchedule();
                    break;
               /* for all the following jobs job end or job error notification will be called
                  based on the job result  */
                case FEE_JOB_WRITE_DATA:
                case FEE_JOB_WRITE_UNALIGNED_DATA:
                case FEE_JOB_WRITE_VALIDATE:
                case FEE_JOB_WRITE_DONE:
                case FEE_JOB_INVAL_BLOCK_DONE:
                case FEE_JOB_ERASE_IMMEDIATE_DONE:
                case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
                case FEE_JOB_INT_SCAN_CLR:
                case FEE_JOB_INT_SCAN_CLR_FMT:
                case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
                case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
                case FEE_JOB_INT_SWAP_BLOCK:
                case FEE_JOB_INT_SWAP_CLR_FMT:
                case FEE_JOB_INT_SWAP_DATA_READ:
                case FEE_JOB_INT_SWAP_DATA_WRITE:
                case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
                case FEE_JOB_DONE:
                default:
                    /* Internal or subsequent job */
                    break;
            }
                    
            /* @implements         DFEE18004 */
            if( MEMIF_JOB_PENDING == Fee_JobResult )
            {
                /* Nothing to do */
            }
            /* @implements         DFEE18005 */
            else if( MEMIF_JOB_OK == Fee_JobResult )
            {
                /* @implements         DFEE18006 */
                if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_ModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_ModuleStatus = MEMIF_IDLE;

                    /* Call job end notification function */
                    /* @implements         DFEE18011 */
                    FEE_NVM_JOB_END_NOTIFICATION
                }
            }
            else
            {
                /* @implements         DFEE18007 */
                if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_ModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_ModuleStatus = MEMIF_IDLE;
                    
                    /* Call job error notification function */
                    /* @implements         DFEE18012 */
                    FEE_NVM_JOB_ERROR_NOTIFICATION
                }
            }
        }
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
}

/** 
* @brief        Service to read runtime information in the selected cluster. 
*   
* @param[in]    clrGrpIndex    Index of the selected cluster group

* @return       Fee_ClusterGroupRuntimeInfoType 
* @retval       current cluster total size 
* @retval       current cluster available space. 
* @retval       the block header overhead (blk header, valid flag and inval flag), 
* @retval       the virtual page size (the size of an allocation unit) 
* @retval       number of cluster swap already performed 
*   
* @pre          The module must be initialized, not busy and clrGrpIndex must be valid 
*               
* @api   
* 
* @implements   DFEE03083
* 
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fee_ClusterGroupRuntimeInfoType, FEE_CODE ) Fee_GetRunTimeInfo( 
    VAR( uint8, AUTOMATIC ) clrGrpIndex    ) 
{ 
    VAR( Fee_ClusterGroupRuntimeInfoType, AUTOMATIC ) clrGrpRTInfo= { (Fls_AddressType)0,
                                                                      (Fls_AddressType)0,
                                                                      (uint8)0,
                                                                      (uint8)0,
                                                                      (uint32)0 };
    
    /* DET Check for cluster group should be added: 
        - INITIALIZED driver 
        - BUSY and BUSY_INTERNAL driver 
        - Cluster group valid 
    */
    /* @implements            DFEE40002, DFEE40011 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
    /* @implements            DFEE40001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    /* @implements            DFEE40003, DFEE40012 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements            DFEE40004, DFEE40013 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY_INTERNAL );
    }
    /* Cluster group index in valid range */
    /* @implements            DFEE40005, DFEE40014 */
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= clrGrpIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_CLUSTER_GROUP_IDX );
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
        /* Get active cluster index for selected cluster group */
        VAR( uint32, AUTOMATIC ) ActiveClrIndex = Fee_ClrGrpInfo[clrGrpIndex ].actClr;
        
        /* Size of the active cluster in selected cluster group */
        /* @implements DFEE40006 */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only 
        allowed form of pointer arithmetic. */
        clrGrpRTInfo.clusterTotalSpace = Fee_ClrGrps[clrGrpIndex ].clrPtr[ActiveClrIndex ].length; 

        /* @implements DFEE40007 */
        clrGrpRTInfo.clusterFreeSpace = 
                (Fee_ClrGrpInfo[clrGrpIndex ].dataAddrIt - 
                (Fee_ClrGrpInfo[clrGrpIndex ].hdrAddrIt + FEE_BLOCK_OVERHEAD));
        
        /* @implements DFEE40008 */
        clrGrpRTInfo.blockHeaderOverhead  = FEE_CLUSTER_OVERHEAD; 
        
        /* @implements DFEE40009 */
        clrGrpRTInfo.virtualPageSize = FEE_VIRTUAL_PAGE_SIZE; 

        /* @implements DFEE40010 */
        clrGrpRTInfo.numberOfSwap = Fee_ClrGrpInfo[clrGrpIndex ].actClrID - 1U;
    }
    /* @violates @ref Fee_c_REF_10 All automatic variables shall have been assigned a value before being used */
    return (clrGrpRTInfo); 
}

/** 
* @brief        Service to prepare the driver for a cluster swap in the selected cluster group. 
* 
* @detailes     While the computed amount of memory is allocated as a result of Fee_Write 
*               call for plain data blocks, for immediate data blocks memory gets completely 
*               pre-allocated through Fee_EraseImmediateBlock function (i.e. Fee_Write does 
*               not change the remaining space). 
*               As a result, swaps triggered by the planned Fee_ForceSwapOnNextWrite function 
*               behave the same way, or in other words, an operation that really activates the 
*               pysical swap must be either Fee_Write on plain FEE block or 
*               Fee_EraseImmediateBlock on immediate data block. 
*   
* @param[in]    clrGrpIndex    Index of the selected cluster group 

* @return       Std_ReturnType 
* @retval       E_NOT_OK, module is not initialized, busy or clrGrpIndex is not in the 
*                         valid range. 
* @retval       E_OK,     No more space available in the selected cluster.
*   
* @pre          The module must be initialized, not busy and clrGrpIndex must be valid.
* 
* @api   
* 
* @implements   DFEE03084
* 
* @note         As this API manipulates the internal driver state, it has to be claimed 
*               non-reentrant and colliding with other FEE ASR APIs 
* 
*/ 
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite ( 
    VAR( uint8, AUTOMATIC ) clrGrpIndex    ) 
{ 
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK; 

    /* DET Check for cluster group should be added: 
        - INITIALIZED driver 
        - BUSY and BUSY_INTERNAL driver 
        - Cluster group valid 
    */
    
    /* @implements            DFEE41002, DFEE41007 */
    if( MEMIF_UNINIT == Fee_ModuleStatus )
    {
    /* @implements            DFEE41001 */
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements            DFEE41003, DFEE41008 */
    else if( MEMIF_BUSY == Fee_ModuleStatus )
    {
#if( FEE_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* @implements            DFEE41004, DFEE41009 */
    else if( MEMIF_BUSY_INTERNAL == Fee_ModuleStatus )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY_INTERNAL );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Cluster group index in valid range */
    /* @implements            DFEE41005, DFEE41010 */
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= clrGrpIndex )
    {
        Det_ReportError( FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_CLUSTER_GROUP_IDX );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
        /* @implements DFEE41006 */
        Fee_ClrGrpInfo[clrGrpIndex].dataAddrIt = 
            Fee_ClrGrpInfo[clrGrpIndex].hdrAddrIt + (2U * FEE_BLOCK_OVERHEAD ); 

    }

    return( RetVal );
}

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
