#include "LED.h"


void LED_ON(Dio_ChannelType Channel){
		Dio_WriteChannel(Channel, High);
}

void LED_OFF(Dio_ChannelType Channel){
		Dio_WriteChannel(Channel, Low);
}
