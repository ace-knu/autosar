/*============================================================================*/
/*                        AUTRON SOFTWARE GROUP                               */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %bbconfig.h%
* Instance:         %
* %version:         1 %
* %created_by:      ca364 %
* %date_created:    2013/12/18 11:06:54 %
*=============================================================================*/
/* DESCRIPTION : header file for FBL configuration                            */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/* COPYRIGHT (C) 2013 HYUNDAI AUTRON Co., Ltd.                                */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*   1.2.0   | 13/Nov/2013 |  Task xar~738                 |      SH Yoo      */
/*   Fix the issue that wachdog doesn't work during flash operation           */
/*   - instruction fetch trap occurs during flash operation                   */
/*----------------------------------------------------------------------------*/
/*   1.1.0   | 16/Oct/2013 |  Task xar~701                 |      SH Yoo      */
/*   Adapt for TC27x (from XC2K project)                                      */
/*============================================================================*/

#ifndef BBCONFIG_H
#define BBCONFIG_H

#define INFINEON_TC27X

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE SW MAPPING                                   */
/*                                                                            */
/******************************************************************************/
/* Value of the Security Key */
#define SK_VALUE          (0x90482442UL)

/* Value of the Security Key mask: ULONG_MAX (SK is 4 bytes long) */
#define SECURITY_KEY_MASK (0xFFFFFFFFUL)

/* Factory mode: Disabled --> Value is 0 */
#define SK_FACTORY_MODE   (0x00000000UL)


#define IS_VALID_SECURITY_KEY_VALUE( value )   ( ( (value^SK_VALUE)        & SECURITY_KEY_MASK ) == 0 )
#define IS_FACTORY_MODE_SECURITY_KEY( value )  ( ( (value^SK_FACTORY_MODE) & SECURITY_KEY_MASK ) == 0 )

#define NUMBER_OF_SW_MODULES 2

/* Define the Main SW Module (with the Main Security Key) */
#define MAIN_SW_MODULE       E_ASW

/* SW module 0: Bootloader */
#define START_BOOT	 0x80004000UL
#define END_BOOT	 0x8000FFE0UL
#define BOOT_IDENT	 (&cs_BootId)
#define BOOT_CRC	 (&cs_CRCArea)
 
/* SW module 1: RTSW */
#define START_ASW    0x80000000UL
#define END_ASW      0x80203FFFUL
#define ASW_IDENT    (const T_SW_MODULE_ID *)0x80000120UL
#define ASW_CRC      (const T_CRC_AREA *)0x8000012CUL
#define ASW_SK       (const T_ULONG *)0x80000200UL

/******************************************************************************/
/*                                                                            */
/*          IDENTIFICATION AREA                                               */
/*                                                                            */
/******************************************************************************/
#define CUSTOMER_ID                 0x00U
#define PRODUCT_ID                  0x34U
#define PRODUCT_VARIANT             0x00U
/* Always a boot */
#define SW_TYPE_ID                  0x01U
#define SW_VERSION                  0x01U
#define INTERMEDIATE_SW_VERSION     0x00U
/* Compatibility area */
#define  SYNCHRO_BYTE_1             0x00U
#define  SYNCHRO_BYTE_2             0x00U

/* Build date */
#define  BOOT_BUILD_YEAR		    0x2013U
#define  BOOT_BUILD_MONTH		    0x07U
#define  BOOT_BUILD_DAY			    0x17U

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE CORE                                         */
/*                                                                            */
/******************************************************************************/
/* Define this if your boot embeds a diag job                                */
/* If this flag is defined, you will need to compile and link some files that  */
/* define the symbols bbdiag_Init and bbdiag_Job                             */
#define DIAG_JOB_ENABLED
    	
/* Define this if you want to activate the CAN Driver of the Bootloader. */
#define FBL_COMM_IF_CAN
   	
/* Define this if your boot embeds a Flash driver                            */
/* If this flag is defined, you will need to compile and link some files that  */
/* implement the Flash API                                                   */
#define FLASH_DRIVER_ENABLED

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE DIAGNOSTIC                                   */
/*                                                                            */
/******************************************************************************/
//#define FBL_DIAG_SPECIFICATION_ES95485_PT
#define FBL_DIAG_SPECIFICATION_ISO_14229
#define FBL_DIAG_P2_CAN_SERVER_MAX	      50U
#define FBL_DIAG_P2_EXT_CAN_SERVER_MAX	  (500 * 10U)
//#define FBL_DIAG_CANTP_RCV_DATA_LEN       129U
#define FBL_DIAG_CANTP_RCV_DATA_LEN       130U
#define FBL_DIAG_CANTP_ST_MIN	          1U

#if (FBL_DIAG_CANTP_RCV_DATA_LEN == 130) 
 #if FBL_DIAG_SPECIFICATION_ES95485_PT
  #error "ES95485_PT requires ServerNumOfBlockLen of 129 bytes"
 #endif
#endif

#if (FBL_DIAG_CANTP_RCV_DATA_LEN == 129) 
 #ifdef FBL_DIAG_SPECIFICATION_ISO_14229
  #error "ISO_14229 requires ServerNumOfBlockLen of 130 bytes"
 #endif
