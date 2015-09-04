#include <stdint.h>
#include "memory.h"

uint32_t FAKE_FLASH_DATA[1 << 20];

void flash_clear_status_flags(void)
{
}

void flash_lock(void)
{
}

void flash_unlock(void)
{
}

void flash_erase_sector(uint8_t sector, uint32_t program_size)
{
	(void)sector;
	(void)program_size;
}

void flash_program_word(uint32_t address, uint32_t data) {
	address = address - (uint64_t)(&FAKE_FLASH_DATA);
	FAKE_FLASH_DATA[address] = data;
}
