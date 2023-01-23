#ifndef __STD_TYPES__
#define __STD_TYPES__
#include "stdint.h"
#include "stdbool.h"

//*****************************************************************************
//
// Interrupt assignments
//
//*****************************************************************************
#define INT_RESET 1		   // Reset_Handler
#define INT_NMI 2		   // NMI Handler
#define INT_HARDFAULT 3	   // Hard Fault Handler
#define INT_MEMMANAGE 4	   // MPU Fault Handler
#define INT_BUSFAULT 5	   // Bus Fault Handler
#define INT_USAGEFAULT 6   // Usage Fault Handler
#define INT_SVC 11		   // SVCall Handler
#define INT_DEBUGMON 12	   // Debug Monitor Handler
#define INT_PENDSV 14	   // PendSV_Handler
#define INT_SYSTICK 15	   // SysTick_Handler
#define INT_GPIOA 16	   // GPIO Port A
#define INT_GPIOB 17	   // GPIO Port B
#define INT_GPIOC 18	   // GPIO Port C
#define INT_GPIOD 19	   // GPIO Port D
#define INT_GPIOE 20	   // GPIO Port E
#define INT_UART0 21	   // UART0
#define INT_UART1 22	   // UART1
#define INT_SSI0 23		   // SSI0
#define INT_I2C0 24		   // I2C0
#define INT_PWM0_FAULT 25  // PWM0 Fault
#define INT_PWM0_0 26	   // PWM0 Generator 0
#define INT_PWM0_1 27	   // PWM0 Generator 1
#define INT_PWM0_2 28	   // PWM0 Generator 2
#define INT_QEI0 29		   // QEI0
#define INT_ADC0SS0 30	   // ADC0 Sequence 0
#define INT_ADC0SS1 31	   // ADC0 Sequence 1
#define INT_ADC0SS2 32	   // ADC0 Sequence 2
#define INT_ADC0SS3 33	   // ADC0 Sequence 3
#define INT_WATCHDOG 34	   // Watchdog Timers 0 and 1
#define INT_TIMER0A 35	   // 16/32-Bit Timer 0A
#define INT_TIMER0B 36	   // 16/32-Bit Timer 0B
#define INT_TIMER1A 37	   // 16/32-Bit Timer 1A
#define INT_TIMER1B 38	   // 16/32-Bit Timer 1B
#define INT_TIMER2A 39	   // 16/32-Bit Timer 2A
#define INT_TIMER2B 40	   // 16/32-Bit Timer 2B
#define INT_COMP0 41	   // Analog Comparator 0
#define INT_COMP1 42	   // Analog Comparator 1
#define INT_SYSCTL 44	   // System Control
#define INT_FLASH 45	   // Flash Memory Control and EEPROM
#define INT_GPIOF 46	   // GPIO Port F
#define INT_UART2 49	   // UART2
#define INT_SSI1 50		   // SSI1
#define INT_TIMER3A 51	   // Timer 3A
#define INT_TIMER3B 52	   // Timer 3B
#define INT_I2C1 53		   // I2C1
#define INT_QEI1 54		   // QEI1
#define INT_CAN0 55		   // CAN0
#define INT_CAN1 56		   // CAN1
#define INT_HIBERNATE 59   // Hibernation Module
#define INT_USB0 60		   // USB
#define INT_PWM0_3 61	   // PWM Generator 3
#define INT_UDMA 62		   // uDMA Software
#define INT_UDMAERR 63	   // uDMA Error
#define INT_ADC1SS0 64	   // ADC1 Sequence 0
#define INT_ADC1SS1 65	   // ADC1 Sequence 1
#define INT_ADC1SS2 66	   // ADC1 Sequence 2
#define INT_ADC1SS3 67	   // ADC1 Sequence 3
#define INT_SSI2 73		   // SSI2
#define INT_SSI3 74		   // SSI3
#define INT_UART3 75	   // UART3
#define INT_UART4 76	   // UART4
#define INT_UART5 77	   // UART5
#define INT_UART6 78	   // UART6
#define INT_UART7 79	   // UART7
#define INT_I2C2 84		   // I2C2
#define INT_I2C3 85		   // I2C3
#define INT_TIMER4A 86	   // 16/32-Bit Timer 4A
#define INT_TIMER4B 87	   // 16/32-Bit Timer 4B
#define INT_TIMER5A 108	   // 16/32-Bit Timer 5A
#define INT_TIMER5B 109	   // 16/32-Bit Timer 5B
#define INT_WTIMER0A 110   // 32/64-Bit Timer 0A
#define INT_WTIMER0B 111   // 32/64-Bit Timer 0B
#define INT_WTIMER1A 112   // 32/64-Bit Timer 1A
#define INT_WTIMER1B 113   // 32/64-Bit Timer 1B
#define INT_WTIMER2A 114   // 32/64-Bit Timer 2A
#define INT_WTIMER2B 115   // 32/64-Bit Timer 2B
#define INT_WTIMER3A 116   // 32/64-Bit Timer 3A
#define INT_WTIMER3B 117   // 32/64-Bit Timer 3B
#define INT_WTIMER4A 118   // 32/64-Bit Timer 4A
#define INT_WTIMER4B 119   // 32/64-Bit Timer 4B
#define INT_WTIMER5A 120   // 32/64-Bit Timer 5A
#define INT_WTIMER5B 121   // 32/64-Bit Timer 5B
#define INT_SYSEXC 122	   // System Exception (imprecise)
#define INT_PWM1_0 150	   // PWM1 Generator 0
#define INT_PWM1_1 151	   // PWM1 Generator 1
#define INT_PWM1_2 152	   // PWM1 Generator 2
#define INT_PWM1_3 153	   // PWM1 Generator 3
#define INT_PWM1_FAULT 154 // PWM1 Fault

