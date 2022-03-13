/**
 *     @file    Icu_LLD.c
 *     @version 1.0.1
 *
 *     @brief   AUTOSAR Icu - ICU Driver LLD source file.
 *     @details ICU driver source file, containing the LLD variables and functions that are used by
 *              the ICU driver.
 *
 *     @addtogroup ICU_MODULE
 *     @{
*/
/*==================================================================================================
* ==================================================================================================*/

/**
 * @file    Icu_LLD.c
 * @remarks Implements DICU02601
*/

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
* 
* @section Icu_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
* @section Icu_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or
* unspecified behaviour.
* 
* @section Icu_LLD_c_REF_4 
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information that
* information must be tested.
* In this case the function does not return error information  and the information returned
* is not relevand
*
* @section Icu_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form 
* of pointer arithmetic.
* The violation occurs because the variables are defined as per Autosar API specifications.
*
* @section Icu_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Icu_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 12.4, The rigth hand operand of a logical && or || shall not
* containt side effects. This is not a violation since the function at the rigth side of 
* the logical operator only reads a status bit.
*
* @section Icu_LLD_c_REF_9
* Violates MISRA 2004 Advisory Rule 12.11, Evaluation of constant unsigned integer expressions
* should not lead to wrap-around.
* 
* @section Icu_LLD_c_REF_10
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall 
* not be permitted.
*
* @section Icu_LLD_c_REF_11
* Violates MISRA 2004 Required Rule 12.4, The right hand operand of a logical && or || operator 
* shall not contain side effects.
*
* @section Icu_LLD_c_REF_12
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type..
*
* @section Icu_LLD_c_REF_13
* Violates MISRA 2004 Required Rule 12.9, The unary minus operator shall not be applied to
* an expression whose underlying type is unsigned. This Violation cannot be fixed as we need
* to point to the beginning of buffer once end is reached. We need 2's compliment of the
* signed number.
*
* @section Icu_LLD_c_REF_14
* Violates MISRA 2004 Advisory Rule 11.4,
* A cast should not be performed between a pointer to object type and a different pointer
* to object type.Casts between (uint8*) and (uint32*) are used for optimizing the memory
* accesses.
*
*@section Icu_LLD_c_REF_15
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Icu_LLD_c_REF_16
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one 
* and only one file.
*
* @section Icu_LLD_c_REF_17
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be 
* implicitly converted to a different underlying type if:
* a) it is not a conversion to a wider integer type of the same
* signedness, or
* b) the expression is complex, or
* c) the expression is not constant and is a function argument, or
* d) the expression is not constant and is a return expression.
*
* @section Icu_LLD_c_REF_18
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may 
* only be cast to a type that is narrower and of the same signedness as the underlying
* type of the expression.
*
* @section Icu_LLD_c_REF_19
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/
/*
 * @violates @ref Icu_LLD_c_REF_2  MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file
 *       being included twice
*/
/* @implements DICU02601 */

#include "Icu.h"
#include "Icu_LLD.h"
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_eMIOS_LLD.h"
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_Siul_LLD.h"
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_WKPU_LLD.h"
#include "Reg_Macros.h"
#include "EcuM.h"
#include "SchM_Icu.h"
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys_eMIOS.h"
#include "Reg_eSys_eMIOS_CfgEx.h"
#if(ICU_DMA_SUPPORTED == STD_ON)
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice 
*/
#include "Dma_LLD.h"
#include "Reg_eSys_DMA.h"
#endif

/*==================================================================================================
 *                                         LOCAL MACROS
==================================================================================================*/

/* @implements     DICU02407, DICU02406, DICU02405, DICU02404, DICU02403, DICU02402, DICU02401 */
#define ICU_LLD_VENDOR_ID_C                     43
/*
* @violates @ref Icu_LLD_c_REF_6 External function could be made static.
*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement, 
*/
#define ICU_LLD_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Icu_LLD_c_REF_6 External function could be made static.
*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement, 
*/ 
#define ICU_LLD_AR_RELEASE_MINOR_VERSION_C      0
/*
* @violates @ref Icu_LLD_c_REF_6 External function could be made static.
*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement, 
*/ 
#define ICU_LLD_AR_RELEASE_REVISION_VERSION_C   3

#define ICU_LLD_SW_MAJOR_VERSION_C              1
#define ICU_LLD_SW_MINOR_VERSION_C              0
#define ICU_LLD_SW_PATCH_VERSION_C              1
/**@}*/

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_LLD_VENDOR_ID_C != ICU_VENDOR_ID)
#error "Icu_LLD.c and Icu.h have different vendor IDs"
#endif

/* Check if source file Icu_LLD.c and Icu.h header file are of the same Autosar version */
    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.c and Icu.h are different"
    #endif
/* Check if source file Icu_LLD.c and Icu.h header file are of the same Software version */
#if ((ICU_LLD_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.c and Icu.h are different"
#endif

#if (ICU_LLD_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Icu_LLD.c and Icu_LLD.h have different vendor IDs"
#endif

/* Check if source file and Icu_LLD header file are of the same Autosar version */
    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.c and Icu_LLD.h are different"
    #endif

/* Check if source file and Icu_LLD header file are of the same Software version */
#if ((ICU_LLD_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.c and Icu_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Icu_LLD.c and EcuM.h file are of the same Autosar version */
    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.c and EcuM.h are different"
    #endif
#endif
/* Check if Icu_LLD.c and Icu_eMIOS_LLD.h file are of the same Autosar version */

    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.c and Icu_eMIOS_LLD.h are different"
    #endif

/* Check if source file and Icu_eMIOS_LLD.h file are of the same Software version */
#if ((ICU_LLD_SW_MAJOR_VERSION_C != ICU_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION_C != ICU_EMIOS_LLD_H_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION_C != ICU_EMIOS_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.c and Icu_eMIOS_LLD.h are different"
#endif
/* Check if Icu_LLD.c and Icu_WKPU_LLD.h file are of the same Autosar version */
    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.c and Icu_WKPU_LLD.h are different"
    #endif

/* Check if source file and Icu_WKPU_LLD.h file are of the same Software version */
#if ((ICU_LLD_SW_MAJOR_VERSION_C != ICU_WKPU_LLD_H_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION_C != ICU_WKPU_LLD_H_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION_C != ICU_WKPU_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.c and Icu_WKPU_LLD.h are different"
#endif


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "MemMap.h"
LOCAL_INLINE\
     FUNC (Icu_ValueType, ICU_CODE) Icu_Read_Counter_Bus(CONST(Icu_ChannelType, AUTOMATIC) Channel);
#if (ICU_DMA_SUPPORTED == STD_ON)
static FUNC (uint32, ICU_CODE) Icu_MeasurePulseWidth( VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                VAR(uint32, AUTOMATIC)BufferValue1,
                                                VAR(uint32, AUTOMATIC)BufferValue2 );
#endif
#define ICU_STOP_SEC_CODE
/* @violates @ref Icu_LLD_c_REF_1 precautions to prevent the contents of a header file
       being included twice
*/
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents of a header file being included twice
*/
#include "MemMap.h"
#endif
/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement, 
*/
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Icu_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*  comments before "#include".
*/
/*
* @violates @ref Icu_LLD_c_REF_2 MISRA 2004 Advisory Rule 19.15, Precautions shall be taken in order
*  to prevent the contents of a header file being included twice
*/

#include "MemMap.h"
/**
  *@{
  *@brief Extern variable declarations
*/
/**
  *@{
  *@brief   Stores actual state and configuration of ICU Channels
  * @implements DICU02024
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(uint8, ICU_VAR) Icu_ChannelState[ICU_MAX_CHANNEL];
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)

/*
@brief Array for saving the initial counter value
*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
volatile VAR(uint8, ICU_VAR) Icu_Int_Counter[ICU_MAX_CHANNEL];
#if (ICU_DMA_SUPPORTED == (STD_ON))
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(uint8,ICU_VAR) Icu_DmaBuffer_Index[ICU_MAX_DMA_CHANNEL];
#endif
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#if (ICU_DMA_SUPPORTED == (STD_ON))
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_Dmabuffertype,ICU_VAR) \
/*
* @violates @ref Icu_LLD_c_REF_16  MISRA-C:2004 Rule 8.8, An external object or function shall be
* declared in one and only one file.
*/
                            Icu_DmaBuffer[ICU_MAX_DMA_CHANNEL][ICU_DMA_MAJORLOOP_COUNT];
#endif
#endif

