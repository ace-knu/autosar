
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Rte_SWC_IoHwAbTest.h"
#include "IoHwAb_Util.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define IOHWAB_TEST                                   STD_ON

#define MCU_TC26X                                     STD_OFF
#define MCU_TC27X                                     STD_OFF
#define MCU_MPC560XB                                  STD_ON

#define IOHWAB_TEST_MAXCOUNT                          10000

/*************************      Digital Direct     ****************************/
#define IOHWAB_TEST_DIGDIR                            STD_ON
#if (IOHWAB_TEST != STD_ON)
#undef IOHWAB_TEST_DIGDIR
#endif /* (IOHWAB_TEST != STD_ON) */
#if (IOHWAB_TEST_DIGDIR == STD_ON)
#define IOHWAB_TEST_DIGDIR_MAXCOUNT                   1000
#endif /* (IOHWAB_TEST_DIGDIR == STD_ON) */


/*************************            Gpt          ****************************/
#define IOHWAB_TEST_GPT                               STD_OFF
#if (IOHWAB_TEST_GPT == STD_ON)
#define IOHWAB_TEST_GPT_USE_PINOUT                    STD_ON
#define IOHWAB_TEST_GPT_NUM                           7
#if (IOHWAB_TEST_GPT_USE_PINOUT == STD_ON)
#if ((MCU_TC26X == STD_ON) || (MCU_TC27X == STD_ON))
#define IOHWAB_TEST_GPT_PIN                           P33_OUT.B.P13  /* P33.13 */
#elif (MCU_MPC560XB == STD_ON)
#define IOHWAB_TEST_GPT_PIN                           70             /* PE6 */
#endif
#endif /* (IOHWAB_TEST_GPT_USE_PINOUT == STD_ON) */
#endif /* (IOHWAB_TEST_GPT == STD_ON) */

/*************************            Pwm          ****************************/
#define IOHWAB_TEST_PWM                               STD_ON
#if (IOHWAB_TEST != STD_ON)
#undef IOHWAB_TEST_PWM
#endif /* (IOHWAB_TEST != STD_ON) */
#if (IOHWAB_TEST_PWM == STD_ON)
#define IOHWAB_TEST_PWM_NUM                           1
#if ((MCU_TC27X == STD_ON) || (MCU_TC27X == STD_ON))
/* 
  GtmGlobalClk : 100Mhz
  GTM_FIXED_CLOCK_1 : 2^4
  100,000,000Hz / 2^4 = 6,250,000Hz(1s)
  Target Hz : 100Hz(10ms)
*/
#define IOHWAB_TEST_PWM_DEFAULT_PERIOD                62500 /* tick */
#elif (MCU_MPC560XB == STD_ON)
/* 
  Target Hz : 100Hz(10ms)
*/
#define IOHWAB_TEST_PWM_DEFAULT_PERIOD                30000 /* us */
#else
#define IOHWAB_TEST_PWM_DEFAULT_PERIOD                10000
#endif
#endif /* (IOHWAB_TEST_PWM == STD_ON) */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
uint16	TestIoHwAb_TestCount = 1;

/*************************      Digital Direct     ****************************/
uint16  TestIoHwAb_DigDirInTestCount  = 65000;
uint16  TestIoHwAb_DigDirOutTestCount = 200;

boolean DigDir_IsInput_Value     = IOHWAB_FALSE; /*0*/
boolean DigDir_IsOutput_Value    = IOHWAB_FALSE; 
uint8   DigDir_ReadDirect_Value  = IOHWAB_LOW;
uint8   DigDir_WriteDirect_Value = IOHWAB_LOW;
uint8   DigDir_SetToInput_Value  = IOHWAB_LOW;
uint8   DigDir_SetToOutput_Value = IOHWAB_LOW;


/*************************            Gpt          ****************************/
#if (IOHWAB_TEST_GPT == STD_ON)
uint8 TestIoHwAb_GptTestPortLevel = 0;
uint16 TestIoHwAb_GptTestCount = 100;
uint16 TestIoHwAb_GptTestCheckCount = 10;
boolean TestIoHwAb_GptRunning = IOHWAB_FALSE;
boolean TestIoHwAb_GptExpired = IOHWAB_TRUE;
boolean TestIoHwAb_GptEnableReq = IOHWAB_TRUE;
boolean TestIoHwAb_GptDisableReq = IOHWAB_FALSE;

