#include "trezor.h"
#include "usb.h"
#include "debug.h"
#include "messages.h"
#include "storage.h"
#include "util.h"

#include <assert.h>
#include <stdio.h>

static volatile char tiny = 0;

void usbInit(void)
{
}

static int _done = 0;

void usbPoll(void)
{
	static uint8_t *data;
	static uint8_t buf[64];

	size_t res = fread(buf, sizeof(buf), 1, stdin);
	if (res == 0) {
		_done = 1; // stop polling
		return;
	}

	// poll read buffer
	if (!tiny) {
		_dprintf("usbPoll", "read");
		msg_read(buf, sizeof(buf));
	} else {
		_dprintf("usbPoll", "read tiny");
		msg_read_tiny(buf, sizeof(buf));
	}

	// write pending data
	data = msg_out_data();
	if (data) {
	}

#if DEBUG_LINK
	// write pending debug data
	data = msg_debug_out_data();
	if (data) {
	}
#endif
}

void usbReconnect(void)
{
}

void usbTiny(char set)
{
	tiny = set;
}

void usbDelay(int cycles)
{
	(void)cycles;
}

int usbDone(void) {
	return _done;
}