/*
@brief Saves the current Icu mode
  *@implements DICU01216
*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ModeType, ICU_VAR) Icu_Current_Mode;

#if (ICU_TIMESTAMP_API == STD_ON)
/*
  *@brief Pointer to the buffer-array where the timestamp values shall be placed.
  *@implements DICU01209
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern P2VAR(Icu_ValueType, ICU_VAR, ICU_APPL_DATA) Icu_Buffer[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the size of the external buffer (number of entries)
  *@implements DICU01212
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ValueType, ICU_VAR) Icu_BufferSize[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving Notification interval (number of events).
  *@implements DICU01211
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ValueType, ICU_VAR) Icu_BufferNotify[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the number of notify counts
  *@implements DICU01217
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ValueType, ICU_VAR) Icu_NotifyCount[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the time stamp index
  *@implements DICU01210
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_IndexType, ICU_VAR) Icu_BufferIndex[ICU_MAX_CHANNEL];
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*
  *@brief Array for saving the pulse width of active time
  *@implements DICU01210
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ValueType, ICU_VAR) Icu_ActivePulseWidth[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the period
  *@implements DICU01218
*/
/*
*  @violates @ref Icu_LLD_c_REF_16 Function is declared previously
*/
extern volatile VAR(Icu_ValueType, ICU_VAR) Icu_Period[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the timer start value
  *@implements DICU02416
*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
/* @violates @ref Icu_LLD_c_REF_19 Violates MISRA 2004 Required Rule 8.7,
The object is defined with external linkage but is only used in function*/
volatile VAR(Icu_ValueType, ICU_VAR) Icu_Start[ICU_MAX_CHANNEL];
/*
  *@brief Array for saving the previous pulse with
  *@implements DICU02419
*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
/* @violates @ref Icu_LLD_c_REF_19 Violates MISRA 2004 Required Rule 8.7,
The object is defined with external linkage but is only used in function*/
volatile VAR(Icu_ValueType, ICU_VAR) Icu_CapturedActivePulseWidth[ICU_MAX_CHANNEL];
#endif


#if (ICU_EDGE_COUNT_API == STD_ON)
/*
  *@brief Array for saving the edge count value
  *@implements DICU01037
*/
static volatile VAR(Icu_EdgeNumberType, ICU_VAR) Icu_EdgeCount[ICU_MAX_CHANNEL];
#endif
/**@}*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement, 
*/
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Icu_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_LLD_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_LLD_c_REF_2 MISRA 2004  Advisory Rule 19.15, Precautions shall be taken in
*        order to prevent the contents of a header file being included twice
*/

#include "MemMap.h"
/*================================================================================================*/
/**
  *@brief      Icu driver function that gets the bitfield value in channel state.
  *@details    This function returns the Icu_ChannelState bitfield specified by mask parameter
  *            in an atomic way.
  *
  *@param[in]  numChl  - The index of ICU channel for current configuration structure
  *@param[in]  mask    - bitfield mask
  *
  *@return     Icu_ChannelStateType - Bitfield specified by mask parameter
  *@implements DICU02411
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (Icu_ChannelStateType, ICU_CODE) Icu_LLD_GetBitChState(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                                            Icu_ChannelStateType mask)
{
    VAR(Icu_ChannelStateType, AUTOMATIC) value;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
    {
        value = Icu_ChannelState[numChl] & mask;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();

    return value;
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that sets the bitfield value in channel state.
  *@details    This function sets the Icu_ChannelState bitfield specified by mask parameter in an
  *            atomic way.
  *
  *@param[in]  numChl  - The index of ICU channel for current configuration structure
  *@param[in]  mask    - bitfield mask
  *@implements  DICU02412
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_LLD_SetBitChState(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                                        Icu_ChannelStateType mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
    {
        Icu_ChannelState[numChl] |= mask;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that resets the bitfield value in channel state.
  *@details    This function clears the Icu_ChannelState bitfield specified by mask parameter in an
  *            atomic way.
  *
  *@param[in]  numChl  - The index of ICU channel for current configuration structure
  *@param[in]  mask    - bitfield mask
  *@implements DICU02410
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_LLD_ClearBitChState(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                            Icu_ChannelStateType mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04();
    {
        Icu_ChannelState[numChl] &= ((Icu_ChannelStateType)(~mask));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04();
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that checks if overflow event occured for given eMIOS channel
  *@details    This function returns TRUE if on the given channel an overflow event occurred.
  *
  *@param[in]  numChl  - The index of ICU channel for current configuration structure
  *@param[in]  flags   - bitfield mask
  *
  *@return     boolean
  *             - true -  if an overflow event occurred
  *             - false - if no overflow event has occurred
  *@implements DICU02415
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (boolean, ICU_CODE) Icu_LLD_CheckHwOverflowFlag(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                                VAR(uint32, AUTOMATIC) flags)
{
    boolean result = (boolean)FALSE;
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        result = Icu_eMIOS_LLD_CheckOverflowFlag(flags);
    }

    return result;
}


/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
  *@brief      Icu driver function that initializes the ICU hardware channel.
  *@details    This function initializes a hardware ICU channel
  *
  *@param[in]  tempPtr     - Pointer to configuration structure
  *@param[in]  numChl      - The index of ICU channel for current configuration structure
  *@param[in]  msChannel   - This index relates the Icu Channel number with the respective global
  *                          variable, depending on the measurement mode. Each kind of measurement
  *                          mode has an array(s) in the ICU driver, this index points to the
  *                          corresponding variable within the ICU channel.
  *@implements DICU02013
*/
/*================================================================================================*/
#if ((ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))
FUNC (void, ICU_CODE) Icu_LLD_InitChannel(
                                  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                  VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                  CONST(Icu_ChannelType, AUTOMATIC) msChannel)
#else
FUNC (void, ICU_CODE) Icu_LLD_InitChannel(
                                  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                  VAR(Icu_ChannelType, AUTOMATIC) numChl)
#endif
{
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* The wakeup-capability of a channel shall be disabled
       * This service shall disable all notifications.
       * All ICU channel status shall be set to ICU_IDLE
     */

    /* Clear channel internal state */
    Icu_ChannelState[numChl] =  0x00U;

    /* Store activation edge */
    switch ((tempPtr->Icu_ParamValue & ICU_EDGE_PARAM_MASK) >> ICU_EDGE_PARAM_SHIFT)
    {
        case (uint32)ICU_RISING_EDGE:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RISING);
            break;

        case (uint32)ICU_FALLING_EDGE:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_FALLING);
            break;

        default:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_BOTH_EDGES);
            break;
    }


    /* eMIOS Channel Configuration */
    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
#if (ICU_EDGE_COUNT_API == STD_ON)
        if (ICU_MODE_EDGE_COUNTER == tempPtr->Icu_Channel_Mode)
        {
            Icu_EdgeCount[msChannel] = (Icu_EdgeNumberType)1U;
        }
#endif /* ICU_EDGE_COUNT_API */
#if (ICU_TIMESTAMP_API == STD_ON)
        if (ICU_MODE_TIMESTAMP == tempPtr->Icu_Channel_Mode)
        {
            Icu_Buffer[msChannel] = NULL_PTR;
        }
#endif /* ICU_TIMESTAMP_API */

        if (ICU_MODE_EDGE_COUNTER == tempPtr->Icu_Channel_Mode)
        {
            Icu_eMIOS_LLD_InitChannel(tempPtr->Icu_ParamValue, ICU_eMIOS_CHANNEL(hwChannel));
        }
        else if (ICU_MODE_SIGNAL_EDGE_DETECT == tempPtr->Icu_Channel_Mode)
        {
            Icu_eMIOS_LLD_InitChannel(tempPtr->Icu_ParamValue, ICU_eMIOS_CHANNEL(hwChannel));
        }
        else
        {
            Icu_eMIOS_LLD_InitChannel(tempPtr->Icu_ParamValue, ICU_eMIOS_CHANNEL(hwChannel));
        }
    }
    /* External Interrupt Channel Configuration */
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_InitChannel(tempPtr->Icu_ParamValue,
                               (SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
    /* WKPU Interrupt Channel Configuration */
    else
    {
        Icu_WKPU_LLD_InitChannel(tempPtr->Icu_ParamValue, 
                                (WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel));
    }
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that de-initializes the ICU hardware channel.
  *@details    This function de-initializes the ICU hardware channel.
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@implements DICU02002
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DeInitChannel(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* eMIOS Channel Configuration */
    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        VAR(boolean,AUTOMATIC) reg_EMIOSCNT_available = (boolean)FALSE;
        VAR(boolean,AUTOMATIC) reg_EMIOSB_available   = (boolean)FALSE;
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
        if (ICU_MODE_EDGE_COUNTER == Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Mode)
        {
            reg_EMIOSCNT_available = (boolean)TRUE;
        }
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
        else if (ICU_MODE_SIGNAL_MEASUREMENT ==
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/        
                                         Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Mode)
        {
            reg_EMIOSB_available = (boolean)TRUE;
        }
        else
        {
        /*For Misra Compliance*/
        }
        Icu_eMIOS_LLD_DeInitChannel(ICU_eMIOS_CHANNEL(hwChannel), reg_EMIOSCNT_available,
                                                                  reg_EMIOSB_available);
    }
    /* External Interrupt Channel Configuration */
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_DeInitChannel((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
    /* WKPU Interrupt Channel Configuration */
    else
    {
        Icu_WKPU_LLD_DeInitChannel((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel));
    }
}

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
  *@brief      Icu driver function that sets the ICU hardware channel into sleep mode.
  *@details    This function sets the ICU hardware channels (eMIOS, SIUL or WKUP) into SLEEP mode
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@param[in]  active - ICU channel is active during SLEEP mode (wakeup was enabled)
  *@implements DICU02018
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetSleepMode(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                           VAR(boolean, AUTOMATIC) active)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/    
        Icu_eMIOS_LLD_SetSleepMode(ICU_eMIOS_CHANNEL(hwChannel), active, Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Mode);
    }
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_SetSleepMode((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel), active);
    }
    else
    {
        Icu_WKPU_LLD_SetSleepMode((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel), active);
    }
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that sets the ICU hardware channel into NORMAL mode.
  *@details    This function sets the ICU hardware channels (eMIOS, SIUL or WKUP) into NORMAL mode,
  *            Enables the notification for the channel.
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@param[in]  active - ICU channel is active during NORMAL mode (notification was enabled)
  *@implements DICU02017
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetNormalMode(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                            VAR(boolean, AUTOMATIC) active)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/    
        Icu_eMIOS_LLD_SetNormalMode(ICU_eMIOS_CHANNEL(hwChannel), active,Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Mode);
    }
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_SetNormalMode((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel), active);
    }
    else
    {
        Icu_WKPU_LLD_SetNormalMode((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel), active);
    }
}
#endif  /* ICU_SET_MODE_API */

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/*================================================================================================*/
/**
  *@brief      Icu driver function that disables the wakeup for channel.
  *@details    This function disables wakeup for ICU hardware channels.
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@implements DICU02005
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_WKUP);
}
#endif  /* ICU_DISABLE_WAKEUP_API */

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/*================================================================================================*/
/**
  *@brief      Icu driver function that enables the wakeup for channel.
  *@details    This function enables wakeup for ICU hardware channels.
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@implements DICU02008
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableWakeup(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_WKUP);
}
#endif  /* ICU_ENABLE_WAKEUP_API */

