#ifndef __FAKE_FLASH_H
#define __FAKE_FLASH_H

extern void *FLASH_STORAGE_START;

enum {
	FLASH_SR = 1,
	FLASH_SR_PGAERR,
	FLASH_SR_PGPERR,
	FLASH_SR_PGSERR,
	FLASH_SR_WRPERR,
	FLASH_CR_PROGRAM_X32
};

void flash_clear_status_flags(void);
void flash_lock(void);
void flash_unlock(void);
void flash_erase_sector(uint8_t sector, uint32_t program_size);
void flash_program_word(uint32_t address, uint32_t data);

#endif