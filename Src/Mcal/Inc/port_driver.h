#include "std_types.h"
#include "MCU_hw.h"

#define GPIOA_BASE 				0x40004000
#define GPIO_DATA_OFFSET 	0x3FC
#define GPIO_DIR_OFFSET 	0x400
#define GPIO_DEN_OFFSET		0x51C
#define GPIO_AMSEL_OFFSET	0x528
#define GPIO_PUR_OFFSET		0x510
#define GPIO_PDR_OFFSET		0x514
#define GPIO_ODR_OFFSET		0x50C
#define GPIO_SLR_OFFSET		0x518
#define GPIO_DR8R_OFFSET	0x508
	


void Port_Init(const Port_ConfigType* ConfigPtr);