/*================================================================================================*/
/**
  *@brief      Icu driver function that sets activation conditiond for channel with requested
  *            activation type.
  *@details    This function sets the requested Activation for the channels (eMIOS, SIUL or WKUP)
  *
  *@param[in]  numChl     - The index of ICU channel for current configuration structure
  *@param[in]  Activation - the type of activation for the ICU channel.
  *@implements DICU02016
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                     VAR(Icu_ActivationType, AUTOMATIC) Activation)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* Clear IDLE status */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_IDLE);

    /* Clear activation bitfield */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_BOTH_EDGES);

    switch (Activation)
    {
        case ICU_RISING_EDGE:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RISING);
            break;

        case ICU_FALLING_EDGE:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_FALLING);
            break;

        default:
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_BOTH_EDGES);
            break;
    }

    /* eMIOS Channel Configuration */
    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        Icu_eMIOS_LLD_SetActivationCondition(ICU_eMIOS_CHANNEL(hwChannel),
                                         (eMIOS_ActivationType)Activation);
    }
    /* External Interrupt Channel Configuration */
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_SetActivationCondition((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel),
                                            (SIUL_ActivationType)Activation);
    }
    else
    {
        Icu_WKPU_LLD_SetActivationCondition((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel),
                                        (WKPU_ActivationType)Activation);
    }
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that disables the notification for channel.
  *@details    This function disables notification for an ICU Hardware Channel.
  *            For disabling notification, for some ICU channels, the interrupt
  *            for the channel must be also disabled
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@implements DICU02004
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_NOTIFICATION);
}

/*================================================================================================*/
/**
  *@brief      Icu driver function that enables the notification for channel.
  *@details    This function enables notification for an ICU Hardware Channel.
  *            For enabling notifications for some ICU channels, the interrupt
  *            for the channel must be also re-enabled
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *@implements DICU02007
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_NOTIFICATION);
}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that gets the input state of ICU hardware channel.
 * @details    This function gets the state of ICU channel (eMIOS, SIUL or WKUP)
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 * @return     Icu_InputStateType
 *              - ICU_ACTIVE - An activation edge has been detected
 *              - ICU_IDLE - No activation edge has been detected.
 *@implements  DICU02011
*/
/*================================================================================================*/
FUNC (Icu_InputStateType, ICU_CODE) Icu_LLD_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    VAR(Icu_InputStateType, AUTOMATIC) tempReturn = ICU_IDLE;
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

        /* If active edge detected already and status updated in ISR, this first condition MAY
           result true */
        if (ICU_CHANNEL_STATE_IDLE == Icu_LLD_GetBitChState(numChl, ICU_CHANNEL_STATE_IDLE))
        {
            tempReturn = ICU_ACTIVE;

            /* Clear IDLE status */
            Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
        }
        else if  (ICU_MODE_SIGNAL_EDGE_DETECT == 
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/        
                         Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Mode)

        {
            if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
            {
                if (Icu_eMIOS_LLD_GetInputState(ICU_eMIOS_CHANNEL(hwChannel)))
                {
                    tempReturn = ICU_ACTIVE;
                }
            }
            else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
            {
                if (Icu_Siul_LLD_GetInputState((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel)))
                {
                    tempReturn = ICU_ACTIVE;
                }
            }
            else
            {
                if (Icu_WKPU_LLD_GetInputState((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel)))
                {
                    tempReturn = ICU_ACTIVE;
                }
            }

        }
        else
        {
          /*For Misra compliance*/
        }

    return (tempReturn);
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that starts the time stamp of ICU hardware channel.
 * @details    This function starts the time stamp measurement of ICU channel.
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @param[in]  msChannel - The index of Logical ICU channel
 * @param[in]  BufferPtr - Pointer to the buffer
 * @param[in]  BufferSize - Size of buffer
 * @param[in]  NotifyInterval - Notification interval time
 * @implements DICU02020
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StartTimestamp(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                             CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                             P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr,
                                             VAR(uint16, AUTOMATIC) BufferSize,
                                             VAR(uint16, AUTOMATIC) NotifyInterval)
{
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
#if(ICU_DMA_SUPPORTED == STD_ON)
        CONST(uint8, ICU_CONST) mIdx = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
        VAR(uint32, AUTOMATIC) dma_params;
        VAR(Icu_MeasurementSubModeType, AUTOMATIC) buffer_type;
        VAR(uint8, AUTOMATIC) dmaChannel;
        VAR(uint32, AUTOMATIC) dlast_sga;
        P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA) IcuDMA;
#endif

    /* Time stamp is running */
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05();
    {
        Icu_Buffer[msChannel]       = BufferPtr;
        Icu_BufferSize[msChannel]   = BufferSize;
        Icu_BufferNotify[msChannel] = NotifyInterval;
        Icu_NotifyCount[msChannel]  = 0U;
        Icu_BufferIndex[msChannel]  = 0U;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05();

    #if(ICU_DMA_SUPPORTED == STD_ON)
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/    
   dmaChannel = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Channel;
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/  
   IcuDMA = (P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA))DMA_TCD(dmaChannel);
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
   if(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Enable == (boolean)TRUE)    
   {
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/   
     buffer_type = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Property;

          if(0U == NotifyInterval)
                {
                  if(buffer_type == (uint8) ICU_LINEAR_BUFFER)
                   {
               /*Set INT_MAJ =1 and DLAST_SGA =0 */
                           dma_params = (DMA_TCD_DISABLE_REQ | DMA_TCD_INT_MAJOR);
                        }
                  else
                        {
                           /* DMA interrupt is not required since NOTIFY INTERVAL is zero & buffer
                              is circular */
                           dma_params = ICU_DMA_UPDATE_DLAST_SGA;
                        }
                }
            else if(BufferSize == NotifyInterval)
                {
                        if(buffer_type == (uint8) ICU_LINEAR_BUFFER)
                        {
                 /*Set D_REQ =1 and INT_MAJ =1*/
                                dma_params = (DMA_TCD_DISABLE_REQ | DMA_TCD_INT_MAJOR);

                        }
                        else
                        {
                /*Set INT_MAJ =1 and DLAST_SGA =0 */
                                dma_params = (DMA_TCD_INT_MAJOR | ICU_DMA_UPDATE_DLAST_SGA);
                        }
                }
                else if((BufferSize - NotifyInterval) == NotifyInterval)
                {
                        if(buffer_type == (uint8) ICU_LINEAR_BUFFER)
                        {
                /*Set INT_MAJ =1,INT_HALF=1 and DLAST_SGA =0 */
                                dma_params = \
                                       (DMA_TCD_DISABLE_REQ | DMA_TCD_INT_MAJOR | DMA_TCD_INT_HALF);
                        }
                        else
                        {
                /*Set INT_MAJ =1,INT_HALF=1 and DLAST_SGA =0 */
                                dma_params = \
                                  (DMA_TCD_INT_MAJOR | DMA_TCD_INT_HALF | ICU_DMA_UPDATE_DLAST_SGA);
                        }
                }
                else
                {
                           /* Buffer size is not multiple of notify interval or it is multiple of
                              more than twice */
                           dma_params = (DMA_TCD_DISABLE_REQ | DMA_TCD_INT_MAJOR);
                           BufferSize = NotifyInterval;
                }

        if((dma_params & ICU_DMA_UPDATE_DLAST_SGA) == 0U)
        {
            dlast_sga = 0U;
        }
        else
        {
          /*
          * @violates @ref Icu_LLD_c_REF_13 The unary minus operator shall not be applied to an
          * expression whose underlying type is unsigned. This Violation cannot be fixed as we
          * need to point to the beginning of buffer once end is reached. We need 2's compliment
          * of the signed number.
          */                 
            dlast_sga = (-((uint32)BufferSize * (uint32)2U));
        }
    /*
    * @violates @ref Icu_LLD_c_REF_14 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
       Dma_setup_descriptor((DmaTcdPointerType)IcuDMA,
                             (EMIOS_CADR(mIdx, chIdx)+2U),/* src_addr */
                             DMA_DATA_TRANSFER_16_BIT,
                             DMA_DATA_TRANSFER_16_BIT,
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16)0x00U,/* src_offset is always 0*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16)0x02U,/*Number of bytes to transfer*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint32)0x00U,/*source address last adjustment*/
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint32) BufferPtr, /* dest address */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16) BufferSize, /*Major loop count*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16)0x02U, /* dest offset */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint32) dlast_sga, /*destination address last adjustment*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16) BufferSize, /* beg maj iter cnt */
                             (uint8)  0u, /* no major linked channel */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint8) (dma_params)); /*Dma interrupt always enabled*/
    }
#endif
    Icu_eMIOS_LLD_StartTimestamp(ICU_eMIOS_CHANNEL(hwChannel));
#if(ICU_DMA_SUPPORTED == STD_ON)
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
   if(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Enable == (boolean)TRUE)
   {
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                    
        Dma_start_channel(dmaChannel);
        }
#endif
}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that stops the time stamp of ICU hardware channel.
 * @details    This function stops the time stamp measurement of ICU channel.
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02022
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* Stop time stamp channel */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    Icu_eMIOS_LLD_StopTimestamp(ICU_eMIOS_CHANNEL(hwChannel));
}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that gets the time stamp index of ICU logical channel.
 * @details    This function gets the time stamp measurement index of ICU logical channel.
 *             If Buffer pointer of channel is NULL_PTR then it returns value as 0 else
 *             it returns the value of time stamp index.
 *
 * @param[in]  msChannel - The index of ICU channel for current configuration structure
 *
 * @return     Icu_IndexType - Timestamp index
 * @implements DICU02012
*/
/*================================================================================================*/
#if (ICU_DMA_SUPPORTED == STD_ON)
    FUNC (Icu_IndexType, ICU_CODE) Icu_LLD_GetTimestampIndex(
                                                       CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                                       VAR(Icu_ChannelType, AUTOMATIC) Channel)
#else
FUNC (Icu_IndexType, ICU_CODE) Icu_LLD_GetTimestampIndex(
                                                       CONST(Icu_ChannelType, ICU_CONST) msChannel)
