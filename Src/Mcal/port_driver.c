#include "port_driver.h"


/* Initialize a port with the given configuration */
void Port_Init(const Port_ConfigType* ConfigPtr) {
	if(!ConfigPtr){
		// ConfigPtr is equal to NULL
		return;
	}
	
  /* Enable the clock for the port */
  SYSCTL_RCGCGPIO_R |= (1 << ConfigPtr->port);
	if (ConfigPtr->port == PortF){
		GPIOLOCK(ConfigPtr->port) = 0x4C4F434B;
		GPIOCR(ConfigPtr->port) = 0xFE;
	}
  /* Set the direction of the pin */
  if (ConfigPtr->direction == Input) {
    GPIODIR(ConfigPtr->port) &= ~(1 << ConfigPtr->pin);
  } else {
		GPIODIR(ConfigPtr->port)|= (1 << ConfigPtr->pin);
  }

  /* Set the mode of the pin */
  if (ConfigPtr->mode == Digital) {
			GPIOAFSEL(ConfigPtr->port) &= ~(1 << ConfigPtr->pin);
			GPIODEN(ConfigPtr->port) |= (1 << ConfigPtr->pin);
			GPIOAMSEL(ConfigPtr->port) &= ~(1 << ConfigPtr->pin);
  } else {
			GPIODEN(ConfigPtr->port) &= ~(1 << ConfigPtr->pin);
			GPIOAMSEL(ConfigPtr->port) |= (1 << ConfigPtr->pin);
  }

  /* Set the internal attachment of the pin */
  switch (ConfigPtr->internalAttach) {
    case PullUp:
      GPIOPUR(ConfigPtr->port) |= (1 << ConfigPtr->pin);
      break;
    case PullDown:
      GPIOPDR(ConfigPtr->port) |= (1 << ConfigPtr->pin);
      break;
    case OpenDrain:
      GPIOODR(ConfigPtr->port) |= (1 << ConfigPtr->pin);
      break;
		default:
      /* Invalid internal attachment, do nothing */
      break;
  }

  /* Set the output current of the pin */
  if (ConfigPtr->outputCurrent == Double) {
    GPIODR8R(ConfigPtr->port) |= (1 << ConfigPtr->pin);
  }
}
