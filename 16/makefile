CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -mfloat-abi=soft -T stm32_ls.ld -Wl,-Map=final.map
#--specs=nano.specs
all:main.o led.o stm32_startup.o final.elf final.hex

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@
led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
#syscalls.o: syscalls.c
#	$(CC) $(CFLAGS) $^ -o $@
final.elf: main.o led.o stm32_startup.o #syscalls.o
	$(CC) $(LDFLAGS) $^ -o $@
final.hex:
	arm-none-eabi-objcopy -O ihex final.elf final.hex
clean:
	rm -rf *.o *.elf
load:
	openocd -f board/stm32f4discovery.cfg