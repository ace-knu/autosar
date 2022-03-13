/* App_Os.c */

#include "Os.h"
#include "Os_counter_config.h"
#include "Reg_Macros.h"
#include "Reg_eSys_SIUL.h"

boolean GblLedInit = FALSE;

void DelayMS(uint32 LulMilliSecDelay)
{
  TickType LddTickDelay;
  TickType LddCount;
  TickType LddCurrentCount;
  TickType LddElapsedCount = 0;

  GetCounterValue(OsCounter_0, &LddCurrentCount);
  LddCount = LddCurrentCount;

  /* Convert milliseconds to ticks */
  LddTickDelay = LulMilliSecDelay * 1000 / OS_TICKS2US_OsCounter_0(1);

  while (LddElapsedCount < LddTickDelay)
  {
    GetElapsedValue(OsCounter_0, &LddCurrentCount, &LddElapsedCount);
    LddCurrentCount = LddCount;
  }
}

/* Used LED : LED2(Port PE5) */
TASK(OsTask_LED_Init)
{
  /* Turn off LED */
  REG_WRITE8(SIUL_GPDO(0x45U), STD_HIGH);

  /* Delay 500ms */
  DelayMS(500);

  /* Turn on LED */
  REG_WRITE8(SIUL_GPDO(0x45U), STD_LOW);

  GblLedInit = TRUE;

  TerminateTask();
}

TASK(OsTask_Test_1s)
{
  static sint8 LscToggle = 1;

  if (GblLedInit == TRUE)
  {
    /* Toggle LED */
    if (LscToggle == 1)
    {
      /* Turn on LED */
      REG_WRITE8(SIUL_GPDO(0x45U), STD_LOW);
    }
    else
    {
      /* Turn off LED */
      REG_WRITE8(SIUL_GPDO(0x45U), STD_HIGH);
    }
    LscToggle ^= 1;
  }
  TerminateTask();
}
