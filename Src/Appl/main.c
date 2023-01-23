#include "User_Config.h"

/* Example usage of the Port_Init function */
int main(void) {

	
  Port_Init(&port_config);
	Gpt_Init(&gpt_config);
	IntCrtl_Init(&g_user_data);
	Gpt_StartTimer(gpt_config.channelId, gpt_config.tickValueMax); 
  
	while(1);
  return 0;
}
