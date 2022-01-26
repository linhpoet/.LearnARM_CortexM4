CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0

all:main.o led.o stm32_startup.o stm32_startup.o_h

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
stm32_startup.o_h:
	arm-none-eabi-objdump -h stm32_startup.o
clean:
	rm -rf *.o *.elf
	