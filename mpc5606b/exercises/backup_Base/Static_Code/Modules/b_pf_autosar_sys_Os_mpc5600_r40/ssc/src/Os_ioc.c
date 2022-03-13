/**
*   @file    Os_ioc.c
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
*
* @section Os_ioc_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_ioc_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_ioc_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used when memory copy performed.
*
* @section Os_ioc_c_REF_19_1_1
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

#include <Os_ioc_api.h>
#include <Os_ioc_internal_api.h>
#include <Os_ioc_internal_types.h>
#include <Os_ioc_config.h>

#if (OSNIOCGROUPBUFFERS > 0U) || (OSNIOCGROUPQUEUES > 0U)

#if defined(APPTYPESH)
#include    APPTYPESH    /* User/application specific types and definitions */
#endif
#include <Ioc.h>

#endif

#include <string.h>  /* memcpy() */


#if defined(OSIOC)

#if (OSNIOCCALLBACKS > 0U)

/*
* @violates @ref Os_ioc_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include    "Os_sections.h"

OSDECLAREVAR (OSNEAR OSIocCallbackQueue, OsIOCCallbacks_);   /* Queue for IOC callbacks */

OSNEAR OSWORD OsIOCCallbackCommId;    /* IOC communication ID for which callback shall be invoked */

/*
* @violates @ref Os_ioc_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_ioc_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include    "Os_sections.h"

#endif /* (OSNIOCCALLBACKS > 0U) */

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_ioc_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include    "Os_sections.h"

#if (OSNIOCBUFFERS > 0U)
OSNONCACHE OSIOCBUFFERCOMMCB OsIocBufferCommCB[OSNIOCBUFFERS];
#endif

#if (OSNIOCGROUPBUFFERS > 0U)
OSNONCACHE OSIOCGROUPBUFFERCOMMCB OsIocGroupBufferCommCB[OSNIOCGROUPBUFFERS];
#endif

#if (OSNIOCQUEUES > 0U)
OSNONCACHE OSIOCQUEUECOMMCB OsIocQueueCommCB[OSNIOCQUEUES];
#endif

#if (OSNIOCGROUPQUEUES > 0U)
OSNONCACHE OSIOCQUEUECOMMCB OsIocGroupQueueCommCB[OSNIOCGROUPQUEUES];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_ioc_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include    "Os_sections.h"

#endif /* defined(OSIOC) */


#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_ioc_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSIOC)

#define OSIOCQUEUE (OsIocQueueCommCB[commId-(OSNIOCBUFFERS+OSNIOCGROUPBUFFERS)])

#define OSIOCGROUPQUEUE (OsIocGroupQueueCommCB[commId-(OSNIOCBUFFERS+OSNIOCGROUPBUFFERS+OSNIOCQUEUES)])

/******************************************************************************
 * Function:     OSInitIOC
 *
 * Description:  Initialization of IOC internal structures
 *
 * Returns:      none
 *
 * Notes:        Should be called from StartOS()
 *
 ******************************************************************************/
