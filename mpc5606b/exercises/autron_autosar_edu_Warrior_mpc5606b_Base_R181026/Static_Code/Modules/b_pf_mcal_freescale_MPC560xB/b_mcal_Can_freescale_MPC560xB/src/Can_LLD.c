/**
*   @file    Can_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details API implementation for CAN driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
*
* @section Can_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section  Can_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.

* @section Can_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*
*/



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Can_LLD.c
* @implements     DCAN02661
*/
#include "Can.h"
#include "Can_LLD.h"
#include "CanIf_Cbk.h"
#if(CAN_WAKEUP_SUPPORT == STD_ON)
    #include "EcuM_Cbk.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_LLD.c
* @implements     DCAN02661
*/
#define CAN_VENDOR_ID_LLD_C                      43
/*
* @violates @ref Can_LLD_c_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref Can_LLD_c_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_LLD_C       4
/*
* @violates @ref Can_LLD_c_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref Can_LLD_c_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_LLD_C       0
/*
* @violates @ref Can_LLD_c_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref Can_LLD_c_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_LLD_C    3
#define CAN_SW_MAJOR_VERSION_LLD_C               1
#define CAN_SW_MINOR_VERSION_LLD_C               0
#define CAN_SW_PATCH_VERSION_LLD_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_LLD_C != CAN_VENDOR_ID_LLD_H)
    #error "Can_LLD.c and Can_LLD.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_LLD_C    != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_LLD_C    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_LLD_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_LLD.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_LLD_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_LLD_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_LLD_C != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_LLD.c and Can.h are different"
#endif


/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_LLD_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_LLD_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_LLD.c and Det.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Can_LLD_c_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/*
* @brief          Process BusOff event.
* @details        This routine is called by:
*              - Can_MainFunction_BusOff() from Can.c file.
*              - Can_IsrFC##FC##_BO() from Can_Irq.c file.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
*
* @pre            Driver must be initialized.
* @post           Handle the Busoff event.
*
* @implements     DCAN01069, DCAN01070, DCAN02652
*
* @note           Not AUTOSAR required. This is user implementation.
*
*/
FUNC(void, CAN_CODE) Can_LLD_Process_BusOff( CONST(uint8, CAN_CONST) controller)
    {

        /* Used for internal logic - return value */
        VAR(Can_ReturnType, AUTOMATIC) can_return = CAN_NOT_OK;

        /*
           (CAN272) After bus-off detection, the Can module shall transition to the state CANIF_CS_STOPPED and shall ensure that
                   the CAN controller doesn't participate on the network anymore.
        */
        /* @violates @ref Can_LLD_c_REF_3 Violates MISRA 2004 Advisory Rule 17.4 */
        can_return = Can_LLD_SetControllerMode( controller,  &(Can_CurrentConfigPtr->ControlerDescriptors[controller]), CAN_T_STOP, (boolean)FALSE);

        /* Process Busoff event only if controller was passed to Stop mode. */
        if ( CAN_OK == can_return )
        {
            /* Process Busoff event. Clear the bus off interrupt flag. */
            FlexCan_LLD_Process_BusOff( controller);

            /*
               (CAN020) The CanIf module is notified with the callback function CanIf_ControllerBusOff after stopped state is reached.
            */
            CanIf_ControllerBusOff( controller);
        }
}


/*================================================================================================*/
/*
* @brief          Process WakeUp event.
* @details        This routine is called by:
*                - Can_MainFunction_Wakeup() from Can.c file.
*                - Can_IsrFC##FC##_WKP() from Can_Irq.c file.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
*
* @pre            Driver must be initialized.
* @post           Handle the Wakeup event.
*
* @implements     DCAN01129, DCAN02653
*
* @note           Not AUTOSAR required. This is user implementation.
*
*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)

FUNC(void, CAN_CODE) Can_LLD_Process_Wakeup( CONST(uint8, CAN_CONST) controller )
    {

        /* Used for internal logic - return value */
        VAR(Can_ReturnType, AUTOMATIC)  can_return = CAN_NOT_OK;


        /* Transition the controller to WAKEUP mode. */
        can_return = Can_LLD_SetControllerMode( controller, &Can_CurrentConfigPtr->ControlerDescriptors[controller], CAN_T_WAKEUP, (boolean)FALSE);

        /* Process Wakeup event only if transition from Sleep to Wakeup was ok. */
        if ( CAN_OK == can_return )
        {
            /* Process WakeUp event. Clear the wakeup interrupt flag. */
            EcuM_CheckWakeup( Can_ControlerDescriptorsPtr[controller].CanWakeupSourceID );
            FlexCan_LLD_Process_Wakeup (controller);
        }
    }

#endif  /* (CAN_WAKEUP_SUPPORT == STD_ON) */


