CC = arm-none-eabi-gcc
MACH = cortex-m4
INC_DIR = ../Include
OUTPUT_DIR = ../Output
OUTPUT_SRC_DIR = $(OUTPUT_DIR)/Src
OUTPUT_STARTUP_DIR = $(OUTPUT_DIR)/Startup
SRC_DIR = ../Src
APPL_SRC = $(SRC_DIR)/Application
SYSCALL_SRC = $(SRC_DIR)/SysLib
STARTUP_SRC = ../Startup

CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs --specs=nosys.specs -T linker.ld -Wl,-Map=$(OUTPUT_DIR)/final.map

#OBJS = $(OUTPUT_SRC_DIR)/main.o $(OUTPUT_SRC_DIR)/led.o $(OUTPUT_STARTUP_DIR)/stm32_startup.o $(OUTPUT_SRC_DIR)/syscalls.o
OBJS = $(OUTPUT_SRC_DIR)/main.o $(OUTPUT_SRC_DIR)/adc.o $(OUTPUT_SRC_DIR)/gpio.o $(OUTPUT_SRC_DIR)/timer.o $(OUTPUT_STARTUP_DIR)/startup.o $(OUTPUT_SRC_DIR)/syscalls.o

all: final.elf

#main.o:main.c
$(OUTPUT_SRC_DIR)/%.o: $(APPL_SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<
#   $(CC) $(CFLAGS) -o main.o main.c
#   arm-none-eabi-objdump.exe
#	arm-none-eabi-gcc -S/-c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 main.c -o main.s/main.o

$(OUTPUT_STARTUP_DIR)/startup.o: $(STARTUP_SRC)/startup.c
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPUT_SRC_DIR)/syscalls.o: $(SYSCALL_SRC)/syscalls.c
	$(CC) $(CFLAGS) -o $@ $<

final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $(OUTPUT_DIR)/$@ $^

clean:
	rm -rf $(OUTPUT_SRC_DIR)/*.o $(OUTPUT_STARTUP_DIR)/*.o $(OUTPUT_DIR)/*.elf $(OUTPUT_DIR)/*.map
	
load:
	openocd -f board/stm32f4discovery.cfg