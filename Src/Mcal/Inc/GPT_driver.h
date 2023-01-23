#include "std_types.h"
#include "MCU_hw.h"


// GPT callback functions
static void (*gpt_callbacks[4])(void);

void Gpt_Init(Gpt_ConfigType* config);

void Gpt_StartTimer(Gpt_ChannelType channelId, Gpt_ValueType value);

void Gpt_StopTimer(Gpt_ChannelType channelId);

void Gpt_SetCallback(Gpt_ChannelType channelId, void (*callback)(void));

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channelId);

// GPT interrupt handlers
void TIMER0A_Handler(void);

void TIMER1A_Handler(void);