#endif
{
    VAR(Icu_IndexType, AUTOMATIC) tempIndex = 0U;
    #if (ICU_DMA_SUPPORTED == STD_ON)
    VAR(uint8, AUTOMATIC) tempDMAchannel;
        VAR(Icu_MeasurementSubModeType, AUTOMATIC) buffer_type;
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                
        tempDMAchannel = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_DMA_Channel;
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                
        buffer_type = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_Channel_Property;
        #endif
    /* The service shall return "0" in case the service is called before
       * Icu_StartTimestamp (no buffer is defined in this case).
     */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06();
    {
        if (NULL_PTR == Icu_Buffer[msChannel])
        {
            tempIndex = 0U;
        }
        else
        {
            #if (ICU_DMA_SUPPORTED == STD_ON)
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                        
            if(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_DMA_Enable == (boolean)TRUE)
                         {
                          /*read the DMA interation values*/
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                   
                tempIndex = (Icu_IndexType)(ICU_LLM_READ_MAJORCOUNT_BITER(tempDMAchannel) - \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */        
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
/* @violates @ref Icu_LLD_c_REF_18 The value of a complex expression cast to a type that is narrower*/
                                                     ICU_LLM_READ_MAJORCOUNT_CITER(tempDMAchannel));
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/                                                                                                           
                if( (Icu_BufferSize[msChannel] -  Icu_BufferNotify[msChannel]) !=  \
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/                                
                                                                      Icu_BufferNotify[msChannel])
                {
                                    /* return timestamp index */
                    tempIndex += Icu_BufferIndex[msChannel];
                                }
                            if((buffer_type == (uint8) ICU_LINEAR_BUFFER) && (tempIndex==0U))
                                {
                    tempIndex = Icu_BufferIndex[msChannel];
                                }
                         }
                     else
             #endif
             {
                /* return timestamp index */
                tempIndex = Icu_BufferIndex[msChannel];
             }
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06();

    return (tempIndex);
}
#endif  /* ICU_TIMESTAMP_API */

#if ((ICU_SET_MODE_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))
/*================================================================================================*/
/**
  *@brief      Icu driver function that gets the status of ICU hardware channel.
  *@details    This function returns TRUE if channel is running else returns FALSE.
  *
  *@param[in]  numChl - The index of ICU channel for current configuration structure
  *
  *@return     boolean
  *             - true - if the given channel is running
  *             - false - if the channel is in idle state
  * @implements DICU02001
*/
/*================================================================================================*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
FUNC (boolean, ICU_CODE) Icu_LLD_Channel_Get_Status(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    return (boolean)((ICU_CHANNEL_STATE_RUNNING == Icu_LLD_GetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING)) ? TRUE : FALSE);
}

#endif /*((ICU_SET_MODE_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))*/
#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that resets the edge counter measurement of ICU channel.
 * @details    This function:
 *              - Clears the overflow flag
 *              - Resets the edge counter measurement of ICU hardware channel
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02014
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ResetEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];

    /* Clear overflow flag */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_OVERFLOW);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07();
    {
        /* Sync. variable with internal hardware eMIOS module counter */
        Icu_EdgeCount[msChannel] = (Icu_EdgeNumberType)EMIOS_INIT_CCNTR;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07();

    Icu_eMIOS_LLD_ResetEdgeCount(ICU_eMIOS_CHANNEL(hwChannel));
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that enables the edge counter measurement of ICU channel.
 * @details    This function enables the edge counter measurement of ICU hardware channel
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02006
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];

    /* Edge counting enabled */
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    Icu_eMIOS_LLD_EnableEdgeCount(ICU_eMIOS_CHANNEL(hwChannel),(uint32)Icu_EdgeCount[msChannel]);
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that disables the edge counter measurement of ICU channel.
 * @details    This function disables the edge counter measurement of ICU hardware channel
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02003
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*     pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];
    VAR(uint32, AUTOMATIC) value = 0U;

/*
* @violates @ref Icu_LLD_c_REF_3 MISRA 2004 Advisory Rule 1.2, No reliance shall be placed on
*      undefined or unspecified behavior */

    Icu_eMIOS_LLD_DisableEdgeCount(ICU_eMIOS_CHANNEL(hwChannel), &value);


    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08();
    {
        Icu_EdgeCount[msChannel] = ((Icu_EdgeNumberType)value);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08();

    /* Edge counting stopped */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function thatgets edge counter measurement of ICU channel.
 * @details    his function returns counter value (the number of counter edges) of ICU channel
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 * @return     Icu_EdgeNumberType - Counted edges number
 * @implements  DICU02010
*/
/*================================================================================================*/
FUNC (Icu_EdgeNumberType, ICU_CODE) Icu_LLD_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];
    VAR(Icu_EdgeNumberType, AUTOMATIC) tempEdge = 0U;

    /* If MCB is activated, read must come from the counter register otherwise it must come from
       sync. variable */
    if (Icu_LLD_Channel_Get_Status(numChl))
    {
        tempEdge = ((Icu_EdgeNumberType)Icu_eMIOS_LLD_GetEdgeNumbers(hwChannel) - (1U));
    }
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
        {
             tempEdge = ((Icu_EdgeNumberType)Icu_EdgeCount[msChannel] - (1U));
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();
    }

    return (tempEdge);
}
#endif  /* ICU_EDGE_COUNT_API */

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/*================================================================================================*/
/**
 * @brief      Icu driver function that checks overflow flag status of ICU channel
 * @details    This function returns the overflow status for the given channel and
 *             resets the channel status flag
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 * @return     boolean
 *              - true - if an overflow event occurred for the given channel
 *              - false - if no overflow event occurred for the given channel
 * @implements DICU02009
*/
/*================================================================================================*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
FUNC (boolean, ICU_CODE) Icu_LLD_Get_Overflow(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    VAR(boolean, AUTOMATIC) result;
    result = (boolean)((Icu_LLD_GetBitChState
                                        (numChl, ICU_CHANNEL_STATE_OVERFLOW) != 0U) ? TRUE : FALSE);

    if (result)
    {
        /* Reset overflow status flag of the logic channel */
        Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_OVERFLOW);
    }

    return result;
}
#endif /* ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) ) */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that starts the signal measurement of ICU channel.
 * @details    This function:
 *             - Configures the Activation type depends on tempProperty value
 *             - starts the signal measurement of ICU channel.
 *
 *
 * @param[in]  tempPtr - Buffer pointer
 * @param[in]  hwChannel - ICU hardware channel number
 * @param[in]  tempProperty - Time measurement type (HIGH or LOW)
 * @param[in]  msChannel - The index of ICU logical channel
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02019
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StartSignalMeasurement(
                                  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                  CONST(Icu_ChannelType, AUTOMATIC) hwChannel,
                                  VAR(Icu_ParamType, AUTOMATIC) tempProperty,
                                  CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                  VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    #if(ICU_DMA_SUPPORTED == STD_ON)
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                
        VAR(uint8, AUTOMATIC) DmaChannelIndex = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Channel;
        VAR(uint8, AUTOMATIC) loopCount = 4U;
        VAR(uint8, AUTOMATIC) index;
        VAR(uint8, AUTOMATIC) inputStateInGpio = 0U;
        VAR(uint8, AUTOMATIC) inputStateInSaic = 0U;
        VAR(uint32, AUTOMATIC) dma_flags;
        VAR(uint8, AUTOMATIC) majorLoopCount =  0U;
        VAR(uint32, AUTOMATIC) dlast_sga;
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                
        VAR(uint8, AUTOMATIC) msDmaChannel = Icu_Cfg_Ptr->Icu_DmaChannelIndex[DmaChannelIndex];
        P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA) IcuDMA;
    #endif
    eMIOS_ActivationType activation = EMIOS_RISING_EDGE;
    eMIOS_OperationMode  opmode = (eMIOS_OperationMode)((tempPtr->Icu_ParamValue & ICU_EMIOS_UC_MODE_PARAM_MASK) >> ICU_EMIOS_UC_MODE_PARAM_SHIFT);

    /* Signal measurement is running */
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    /* Clear the previous overflow status flag (if was the case) */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_OVERFLOW);

#if(ICU_DMA_SUPPORTED == STD_ON)
    if(tempPtr->Icu_DMA_Enable)
    {
        /*DMA logical channel index*/
 /* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/  
        IcuDMA = (P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA))DMA_TCD(DmaChannelIndex);
        dma_flags = (DMA_TCD_INT_MAJOR | DMA_TCD_INT_HALF | ICU_DMA_UPDATE_DLAST_SGA);
        /*@violates @ref Icu_LLD_c_REF_10 MISRA 2004 Required Rule,This condition is added to 
        optimize the driver code*/        
        if((dma_flags & ICU_DMA_UPDATE_DLAST_SGA) == 0U)
        {
            dlast_sga = 0U;
        }
        else
        {
          /*
          * @violates @ref Icu_LLD_c_REF_13 The unary minus operator shall not be applied to an
          * expression whose underlying type is unsigned. This Violation cannot be fixed as we
          * need to point to the beginning of buffer once end is reached. We need 2's compliment
          * of the signed number.
          */                  
            dlast_sga =  -(ICU_DMA_MAJORLOOP_COUNT*2U);
        }
        activation = (eMIOS_ActivationType)ICU_BOTH_EDGES;
        #if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
        loopCount = 4U; /* DMA major loop count for high and low time*/
                /*Start the DMA for configured DMA cahnnel*/
    /*
    * @violates @ref Icu_LLD_c_REF_14 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */                        
        Dma_setup_descriptor((DmaTcdPointerType)IcuDMA,/* dma_channel */
                             (EMIOS_CADR(mIdx, chIdx)+2U),/* src_addr */
                             DMA_DATA_TRANSFER_16_BIT,/*Source access transfer size*/
                             DMA_DATA_TRANSFER_16_BIT,/*Destination access transfer size*/
                             (uint16)0x00U,/* src_offset is always 0*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint16)0x02U,/*Number of bytes to transfer*/
                             (uint32)0x00U,/*source address last adjustment*/
                            /*Destination address for DMA transfer*/ 
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */                                                                        
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                        
                             (uint32)&Icu_DmaBuffer[msDmaChannel][0],
                             ICU_DMA_MAJORLOOP_COUNT,/*Major loop count*/
                             (uint16)0x02U, /* dest offset */
                             dlast_sga,/*destination address last adjustment*/
                             ICU_DMA_MAJORLOOP_COUNT,/*Beginning major iteration count*/
                             (uint8)0x0U,/* no major linked channel */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                             (uint8)(dma_flags));
         /*Clear the DMA result buffer for configured DMA channel*/
            for(index=0U;index<loopCount;index++)
            {
                Icu_DmaBuffer[msDmaChannel][index] = (uint16)0;
            }
         /*#if(((ICU_GET_TIME_ELAPSED_API== STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)))*/
            #endif 
        }
