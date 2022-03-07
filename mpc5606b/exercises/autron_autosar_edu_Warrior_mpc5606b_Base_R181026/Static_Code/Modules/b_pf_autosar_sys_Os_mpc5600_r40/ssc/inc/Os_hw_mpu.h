/**
*   @file    Os_hw_mpu.h
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

#ifndef OS_HW_MPU_H
#define OS_HW_MPU_H

#ifdef __cplusplus
extern "C"
{
#endif


#if defined(OSMEMPROTECTION)

    /* MPU region descriptor words */
    #define OSMPU_RGD_WORD0 (0U)
    #define OSMPU_RGD_WORD1 (1U)
    #define OSMPU_RGD_WORD2 (2U)
    #define OSMPU_RGD_WORD3 (3U)

    /* Descriptor numbers */
    #define OSMPU_RGD_DESC0   (0U)
    #define OSMPU_RGD_DESC1   (1U)
    #define OSMPU_RGD_DESC2   (2U)
    #define OSMPU_RGD_DESC3   (3U)
    #define OSMPU_RGD_DESC4   (4U)
    #define OSMPU_RGD_DESC5   (5U)
    #define OSMPU_RGD_DESC6   (6U)
    #define OSMPU_RGD_DESC7   (7U)

    #define OSMPU_RGD_DESC8   (8U)
    #define OSMPU_RGD_DESC9   (9U)
    #define OSMPU_RGD_DESC10 (10U)
    #define OSMPU_RGD_DESC11 (11U)
    #define OSMPU_RGD_DESC12 (12U)
    #define OSMPU_RGD_DESC13 (13U)
    #define OSMPU_RGD_DESC14 (14U)
    #define OSMPU_RGD_DESC15 (15U)

/* MPU_CESR register */
    #define OSMPU_CESR              OSREG32(OSMPU_BASE)    /* MPU control/error status register */

/* MPU_CESR register bit masks */
    #define OSMPU_CESR_VLD          (0x1UL)        /* This bit provides a global enable/disable for the MPU */
    #define OSMPU_CESR_SPERR        (0xFF000000UL) /* mask for the SPERR bits */

    #define OSMPU_CESR_SPERR_S0     (0x80000000UL)
    #define OSMPU_CESR_SPERR_S1     (0x40000000UL)
    #define OSMPU_CESR_SPERR_S2     (0x20000000UL)

/* MPU_EARn/MPU_EDRn registers */
    #define OSMPU_EAR0              OSREG32(OSMPU_BASE + 0x10UL)/* MPU Error Address Register, Slave Port 0 */
    #define OSMPU_EDR0              OSREG32(OSMPU_BASE + 0x14UL)/* MPU Error Detail Register, Slave Port 0 */
    #define OSMPU_EAR1              OSREG32(OSMPU_BASE + 0x18UL)/* MPU Error Address Register, Slave Port 1 */
    #define OSMPU_EDR1              OSREG32(OSMPU_BASE + 0x1cUL)/* MPU Error Detail Register, Slave Port 1 */
    #define OSMPU_EAR2              OSREG32(OSMPU_BASE + 0x20UL)/* MPU Error Address Register, Slave Port 2 */
    #define OSMPU_EDR2              OSREG32(OSMPU_BASE + 0x24UL)/* MPU Error Detail Register, Slave Port 2 */

/* MPU_EDRn bit masks */
    #define OSMPU_EDR_ERW           (0x1UL)        /* Error Read/Write. 0 - read access, 1 - write access */
    #define OSMPU_EDR_EACD          (0xFFFF0000UL) /* Error Access Control Detail. */
    #define OSMPU_EDR_EATTR         (0xEUL) /* Error Attributes. This 3-bit read-only field records attribute information
                                             about the faulting reference. The supported encodings are defined as:
                                             000 User mode, instruction access
                                             001 User mode, data access
                                             010 Supervisor mode, instruction access
                                             011 Supervisor mode, data access */

/* MPU Region Descriptor Alternate Access Control num (0..15) */
    #define OSMPU_RGDAAC(num)       OSREG32(OSMPU_BASE + 0x800UL + ((num)*4UL))

        #define OSMPUx_RGD_GETADDR(num)  /*lint -save -e960 */ ((OSDWORD)(OSMPU_BASE + 0x400UL + ((OSDWORD)(num)*0x10UL)))  /*lint -restore */ /* MPUx Region Descriptor num (0..15) address */
        #define OSMPUx_RGD(num,word)    OSREG32(OSMPU_BASE  + 0x400UL + ((num)*0x10UL) + ((word)*4UL)) /* MPUx Region Descriptor num (0..15), word (0..3) */