void
OSInitIOC (void)
{
    OSCARDINAL i;

    #if (OSNIOCBUFFERS > 0U)
    for (i = 0U; i < OSNIOCBUFFERS; i++)
    {
        OsIocBufferCommCB[i].dataBuf = OsIocBufferInfo[i].dataBuf;
        OsIocBufferCommCB[i].dataSize = OsIocBufferInfo[i].dataSize;

        #if (OSNIOCCALLBACKS > 0U)
        OsIocBufferCommCB[i].next = (OSIOCCommCBType)&OsIocBufferCommCB[i];
        OsIocBufferCommCB[i].callBack = OsIocBufferInfo[i].callBack;
        #endif

        OsIocBufferCommCB[i].sndAppMask = OsIocBufferInfo[i].sndAppMask;
        OsIocBufferCommCB[i].rcvAppId = OsIocBufferInfo[i].rcvAppId;
        OsIocBufferCommCB[i].rcvAppMask = 1U << OsIocBufferInfo[i].rcvAppId;


        #if defined(OSIOCACTION)
        OsIocBufferCommCB[i].action.taskIndex = OsIocBufferInfo[i].taskIndex;

        #if defined(OSIOCSETEVENT)
        OsIocBufferCommCB[i].action.event = OsIocBufferInfo[i].event;
        #endif
        #endif
    }
    #endif /* (OSNIOCBUFFERS > 0U) */

    #if (OSNIOCGROUPBUFFERS > 0U)
    for (i = 0U; i < OSNIOCGROUPBUFFERS; i++)
    {
        #if (OSNIOCCALLBACKS > 0U)
        OsIocGroupBufferCommCB[i].next = (OSIOCCommCBType)&OsIocGroupBufferCommCB[i];
        OsIocGroupBufferCommCB[i].callBack = OsIocGroupBufferInfo[i].callBack;
        #endif

        OsIocGroupBufferCommCB[i].sndAppMask = OsIocGroupBufferInfo[i].sndAppMask;
        OsIocGroupBufferCommCB[i].rcvAppId = OsIocGroupBufferInfo[i].rcvAppId;
        OsIocGroupBufferCommCB[i].rcvAppMask = 1U << OsIocGroupBufferInfo[i].rcvAppId;


        #if defined(OSIOCACTION)
        OsIocGroupBufferCommCB[i].action.taskIndex = OsIocGroupBufferInfo[i].taskIndex;

        #if defined(OSIOCSETEVENT)
        OsIocGroupBufferCommCB[i].action.event = OsIocGroupBufferInfo[i].event;
        #endif
        #endif
    }
    #endif /* (OSNIOCGROUPBUFFERS > 0U) */

    #if (OSNIOCQUEUES > 0U)
    for (i = 0U; i < OSNIOCQUEUES; i++)
    {
        OsIocQueueCommCB[i].dataQueue = OsIocQueueInfo[i].dataQueue;
        OsIocQueueCommCB[i].dataSize  = OsIocQueueInfo[i].dataSize;
        OsIocQueueCommCB[i].queueSize = OsIocQueueInfo[i].queueSize;

        #if (OSNIOCCALLBACKS > 0U)
        OsIocQueueCommCB[i].next = (OSIOCCommCBType)&OsIocQueueCommCB[i];
        OsIocQueueCommCB[i].callBack = OsIocQueueInfo[i].callBack;
        #endif

        OsIocQueueCommCB[i].sndAppMask = OsIocQueueInfo[i].sndAppMask;
        OsIocQueueCommCB[i].rcvAppId = OsIocQueueInfo[i].rcvAppId;
        OsIocQueueCommCB[i].rcvAppMask = 1U << OsIocQueueInfo[i].rcvAppId;


        #if defined(OSIOCACTION)
        OsIocQueueCommCB[i].action.taskIndex = OsIocQueueInfo[i].taskIndex;
        #if defined(OSIOCSETEVENT)
        OsIocQueueCommCB[i].action.event = OsIocQueueInfo[i].event;
        #endif
        #endif

        OsIocQueueCommCB[i].nItems = 0U;
        OsIocQueueCommCB[i].head = 0U;
        OsIocQueueCommCB[i].tail = 0U;
        OsIocQueueCommCB[i].overflow = OSFALSE;
    }
    #endif /* OSNIOCQUEUES > 0U */

    #if (OSNIOCGROUPQUEUES > 0U)
    for (i = 0U; i < OSNIOCGROUPQUEUES; i++)
    {
        OsIocGroupQueueCommCB[i].dataQueue = OsIocGroupQueueInfo[i].dataQueue;
        OsIocGroupQueueCommCB[i].dataSize  = OsIocGroupQueueInfo[i].dataSize;
        OsIocGroupQueueCommCB[i].queueSize = OsIocGroupQueueInfo[i].queueSize;

        #if (OSNIOCCALLBACKS > 0U)
        OsIocGroupQueueCommCB[i].next = (OSIOCCommCBType)&OsIocGroupQueueCommCB[i];
        OsIocGroupQueueCommCB[i].callBack = OsIocGroupQueueInfo[i].callBack;
        #endif

        OsIocGroupQueueCommCB[i].sndAppMask = OsIocGroupQueueInfo[i].sndAppMask;
        OsIocGroupQueueCommCB[i].rcvAppId = OsIocGroupQueueInfo[i].rcvAppId;
        OsIocGroupQueueCommCB[i].rcvAppMask = 1U << OsIocGroupQueueInfo[i].rcvAppId;


        #if defined(OSIOCACTION)
        OsIocGroupQueueCommCB[i].action.taskIndex = OsIocGroupQueueInfo[i].taskIndex;
        #if defined(OSIOCSETEVENT)
        OsIocGroupQueueCommCB[i].action.event = OsIocGroupQueueInfo[i].event;
        #endif
        #endif

        OsIocGroupQueueCommCB[i].nItems = 0U;
        OsIocGroupQueueCommCB[i].head = 0U;
        OsIocGroupQueueCommCB[i].tail = 0U;
        OsIocGroupQueueCommCB[i].overflow = OSFALSE;
    }
    #endif /* OSNIOCGROUPQUEUES > 0U */

    #if (OSNIOCBUFFERS > 0U) || (OSNIOCGROUPBUFFERS > 0U)
    OSIOC_Init ();              /* IOC initialization generated by SysGen */
    #endif

    #if (OSNIOCCALLBACKS > 0U)
    /* clear INTC sources for IOC callback ISR(s) */
    OSIocCallbackClear();
    /* init callback queue */
    OsIOCCallbacks.head = OSIOCCALLBACKPTR0;
    OsIOCCallbacks.tail = OSIOCCALLBACKPTR0;
    #endif /* (OSNIOCCALLBACKS > 0U) */
}