#endif /*#if(ICU_DMA_SUPPORTED == STD_ON)*/
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10();
    {
#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
        Icu_ActivePulseWidth[msChannel] = 0U;
        Icu_Period[msChannel] = 0U;
        #if(ICU_DMA_SUPPORTED == STD_ON)
        if(tempPtr->Icu_DMA_Enable)
        {
            inputStateInGpio = Icu_LLD_GetInputLevel(numChl);
            /*Configure the channel in SAIC mode set Interrupt enable bit and DMA bit*/
            REG_RMW32(EMIOS_CCR(mIdx, chIdx),  \
                                  (CCR_FEN_MASK |CCR_DMA_MASK|(CCR_MODE_MASK & CCR_MODE_SAIC)), \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                  
                                   (CCR_FEN_MASK|CCR_DMA_MASK|(CCR_MODE_MASK & CCR_MODE_SAIC)));
            inputStateInSaic = Icu_LLD_GetInputLevel(numChl);
            majorLoopCount =  \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                        
                (uint8)LLM_Get_DMA_CITER(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Channel);
        }
        #endif
#endif
/* ICU_GET_TIME_ELAPSED_API || ICU_GET_DUTY_CYCLE_VALUES_API */
        /* Clear the counter for signal measurement */
        Icu_Int_Counter[msChannel] = 0U;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10();
#if(ICU_DMA_SUPPORTED == STD_ON)
    if(tempPtr->Icu_DMA_Enable)
    {
        if((inputStateInGpio == inputStateInSaic) || ((majorLoopCount == loopCount) && \
                                                   (inputStateInSaic != inputStateInGpio)))
        {
            if(inputStateInSaic == (uint8)0)
            {
                Icu_DmaBuffer_Index[msDmaChannel] = (((tempPtr->Icu_ParamValue & \
                ICU_EDGE_PARAM_MASK)>>ICU_EDGE_PARAM_SHIFT)  ==  (uint32)ICU_RISING_EDGE) ? \
                                                                               (uint8)0  : (uint8)1; 
            }
            else
            {
                Icu_DmaBuffer_Index[msDmaChannel] = (((tempPtr->Icu_ParamValue & \
                ICU_EDGE_PARAM_MASK)>>ICU_EDGE_PARAM_SHIFT)  ==  (uint32)ICU_FALLING_EDGE) ? \
                                                                               (uint8)0  : (uint8)1;
            }
        }
        else
        {
            if(inputStateInSaic == (uint8)0)
            {
                Icu_DmaBuffer_Index[msDmaChannel] = (((tempPtr->Icu_ParamValue & \
                ICU_EDGE_PARAM_MASK)>>ICU_EDGE_PARAM_SHIFT)  ==  (uint32)ICU_RISING_EDGE) ?  \
                                                                               (uint8)1  : (uint8)0; 
            }
            else
            {
                Icu_DmaBuffer_Index[msDmaChannel] = (((tempPtr->Icu_ParamValue & \
                ICU_EDGE_PARAM_MASK)>>ICU_EDGE_PARAM_SHIFT)  ==   (uint32)ICU_FALLING_EDGE) ?  \
                                                                               (uint8)1  : (uint8)0;
            }
        }
    }
    else
#endif
    {
#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    /* Configure channels to measure high and low time */
    if ((uint32)ICU_HIGH_TIME == tempProperty)
    {
        activation = EMIOS_RISING_EDGE;
    }
    else if ((uint32)ICU_LOW_TIME == tempProperty)
    {
        activation = EMIOS_FALLING_EDGE;
    }
    else
#endif /* ICU_GET_TIME_ELAPSED_API== STD_ON */
    {
        /* Set Default Start Edge, signal can be start measured either by falling edge or rising
         * edge */
        if ((Icu_ParamType)((Icu_ParamType)ICU_FALLING_EDGE << ICU_EDGE_PARAM_SHIFT) ==  \
                            (Icu_ParamType)(tempPtr->Icu_ParamValue & ICU_EDGE_PARAM_MASK))
        {
            activation = EMIOS_FALLING_EDGE;
        }
        else
        {
            activation = EMIOS_RISING_EDGE;
        }
    }
    }
    /* Start Signal Measurement */
    Icu_eMIOS_LLD_StartSignalMeasurement(hwChannel, activation, opmode);
#if(ICU_DMA_SUPPORTED == STD_ON)
    if(tempPtr->Icu_DMA_Enable)
    {
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                        
        Dma_start_channel(DmaChannelIndex);
    }
#endif
    /* This service shall reset the state for the given channel to ICU_IDLE. */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that stops the signal measurement of ICU channel.
 * @details    This function stops the signal measurement of ICU channel.
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02021
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* Signal Measurement stopped  */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    Icu_eMIOS_LLD_StopSignalMeasurement(ICU_eMIOS_CHANNEL(hwChannel));
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that handles the signal measurement type interrupt.
 * @details    This service is  called when an  interrupt is recognized  as a Signal  Measurement
 *             type.
 *             There are two branch depending on  the sub-function selected: Duty Cycle or  OTHER.
 *             Duty Cycle requires  an extra  variable, because  three values  are required:
 *             two flanks for active signal time and another flank for the end of the pulse. For
 *             calculating high, low and period is enough with the HW registers.
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 * @implements DICU02413
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_LLD_SignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];
/*            
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
    VAR(Icu_MeasurementSubModeType, AUTOMATIC) measurement_property;
        VAR(uint16, AUTOMATIC) Period;
    VAR(uint16, AUTOMATIC) tempA, tempB;
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    VAR(uint16, AUTOMATIC) previous_value;
    VAR(uint16, AUTOMATIC) pulse_width;
#endif
#if (ICU_DMA_SUPPORTED == STD_ON)
        VAR(uint8, AUTOMATIC) tempDmaChannel;
    VAR(uint8, AUTOMATIC) msDmaChannel;
    VAR(uint8, AUTOMATIC) index0;
    VAR(uint8, AUTOMATIC) index1;
    volatile P2VAR(uint16, AUTOMATIC, ICU_APPL_DATA) dma_buffer;
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                
    tempDmaChannel = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Channel;
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/        
    msDmaChannel = Icu_Cfg_Ptr->Icu_DmaChannelIndex[tempDmaChannel];
#endif
/* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    measurement_property = Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_Property;


    /* Read captured values */
    tempA = (Icu_ValueType)Icu_eMIOS_LLD_GetCaptureRegA(hwChannel);
    tempB = (Icu_ValueType)Icu_eMIOS_LLD_GetCaptureRegB(hwChannel);
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/

    if ((Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_ParamValue & ICU_EMIOS_UC_MODE_PARAM_MASK) == ((Icu_ParamType)EMIOS_UC_IPWM_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT))
    {

        if (((uint32)ICU_HIGH_TIME == measurement_property) || 
                                       ((uint32)ICU_LOW_TIME == measurement_property))
        {
             if (tempA > tempB)
                {
                 Icu_ActivePulseWidth[msChannel] = (Icu_ValueType)(tempA - tempB);
                }
             else     /*Counter overflow Case*/
                {
                 Period = Icu_Read_Counter_Bus(numChl);                                
                 Icu_ActivePulseWidth[msChannel] = (Icu_ValueType)(tempA +  \
                                                ((uint32)Period - tempB));
                }
                 Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
                }

        else
        {
        /* Check if a complete signal was acquired */
            if (0U == Icu_Int_Counter[msChannel])
            {
                /* Mark that the complete signal was acquired */
                Icu_Int_Counter[msChannel] = 1U;
            }
            else
            {
                /* Compute Period of the signal */
                    if (tempB > Icu_Start[msChannel])
                    {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                Icu_Period[msChannel] = tempB - Icu_Start[msChannel];
                    }
                    else     /*Counter overflow Case */
                    {                
                 Period = Icu_Read_Counter_Bus(numChl);                                
                 Icu_Period[msChannel] = (Icu_ValueType)\
                     (tempB + ((uint32)Period - Icu_Start[msChannel]));
                    }                    
                Icu_ActivePulseWidth[msChannel] = Icu_CapturedActivePulseWidth[msChannel];
                Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
                }
            }
            if (tempA > tempB)
            {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
            Icu_CapturedActivePulseWidth[msChannel] = tempA - tempB;
            }    
            else     /*Counter overflow Case */
            {            
              Period = Icu_Read_Counter_Bus(numChl);                         
              Icu_CapturedActivePulseWidth[msChannel] = (Icu_ValueType)\
                                   (tempA + ((uint32)Period - tempB));
        }
                Icu_Start[msChannel]  = (Icu_ValueType)tempB;
    }
    else
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    /*
    * @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed
    *        form of pointer arithmetic.
    */
        if ((Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_ParamValue & ICU_EMIOS_UC_MODE_PARAM_MASK) == ((Icu_ParamType)EMIOS_UC_IPM_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT))
