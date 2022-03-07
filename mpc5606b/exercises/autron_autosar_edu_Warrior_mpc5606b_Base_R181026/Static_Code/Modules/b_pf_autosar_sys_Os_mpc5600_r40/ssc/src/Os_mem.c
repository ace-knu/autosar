/**
*   @file    Os_mem.c
*   @version 4.0.69
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Power Architecture
*   Peripheral           : e200z0/e200z0h
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.69
*   Build Version        : MPC5600V4_OS_4.0.69_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
* @section Os_mem_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_mem_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_mem_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OSLongJmp is used for switching context and it is not supposed 
* to return to the place where it is called.
*
* @section Os_mem_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_mem_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*/


/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/

#include <Os_task_api.h> /* for INVALID_TASK */
#include <Os_isr_api.h> /* for INVALID_ISR */
#include <Os_resource_internal_api.h>

#include <Os_memory_api.h>
#include <Os_memory_types.h>
#include <Os_memory_internal_api.h>
#include <Os_memory_internal_types.h>


#if defined(OSMEMPROTECTION)


/*
* @violates @ref Os_mem_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

OSDECLAREVAR (OSNEAR OSDWORD, OsStackDesc_);            /* address of MPU osstack descriptor per core */
OSDECLAREVAR (OSNEAR OSDWORD, OsRunableStackDesc_);     /* address of MPU runable stack descriptor per core */

#if (OSNNOTTRUSTEDAPPS > 1U)
OSDECLAREVAR (OSNEAR OSAPPLICATIONTYPE, OsLastApp_);    /* Last nontrusted application ID */
#endif

/*
* @violates @ref Os_mem_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#endif /* defined(OSMEMPROTECTION) */


#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSMEMPROTECTION)

/* Array of application data section addresses (in RAM) */
#if (OSNMEMDATA0 > 0U)
OSMP_DSADDR_CB OsMPDataRAM[OSNNOTTRUSTEDAPPS];
#endif

#if (OSNMEMDATA1 > 0U)
OSMP_DSADDR_CB OsMPDataRAM_1[OSNNOTTRUSTEDAPPS];
#endif

#if (OSNMEMDATA2 > 0U)
OSMP_DSADDR_CB OsMPDataRAM_2[OSNNOTTRUSTEDAPPS];
#endif

/* Array of application peripheral section addresses (in RAM) */
#if defined(OSPERIPHERALS0)
OSMP_DSADDR_CB OsMPPeripheralRAM[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS1)
OSMP_DSADDR_CB OsMPPeripheralRAM_1[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS2)
OSMP_DSADDR_CB OsMPPeripheralRAM_2[OSNNOTTRUSTEDAPPS];
#endif

#endif /* OSMEMPROTECTION */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSGHSPPC)
#pragma ghs startdata           /* To prevent compiler to use short addressing */
#endif /* defined(OSGHSPPC) */

/**** linker defined symbols for ProtectionHandler ****/
extern char OS_BEGIN_DSADDR (ostext)[];    /* beginning of OS code section */
extern char OS_END_DSADDR (ostext)[];      /* end of OS code section */

#if defined(OSGHSPPC)
#pragma ghs enddata
#endif /* defined(OSGHSPPC) */

/* local functions prototypes */
#if defined(OSHOOKPROTECTION)
static void OSProtectionHandler (StatusType ecode);
#endif

#if defined(OSMEMPROTECTION)

static AccessType OSAppMemAccess (OSAPPLICATIONTYPE appId, OSDWORD start, OSDWORD end);

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

OSDWORD OsExceptionStack[OSEXCEPTIONSTACKSIZE];


#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#if defined(OSGHSPPC)
#pragma ghs startdata           /* To prevent compiler to use short addressing */
#endif /* defined(OSGHSPPC) */

extern char OS_BEGIN_DSADDR (osbegincode)[];  /* beginning of common code section */
extern char OS_END_DSADDR (osendcode)[];      /* end of common code section */

/**** linker defined symbols for ProtectionHandler ****/
extern char OS_BEGIN_DSADDR (osstack)[];   /* beginning of OS stack section */
extern char OS_END_DSADDR (osstack)[];     /* end of of OS stack section */


#if defined(OSGHSPPC)
#pragma ghs enddata
#endif /* defined(OSGHSPPC) */


#define OSMPU_GRANULARITY       (0x20UL)  /* MPU granularity */


#define OS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/* Indexes for OsMPU_ConstRGD[] */
typedef enum
{
    OSRGD_SYS1,
    OSRGD_STACK,
    OSRGD_SYS2,
    OSRGD_CODE
    #if defined(OSINTRAMSIZE)
    ,
    OSRGD_INTRAM
    #endif
    #if defined(OSINTRAM2SIZE)
    ,
    OSRGD_INTRAM2
    #endif
} OSConstRGDIndex;

/* MPU region descriptor structure */
typedef struct
{
    OSDWORD word0;
    OSDWORD word1;
    OSDWORD word2;
} OsMPU_RGD;

static void OSFillConstDesc (OSWORD descNum);
#if (OSNNOTTRUSTEDAPPS > 0U)
static OSWORD OSPrepareApp (OSWORD descOffset, OSMP_DSADDR const *mpdatarom, OSMP_DSADDR_CB * mpdataram);
#endif


/* Memory region rights structure */
typedef struct
{
    OSDWORD start;
    OSDWORD end;
    AccessType rights;
} OSMEMRGN;