/*================================================================================================*/
/*
* @brief          Process Receive Data event.
* @details        This routine is called by:
*                - Can_IsrFC##FC##_UNI() from Can_Irq.c file.
*                - Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process.
* @param[in]      mbindex_end last MB to process.
*
* @pre            Driver must be initialized.
* @post           Handle the Receive event.
*
* @implements     DCAN01130, DCAN02654
*
* @note           Not AUTOSAR required. This is user implementation.
*
* @violates @ref Can_LLD_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC(void, CAN_CODE) Can_LLD_Process_Rx( CONST(uint8, CAN_CONST) controller,
                                     CONST(uint8, CAN_CONST) mbindex_start,
                                     CONST(uint8, CAN_CONST) mbindex_end )
    {

        /* Process Rx event. Clear the rx interrupt flag. */
        FlexCan_LLD_Process_Rx( controller, mbindex_start, mbindex_end);
    }


/*================================================================================================*/
/*
* @brief          Process Transmit Data event.
* @details        This routine is called by:
*                - Can_IsrFC##FC##_UNI() from Can_Irq.c file.
*                - Can_IsrFC##FC##_##Name() from Can_Irq.c file.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
* @param[in]      mbindex_start first MB to process.
* @param[in]      mbindex_end last MB to process.
*
* @pre            Driver must be initialized.
* @post           Handle the Transmit event.
*
* @implements     DCAN01131, DCAN02655
*
* @note           Not AUTOSAR required. This is user implementation.
*
* @violates @ref Can_LLD_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC(void, CAN_CODE) Can_LLD_Process_Tx( CONST(uint8, CAN_CONST) controller,
                                     CONST(uint8, CAN_CONST) mbindex_start,
                                     CONST(uint8, CAN_CONST) mbindex_end )
    {

        /* Process Rx event. Clear the rx interrupt flag. */
        FlexCan_LLD_Process_Tx( controller, mbindex_start, mbindex_end );
    }


/*================================================================================================*/
/*
* @brief          Process Rx Fifo FrameAvailable events
* @details        This function is much faster for handling FrameAvailable interrupt events than Can_LLD_Process_Rx, specific to MB (Mapped to MB5).
*                This routine is called by:
*                - Can_IsrFC##FC##_FrameAv() from Can_Irq.c file.
*                - Can_IsrFC##FC##_RxFifoEvents() from Can_Irq.c file.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
*
* @pre            Driver must be initialized.
* @post           Rx fifo must be enabled.
*
* @implements     DCAN01132, DCAN02656
*
* @note           Not AUTOSAR required. This is user implementation.
*
*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
/*@violates @ref Can_LLD_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */

FUNC(void, CAN_CODE) Can_LLD_RxFifoFrameAvNotif( CONST(uint8, CAN_CONST) controller)
    {

        /* Process RxFifo frame available event. Clear the rxfifo frame available interrupt flag.*/
        FlexCan_LLD_RxFifoFrameAvNotif( controller);
    }

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*================================================================================================*/
/*
* @brief          This function checks the Baudrate for the controller.
* @details        This routine is called by:
*                  - Can_ChangeBaudrate() from Can.c file.
*                  - Can_CheckBaudrate() from Can.c file.
*
* @param[in]      controller    CAN controller for which Baudrate checks is required
*                 Baudrate      Baudrate to check
*                 ApiId         ApiId of the function which calls this function
* @return        Std_ReturnType
* @retval        E_OK Valid Baudrate
* @retval        E_NOT_OK Invalid Baudrate
*
* @pre            A request for wakeup checking is required.
* @post           Report the occurence or not for an wakeup event.
*
*/
#if (CAN_CHANGE_BAUDRATE_API == STD_ON)

FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckBaudrate
(
    VAR(uint8, AUTOMATIC) controller,
    CONST(uint16, CAN_CONST) Baudrate,
    VAR(uint8, AUTOMATIC) ApiId
)
    {
        /* Return value. */
        VAR(Std_ReturnType, AUTOMATIC) Out_can_return = (uint8)E_NOT_OK;
        VAR(uint8, AUTOMATIC) Baudrateindex = 0U;
        /* @violates @ref Can_LLD_c_REF_3 Violates MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_LLD_c_REF_3 Violates MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
        for ( Baudrateindex = 0U; Baudrateindex < Can_ControlerDescriptorsPtr[controller].MaxBaudRateCount; Baudrateindex++)
        {
            /* Check the Baudrate */
            /* @violates @ref Can_LLD_c_REF_3 Violates MISRA 2004 Advisory Rule 17.4 */
            if (Baudrate == (uint16)(Can_ControlerDescriptorsPtr[controller].ControllerBaudrateConfigsPtr[Baudrateindex].ControllerBaudRate))
            {
                /* Baudrate is Valid */
                if (ApiId == CAN_SID_CHANGE_BAUDRATE)
                {
                    /* Copy the index of Valid Baudrate into the Can_ControllerStatuses as CurrentBaudRateIndex */
                    Can_ControllerStatuses[controller].CurrentBaudRateIndex = Baudrateindex;
                }
                Out_can_return = (uint8)E_OK;
                break;
            }
        }

        return (Out_can_return);
    }

#endif /* (CAN_CHANGE_BAUDRATE_API == STD_ON) */


#define CAN_STOP_SEC_CODE

/*
* @violates @ref Can_LLD_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
*/
/*
* @violates @ref Can_LLD_c_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