#endif   /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
    {
          if (tempA > tempB)
    {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
            Icu_Period[msChannel] = tempA - tempB;
          }
          else     /*Counter overflow Case*/
          {
            Period = Icu_Read_Counter_Bus(numChl);
            Icu_Period[msChannel] = (Icu_ValueType)(tempA + \
                                              ((uint32)Period - tempB));
          }
            Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
    }
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
    #if (ICU_DMA_SUPPORTED == STD_ON)
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/        
                if(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Enable)
        {
                        index0 = Icu_DmaBuffer_Index[msDmaChannel];
                        dma_buffer = &Icu_DmaBuffer[msDmaChannel][0];
            /*configured and UCIN pin state are different */
            if((Icu_DmaBuffer_Index[msDmaChannel] == 1U) ||  \
/*
* @violates @ref Icu_LLD_c_REF_8 side effects on right hand of logical operator: '||'.
 */                        
                                                 (Icu_DmaBuffer_Index[msDmaChannel] == 0U))
            {
                  Icu_DmaBuffer_Index[msDmaChannel] += 2U;
            }
             else
             {
                  index0 = Icu_DmaBuffer_Index[msDmaChannel] - 2U;
                  index1 = ((index0+1U) % ICU_DMA_MAJORLOOP_COUNT);
                  /* Enter critical section */
                  SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();

                  Icu_ActivePulseWidth[msChannel] =  \
                        (Icu_ValueType) \
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/                                                
                              Icu_MeasurePulseWidth(numChl, (uint32)dma_buffer[index0],  \
                                                                   (uint32)dma_buffer[index1] );
                  /* Exist critical section */
                  SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();

                  index0 = index1;
                  index1 = ((index0 + 1U) % ICU_DMA_MAJORLOOP_COUNT);
                  pulse_width = (uint16)Icu_MeasurePulseWidth(numChl, \
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                          (uint32)dma_buffer[index0],(uint32)dma_buffer[index1] );
                              /* Enter critical section */
                                 SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();

                  Icu_Period[msChannel] =  (Icu_ValueType)  \
                                                (pulse_width + Icu_ActivePulseWidth[msChannel]);
                              /* Exist critical section */
                                 SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
                  Icu_DmaBuffer_Index[msDmaChannel] += 2U;
                  if(Icu_DmaBuffer_Index[msDmaChannel] > (ICU_DMA_MAJORLOOP_COUNT + 1U))
                  {
                      Icu_DmaBuffer_Index[msDmaChannel] -= ICU_DMA_MAJORLOOP_COUNT;
                  }
              }
        }
        else
    #endif/* #if (ICU_DMA_SUPPORTED = STD_ON)*/
        {
            Icu_eMIOS_LLD_SetActivationCondition(hwChannel, EMIOS_OPPOSITE_EDGES);

            if (Icu_Int_Counter[msChannel] == 0U)   /* store the first value */
            {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                Icu_Start[msChannel] = tempA;
                Icu_Int_Counter[msChannel]++;
            }
            else
            {
                previous_value = Icu_Start[msChannel];
                /* if first value is greater than the second value */
                if (tempA < previous_value)
                {
                    Period = Icu_Read_Counter_Bus(numChl);
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                    pulse_width = (Period - previous_value) + tempA;
                }
                else
                {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                    pulse_width = tempA - previous_value;
                }

                /* HIGH TIME or LOW TIME measurement */
                if (((uint32)ICU_HIGH_TIME == measurement_property) ||   \
                                          ((uint32)ICU_LOW_TIME == measurement_property))
                {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                    Icu_ActivePulseWidth[msChannel] = pulse_width;
                    /* clear to measure next LOW/HIGH pulse */
                    Icu_Int_Counter[msChannel] = 0U;
                    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
                }
                else
                {
                    /* DUTYCYCLE or PERIOD measurement */
                    if (Icu_Int_Counter[msChannel] == 1U)
                    {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                        Icu_CapturedActivePulseWidth[msChannel] = pulse_width;
                        Icu_Int_Counter[msChannel] = 2U;
                    }
                    else
                    {
                        /* counter = 2 */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                        Icu_Period[msChannel] = Icu_CapturedActivePulseWidth[msChannel] + pulse_width;
                        Icu_ActivePulseWidth[msChannel] = Icu_CapturedActivePulseWidth[msChannel];
                        /* set to 1 to find active pulse width next time */
                        Icu_Int_Counter[msChannel] = 1U;

                        Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);
                    }

                    /* store for next time */
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                    Icu_Start[msChannel] = tempA;
                }
            }
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
    }
#endif /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

