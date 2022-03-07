/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
#ifndef APP_OSHOOK_H
#define APP_OSHOOK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_Util.h"
#include "Reg_eSys_Stm.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

FUNC(void, OS_CODE) Opf_StartOsProfilerWrap();

FUNC(void, OS_CODE) Opf_StopOsProfilerWrap();

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

