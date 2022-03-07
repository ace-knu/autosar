#include "Fbl_Stub.h"

void bcore_SetStartupCommand(unsigned int ul_Value)
{
	STARTUP_COMMAND = ul_Value; /*lint !e923 Cast from int to pointer */
}

unsigned int bcore_GetStartupCommand(void)
{
	return STARTUP_COMMAND; /*lint !e923 Cast from int to pointer */
}