/* MPU Region Descriptor with address 'desc_addr', word (0..3) */
    #define OSMPU_RGD_ADDR(desc_addr,word)  OSREG32((desc_addr) + ((word)*4UL))

/* MPU Region Descriptor num (0..15), word (0..3) */
    #define OSMPU_RGD(num,word)     OSREG32(OSMPU_BASE  + 0x400UL + ((num)*0x10UL) + ((word)*4UL))

/* MPU Region Descriptor word 3: This bit signals the region descriptor is valid. */
    #define OSMPU_RGD_W3_VLD        (0x1UL)

/* Master Supervisor mode (sm) access bit field */
    #define OSMPU_SM_RWX (0x0UL)
    #define OSMPU_SM_RX  (0x1UL)
    #define OSMPU_SM_RW  (0x2UL)
    #define OSMPU_SM_UM  (0x3UL)

/* Master User mode (um) access bits */
    #define OSMPU_UM_R   (0x4UL)
    #define OSMPU_UM_W   (0x2UL)
    #define OSMPU_UM_X   (0x1UL)
    #define OSMPU_UM_RWX (OSMPU_UM_R | OSMPU_UM_W | OSMPU_UM_X)
    #define OSMPU_UM_RW  (OSMPU_UM_R | OSMPU_UM_W)
    #define OSMPU_UM_RX  (OSMPU_UM_R | OSMPU_UM_X)

/* Master PID Enable */
    #define OSMPU_PE_ON  (0x1UL)
    #define OSMPU_PE_OFF (0x0UL)

/* Mask for Master ID 0..3 rights */
    #define OSMPU_RGD_W2_M0(mpe,sm,um)  (((mpe)<<5) |((sm)<<3) |(um))      /* Word 2: Bus Master ID 0 rights */
    #define OSMPU_RGD_W2_M1(mpe,sm,um)  (((mpe)<<11)|((sm)<<9) |((um)<<6)) /* Word 2: Bus Master ID 1 rights */
    #define OSMPU_RGD_W2_M2(mpe,sm,um)  (((mpe)<<17)|((sm)<<15)|((um)<<12))/* Word 2: Bus Master ID 2 rights */
    #define OSMPU_RGD_W2_M3(mpe,sm,um)  (((mpe)<<23)|((sm)<<21)|((um)<<18))/* Word 2: Bus Master ID 3 rights */

/* Master M4 rights */
    #define OSMPU_RGD_W2_M4E_R   (0x2UL)
    #define OSMPU_RGD_W2_M4E_W   (0x1UL)
    #define OSMPU_RGD_W2_M4(m4)  ((m4)<<24UL)    /* Word 2: Bus Master ID 4 rigths */

        #if defined(OSMPU_NO_OTHERMASTERS)
        /* Make masters 1,2 and 3 without any rights */
            #define OSMPU_RGD_W2_OTHERS()                            \
                (OSMPU_RGD_W2_M1( OSMPU_PE_OFF, OSMPU_SM_UM, 0UL ) | \
                 OSMPU_RGD_W2_M2( OSMPU_PE_OFF, OSMPU_SM_UM, 0UL ) | \
                 OSMPU_RGD_W2_M3( OSMPU_PE_OFF, OSMPU_SM_UM, 0UL ))
        #else
        /* Make masters 1,2 and 3 with RWX rights in system mode
           Note: practically this macro returns 0 */
            #define OSMPU_RGD_W2_OTHERS()                    \
                (OSMPU_RGD_W2_M1( OSMPU_PE_OFF, 0UL, 0UL ) | \
                 OSMPU_RGD_W2_M2( OSMPU_PE_OFF, 0UL, 0UL ) | \
                 OSMPU_RGD_W2_M3( OSMPU_PE_OFF, 0UL, 0UL ))
        #endif       /* defined(OSMPU_NO_OTHERMASTERS) */

#endif /* defined(OSMEMPROTECTION) */


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_MPU_H*/

/** @} */

