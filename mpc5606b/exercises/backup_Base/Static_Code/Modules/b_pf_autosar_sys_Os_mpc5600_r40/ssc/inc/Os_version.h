/**
*   @file    Os_version.h
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

#ifndef OS_VERSION_H
#define OS_VERSION_H


#ifdef __cplusplus
extern "C"
{
#endif

#define OS_VENDOR_ID        43u    /* Freescale AUTOSAR Vendor ID  */
#define OS_MODULE_ID        0x01   /* OS Module ID                 */

#define OS_AR_MAJOR_VERSION 4   /* Major version number of AUTOSAR specification       */
#define OS_AR_MINOR_VERSION 0   /* Minor version number of AUTOSAR specification       */
#define OS_AR_PATCH_VERSION 3   /* Patch level version number of AUTOSAR specification */

#define OS_SW_MAJOR_VERSION 40   /* Major version number of the implementation   */
#define OS_SW_MINOR_VERSION 69   /* Minor version number of the implementation   */
#define OS_SW_PATCH_VERSION 0    /* Patch level version number of the implementation */

#define OSBUILDNUMBER   "OS/MPC5600 v4.0 build 4.0.69"



#ifdef __cplusplus
}
#endif



#endif /*OS_VERSION_H*/

/** @} */