#if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)

#if defined(OSIOCACTION)
/******************************************************************************
 * Function:    OSSCIocAction()
 *
 * Description: Invoking of configured IOC action 
 *
 * Returns:     none
 *
 * Notes:       
 *
 ******************************************************************************/
OSINLINE_ void
OSSCIocAction (const OSIOCACT* action, OSAPPLICATIONTYPE appId)
{
    if ((OSGIVENAPPMASK (appId) & OsTaskTable[action->taskIndex].appMask) == 0U)
    {
        OSErrorHook_noPar (E_OS_ACCESS);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }

    #if defined(OSECC) && (OSNXTSKS > 0U)
    #if defined(OSIOCSETEVENT)
    if (action->event)
    {
        if ((OSTASKSTATUS (action->taskIndex) & OSTCBNOSUSPENDED) == 0U)
        {
            OSErrorHook_noPar (E_OS_STATE);     /* the task is in a suspended state */
        }
        else
        {                       /* set event */
            OSSetEventInAlm (&OsTaskTable[action->taskIndex], action->event);
        }
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    else
    #endif
    #endif /* defined(OSECC) && (OSNXTSKS > 0U) */
    {
        if (OSTASKACTEXHAUSTED (action->taskIndex))
        {
            OSErrorHook_noPar (E_OS_LIMIT);
        }
        else
        {
            #if defined(OSECC) && (OSNXTSKS > 0U)
            OsTaskTable[action->taskIndex].set_event = OSNOEVENTS;
            #endif
            /* activate task */
            OSActivateTaskInAlm (action->taskIndex);
        }
    }
}

/******************************************************************************
 * Function:    OSIocAction()
 *
 * Description: Invoking of configured IOC action
 *
 * Returns:     none
 *
 * Notes:       Called from IocWrite, IocSend services if there's an action
 *              configured for IOC communication
 *
 ******************************************************************************/
void
OSIocAction (OSIOCACT * action, OSAPPLICATIONTYPE appId)
{


    OSSCIocAction (action, appId);
}
#endif /* defined(OSIOCACTION) */

#if (OSNIOCCALLBACKS > 0U)
/******************************************************************************
 * Function:     OSSCIocInsertCallback
 *
 * Description:  Insert CB to callback queue tail and invokes callback interrupt
 *
 * Returns:      none
 *
 ******************************************************************************/
OSINLINE_ void  
OSSCIocInsertCallback (OSIOCCommCBType cb)
{
    if (cb->next == cb)  /* cb is not queued */
    {
        cb->next = OSIOCCALLBACKPTR0;
        if (OsIOCCallbacks.tail == OSIOCCALLBACKPTR0)
        {
            OsIOCCallbacks.tail = cb;
            OsIOCCallbacks.head = cb;
        }
        else
        {
            (OsIOCCallbacks.tail)->next = cb;
            OsIOCCallbacks.tail = cb;
        }

        OSIocCallbackInvoke();  /* invoke interrupt for IOC CallBack ISR */
    }
}

/******************************************************************************
 * Function:     OSIocGetCallback
 *
 * Description:  get item from callback queue head
 *
 * Returns:      communication control block pointer
 *
 ******************************************************************************/
static OSINLINE OSIOCCommCBType
OSIocGetCallback (void)
{
    OSIOCCommCBType cb;

    /* get CB from head */
    cb = OsIOCCallbacks.head;

    /* Remove item from queue */
    if (OsIOCCallbacks.tail == OsIOCCallbacks.head)
    {
        /* queue is empty */
        OsIOCCallbacks.tail = OSIOCCALLBACKPTR0;
        OsIOCCallbacks.head = OSIOCCALLBACKPTR0;
        
        OSIocCallbackClear();  /* clear interrupt request */
    }
    else
    {
        OsIOCCallbacks.head = cb->next;
    }

    cb->next = cb;   /* cb is not queued */

    return cb;
}



/******************************************************************************
 * Function:     OSIocInsertCallback
 *
 * Description:  put callback into queue ind invoke software interrupt
 *
 * Returns:      none
 *
 ******************************************************************************/
void 
OSIocInsertCallback (OSIOCCommCBType cb)
{
    OSSCIocInsertCallback (cb);
}



/******************************************************************************
 * Function:     OSIocRemoveCallBack
 *
 * Description:  removes specified callback item from queue 
 *
 * Returns:      none
 *
 * Notes:   it may be called only when an OS-applicatiion is killed
 *
 ******************************************************************************/

static void 
OSIocRemoveCallBack (OSIOCCommCBType cb)
{
    OSIOCCommCBType item;

    if (cb == OsIOCCallbacks.head)
    {
        if (OsIOCCallbacks.tail == OsIOCCallbacks.head)
        {
            OsIOCCallbacks.tail = OSIOCCALLBACKPTR0;
            OsIOCCallbacks.head = OSIOCCALLBACKPTR0;

            /* queue is  empty */
            OSIocCallbackClear();  /* clear interrupt request */
        }
        else
        {
            OsIOCCallbacks.head = cb->next;
        }
    }
    else
    {
        item = OsIOCCallbacks.head;

        while (item->next != cb)
        {
            item = item->next;
        }

        if (cb == OsIOCCallbacks.tail)
        {
            item->next = OSIOCCALLBACKPTR0;
            OsIOCCallbacks.tail = item;
        }
        else
        {
            item->next = cb->next;
        }
    }

    cb->next = cb;   /* cb is not queued */
}


/******************************************************************************
 * Function:     OSIocSearchCallBack
 *
 * Description:  searches item (which belonges to specified application)in queue 
 *
 * Returns:      none
 *
 * Notes:   it is called when an OS-applicatiion is killed
 *
 ******************************************************************************/

static OSIOCCommCBType 
OSIocSearchCallBack (OSAPPLICATIONTYPE appId)
{
    OSIOCCommCBType cb;
    OSGETCOREID

    cb = OsIOCCallbacks.head;

    while (cb != OSIOCCALLBACKPTR0)
    {
        if (cb->rcvAppId == appId)
        {
            break;
        }
        else
        {
            cb = cb->next;
        }
    }
    
    return cb;
}

/******************************************************************************
 * Function:     OSIocRemoveAppCallBack
 *
 * Description:  Removes IOC callback(s) (that belong(s) to specified OS-Application)
 *               from callback queue if any 
 *
 * Returns:      none
 *
 * Notes:   it is called when an OS-applicatiion is killed
 *
 ******************************************************************************/

void OSIocRemoveAppCallBack (OSAPPLICATIONTYPE appId)
{
    OSIOCCommCBType cb;

    for(;;) 
    {
        cb = OSIocSearchCallBack(appId);

        if (cb == OSIOCCALLBACKPTR0)  /* there is no callback for specified application in queue */
        {
            break;
        }

        OSIocRemoveCallBack(cb);
    }
}

#endif /* (OSNIOCCALLBACKS > 0U) */

/******************************************************************************
 * Function:     OSIOCCheckAppState
 *
 * Description:  Checks that receiving application is accessible
 *
 * Returns:      OSTRUE if the application is accessible, otherwise - OSFALSE
 *
 * Notes:
 *
 ******************************************************************************/
OSINLINE OSBYTE OSIOCCheckAppState (OSIOCCommCBType cb)
{
    OSBYTE ret;
    #if defined(OSAPPIDRAM)         /* for OSGetCurApp() */
    OSGETCOREID                 /* get core Id */
    #endif

    switch( OsAppTable[cb->rcvAppId].state )
    {         
        case APPLICATION_RESTARTING:
            if (OSGetCurApp() == cb->rcvAppId)
            {
                ret = OSTRUE;
                break;
            }  

        /*lint -fallthrough -e{960} */ /* no break, 'ret' will be OSFALSE */
        case APPLICATION_TERMINATED:
            ret = OSFALSE;
            break;

        default:
            ret = OSTRUE;
            break;
    }
    return ret;
}

/******************************************************************************
 * Function:     OSIOCNotify
 *
 * Description:  Performs IOC action or callback if configured
 *
 * Returns:      none
 *
 * Notes:
 *
 ******************************************************************************/
static void 
OSIOCNotify (OSIOCCommCBType cb)
{
    if( OSIOCCheckAppState(cb) == OSTRUE )
    {
        #if (OSNIOCCALLBACKS > 0U)
        if (cb->callBack != 0)
        {
            OSIocInsertCallback (cb);
        }
        else
        #endif
        #if defined(OSIOCACTION)
        if ((cb->action).taskIndex != OSINVALID_TASK)
        {
            OSIocAction (&(cb->action), cb->rcvAppId);
            OSDISPATCH ();
        }
        else
        #endif
        {
            /* nothing todo */
        }
    }
}
#endif /* (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION) */


#if (OSNIOCBUFFERS > 0U)
/******************************************************************************
 * Function:     OSIocWriteRef
 *
 * Description:  Performs data transmission for "LastIsBest" (data semantic) communication type.
 *               Used for unidirectional 1:1 and N:1 communication between OS-Applications
 *               located on the same core.
 *               Data is passed by reference.
 *
 * Returns:      IOC_E_OK        no errors
 *               IOC_E_NOK       call while interrupts are disabled by OS services
 *               IOC_E_NOK       service call from wrong context
 *               IOC_E_NOK       access to the object denied for this application
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocWriteRef (OSWORD commId, OSBYTEPTR dataRef)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OsIocBufferCommCB[commId].sndAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKREADACCESS (dataRef, (MemorySizeType)OsIocBufferCommCB[commId].dataSize);

    OSDIS (save);

    memcpy (OsIocBufferCommCB[commId].dataBuf, dataRef, (size_t)OsIocBufferCommCB[commId].dataSize);

    #if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)
    OSIOCNotify ( (OSIOCCommCBType)(&OsIocBufferCommCB[commId]) );
    #endif 

    OSRI (save);
    return IOC_E_OK;
}


/******************************************************************************
 * Function:     OSIocRead
 *
 * Description:  Performs data reception for "LastIsBest" (data semantic) communication type.
 *               Used for unidirectional communication between OS-Applications
 *               located on the same core.
 *
 * Returns:      IOC_E_OK        no errors
 *               IOC_E_NOK       call while interrupts are disabled by OS services
 *               IOC_E_NOK       service call from wrong context
 *               IOC_E_NOK       access to the object denied for this application
 *               IOC_E_NOK       an invalid address is given as a parameter to a service
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocRead (OSWORD commId, OSBYTEPTR dataRef)
{
    OSIMSAVE                /* OSINTMASKTYPE save; */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OsIocBufferCommCB[commId].rcvAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKWRITEACCESS (dataRef, (MemorySizeType)OsIocBufferCommCB[commId].dataSize);

    OSDIS (save);
    memcpy (dataRef, OsIocBufferCommCB[commId].dataBuf, (size_t)OsIocBufferCommCB[commId].dataSize);
    OSRI (save);

    return IOC_E_OK;
}

