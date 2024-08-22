# Project Name
PROJECT = blink-led

# Build Directory
BUILD_DIR = bin

# Source files 
#One applcation source  One Drivers source
CFILES = Src/main.cpp Drivers.Src/???

#Header files
APP_INC_DIR = Inc # Applacation headers
DRIVER_INC_DIR = drivers/Inc # Driver headers


# Source Files - Adjust this list to include only the files you want to compile
CFILES = my-project.cpp

# Update these lines with correct values if needed
DEVICE = stm32f103c8
OOCD_FILE = board/stm32f4discovery.cfg

<<<<<<< HEAD
# Include directories (if any)
INCLUDES = -I$(APP_INC_DIR) -I$(DRIVER_INC_DIR)

# Source Files - Adjust this list to include only the files you want to compile
CFILES = my-project.cpp

# Update these lines with correct values if needed
DEVICE = stm32f103c8
OOCD_FILE = board/stm32f4discovery.cfg


# Paths
OPENCM3_DIR = ../libopencm3
SHARED_DIR = $(OPENCM3_DIR)/include
INCLUDES += -I$(SHARED_DIR)

# Compiler and Linker Flags
CXXFLAGS += -std=c++17 $(INCLUDES)
LDFLAGS += -L$(OPENCM3_DIR)/lib

# Source and Object Files
SOURCES = $(CFILES)
OBJECTS = $(SOURCES:my-project/%.cpp=$(BUILD_DIR)/%.o)

# Build Targets
all: $(BUILD_DIR)/$(PROJECT).elf


# Source Files - Adjust this list to include only the files you want to compile
CFILES = my-project.cpp

# Update these lines with correct values if needed
DEVICE = stm32f103c8
OOCD_FILE = board/stm32f4discovery.cfg

# Paths
OPENCM3_DIR = ../libopencm3
SHARED_DIR = $(OPENCM3_DIR)/include
INCLUDES += -I$(SHARED_DIR)

# Compiler and Linker Flags
CXXFLAGS += -std=c++17 $(INCLUDES)
LDFLAGS += -L$(OPENCM3_DIR)/lib

# Source and Object Files
SOURCES = $(CFILES)
OBJECTS = $(SOURCES:my-project/%.cpp=$(BUILD_DIR)/%.o)

# Build Targets
all: $(BUILD_DIR)/$(PROJECT).elf


# Link the final executable
$(BUILD_DIR)/$(PROJECT).elf: $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

# Compile each .cpp file into an object file
$(BUILD_DIR)/%.o: my-project/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(PROJECT).elf

# Declare targets that don't produce files
.PHONY: all clean
