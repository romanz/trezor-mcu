#include "trezor.h"
#include "usb.h"
#include "debug.h"
#include "messages.h"
#include "storage.h"
#include "util.h"

static volatile char tiny = 0;

static void hid_rx_callback(void)
{
	static uint8_t buf[64] __attribute__ ((aligned(4)));
	debugLog(0, "", "hid_rx_callback");
	if (!tiny) {
		msg_read(buf, 64);
	} else {
		msg_read_tiny(buf, 64);
	}
}

void usbInit(void)
{
}

void usbPoll(void)
{
	static uint8_t *data;
	// poll read buffer
	hid_rx_callback();
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
