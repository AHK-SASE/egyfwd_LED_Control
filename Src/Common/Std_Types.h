#include "port_driver.h"
#include "LED.h"
#include "GPT_driver.h"
#include "IntCtrl_driver.h"
#include "Systick_driver.h"


#define LED_LOW 5
#define LED_HIGH 10
#define TOTAL_TIME LED_HIGH+LED_LOW



void callback_func(){
	static int count=0;
	count++;
	if(count > LED_LOW){
			LED_ON(PF1);
	}
	if(count == TOTAL_TIME){
			LED_OFF(PF1);
			count = 0;
	}
}

  Port_ConfigType port_config = {
    .port = PortF,
    .pin = 1,
    .direction = Output,
    .mode = Digital,
    .internalAttach = PullUp,
    .outputCurrent = Normal
  };
		
	
	Gpt_ConfigType gpt_config = {
    .channelId = GPT_CH0,
    .tickValueMax = 48000000,
    .channelMode = GPT_MODE_CONTINUOUS,
		.notification = callback_func
  };
	
	 Int_ConfigType g_user_data = {
    .groupspriority_config = bxxx,
    .Int_Cfg.Group_Prio = 1,
    .Int_Cfg.Sub_Group_Prio = 0,
    .Int_Cfg.Interrupt_Type = INTCTRL_INTERRUPT_TYPE_TIMER0A - 16,
  };