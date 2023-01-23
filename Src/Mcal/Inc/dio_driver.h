#include "std_types.h"
#include "MCU_hw.h"

#define GPIOA_BASE 0x40004000
#define GPIO_DATA_OFFSET	0x3FC




Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