/*================================================================================================*/
/**
 * @brief      Icu driver function that clears the input state of ICU channel.
 * @details    This function clears the input state of ICU channel used in
 *              signal measurement mode
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 *@implements  DICU02416
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ClearActiveState(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_ClearBitChState(numChl,ICU_CHANNEL_STATE_IDLE);
}


#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that handles the timestamp measurement type interrupt.
 * @details    This service is  called when an  interrupt is recognized  as a Timestamp Measurement
 *             type.
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 * @implements DICU02414
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_LLD_Timestamp(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr =
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/    
                                                         &Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl];
/*

* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel  = Icu_Cfg_Ptr->Icu_ChannelId[numChl];
/*

* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) msChannel  = Icu_Cfg_Ptr->Icu_ChannelIndex[numChl];
    VAR(boolean, AUTOMATIC) stopChannel          = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) callNotification     = (boolean)FALSE;

    #if (ICU_DMA_SUPPORTED == STD_ON)
       VAR(uint8, AUTOMATIC) tempDmaChannel = (uint8) Icu_Cfg_Ptr->  \
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/           
                                               Icu_ChannelConfigPtr[numChl].Icu_DMA_Channel;
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/
       VAR(uint16, AUTOMATIC) dma_biter = (uint16)ICU_LLM_READ_MAJORCOUNT_BITER(tempDmaChannel);
       VAR(boolean, AUTOMATIC) dma_enable =   \
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/           
                                          Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_DMA_Enable;
    #endif
   SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    {
        CONST(Icu_ValueType, AUTOMATIC) chBufferSize   = Icu_BufferSize[msChannel] ;
        CONST(Icu_ValueType, AUTOMATIC) chBufferNotify = Icu_BufferNotify[msChannel] ;

        #if (ICU_DMA_SUPPORTED == STD_ON)
                if(dma_enable == (boolean)TRUE)
                {
                        /* Read MAJOR iteration count */
                        if((Icu_BufferNotify[msChannel] != 0U) && \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */        
/*
* @violates @ref Icu_LLD_c_REF_8 side effects on right hand of logical operator: '||'.
 */                                        
                                            ((dma_biter % Icu_BufferNotify[msChannel]) == 0U))
                        {
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/                                                
                                Icu_NotifyCount[msChannel] += Icu_BufferNotify[msChannel] - 1U;
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/                                                                
                                Icu_BufferIndex[msChannel] += Icu_BufferNotify[msChannel];
                        }
                        else
                        {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                                Icu_NotifyCount[msChannel] += dma_biter - 1U;
                                Icu_BufferIndex[msChannel] += dma_biter;
                        }
                }
                else
                #endif
                                  {
/*
* @violates @ref Icu_LLD_c_REF_5 Array indexing shall be the only allowed form of pointer
*  arithmetic.
*/

/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
        /* Store timestamp */
        Icu_Buffer[msChannel][Icu_BufferIndex[msChannel]] = (Icu_ValueType)Icu_eMIOS_LLD_GetTimeStamp(ICU_eMIOS_CHANNEL(hwChannel));

        Icu_BufferIndex[msChannel]++;
                }
        if (Icu_BufferIndex[msChannel] >= chBufferSize)
        {
            /* If circular buffer, loop; if linear buffer, terminate. */
            if ((uint8)ICU_CIRCULAR_BUFFER == tempPtr->Icu_Channel_Property)
            {
                Icu_BufferIndex[msChannel] = (Icu_BufferIndex[msChannel])%chBufferSize;
                #if (ICU_DMA_SUPPORTED == STD_ON)
                                if(dma_enable == (boolean)TRUE)
                                {
                                        /* If DLAST_SGA is ZERO */
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                                 
                                        if(REG_READ32(DMA_TCD_CHANNEL(tempDmaChannel, 0x18U)) == 0U)
                                        {
                                                /* Re-initialize destination address, biter, citer and enable the DMA request */
                                              REG_WRITE32(DMA_TCD_CHANNEL(tempDmaChannel, 0x10U), \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                                           
                                                                 (uint32)(Icu_Buffer[msChannel]));
                                              REG_WRITE16(DMA_TCD_CHANNEL(tempDmaChannel, 0x14U),  \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                                           
                                                                       Icu_BufferNotify[msChannel]);
                                              REG_WRITE16(DMA_TCD_CHANNEL(tempDmaChannel, 0x1CU),  \
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                                           
                                                                       Icu_BufferNotify[msChannel]);
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                                                                                            
                                              Dma_start_channel(tempDmaChannel);
                                        }
                                }
                                #endif
            }
            else
            {
                /* Linear buffer is full, stop the channel */
                stopChannel = (boolean)TRUE;
            }
        }
        #if (ICU_DMA_SUPPORTED == STD_ON)
                else if(dma_enable == (boolean)TRUE)
                {
                        if (dma_biter == Icu_BufferNotify[msChannel])
                        {
                                /* Calculate next major iteration count */
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */        
/*
* @violates @ref Icu_LLD_c_REF_3 No reliance shall be placed on undefined or
* unspecified behavior
*/
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                                dma_biter = Icu_BufferSize[msChannel] - Icu_BufferIndex[msChannel];
                                if(dma_biter > Icu_BufferNotify[msChannel])
                                {
/* @violates @ref Icu_LLD_c_REF_17  Conditon for converted an expression of integer to different */
                                        dma_biter = Icu_BufferNotify[msChannel];
                                }
                                /* Write major iteration, both BITER & CITER and start the DMA */
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                 
                                REG_WRITE16(DMA_TCD_CHANNEL(tempDmaChannel, 0x14U), dma_biter);
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                 
                                REG_WRITE16(DMA_TCD_CHANNEL(tempDmaChannel, 0x1CU), dma_biter);
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                                                                 
                                Dma_start_channel(tempDmaChannel);
                        }
                }
                                else
                                {
                                 /* For Misra Compliance */
                                }
                #endif

        /*
           *  [ICU134]: The Icu module shall only call a notification function if the following
           *            facts are given:
           *      - A notification function is configured
           *      - The notification has been enabled by the call of Icu_EnableNotification()
           *      - NotifyInterval > 0
           *      - The number of events specified by NotifyInterval has been captured
         */
        if (chBufferNotify != 0U)
        {
            Icu_NotifyCount[msChannel]++;
            if (Icu_NotifyCount[msChannel] >= chBufferNotify)
            {
                Icu_NotifyCount[msChannel] = 0U;

                if ((0U != Icu_LLD_GetBitChState(numChl, ICU_CHANNEL_STATE_NOTIFICATION)) &&
                    (NULL_PTR != tempPtr->Icu_Channel_Notification))
                {
                    callNotification = (boolean)TRUE;
                }
            }
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();


    /* Stop channel */
    if (stopChannel)
    {
        Icu_LLD_StopTimestamp(numChl);
    }

    /* Call User Notification Function and/or Wakeup Function */
    if (callNotification)
    {
        tempPtr->Icu_Channel_Notification();
    }
}
#endif  /* ICU_TIMESTAMP_API */
/*================================================================================================*/
/**
  * @brief          Icu_LLD_EnableEdgeDetection
  * @details        Enables the detection of edges on a specific channel
  *
  * @param[in]      numChl - The index of ICU channel for current configuration structure
  * @return         void
  *
  * @implements
*/
/*================================================================================================*/
#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_LLD_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* Edge detection is running */
    Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);

    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        Icu_eMios_LLD_EnableEdgeDetection(ICU_eMIOS_CHANNEL(hwChannel));
    }
        /* External Interrupt Channel Configuration */
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_EnableEdgeDetection((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
    /* WKPU Interrupt Channel Configuration */
    else
    {
        Icu_WKPU_LLD_EnableEdgeDetection( ICU_WKPU_CHANNEL(hwChannel));
    }

}
#endif /* ICU_EDGE_DETECT_API */

/*================================================================================================*/
/**
  * @brief      Icu_LLD_DisableEdgeDetection
  * @details    Enables the detection of edges on a specific channel
  *
  * @param[in]      numChl - The index of ICU channel for current configuration structure
  * @return         void
  *
  * @violates @ref Icu_LLD_c_REF_4 MISRA-C:2004 17.4: Array indexing shall be the only allowed form
  *                of pointer arithmetic.
  *
  * @implements
*/
/*================================================================================================*/
#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_LLD_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* Edge detection is stoped */
    Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_STATE_RUNNING);
    /* Stop edge detection  */
    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        Icu_eMios_LLD_DisableEdgeDetection(ICU_eMIOS_CHANNEL(hwChannel));
    }
        /* External Interrupt Channel Configuration */
    else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
    {
        Icu_Siul_LLD_DisableEdgeDetection((SIUL_Icu_IRQ_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
    /* WKPU Interrupt Channel Configuration */
    else
    {
        Icu_WKPU_LLD_DisableEdgeDetection((WKPU_Icu_ChannelType)ICU_WKPU_CHANNEL(hwChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */

/*================================================================================================*/
/**
  * @brief          Icu_LLD_CheckWakeup
  * @details        Checks if a wakeup capable ICU channel is the source for a wakeup event.
  *
  * @param[in]      WakeupSource - Informatin on wakeup source to be checked. The associated ICU channel can be determined from configuration data.
  *
  * @return         void
  *
  * @implements DICU02410
*/
/*================================================================================================*/
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (ICU_ENABLE_WAKEUP_API == STD_ON))
FUNC (void, ICU_CODE) Icu_LLD_CheckWakeup( VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource )
{
    VAR(Icu_ChannelType, AUTOMATIC) numChl;
    VAR(Icu_ChannelStateType, AUTOMATIC ) tempChanelState;
    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr;

    for (numChl = 0U; numChl < Icu_Cfg_Ptr->Icu_MaxChannels; numChl++)
    {
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of pointer arithmetic.
*/
        tempPtr = &Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl];
        tempChanelState = Icu_LLD_GetBitChState(numChl, ( ICU_CHANNEL_STATE_WKUP |  \
                                                          ICU_CHANNEL_IS_WAKEUP_SOURCE ));

        if ((WakeupSource == (EcuM_WakeupSourceType)tempPtr->Icu_Channel_WakeupValue) &&
            ((ICU_CHANNEL_IS_WAKEUP_SOURCE | ICU_CHANNEL_STATE_WKUP) == tempChanelState ))
        {
            EcuM_SetWakeupEvent(WakeupSource);
            Icu_LLD_ClearBitChState(numChl, ICU_CHANNEL_IS_WAKEUP_SOURCE);
            break;
        }
    }
}
#endif /* ICU_WAKEUP_FUNCTIONALITY_API && ICU_REPORT_WAKEUP_SOURCE  &&  ICU_ENABLE_WAKEUP_API */
/*================================================================================================*/
/**
 * @brief      Icu driver function that handles the interrupt of ICU channel.
 * @details    Interrupt function  that may  jump to  the WakeUp  function (Depending  on the  selected
 *             configuration)  and branches  to the  proper actions  depending the  mode in  which the
 *             channel is operating.
 *
 * @param[in]  numChl - ICU logical channel
 * @param[in]  flags  - Interrupts Status Flags
 *
 * @implements DICU02023
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ProcessCommonInterrupt(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                     VAR(uint32, AUTOMATIC) flags)
{
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr =
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/    
                                                       &Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl];

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
    VAR(boolean, AUTOMATIC) chWakeupCapable;
    VAR(boolean, AUTOMATIC) crtModeSleep;

    chWakeupCapable = (ICU_CHANNEL_STATE_WKUP ==   \
                      Icu_LLD_GetBitChState(numChl, ICU_CHANNEL_STATE_WKUP))?   \
                                                                   (boolean)TRUE : (boolean)FALSE ;
    crtModeSleep    = (ICU_MODE_SLEEP == Icu_Current_Mode)? (boolean)TRUE : (boolean)FALSE ;

    if ((( chWakeupCapable == (boolean)TRUE) && ( crtModeSleep == (boolean)TRUE))&&   \
                                    (tempPtr->IcuDisableEcumWakeupSourceNotification ==  \
                                    (boolean)FALSE))
    {
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_IS_WAKEUP_SOURCE);
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form
*        of pointer arithmetic.
*/
        EcuM_CheckWakeup(Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl].Icu_Channel_WakeupValue);
#endif  /* ICU_REPORT_WAKEUP_SOURCE */
    }
#endif  /* ICU_ENABLE_WAKEUP_API */
    #if (ICU_DMA_SUPPORTED == STD_ON)
        if(tempPtr->Icu_DMA_Enable)
        {
/* @violates @ref Icu_LLD_c_REF_9 MISRA 2004 Required Rule,Side effects of && and ||  */
/* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/                                
           CLEAR_DMA_INTC(tempPtr->Icu_DMA_Channel);
        }
    #endif
    /* Verify configuration of channel and make the right processing */
    if (ICU_MODE_SIGNAL_EDGE_DETECT == tempPtr->Icu_Channel_Mode)
    {
        Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_IDLE);

        if ((0U != Icu_LLD_GetBitChState(numChl, ICU_CHANNEL_STATE_NOTIFICATION)) &&
            (NULL_PTR != tempPtr->Icu_Channel_Notification))
        {
            tempPtr->Icu_Channel_Notification();
        }
    }
/*

* @violates @ref Icu_LLD_c_REF_4 MISRA 2004 Advisory Rule 12.6, The operands of logical operators
*        (&&, || and !) should be effectively Boolean.
*/
/*
* @violates @ref Icu_LLD_c_REF_8 side effects on right hand of logical operator: '||'.
 */
    else if ( ((boolean)TRUE == Icu_LLD_CheckHwOverflowFlag(numChl, flags)) ||
             ((ICU_MODE_EDGE_COUNTER == (tempPtr->Icu_Channel_Mode))&&  \
/*
* @violates @ref Icu_LLD_c_REF_8 side effects on right hand of logical operator: '||'.
 */             
             (((Icu_ChannelState[numChl] & ICU_CHANNEL_STATE_WKUP) == 0U))))
    {
        Icu_LLD_SetBitChState(numChl, ICU_CHANNEL_STATE_OVERFLOW);

#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        if (NULL_PTR != tempPtr->Icu_Channel_OverFlowNotification)
        {
            tempPtr->Icu_Channel_OverFlowNotification();
        }
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
    }
    else
    {
        /* does nothing  - structure request by misra*/
    }

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
    if (ICU_MODE_SIGNAL_MEASUREMENT == tempPtr->Icu_Channel_Mode)
    {
        Icu_LLD_SignalMeasurement(numChl);
    }
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
    if (ICU_MODE_TIMESTAMP == tempPtr->Icu_Channel_Mode)
    {
        Icu_LLD_Timestamp(numChl);
    }
#endif  /* ICU_TIMESTAMP_API */
}


#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
  * @brief      This function changes the channel prescaler.
  * @details    This function sets all channels prescalers based on the input mode.
  *
  * @param[in]  tempPtr   - Pointer to configuration structure
  * @param[in]  numChl    - The index of ICU channel for current configuration structure
  * @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
  *
  * @return void
  *
  * @violates @ref Icu_LLD_c_REF_4 MISRA-C:2004 17.4: Array indexing shall be the only allowed form
  *            of pointer arithmetic.
  *
  * @implements DICU02015
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SelectPrescaler(
                                  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                  VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                  VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler)
{
    VAR(uint32, AUTOMATIC) ParamValue = 0x00000000U;
/**
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    /* eMIOS Channel Configuration */
    if (hwChannel < ICU_MAX_eMIOS_CHANNELS)
    {
        if (ICU_NORMAL == Prescaler)
        {
            ParamValue = ((tempPtr->Icu_ParamValue & ICU_EMIOS_PRESCALER_PARAM_MASK) >>  \
                           ICU_EMIOS_PRESCALER_PARAM_SHIFT) << CCR_UCPRE_SHIFT;
        }
        else
        {
            ParamValue = ((tempPtr->Icu_ParamValue & ICU_EMIOS_PRESC_ALT_PARAM_MASK) >>   \
                           ICU_EMIOS_PRESC_ALT_PARAM_SHIFT) << CCR_UCPRE_SHIFT;
        }

        Icu_eMIOS_LLD_SelectPrescaler(ParamValue, ICU_eMIOS_CHANNEL(hwChannel));
    }
     else if (hwChannel < ICU_MAX_IRQ_CHANNELS)
     {
         if (ICU_NORMAL == Prescaler)
        {
            SIUL_Icu_LLD_SelectPrescaler(tempPtr->Icu_ParamValue, Icu_Cfg_Ptr->Icu_Irq_ClockPrescaler);
        }                
         else
        {
            SIUL_Icu_LLD_SelectPrescaler(tempPtr->Icu_ParamValue, Icu_Cfg_Ptr->Icu_Irq_AlternateClockPrescaler);
        }        
     }
     else
     {
       /* For Misra Compliance */         
     }
         
}
#endif /* ICU_DUAL_CLOCK_MODE == STD_ON */

/*================================================================================================*/
/**
* @brief      This function returns the actual status of PIN.

* @details    This function returns the actual status a PIN .
*
* @param[in]     Channel          Numeric identifier of the ICU channel
*
* @return  void
*
* @pre        Icu_Init must be called before.
*
* @implements DICU02702
*/
/*================================================================================================*/
/* @violates @ref Icu_LLD_c_REF_7 use of external objects*/
FUNC (boolean, ICU_CODE) Icu_LLD_GetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    VAR(boolean, AUTOMATIC) tempStatus;
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[numChl];

    tempStatus = (boolean)Icu_eMIOS_LLD_GetInputLevel(ICU_eMIOS_CHANNEL(hwChannel));

    return(tempStatus);

}