const OSMEMRGN OsMemRgn[] =        /* the size is not declared because it highly depends on configuration (CR12) */
{
    #ifdef OSINTRAMSIZE
    {
        (OSDWORD) (OSINTRAMADDR),
        (OSDWORD) (OSINTRAMADDR + (OSINTRAMSIZE - 1U)),
        (AccessType) (OSMP_S | OSMP_E | OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSINTRAM2SIZE
    {
        (OSDWORD) (OSINTRAM2ADDR),
        (OSDWORD) (OSINTRAM2ADDR + (OSINTRAM2SIZE - 1U)),
        (AccessType) (OSMP_S | OSMP_E | OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSEXTRAMSIZE
    {
        (OSDWORD) (OSEXTRAMADDR),
        (OSDWORD) (OSEXTRAMADDR + (OSEXTRAMSIZE - 1U)),
        (AccessType) (OSMP_S | OSMP_E | OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSINTROMSIZE
    {
        (OSDWORD) (OSINTROMADDR),
        (OSDWORD) (OSINTROMADDR + (OSINTROMSIZE - 1U)),
        (AccessType) (OSMP_E | OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSEXTROMSIZE
    {
        (OSDWORD) (OSEXTROMADDR),
        (OSDWORD) (OSEXTROMADDR + (OSEXTROMSIZE - 1U)),
        (AccessType) (OSMP_E | OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSBRIDGE1SIZE
    {
        (OSDWORD) (OSBRIDGE1ADDR),
        (OSDWORD) (OSBRIDGE1ADDR + (OSBRIDGE1SIZE - 1U)),
        (AccessType) (OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSBRIDGE2SIZE
    {
        (OSDWORD) (OSBRIDGE2ADDR),
        (OSDWORD) (OSBRIDGE2ADDR + (OSBRIDGE2SIZE - 1U)),
        (AccessType) (OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSBRIDGE3SIZE
    {
        (OSDWORD) (OSBRIDGE3ADDR),
        (OSDWORD) (OSBRIDGE3ADDR + (OSBRIDGE3SIZE - 1U)),
        (AccessType) (OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSBRIDGE4SIZE
    {
        (OSDWORD) (OSBRIDGE4ADDR),
        (OSDWORD) (OSBRIDGE4ADDR + (OSBRIDGE4SIZE - 1U)),
        (AccessType) (OSMP_R | OSMP_W)
    },
    #endif

    #ifdef OSBRIDGE5SIZE
    {
        (OSDWORD) (OSBRIDGE5ADDR),
        (OSDWORD) (OSBRIDGE5ADDR + (OSBRIDGE5SIZE - 1U)),
        (AccessType) (OSMP_R | OSMP_W)
    }
    #endif
};

/* Rights for dynamic stack descriptors */
#define OSMPU_STACK_RIGHTS   (OSMPU_RGD_W2_M0( OSMPU_PE_OFF, 0U, OSMPU_UM_R | OSMPU_UM_W ) | OSMPU_RGD_W2_OTHERS())

/* Constant MPU region descriptors */
const OsMPU_RGD OsMPU_ConstRGD[] = {  /* the size is not declared because it highly depends on configuration (CR12) */

    /* Descriptor:  <start of osstack - 1>,
       M0/M1 SM: "RWX", M0 UM: "---" , M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        0ul,
        (OSDWORD) OS_BEGIN_DSADDR (osstack),
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_RWX, 0U) |
        OSMPU_RGD_W2_OTHERS ()
    },

    /* Descriptor for osstack: <start of osstack> - <end of osstack - 1>,
       M0 SU : "RW-", M0 UM: "---", M4: "---",other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        (OSDWORD) OS_BEGIN_DSADDR (osstack),
        (OSDWORD) OS_END_DSADDR (osstack),
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_RW, 0U) | OSMPU_RGD_W2_OTHERS ()
    },


    /* Descriptor: <end of osstack> - (0x100000000-1),
       M0/M1 SM: "RWX", M0 UM and M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        (OSDWORD) OS_END_DSADDR (osstack),
        0ul,                       /* Note: 0lu - 1lu = 0xfffffffflu */
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_RWX, 0U) |
        OSMPU_RGD_W2_OTHERS (),
     },

    /* Descriptor: <start of .text> - <end of .osrodata - 1>,
       M0/M1 UM/SM: "RWX", M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        (OSDWORD) OS_BEGIN_DSADDR (osbegincode),
        (OSDWORD) OS_END_DSADDR (osendcode),
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, 0U, OSMPU_UM_R | OSMPU_UM_X) |
        OSMPU_RGD_W2_OTHERS (),
    },

    #if defined(OSINTRAMSIZE)
    /* Descriptor: whole <internal RAM>,
       M0/M1 SM: "RW-", M0/M1 UM: "R--", M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        OSINTRAMADDR,
        OSINTRAMADDR + OSINTRAMSIZE,
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_UM, OSMPU_UM_R) |
        OSMPU_RGD_W2_OTHERS (),
     },
    #endif
    #if defined(OSINTRAM2SIZE)
    /* Descriptor: whole <internal RAM2>, 
       M0/M1 SM: "RW-", M0/M1 UM: "R--", M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        OSINTRAM2ADDR,
        OSINTRAM2ADDR + OSINTRAM2SIZE,
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_UM, OSMPU_UM_R) |
        OSMPU_RGD_W2_OTHERS (),
    },
    #endif
    #if defined(OSEXTRAMSIZE)
    /* Descriptor: whole <External RAM>, 
       M0/M1 SM: "RW-", M0/M1 UM: "R--", M4: "---", other masters depend on OSMPU_RGD_W2_OTHERS() */
    {
        OSEXTRAMADDR,
        OSEXTRAMADDR + OSEXTRAMSIZE,
        OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, OSMPU_SM_UM, OSMPU_UM_R) |
        OSMPU_RGD_W2_OTHERS (),
    },
    #endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*****************************************************************************
 * Function    : OSFillRights
 *
 * Description : Fill rights in the given descriptor
 *
 * Returns     : none
 *
 * Notes       : none

 *****************************************************************************/
static OSINLINE void
OSFillRights (OSWORD descNum, OSDWORD rights)
{
    OSMPUx_RGD( descNum, OSMPU_RGD_WORD2 ) = rights;
}

/*****************************************************************************
 * Function    : OSFillConstDesc
 *
 * Description : Fill constant descriptor
 *
 * Returns     : none
 *
 * Notes       : none

 *****************************************************************************/
static void
OSFillConstDesc (OSWORD descNum)
{
    OSDWORD word1;
    OsMPU_RGD const *rgd;

    /*
    * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    rgd = OsMPU_ConstRGD + descNum;

    if (rgd->word0 != rgd->word1)
    {
        OSMPUx_RGD (descNum, OSMPU_RGD_WORD0) = rgd->word0;

        word1 = rgd->word1;
        if ((word1 & (OSMPU_GRANULARITY - 1UL)) == 0UL)   /* end address is aligned by MPU granularity */
        {
            word1--;
        }
        OSMPUx_RGD (descNum, OSMPU_RGD_WORD1) = word1;
        OSMPUx_RGD (descNum, OSMPU_RGD_WORD2) = rgd->word2;
        OSMPUx_RGD (descNum, OSMPU_RGD_WORD3) = OSMPU_RGD_W3_VLD;
    }
    else
    {
        OSMPUx_RGD (descNum, OSMPU_RGD_WORD3) = 0U;
    }
}


/*****************************************************************************
 * Function    : OSInitMemProtection
 *
 * Description : initializes descriptors on both MPUs and switches MPUs on. 
 *
 * Returns     : none
 *
 * Notes       : none
 *****************************************************************************/
void
OSInitMemProtection (void)
{
    OSWORD i;

    {
        /* Put off MPU */
        OSMPU_CESR = 0U;

        /* Set constant MPU region descriptors. */
        for (i = 0U; i < (sizeof (OsMPU_ConstRGD) / sizeof (OsMPU_ConstRGD[0])); i++)
        {
            OSFillConstDesc (i);
        }

        /* Set rights for runable stack descriptor on master core */
        OSFillRights (i, (OSDWORD)OSMPU_STACK_RIGHTS);
        OSRUNABLESTACKDESC = OSMPUx_RGD_GETADDR (i);     /* pointer to runable stack descriptor */
        OSSTACKDESC = OSMPUx_RGD_GETADDR (OSRGD_STACK);  /* pointer to OS stack descriptor */
        i++;

       
        #if (OSNNOTTRUSTEDAPPS > 0U)
        #if (OSNMEMDATA0 > 0U)
        i += OSPrepareApp (i, OsMPData, OsMPDataRAM);
        #endif
        #if (OSNMEMDATA1 > 0U)
        i += OSPrepareApp (i, OsMPData_1, OsMPDataRAM_1);
        #endif
        #if (OSNMEMDATA2 > 0U)
        i += OSPrepareApp (i, OsMPData_2, OsMPDataRAM_2);
        #endif
        #if defined(OSPERIPHERALS0)
        i += OSPrepareApp (i, OsMPPeripheral, OsMPPeripheralRAM);
        #endif
        #if defined(OSPERIPHERALS1)
        i += OSPrepareApp (i, OsMPPeripheral_1, OsMPPeripheralRAM_1);
        #endif
        #if defined(OSPERIPHERALS2)
        i += OSPrepareApp (i, OsMPPeripheral_2, OsMPPeripheralRAM_2);
        #endif
        #endif

        /* Put off other descriptors */
        for (; i <= OSMPU_RGD_LAST; i++)
        {
            OSMPUx_RGD (i, OSMPU_RGD_WORD3) = 0U;
        }
    }

    #if (OSNNOTTRUSTEDAPPS > 1U)
    OsLastApp = OSINVALID_OSAPPLICATION;
    #endif

    #if (OSNNOTTRUSTEDAPPS == 1U)
    OSSetCurApp (0);
    OSMP_DATA_DESC ();
    #endif

    OSStackEnableAccess ();     /* RW rigths for all osstack area */

    OSMPU_CESR = OSMPU_CESR_VLD;        /* switch on MPU */

}

#if (OSNNOTTRUSTEDAPPS > 0U)
/*****************************************************************************
 * Function    : OSPrepareApp
 *
 * Description : Sets rights of applications in corresponding MPU descriptor.
 *               Saves address of this MPU descriptor.
 *               Increments the number of used descriptors.
 *
 * Returns :     number of necessary descriptors
 * 
 * Notes :       returned value cannot be more than OSNCORES
 *****************************************************************************/
static OSWORD
OSPrepareApp (OSWORD descNum, OSMP_DSADDR const *mpdatarom, OSMP_DSADDR_CB * mpdataram)
{
    OSWORD i;

    for (i = 0U; i < OSNNOTTRUSTEDAPPS; i++)
    {
        mpdataram[i].descaddr = OSMPUx_RGD_GETADDR (descNum);

        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSMP_PREP_DESC (mpdatarom, mpdataram, i);
    }
    OSFillRights (descNum, OSMPU_RGD_W2_M0 (OSMPU_PE_OFF, 0UL, OSMPU_UM_R | OSMPU_UM_W) | OSMPU_RGD_W2_OTHERS ());
    return 1U;
}
#endif /* (OSNNOTTRUSTEDAPPS > 0U) */


/*****************************************************************************
 * Function    : OSAppMemAccess
 *
 * Description : Determinate access type to memory area for application
 *
 * Returns     : AccessType
 *
 * Notes       : none
 *****************************************************************************/
static AccessType
OSAppMemAccess (OSAPPLICATIONTYPE appId, OSDWORD start, OSDWORD end)
{
    #if defined(OSCWPPC)
    #pragma unused( appId ) /* to suppress warning about unused variable */
    #endif

    OSBYTE i;
    OSDWORD stackBegin, stackEnd;

    #if (OSNNOTTRUSTEDAPPS > 0U)
    if ( OSMP_IS_NONTRUSTEDAPP (appId)
        #if (OSNTRUSTEDFUNCTIONS > 0U)
        && (0U == OsAppTable[appId].tfContext)
        #endif
        )
    {   /* Nontrusted application */
        #if (OSNMEMDATA0 > 0U)
        if ((start >= OsMPData[appId].startaddr) && (end < OsMPData[appId].endaddr))
        {   /* given ISR or Task application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        #if (OSNMEMDATA1 > 0U)
        if ((start >= OsMPData_1[appId].startaddr) && (end < OsMPData_1[appId].endaddr))
        {   /* given ISR or Task application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        #if (OSNMEMDATA2 > 0U)
        if ((start >= OsMPData_2[appId].startaddr) && (end < OsMPData_2[appId].endaddr))
        {   /* given ISR or Task application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        #if defined(OSPERIPHERALS0)
        if ((start >= OsMPPeripheral[appId].startaddr) && (end <= OsMPPeripheral[appId].endaddr))
        {   /* given ISR or Task application peripheral */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        #if defined(OSPERIPHERALS1)
        if ((start >= OsMPPeripheral_1[appId].startaddr) && (end <= OsMPPeripheral_1[appId].endaddr))
        {   /* given ISR or Task application peripheral */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        #if defined(OSPERIPHERALS2)
        if ((start >= OsMPPeripheral_2[appId].startaddr) && (end <= OsMPPeripheral_2[appId].endaddr))
        {   /* given ISR or Task application peripheral */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_W);
        }
        #endif

        if ((start >= (OSDWORD) OS_BEGIN_DSADDR (osbegincode)) && (end < (OSDWORD) OS_END_DSADDR (osendcode)))
        {   /* code */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_R | OSMP_E);
        }
    }
    else
    #endif /* (OSNNOTTRUSTEDAPPS > 0U) */
    {   /* Trusted application */
            stackBegin = (OSDWORD) OS_BEGIN_DSADDR (osstack);
            stackEnd = (OSDWORD) OS_END_DSADDR (osstack);
        if ((start >= stackBegin) && (end < stackEnd))
        {   /* another tasks and ISRs stacks */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (0U);         /* no access */
        }
        for (i = 0U; i < (sizeof (OsMemRgn) / sizeof (OSMEMRGN)); i++)
        {
            if ((start >= OsMemRgn[i].start) && (end <= OsMemRgn[i].end))
            {
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return (OsMemRgn[i].rights);
            }
        }
    }
    return (0U); /* no access */
}

#if defined(OSHOOKERROR) || defined(OSHOOKPROTECTION) || defined(OSHOOKPRETASK) || \
    defined(OSHOOKPOSTTASK) || defined(OSHOOKSTARTUP) || defined(OSHOOKSHUTDOWN) || \
    defined(OSIOC)
/******************************************************************************
 * Function :   OSCheckRAMAccess
 *
 * Description: Checks the OS-Application read access for any application,
 *              write access for trusted application to the RAM area
 *
 * Returns:     OSTRUE - if read/write access is permitted,
 *              otherwise - OSFALSE.
 *            
 *****************************************************************************/
static OSINLINE AccessType
OSCheckRAMAccess (OSDWORD startAddr, OSDWORD endAddr)
{
    #if defined(OSINTRAMSIZE)
    if ((startAddr >= OSINTRAMADDR) && (endAddr <= (OSINTRAMADDR + OSINTRAMSIZE)))
    {   /* begin of internal RAM <= address, endAddr <= end of internal RAM */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSTRUE;
    }
    #endif
    #if defined(OSINTRAM2SIZE)
    if ((startAddr >= OSINTRAM2ADDR) && (endAddr <= (OSINTRAM2ADDR + OSINTRAM2SIZE)))
    {   /* begin of internal RAM2 <= address, endAddr <= end of internal RAM2 */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSTRUE;
    }
    #endif
    #if defined(OSEXTRAMSIZE)
    if ((startAddr >= OSEXTRAMADDR) && (endAddr <= (OSEXTRAMADDR + OSEXTRAMSIZE)))
    {   /* begin of external RAM <= address, endAddr <= end of external RAM */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSTRUE;
    }
    #endif
    return OSFALSE;
}
#endif

/******************************************************************************
 * Function :   OSCheckMemoryAccess
 *
 * Description: Checks the OS-Application read/write access to the data area.
 *
 * Returns:     OSTRUE - if read/write access is permitted (area is stack or application data),
 *              otherwise - OSFALSE.
 *            
 *****************************************************************************/
static OSINLINE AccessType
OSCheckMemoryAccess (OSDWORD startAddr, OSDWORD endAddr)
{
    OSDWORD stackBottom, stackTop, stackBegin, stackEnd;

    #if defined(OSAPPHOOKSHUTDOWN)
    if (OsIsrLevel & ( OSISRLEVELHOOKAPPSHUTDOWN ))
    {   /* stack that used in application specific shutdown hook in ShutdownOS */
        stackBottom = (OSDWORD) (OSSTACKBOTTOM);
        stackTop = (OSDWORD) (OSSTACKTOP - OSSTKADDS);
    }
    else
    #endif
    #if (OSNUSERISR > 0U)
    if (OSISRLEVELMASKED != 0U)
    {
        OS_ISRTYPEPTR handlerPtr; /* pointer to ISR descriptor */
        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];
        stackBottom = (OSDWORD) (handlerPtr->isrBos);
        stackTop = (OSDWORD) (handlerPtr->stackPtr);
    }
    else
    #endif /* (OSNUSERISR > 0U) */
    {
        stackBottom = (OSDWORD) (OsRunning->bos);
        stackTop = (OSDWORD) (OsRunning->tos);
    }
    if ((startAddr >= stackBottom) && (endAddr < stackTop))
    {   /* current runnable task, ISR, hook stack */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSTRUE;
    }

    #if (OSNNOTTRUSTEDAPPS > 0U)
    if (OSMP_IS_TRUSTEDAPP (OSGetCurApp ())
    #if (OSNTRUSTEDFUNCTIONS > 0U)
        || (0U != OsAppTable[OSGetCurApp ()].tfContext)
    #endif
        )
    {   /* trusted application */
    #endif
            stackBegin = (OSDWORD) OS_BEGIN_DSADDR (osstack);
            stackEnd = (OSDWORD) OS_END_DSADDR (osstack);
        if ((startAddr >= stackBegin) && (endAddr < stackEnd))
        {   /* another tasks and ISRs stacks */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSFALSE;
        }
        #if defined(OSINTRAMSIZE)
        if ((startAddr >= OSINTRAMADDR) && (endAddr <= (OSINTRAMADDR + OSINTRAMSIZE)))
        {   /* begin of internal RAM <= startAddr, endAddr <= end of internal RAM */
            if (endAddr < stackBegin)
            {   /* begin of internal RAM <= startAddr, endAddr < begin of osstack */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
            if (startAddr >= stackEnd)
            {   /* end of osstack < startAddr, endAddr <= end of internal RAM */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
        }
        #endif

        #if defined(OSINTRAM2SIZE)
        if ((startAddr >= OSINTRAM2ADDR) && (endAddr <= (OSINTRAM2ADDR + OSINTRAM2SIZE)))
        {   /* begin of internal RAM <= startAddr, endAddr <= end of internal RAM */
            if (endAddr < stackBegin)
            {   /* begin of internal RAM <= startAddr, endAddr < begin of osstack */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
            if (startAddr >= stackEnd)
            {   /* end of osstack < startAddr, endAddr <= end of internal RAM */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
        }
        #endif

        #if defined(OSEXTRAMSIZE)
        if ((startAddr >= OSEXTRAMADDR) && (endAddr <= (OSEXTRAMADDR + OSEXTRAMSIZE)))
        {   /* begin of external RAM <= startAddr, endAddr <= end of external RAM */
            if (endAddr < stackBegin)
            {   /* begin of external RAM <= startAddr, endAddr < begin of osstack */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
            if (startAddr >= stackEnd)
            {   /* end of osstack < startAddr, endAddr <= end of external RAM */
                /*
                 * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return OSTRUE;
            }
        }
        #endif
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSFALSE;
    #if (OSNNOTTRUSTEDAPPS > 0U)
    }
    else
    {   /* nontrusted application */
    #if (OSNMEMDATA0 > 0U)
        if ((startAddr >= OsMPData[OSGetCurApp ()].startaddr) && (endAddr <= OsMPData[OSGetCurApp ()].endaddr))
        {   /* current nontrusted application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSTRUE;
        }
    #endif
    #if (OSNMEMDATA1 > 0U)
        if ((startAddr >= OsMPData_1[OSGetCurApp ()].startaddr) && (endAddr <= OsMPData_1[OSGetCurApp ()].endaddr))
        {   /* current nontrusted application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSTRUE;
        }
    #endif
    #if (OSNMEMDATA2 > 0U)
        if ((startAddr >= OsMPData_2[OSGetCurApp ()].startaddr) && (endAddr <= OsMPData_2[OSGetCurApp ()].endaddr))
        {   /* current nontrusted application data */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSTRUE;
        }
    #endif
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSFALSE;
    }
    #endif /* (OSNNOTTRUSTEDAPPS > 0U) */
}

/******************************************************************************
 * Function :   OSCheckWriteAccess
 *
 * Description: Checks the OS-Application write access to the data area.
 *
 * Returns:     OSTRUE - if write access is permitted (area is stack or application data),
 *              otherwise - OSFALSE.
 *            
 *****************************************************************************/
AccessType
OSCheckWriteAccess (MemoryStartAddressType address, MemorySizeType size)
{
    register OSDWORD endAddr = (OSDWORD) address + size;

    #if defined(OSHOOKERROR) || defined(OSHOOKPROTECTION) || \
    defined(OSHOOKPRETASK) || defined(OSHOOKPOSTTASK) || \
    defined(OSHOOKSTARTUP) || defined(OSHOOKSHUTDOWN)
    if (OsIsrLevel & (OSISRLEVELHOOKERROR | OSISRLEVELHOOKPROTECTION |
                      OSISRLEVELHOOKTASK | OSISRLEVELHOOKSTARTUP | OSISRLEVELHOOKSHUTDOWN ))
    {
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSCheckRAMAccess ((OSDWORD) address, endAddr);
    }
    #endif

    return OSCheckMemoryAccess ((OSDWORD) address, endAddr);
}

#if defined(OSIOC)
/******************************************************************************
 * Function :   OSIOCCheckReadAccess
 *
 * Description: Checks the OS-Application read access to the data area.
 *
 * Returns:     OSTRUE - if read access is permitted (area is stack or application data),
 *              otherwise - OSFALSE.
 *            
 *****************************************************************************/
AccessType
OSIOCCheckReadAccess (MemoryStartAddressType address, MemorySizeType size)
{
    register OSDWORD endAddr = (OSDWORD) address + size;

    if (((OSDWORD) address >= (OSDWORD) OS_BEGIN_DSADDR (osbegincode)) && (endAddr < (OSDWORD) OS_END_DSADDR (osendcode)))
    {   /* code */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSTRUE);
    }
    return OSCheckRAMAccess ((OSDWORD) address, endAddr);
}
#endif /* defined(OSIOC) */

#if !defined(OSNOISR2)
/*****************************************************************************
 * Function :   OS_CheckISRMemoryAccess
 *
 * Description: checks whether or not the private memory section of the ISR
 *              is within the memory section 
 *
 * Return:      Set of access rights for the specified region of memory.
 *              0 - for no access.    
 *            
 ******************************************************************************/
AccessType
OS_CheckISRMemoryAccess (ISRType handlerId, MemoryStartAddressType address, MemorySizeType size)
{
    const OS_ISRTYPE *handlerPtr;
    AccessType access;
    OSDWORD end;

    OSOrtiSetServiceWatch (OSServiceId_CheckISRMemoryAccess);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_CheckISRMemoryAccess, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_CheckISRMemoryAccess);
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (0U);
        }
        else
        #endif /* defined(OSEXTSTATUS) */
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_CheckISRMemoryAccess, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_CheckISRMemoryAccess);
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (0U);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSISRIDISINVALID (handlerId))
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_ID, OSServiceId_CheckISRMemoryAccess, handlerId); /* invalid ID */
        #endif
        OSOrtiServiceWatchOnExit (OSServiceId_CheckISRMemoryAccess);
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (0U);
    }
    #endif /* defined(OSEXTSTATUS) */

    handlerPtr = &(OsIsrTable[OS_GETOBJIND (handlerId)]);

    #if defined(OSEXTSTATUS)
    if (handlerPtr->type > OSISR1)     /* if it is a system interrupt */
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_ID, OSServiceId_CheckISRMemoryAccess, handlerId); /* invalid ID */
        #endif
        OSOrtiServiceWatchOnExit (OSServiceId_CheckISRMemoryAccess);
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (0U);
    }
    #endif /* defined(OSEXTSTATUS) */

    end = (OSDWORD) (address) + (size - 1U);
    if (((OSDWORD) (address) >= (OSDWORD) (handlerPtr->isrBos)) && (end < (OSDWORD) (handlerPtr->stackPtr)))
    {                           /* given ISR stack */
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSMP_S | OSMP_R | OSMP_W);
    }

    access = OSAppMemAccess (handlerPtr->appId, (OSDWORD) address, end);

    OSOrtiServiceWatchOnExit (OSServiceId_CheckISRMemoryAccess);

    return (access);
}
#endif  /* !defined(OSNOISR2) */

/*****************************************************************************
 * Function :   OS_CheckTaskMemoryAccess
 *
 * Description: checks whether or not the private memory section of the task
 *              is within the memory section 
 *
 * Return:      Set of access rights for the specified region of memory.
 *              0 - for no access.    
 *            
 ******************************************************************************/
AccessType
OS_CheckTaskMemoryAccess (TaskType taskId, MemoryStartAddressType address, MemorySizeType size)
{
    const OSTSKCB *task;
    AccessType access;
    OSDWORD end;

    OSOrtiSetServiceWatch (OSServiceId_CheckTaskMemoryAccess);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_CheckTaskMemoryAccess, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_CheckTaskMemoryAccess);
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (0U);
        }
        else
        #endif /* defined(OSEXTSTATUS) */
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_CheckTaskMemoryAccess, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_CheckTaskMemoryAccess);
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (0U);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_ID, OSServiceId_CheckTaskMemoryAccess, taskId);       /* invalid ID */
        #endif
        OSOrtiServiceWatchOnExit (OSServiceId_CheckTaskMemoryAccess);
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (0U);
    }
    #endif

    task = &(OsTaskTable[OS_GETOBJIND (taskId)]);
    end = (OSDWORD) (address) + (size - 1U);
    #if (OSNTSKS != OSNXTSKS)
    if (task->status & (OSTSKEXTENDED | OSTCBNOSUSPENDED))
    {                           /* check stack area only for extended tasks or nonsuspended basic tasks */
    #endif
        if (((OSDWORD) (address) >= (OSDWORD) task->bos) && (end < (OSDWORD) task->tos))
        {   /* given Task stack */
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (OSMP_S | OSMP_R | OSMP_W);
        }
    #if (OSNTSKS != OSNXTSKS)
    }
    #endif

    access = OSAppMemAccess (task->appId, (OSDWORD) address, end);

    OSOrtiServiceWatchOnExit (OSServiceId_CheckTaskMemoryAccess);
    return (access);
}
#endif /* defined(OSMEMPROTECTION) */

#if defined(OSMEMPROTECTION)
#if (OSNTRUSTEDFUNCTIONS > 0U)
/******************************************************************************
* Function:    OS_CallTrustedFunction
*
* Description: calls a trusted function written by user 
*
* Return: E_OK                       no errors 
*         E_OS_DISABLEDINT           service call while interrupts disabled
*         E_OS_CALLEVEL (ext.status) service call from wrong context
*         E_OS_SERVICE_ID            trusted function is not configured
******************************************************************************/
StatusType
OS_CallTrustedFunction (TrustedFunctionIndexType ix, TrustedFunctionParameterRefType ptr)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */
    OSAPPLICATIONTYPE curApp;

    OSAPPCB *app;
    OSBYTE *tfContextRef;

    OSOrtiSetServiceWatch (OSServiceId_CallTrustedFunction);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_CallTrustedFunction, ix);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_CallTrustedFunction, ix);
        }
    }
    #endif /* OSCHECKCONTEXT */

    if (ix > (OSNTRUSTEDFUNCTIONS - 1U))
    {
        /*
         * @violates @ref Os_mem_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_SERVICEID, OSServiceId_CallTrustedFunction, ix);
    }


    curApp = (OSAPPLICATIONTYPE)OSGetCurApp ();


    app = &OsAppTable[curApp];

    tfContextRef = &app->tfContext;

    OSDIS (save);

    if (0U == *tfContextRef)
    {                           /* if it isn't nested call of trusted function */
        OSDisableTasks4App (app);       /* clear scheduler vector mask for tasks of current application */
        #if (OSNUSERISR > 0U)
        OSDisableISRs4App (curApp);     /* disable interrupts of category 2 of current application */
        #endif
    }

    (*tfContextRef)++;          /* increment counter of nested calls of trusted function */

    OSRI (save);

    OsTrustedFunctionsTable[ix] (ix, ptr);

    OSDIS (save);

    (*tfContextRef)--;          /* decrement counter of nested calls of trusted function */

    if (0U == *tfContextRef)
    {                           /* if it isn't nested call of trusted function */

        #if (OSNUSERISR > 0U)
        OSEnableISRs4App (curApp);      /* enable interrupts of category 2 of current application */
        #endif
        OSEnableTasks4App (app);        /* set scheduler vector mask for tasks of current application */

        #if defined(OSTPBUDGET)
        if (app->tpError != 0U)  /* an TP violation has occured inside the trusted function */
        {
            OSTPTimerInterruptForce (OSTPFORCEPOSTPONED);       /* Force TP interrupt */
        }
        else
        #endif
        {
            /* comments added to avoid MISRA violation: 
             * Note 960: Violates MISRA 2004 Required Rule 14.10, else-branch must have a comment or action 
             */
            OSDISPATCH ();
        }
    }
    OSRI (save);


    OSOrtiServiceWatchOnExit (OSServiceId_CallTrustedFunction);
    return E_OK;
}
#endif /* (OSNTRUSTEDFUNCTIONS > 0U */
#endif /* OSMEMPROTECTION */

