#include <string.h>
#include <stdint.h>

int memory_bootloader_hash(uint8_t *hash) {
	const int size = 32;
	memset(hash, 0, size);
	return size;
}