#if (ICU_GET_PULSE_WIDTH_API == STD_ON)
/*================================================================================================*/
/**
 @brief      This function returns the signals High time, Low time and Period without using the
             channel interrupt.
 @details    This function returns the signals High time, Low time and Period without using the
             channel interrupt.
 @param[in]     Channel          Numeric identifier of the ICU channel
 @pre        Icu_Init must be called before.
 @implements DICU02420
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_GetPulseWidth(VAR(Icu_ChannelType, AUTOMATIC) numChl)
{
    Icu_LLD_SignalMeasurement(numChl);
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that returns clock mode of channel
* @details    This function returns clock mode of channel
*
* @param[in]  hardware channel eMIOS
*
* @return       uint32
*
* @api
* @implements DICU02420
*/
/*================================================================================================*/
LOCAL_INLINE \
      FUNC (uint32, ICU_CODE) Icu_LLD_GetChannelClockMode(CONST(Icu_ChannelType, AUTOMATIC) Channel)
{

    CONST(uint8, ICU_CONST) mIdx = (uint8)((Channel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, ICU_CONST) chIdx = (uint8)((Channel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    VAR(uint32, AUTOMATIC) Channel_clockMode;
    /* @violates @ref Icu_LLD_c_REF_12 MISRA 2004 Required Rule, Pointer to function Conversion*/
    Channel_clockMode = REG_READ32(EMIOS_CCR(mIdx, chIdx)) & CCR_MODE_MASK;
    
    return Channel_clockMode;
}

/*================================================================================================*/
/**
 @brief      This function is used to read the period values for channels
 @details    This function returns the Counter Value based on the configuration
 @param[in]  Channel          Numeric identifier of the ICU channel
 @pre        Icu_Init must be called before.
 @implements DICU02421
*/
/*================================================================================================*/
LOCAL_INLINE\
    FUNC (Icu_ValueType, ICU_CODE) Icu_Read_Counter_Bus(CONST(Icu_ChannelType, AUTOMATIC) Channel)   
{
    VAR(uint16, AUTOMATIC) Period = (uint16)0u;
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
* pointer arithmetic.
*/    
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[Channel];
    CONST(uint8, ICU_CONST) mIdx = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    
    VAR(uint32, AUTOMATIC) BusChannelClockMode = (uint32)0u;
    VAR(uint32, AUTOMATIC) EmiosBusAClockMode = (uint32)0u;

/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
* pointer arithmetic.
*/
    if ((((Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_ParamValue) &
                                                             (EMIOS_BUS_INTERNAL_COUNTER)) ==  \
                                EMIOS_BUS_INTERNAL_COUNTER) && (hwChannel < ICU_MAX_eMIOS_CHANNELS))
    {
        Period = (uint16)EMIOS_INTERNAL_COUNTER_MAX_COUNT;
    }
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
* pointer arithmetic.
*/    
    else if ((((Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_ParamValue) &
                   (EMIOS_BUS_DIVERSE)) == EMIOS_BUS_DIVERSE) &&  \
                    (hwChannel < ICU_MAX_eMIOS_CHANNELS))
    {
        if (chIdx <= EMIOS_CHANNEL_7)
        {
            BusChannelClockMode = \
                    Icu_LLD_GetChannelClockMode((uint8)(mIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
            /* eMIOS Counter Bus_B Channel (EMIOS_CHANNEL_0) is in Modulous counter buffer or
            Modulous counter mode */
            if ((BusChannelClockMode == CCR_MCB_MODE) || (BusChannelClockMode == CCR_MC_MODE))
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegA((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                 + EMIOS_CHANNEL_0);
            }
            else
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegB((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                 + EMIOS_CHANNEL_0);
            }
        }

        /* eMIOS Channel configured is using Counter Bus_C */
        else if ((chIdx >= EMIOS_CHANNEL_8) && (chIdx <= EMIOS_CHANNEL_15))
        {
            BusChannelClockMode = \
                    Icu_LLD_GetChannelClockMode((uint8)(mIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
            /* eMIOS Counter Bus_C Channel (EMIOS_CHANNEL_8) is in Modulous counter buffer or
             Modulous counter mode */
            if ((BusChannelClockMode == CCR_MCB_MODE) || (BusChannelClockMode == CCR_MC_MODE))
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegA((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                 + EMIOS_CHANNEL_8);
            }
            else
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegB((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                 + EMIOS_CHANNEL_8);
            }
        }

        /* eMIOS Channel configured is using Counter Bus_D */
        else if ((chIdx >= EMIOS_CHANNEL_16) && (chIdx <= EMIOS_CHANNEL_23))
        {
            BusChannelClockMode = \
                   Icu_LLD_GetChannelClockMode((uint8)(mIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
            /* eMIOS Counter Bus_D Channel (EMIOS_CHANNEL_16) is in Modulous counter buffer or
             Modulous counter mode */
            if ((BusChannelClockMode == CCR_MCB_MODE) || (BusChannelClockMode == CCR_MC_MODE))
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegA((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_16);
            }
            else
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegB((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_16);
            }
        }

        /* eMIOS Channel configured is using Counter Bus_E */
        else if ((chIdx >= EMIOS_CHANNEL_24) && (chIdx <= EMIOS_CHANNEL_31))
        {
            BusChannelClockMode = \
                Icu_LLD_GetChannelClockMode((uint8)(mIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
            /* eMIOS Counter Bus_E Channel (EMIOS_CHANNEL_24) is in Modulous counter buffer or
             Modulous counter mode */
            if ((BusChannelClockMode == CCR_MCB_MODE) || (BusChannelClockMode == CCR_MC_MODE))
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegA((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_24);
            }
            else
            {
                Period= (uint16)Icu_eMIOS_LLD_GetCaptureRegB((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_24);
            }
        }
        else
        {
            /* Do Nothing */
        }
     }
/*
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
* pointer arithmetic.
*/     
     else if ((((Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_ParamValue) &
/*@violates @ref Icu_LLD_c_REF_10 MISRA 2004 Required Rule,This condition is added to 
        optimize the driver code*/     
                  (EMIOS_BUS_A)) == EMIOS_BUS_A) && (hwChannel < ICU_MAX_eMIOS_CHANNELS))
    {

        /* Get clock mode */
        EmiosBusAClockMode = \
                  Icu_LLD_GetChannelClockMode((uint8)(mIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23);
        
        if ((EmiosBusAClockMode == CCR_MCB_MODE) || \
                                            (EmiosBusAClockMode == CCR_MC_MODE))
        {
            Period  = (uint16) Icu_eMIOS_LLD_GetCaptureRegA((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_23);
        }
        else
        {
            Period  = (uint16) Icu_eMIOS_LLD_GetCaptureRegB((uint8)(mIdx << EMIOS_MOD_SHIFT) \
                                                                                + EMIOS_CHANNEL_23);
        }
    }
    else
    {
        /* Do Nothing */
    }

    /* return Period */
    return (Period);
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#if (ICU_DMA_SUPPORTED == STD_ON)
/**********************************************************************
* Function Name: Icu_MeasurePulseWidth
* Service ID: n/a
* Sync/Asyn: n/a
* Parameters (in): Channel- signalmeasurement eMIOS channel
                   BufferValue1 - dma captured value1
                   BufferValue2 - dma captured value2
* Parameters (out): None
* Return Value: None
* Description: This service is called when an interrupt is recognized as
               a Signal Measurement type. There are two branch depending
               on the sub-function selected: Duty Cycle or OTHER. Duty Cycle
               requires an extra variable, because three values are required:
               two flanks for active signal time and another flank for the end
               of the pulse. For calculating high, low and period is enough
               with the HW registers.
**********************************************************************/
static FUNC (uint32, ICU_CODE) Icu_MeasurePulseWidth( VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                VAR(uint32, AUTOMATIC)BufferValue1,
                                                VAR(uint32, AUTOMATIC)BufferValue2 )
    {
        VAR(uint32, AUTOMATIC) Period;
            VAR(uint32, AUTOMATIC) pulsewidth;        
        if((BufferValue2) < (BufferValue1))
        {
            Period = Icu_Read_Counter_Bus(Channel);
            pulsewidth = ((Period - BufferValue1 ) + BufferValue2);
        }
        else
        {
            pulsewidth = (BufferValue2- BufferValue1);
        }
          return(pulsewidth);
    }
#endif
#endif

/*================================================================================================*/
/**
 @brief      The function enables pull up for not configured and unavailable Wakeup pins.
 @details    The function enables pull up for not configured and unavailable Wakeup pins.
 @param[in]    None
*/
/*================================================================================================*/
/*
* @violates @ref Icu_LLD_c_REF_15 This is required as per autosar Requirement,
*/
FUNC (void, ICU_CODE) Icu_LLD_PullUpNonBondedWakeupPin(void)
{
    WKPU_LLD_PullUpNonBondedWakeupPin();
}
#if (ICU_CAPTURERGISTER_API == STD_ON)
/**********************************************************************
* Function Name   : Icu_LLD_GetCaptureRegisterValue
* Service ID: n/a
* Sync/Asyn: n/a
* Parameters (in):Channel - Icu channel
* Parameters (out): Icu_ValueType
* Return Value: tempA(value of Register A)
* Description: This service Returns the  current value of Register A. This API
*                        is used when user wants to know the time difference  between 2
*                         channels.
**********************************************************************/
FUNC (Icu_ValueType, ICU_CODE)   Icu_LLD_GetCaptureRegisterValue(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_ValueType, ICU_VAR) tempA;
/*
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/
    CONST(Icu_ChannelType, AUTOMATIC) hwChannel = Icu_Cfg_Ptr->Icu_ChannelId[Channel];
/*
* @file  Icu_LLD.c
* @violates @ref Icu_LLD_c_REF_5 MISRA-C 2004 17.4: Array indexing shall be the only allowed form of
*        pointer arithmetic.
*/

    tempA = (Icu_ValueType)Icu_eMIOS_LLD_GetCaptureRegA(hwChannel);
    return tempA;
}
#endif /* ICU_CAPTURERGISTER_API */
#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_LLD_c_REF_1  MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_LLD_c_REF_2  MISRA  Advisory Rule 19.15, Precautions shall be taken in order to
*        prevent the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/**@}*/