#endif /* OSNIOCBUFFERS > 0U */


#if (OSNIOCGROUPBUFFERS > 0U)
#if defined(OSIOCBUFFERCOMM_WRITEDATA)
/******************************************************************************
 * Function:     OSIocWriteGroup
 *
 * Description:  Performs data transmission for "LastIsBest" (data semantic) communication type.
 *               Used for unidirectional 1:1 and N:1 communication between OS-Applications
 *               located on the same core.
 *               Data is passed by reference.
 *
 * Returns:      IOC_E_OK        no errors
 *               IOC_E_NOK       call while interrupts are disabled by OS services
 *               IOC_E_NOK       service call from wrong context
 *               IOC_E_NOK       access to the object denied for this application
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocWriteGroup (OSWORD commId, OSBYTEPTR dataRef)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OsIocGroupBufferCommCB[commId-OSNIOCBUFFERS].sndAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */    
    OSIOCBUFFERCOMM_CHECKREADACCESS (commId, dataRef);
    
    OSDIS (save);

    OSIOCBUFFERCOMM_WRITEDATA (commId, dataRef);

    #if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)
    OSIOCNotify ( (OSIOCCommCBType)(&OsIocGroupBufferCommCB[commId-OSNIOCBUFFERS]) );
    #endif 

    OSRI (save);
    return IOC_E_OK;
}
#endif /* defined(OSIOCBUFFERCOMM_WRITEDATA) */


