#include "GPT_driver.h"

void Gpt_Init(Gpt_ConfigType* config) {
    // Enable GPT clock
    SYSCTL_RCGCTIMER_R |= (1 << config->channelId);
	
		GPT_CH_CTL(config->channelId) = 0x00000000;
    // Set GPT configurations
    // ...
		GPT_CH_CFG(config->channelId) = 0x00000000;
		GPT_CH_TAMR(config->channelId) |= (1 << config->channelMode); // set the mode type
		GPT_CH_TAMR(config->channelId) |= (1 << GPT_DIR_BIT);
		GPT_CH_TAILR(config->channelId) = config->tickValueMax;
		GPT_CH_ICR(config->channelId) |= (1 << config->channelId);
		GPT_CH_IMR(config->channelId) |= (1 << 0);
	
		Gpt_SetCallback(config->channelId, config->notification);
}

void Gpt_StartTimer(Gpt_ChannelType channelId, Gpt_ValueType value) {
    // Set timer reload value
    GPT_CH_TAILR(channelId) = value;

    // Enable timer
    GPT_CH_CTL(channelId) |= (1 << 0);
}

void Gpt_StopTimer(Gpt_ChannelType channelId) {
    // Disable timer
    GPT_CH_CTL(channelId) &= ~(1 << 0);
}

void Gpt_SetCallback(Gpt_ChannelType channelId, void (*callback)(void)) {
    // Set callback function
    gpt_callbacks[channelId] = callback;

    // Enable timer interrupt
    GPT_CH_IMR(channelId) |= (1 << 0);
}

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channelId) {
    // Get current timer value
		volatile uint32_t currenttime;
		currenttime = (volatile uint32_t)GPT_CH_TAR(channelId);
		volatile uint32_t maxtime;
		maxtime = (volatile uint32_t)GPT_CH_TAILR(channelId);
    return maxtime - currenttime;
}


// GPT interrupt handlers
void TIMER0A_Handler(void) {
	// Check if interrupt is from channel 0
	if (GPT_CH_MIS(0) & (1 << 0)) {
		// Clear interrupt
		GPT_CH_ICR(0) = (1 << 0);
		if (gpt_callbacks[0]) {
        gpt_callbacks[0]();
    }
	}
}

void TIMER1A_Handler(void) {
	// Check if interrupt is from channel 1
	if (GPT_CH_MIS(1) & (1 << 0)) {
	// Clear interrupt
	GPT_CH_ICR(1) = (1 << 0);
	// Call callback function
  if (gpt_callbacks[1]) {
        gpt_callbacks[1]();
    }
	}
}