/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_Config.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : IoHwAb module const variable declarations for                 **
**              making a library                                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.1.3     05-Mar-2017   Jongyoung  #7764                                   **
** 1.1.2     11-Dec-2016   Jongyoung  #6845, #6929                            **
** 1.1.1     11-Oct-2015   Jongyoung  #6240                                   **
*******************************************************************************/

#ifndef IOHWAB_CONFIG_H
#define IOHWAB_CONFIG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"
#if (IOHWAB_USE_IO_MAN == STD_ON)
#include "Os.h"
#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#include "CoSvAb_GenExterns.h"
#endif
#if (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#include "Gpt.h"
#endif

#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */
#include "Rte_Type.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#if (IOHWAB_USE_DIG_DIR == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_DIGDIR_NUM_LGC */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddDigDirNumLgc;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_DIR == STD_ON) */

#if (IOHWAB_USE_IO_MAN == STD_ON)
#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_FAST_TIMER_ID */
extern CONST(CoSvAb_TimerType, IOHWAB_CONST) IoHwAb_GddIOMFastTimerID;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON) */

#if (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_GPT_TIMER_ID */
extern CONST(Gpt_ChannelType, IOHWAB_CONST) IoHwAb_GddIOMGptTimerID;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_IOM_GPT_TICKS_FOR_1US */
extern CONST(uint16, IOHWAB_CONST) IoHwAb_GusIOMGptTicksFor1us;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON) */

#if (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) )
#define IOHWAB_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
extern VAR(TaskType, IOHWAB_VAR) IoHwAb_GddIOMTaskFG1;
#define IOHWAB_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
#define IOHWAB_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
extern VAR(TaskType, IOHWAB_VAR) IoHwAb_GddIOMTaskFG2;
#define IOHWAB_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
#else /* All but RH850 */
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_TASK_FG1 */
extern CONST(TaskType, IOHWAB_CONST) IoHwAb_GddIOMTaskFG1;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_TASK_FG2 */
extern CONST(TaskType, IOHWAB_CONST) IoHwAb_GddIOMTaskFG2;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_MULTI_ACT_DELAY */
extern CONST(IoHwAb_TimerDelay, IOHWAB_CONST) IoHwAb_GddIOMMultiActDelay;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */

#if (IOHWAB_USE_ANA_IN == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_NUM_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInNumLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_NUM_ADC_ALLGROUP */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInNumAdcAllGroup;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_BUSY_ERR */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInBusyErr;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */

#if ((IOHWAB_USE_ANA_IN == STD_ON)||(IOHWAB_USE_ANA_IN_DIR == STD_ON))
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ADCHWUNIT_MAX_NUM */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucAdcHwUnitMaxNum;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_ADCHWUNIT_MAX_NUM */
extern CONST(uint16, IOHWAB_CONST) IoHwAb_GucAdcReadDirectMaxDelay;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_IN == STD_ON)||(IOHWAB_USE_ANA_IN_DIR == STD_ON) */


#if (IOHWAB_USE_DIG_IN == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MCU_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigInMcuLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_LGC */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInLgc;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_FAST_HIGH */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInFastHigh;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_FAST */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInFast;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_SLOW */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInSlow;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */

#if (IOHWAB_USE_MC33972 == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MC33972_LGC */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInMC33972Lgc;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MC33972 */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigInMC33972;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_MC33972 == STD_ON) */

#if (IOHWAB_USE_DIG_OUT == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_MCU_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutMcuLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_MCU_BUFFER */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutMcuBuffer;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_RESULT_BUFFER */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutResultBuffer;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_OUT == STD_ON) */

#if (IOHWAB_USE_L9826 == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L9826 */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL9826;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L9826_START_IDX */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL9826StartIdx;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_L9826 == STD_ON) */

#if (IOHWAB_USE_L99MC6 == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L99MC6 */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL99MC6;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L99MC6_START_IDX */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL99MC6StartIdx;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_L99MC6 == STD_ON) */

#if (IOHWAB_USE_TLE7240SL == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_TLE7240SL */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutTLE7240SL;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_TLE7240SL_START_IDX */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutTLE7240SLStartIdx;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_TLE7240SL == STD_ON) */

#if (IOHWAB_USE_IN_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupply;

/* IOHWAB_NUM_ISUPPLY_DIG */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyDig;

/* IOHWAB_NUM_ISUPPLY_DIG */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddISupplyMcuClkHp;

/* IOHWAB_NUM_ISUPPLY_DIG */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddISupplyMcuClkLp;

#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IN_SUP_SWT == STD_ON) */

#if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY_DIG_IN_LP */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyDigInLp;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_DIG_SWITCH_DELAY */
extern CONST(CoSvAb_FastTimerDelay, IOHWAB_CONST) IoHwAb_GddISupplyDigSwitchDelay;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#elif (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_DIG_SWITCH_DELAY */
extern CONST(IoHwAb_GptValueType, IOHWAB_CONST) IoHwAb_GddISupplyDigSwitchDelay;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */


#if (IOHWAB_USE_ANA_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY_ANA */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyAna;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_ANA_SWITCH_DELAY */
extern CONST(CoSvAb_FastTimerDelay, IOHWAB_CONST) IoHwAb_GddISupplyAnaSwitchDelay;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#elif (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_ANA_SWITCH_DELAY */
extern CONST(IoHwAb_GptValueType, IOHWAB_CONST) IoHwAb_GddISupplyAnaSwitchDelay;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif /* (IOHWAB_USE_ANA_SUP_SWT == STD_ON) */

#if (IOHWAB_USE_VOL_MON == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_VOLMON_LEVEL */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumVolMonLevel;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_VOLMON_FILTER */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucVolMonFilter;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_VOLMON_DEFAULT_VALUE */
extern CONST(uint16, IOHWAB_CONST) IoHwAb_GusVolMonDefaultValue;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_VOLMON_ADC_CH_IDX */
extern CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddVolMonAdcChIdx;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_VOL_MON == STD_ON) */

#if (IOHWAB_USE_PWM == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_PWM_NUM_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumPwmLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_PWM == STD_ON) */

#if (IOHWAB_USE_ICU == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ICU_NUM_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumIcuLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_ICU == STD_ON) */

#if (IOHWAB_USE_GPT == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_GPT_NUM_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumGptLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_GPT == STD_ON) */

#if (IOHWAB_USE_OCU == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_OCU_NUM_LGC */
extern CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumOcuLgc;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_OCU == STD_ON) */

/*******************************************************************************
**                      MCU Dependency feature                                **
*******************************************************************************/
/* Bolero */
#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
#define IOHWAB_PORT_A	(0U)
#define IOHWAB_PORT_B	(16U)
#define IOHWAB_PORT_C	(32U)
#define IOHWAB_PORT_D	(48U)
#define IOHWAB_PORT_E	(64U)
#define IOHWAB_PORT_F	(80U)
#define IOHWAB_PORT_G	(96U)
#define IOHWAB_PORT_H	(112U)
#define IOHWAB_PORT_I	(128U)
#define IOHWAB_PORT_J	(144U)
#endif 

/* RH850F1L/K */
#if (IOHWAB_USE_IO_MAN == STD_ON)
#if (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) )
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOManager_AssignTaskID(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* RH850 */
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */
#endif /* IOHWAB_CONFIG_H */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