#if defined(OSIOCBUFFERCOMM_READDATA)
/******************************************************************************
 * Function:     OSIocReadGroup
 *
 * Description:  Performs data reception for "LastIsBest" (data semantic) communication type.
 *               Used for unidirectional communication between OS-Applications
 *               located on the same core.
 *
 * Returns:      IOC_E_OK        no errors
 *               IOC_E_NOK       call while interrupts are disabled by OS services
 *               IOC_E_NOK       service call from wrong context
 *               IOC_E_NOK       access to the object denied for this application
 *               IOC_E_NOK       an invalid address is given as a parameter to a service
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocReadGroup (OSWORD commId, OSBYTEPTR dataRef)
{
    OSIMSAVE                /* OSINTMASKTYPE save; */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OsIocGroupBufferCommCB[commId-OSNIOCBUFFERS].rcvAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */    
    OSIOCBUFFERCOMM_CHECKWRITEACCESS (commId, dataRef);

    OSDIS (save);
    OSIOCBUFFERCOMM_READDATA (commId, dataRef);
    OSRI (save);

    return IOC_E_OK;
}
#endif /* defined(OSIOCBUFFERCOMM_READDATA) */

#endif /* OSNIOCGROUPBUFFERS > 0U */


#if (OSNIOCQUEUES > 0U)
/******************************************************************************
 * Function:     OSIocSendRef
 *
 * Description:  Performs data transmission for "Queued" (event semantic) communication type.
 *               Used for unidirectional 1:1 and N:1 communication between OS-Applications
 *               located on the same core.
 *               Data is passed by reference.
 *
 * Returns:      IOC_E_OK            no errors
 *               IOC_E_LIMIT         IOC internal communication queue is full
 *               IOC_E_NOK           call while interrupts are disabled by OS services
 *               IOC_E_NOK           service call from wrong context
 *               IOC_E_NOK           access to the object denied for this application
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocSendRef (OSWORD commId, OSBYTEPTR dataRef)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OSIOCQUEUE.sndAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKREADACCESS (dataRef, (MemorySizeType)OSIOCQUEUE.dataSize);

    OSDIS (save);
    if (OSIOCQUEUE.nItems == OSIOCQUEUE.queueSize)
    {
        OSIOCQUEUE.overflow = OSTRUE;
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_LIMIT;
    }

    /*
    * @violates @ref Os_ioc_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    memcpy (&OSIOCQUEUE.dataQueue[OSIOCQUEUE.head * OSIOCQUEUE.dataSize], dataRef, (size_t)OSIOCQUEUE.dataSize);
    OSIOCQUEUE.nItems++;
    OSIOCQUEUE.head++;
    if (OSIOCQUEUE.head == OSIOCQUEUE.queueSize)
    {
        OSIOCQUEUE.head = 0U;
    }

    #if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)
    OSIOCNotify ( (OSIOCCommCBType)(&OSIOCQUEUE) );
    #endif 

    OSRI (save);
    return IOC_E_OK;
}


/******************************************************************************
 * Function:     OSIocReceive
 *
 * Description:  Performs data reception for "Queued" (event semantic) communication type.
 *               Used for unidirectional communication between OS-Applications
 *               located on the same core.
 *
 * Returns:      IOC_E_OK              no errors
 *               IOC_E_NO_DATA         no data is available for reception
 *               IOC_E_LOST_DATA       internal queue oveflow happened during last OSIocSend
 *                                     and data passed with it was lost. There is no error in data returned
 *                                     by OSIocReceive however
 *               IOC_E_NOK             call while interrupts are disabled by OS services
 *               IOC_E_NOK             service call from wrong context
 *               IOC_E_NOK             access to the object denied for this application
 *               IOC_E_NOK             an invalid address is given as a parameter to a service
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocReceive (OSWORD commId, OSBYTEPTR dataRef)
{
    OSIMSAVE                /* OSINTMASKTYPE save; */
    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OSIOCQUEUE.rcvAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKWRITEACCESS (dataRef, (MemorySizeType)OSIOCQUEUE.dataSize);

    OSDIS (save);

    if (OSIOCQUEUE.nItems == 0U) /* no data is available */
    {
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_NO_DATA;
    }

    /*
    * @violates @ref Os_ioc_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    memcpy (dataRef, &OSIOCQUEUE.dataQueue[OSIOCQUEUE.tail * OSIOCQUEUE.dataSize], (size_t)OSIOCQUEUE.dataSize);
    OSIOCQUEUE.nItems--;
    OSIOCQUEUE.tail++;
    if (OSIOCQUEUE.tail == OSIOCQUEUE.queueSize)
    {
        OSIOCQUEUE.tail = 0U;
    }

    if (OSIOCQUEUE.overflow == OSTRUE)
    {
        OSIOCQUEUE.overflow = OSFALSE;
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_LOST_DATA;
    }

    OSRI (save);

    return IOC_E_OK;
}

#endif /* OSNIOCQUEUES > 0U */


