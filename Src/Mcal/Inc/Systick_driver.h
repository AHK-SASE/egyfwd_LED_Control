#include "std_types.h"
#include "MCU_hw.h"

#define SysTick_Ctrl					*((volatile uint32_t*)(NVIC_BASE + 0x010))
#define SysTick_Reload	 			*((volatile uint32_t*)(NVIC_BASE + 0x014))
#define SysTick_Current				*((volatile uint32_t*)(NVIC_BASE + 0x018))

#define Systick_Int								6UL //set clock source and enable systick interrupt
#define Systick_Counter_Enable 		1UL // start systick counter
#define Systick_Reload_Value 			0x00FFFFFF


static	void (*led_callback)(void);

void Systick_init(void);
void Systick_Start(void);
void Systick_SetCallback(void (*callback) (void));

// Systick interrupt handlers
void SysTick_Handler(void);