/* Enumeration for channel type */
typedef enum
{
	PA0 = 0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	PE0,
	PE1,
	PE2,
	PE3,
	PE4,
	PE5,
	PE6,
	PE7,
	PF0,
	PF1,
	PF2,
	PF3,
	PF4,
	PF5,
	PF6,
	PF7
} Dio_ChannelType;

/* Enumeration for port type */
typedef enum
{
	PortA = 0,
	PortB,
	PortC,
	PortD,
	PortE,
	PortF
} Dio_PortType;

/* Enumeration for level type */
typedef enum
{
	Low = 0,
	High
} Dio_LevelType;

/* Enumeration for port level type */
typedef uint8_t Dio_PortLevelType;

/* Enumeration for port pin type */
typedef Dio_PortType Port_PinType;

/* Enumeration for port pin direction */
typedef enum
{
	Input,
	Output
} Port_PinDirectionType;

/* Enumeration for port pin mode */
typedef enum
{
	Digital,
	Analog
} Port_PinModeType;

/* Enumeration for port pin internal attachment */
typedef enum
{
	PullUp,
	PullDown,
	OpenDrain
} Port_PinInternalAttachType;

/* Enumeration for port pin output current */
typedef enum
{
	Normal,
	Double
} Port_PinOutputCurrentType;

/* Structure for port configuration */
typedef struct
{
	Port_PinType port;
	uint8_t pin;
	Port_PinDirectionType direction;
	Port_PinModeType mode;
	Port_PinInternalAttachType internalAttach;
	Port_PinOutputCurrentType outputCurrent;
} Port_ConfigType;

/* GPT Channel Type */
typedef enum
{
	GPT_CH0 = 0,
	GPT_CH1,
	GPT_CH2,
	GPT_CH3,
	GPT_CH4,
	GPT_CH5,
	GPT_CH6,
	GPT_CH7,
	GPT_CH8,
	GPT_CH9,
	GPT_CH10,
	GPT_CH11
} Gpt_ChannelType;

/* Type for reading and setting timer values (in number of ticks) */
typedef uint32_t Gpt_ValueType;

/* GPT Mode Type */
typedef enum
{
	GPT_MODE_ONESHOT = 0,
	GPT_MODE_CONTINUOUS = 1
} Gpt_ModeType;

/* GPT Predefined Timer Type */
typedef enum
{
	GPT_PREDEF_TIMER_16BIT,
	GPT_PREDEF_TIMER_24BIT,
	GPT_PREDEF_TIMER_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
} Gpt_PredefTimerType;

/* GPT Configuration */
typedef struct
{
	Gpt_ChannelType channelId;
	Gpt_ValueType tickFrequency;
	Gpt_ValueType tickValueMax;
	Gpt_ModeType channelMode;
	Gpt_PredefTimerType timerType;
	void (*notification)(void);
} Gpt_ConfigType;