#if (OSNIOCGROUPQUEUES > 0U)

#if defined(OSIOCQUEUECOMM_WRITEDATA)
/******************************************************************************
 * Function:     OSIocSendGroup
 *
 * Description:  Performs data transmission for "Queued" (event semantic) communication type.
 *               Used for unidirectional 1:1 and N:1 communication between OS-Applications
 *               located on the same core.
 *               Data is passed by reference.
 *
 * Returns:      IOC_E_OK            no errors
 *               IOC_E_LIMIT         IOC internal communication queue is full
 *               IOC_E_NOK           call while interrupts are disabled by OS services
 *               IOC_E_NOK           service call from wrong context
 *               IOC_E_NOK           access to the object denied for this application
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocSendGroup (OSWORD commId, OSBYTEPTR dataRef)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OSIOCGROUPQUEUE.sndAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCQUEUECOMM_CHECKREADACCESS (commId, dataRef);

    OSDIS (save);

    if (OSIOCGROUPQUEUE.nItems == OSIOCGROUPQUEUE.queueSize)
    {
        OSIOCGROUPQUEUE.overflow = OSTRUE;
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_LIMIT;
    }

    OSIOCQUEUECOMM_WRITEDATA (commId, &OSIOCGROUPQUEUE.dataQueue[OSIOCGROUPQUEUE.head * OSIOCGROUPQUEUE.dataSize], dataRef);

    OSIOCGROUPQUEUE.nItems++;
    OSIOCGROUPQUEUE.head++;
    if (OSIOCGROUPQUEUE.head == OSIOCGROUPQUEUE.queueSize)
    {
        OSIOCGROUPQUEUE.head = 0U;
    }

    #if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)
    OSIOCNotify ( (OSIOCCommCBType)(&OSIOCGROUPQUEUE) );
    #endif 

    OSRI (save);
    return IOC_E_OK;
}   
#endif /* defined(OSIOCQUEUECOMM_WRITEDATA) */