#if ((MCU_TC27X == STD_ON) || (MCU_TC27X == STD_ON))
/* GTM_FIXED_CLOCK_3 */
/* 100,000,000Hz/2^12 = 24,414Hz */
IoHwAb_GptValueType TestIoHwAb_GptTimerValue = 24414/4;
#elif (MCU_MPC560XB == STD_ON)
/* 10ms */
IoHwAb_GptValueType TestIoHwAb_GptTimerValue = 30000;
#endif
IoHwAb_GptValueType TestIoHwAb_GptRemainTime[IOHWAB_TEST_GPT_NUM] = {0, };
IoHwAb_GptValueType TestIoHwAb_GptGetElapsedTime[IOHWAB_TEST_GPT_NUM]   = {0, };
uint16 TestIoHwAb_GptCount[IOHWAB_TEST_GPT_NUM] = {0, };

#endif /* (IOHWAB_TEST_GPT == STD_ON) */

/*************************            Pwm          ****************************/
#if (IOHWAB_TEST_PWM == STD_ON)
uint16 TestIoHwAb_PwmTestCount = 100;
uint16 TestIoHwAb_PwmTestMode = 100;
uint16 TestIoHwAb_PwmPeriod = IOHWAB_TEST_PWM_DEFAULT_PERIOD;
uint16 TestIoHwAb_PwmDuty = 0x4000;  /* 50% */
IoHwAb_LevelType TestIoHwAb_PwmLevel[IOHWAB_TEST_PWM_NUM];
#endif /* (IOHWAB_TEST_PWM == STD_ON) */


/*******************************************************************************
** Function Name        : RE_IoHwAbTest_DigDir                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                         Function(s) invoked   :                            **
**				     Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_IsInput              **
**			       Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_IsOutput	            **
**			       Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_ReadDirect           **
**             Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_WriteDirect          **
**             Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_SetToInput           **
**			       Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_SetToOutput          **
*******************************************************************************/
#define SWC_IoHwAbTest_START_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"
void RE_IoHwAbTest_DigDir(void)
{
  #if (IOHWAB_TEST_DIGDIR == STD_ON)
  if ((TestIoHwAb_TestCount % TestIoHwAb_DigDirInTestCount) == 0)
  {
     Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_IsOutput(&DigDir_IsOutput_Value);

     if (DigDir_IsOutput_Value == IOHWAB_TRUE)
     {
       Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_SetToInput();
     }
     Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_ReadDirect(&DigDir_ReadDirect_Value);
  }

  if ((TestIoHwAb_TestCount % TestIoHwAb_DigDirOutTestCount) == 0)
  {
    Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_IsInput(&DigDir_IsInput_Value);
    if (DigDir_IsInput_Value == IOHWAB_TRUE)
    {
      Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_SetToOutput();
    }
    Rte_Call_R_IoHwAbDigitalDirectLogical_PE5_WriteDirect(DigDir_WriteDirect_Value);
	  
	  if (DigDir_WriteDirect_Value == IOHWAB_HIGH)
	  {
         DigDir_WriteDirect_Value = IOHWAB_LOW;
	  }
	  else
	  {
         DigDir_WriteDirect_Value = IOHWAB_HIGH;
      }
  }

  #endif /* (IOHWAB_TEST_DIGDIR == STD_ON) */
}
#define SWC_IoHwAbTest_STOP_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"