typedef enum
{
	INTCTRL_INTERRUPT_TYPE_RESET = INT_RESET,
	INTCTRL_INTERRUPT_TYPE_NMI = INT_NMI,
	INTCTRL_INTERRUPT_TYPE_HARDFAULT = INT_HARDFAULT,
	INTCTRL_INTERRUPT_TYPE_MEMMANAGE = INT_MEMMANAGE,
	INTCTRL_INTERRUPT_TYPE_BUSFAULT = INT_BUSFAULT,
	INTCTRL_INTERRUPT_TYPE_USAGEFAULT = INT_USAGEFAULT,
	INTCTRL_INTERRUPT_TYPE_SVC = INT_SVC,
	INTCTRL_INTERRUPT_TYPE_DEBUGMON = INT_DEBUGMON,
	INTCTRL_INTERRUPT_TYPE_PENDSV = INT_PENDSV,
	INTCTRL_INTERRUPT_TYPE_SYSTICK = INT_SYSTICK,
	INTCTRL_INTERRUPT_TYPE_GPIOA = INT_GPIOA,
	INTCTRL_INTERRUPT_TYPE_GPIOB = INT_GPIOB,
	INTCTRL_INTERRUPT_TYPE_GPIOC = INT_GPIOC,
	INTCTRL_INTERRUPT_TYPE_GPIOD = INT_GPIOD,
	INTCTRL_INTERRUPT_TYPE_GPIOE = INT_GPIOE,
	INTCTRL_INTERRUPT_TYPE_UART0 = INT_UART0,
	INTCTRL_INTERRUPT_TYPE_UART1 = INT_UART1,
	INTCTRL_INTERRUPT_TYPE_SSI0 = INT_SSI0,
	INTCTRL_INTERRUPT_TYPE_I2C0 = INT_I2C0,
	INTCTRL_INTERRUPT_TYPE_PWM0_FAULT = INT_PWM0_FAULT,
	INTCTRL_INTERRUPT_TYPE_PWM0_0 = INT_PWM0_0,
	INTCTRL_INTERRUPT_TYPE_PWM0_1 = INT_PWM0_1,
	INTCTRL_INTERRUPT_TYPE_PWM0_2 = INT_PWM0_2,
	INTCTRL_INTERRUPT_TYPE_QEI0 = INT_QEI0,
	INTCTRL_INTERRUPT_TYPE_ADC0SS0 = INT_ADC0SS0,
	INTCTRL_INTERRUPT_TYPE_ADC0SS1 = INT_ADC0SS1,
	INTCTRL_INTERRUPT_TYPE_ADC0SS2 = INT_ADC0SS2,
	INTCTRL_INTERRUPT_TYPE_ADC0SS3 = INT_ADC0SS3,
	INTCTRL_INTERRUPT_TYPE_WATCHDOG = INT_WATCHDOG,
	INTCTRL_INTERRUPT_TYPE_TIMER0A = INT_TIMER0A,
	INTCTRL_INTERRUPT_TYPE_TIMER0B = INT_TIMER0B,
	INTCTRL_INTERRUPT_TYPE_TIMER1A = INT_TIMER1A,
	INTCTRL_INTERRUPT_TYPE_TIMER1B = INT_TIMER1B,
	INTCTRL_INTERRUPT_TYPE_TIMER2A = INT_TIMER2A,
	INTCTRL_INTERRUPT_TYPE_TIMER2B = INT_TIMER2B,
	INTCTRL_INTERRUPT_TYPE_COMP0 = INT_COMP0,
	INTCTRL_INTERRUPT_TYPE_COMP1 = INT_COMP1,
	INTCTRL_INTERRUPT_TYPE_SYSCTL = INT_SYSCTL,
	INTCTRL_INTERRUPT_TYPE_FLASH = INT_FLASH,
	INTCTRL_INTERRUPT_TYPE_GPIOF = INT_GPIOF,
	INTCTRL_INTERRUPT_TYPE_UART2 = INT_UART2,
	INTCTRL_INTERRUPT_TYPE_SSI1 = INT_SSI1,
	INTCTRL_INTERRUPT_TYPE_TIMER3A = INT_TIMER3A,
	INTCTRL_INTERRUPT_TYPE_TIMER3B = INT_TIMER3B,
	INTCTRL_INTERRUPT_TYPE_I2C1 = INT_I2C1,
	INTCTRL_INTERRUPT_TYPE_QEI1 = INT_QEI1,
	INTCTRL_INTERRUPT_TYPE_CAN0 = INT_CAN0,
	INTCTRL_INTERRUPT_TYPE_CAN1 = INT_CAN1,
	INTCTRL_INTERRUPT_TYPE_HIBERNATE = INT_HIBERNATE,
	INTCTRL_INTERRUPT_TYPE_USB0 = INT_USB0,
	INTCTRL_INTERRUPT_TYPE_PWM0_3 = INT_PWM0_3,
	INTCTRL_INTERRUPT_TYPE_UDMA = INT_UDMA,
	INTCTRL_INTERRUPT_TYPE_UDMAERR = INT_UDMAERR,
	INTCTRL_INTERRUPT_TYPE_ADC1SS0 = INT_ADC1SS0,
	INTCTRL_INTERRUPT_TYPE_ADC1SS1 = INT_ADC1SS1,
	INTCTRL_INTERRUPT_TYPE_ADC1SS2 = INT_ADC1SS2,
	INTCTRL_INTERRUPT_TYPE_ADC1SS3 = INT_ADC1SS3,
	INTCTRL_INTERRUPT_TYPE_SSI2 = INT_SSI2,
	INTCTRL_INTERRUPT_TYPE_SSI3 = INT_SSI3,
	INTCTRL_INTERRUPT_TYPE_UART3 = INT_UART3,
	INTCTRL_INTERRUPT_TYPE_UART4 = INT_UART4,
	INTCTRL_INTERRUPT_TYPE_UART5 = INT_UART5,
	INTCTRL_INTERRUPT_TYPE_UART6 = INT_UART6,
	INTCTRL_INTERRUPT_TYPE_UART7 = INT_UART7,
	INTCTRL_INTERRUPT_TYPE_I2C2 = INT_I2C2,
	INTCTRL_INTERRUPT_TYPE_I2C3 = INT_I2C3,
	INTCTRL_INTERRUPT_TYPE_TIMER4A = INT_TIMER4A,
	INTCTRL_INTERRUPT_TYPE_TIMER4B = INT_TIMER4B,
	INTCTRL_INTERRUPT_TYPE_TIMER5A = INT_TIMER5A,
	INTCTRL_INTERRUPT_TYPE_TIMER5B = INT_TIMER5B,
	INTCTRL_INTERRUPT_TYPE_WTIMER0A = INT_WTIMER0A,
	INTCTRL_INTERRUPT_TYPE_WTIMER0B = INT_WTIMER0B,
	INTCTRL_INTERRUPT_TYPE_WTIMER1A = INT_WTIMER1A,
	INTCTRL_INTERRUPT_TYPE_WTIMER1B = INT_WTIMER1B,
	INTCTRL_INTERRUPT_TYPE_WTIMER2A = INT_WTIMER2A,
	INTCTRL_INTERRUPT_TYPE_WTIMER2B = INT_WTIMER2B,
	INTCTRL_INTERRUPT_TYPE_WTIMER3A = INT_WTIMER3A,
	INTCTRL_INTERRUPT_TYPE_WTIMER3B = INT_WTIMER3B,
	INTCTRL_INTERRUPT_TYPE_WTIMER4A = INT_WTIMER4A,
	INTCTRL_INTERRUPT_TYPE_WTIMER4B = INT_WTIMER4B,
	INTCTRL_INTERRUPT_TYPE_WTIMER5A = INT_WTIMER5A,
	INTCTRL_INTERRUPT_TYPE_WTIMER5B = INT_WTIMER5B,
	INTCTRL_INTERRUPT_TYPE_SYSEXC = INT_SYSEXC,
	INTCTRL_INTERRUPT_TYPE_PWM1_0 = INT_PWM1_0,
	INTCTRL_INTERRUPT_TYPE_PWM1_1 = INT_PWM1_1,
	INTCTRL_INTERRUPT_TYPE_PWM1_2 = INT_PWM1_2,
	INTCTRL_INTERRUPT_TYPE_PWM1_3 = INT_PWM1_3,
	INTCTRL_INTERRUPT_TYPE_PWM1_FAULT = INT_PWM1_FAULT
} IntCtrl_InterruptType;

typedef enum
{
	bxxx = 0x4,
	bxxy = 0x5,
	bxyy = 0x6,
	byyy = 0x7
} Group_SubgroupType;

typedef struct
{
	uint8_t Group_Prio;
	uint8_t Sub_Group_Prio;
	IntCtrl_InterruptType Interrupt_Type;
} Int_Pri_Cfg;

/* INT Configuration */
typedef struct
{
	Group_SubgroupType groupspriority_config;
	Int_Pri_Cfg Int_Cfg;

} Int_ConfigType;

#endif