/***************************************************************************
 * inline function:    OSExceptionExit
 *
 * Description: calls ProtectionHandler or ShutdownOS
 *
 * Returns:     never
 *
 **************************************************************************/
static OSINLINE void
OSExceptionExit (StatusType ecode, OSDWORD srr0, OSDWORD srr1)
{
    #if defined(OSCWPPC)
    #pragma unused( srr0, srr1 ) /* to suppress warning about unused variable */
    #endif

    OSPUTERROR (ecode);

    #if defined( OSHOOKPROTECTION )
    /* if exception occurs in OS code itself */
    if (((srr0 >= (OSDWORD) OS_BEGIN_DSADDR (ostext)) && (srr0 < (OSDWORD) OS_END_DSADDR (ostext)) && ((srr1 & OSMSR_PR) == 0U))
        /* if exception occurs in any system-wide hooks */
        || ((OsIsrLevel & OSISRLEVELHOOKANYSYSTEM) != 0U)
        #if (OSNISR > 0U)
        /* if exception occurs not in TASK or ISR cat.2  */
        || (OSISRGetPrio () > OSHIGHISRPRIO)
        #endif
        /* if exception occurs before OsStarted variable initialization */
        || (OSTRUE != OsStarted)
       )
    {
        OSShutdownOS (ecode);
    }

    OSProtectionHandler (ecode);
    #else
    OSShutdownOS (ecode);
    #endif /* defined( OSHOOKPROTECTION ) */
}

