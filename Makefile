OBJS += fake_setup.o
OBJS += fake_flash.o
OBJS += fake_memory.o
OBJS += fake/fake_gpio.o
OBJS += fake/fake_spi.o
OBJS += buttons.o
OBJS += layout.o
OBJS += oled.o
OBJS += serialno.o
OBJS += util.o
OBJS += gen/bitmaps.o
OBJS += gen/fonts.o
OBJS += dprint.o

libtrezor.a: $(OBJS)
	ar rcs libtrezor.a $(OBJS)

include Makefile.include
