#include "Systick_driver.h"

//initialise systick peripheral
void Systick_init(void){
	
	//enable systick interrupt
	SysTick_Ctrl |= Systick_Int;
  //set reload value for systick counter
  SysTick_Reload = Systick_Reload_Value;
	//start systick counter
	Systick_Start();
}

//start systick counter
void Systick_Start(void){
	//set the counter enable bit in the systick control register
	SysTick_Ctrl |= Systick_Counter_Enable;
}

//function to set callback function
void Systick_SetCallback(void (*callback) (void)){
	//assign the callback function to the global led_callback function pointer
	led_callback = callback;
}

//systick interrupt handler
void SysTick_Handler(void){
	//check if the led_callback function pointer is not null
    if(led_callback)
    {
        //call the function pointed to by the led_callback function pointer
        led_callback();
    }
}
