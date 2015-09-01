#ifndef __FAKE_SPI_H
#define __FAKE_SPI_H

#include "common.h"

enum {
	SPI0,
	SPI1,
	SPI2,
};

void spi_send(uint32_t spi, uint16_t data);

#endif