/***************************************************************************
 * Function:    OSExceptionError
 *
 * Description: it is called when critical or noncritical core exception occurs
 *
 * Returns:     never
 *
 **************************************************************************/
void
OSExceptionError (OSDWORD srr0, OSDWORD srr1)
{
    StatusType ecode;

    #if defined(OSMEMPROTECTION)
    OSDWORD sperr;

    sperr = (OSDWORD)(OSMPU_CESR & OSMPU_CESR_SPERR);
    OSMPU_CESR |= sperr;
    #endif /* defined(OSMEMPROTECTION) */

    #if defined(OSMEMPROTECTION)
    if (sperr != 0U)
    {
        /* MPU exeception */
        ecode = E_OS_PROTECTION_MEMORY;
    }
    else
    {
        if ((OSGetESR () & OSESR_ST) != 0U)
        {
            ecode = E_OS_PROTECTION_MEMORY;
        }
        else
        {
            ecode = E_OS_PROTECTION_EXCEPTION;
        }
    }

    #else /* defined(OSMEMPROTECTION) */
    ecode = E_OS_PROTECTION_EXCEPTION;
    #endif /* defined(OSMEMPROTECTION) */

    OSExceptionExit (ecode, srr0, srr1);
}

/***************************************************************************
 * Function:    OSMCExceptionError
 *
 * Description: it's called when Machine Check exception occurs.
 *
 * Returns:     never
 *
 **************************************************************************/
