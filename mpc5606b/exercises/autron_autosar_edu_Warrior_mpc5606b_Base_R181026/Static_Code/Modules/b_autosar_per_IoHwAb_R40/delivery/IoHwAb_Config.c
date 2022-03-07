/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_Config.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : IoHwAb module const variable definitions for                  **
**              making a library                                              **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.10    05-Mar-2017   Jongyoung  #7764                                   **
** 1.0.9     11-Oct-2015   Jongyoung  #6240                                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_Config.h"
#include "Rte_IoHwAb.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#if (IOHWAB_USE_DIG_DIR == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_DIGDIR_NUM_LGC */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddDigDirNumLgc
  = IOHWAB_DIGDIR_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_DIR == STD_ON) */

#if (IOHWAB_USE_IO_MAN == STD_ON)
#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_FAST_TIMER_ID */
CONST(CoSvAb_TimerType, IOHWAB_CONST) IoHwAb_GddIOMFastTimerID
  = IOHWAB_IOM_FAST_TIMER_ID;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON) */

#if (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_GPT_TIMER_ID */
CONST(Gpt_ChannelType, IOHWAB_CONST) IoHwAb_GddIOMGptTimerID
  = IOHWAB_IOM_GPT_TIMER_ID;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_GPT_TICKS_FOR_1US */
CONST(uint16, IOHWAB_CONST) IoHwAb_GusIOMGptTicksFor1us
  = IOHWAB_IOM_GPT_TICKS_FOR_1US;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON) */

#if (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) )
#define IOHWAB_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
VAR(TaskType, IOHWAB_VAR) IoHwAb_GddIOMTaskFG1 = 0U;
#define IOHWAB_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
#define IOHWAB_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
VAR(TaskType, IOHWAB_VAR) IoHwAb_GddIOMTaskFG2 = 0U;
#define IOHWAB_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
#else /* All but RH850 */
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_TASK_FG1 */
CONST(TaskType, IOHWAB_CONST) IoHwAb_GddIOMTaskFG1
  = IOHWAB_IOM_TASK_FG1;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_TASK_FG2 */
CONST(TaskType, IOHWAB_CONST) IoHwAb_GddIOMTaskFG2
  = IOHWAB_IOM_TASK_FG2;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* RH850 */

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_IOM_MULTI_ACT_DELAY */
CONST(IoHwAb_TimerDelay, IOHWAB_CONST) IoHwAb_GddIOMMultiActDelay
  = IOHWAB_IOM_MULTI_ACT_DELAY;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */

#if (IOHWAB_USE_ANA_IN == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_NUM_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInNumLgc
  = IOHWAB_ANAIN_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_NUM_ADC_ALLGROUP */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInNumAdcAllGroup
  = IOHWAB_ANAIN_NUM_ADC_ALLGROUP;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ANAIN_BUSY_ERR */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucAnaInBusyErr
  = IOHWAB_ANAIN_BUSY_ERR;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */

#if ((IOHWAB_USE_ANA_IN == STD_ON)||(IOHWAB_USE_ANA_IN_DIR == STD_ON))
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ADCHWUNIT_MAX_NUM */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucAdcHwUnitMaxNum
  = IOHWAB_ADCHWUNIT_MAX_NUM;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_ADC_READDIRECT_MAX_DELAY */
CONST(uint16, IOHWAB_CONST) IoHwAb_GucAdcReadDirectMaxDelay
  = IOHWAB_ADC_READDIRECT_MAX_DELAY;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_IN == STD_ON)||(IOHWAB_USE_ANA_IN_DIR == STD_ON) */

#if (IOHWAB_USE_DIG_IN == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MCU_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigInMcuLgc
  = IOHWAB_NUM_DIGIN_MCU_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_LGC */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInLgc
  = IOHWAB_NUM_DIGIN_LGC;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_FAST_HIGH */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInFastHigh
  = IOHWAB_NUM_DIGIN_FAST_HIGH;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_FAST */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInFast
  = IOHWAB_NUM_DIGIN_FAST;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_SLOW */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInSlow
  = IOHWAB_NUM_DIGIN_SLOW;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */

#if (IOHWAB_USE_MC33972 == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MC33972_LGC */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumDigInMC33972Lgc
  = IOHWAB_NUM_DIGIN_MC33972_LGC;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGIN_MC33972 */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigInMC33972
  = IOHWAB_NUM_DIGIN_MC33972;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_MC33972 == STD_ON) */

#if (IOHWAB_USE_DIG_OUT == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_MCU_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutMcuLgc
  = IOHWAB_NUM_DIGOUT_MCU_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_MCU_BUFFER */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutMcuBuffer
  = IOHWAB_NUM_DIGOUT_MCU_BUFFER;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_RESULT_BUFFER */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutResultBuffer
  = IOHWAB_NUM_DIGOUT_RESULT_BUFFER;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_OUT == STD_ON) */

#if (IOHWAB_USE_L9826 == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L9826 */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL9826
  = IOHWAB_NUM_DIGOUT_L9826;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L9826_START_IDX */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL9826StartIdx
  = IOHWAB_NUM_DIGOUT_L9826_START_IDX;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_L9826 == STD_ON) */

