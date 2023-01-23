#include "dio_driver.h"


/* Read the level of a channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
  Dio_LevelType level;
  /* Determine the port number */
	Dio_PortType PortId = (ChannelId / 8);
  /* Determine the pin number */
  uint8_t pin = ChannelId % 8;
  /* Read the level of the pin */
  level = (GPIODATA(PortId) & (1 << pin)) ? High : Low;
  return level;
}

/* Write a level to a channel */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
  /* Determine the port number */
	Dio_PortType PortId = (ChannelId / 8);
  /* Determine the pin number */
  uint8_t pin = ChannelId % 8;
  /* Write the level to the pin */
  
	if (Level == High) {
    GPIODATA(PortId) |= (1 << pin);
  } else {
    GPIODATA(PortId) &= ~(1 << pin);
  }
}

/* Read the level of a port */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
  /* Read the level of the port */
  return GPIODATA(PortId);
}

/* Write a level to a port */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
  /* Write the level to the port */
  GPIODATA(PortId) = Level;
}

/* Flip the level of a channel */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {
  Dio_LevelType level;
  /* Determine the port number */
	Dio_PortType PortId = (ChannelId / 8);
  /* Determine the pin number */
  uint8_t pin = ChannelId % 8;
  /* Flip the level of the pin */
  GPIODATA(PortId) ^= (1 << pin);
  level = (GPIODATA(PortId) & (1 << pin)) ? High : Low;
  return level;
}