/*******************************************************************************
** Function Name        : RE_IoHwAbTest_Gpt                                   **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_EnableNotification  **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_DisableNotification **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_StartTimer            **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_StopTimer             **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_TimeRemaining      **
**                        Rte_Call_R_IoHwAbGptLogical_EMIOS4_GetTimeElapsed     **
*******************************************************************************/
#define SWC_IoHwAbTest_START_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"
void RE_IoHwAbTest_Gpt(void)
{
  #if (IOHWAB_TEST_GPT == STD_ON)
  uint8 LucIndex;
  if ( (TestIoHwAb_TestCount % TestIoHwAb_GptTestCount) == 0)
  {
    Rte_Call_R_IoHwAbGptLogical_EMIOS4_StopTimer();
    Rte_Call_R_IoHwAbGptLogical_EMIOS4_EnableNotification();
    Rte_Call_R_IoHwAbGptLogical_EMIOS4_StartTimer(TestIoHwAb_GptTimerValue);
  }

  if ( (TestIoHwAb_TestCount % TestIoHwAb_GptTestCheckCount) == 0)
  {
    for (LucIndex = 0; LucIndex < IOHWAB_TEST_GPT_NUM; LucIndex++)
    {
      Rte_Call_R_IoHwAbGptLogical_EMIOS4_GetTimeElapsed(&TestIoHwAb_GptGetElapsedTime[LucIndex]);
      Rte_Call_R_IoHwAbGptLogical_EMIOS4_GetTimeRemaining(&TestIoHwAb_GptRemainTime[LucIndex]);
    }
  }

  #endif /* (IOHWAB_TEST_GPT == STD_ON) */
}
#define SWC_IoHwAbTest_STOP_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"


#define SWC_IoHwAbTest_START_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"
void RE_IoHwAbTest_Dummy_GptCbk(void){}


void RE_IoHwAbTest_EMIOS4_GptCbk(void) 

{
#if (IOHWAB_TEST_GPT == STD_ON)
	TestIoHwAb_GptExpired = IOHWAB_TRUE;
  if (TestIoHwAb_GptTestPortLevel == IOHWAB_LOW)
  {
    TestIoHwAb_GptTestPortLevel = IOHWAB_HIGH;
    Rte_Call_R_IoHwAbDigitalDirectLogical_PE6_WriteDirect(IOHWAB_HIGH);
  }
  else
  {
    TestIoHwAb_GptTestPortLevel = IOHWAB_LOW;
    Rte_Call_R_IoHwAbDigitalDirectLogical_PE6_WriteDirect(IOHWAB_LOW);

  }
#endif
}

#define SWC_IoHwAbTest_STOP_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"



/*******************************************************************************
** Function Name        : RE_IoHwAbTest_Pwm                                   **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_SetDutyCycle       **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_SetPeriodAndDuty   **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_SetOutputToIdle    **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_GetOutputState     **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_EnableNotification **
**                     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_DisableNotification**
*******************************************************************************/
#define SWC_IoHwAbTest_START_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"
void RE_IoHwAbTest_Pwm(void)
{
  #if (IOHWAB_TEST_PWM == STD_ON)
  
  if ((TestIoHwAb_TestCount % TestIoHwAb_PwmTestCount) == 0)
  {
     Rte_Call_R_IoHwAbPwmLogical_EMIOS23_SetPeriodAndDuty
     (TestIoHwAb_PwmPeriod, TestIoHwAb_PwmDuty);
     TestIoHwAb_PwmDuty += 0x400U;
  }
  if (TestIoHwAb_PwmDuty > 0x7FFFU)
  {
    TestIoHwAb_PwmDuty = 0U;
  }
  #endif  /*(IOHWAB_TEST_PWM == STD_ON)*/
}
#define SWC_IoHwAbTest_STOP_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"


/*******************************************************************************
** Function Name        : RE_IoHwAbTest                                       **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define SWC_IoHwAbTest_START_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"
void RE_IoHwAbTest(void)
{
  #if (IOHWAB_TEST_DIGDIR == STD_ON)
  RE_IoHwAbTest_DigDir();
  #endif /* (IOHWAB_TEST_DIGDIR == STD_ON) */

  #if (IOHWAB_TEST_GPT == STD_ON)
  RE_IoHwAbTest_Gpt();
  #endif /* (IOHWAB_TEST_GPT == STD_ON) */

  #if (IOHWAB_TEST_PWM == STD_ON)
  RE_IoHwAbTest_Pwm();
  #endif /* (IOHWAB_TEST_PWM == STD_ON) */

  if (TestIoHwAb_TestCount == IOHWAB_TEST_MAXCOUNT)
    TestIoHwAb_TestCount = 0;
  else
    TestIoHwAb_TestCount++;
}
#define SWC_IoHwAbTest_STOP_SEC_CODE
#include "SWC_IoHwAbTest_MemMap.h"

/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/
