/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mem_Integration_User.h                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemStack Integration Module                           **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: Only STD_ON or STD_OFF of the macros can  **
**                                  be modified by user                       **
**                                                                            **
*******************************************************************************/

#ifndef MEM_INTEGRATION_USER_H_
#define MEM_INTEGRATION_USER_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "NvM.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(uint8, NVM_CODE) Mem_ExceptionHandlerOnFeeInitFail(void);

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
 * START : Only STD_ON or STD_OFF of the macros can be modified by user        *
 ******************************************************************************/

/* STD_ON  : When WriteAll is called , mainFunctions of the NvM,Fee,Fls,Eep,Ea 
 *           are called in the while-loop 
 * STD_OFF : When WriteAll is called , mainFunctions of the NvM,Fee,Fls,Eep,Ea
 *           are called by the GPT or periodic task 
 */

/* CAUTION!!!
 *
 * WriteAll : Depending on the type of MCU, 
 *            there may be a timing problems.
 * Default  : STD_OFF
 *
 * please contact us. 
 *******************************************************************************/
 

#define MEM_WRITEALL_FAST_MODE    (STD_OFF)


/*******************************************************************************
 * END : Only STD_ON or STD_OFF of the macros can be modified by user          *
 ******************************************************************************/

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* MEM_INTEGRATION_USER_H_ */
