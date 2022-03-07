#include "BswM.h"

void Dem_ReadNvData()
{
  BswM_RequestMode(54, 3);
}

void Dem_WriteNvData()
{
  BswM_RequestMode(54, 4);
}