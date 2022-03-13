/**
*   @file    Mcal.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction specific for MCAL.
*   @details The file Mcal.h provides MCAL specific macros used for compiler abstraction.
*
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
@file        Mcal.h
@implements DBASE05000
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcal_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. Compiler abstraction need to implement function-like macros to hide compiler specifics from
* the implementation.
*
* @section Mcal_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Mcal_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class
* specifier, or a do-while-zero construct
*
* @section Mcal_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as
* the operand of # or ##.
*
* @section Mcal_h_REF_5
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/

#ifndef MCAL_H
#define MCAL_H

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
* @file        Mcal.h
* @brief Include compiler abstraction
*/
/*
* @violates @ref Mcal_h_REF_2 MISRA 2004 Precautions shall be taken in order to
* prevent the contents of a header being included twice.
*/
#include "Compiler.h"
/*
* @file        Mcal.h
* @brief Include standard types
*/
/*
* @violates @ref Mcal_h_REF_2 MISRA 2004 Precautions shall be taken in order to
* prevent the contents of a header being included twice.
*/
#include "Std_Types.h"
/*
* @file        Mcal.h
* @brief Include standard types
*/
#include "Cer.h"
/*
* @file        Mcal.h
* @brief Include offset for exit interrupt
*/
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_MPC560XB_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @implements DBASE05024
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    * @implements DBASE05005
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
/*
* @violates @ref Mcal_h_REF_5 This is not a standard library macro, 
*/    
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wait")
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05001
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05027
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */
/*
* @violates @ref Mcal_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/     
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05002
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
#endif /* #ifdef _GREENHILLS_C_MPC560XB_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_MPC560XB_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @implements DBASE05024
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  asm volatile

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    * @implements DBASE05005
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define EXECUTE_WAIT()      ASM_KEYWORD("  .word 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05001
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05027
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05002
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()

#endif /* #ifdef _DIABDATA_C_MPC560XB_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_MPC560XB_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @implements DBASE05024
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    * @implements DBASE05005
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define EXECUTE_WAIT()      ASM_KEYWORD (" opword 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05001
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05027
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define VAR_ALIGN(v, size) v __attribute__(( aligned(size) ));
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05002
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()

#endif /* #ifdef _CODEWARRIOR_C_MPC560XB_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_MPC560XB_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @implements DBASE05024
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  _asm
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @remarks Implements DBASE05003
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_PUBLIC_LABEL(label)  _asm("\txdef\t" #label "\n" #label ":")

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    * @implements DBASE05005
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define EXECUTE_WAIT()      ASM_KEYWORD (" dc.l 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05001
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ALIGNED_VARS_START(sec_name, align) \#pragma section [sec_name ## align]
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05027
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define VAR_ALIGN(v, size) v;
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05002
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ALIGNED_VARS_STOP() \#pragma section []
#endif /* #ifdef _COSMIC_C_MPC560XB_ */

/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_MPC560XB_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @implements DBASE05024
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    * @implements DBASE05005
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wait")
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05001
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05027
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    * @implements DBASE05002
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
#endif /* #ifdef _HITECH_C_MPC560XB_ */
/* check that the compiler used is supported (otherwise some defines might not exist) */
#ifndef _GREENHILLS_C_MPC560XB_
    #ifndef _DIABDATA_C_MPC560XB_
        #ifndef _CODEWARRIOR_C_MPC560XB_
            #ifndef _COSMIC_C_MPC560XB_
                #ifndef _HITECH_C_MPC560XB_
                    #error "Unsupported compiler. Compiler abstraction needs to be updated to use this compiler."
                #endif
            #endif
        #endif
    #endif
#endif

#if defined(AUTOSAR_OS_NOT_USED)
    #if defined (USE_SW_VECTOR_MODE)
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        * @implements DBASE05016
        */
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
        #define ISR(IsrName)       void IsrName(void)

        /**
        * @brief Compiler abstraction for returning from an ISR if no OS is present.
        * @implements DBASE05006
        */
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        */
        #define EXIT_INTERRUPT()
    #else
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        * @implements DBASE05016
        */
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */            
/*
* @violates @ref Mcal_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/     
        #define ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)

        /**
        * @brief Compiler abstraction for returning from an ISR if no OS is present.
        * @implements DBASE05006
        */
        /* @errata  ERR_IPV_INTC_0001 */
        #ifdef ERR_IPV_INTC_0001
          #if (ERR_IPV_INTC_0001 == STD_ON)
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */            
/*
* @violates @ref Mcal_h_REF_5 This is not a standard library macro, 
*/    
            #define EXIT_INTERRUPT()        SuspendAllInterrupts(); *((volatile uint32 *)((uint32)INTC_BASEADDR + (uint32)INTC_EOIR_OFFSET)) = 0U; *((volatile uint32 *)((uint32)INTC_BASEADDR + (uint32)INTC_EOIR_OFFSET)) = 0U
          #else
            /*
            * @violates @ref Mcal_h_REF_1 A function should be used in
            * preference to a function-like macro.
            */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */                
/*
* @violates @ref Mcal_h_REF_5 This is not a standard library macro, 
*/    
            #define EXIT_INTERRUPT()        SuspendAllInterrupts(); *((volatile uint32 *)((uint32)INTC_BASEADDR + (uint32)INTC_EOIR_OFFSET)) = 0U
          #endif
        #else
            /*
            * @violates @ref Mcal_h_REF_1 A function should be used in
            * preference to a function-like macro.
            */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */                
/*
* @violates @ref Mcal_h_REF_5 This is not a standard library macro, 
*/    
            #define EXIT_INTERRUPT()        SuspendAllInterrupts(); *((volatile uint32 *)((uint32)INTC_BASEADDR + (uint32)INTC_EOIR_OFFSET)) = 0U
        #endif
    #endif /*USE_SW_VECTOR_MODE*/

    /**
    * @brief Compiler abstraction for disabling all interrupts if no OS is present.
    * @implements DBASE05021
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define SuspendAllInterrupts() ASM_KEYWORD(" wrteei 0")

    /**
    * @brief Compiler abstraction for re-enabling all interrupts if no OS is present.
    * @implements DBASE05020
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define ResumeAllInterrupts() ASM_KEYWORD(" wrteei 1")
#else
    #include "Os.h"
    /**
    * @brief Compiler abstraction for returning from an ISR if OS is present must be empty.
    * @implements DBASE05006
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXIT_INTERRUPT()
#endif

/**
* @brief The compiler abstraction for pointer to pointer to variable.
* @implements DBASE05025
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */
/*
* @violates @ref Mcal_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/     
#define P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **

/**
* @brief The compiler abstraction for pointer to pointer to constant.
* @implements DBASE05026
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */
/*
* @violates @ref Mcal_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/     
#define P2P2CONST(ptrtype, memclass, ptrclass) const ptrtype **

/**
* @brief The compiler abstraction for const pointer to function.
* @implements DBASE05031
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */
/*
* @violates @ref Mcal_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/    
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)

/**
* @brief The compiler abstraction shall provide the STATIC define for abstraction of compiler
*        keyword static. Keep here for backward compatibility. It has been removed from ASR4.0
* @implements DBASE05030
*/
  /*
    * @violates @ref Mcal_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
#define STATIC static

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Typedef for DEM error management implemented by MCAL drivers
* @implements DBASE05032
*/
typedef struct
{
    uint32 state;   /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 id ;     /**< ID of DEM error (0 if STD_OFF)*/
}Mcal_DemErrorType; 
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MCAL_H */

/** @} */
