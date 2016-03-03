################################################################################
# Makefile-template with minimalistic program
################################################################################

#-------------------------------------------------------------------------------
# variables
#-------------------------------------------------------------------------------

# program-name
PROGRAM = timer

# compiler-variables
CC = arm-none-eabi-gcc
CFLAGS =  -mcpu=cortex-m4 -mthumb -Wall -ffunction-sections -g -O0 -c -DSTM32F407VG -DSTM32F4XX -DUSE_STDPERIPH_DRIVER -D__ASSEMBLY__
LDFLAGS = -mcpu=cortex-m4 -mthumb -g -nostartfiles -Wl,-Map=$(PROGRAM).map -O0 -Wl,--gc-sections -Wl,-T../../../utils/stm32_flash.ld -g

# files and filepaths - relative to projectfolder
# works only if folder is places in ~/Desktop/git/stm32
# need a copy of system_stm32f4xx.c in the project folder cause clock-settings are done in there
INCLUDEDIRS = -I../ -I../../../utils/STM32F4xx_StdPeriph/inc -I../../../utils/cmsis/Include -I../../../utils/cmsis_boot/
CFILES = ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_syscfg.c ../system_stm32f4xx.c ../main.c ../../../utils/cmsis_boot/startup/startup_stm32f4xx.c ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_rcc.c ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_gpio.c ../../../utils/STM32F4xx_StdPeriph/src/stm32f4xx_tim.c ../../../utils/STM32F4xx_StdPeriph/src/misc.c ../stm32f4xx_it.c
OBJFILES = ../obj/main.o ../obj/startup_stm32f4xx.o ../obj/stm32f4xx_syscfg.o ../obj/system_stm32f4xx.o ../obj/stm32f4xx_rcc.o ../obj/stm32f4xx_gpio.o ../obj/stm32f4xx_tim.o ../obj/misc.o ../obj/stm32f4xx_it.o

.PHONY: clean, all, main, flash

clean:
	del .\obj\*.o
	del .\bin\*.elf
	del .\bin\*.hex
	del .\bin\*.map

all: clean main flash

main:
	cd ./obj && \
	$(CC) $(CFLAGS) $(INCLUDEDIRS) $(CFILES)
	cd ./bin && \
	$(CC) $(LDFLAGS) -o $(PROGRAM).elf $(OBJFILES)
	cd ./bin && \
	arm-none-eabi-objcopy -O ihex $(PROGRAM).elf $(PROGRAM).hex

flash:
	"C:/CooCox/CoIDE/bin/coflash.exe" program STM32F407VG ./bin/$(PROGRAM).elf --adapter-name=ST-Link --port=SWD --adapter-clk=1000000 --erase=affected --reset=SYSRESETREQ --driver="C:/CooCox/CoIDE/flash/STM32F4xx_1024.elf"
