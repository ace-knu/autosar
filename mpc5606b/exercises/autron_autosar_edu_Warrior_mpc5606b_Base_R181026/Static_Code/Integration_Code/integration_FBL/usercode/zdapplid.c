/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: zdapplid.c                                                    **
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
/* Common declarations */
/* ------------------- */
#include "Std_Types.h"

/* Used interfaces */
/* --------------- */

/* Provide interface */
/* ----------------- */
#include "zdapplid.h"

/* Private functions macros, constants, types and datas */
/* ---------------------------------------------------- */
/* Functions macros */

#pragma ghs section rodata=".ASW_IDENT"
const T_IDENT cat_ApplId =
{
	CUSTOMER_ID,
	PRODUCT_ID,
	PRODUCT_VARIANT | SW_TYPE_ID,
	SW_VERSION,
	INTERMEDIATE_SW_VERSION,
	SYNCHRO_BOOT_ASW | SYNCHRO_ASW_CALIB,
	SYNCHRO_ASW1_ASW2,
	RESERVED,
	ASW_BUILD_DAY,
	ASW_BUILD_MONTH,
	ASW_BUILD_YEAR,
   	ASW_CRC_VALUE,
   	ASW_NUMBER_OF_AREA
};

const T_TESTADR cat_AswAreaAddr[ASW_DIM_OF_AREA] =
{
    {ASW_START_ADDR_AREA1,ASW_END_ADDR_AREA1},
    {ASW_START_ADDR_AREA2,ASW_END_ADDR_AREA2},
    {ASW_START_ADDR_AREA3,ASW_END_ADDR_AREA3},
    {ASW_START_ADDR_AREA4,ASW_END_ADDR_AREA4},
    {ASW_START_ADDR_AREA5,ASW_END_ADDR_AREA5},
    {ASW_START_ADDR_AREA6,ASW_END_ADDR_AREA6},
    {ASW_START_ADDR_AREA7,ASW_END_ADDR_AREA7},
    {ASW_START_ADDR_AREA8,ASW_END_ADDR_AREA8},
    {ASW_START_ADDR_AREA9,ASW_END_ADDR_AREA9},
    {ASW_START_ADDR_AREA10,ASW_END_ADDR_AREA10},
    {ASW_START_ADDR_AREA11,ASW_END_ADDR_AREA11},
    {ASW_START_ADDR_AREA12,ASW_END_ADDR_AREA12},
    {ASW_START_ADDR_AREA13,ASW_END_ADDR_AREA13},
    {ASW_START_ADDR_AREA14,ASW_END_ADDR_AREA14},
    {ASW_START_ADDR_AREA15,ASW_END_ADDR_AREA15},
    {ASW_START_ADDR_AREA16,ASW_END_ADDR_AREA16},
    {ASW_START_ADDR_AREA17,ASW_END_ADDR_AREA17},
    {ASW_START_ADDR_AREA18,ASW_END_ADDR_AREA18},
    {ASW_START_ADDR_AREA19,ASW_END_ADDR_AREA19},
    {ASW_START_ADDR_AREA20,ASW_END_ADDR_AREA20},
};
#pragma ghs section

#pragma ghs section rodata=".ASW_SECURITY_KEY"
const uint32 AswSecurityKey = ECU_KEYS;
#pragma ghs section




