/***************************************************************************
 * Copyright                                                               *
 *                                                                         *
 *     ESCRYPT GmbH - Embedded Security       ESCRYPT Inc.                 *
 *     Zentrum fuer IT-Sicherheit             315 E Eisenhower Parkway     *
 *     Lise-Meitner-Allee 4                   Suite 214                    *
 *     44801 Bochum                           Ann Arbor, MI 48108          *
 *     Germany                                USA                          *
 *                                                                         *
 *     http://www.escrypt.com                                              *
 *     info"at"escrypt.com                                                 *
 *                                                                         *
 * All Rights reserved                                                     *
 ***************************************************************************/

/***************************************************************************/
/*!
   \file        SecM_config.h

   \brief  Configuration interface file for SecM security module.

   File must be included before cycurlib_config.h to overwrite cycurLIB configuration.

   Variables for KEYs can be found in SecM_keys.h

   Defines from (SecM242)

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_CONFIG_H_
#define _ESC_SECM_CONFIG_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/
/** Security class VENDOR */
#define SEC_CLASS_VENDOR 0x00
/** Security class D */
#define SEC_CLASS_D      0x01
/** Security class DD */
#define SEC_CLASS_DD     0x02
/** Security class DDD */
#define SEC_CLASS_DDD    0x03
/** Security class C */
#define SEC_CLASS_C      0x04
/** Security class CC */
#define SEC_CLASS_CC     0x05
/** Security class CCC */
#define SEC_CLASS_CCC    0x06
/** Security class B */
#define SEC_CLASS_B      0x07
/** Security class BB */
#define SEC_CLASS_BB     0x08
/** Security class BBB */
#define SEC_CLASS_BBB    0x09
/** Security class A */
#define SEC_CLASS_A      0x0A
/** Security class AA */
#define SEC_CLASS_AA     0x0B
/** Security class AAA */
#define SEC_CLASS_AAA    0x0C

/** Hash algorithm RIPEMD-160 */
#define SEC_RIPEMD160    0x01
/** Hash algorithm SHA-1 */
#define SEC_SHA1         0x02

/** File oriented flash access (SecM242) */
#define SEC_FILE         0x01
/** Memory oriented flash access (SecM240) */
#define SEC_ADDRESS      0x02

/** Production environment */
#define SEC_PRODUCTION   0x01
/** Development (Debugging) environment */
#define SEC_DEVELOPMENT  0x02

/***************************************************************************
 * 2.1 HIS-CONFIGURATION                                                   *
 ***************************************************************************/

/**
 These are the parameters according to SecM353,
 keys can be defined in SecM_keys.h.
 */
#ifndef SEC_SECURITY_CLASS
/** The security class used */
#    define SEC_SECURITY_CLASS    SEC_CLASS_DDD
#endif
#ifndef SEC_MEMORY_ACCESS
/** Memory access type */
#    define SEC_MEMORY_ACCESS     SEC_ADDRESS
#endif
#ifndef SEC_HASH_ALGORITHM
/** Hash algorithm */
#    define SEC_HASH_ALGORITHM    SEC_RIPEMD160
#endif

/** ECU specific key for authorisation */
#define SEC_ECU_KEY           0xFFFFFFFFU
/** Call cycle of routine SecTask() (Not used) */
#define SEC_CALL_CYCLE        10U
#ifdef Esc_NDEBUG
/** Production mode */
#    define SEC_MODE              SEC_PRODUCTION
#else
/** Development mode */
#    define SEC_MODE              SEC_DEVELOPMENT
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. MACRO FUNCTIONS / PARAMETER CHECKS                                   *
 ***************************************************************************/

#if ( SEC_SECURITY_CLASS == SEC_CLASS_AAA )
#    error "Not implemented!"
#endif

#if ( SEC_MEMORY_ACCESS == SEC_ADDRESS )
/* fine */
#elif ( SEC_MEMORY_ACCESS == SEC_FILE )
#    error "SEC_MEMORY_ACCESS == SEC_FILE is not implemented!"
#else
#    error "no valid SEC_MEMORY_ACCESS defined"
#endif

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#endif
/***************************************************************************
 * 6. END                                                                  *
 ***************************************************************************/
