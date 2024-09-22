CC = arm-none-eabi-gcc
MACH = cortex-m4
INC_DIR = ../Include
OUTPUT_DIR = ../Output
AR = ar
ARFLAGS = rcs
LIBRARY_NAME = libmylib.a
OUTPUT_SRC_DIR = $(OUTPUT_DIR)/Src
OUTPUT_STARTUP_DIR = $(OUTPUT_DIR)/Startup
SRC_DIR = ../Src
APPL_SRC = $(SRC_DIR)/Application
SYSCALL_SRC = $(SRC_DIR)/SysLib
STARTUP_SRC = ../Startup
FEATURE_FLAG =

CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
#LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs --specs=nosys.specs -T linker.ld -L./$(OUTPUT_DIR) -lmylib -Wl,-Map=$(OUTPUT_DIR)/final.map
LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs --specs=nosys.specs -T linker.ld -Wl,-Map=$(OUTPUT_DIR)/final.map

#OBJS = $(OUTPUT_SRC_DIR)/main.o $(OUTPUT_SRC_DIR)/led.o $(OUTPUT_STARTUP_DIR)/stm32_startup.o $(OUTPUT_SRC_DIR)/syscalls.o
OBJS = $(OUTPUT_SRC_DIR)/main.o $(OUTPUT_SRC_DIR)/adc.o $(OUTPUT_SRC_DIR)/gpio.o $(OUTPUT_SRC_DIR)/timer.o $(OUTPUT_STARTUP_DIR)/startup.o $(OUTPUT_SRC_DIR)/syscalls.o

#not phony as it does not require explicit mention
#this is default goal as it appeared as first target in makefile
#if no input is given from make, this target is excuted by default.
all: final.elf

#this enables the user to use certain flags in 
#src file to perform conditional compilation
ifdef ENABLE
FEATURE_FLAG = -DENABLE_FEATURE
endif

# Add FEATURE_FLAG to the CFLAGS
CFLAGS += $(FEATURE_FLAG)

$(OUTPUT_DIR) $(OUTPUT_STARTUP_DIR) $(OUTPUT_SRC_DIR):
	@mkdir -p $@

#main.o:main.c	
$(OUTPUT_SRC_DIR)/%.o: $(APPL_SRC)/%.c | $(OUTPUT_SRC_DIR)
	$(CC) $(CFLAGS) -o $@ $<
#	$(CC) $(CFLAGS) -o target  prerequisite
#   $(CC) $(CFLAGS) -o main.o main.c
#   arm-none-eabi-objdump.exe
#	arm-none-eabi-gcc -S/-c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 main.c -o main.s/main.o

#----------this is example of explicit rule.------------
$(OUTPUT_STARTUP_DIR)/startup.o: $(STARTUP_SRC)/startup.c | $(OUTPUT_STARTUP_DIR)
	$(CC) $(CFLAGS) -o $@ $<
#--------------------------------------------------------

$(OUTPUT_SRC_DIR)/syscalls.o: $(SYSCALL_SRC)/syscalls.c | $(OUTPUT_SRC_DIR)	
	$(CC) $(CFLAGS) -o $@ $<

final.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $(OUTPUT_DIR)/$@ $^

$(LIBRARY_NAME): $(OBJS)
	$(AR) $(ARFLAGS) -v $(OUTPUT_DIR)/$@ $^

.PHONY: library clean load
library: $(LIBRARY_NAME) $(OBJS)

clean:
	rm -rf $(OUTPUT_SRC_DIR)/*.o $(OUTPUT_STARTUP_DIR)/*.o $(OUTPUT_DIR)/*.elf $(OUTPUT_DIR)/*.map $(OUTPUT_DIR)/*.a
	
load:
	openocd -f board/stm32f4discovery.cfg