#if defined(OSIOCQUEUECOMM_READDATA)
/******************************************************************************
 * Function:     OSIocReceiveGroup
 *
 * Description:  Performs data reception for "Queued" (event semantic) communication type.
 *               Used for unidirectional communication between OS-Applications
 *               located on the same core.
 *
 * Returns:      IOC_E_OK              no errors
 *               IOC_E_NO_DATA         no data is available for reception
 *               IOC_E_LOST_DATA       internal queue oveflow happened during last OSIocSend
 *                                     and data passed with it was lost. There is no error in data returned
 *                                     by OSIocReceive however
 *               IOC_E_NOK             call while interrupts are disabled by OS services
 *               IOC_E_NOK             service call from wrong context
 *               IOC_E_NOK             access to the object denied for this application
 *               IOC_E_NOK             an invalid address is given as a parameter to a service
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocReceiveGroup (OSWORD commId, OSBYTEPTR dataRef)
{
    OSIMSAVE                /* OSINTMASKTYPE save; */
    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCCHECKACCESSRIGHTS (OSIOCGROUPQUEUE.rcvAppMask);
    /*
     * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSIOCQUEUECOMM_CHECKWRITEACCESS (commId, dataRef);

    OSDIS (save);

    if (OSIOCGROUPQUEUE.nItems == 0U) /* no data is available */
    {
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_NO_DATA;
    }

    OSIOCQUEUECOMM_READDATA (commId, &OSIOCGROUPQUEUE.dataQueue[OSIOCGROUPQUEUE.tail * OSIOCGROUPQUEUE.dataSize], dataRef);    
    
    OSIOCGROUPQUEUE.nItems--;
    OSIOCGROUPQUEUE.tail++;
    if (OSIOCGROUPQUEUE.tail == OSIOCGROUPQUEUE.queueSize)
    {
        OSIOCGROUPQUEUE.tail = 0U;
    }

    if (OSIOCGROUPQUEUE.overflow == OSTRUE)
    {
        OSIOCGROUPQUEUE.overflow = OSFALSE;
        OSRI (save);
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return IOC_E_LOST_DATA;
    }

    OSRI (save);

    return IOC_E_OK;
}
#endif /* defined(OSIOCQUEUECOMM_READDATA) */

