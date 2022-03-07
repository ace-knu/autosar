/**
*   @file    Fee_Cbk.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Callback Notifications.
*   @details Definitions of the callback functions Fee_JobEndNotification 
*            and Fee_JobErrorNotification.
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
#ifndef FEE_CBK_H
#define FEE_CBK_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_Cbk_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_Cbk_h_REF_2 Repeatedly included but does not have a standard include guard */
#include "MemMap.h"

extern FUNC( void, FEE_CODE ) Fee_JobEndNotification( void );
extern FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void );

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_Cbk_h_REF_2 Repeatedly included but does not have a standard include guard */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* _FEE_CBK_H_ */
/** @} */
