# Project Name
PROJECT = GPIO

# Build Directory
BUILD_DIR = bin

# Source and Header Directories
SRC_DIR = Src
SRC_DRIVERS_DIR = Drivers/Src
APP_INC_DIR = Inc            # Application headers
DRIVER_INC_DIR = Drivers/Inc # Driver headers

# Source Files
CFILES = $(SRC_DIR)/Main.cpp \
         $(SRC_DRIVERS_DIR)/STM32F103xx-GPIO.cpp

# Include Directories
INCLUDES = -I$(APP_INC_DIR) -I$(DRIVER_INC_DIR)

# Device and OpenOCD settings
DEVICE = stm32f103c8
OOCD_FILE = board/stm32f4discovery.cfg

# Paths for external libraries
OPENCM3_DIR = ../libopencm3
SHARED_DIR = $(OPENCM3_DIR)/include
INCLUDES += -I$(SHARED_DIR)

# Compiler and Linker Flags
CXXFLAGS = -std=c++17 $(INCLUDES)
LDFLAGS = -L$(OPENCM3_DIR)/lib

# Source and Object Files
SOURCES = $(CFILES)
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Build Targets
all: $(BUILD_DIR)/$(PROJECT).elf

# Link the final executable
$(BUILD_DIR)/$(PROJECT).elf: $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

# Compile each .cpp file into an object file
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)  # Ensure the directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(PROJECT).elf

# Declare targets that don't produce files
.PHONY: all clean
