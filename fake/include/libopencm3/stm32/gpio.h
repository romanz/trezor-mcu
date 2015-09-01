#ifndef __FAKE_GPIO_H
#define __FAKE_GPIO_H

#include "common.h"

enum {
	GPIO0,
	GPIO1,
	GPIO2,
	GPIO3,
	GPIO4,
	GPIO5,
	GPIOA,
	GPIOB,
	GPIOC,
	BTN_PORT
};

uint16_t gpio_port_read(uint32_t gpioport);
void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);

#endif