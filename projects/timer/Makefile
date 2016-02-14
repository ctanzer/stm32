CC = arm-none-eabi-gcc
CFLAGS =  -mcpu=cortex-m4 -mthumb -Wall -ffunction-sections -g -O0 -c -DSTM32F407VG -DSTM32F4XX -DUSE_STDPERIPH_DRIVER -D__ASSEMBLY__
LDFLAGS = -mcpu=cortex-m4 -mthumb -g -nostartfiles -Wl,-Map=test.map -O0 -Wl,--gc-sections -Wl,-T../utils/stm32_flash.ld -g

INCLUDEDIRS = -I../../../utils/STM32F4xx_StdPeriph/inc -I../../../utils/cmsis/Include -I../../../utils/cmsis_boot/
CFILES = ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_syscfg.c ../../../utils/cmsis_boot/system_stm32f4xx.c ../main.c ../../../utils/cmsis_boot/startup/startup_stm32f4xx.c ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_rcc.c ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_gpio.c 

.PHONY: clean, all, main, flash

clean:
	del .\obj\*.o
	del .\bin\*.elf
	del .\bin\*.hex
	del .\bin\*.bin
	del .\bin\*.map

all: clean main

main:
	cd ./obj && \
	$(CC) $(CFLAGS) $(INCLUDEDIRS) $(CFILES)

flash:
