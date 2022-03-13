/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: zdapplid.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTRON FBL                                            **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.0     29-Apr-2016  Jinseok Park    Initial version                     **
*******************************************************************************/

#ifndef ZDAPPLID_H                               /* To avoid double inclusion */
#define ZDAPPLID_H

#include "Std_Types.h"

/* ZDAPPLID.H Content : */

/* Information common to BootSW and ASW */
#define CUSTOMER_ID               0x00U        /* CC: Customer ID (1 byte)     */
#define PRODUCT_ID                0x34U        /* AA: Product ID  (1 byte)     */
#define PRODUCT_VARIANT           0x00U        /* V_: Product variant (high digit only) from 0:(0x00) to F:(0xF0) */

/* compatibility number between BootSW and ASW */
#define SYNCHRO_BOOT_ASW          0x00U        /* E_: Synchro between BootSW and ASW (high digit only) from 0:(0x00), 1:(0x10), ... to F:(0xF0) */

/* compatibility number between ASW and Calib */
#define SYNCHRO_ASW_CALIB         0x00U        /* _E: Synchro between ASW and Calibratoin (low digit only) from 0:(0x00), 1:(0x01), ... to F:(0x0F) */

/* Information relative to the ASW the naming rule */
#define SW_TYPE_ID                0x02U       /* _T: SW type (low digit only) from 0:(0x00) to F:(0x0F) (=0x02 for ASW)*/
#define SW_VERSION                0x01U       /* VV: SW version (1 byte)    */
#define INTERMEDIATE_SW_VERSION   0x00U       /* ZZ: Intermidiate SW version (1 byte)    */
#define SYNCHRO_ASW1_ASW2         0x00U       /* _F: Synchro between ASW1 and ASW2 (low digit only) from 0:(0x00), 1:(0x01), ... to F:(0x0F) */
#define RESERVED                  0xFFU       /* RR: Reserved 0xFF (1 byte)    */


/* Information relative to the ASW build date */
#define ASW_BUILD_DAY             0x01U       /* 0xXX   (1 byte)  */
#define ASW_BUILD_MONTH           0x01U       /* 0xXX   (1 byte)  */
#define ASW_BUILD_YEAR            0x2015U     /* 0xXXXX (2 bytes) */

/* security key */
#define ECU_KEYS            	  0x90482442UL /* 0xXXXX (4 bytes) */

/* Information relative to the ASW CRC */
#define ASW_CRC_VALUE             0xFFFFU     /* Value of the CRC (2 bytes) initialized to 0xFFFF, then be computed and set by CKS_CALC */

/* Information relative to the ASW CRC */
#define ASW_DIM_OF_AREA           20U         /* Number of non contigues area (2 bytes) */

