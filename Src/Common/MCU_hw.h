#ifndef __MCU_HW__
#define __MCU_HW__


#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCGCTIMER_R      (*((volatile unsigned long *)0x400FE604))
	
#define GPIO_OFFSET(x) (x<4?((0x40004000)+ ((x)* 0x1000)): ((0x40024000)+((x-4)*0x1000))) 

#define GPIODATA(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x3FC)) 
#define GPIODIR(x)		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0400)) 
#define GPIOIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0404)) 
#define GPIOIBE(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0408)) 
#define GPIOIEV(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x040C)) 
#define GPIOIM(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0410)) 
#define GPIORIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0414))
#define GPIOMIS(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0418)) 
#define GPIOICR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x041C)) 
#define GPIOAFSEL(x)	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0420)) 
#define GPIODR2R(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0500)) 
#define GPIODR4R(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0504)) 
#define GPIODR8R(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0508)) 
#define GPIOODR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x050C)) 
#define GPIOPUR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0510)) 
#define GPIOPDR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0514)) 
#define GPIOSLR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0518))
#define GPIODEN(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x051C)) 
#define GPIOLOCK(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0520))
#define GPIOCR(x) 		*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0524)) 
#define GPIOAMSEL(x) 	*((volatile uint32_t*)(GPIO_OFFSET(x)+ 0x0528))

// GPT module registers base address
#define GPT_BASE 0x40030000
#define GPT_WBASE 0x40036000
// GPT channel registers offset
#define GPT_CH_OFFSET 0x1000

// GPT channel register addresses
#define GPT_CH_CFG(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x00))
#define GPT_CH_TAMR(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x04))
#define GPT_CH_CTL(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x0C))
#define GPT_CH_IMR(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x18))
#define GPT_CH_RIS(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x1C))
#define GPT_CH_MIS(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x20))
#define GPT_CH_ICR(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x24))
#define GPT_CH_TAILR(channelId) *((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x28))
#define GPT_CH_TAR(channelId) 	*((volatile uint32_t*)(GPT_BASE + channelId * GPT_CH_OFFSET + 0x48))
	
#define	GPT_CH_TAPR							*((volatile uint32_t*)(GPT_WBASE + GPT_CH_OFFSET + 0x38))

#define GPT_DIR_BIT							4

#endif