void
OSMCExceptionError (OSDWORD srr0, OSDWORD srr1)
{
    StatusType ecode;
    #if defined(OSE200Z4) || defined(OSE200Z7) || defined(OSMEMPROTECTION)
    OSDWORD mcsr;
    #endif

    #if defined(OSMEMPROTECTION)
    OSDWORD sperr;

    sperr = (OSDWORD)(OSMPU_CESR & OSMPU_CESR_SPERR);
    OSMPU_CESR |= sperr;
    #endif /* defined(OSMEMPROTECTION) */

    #if defined(OSE200Z4) || defined(OSE200Z7) || defined(OSMEMPROTECTION)
    mcsr = OSGetMCSR ();
    #endif

    #if defined(OSE200Z4) || defined(OSE200Z7)
    {
        OSSetMCSR (mcsr);       /* clear Machine check asynchronous events */
    }
    #endif

    #if defined(OSMEMPROTECTION)
    if (sperr != 0U)
    {
        /* MPU exeception */
        ecode = E_OS_PROTECTION_MEMORY;
    }
    else
    {
        if ((mcsr & OSMCSR_EXCP_ERR) != 0U)
        {
            OSPUTERROR (E_OS_SYS_FATAL);
            OSShutdownOS (E_OS_SYS_FATAL);
        }

        if ((mcsr & OSMCSR_BUS_ERROR) != 0U)
        {
            ecode = E_OS_PROTECTION_MEMORY;
        }
        else
        {
            ecode = E_OS_PROTECTION_EXCEPTION;
        }
    }

    #else /* defined(OSMEMPROTECTION) */
    ecode = E_OS_PROTECTION_EXCEPTION;
    #endif /* defined(OSMEMPROTECTION) */

    OSExceptionExit (ecode, srr0, srr1);
}