#define ASW_NUMBER_OF_AREA		 0xFFFFU     /* Number of non contigues area (2 bytes) */
#define ASW_START_ADDR_AREA1	 0xFFFFFFFFUL /* Start address of area1 (4 bytes) */
#define ASW_END_ADDR_AREA1	     0xFFFFFFFFUL /* End address of area1 (4 bytes) */
#define ASW_START_ADDR_AREA2     0xFFFFFFFFUL /* Start address of area2 (4 bytes) */
#define ASW_END_ADDR_AREA2       0xFFFFFFFFUL /* End address of area2 (4 bytes) */
#define ASW_START_ADDR_AREA3     0xFFFFFFFFUL /* Start address of area3 (4 bytes) */
#define ASW_END_ADDR_AREA3       0xFFFFFFFFUL /* End address of area3 (4 bytes) */
#define ASW_START_ADDR_AREA4     0xFFFFFFFFUL /* Start address of area4 (4 bytes) */
#define ASW_END_ADDR_AREA4       0xFFFFFFFFUL /* End address of area4 (4 bytes) */
#define ASW_START_ADDR_AREA5     0xFFFFFFFFUL /* Start address of area5 (4 bytes) */
#define ASW_END_ADDR_AREA5       0xFFFFFFFFUL /* End address of area5 (4 bytes) */
#define ASW_START_ADDR_AREA6     0xFFFFFFFFUL /* Start address of area6 (4 bytes) */
#define ASW_END_ADDR_AREA6       0xFFFFFFFFUL /* End address of area6 (4 bytes) */
#define ASW_START_ADDR_AREA7     0xFFFFFFFFUL /* Start address of area7 (4 bytes) */
#define ASW_END_ADDR_AREA7       0xFFFFFFFFUL /* End address of area7 (4 bytes) */
#define ASW_START_ADDR_AREA8     0xFFFFFFFFUL /* Start address of area8 (4 bytes) */
#define ASW_END_ADDR_AREA8       0xFFFFFFFFUL /* End address of area8 (4 bytes) */
#define ASW_START_ADDR_AREA9     0xFFFFFFFFUL /* Start address of area9 (4 bytes) */
#define ASW_END_ADDR_AREA9       0xFFFFFFFFUL /* End address of area9 (4 bytes) */
#define ASW_START_ADDR_AREA10    0xFFFFFFFFUL /* Start address of area10(4 bytes) */
#define ASW_END_ADDR_AREA10      0xFFFFFFFFUL /* End address of area10(4 bytes) */
#define ASW_START_ADDR_AREA11    0xFFFFFFFFUL /* Start address of area11(4 bytes) */
#define ASW_END_ADDR_AREA11      0xFFFFFFFFUL /* End address of area11(4 bytes) */
#define ASW_START_ADDR_AREA12    0xFFFFFFFFUL /* Start address of area12(4 bytes) */
#define ASW_END_ADDR_AREA12      0xFFFFFFFFUL /* End address of area12(4 bytes) */
#define ASW_START_ADDR_AREA13    0xFFFFFFFFUL /* Start address of area13(4 bytes) */
#define ASW_END_ADDR_AREA13      0xFFFFFFFFUL /* End address of area13(4 bytes) */
#define ASW_START_ADDR_AREA14    0xFFFFFFFFUL /* Start address of area14(4 bytes) */
#define ASW_END_ADDR_AREA14      0xFFFFFFFFUL /* End address of area14(4 bytes) */
#define ASW_START_ADDR_AREA15    0xFFFFFFFFUL /* Start address of area15(4 bytes) */
#define ASW_END_ADDR_AREA15      0xFFFFFFFFUL /* End address of area15(4 bytes) */
#define ASW_START_ADDR_AREA16    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA16      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA17    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA17      0xFFFFFFFFUL /* End address of area10(4 bytes) */
#define ASW_START_ADDR_AREA18    0xFFFFFFFFUL /* Start address of area11(4 bytes) */
#define ASW_END_ADDR_AREA18      0xFFFFFFFFUL /* End address of area11(4 bytes) */
#define ASW_START_ADDR_AREA19    0xFFFFFFFFUL /* Start address of area12(4 bytes) */
#define ASW_END_ADDR_AREA19      0xFFFFFFFFUL /* End address of area12(4 bytes) */
#define ASW_START_ADDR_AREA20    0xFFFFFFFFUL /* Start address of area13(4 bytes) */
#define ASW_END_ADDR_AREA20      0xFFFFFFFFUL /* End address of area13(4 bytes) */
#define ASW_START_ADDR_AREA21    0xFFFFFFFFUL /* Start address of area14(4 bytes) */
#define ASW_END_ADDR_AREA21      0xFFFFFFFFUL /* End address of area14(4 bytes) */
#define ASW_START_ADDR_AREA22    0xFFFFFFFFUL /* Start address of area15(4 bytes) */
#define ASW_END_ADDR_AREA22      0xFFFFFFFFUL /* End address of area15(4 bytes) */
#define ASW_START_ADDR_AREA23    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA23      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA24    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA24      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA25    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA25      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA26    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA26      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA27    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA27      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA28    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA28      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA29    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA29      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA30    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA30      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA31    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA31      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA32    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA32      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA33    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA33      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA34    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA34      0xFFFFFFFFUL /* End address of area16(4 bytes) */
#define ASW_START_ADDR_AREA35    0xFFFFFFFFUL /* Start address of area16(4 bytes) */
#define ASW_END_ADDR_AREA35      0xFFFFFFFFUL /* End address of area16(4 bytes) */

/******************************************************************************/
/* Reservation of two bytes for program checksum                              */
/*                                                                            */
/* ATTENTION : crc_value have to be placed at an even address !               */
/*                                                                            */
/******************************************************************************/

/*******************************************************************/
/* APPLICATION/CALIBRATION SW Identification Structure Description */
/*******************************************************************/
typedef struct {
  /* ASW identification according to the naming rule */
  uint8 cub_customer_id;
  uint8 cub_product_id;
  uint8 cub_product_variant;
  uint8 cub_sw_version;
  uint8 cub_intermediate_sw_version;
  uint8 cub_synchro_boot_asw_calib;
  uint8 cub_synchro_boot1_boot2_asw1_asw2;					  
  uint8 cub_reserved;
  /* ASW build date */
  uint8 cub_build_day;
  uint8 cub_build_month;
  uint16 cuw_build_year;
  /* ASW CRC */
  uint16 cuw_crc_value;
  uint16 cub_crc_number_of_area;
}T_IDENT;


/********************************************************/
/* ECU STATUS + NB REPROG ATTEMPT Structure Description */
/********************************************************/
typedef struct {
  /* ECU status + INFRACT ATTEMPT  */
  uint16 cub_ECU_status;
  uint16 infract_attempt;
}T_ECU_STATUS;

/********************************************************/
/* CKS structure  										*/
/********************************************************/
typedef struct {
	uint32 StartAdr;
	uint32 EndAdr;
}T_TESTADR;


/* ZDAPPLID.H Content : */

/*
#pragma CONST_SEG SECURITY_KEY 
extern const uint32 cul_sk;
#pragma CONST_SEG DEFAULT
*/

#pragma ghs section rodata=".ASW_IDENT"
extern const T_IDENT cat_ApplId;
extern const T_TESTADR cat_AswAreaAddr[ASW_DIM_OF_AREA];
#pragma ghs section

#endif  /* ZDAPPLID_H */