#if (IOHWAB_USE_L99MC6 == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L99MC6 */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL99MC6
  = IOHWAB_NUM_DIGOUT_L99MC6;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_L99MC6_START_IDX */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutL99MC6StartIdx
  = IOHWAB_NUM_DIGOUT_L99MC6_START_IDX;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_L99MC6 == STD_ON) */

#if (IOHWAB_USE_TLE7240SL == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_TLE7240SL */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutTLE7240SL
  = IOHWAB_NUM_DIGOUT_TLE7240SL;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_DIGOUT_TLE7240SL_START_IDX */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumDigOutTLE7240SLStartIdx
  = IOHWAB_NUM_DIGOUT_TLE7240SL_START_IDX;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_TLE7240SL == STD_ON) */

#if (IOHWAB_USE_IN_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupply
  = IOHWAB_NUM_ISUPPLY;

/* It is required for DIG and ANA supply switch */
/* IOHWAB_NUM_ISUPPLY_DIG */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyDig
  = IOHWAB_NUM_ISUPPLY_DIG;

/* IOHWAB_NUM_ISUPPLY_DIG */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddISupplyMcuClkHp
  = IOHWAB_ISUPPLY_MCU_CLK_HP;

/* IOHWAB_NUM_ISUPPLY_DIG */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddISupplyMcuClkLp
  = IOHWAB_ISUPPLY_MCU_CLK_LP;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_IN_SUP_SWT == STD_ON) */

#if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY_DIG_IN_LP */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyDigInLp
  = IOHWAB_NUM_ISUPPLY_DIG_IN_LP;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_DIG_SWITCH_DELAY */
CONST(CoSvAb_FastTimerDelay, IOHWAB_CONST) IoHwAb_GddISupplyDigSwitchDelay
  = IOHWAB_ISUPPLY_DIG_SWITCH_DELAY;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#elif (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_DIG_SWITCH_DELAY */
CONST(IoHwAb_GptValueType, IOHWAB_CONST) IoHwAb_GddISupplyDigSwitchDelay
  = IOHWAB_ISUPPLY_DIG_SWITCH_DELAY;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */

#if (IOHWAB_USE_ANA_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_NUM_ISUPPLY_ANA */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddNumISupplyAna
  = IOHWAB_NUM_ISUPPLY_ANA;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_ANA_SWITCH_DELAY */
CONST(CoSvAb_FastTimerDelay, IOHWAB_CONST) IoHwAb_GddISupplyAnaSwitchDelay
  = IOHWAB_ISUPPLY_ANA_SWITCH_DELAY;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#elif (IOHWAB_USE_IO_MAN_GPTTIMER == STD_ON)
#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_ISUPPLY_ANA_SWITCH_DELAY */
CONST(IoHwAb_GptValueType, IOHWAB_CONST) IoHwAb_GddISupplyAnaSwitchDelay
  = IOHWAB_ISUPPLY_ANA_SWITCH_DELAY;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* (IOHWAB_USE_ANA_SUP_SWT == STD_ON) */

#if (IOHWAB_USE_VOL_MON == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_NUM_VOLMON_LEVEL */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumVolMonLevel
  = IOHWAB_NUM_VOLMON_LEVEL;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_VOLMON_FILTER */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucVolMonFilter
  = IOHWAB_VOLMON_FILTER;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_16
#include "MemMap.h"
/* IOHWAB_VOLMON_DEFAULT_VALUE */
CONST(uint16, IOHWAB_CONST) IoHwAb_GusVolMonDefaultValue
  = IOHWAB_VOLMON_DEFAULT_VALUE;
#define IOHWAB_STOP_SEC_CONST_16
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* IOHWAB_VOLMON_ADC_CH_IDX */
CONST(IoHwAb_IndexType, IOHWAB_CONST) IoHwAb_GddVolMonAdcChIdx
  = IOHWAB_VOLMON_ADC_CH_IDX;
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (IOHWAB_USE_VOL_MON == STD_ON) */

#if (IOHWAB_USE_PWM == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_PWM_NUM_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumPwmLgc
  = IOHWAB_PWM_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_PWM == STD_ON) */

#if (IOHWAB_USE_ICU == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_ICU_NUM_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumIcuLgc
  = IOHWAB_ICU_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_ICU == STD_ON) */

#if (IOHWAB_USE_GPT == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_GPT_NUM_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumGptLgc
  = IOHWAB_GPT_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_GPT == STD_ON) */

#if (IOHWAB_USE_OCU == STD_ON)
#define IOHWAB_START_SEC_CONST_8
#include "MemMap.h"
/* IOHWAB_OCU_NUM_LGC */
CONST(uint8, IOHWAB_CONST) IoHwAb_GucNumOcuLgc
  = IOHWAB_OCU_NUM_LGC;
#define IOHWAB_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_OCU == STD_ON) */

#if (IOHWAB_USE_IO_MAN == STD_ON)
#if (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) )
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IOHWAB_CODE)IoHwAb_IOManager_AssignTaskID(void)
{
	IoHwAb_GddIOMTaskFG1 = IOHWAB_IOM_TASK_FG1;
	IoHwAb_GddIOMTaskFG2 = IOHWAB_IOM_TASK_FG2;
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* RH850 */
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