#endif

/* Define the function that will be called to generate the seed */
/* If not defined, there is no security access                  */
#define DIAG_SEED_GENERATION_FUNCTION               bbrand()

/* Define the function that will be called to compute the key */
/* Requires SEED_GENERATION_FUNCTION to be defined            */
#define DIAG_KEY_GENERATION_FUNCTION(seed)          bsseedsi_crypt_si_key( seed )

/* Define the function that is called to initialize the random */
/* generator sequence                                          */
#define DIAG_SEED_INITIALIZATION_FUNCTION( value )  bbrand_seed( value ) 

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE PLL                                          */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE STM                                          */
/*                                                                            */
/******************************************************************************/
#define STM_CLOCK                   100 /* Mhz */

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE WATCHDOG                                     */
/*                                                                            */
/******************************************************************************/
#define FBL_WDT_PRESCALER_CFG          0x0U
	
/* Start value of the watchdog reload timer */
#define FBL_WDT_START_VALUE_CFG        0xFB3BU // 0.2 sec (PRESCALER: 00U, SPB: 100MHz)
#define FBL_WDT_FLASH_START_VALUE_CFG  0xD051U // 2 sec   (PRESCALER: 00U, SPB: 100MHz)

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE CAN                                          */
/*                                                                            */
/******************************************************************************/
/* CAN node */
#define CAN_CELL  					0U

/* CAN port configuration */
#define CAN_INPUT_PORT_CONFIG       0x02U
#define CAN_OUTPUT_PORT_CONFIG      0x15U

#define CAN_NPCR_RXSEL_P2_01        0x0U	  /* CAN0 */
#define CAN_NPCR_RXSEL_P20_07       0x1U
#define CAN_NPCR_RXSEL_P12_00       0x2U
#define CAN_NPCR_RXSEL_P2_04        0x3U
#define CAN_NPCR_RXSEL_P33_07       0x4U
#define CAN_NPCR_RXSEL_P34_02       0x5U

#define CAN_NPCR_RXSEL_P15_03       0x0U	  /* CAN1 */
#define CAN_NPCR_RXSEL_P14_01       0x1U
#define CAN_NPCR_RXSEL_P1_04        0x2U
#define CAN_NPCR_RXSEL_P0_01        0x3U
#define CAN_NPCR_RXSEL_P2_10        0x4U

#define CAN_NPCR_RXSEL_P15_01       0x0U	  /* CAN2 */
#define CAN_NPCR_RXSEL_P2_03        0x1U
#define CAN_NPCR_RXSEL_P32_06       0x2U
#define CAN_NPCR_RXSEL_P14_08       0x3U
#define CAN_NPCR_RXSEL_P10_02       0x4U

#define CAN_NPCR_RXSEL_P0_03        0x0U	  /* CAN3 */
#define CAN_NPCR_RXSEL_P32_02       0x1U
#define CAN_NPCR_RXSEL_P20_00       0x2U
#define CAN_NPCR_RXSEL_P11_10       0x3U
#define CAN_NPCR_RXSEL_P20_09       0x4U

#define Mcan_N_Config_TxPort()  { P20_IOCR8.B1.PC8 = CAN_OUTPUT_PORT_CONFIG;\
                                }
#define Mcan_N_Config_RxPort()  { P20_IOCR4.B1.PC7 = CAN_INPUT_PORT_CONFIG;\
                                  CAN_NPCR0.B.RXSEL = CAN_NPCR_RXSEL_P20_07;\
								}

/* CAN baud rate */
#define CAN_DEFAULT_SPEED   	    CAN_500KBPS
#define FBL_CAN_NODE_SPEED_CONFIG_ARRAY   { {CAN_500KBPS,1U/* FDRL.STEP */,((T_UWORD)(5 - 1)<<8)|((T_UWORD)(4 - 1)<<12)|((T_UWORD)(2 - 1)<<6)|(T_UWORD)(20 - 1)}, {CAN_100KBPS,1U/* FDRL.STEP */,((T_UWORD)(16 - 1)<<8)|((T_UWORD)(8 - 1)<<12)|((T_UWORD)(3 - 1)<<6)|(T_UWORD)(40 - 1)},}

/* CAN message object identifier */
#define DIAG_RX_IDENTIFIER   	    0x07C4UL	 /* physical communication   */
#define DIAG_TX_IDENTIFIER   	    0x07CCUL	 /* physical communication   */
#define DIAG_FNC_RX_IDENTIFIER      0x07DFUL	 /* functional communication */

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE FLASH                                        */
/*                                                                            */
/******************************************************************************/
#define FLASH_ALIGNMENT             128UL

/******************************************************************************/
/*                                                                            */
/*          CONFIGURATION OF THE CRC16                                        */
/*                                                                            */
/******************************************************************************/
/* This define indicates if the CRC16 module is embedded in the FBL */
#define CRC_MODULE_COMPILED_IN_FBL

/* Use this define to set the block size for the CRC calculation. This size has to */
/* be defined according to the hardware (CPU, clock...)                            */
/* Between two bloks, the watchdog is refreshed                                    */
#define CRC16_BLOCK_SIZE  			32768UL

#endif

