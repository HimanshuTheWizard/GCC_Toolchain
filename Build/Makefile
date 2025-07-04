# Variables definition
CC = arm-none-eabi-gcc
MACH = cortex-m4
INC_DIR = ../Include
OUTPUT_DIR = ../Output
OUTPUT_SRC_DIR = $(OUTPUT_DIR)/Src
OUTPUT_STARTUP_DIR = $(OUTPUT_DIR)/Startup
SRC_DIR = ../Src
TARGET = final.elf
AR = arm-none-eabi-ar
ARFLAGS = rcs
LIBRARY_NAME = libmylib.a
APPL_SRC = $(SRC_DIR)/Application
SYSCALL_SRC = $(SRC_DIR)/SysLib
STARTUP_SRC = ../Startup

# Optional feature flag (e.g. ENABLE=1 in command line)
FEATURE_FLAG =
ifdef ENABLE
FEATURE_FLAG = -DENABLE_FEATURE
endif

CFLAGS = -mcpu=$(MACH) -mthumb -Wall -O2 -std=gnu11 -I$(INC_DIR) $(FEATURE_FLAG)
LDFLAGS = -mcpu=$(MACH) -mthumb --specs=nano.specs --specs=nosys.specs \
          -T linker.ld -Wl,-Map=$(OUTPUT_DIR)/final.map

# Collect source files
APP_SRCS = $(wildcard $(APPL_SRC)/*.c)
SYS_SRCS = $(wildcard $(SYSCALL_SRC)/*.c)
STARTUP_SRCS = $(wildcard $(STARTUP_SRC)/*.c)

# Create output object paths
APP_OBJS = $(patsubst $(APPL_SRC)/%.c, $(OUTPUT_SRC_DIR)/%.o, $(APP_SRCS))
SYS_OBJS = $(patsubst $(SYSCALL_SRC)/%.c, $(OUTPUT_SRC_DIR)/%.o, $(SYS_SRCS))
STARTUP_OBJS = $(patsubst $(STARTUP_SRC)/%.c, $(OUTPUT_STARTUP_DIR)/%.o, $(STARTUP_SRCS))

OBJS = $(APP_OBJS) $(SYS_OBJS) $(STARTUP_OBJS)

.PHONY: all clean prepare library load

# Default target
all: prepare $(OUTPUT_DIR)/$(TARGET)

# Command to create sub-directory in output directory
prepare:
	@mkdir -p $(OUTPUT_SRC_DIR) $(OUTPUT_STARTUP_DIR)

# Pattern rules for compiling sources
$(OUTPUT_SRC_DIR)/%.o: $(APPL_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_SRC_DIR)/%.o: $(SYSCALL_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_STARTUP_DIR)/%.o: $(STARTUP_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking final executable
$(OUTPUT_DIR)/$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Archiving into static library
$(OUTPUT_DIR)/$(LIBRARY_NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Create library only
library: prepare $(OUTPUT_DIR)/$(LIBRARY_NAME)

# Clean output files
clean:
	rm -rf $(OUTPUT_SRC_DIR) $(OUTPUT_STARTUP_DIR) $(OUTPUT_DIR)/$(TARGET) \
           $(OUTPUT_DIR)/$(LIBRARY_NAME) $(OUTPUT_DIR)/*.map

# Flash via OpenOCD
load:
	openocd -f board/stm32f4discovery.cfg -c "program ../Output/final.elf verify reset exit"
