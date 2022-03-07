/**
*   @file    Cer.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Catastrophic Errors Recovery STUB file
*   @details The system is meant to handle those unexpected runtime situations that the existing
*            DEM and DET subsystems cannot cope with.
*            This file is a Stub. The implementation must be updated by the MCAL integrators.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup BASE_COMPONENT
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

/**
* @file    Cer.h
* @implements DBASE01000
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Cer_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro.
* CER module implemetation can be overriden by the integrator. MCAL validation uses a macro for this
* functionality. This is a stub, not to be used in production environment without integrator review.
*
* @section Cer_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*/

#ifndef CER_H
#define CER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file  Cer.h
* @brief Include standard types
*/
/*
* @violates @ref Cer_h_REF_2 Precautions shall be taken in order to
* prevent the contents of a header being included twice.
*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* define the macro only if it has not been defined elsewhere */
/*@implements DBASE01001*/
#if !defined(Cer_ReportError)
    #ifdef MCAL_CER_VALIDATION
        /*
        * @brief CER: Catastrophic Errors Recovery
        * @details The system is meant to handle those unexpected runtime situations that the
        *          existing DEM and DET subsystems cannot cope with.
        * @implements DBASE10001
        * @note This implementation will be used only for MCAL validation
        */
        /*
        * @violates @ref Cer_h_REF_1 A function should be used in
        * preference to a function-like  macro.
        */
        #define Cer_ReportError(ModuleId, InstanceId, ApiId, ErrorId) \
        { \
            Cer_ModuleId = ModuleId; \
            Cer_InstanceId = InstanceId; \
            Cer_ApiId = ApiId; \
            Cer_ErrorId = ErrorId; \
            while(1){}; \
        }
    #else
        /*
        * @brief CER: Catastrophic Errors Recovery
        * @details The system is meant to handle those unexpected runtime situations that the
                   existing DEM and DET subsystems cannot cope with.
        * @implements DBASE10001
        * @note Platform integrator should redefine the functionality of this macro.
        */
        /*
        * @violates @ref Cer_h_REF_1 A function should be used in
        * preference to a function-like  macro.
        */
        #define Cer_ReportError(ModuleId, InstanceId, ApiId, ErrorId)
    #endif /* MCAL_CER_VALIDATION */
#endif /* !defined(Cer_ReportError) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/**
* @brief Variable used by MCAL validation to save CER module ID.
* @note This should be changed by the platform integrator (based on the implementation of the CER
* functionality
*/
extern VAR(uint16, DET_VAR) Cer_ModuleId;
/**
* @brief Variable used by MCAL validation to save CER instance ID.
* @note This should be changed by the platform integrator (based on the implementation of the CER
* functionality
*/
extern VAR(uint8 , DET_VAR) Cer_InstanceId;
/**
* @brief Variable used by MCAL validation to save CER API ID.
* @note This should be changed by the platform integrator (based on the implementation of the CER
* functionality
*/
extern VAR(uint8 , DET_VAR) Cer_ApiId;
/**
* @brief Variable used by MCAL validation to save CER Error ID.
* @note This should be changed by the platform integrator (based on the implementation of the CER
* functionality
*/
extern VAR(uint8 , DET_VAR) Cer_ErrorId;

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*CER_H*/

/** @} */