#endif /* OSNIOCGROUPQUEUES > 0U */


#if (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U)
/******************************************************************************
 * Function:     OSIocEmptyQueue
 *
 * Description:  Deletes the content of the IOC internal communication queue
 *
 * Returns:      IOC_E_OK        no errors
 *               IOC_E_NOK       call while interrupts are disabled by OS services
 *               IOC_E_NOK       service call from wrong context
 *               IOC_E_NOK       access to the object denied for this application
 *
 * Notes:
 *
 ******************************************************************************/
Std_ReturnType
OS_OSIocEmptyQueue (OSWORD commId)
{
    OSIMSAVE                /* OSINTMASKTYPE save; */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return IOC_E_NOK;
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */
   
    #if (OSNIOCQUEUES > 0U)    
    #if (OSNIOCGROUPQUEUES > 0U)
    if (commId < (OSNIOCBUFFERS + OSNIOCGROUPBUFFERS + OSNIOCQUEUES))
    #endif
    {
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSIOCCHECKACCESSRIGHTS ((OSIOCQUEUE.rcvAppMask | OSIOCQUEUE.sndAppMask));
    }
    #if (OSNIOCGROUPQUEUES > 0U)     
    else/* if (commId < OSNIOCBUFFERS + OSNIOCGROUPBUFFERS + OSNIOCQUEUES + OSNIOCGROUPQUEUES) */
    #endif
    #endif
    #if (OSNIOCGROUPQUEUES > 0U)
    {        
        /*
         * @violates @ref Os_ioc_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSIOCCHECKACCESSRIGHTS ((OSIOCGROUPQUEUE.rcvAppMask | OSIOCGROUPQUEUE.sndAppMask));
    }
    #endif
    OSDIS (save);
      
    #if (OSNIOCQUEUES > 0U)
    #if (OSNIOCGROUPQUEUES > 0U)
    if (commId < (OSNIOCBUFFERS + OSNIOCGROUPBUFFERS + OSNIOCQUEUES))
    #endif
    {
        OSIOCQUEUE.nItems = 0U;
        OSIOCQUEUE.head = 0U;
        OSIOCQUEUE.tail = 0U;
        OSIOCQUEUE.overflow = OSFALSE;
    }
    #if (OSNIOCGROUPQUEUES > 0U)    
    else/* if (commId < OSNIOCBUFFERS + OSNIOCGROUPBUFFERS + OSNIOCQUEUES + OSNIOCGROUPQUEUES) */
    #endif
    #endif
    #if (OSNIOCGROUPQUEUES > 0U)
    {    
        OSIOCGROUPQUEUE.nItems = 0U;
        OSIOCGROUPQUEUE.head = 0U;
        OSIOCGROUPQUEUE.tail = 0U;
        OSIOCGROUPQUEUE.overflow = OSFALSE;         
    }
    #endif
    OSRI (save);

    return IOC_E_OK;
}

#endif /* (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U) */


#if (OSNIOCCALLBACKS > 0U)
/******************************************************************************
 * Function:     OSIocPrepareCallbackISR
 *
 * Description:  This function is called from interrupt dispatcher.
 *               It changes handlerPtr given as a parameter so that
 *               an IOC callback can be invoked like a usual user ISR2.
 *
 * Returns:      OSTRUE  - if interrupt flag is set and callback shall be called
 *               OSFALSE - if callback shall not be called
 *
 * Notes:
 *
 ******************************************************************************/

OSBYTE
OSIocPrepareCallbackISR (OS_ISRTYPEPTR handlerPtr)
{
    OSBYTE ret;
    OSIOCCommCBType cb;

    if (OsIOCCallbacks.head == OSIOCCALLBACKPTR0)  
    {
        /* it should be unreachable point because  
           callback ISR shall occur only if the queue is not empty.
           It may occur due to known INTC bug */
        OSIocCallbackClear();
        ret = OSFALSE;
    }
    else
    {
        /* Get CB from callback queue */
        cb = OSIocGetCallback();

        /* prepare ISR cat.2 */
        handlerPtr->appId = cb->rcvAppId;
        handlerPtr->userISR = cb->callBack;
        ret = OSTRUE;
    }

    /* Note callback ISRs will occur until callback queue is empty */        
    return ret;
}
#endif /* OSNIOCCALLBACKS > 0U */

#endif /* defined(OSIOC) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_ioc_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