#if defined(OSMEMPROTECTION)
/***************************************************************************
 * Function:    OSTLBException
 *
 * Description: TLB exception (data or code) .
 *
 * Returns:     never
 *
 **************************************************************************/
void
OSTLBException (OSDWORD srr0, OSDWORD srr1)
{
    OSExceptionExit (E_OS_PROTECTION_MEMORY, srr0, srr1);
}
#endif /* defined(OSMEMPROTECTION) */

#if defined(OSHOOKPROTECTION)
/****************************************************************************************
 * Function:    OSProtectionHandler
 *
 * Description: called from Memory and CPU exception handlers
 *
 * Returns:     never
 *
 ****************************************************************************************/
static void
OSProtectionHandler (StatusType ecode)
{
    ProtectionReturnType action;
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    OSISRLEVELTYPE apphook;
    #endif

    #if defined(OSAPPLICATION)
    RestartType restart = NO_RESTART;

    OsViolatorAppId = OS_MKOBJID (OBJECT_APPLICATION, (ApplicationType)OSGetCurApp ());
    #endif

    OsViolatorTaskId = INVALID_TASK;
    OsViolatorISRId = INVALID_ISR;

    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    apphook = OsIsrLevel & (OSISRLEVELHOOKAPPSTARTUP | OSISRLEVELHOOKAPPSHUTDOWN);
    #endif

    #if !defined(OSNOISR2)
    if (OSISRLEVELMASKED != 0U)
    {
        OSWORD handlerId;
        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        handlerId = OsIsrArray[OSISRLEVELMASKED - 1U] - &OsIsrTable[0];
        OsViolatorISRId = OS_MKOBJID (OBJECT_ISR, handlerId);
    }
    else
    #endif
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    if (apphook == 0U)
    #endif
    {   /* if it's not context of app. spec. Startup/Shutdown hooks */
        if (OSTSKIND (OsRunning) != OSNULLTASK)
        {
            OsViolatorTaskId = OS_MKOBJID (OBJECT_TASK, OSTSKIND (OsRunning));
        }
    }
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    else
    {
        /* to satisfy MISRA Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif

    OSOrtiSetServiceWatch (OSServiceId_ProtectionHook); /* set watch to this service */
    OSSETPROTCNXT ();
    OSCLEARSUSPENDLEVELS ();    /* [OS093] */
    action = ProtectionHook (ecode);
    OSCLRPROTCNTX ();
    OSOrtiServiceWatchOnExit (OSServiceId_ProtectionHook);      /* clear service watch on hook leaving */

    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    if (apphook != 0U)
    {                           /* if an exception occurred in Startup/Shutdown app. spec. hooks */
        OSShutdownOS (ecode);
    }
    #endif

    switch (action)
    {
        case PRO_KILLTASKISR:
            #if (OSNUSERISR > 0U)
            if (OSISRLEVELMASKED != 0U)
            {
                OSKillRunningISR ();
            }
            else
            #endif /* OSNUSERISR > 0 */
            {
                if (OSTSKIND (OsRunning) != OSNULLTASK)
                {
                    OSKillTask (OsRunning);
                }
                #if defined(OSAPPLICATION)
                else if (OSTerminateApplication ((OSAPPLICATIONTYPE)(OS_GETOBJIND (OsViolatorAppId)), NO_RESTART))
                {   /* if no running Task or ISR found */
                    break;
                }
                #endif
                else
                {
                    OSShutdownOS (ecode);
                }
            }
            break;

        case PRO_KILLAPPL_RESTART:
            #if defined(OSAPPLICATION)
            #if defined(OSHAS_RESTARTTASK)
            if (OsAppTable[OS_GETOBJIND (OsViolatorAppId)].restartTask == OSINVALID_TASK)
            #endif
            {
                /* no restart task was configured for the faulty OS-Application (OS557) */
                OSShutdownOS (ecode);
            }
            restart = RESTART;  /* no break */
            #endif /* defined(OSAPPLICATION) */

        case PRO_KILLAPPL:
            #if defined(OSAPPLICATION)
            if (OSTerminateApplication ((OSAPPLICATIONTYPE)(OS_GETOBJIND (OsViolatorAppId)), restart))
            {
                break;
            }
            /* no break. OSShutdownOS() shall be called */
            #endif
        case PRO_SHUTDOWN:
        default:
            OSShutdownOS (ecode);
    }
    OSDI ();

    if (((OsKilled & OSRUNTSKKILLED) != 0U)
        #if defined(OSISRENTRYEXIT)
        && (OSISRLEVELMASKED == 0U)
        #endif
        )
    {
        OSSETTASKMSR ();        /* set MSR for Task, EE = 1 */
        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsRunning = OSGETMAXPRIOTASK;
        OsKilled &= ~OSRUNTSKKILLED;
        OSTaskInternalDispatch ();
        /* no return here */
    }
    #if (OSNIPLS > 0U)

    /* otherwise running ISR is killed - no other option */

    OsIsrLevel--;
    /*
     * @violates @ref Os_mem_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
     * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
     */
    OSLongJmp (OsISRbufs[OSISRLEVELMASKED]);    /* back to OSInterruptDispatcher */
    #endif
}
#endif /* defined(OSHOOKPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
